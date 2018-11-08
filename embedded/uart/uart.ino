

void setup() {
  Serial.begin(115200);
  //Serial1.begin(115200);  //it makes endless rebooting
  Serial2.begin(115200);
}

void loop() {
  Serial.println("\r\n uart1 \r\n");
  //Serial1.println("\r\n uart2\r\n ");
  Serial2.println("\r\n uart3\r\n");
  delay(1000);
}
