

filepath = fullfile('..','..', 'bag', 'test_2016-03-08-14-14-48.bag');
bag = rosbag(filepath);

% rc_bag = select(bag,'Topic','/mavros/rc/out');
% rc_msgs = readMessages(rc_bag);
% 
% control_signals = zeros(size(rc_msgs,1),8);
% for i = 1:size(rc_msgs,1)
%     control_signals(i,:) = rc_msgs{i}.Channels';
% end


