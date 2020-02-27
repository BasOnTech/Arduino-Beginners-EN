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


unsigned long previousMillis = 0;     // Previous millis
unsigned long elapsedMillis = 0;      // Elapesed millis since touch
int ledState = LOW;                   // Current LED state
int debounceTime = 1000;              // Debounce time for the touch sensor

void setup()
{
  pinMode(8, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Turn builtin LED off
  digitalWrite(LED_BUILTIN, LOW);
}

void loop()
{

  // Calculate the elapsed seconds
  elapsedMillis = millis() - previousMillis;

  // If the sensor is touched AND
  // the elapsed time is larger than the given debounce time
  if(digitalRead(8) == HIGH && elapsedMillis > debounceTime) {

    // Set ledState to LOW if it was HIGH and vice versa
    if(ledState == HIGH) {
      ledState = LOW;
    } else {
      ledState = HIGH;
    }

    // send ledState to the builtin LED
    digitalWrite(LED_BUILTIN, ledState);

    // Store the current millis on the previous millis
    previousMillis = millis();
  };

}
