#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"

#define OLED_SDA D1
#define OLED_SCL D2
#define INBUILT_LED 16
uint16_t duration = 400;

bool increase = true;
bool decrease = false;

SSD1306Wire display(0x3C,OLED_SDA,OLED_SCL); //oled i2c address and pins




void setup() {
  Serial.begin(9600);
  //----setup pin functions------------
  pinMode(INBUILT_LED,OUTPUT);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);

  display.drawString(0,30,"DONE SETUP");
  display.display();
  delay(2000);
  display.clear();
}

void loop() {

  if(increase) duration+=100;
  if(decrease) duration-=100;

  if(duration == 5000) {
    decrease = true;
    increase = false;
  }
  if(duration == 300){
    decrease = false;
    increase = true;
  }

  
  digitalWrite(INBUILT_LED,LOW);
  display.drawString(20,20,"LED ON");
  display.drawString(10,40,String(duration));
  display.display();
  delay(duration);
  display.clear();
  digitalWrite(INBUILT_LED,HIGH);
  display.drawString(20,20,"LED OUT");
  display.drawString(10,40,String(duration));
  display.display();
  delay(duration);
  display.clear();

  
}