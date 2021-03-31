#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D0,D8);

void setup(){
	Serial.begin(9600);
	NodeMCU.begin(4800);
	pinMode(D2,INPUT);
	pinMode(D3,OUTPUT);
}

void loop(){
	String i = "sensor";
	NodeMCU.print(i);
	//NodeMCU.println("\n");
  Serial.println(i);
  i="";
  
	delay(30);
}
