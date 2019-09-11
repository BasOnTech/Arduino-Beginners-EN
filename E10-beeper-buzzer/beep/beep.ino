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
 * ---------------------------------------------------------------------------
  *
 * PIN CONNECTIONS
 *
 * GND  --> GND
 * 5V --> 5V
 * Data --> 12
 *
 */

static const int buzzerPin = 12;    // set the variable "buzzerPin" to pin 12

void setup(void) {
  pinMode(buzzerPin, OUTPUT);       // set the buzzerPin as output
}

void loop() {
  beep();                           // execute the "beep" function
  delay(5000);                      // pause 5s
}

void beep() {
  tone(buzzerPin, 196, 200);        // give a tone on the buzzerPin, at 196hz for, 200ms  
}
