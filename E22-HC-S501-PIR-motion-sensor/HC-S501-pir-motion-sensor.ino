/*
 * Bas on Tech - HCS501 PIR motion sensor
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

int ledPin = 13;   // Buildin LED on pin 13 of the Arduino
int pirPin = 12;   // Pin for the HC-S501 sensor
int pirValue;      // Value of the PIR

void setup() {
  pinMode(ledPin, OUTPUT);    // Set the ledPin as output
  pinMode(pirPin, INPUT);     // Set the pirPin as input
  digitalWrite(ledPin, LOW);  // Turn off of the buildin LED
}

void loop() {
  pirValue = digitalRead(pirPin); // Read the PIR value
  digitalWrite(ledPin, pirValue); // Write the PIR value to the buildin LED
}
