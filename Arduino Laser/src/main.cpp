#include <Arduino.h>
#include <Servo.h>

#define servoPin 3

int lichtDoelwaarde = 250;   //0-1023
int servoStart = 0; //0-180
int servoDoel = 180; //0-180

Servo servo1;


void setup() {

  servo1.attach(servoPin);
  servo1.write(servoStart);
}

void loop() {

  int lichtWaarde = analogRead(0);

  if(lichtWaarde >= lichtDoelwaarde){
    servo1.write(servoDoel);
  }

}
