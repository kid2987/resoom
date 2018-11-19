#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int temp[300];
int BTtemp[300];
int BTbufferIndex=0;
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
    for(int i =0; i<bufferIndex; i++){
    SerialBT.write(temp[i]);
    delay(3); 
    }    
   }
   
   while (SerialBT.available()) {
    BTtemp[BTbufferIndex]=SerialBT.read();
    BTbufferIndex++;
    delay(3);
  }
     if((BTtemp[0]={'0'}) && (BTtemp[1]={'x'}) && (BTtemp[2]={'B'}) && (BTtemp[3]={'B'})){
    for(int i =0; i<BTbufferIndex; i++){
    Serial.write(BTtemp[i]);
    delay(3); 
    }    
   }
  
    for(int a=0;a<300;a++)
    temp[a]=NULL;

    bufferIndex=0;
    
    for(int b=0;b<300;b++)
    BTtemp[b]=NULL;

    BTbufferIndex=0;
}
