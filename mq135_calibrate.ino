#include <Wire.h>                             //I2C for OLED
#include <Adafruit_GFX.h>                     //grafix library for OLED
#include <Adafruit_SSD1306.h>                 //OLED Driver

#define OLED_RESET   4

Adafruit_SSD1306 display(OLED_RESET);         //create instance of OLED called display

// select the input pin for the MQ-135 sensor
int sensorPin = A0; 
// variable to store the value coming from the sensor.
int val = 0; 

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //begin display @ hex addy 0x3C
  display.display();                          //show buffer
  display.clearDisplay();                     //clear buffer

}
void loop() {
  // read the value from the sensor
  val = analogRead(sensorPin);
  Serial.println (val);
  display.clearDisplay();                     //clear display @ beginning of each loop
  display.setTextSize(5);                     //set text size
  display.setTextColor(WHITE);                //set text color
  display.setCursor(0,0);                     //set cursor
  display.print (val);
  display.display();                          //show the buffer

  delay(1000);
}
