/*
 * Bas on Tech - LDR
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

int ldrPin = A0;              // LDR pin
int ldrVal = 0;               // Value of LDR
int ledPin = LED_BUILTIN;     // Build in LED pin

void setup() {
  Serial.begin(9600);         // Initialise the serial monitor
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  ldrVal = analogRead(ldrPin);    // Read the analog value of the LDR
  Serial.println(ldrVal);         // Show the value in the serial monitor

  if (ldrVal < 200) {             // If the LDR value is lower than 200
    digitalWrite(ledPin, HIGH);   // Turn buildin LED on
  } else {
    digitalWrite(ledPin, LOW);    // Turn buildin LED off
  }

  delay(100);                     // Pause 100ms
  
}