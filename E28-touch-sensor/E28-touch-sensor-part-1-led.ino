/*
   Bas on Tech - Touch sensor

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
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Turn builtin LED off
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{
 
  if(digitalRead(8) == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);
}
