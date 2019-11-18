#include <Arduino.h>
#include <Servo.h>

#define servoPin 3

int lichtDoelwaarde = 7;   //0-1023
int servoStart = 20; //0-180
int servoDoel = 160; //0-180

Servo servo1;


void setup() {
  Serial.begin(9600);
  servo1.attach(servoPin);
  servo1.write(servoStart);
}

void loop() {

  int lichtWaarde = analogRead(0);
  Serial.println(lichtWaarde);
  if(lichtWaarde <= lichtDoelwaarde){
    Serial.println("sensor geraakt!");
    servo1.write(servoDoel);
  }

}
