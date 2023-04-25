#include "master.h"
#include "timer.h"
bool ledState  = 0;
void setup(){
delay(1000);
Serial.begin(9600);
  Wire.begin();
pinMode (25, OUTPUT);
}
unsigned long previousMillis;
int brightness = 0;  // how bright the LED is
int fade = 5;
void loop(){
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 10) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
     brightness = brightness + fade;
   
  }
if (brightness <= 0 || brightness >= 255) {
    fade = -fade;
}
analogWrite(25, brightness);
}
