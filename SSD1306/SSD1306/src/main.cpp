#include <Arduino.h>

#include <Wire.h>
#include <SSD1306Wire.h>

#define LED_PIN 16
#define SDA_PIN D1
#define SCL_PIN D2

SSD1306Wire display(0x3C,SDA_PIN,SCL_PIN);

void setup(){
    display.init();
    display.flipScreenVertically();
    display.setFont(ArialMT_Plain_16);
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(10,10,"LOADING ");
    display.drawString(10,30,"CONFIGURATION");
    display.display();
    delay(2000);
    display.clear();

    pinMode(LED_PIN,OUTPUT);
    digitalWrite(LED_PIN,LOW);

    for(int i = 10; i<100; i++){
        String status = String(i)+"%";
        display.drawString(50,5,status);
        display.fillRect(20,30,i,10);
        display.display();
        delay(50);
        display.clear();
    }

    display.drawString(10,10,"SETUP");
    display.drawString(10,30,"COMPLETE");
    display.display();

   

}

void loop(){


}