/*
   FSM assignment
*/

#include <Arduino.h>
#include <Wire.h>
//enum State {Zero = 0000, One = 0001, Two = 0010, Three = 0011, Four = 0100, Five = 0101, Six = 0110, Seven = 0111, Eight = 1000, Nine = 1001, Ten = 1010, Eleven = 1011, Twelve = 1100, Thirteen = 1101, Fourteen = 1110, Fifteen = 1111, currentState = Zero};
enum State {ZeroUp, OneUp, TwoUp, ThreeUp, FourUp, FiveUp, SixUp, SevenUp, ZeroDown, OneDown, TwoDown, ThreeDown, FourDown, FiveDown, SixDown, SevenDown};

State currentState = ZeroUp;

int incomingByte = 0;
// bool isReversed = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  switch (currentState) {
    case ZeroUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = SevenDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("0 : 000");
        currentState = OneUp;
        Serial.println();
        delay(500);
      break;
    case OneUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = ZeroDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("1 : 001");
        currentState = TwoUp;
        Serial.println();
        delay(500);
      break;
    case TwoUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = OneDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("2 : 010");
        currentState = ThreeUp;
        Serial.println();
        delay(500);
      break;
    case ThreeUp:
    incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = TwoDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("3 : 011");
        currentState = FourUp;
        Serial.println();
        delay(500);
      break;
    case FourUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = ThreeDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("4 : 100");
        currentState = FiveUp;
        Serial.println();
        delay(500);
      break;
    case FiveUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = FourDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("5 : 101");
        currentState = SixUp;
        Serial.println();
        delay(500);
      break;
    case SixUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = FiveDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("6 : 110");
        currentState = SevenUp;
        Serial.println();
        delay(500);
      break;
    case SevenUp:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = SixDown;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("7 : 111");
        currentState = ZeroUp;
        Serial.println();
        delay(500);
      break;
    case ZeroDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = OneUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("0 : 000");
        currentState = SevenDown;
        Serial.println();
        delay(500);
      break;
    case OneDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = TwoUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("1 : 001");
        currentState = ZeroDown;
        Serial.println();
        delay(500);
      break;
    case TwoDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = ThreeUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("2 : 010");
        currentState = OneDown;
        Serial.println();
        delay(500);
      break;
    case ThreeDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = FourUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("3 : 011");
        currentState = TwoDown;
        Serial.println();
        delay(500);
      break;
    case FourDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = FiveUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("4 : 100");
        currentState = ThreeDown;
        Serial.println();
        delay(500);
      break;
    case FiveDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = SixUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("5 : 101");
        currentState = FourDown;
        Serial.println();
        delay(500);
      break;
    case SixDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = SevenUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("6 : 110");
        currentState = FiveDown;
        Serial.println();
        delay(500);
      break;
    case SevenDown:
      incomingByte = Serial.read();
      if (incomingByte > 0) {
          Serial.print("Reverse");
          currentState = ZeroUp;
          Serial.println();
          delay(500);
      }
      else 
        Serial.print("7 : 111");
        currentState = ZeroDown;
        Serial.println();
        delay(500);
      break;

  }
}

bool checkReverse() {

}

//  incomingByte = Serial.read();
//  if(incomingByte != 'null'){
//    Serial.print("Reverse");
//    bool isReversed = true;
  
//   if (Serial.available() > 0) {
//    Serial.print("Reverse");
//    bool isReversed = true;
//  }
//
