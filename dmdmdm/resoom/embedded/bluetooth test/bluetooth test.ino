#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("testBT"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) //블루투스에 받을 공간 있으면
  {
    char num = SerialBT.read(); //블루투스에서 읽어온 정보를 char 형으로 num변수에 저장
    Serial.write(num); //num정보 읽어옴
    if (num == '1') { //num이 1이면
      String re1 = "2080"; //온도 습도를 앱이 받을수 있는 형태로 변환
      SerialBT.println(re1); //온습도 정보를 블루투스를 이용해 앱으로 보냄
    } else if (num == '2') { 
      String re2 = "3070";
      SerialBT.println(re2); //2번 건조대 오습도 정보를 앱으로 보내는 코드
    } else if (num == '3') {
      
      String re3 = "4060";
      SerialBT.println(re3); //3번 건조대 오습도 정보를 앱으로 보내는 코드
    } else if (num == '4') {
      
      String re4 = "5050";
      SerialBT.println(re4); //4번 건조대 오습도 정보를 앱으로 보내는 코드
    } else if (num == '5') {
      
      String re5 = "6040";
      SerialBT.println(re5); //5번 건조대 오습도 정보를 앱으로 보내는 코드
    } else if (num == '6') {
      
      String re6 = "7030";
      SerialBT.println(re6); //6번 건조대 오습도 정보를 앱으로 보내는 코드
    }
  }
  
}
