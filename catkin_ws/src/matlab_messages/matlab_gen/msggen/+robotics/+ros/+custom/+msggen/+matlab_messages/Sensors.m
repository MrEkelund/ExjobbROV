classdef Sensors < robotics.ros.Message
    %Sensors MATLAB implementation of matlab_messages/Sensors
    %   This class was automatically generated by
    %   robotics.ros.msg.internal.gen.MessageClassGenerator.
    
    %   Copyright 2016 The MathWorks, Inc.
    
    %#ok<*INUSD>
    
    properties (Constant)
        MessageType = 'matlab_messages/Sensors' % The ROS message type
    end
    
    properties (Constant, Hidden)
        MD5Checksum = '94a424b8e3eff696d625cfa1c9dba90a' % The MD5 Checksum of the message definition
    end
    
    properties (Access = protected)
        JavaMessage % The Java message object
    end
    
    properties (Dependent)
        OmegaX
        OmegaY
        OmegaZ
        AccX
        AccY
        AccZ
        MagX
        MagY
        MagZ
        Pressure
    end
    
    properties (Constant, Hidden)
        PropertyList = {'AccX', 'AccY', 'AccZ', 'MagX', 'MagY', 'MagZ', 'OmegaX', 'OmegaY', 'OmegaZ', 'Pressure'} % List of non-constant message properties
        ROSPropertyList = {'AccX', 'AccY', 'AccZ', 'MagX', 'MagY', 'MagZ', 'OmegaX', 'OmegaY', 'OmegaZ', 'Pressure'} % List of non-constant ROS message properties
    end
    
    methods
        function obj = Sensors(msg)
            %Sensors Construct the message object Sensors
            import com.mathworks.toolbox.robotics.ros.message.MessageInfo;
            
            % Support default constructor
            if nargin == 0
                obj.JavaMessage = obj.createNewJavaMessage;
                return;
            end
            
            % Construct appropriate empty array
            if isempty(msg)
                obj = obj.empty(0,1);
                return;
            end
            
            % Make scalar construction fast
            if isscalar(msg)
                % Check for correct input class
                if ~MessageInfo.compareTypes(msg(1), obj.MessageType)
                    error(message('robotics:ros:message:NoTypeMatch', obj.MessageType, ...
                        char(MessageInfo.getType(msg(1))) ));
                end
                obj.JavaMessage = msg(1);
                return;
            end
            
            % Check that this is a vector of scalar messages. Since this
            % is an object array, use arrayfun to verify.
            if ~all(arrayfun(@isscalar, msg))
                error(message('robotics:ros:message:MessageArraySizeError'));
            end
            
            % Check that all messages in the array have the correct type
            if ~all(arrayfun(@(x) MessageInfo.compareTypes(x, obj.MessageType), msg))
                error(message('robotics:ros:message:NoTypeMatchArray', obj.MessageType));
            end
            
            % Construct array of objects if necessary
            objType = class(obj);
            for i = 1:length(msg)
                obj(i,1) = feval(objType, msg(i)); %#ok<AGROW>
            end
        end
        
        function omegax = get.OmegaX(obj)
            %get.OmegaX Get the value for property OmegaX
            omegax = double(obj.JavaMessage.getOmegaX);
        end
        
        function set.OmegaX(obj, omegax)
            %set.OmegaX Set the value for property OmegaX
            validateattributes(omegax, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'omegax');
            
            obj.JavaMessage.setOmegaX(omegax);
        end
        
        function omegay = get.OmegaY(obj)
            %get.OmegaY Get the value for property OmegaY
            omegay = double(obj.JavaMessage.getOmegaY);
        end
        
        function set.OmegaY(obj, omegay)
            %set.OmegaY Set the value for property OmegaY
            validateattributes(omegay, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'omegay');
            
            obj.JavaMessage.setOmegaY(omegay);
        end
        
        function omegaz = get.OmegaZ(obj)
            %get.OmegaZ Get the value for property OmegaZ
            omegaz = double(obj.JavaMessage.getOmegaZ);
        end
        
        function set.OmegaZ(obj, omegaz)
            %set.OmegaZ Set the value for property OmegaZ
            validateattributes(omegaz, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'omegaz');
            
            obj.JavaMessage.setOmegaZ(omegaz);
        end
        
        function accx = get.AccX(obj)
            %get.AccX Get the value for property AccX
            accx = double(obj.JavaMessage.getAccX);
        end
        
        function set.AccX(obj, accx)
            %set.AccX Set the value for property AccX
            validateattributes(accx, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'accx');
            
            obj.JavaMessage.setAccX(accx);
        end
        
        function accy = get.AccY(obj)
            %get.AccY Get the value for property AccY
            accy = double(obj.JavaMessage.getAccY);
        end
        
        function set.AccY(obj, accy)
            %set.AccY Set the value for property AccY
            validateattributes(accy, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'accy');
            
            obj.JavaMessage.setAccY(accy);
        end
        
        function accz = get.AccZ(obj)
            %get.AccZ Get the value for property AccZ
            accz = double(obj.JavaMessage.getAccZ);
        end
        
        function set.AccZ(obj, accz)
            %set.AccZ Set the value for property AccZ
            validateattributes(accz, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'accz');
            
            obj.JavaMessage.setAccZ(accz);
        end
        
        function magx = get.MagX(obj)
            %get.MagX Get the value for property MagX
            magx = double(obj.JavaMessage.getMagX);
        end
        
        function set.MagX(obj, magx)
            %set.MagX Set the value for property MagX
            validateattributes(magx, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'magx');
            
            obj.JavaMessage.setMagX(magx);
        end
        
        function magy = get.MagY(obj)
            %get.MagY Get the value for property MagY
            magy = double(obj.JavaMessage.getMagY);
        end
        
        function set.MagY(obj, magy)
            %set.MagY Set the value for property MagY
            validateattributes(magy, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'magy');
            
            obj.JavaMessage.setMagY(magy);
        end
        
        function magz = get.MagZ(obj)
            %get.MagZ Get the value for property MagZ
            magz = double(obj.JavaMessage.getMagZ);
        end
        
        function set.MagZ(obj, magz)
            %set.MagZ Set the value for property MagZ
            validateattributes(magz, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'magz');
            
            obj.JavaMessage.setMagZ(magz);
        end
        
        function pressure = get.Pressure(obj)
            %get.Pressure Get the value for property Pressure
            pressure = double(obj.JavaMessage.getPressure);
        end
        
        function set.Pressure(obj, pressure)
            %set.Pressure Set the value for property Pressure
            validateattributes(pressure, {'numeric'}, {'nonempty', 'scalar'}, 'Sensors', 'pressure');
            
            obj.JavaMessage.setPressure(pressure);
        end
    end
    
    methods (Access = protected)
        function cpObj = copyElement(obj)
            %copyElement Implements deep copy behavior for message
            
            % Call default copy method for shallow copy
            cpObj = copyElement@robotics.ros.Message(obj);
            
            % Create a new Java message object
            cpObj.JavaMessage = obj.createNewJavaMessage;
            
            % Iterate over all primitive properties
            cpObj.OmegaX = obj.OmegaX;
            cpObj.OmegaY = obj.OmegaY;
            cpObj.OmegaZ = obj.OmegaZ;
            cpObj.AccX = obj.AccX;
            cpObj.AccY = obj.AccY;
            cpObj.AccZ = obj.AccZ;
            cpObj.MagX = obj.MagX;
            cpObj.MagY = obj.MagY;
            cpObj.MagZ = obj.MagZ;
            cpObj.Pressure = obj.Pressure;
        end
        
        function reload(obj, strObj)
            %reload Called by loadobj to assign properties
            obj.OmegaX = strObj.OmegaX;
            obj.OmegaY = strObj.OmegaY;
            obj.OmegaZ = strObj.OmegaZ;
            obj.AccX = strObj.AccX;
            obj.AccY = strObj.AccY;
            obj.AccZ = strObj.AccZ;
            obj.MagX = strObj.MagX;
            obj.MagY = strObj.MagY;
            obj.MagZ = strObj.MagZ;
            obj.Pressure = strObj.Pressure;
        end
    end
    
    methods (Access = ?robotics.ros.Message)
        function strObj = saveobj(obj)
            %saveobj Implements saving of message to MAT file
            
            % Return an empty element if object array is empty
            if isempty(obj)
                strObj = struct.empty;
                return
            end
            
            strObj.OmegaX = obj.OmegaX;
            strObj.OmegaY = obj.OmegaY;
            strObj.OmegaZ = obj.OmegaZ;
            strObj.AccX = obj.AccX;
            strObj.AccY = obj.AccY;
            strObj.AccZ = obj.AccZ;
            strObj.MagX = obj.MagX;
            strObj.MagY = obj.MagY;
            strObj.MagZ = obj.MagZ;
            strObj.Pressure = obj.Pressure;
        end
    end
    
    methods (Static, Access = {?matlab.unittest.TestCase, ?robotics.ros.Message})
        function obj = loadobj(strObj)
            %loadobj Implements loading of message from MAT file
            
            % Return an empty object array if the structure element is not defined
            if isempty(strObj)
                obj = robotics.ros.custom.msggen.matlab_messages.Sensors.empty(0,1);
                return
            end
            
            % Create an empty message object
            obj = robotics.ros.custom.msggen.matlab_messages.Sensors;
            obj.reload(strObj);
        end
    end
end
