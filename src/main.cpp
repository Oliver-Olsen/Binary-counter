#include <Arduino.h>
#define REDPIN 10
#define YELLOWPIN 11
#define GREENPIN 12

// put function declarations here:

void setup() {
  Serial.begin(9600); //Begins serial communication
  
  //Defines pinmodes
  pinMode(REDPIN, OUTPUT); 
  pinMode(YELLOWPIN, OUTPUT); 
  pinMode(GREENPIN, OUTPUT); 

  //Turns the red light on, and the others off
  digitalWrite(REDPIN, LOW);
  digitalWrite(YELLOWPIN, LOW);
  digitalWrite(GREENPIN, LOW);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(GREENPIN, (i % 2));
    digitalWrite(YELLOWPIN, ((i / 2) % 2)); 
    digitalWrite(REDPIN, ((i / 4) % 2)); 
    Serial.println(String(((i / 4) % 2)) + String(((i / 2) % 2)) + String((i % 2)));
    delay(500);     
  }
}
