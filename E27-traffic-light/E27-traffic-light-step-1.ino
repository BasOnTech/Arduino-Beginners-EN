/*
   Bas on Tech - Traffic light step 1

   This course is part of the courses on https://arduino-tutorials.net

   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   This code and course is copyrighted. It is not allowed to use these courses commercially
   without explicit written approval

   YouTube:    https://www.youtube.com/c/BasOnTech
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech

*/

void setup()
{
  // Set pin 8 t/m 10 as output
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  // Set all output to LOW in order to turn all LEDs off
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void loop()
{
  // Red
  digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(8, LOW);

  // Green
  digitalWrite(10, HIGH);
  delay(5000);
  digitalWrite(10, LOW);

  // Orange / Yellow
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
}
