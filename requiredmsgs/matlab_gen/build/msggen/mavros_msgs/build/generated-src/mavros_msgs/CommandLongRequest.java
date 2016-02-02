package mavros_msgs;

public interface CommandLongRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "mavros_msgs/CommandLongRequest";
  static final java.lang.String _DEFINITION = "# Generic COMMAND_LONG\n\nbool broadcast # send this command in broadcast mode\n\nuint16 command\nuint8 confirmation\nfloat32 param1\nfloat32 param2\nfloat32 param3\nfloat32 param4\nfloat32 param5\t# x_lat\nfloat32 param6\t# y_lon\nfloat32 param7\t# z_alt\n";
  boolean getBroadcast();
  void setBroadcast(boolean value);
  short getCommand();
  void setCommand(short value);
  byte getConfirmation();
  void setConfirmation(byte value);
  float getParam1();
  void setParam1(float value);
  float getParam2();
  void setParam2(float value);
  float getParam3();
  void setParam3(float value);
  float getParam4();
  void setParam4(float value);
  float getParam5();
  void setParam5(float value);
  float getParam6();
  void setParam6(float value);
  float getParam7();
  void setParam7(float value);
}
