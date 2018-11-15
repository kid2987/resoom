#include "HardwareSerial.h"

HardwareSerial Serial1(1);
HardwareSerial Serial2(2);

void setup(){
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial2.begin(115200);
}

void loop(){
  Serial.println("uart1");
  Serial1.println("uart2");
  Serial2.println("uart3");
  delay(1000);
}
