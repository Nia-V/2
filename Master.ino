#include "master.h"
unsigned long previousMillis;
bool ledState  = 0;
void setup(){
delay(1000);
  Wire.begin();
pinMode (13, OUTPUT);
pinMode (32, OUTPUT);
Serial.begin(9600);
}
void loop(){
 unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
      
    } else {
      ledState = LOW;

    }

    // set the LED with the ledState of the variable:
  
  }
          Serial.println(ledState);
        digitalWrite(13, ledState);
        digitalWrite(32, ledState);
}
