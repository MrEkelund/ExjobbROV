## *********************************************************
## 
## File autogenerated for the bluerov package 
## by the dynamic_reconfigure package.
## Please do not edit.
## 
## ********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 233, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 262, 'description': '', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'x_axis', 'edit_method': "{'enum_description': 'An enum to set axis index', 'enum': [{'srcline': 42, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_X'}, {'srcline': 43, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Y'}, {'srcline': 44, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Left_Trigger'}, {'srcline': 45, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_X'}, {'srcline': 46, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Y'}, {'srcline': 47, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Trigger'}, {'srcline': 48, 'description': 'right trigger is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Trigger_Pair'}, {'srcline': 49, 'description': 'right bumper is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Bumper_Pair'}]}", 'default': 1, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'y_axis', 'edit_method': "{'enum_description': 'An enum to set axis index', 'enum': [{'srcline': 42, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_X'}, {'srcline': 43, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Y'}, {'srcline': 44, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Left_Trigger'}, {'srcline': 45, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_X'}, {'srcline': 46, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Y'}, {'srcline': 47, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Trigger'}, {'srcline': 48, 'description': 'right trigger is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Trigger_Pair'}, {'srcline': 49, 'description': 'right bumper is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Bumper_Pair'}]}", 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'z_axis', 'edit_method': "{'enum_description': 'An enum to set axis index', 'enum': [{'srcline': 42, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_X'}, {'srcline': 43, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Y'}, {'srcline': 44, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Left_Trigger'}, {'srcline': 45, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_X'}, {'srcline': 46, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Y'}, {'srcline': 47, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Trigger'}, {'srcline': 48, 'description': 'right trigger is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Trigger_Pair'}, {'srcline': 49, 'description': 'right bumper is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Bumper_Pair'}]}", 'default': 6, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'wx_axis', 'edit_method': "{'enum_description': 'An enum to set axis index', 'enum': [{'srcline': 42, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_X'}, {'srcline': 43, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Y'}, {'srcline': 44, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Left_Trigger'}, {'srcline': 45, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_X'}, {'srcline': 46, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Y'}, {'srcline': 47, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Trigger'}, {'srcline': 48, 'description': 'right trigger is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Trigger_Pair'}, {'srcline': 49, 'description': 'right bumper is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Bumper_Pair'}]}", 'default': 7, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'wy_axis', 'edit_method': "{'enum_description': 'An enum to set axis index', 'enum': [{'srcline': 42, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_X'}, {'srcline': 43, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Y'}, {'srcline': 44, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Left_Trigger'}, {'srcline': 45, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_X'}, {'srcline': 46, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Y'}, {'srcline': 47, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Trigger'}, {'srcline': 48, 'description': 'right trigger is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Trigger_Pair'}, {'srcline': 49, 'description': 'right bumper is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Bumper_Pair'}]}", 'default': 4, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 7, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'wz_axis', 'edit_method': "{'enum_description': 'An enum to set axis index', 'enum': [{'srcline': 42, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_X'}, {'srcline': 43, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Y'}, {'srcline': 44, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'Left_Trigger'}, {'srcline': 45, 'description': 'left/right', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_X'}, {'srcline': 46, 'description': 'up/down', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Y'}, {'srcline': 47, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Trigger'}, {'srcline': 48, 'description': 'right trigger is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Trigger_Pair'}, {'srcline': 49, 'description': 'right bumper is positive', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Bumper_Pair'}]}", 'default': 3, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 14, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'enable_button', 'edit_method': "{'enum_description': 'An enum to set button index', 'enum': [{'srcline': 54, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'A_Button'}, {'srcline': 55, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'B_Button'}, {'srcline': 56, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'X_Button'}, {'srcline': 57, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Y_Button'}, {'srcline': 58, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Left_Bumper'}, {'srcline': 59, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Bumper'}, {'srcline': 60, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Back_Button'}, {'srcline': 61, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Start_Button'}, {'srcline': 62, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 8, 'ctype': 'int', 'type': 'int', 'name': 'Power_Button'}, {'srcline': 63, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 9, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Click'}, {'srcline': 64, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 10, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Click'}, {'srcline': 65, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 11, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Left'}, {'srcline': 66, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 12, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Right'}, {'srcline': 67, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 13, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Up'}, {'srcline': 68, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 14, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Down'}]}", 'default': 0, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': '', 'max': 14, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'disable_button', 'edit_method': "{'enum_description': 'An enum to set button index', 'enum': [{'srcline': 54, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'A_Button'}, {'srcline': 55, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'B_Button'}, {'srcline': 56, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'X_Button'}, {'srcline': 57, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'Y_Button'}, {'srcline': 58, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 4, 'ctype': 'int', 'type': 'int', 'name': 'Left_Bumper'}, {'srcline': 59, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 5, 'ctype': 'int', 'type': 'int', 'name': 'Right_Bumper'}, {'srcline': 60, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 6, 'ctype': 'int', 'type': 'int', 'name': 'Back_Button'}, {'srcline': 61, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 7, 'ctype': 'int', 'type': 'int', 'name': 'Start_Button'}, {'srcline': 62, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 8, 'ctype': 'int', 'type': 'int', 'name': 'Power_Button'}, {'srcline': 63, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 9, 'ctype': 'int', 'type': 'int', 'name': 'Left_Stick_Click'}, {'srcline': 64, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 10, 'ctype': 'int', 'type': 'int', 'name': 'Right_Stick_Click'}, {'srcline': 65, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 11, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Left'}, {'srcline': 66, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 12, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Right'}, {'srcline': 67, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 13, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Up'}, {'srcline': 68, 'description': '', 'srcfile': '/home/erik/Documents/ExjobbROV/catkin_ws/src/bluerov/config/teleop_xbox.config', 'cconsttype': 'const int', 'value': 14, 'ctype': 'int', 'type': 'int', 'name': 'D_Pad_Down'}]}", 'default': 1, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 262, 'description': 'the maximum publish rate', 'max': 200.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'pub_rate', 'edit_method': '', 'default': 100.0, 'level': 0, 'min': 0.1, 'type': 'double'}, {'srcline': 262, 'description': 'improves control at low levels', 'max': 1.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'expo', 'edit_method': '', 'default': 0.5, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 262, 'description': 'linear scaling in m/s', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'x_scaling', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': -10.0, 'type': 'double'}, {'srcline': 262, 'description': 'linear scaling in m/s', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'y_scaling', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': -10.0, 'type': 'double'}, {'srcline': 262, 'description': 'linear scaling in m/s', 'max': 10.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'z_scaling', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': -10.0, 'type': 'double'}, {'srcline': 262, 'description': 'angular scaling in rad/s', 'max': 31.4, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'wx_scaling', 'edit_method': '', 'default': 1.5, 'level': 0, 'min': -31.4, 'type': 'double'}, {'srcline': 262, 'description': 'angular scaling in rad/s', 'max': 31.4, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'wy_scaling', 'edit_method': '', 'default': 0.3, 'level': 0, 'min': -31.4, 'type': 'double'}, {'srcline': 262, 'description': 'angular scaling in rad/s', 'max': 31.4, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/indigo/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'wz_scaling', 'edit_method': '', 'default': 1.0, 'level': 0, 'min': -31.4, 'type': 'double'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])    
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

teleop_xbox_Left_Stick_X = 0
teleop_xbox_Left_Stick_Y = 1
teleop_xbox_Left_Trigger = 2
teleop_xbox_Right_Stick_X = 3
teleop_xbox_Right_Stick_Y = 4
teleop_xbox_Right_Trigger = 5
teleop_xbox_Trigger_Pair = 6
teleop_xbox_Bumper_Pair = 7
teleop_xbox_A_Button = 0
teleop_xbox_B_Button = 1
teleop_xbox_X_Button = 2
teleop_xbox_Y_Button = 3
teleop_xbox_Left_Bumper = 4
teleop_xbox_Right_Bumper = 5
teleop_xbox_Back_Button = 6
teleop_xbox_Start_Button = 7
teleop_xbox_Power_Button = 8
teleop_xbox_Left_Stick_Click = 9
teleop_xbox_Right_Stick_Click = 10
teleop_xbox_D_Pad_Left = 11
teleop_xbox_D_Pad_Right = 12
teleop_xbox_D_Pad_Up = 13
teleop_xbox_D_Pad_Down = 14
