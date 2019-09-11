/*
 * Bas on Tech
 * This course is part of the courses on https://arduino-tutorials.net
 *  
 * (c) Copyright 2018-2019 - Bas van Dijk / Bas on Tech
 * This code and course is copyrighted. It is not allowed to use these courses commerically
 * without explicit written approval
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTech
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 * 
 */

// The setup() function only runs when the program starts
void setup() {
  // Initilize the digital pin LED_BUILTIN as output
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop() function runs infinitely
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the built-in LED on
  delay(1000);                       // Pause for 1 second (1000 milliseconds)
  
  digitalWrite(LED_BUILTIN, LOW);    // Turn the built-in LED on
  delay(1000);                       // Pause for 1 second (1000 milliseconds)
}