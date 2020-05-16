#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"

#define OLED_SDA D1
#define OLED_SCL D2
#define INBUILT_LED 16

SSD1306Wire display(0x3C,OLED_SDA,OLED_SCL); //oled i2c address and pins




void setup() {
  Serial.begin(9600);
  //----setup pin functions------------
  pinMode(INBUILT_LED,OUTPUT);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);

  display.drawString(30,30,"DONE SETUP");
  display.display();
  delay(2000);
  display.clear();
}

void loop() {
  digitalWrite(INBUILT_LED,LOW);
  display.drawString(50,50,"LED ON");
  display.display();
  delay(1000);
  display.clear();
  digitalWrite(INBUILT_LED,HIGH);
  display.drawString(50,50,"LED ON");
  display.display();
  delay(1000);
  display.clear();

  
}