#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3C,D1,D2); //oled i2c address and pins




void setup() {
  Serial.begin(9600);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);

  display.drawString(10,10,"HELLO WORLD");
}

void loop() {
  // put your main code here, to run repeatedly:
}