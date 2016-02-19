classdef CustomMsgConsts
    %CustomMsgConsts This class stores all message types
    %   The message types are constant properties, which in turn resolve
    %   to the strings of the actual types.
    
    %   Copyright 2016 The MathWorks, Inc.
    
    properties (Constant)
        mavros_msgs_ActuatorControl = 'mavros_msgs/ActuatorControl'
        mavros_msgs_CommandLong = 'mavros_msgs/CommandLong'
        mavros_msgs_CommandLongRequest = 'mavros_msgs/CommandLongRequest'
        mavros_msgs_CommandLongResponse = 'mavros_msgs/CommandLongResponse'
        mavros_msgs_RCOut = 'mavros_msgs/RCOut'
    end
    
    methods (Static, Hidden)
        function messageList = getMessageList
            %getMessageList Generate a cell array with all message types.
            %   The list will be sorted alphabetically.
            
            persistent msgList
            if isempty(msgList)
                msgList = cell(5, 1);
                msgList{1} = 'mavros_msgs/ActuatorControl';
                msgList{2} = 'mavros_msgs/CommandLong';
                msgList{3} = 'mavros_msgs/CommandLongRequest';
                msgList{4} = 'mavros_msgs/CommandLongResponse';
                msgList{5} = 'mavros_msgs/RCOut';
            end
            
            messageList = msgList;
        end
        
        function serviceList = getServiceList
            %getServiceList Generate a cell array with all service types.
            %   The list will be sorted alphabetically.
            
            persistent svcList
            if isempty(svcList)
                svcList = cell(1, 1);
                svcList{1} = 'mavros_msgs/CommandLong';
            end
            
            % The message list was already sorted, so don't need to sort
            % again.
            serviceList = svcList;
        end
    end
end
