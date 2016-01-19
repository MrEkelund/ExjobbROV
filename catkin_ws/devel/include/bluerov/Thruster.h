// Generated by gencpp from file bluerov/Thruster.msg
// DO NOT EDIT!


#ifndef BLUEROV_MESSAGE_THRUSTER_H
#define BLUEROV_MESSAGE_THRUSTER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <std_msgs/UInt16MultiArray.h>

namespace bluerov
{
template <class ContainerAllocator>
struct Thruster_
{
  typedef Thruster_<ContainerAllocator> Type;

  Thruster_()
    : header()
    , commands()  {
    }
  Thruster_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , commands(_alloc)  {
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::std_msgs::UInt16MultiArray_<ContainerAllocator>  _commands_type;
  _commands_type commands;




  typedef boost::shared_ptr< ::bluerov::Thruster_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::bluerov::Thruster_<ContainerAllocator> const> ConstPtr;

}; // struct Thruster_

typedef ::bluerov::Thruster_<std::allocator<void> > Thruster;

typedef boost::shared_ptr< ::bluerov::Thruster > ThrusterPtr;
typedef boost::shared_ptr< ::bluerov::Thruster const> ThrusterConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::bluerov::Thruster_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::bluerov::Thruster_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace bluerov

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'bluerov': ['/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::bluerov::Thruster_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::bluerov::Thruster_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bluerov::Thruster_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::bluerov::Thruster_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bluerov::Thruster_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::bluerov::Thruster_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::bluerov::Thruster_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ce5410dbe4f7e3f3510d94e3cf5217c2";
  }

  static const char* value(const ::bluerov::Thruster_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xce5410dbe4f7e3f3ULL;
  static const uint64_t static_value2 = 0x510d94e3cf5217c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::bluerov::Thruster_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bluerov/Thruster";
  }

  static const char* value(const ::bluerov::Thruster_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::bluerov::Thruster_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
std_msgs/UInt16MultiArray commands\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: std_msgs/UInt16MultiArray\n\
# Please look at the MultiArrayLayout message definition for\n\
# documentation on all multiarrays.\n\
\n\
MultiArrayLayout  layout        # specification of data layout\n\
uint16[]            data        # array of data\n\
\n\
\n\
================================================================================\n\
MSG: std_msgs/MultiArrayLayout\n\
# The multiarray declares a generic multi-dimensional array of a\n\
# particular data type.  Dimensions are ordered from outer most\n\
# to inner most.\n\
\n\
MultiArrayDimension[] dim # Array of dimension properties\n\
uint32 data_offset        # padding bytes at front of data\n\
\n\
# Accessors should ALWAYS be written in terms of dimension stride\n\
# and specified outer-most dimension first.\n\
# \n\
# multiarray(i,j,k) = data[data_offset + dim_stride[1]*i + dim_stride[2]*j + k]\n\
#\n\
# A standard, 3-channel 640x480 image with interleaved color channels\n\
# would be specified as:\n\
#\n\
# dim[0].label  = \"height\"\n\
# dim[0].size   = 480\n\
# dim[0].stride = 3*640*480 = 921600  (note dim[0] stride is just size of image)\n\
# dim[1].label  = \"width\"\n\
# dim[1].size   = 640\n\
# dim[1].stride = 3*640 = 1920\n\
# dim[2].label  = \"channel\"\n\
# dim[2].size   = 3\n\
# dim[2].stride = 3\n\
#\n\
# multiarray(i,j,k) refers to the ith row, jth column, and kth channel.\n\
================================================================================\n\
MSG: std_msgs/MultiArrayDimension\n\
string label   # label of given dimension\n\
uint32 size    # size of given dimension (in type units)\n\
uint32 stride  # stride of given dimension\n\
";
  }

  static const char* value(const ::bluerov::Thruster_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::bluerov::Thruster_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.commands);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct Thruster_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::bluerov::Thruster_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::bluerov::Thruster_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "commands: ";
    s << std::endl;
    Printer< ::std_msgs::UInt16MultiArray_<ContainerAllocator> >::stream(s, indent + "  ", v.commands);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BLUEROV_MESSAGE_THRUSTER_H
