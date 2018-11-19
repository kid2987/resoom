#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int temp[100];
int bufferIndex=0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("TESTOSAN2"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()) {
    temp[bufferIndex]=Serial.read();
    bufferIndex++;
    delay(3);
  }
     if((temp[0]={'0'}) && (temp[1]={'x'}) && (temp[2]={'B'}) && (temp[3]={'B'})){
      if((temp[bufferIndex-3]={'0'}) && (temp[bufferIndex-2]={'x'}) && (temp[bufferIndex-1]={'7'}) && (temp[bufferIndex]={'E'})){
    for(int i =0; i<bufferIndex; i++){
    SerialBT.write(temp[i]);
    Serial.write(temp[i]);
    delay(3); 
    }
      }
     }
  
    for(int a=0;a<100;a++)
    temp[a]=NULL;

    bufferIndex=0;
}
