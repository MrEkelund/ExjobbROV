/* Copyright 2014-2015 The MathWorks, Inc. */

#include <iostream>
#include <ros/ros.h>
#include <ros/callback_queue.h>

extern ros::NodeHandle * SLROSNodePtr;  ///< The global node handle that is used by all ROS entities in the model

/**
* Class for subscribing to ROS messages in C++.
* 
* This class is used by code generated from the Simulink ROS
* subscriber blocks and is templatized by the ROS message type and
* Simulink bus type.
*/
template <class MsgType, class BusType>
class SimulinkSubscriber
{
public:
    void sub_callback(const boost::shared_ptr<MsgType const>&);
    void create_subscriber(std::string const& topic, uint32_t queue_size);
    bool get_latest_msg(BusType* busPtr); // returns true iff message is new

private:
    boost::shared_ptr<ros::CallbackQueue>   customCallbackQueuePtr;
    ros::Subscriber                         subscriber;
    bool                                    newMessageReceived;
    boost::shared_ptr<MsgType const>        lastMsgPtr;
};

/**
* Callback that is triggered when a new message is received
*
* This function will store the message as latest message.
* @param msgPtr The received message
*/
template <class MsgType, class BusType>
void SimulinkSubscriber<MsgType,BusType>::sub_callback(const boost::shared_ptr<MsgType const>& msgPtr) 
{
    lastMsgPtr = msgPtr; // copy the shared_ptr
    newMessageReceived = true;
}

/**
* Create a C++ subscriber object
*
* @param topic The topic name to subscribe to
* @param queue_size The length of incoming message queue
*/
template <class MsgType, class BusType>
void SimulinkSubscriber<MsgType,BusType>::create_subscriber(std::string const& topic, uint32_t queue_size)
{
    customCallbackQueuePtr.reset( new ros::CallbackQueue() );

    ros::SubscribeOptions opts;
    opts.init<MsgType>(topic, queue_size, 
        boost::bind(&SimulinkSubscriber<MsgType,BusType>::sub_callback, this, _1));
    opts.callback_queue = customCallbackQueuePtr.get();

    subscriber = SLROSNodePtr->subscribe(opts);
}

/** 
* Get the latest received message
*
* @param busPtr Simulink bus structure that should be populated with message contents
* @return =TRUE, then a new message has been received and *busPtr holds the newly-received message. 
* =FALSE when a new message has not been received and *busPtr is unchanged.
*/
template <class MsgType, class BusType>
bool SimulinkSubscriber<MsgType,BusType>::get_latest_msg(BusType* busPtr) 
{
    customCallbackQueuePtr->callOne(); 

    if (newMessageReceived) {
        convert_to_bus(busPtr, lastMsgPtr.get());
        newMessageReceived = false;
        return true; // message is new
    } else {
        return false; // message is not new
    }
}


/**
* Class for publishing ROS messages in C++.
* 
* This class is used by code generated from the Simulink ROS
* publisher blocks and is templatized by the ROS message type and
* Simulink bus type.
*/
template <class MsgType, class BusType>
class SimulinkPublisher
{

public:
    void create_publisher(std::string const& topic, uint32_t queue_size);
    void publish(BusType* busPtr);

private:
    ros::Publisher  publisher; ///< The ROS publisher object
    MsgType         msg;       ///< A prototype of the message to publish (will be filled based on Simulink bus structure)
};


/**
* Create a publisher to a topic
*
* @param topic The name of the topic to advertise
* @param queue_size The length of outgoing publishing message queue
*/
template <class MsgType, class BusType>
void SimulinkPublisher<MsgType,BusType>::create_publisher(std::string const& topic, uint32_t queue_size)
{
    publisher = SLROSNodePtr->advertise<MsgType>(topic, queue_size);
}

/**
* Publish a message
*
* @param busPtr Pointer to the bus structure for the outgoing message
*/
template <class MsgType, class BusType>
void SimulinkPublisher<MsgType,BusType>::publish(BusType* busPtr)
{
    convert_from_bus(&msg, busPtr);
    publisher.publish(msg);
}

// Namespace for parameter parsing code
namespace param_parser
{
    /**
     * Parse a scalar parameter value. This function is templatized by the 
     * expected data type of the ROS parameter.
     * This function is needed, since the standard ROS C++ parameter parsing
     * does not strictly enforce data type consistency.
     *
     * @param[in] xmlValue The value of the parameter as XML-RPC data structure
     * @param[out] paramValue The value of the parameter as scalar data type
     * @retval TRUE if parameter with given type was parsed successfully. The 
     * value of the parameter will be returned in @c paramValue.
     * @retval FALSE if parameter type did not match content in XML-RPC data structure
     */
    template <class T>
    bool getScalar(const XmlRpc::XmlRpcValue& xmlValue, T& paramValue)
    {
        if (xmlValue.getType() != getXmlRpcType(paramValue))
            return false;

        // Setting the output parameter value via overloaded conversion operator.
        // Since the operator is defined as non-const, using const_cast here to
        // avoid compiler warnings.
        // Since the conversion operator does not modify the xmlValue object, 
        // the const_cast is safe.
        paramValue = const_cast<XmlRpc::XmlRpcValue&>(xmlValue);
        return true;
    }
    
    /**
     * Generic template function for getting enumerated XML-RPC data type.
     * See the specialized templates for handling specific data types.
     *
     * @param[in] paramValue The parameter value. The contents of the variable do
     * not matter, but its data type is crucial for calling the correct template 
     * specialization.
     *
     * @return XML-RPC data type enumeration corresponding to the input parameter type
     */
    template <class T>
    XmlRpc::XmlRpcValue::Type getXmlRpcType(const T& paramValue)
    {
        return XmlRpc::XmlRpcValue::TypeInvalid;
    }
    
    /**
     * Specialized template function for handling integer parameters.
     *
     * @param[in] paramValue The parameter value. 
     * @return integer XML-RPC data type enumeration
     */
    template <>
    inline XmlRpc::XmlRpcValue::Type getXmlRpcType<int>(const int& paramValue)
    {
        return XmlRpc::XmlRpcValue::TypeInt;
    }
    
    /**
     * Specialized template function for handling double parameters.
     *
     * @param[in] paramValue The parameter value. 
     * @return double XML-RPC data type enumeration
     */
    template <>
    inline XmlRpc::XmlRpcValue::Type getXmlRpcType<double>(const double& paramValue)
    {
        return XmlRpc::XmlRpcValue::TypeDouble;
    }
    
    /**
     * Specialized template function for handling boolean parameters.
     *
     * @param[in] paramValue The parameter value. 
     * @return boolean XML-RPC data type enumeration
     */
    template <>
    inline XmlRpc::XmlRpcValue::Type getXmlRpcType<bool>(const bool& paramValue)
    {
        return XmlRpc::XmlRpcValue::TypeBoolean;
    }
}

/**
* Class for getting ROS parameters in C++.
* 
* This class is used by code generated from the Simulink ROS
* parameter blocks and is templatized by the expected C++ data type
* for the parameter value.
*/
template <class CppParamType, class ROSCppParamType>
class SimulinkParameterGetter
{
    
public:
    void    initialize(const std::string& pName, const CppParamType& initValue, uint8_t codeSuccess, uint8_t codeNoParam, uint8_t codeTypeMismatch);
    uint8_t get_parameter(CppParamType* dataPtr);
    
private:
    ros::NodeHandle*    nodePtr;        ///< Pointer to node handle (node will be used to connect to parameter server)
    std::string         paramName;      ///< The name of the parameter
    CppParamType        initialValue;   ///< The default value that should be returned by get_parameter if one of the error conditions occurs
    CppParamType        lastValidValue; ///< The last valid value that was received from the parameter server
    bool                hasValidValue;  ///< Indicates if a valid value has been received yet. If TRUE, this last value will be stored in lastValidValue.
    
    uint8_t             errorCodeSuccess;       ///< Returned if parameter was retrieved successfully.
    uint8_t             errorCodeNoParam;       ///< Returned if parameter does not exist on server.
    uint8_t             errorCodeTypeMismatch;  ///< Returned if parameter data type did not match.

    uint8_t             handle_getParam_errors(CppParamType* dataPtr, bool paramRetrieved);
};


/**
* Initialize the class.
* @param pName The name of the ROS parameter
* @param initValue The default value that should be returned by get_parameter if one of the
* error conditions occurs before a valid value is received.
* @param codeSuccess Error code that should be emitted if parameter is retrieved successfully
* @param codeNoParam Error code if parameter with given name does not exist on server
* @param codeTypeMismatch Error code if parameter exists on server, but has a different data type
*/
template <class CppParamType, class ROSCppParamType>
void SimulinkParameterGetter<CppParamType,ROSCppParamType>::initialize(const std::string& pName, const CppParamType& initValue, 
                                                       uint8_t codeSuccess, uint8_t codeNoParam, uint8_t codeTypeMismatch)
{
    nodePtr = SLROSNodePtr;
    paramName = pName;
    initialValue = initValue;
    lastValidValue = initValue;
    hasValidValue = false;

    // Initialize the error codes
    errorCodeSuccess = codeSuccess;
    errorCodeNoParam = codeNoParam;
    errorCodeTypeMismatch = codeTypeMismatch;
}

/**
* Get the value for a named parameter from the parameter server.
* @param dataPtr Pointer to initialized data variable. The retrieved parameter value will be written to this location
* @return =0 if value was read successfully, >0 if an error occurred
*/
template <class CppParamType, class ROSCppParamType>
uint8_t SimulinkParameterGetter<CppParamType,ROSCppParamType>::get_parameter(CppParamType* dataPtr)
{
    XmlRpc::XmlRpcValue xmlValue;
    ROSCppParamType paramValue;
    bool paramRetrieved = false;
 
    // Get parameter as XmlRpcValue and then parse it through our own function
    if (nodePtr->getParam(paramName, xmlValue))
    {
      paramRetrieved = param_parser::getScalar(xmlValue, paramValue);
    }    
    
    // Cast the returned value into the data type that Simulink is expecting
    *dataPtr = static_cast<CppParamType>(paramValue);    
    
    const uint8_t errorCode = handle_getParam_errors(dataPtr, paramRetrieved);
    return errorCode;
}

/**
* Determine value and error code for retrieved parameter
* @param dataPtr Pointer to initialized data variable. The retrieved parameter value will be written to this location
* @param paramRetrieved Return value from ROS function for getting a parameter value
* @return =0 if value was read successfully, >0 if an error occurred
*/
template <class CppParamType, class ROSCppParamType>
uint8_t SimulinkParameterGetter<CppParamType,ROSCppParamType>::handle_getParam_errors(CppParamType* dataPtr, bool paramRetrieved)
{
    // By default, assume that parameter can be retrieved successfully
    uint8_t errorCode = errorCodeSuccess;

    if (!paramRetrieved) 
    {
        // An error code of "errorCodeNoParam" means that the parameter does not exist and
        // "errorCodeTypeMismatch" means that it exists, but the data types don't match
        errorCode = nodePtr->hasParam(paramName) ? errorCodeTypeMismatch : errorCodeNoParam;
    }

    if (errorCode == errorCodeSuccess)
    {
        // Remember last valid value
        lastValidValue = *dataPtr;
        hasValidValue = true;
    }
    else
    {
        // An error occurred. If a valid value was previously
        // received, return it. Otherwise, return the
        // initial value.
        if (hasValidValue)
            *dataPtr = lastValidValue;
        else
            *dataPtr = initialValue;
    }

    return errorCode;
}



/**
* Class for setting ROS parameters in C++.
* 
* This class is used by code generated from the Simulink ROS
* parameter blocks and is templatized by the expected C++ data type
* for the parameter value.
*/
template <class CppParamType, class ROSCppParamType>
class SimulinkParameterSetter
{

public:
    void    initialize(const std::string& pName);
    void    set_parameter(const CppParamType& value);

private:
    ros::NodeHandle*    nodePtr;        ///< Pointer to node handle (node will be used to connect to parameter server)
    std::string         paramName;      ///< The name of the parameter
};


/**
* Initialize the class.
* @param pName The name of the ROS parameter
*/
template <class CppParamType, class ROSCppParamType>
void SimulinkParameterSetter<CppParamType,ROSCppParamType>::initialize(const std::string& pName)
{
    nodePtr = SLROSNodePtr;
    paramName = pName;
}

/**
* Set the value of a named parameter.
* @param value The value that should be set.
*/
template <class CppParamType, class ROSCppParamType>
void SimulinkParameterSetter<CppParamType,ROSCppParamType>::set_parameter(const CppParamType& value)
{
    // Cast from Simulink data type to data type that ROS expects
    ROSCppParamType paramValue = static_cast<ROSCppParamType>(value);
    nodePtr->setParam(paramName, paramValue);
}
