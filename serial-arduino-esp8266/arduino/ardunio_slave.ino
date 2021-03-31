#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
/* RST=8, CE=9, DC=10, DIN=11, CLK=13
 * 
 */

SoftwareSerial ArduinoUno(3,2);

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 11, 9, 10, 8);

void setup(){
	
	Serial.begin(9600);
	ArduinoUno.begin(4800);


  //Initialize Display
  display.begin();
  // you can change the contrast around to adapt the display for the best viewing!
  display.setContrast(57);

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello world!");
  display.display();
  delay(2000);
  display.clearDisplay();





}

void loop(){
	
	if(ArduinoUno.available()>0){
    
	String val= ArduinoUno.readString();

  
    display.setTextColor(BLACK);
    display.setCursor(0,0);
    display.setTextSize(1);
      
    display.println("Bem Vindo!");
    display.println(val);
    Serial.println(val);
    display.display();
    delay(10);
    display.clearDisplay();
}
}
