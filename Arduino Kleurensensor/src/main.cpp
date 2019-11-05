#include <Arduino.h>

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define antwoordLED 12

/*
Rood: S2 Low, S3 LOW
Groen: S2 High, S3 High
Blauw: S2 Low, S3 High
*/

int Rood = 0;
int Groen = 0;
int Blauw = 0;

int roodAntwoord = 230;
int groenAntwoord = 230;
int blauwAntwoord = 230;

void setup() {

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(sensorOut, INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  Serial.begin(9600);
}
void loop() {

  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);

  Rood = pulseIn(sensorOut, LOW);

  Serial.print("R = ");
  Serial.print(Rood);
  delay(100);

  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);

  Groen = pulseIn(sensorOut, LOW);

  Serial.print(" G = ");
  Serial.print(Groen);
  delay(100);

  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);

  Blauw = pulseIn(sensorOut, LOW);

  Serial.print(" B = ");
  Serial.println(Blauw);
  delay(100);

if(Rood == roodAntwoord){
  if(Groen == groenAntwoord){
    if(Blauw == blauwAntwoord){
      digitalWrite(antwoordLED, HIGH);

    }
  }
}
}
