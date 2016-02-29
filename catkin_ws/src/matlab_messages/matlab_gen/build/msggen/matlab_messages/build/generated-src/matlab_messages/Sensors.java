package matlab_messages;

public interface Sensors extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "matlab_messages/Sensors";
  static final java.lang.String _DEFINITION = "float64 OmegaX\nfloat64 OmegaY\nfloat64 OmegaZ\nfloat64 AccX\nfloat64 AccY\nfloat64 AccZ\nfloat64 MagX\nfloat64 MagY\nfloat64 MagZ\nfloat64 Pressure\n";
  double getOmegaX();
  void setOmegaX(double value);
  double getOmegaY();
  void setOmegaY(double value);
  double getOmegaZ();
  void setOmegaZ(double value);
  double getAccX();
  void setAccX(double value);
  double getAccY();
  void setAccY(double value);
  double getAccZ();
  void setAccZ(double value);
  double getMagX();
  void setMagX(double value);
  double getMagY();
  void setMagY(double value);
  double getMagZ();
  void setMagZ(double value);
  double getPressure();
  void setPressure(double value);
}
