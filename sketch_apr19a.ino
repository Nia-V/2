#include "slave.h"

void setup(){
Serial.begin(9600);
 Init();
 pinMode(13, OUTPUT);
}
void loop(){
delay(1000);
Serial.println("bchid");
}