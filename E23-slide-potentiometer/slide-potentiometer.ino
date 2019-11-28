/*
 * Bas on Tech - Slide potentiometer
 *
 * This course is part of the courses on https://arduino-tutorials.net
 *  
 * (c) Copyright 2019 - Bas van Dijk / Bas on Tech
 * This code and course is copyrighted. It is not allowed to use these courses commercially
 * without explicit written approval
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTech
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 *
 */

int potmeterPin = A0;              // Slide potentiometer on pin A0
int potmeterVal = 0;               // Slide potentiometer value

void setup() {
  Serial.begin(9600);              // Initialise the serial monitor
}

void loop() {
  
  potmeterVal = analogRead(potmeterPin);    // Read the analog value of the slide potentiometer
  
  Serial.println(potmeterVal);              // Show the value on the serial monitor

  delay(100);                               // Pause 100ms
  
}
