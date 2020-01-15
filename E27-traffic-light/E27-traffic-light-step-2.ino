/*
   Bas on Tech - Traffic light step 2

   This course is part of the courses on https://arduino-tutorials.net

   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   This code and course is copyrighted. It is not allowed to use these courses commercially
   without explicit written approval

   YouTube:    https://www.youtube.com/c/BasOnTech
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech

*/


const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;

void setup()
{
  // Set pin 8 t/m 10 as output
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);

  // Set all output to LOW in order to turn all LEDs off
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
}

void loop()
{
  // Red
  digitalWrite(PIN_RED, HIGH);
  delay(5000);
  digitalWrite(PIN_RED, LOW);

  // Green
  digitalWrite(PIN_GREEN, HIGH);
  delay(5000);
  digitalWrite(PIN_GREEN, LOW);

  // Orange / Yellow
  digitalWrite(PIN_YELLOW, HIGH);
  delay(1000);
  digitalWrite(PIN_YELLOW, LOW);
}