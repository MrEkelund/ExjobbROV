package mavros_msgs;

public interface CommandLongResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "mavros_msgs/CommandLongResponse";
  static final java.lang.String _DEFINITION = "bool success\n# raw result returned by COMMAND_ACK\nuint8 result";
  boolean getSuccess();
  void setSuccess(boolean value);
  byte getResult();
  void setResult(byte value);
}
