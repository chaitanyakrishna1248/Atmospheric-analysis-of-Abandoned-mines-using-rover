#include<SPI.h>
#include <LoRa.h>
#include "DHT.h"
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int gpin = A2;
const int ldrpin = A5;
int gsvalue;
int hum;
float temp; //Stores temperature value

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(A5, INPUT);
  pinMode(gpin, INPUT);
  while (!Serial);
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop()
{
  temp = dht.readTemperature();
  hum = dht.readHumidity();
  int ldr = analogRead(ldrpin);
  gsvalue = analogRead(gpin);
  Serial.println("Sending packet: ");

  // send packet
  LoRa.beginPacket();
  LoRa.print("Humidity %: ");
  LoRa.print(hum);
  LoRa.print(" Temperature C: ");
  LoRa.print(temp);
  LoRa.print(" Gas Readings: ");
  LoRa.print(gsvalue);
  LoRa.print(" LDR status: ");
  LoRa.print(ldr);


  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%");
  Serial.print(" Temperature:");
  Serial.print(temp);
  Serial.println("C");
  Serial.println("Gas Readings");
  Serial.println(gsvalue);
  Serial.println("LDR");
  Serial.println(ldr);

  LoRa.endPacket();
  delay(1000);
}
