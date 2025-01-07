#include <Arduino.h>
#define REDPIN 10
#define YELLOWPIN 11
#define GREENPIN 12

void setup() {
  Serial.begin(9600); //Begins serial communication
  
  //Defines pinmodes
  pinMode(REDPIN, OUTPUT); 
  pinMode(YELLOWPIN, OUTPUT); 
  pinMode(GREENPIN, OUTPUT); 

  //ensures the lights are off
  digitalWrite(REDPIN, LOW);
  digitalWrite(YELLOWPIN, LOW);
  digitalWrite(GREENPIN, LOW);
}

void loop() {
  //Three bits give a total of 2^3 = 8 different combinations. As such we run a for loop for eight times
  for (int i = 0; i < 8; i++) {
    int LSB = (i % 2); //For the least significant bit, we run a modulus with two, which equals on, whenever 'i' is uneven
    int MB = ((i / 2) % 2); //For the middle bit, we first divide 'i' with two, which gets rounded down, before using modulus. This makes the value switch between 1 and 0 for every other number
    int MSB = ((i / 4) % 2); //For the most significant bit we do the same as with the middle bit, but divide with 4 instead, making it change only every four times. 
    //Writes the bit values to the LEDs
    digitalWrite(GREENPIN, LSB); 
    digitalWrite(YELLOWPIN, MB); 
    digitalWrite(REDPIN, MSB); 
    //Prints out the current bits
    Serial.println(String(MSB) + String(MB) + String(LSB)); //Converts the individual bits to strings, in order to combine them
    delay(500); //A 500ms pause between counting one up
  }
}

//2d: 
//We did use the % operator