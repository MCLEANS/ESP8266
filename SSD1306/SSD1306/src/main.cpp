#include <Arduino.h>

#include <Wire.h>
#include <SSD1306Wire.h>

#define LED_PIN 16
#define SDA_PIN D1
#define SCL_PIN D2

SSD1306Wire display(0x3C,SDA_PIN,SCL_PIN);

void setup(){
    display.init();
    display.setFont(ArialMT_Plain_10);
    display.drawString(10,10,"HELLO WORLD");
    display.display();

    pinMode(LED_PIN,OUTPUT);
    digitalWrite(LED_PIN,LOW);

}

void loop(){


}