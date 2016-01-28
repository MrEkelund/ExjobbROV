package mavros_msgs;

public interface ActuatorControl extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "mavros_msgs/ActuatorControl";
  static final java.lang.String _DEFINITION = "# raw servo values for direct actuator controls\n#\n# about groups, mixing and channels:\n# https://pixhawk.org/dev/mixing\n\n# constant for mixer group\nuint8 PX4_MIX_FLIGHT_CONTROL = 0\nuint8 PX4_MIX_FLIGHT_CONTROL_VTOL_ALT = 1\nuint8 PX4_MIX_PAYLOAD = 2\nuint8 PX4_MIX_MANUAL_PASSTHROUGH = 3\n#uint8 PX4_MIX_FC_MC_VIRT = 4\n#uint8 PX4_MIX_FC_FW_VIRT = 5\n\nHeader header\nuint8 group_mix\nfloat32[8] controls\n";
  static final byte PX4_MIX_FLIGHT_CONTROL = 0;
  static final byte PX4_MIX_FLIGHT_CONTROL_VTOL_ALT = 1;
  static final byte PX4_MIX_PAYLOAD = 2;
  static final byte PX4_MIX_MANUAL_PASSTHROUGH = 3;
  std_msgs.Header getHeader();
  void setHeader(std_msgs.Header value);
  byte getGroupMix();
  void setGroupMix(byte value);
  float[] getControls();
  void setControls(float[] value);
}
