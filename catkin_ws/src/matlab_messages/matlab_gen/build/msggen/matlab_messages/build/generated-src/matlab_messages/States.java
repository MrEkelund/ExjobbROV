package matlab_messages;

public interface States extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "matlab_messages/States";
  static final java.lang.String _DEFINITION = "float64 Q0\nfloat64 Q1\nfloat64 Q2\nfloat64 Q3\nfloat64 GyroBiasX\nfloat64 GyroBiasY\nfloat64 GyroBiasZ\nfloat64 AccBiasX\nfloat64 AccBiasY\nfloat64 AccBiasZ\nfloat64 Depth\n";
  double getQ0();
  void setQ0(double value);
  double getQ1();
  void setQ1(double value);
  double getQ2();
  void setQ2(double value);
  double getQ3();
  void setQ3(double value);
  double getGyroBiasX();
  void setGyroBiasX(double value);
  double getGyroBiasY();
  void setGyroBiasY(double value);
  double getGyroBiasZ();
  void setGyroBiasZ(double value);
  double getAccBiasX();
  void setAccBiasX(double value);
  double getAccBiasY();
  void setAccBiasY(double value);
  double getAccBiasZ();
  void setAccBiasZ(double value);
  double getDepth();
  void setDepth(double value);
}
