//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char ControlModulePowerControl;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("TESTOSAN2"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    char ControlModulePowerControl = Serial.read();
    Serial.write(ControlModulePowerControl);
    if (ControlModulePowerControl == 255)
      SerialBT.println("on");
    else //if (ControlModulePowerControl == 0)
      SerialBT.println("off");

  }
  if (SerialBT.available()) {
    char ControlModulePowerControl = SerialBT.read();
    SerialBT.write(ControlModulePowerControl);
    if (ControlModulePowerControl == 255)
      Serial.println("on");
    else if (ControlModulePowerControl == 'off')
      Serial.println("off");

  }
}
