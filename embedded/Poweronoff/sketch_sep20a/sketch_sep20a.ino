#include <DHT.h>
#include "SPI.h"
#include "DHT.h"
#include <SoftwareSerial.h>
#include <time.h>

#define DHTPIN1 2
#define DHTPIN2 3
#define DHTPIN3 4
#define DHTPIN4 5
#define DHTPIN5 6
#define DHTPIN6 7
#define DHTTYPE DHT11

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);
DHT dht6(DHTPIN6, DHTTYPE);

float t1 =0.0;
float h1 =0.0;
float t2 =0.0;
float h2 =0.0;
float t3 =0.0;
float h3 =0.0;
float t4 =0.0;
float h4 =0.0;
float t5 =0.0;
float h5 =0.0;
float t6 =0.0;
float h6 =0.0;

SoftwareSerial BTSerial(8,9);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  t1 = dht1.readTemperature();
  h1 = dht1.readHumidity();
  String humis1 = "Humi1 : " + String(h1,0)+ "%";
  String Temps1 = "Temp1 : " + String(t1,0)+ "c";
  BTSerial.println(humis1);
  BTSerial.println(Temps1);

  t2 = dht2.readTemperature();
  h2 = dht2.readHumidity();
  String humis2 = "Humi2 : " + String(h2,0)+ "%";
  String Temps2 = "Temp2 : " + String(t2,0)+ "c";
  BTSerial.println(humis2);
  BTSerial.println(Temps2);

  t3 = dht3.readTemperature();
  h3 = dht3.readHumidity();
  String humis3 = "Humi3 : " + String(h3,0)+ "%";
  String Temps3 = "Temp3 : " + String(t3,0)+ "c";
  BTSerial.println(humis3);
  BTSerial.println(Temps3);

  t4 = dht4.readTemperature();
  h4 = dht4.readHumidity();
  String humis4 = "Humi4 : " + String(h4,0)+ "%";
  String Temps4 = "Temp4 : " + String(t4,0)+ "c";
  BTSerial.println(humis4);
  BTSerial.println(Temps4);

  t5 = dht5.readTemperature();
  h5 = dht5.readHumidity();
  String humis5 = "Humi5 : " + String(h5,0)+ "%";
  String Temps5 = "Temp5 : " + String(t5,0)+ "c";
  BTSerial.println(humis5);
  BTSerial.println(Temps5);

  t6 = dht6.readTemperature();
  h6 = dht6.readHumidity();
  String humis6 = "Humi6 : " + String(h6,0)+ "%";
  String Temps6 = "Temp6 : " + String(t6,0)+ "c";
  BTSerial.println(humis6);
  BTSerial.println(Temps6);

  delay(2000);
}
