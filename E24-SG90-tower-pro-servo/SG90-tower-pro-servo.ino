/*
 * Bas on Tech - SG90 tower pro servo
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
 * Servo specifications https://servodatabase.com/servo/towerpro/sg90
 * 
 * Brown  -> GND
 * Red    -> 5V
 * Orange -> A8
 * 
 */

#include <Servo.h>    // Import the Servo library to control the servo

Servo servo;          // Initialise the servo object to control the servo

int pos = 10;         // variable for the position of the servo

void setup() {
  servo.attach(8);    // Tell the servo object that we've connected to pin 8
  servo.write(0);     // Helps to adjust the initial position
  delay(40);  
}

void loop() {
  
  // Make the pos variabele go from 0 to 180
  for (pos = 0; pos <= 180; pos++) {
    servo.write(pos);  // Set the position of the servo
    delay(10);         // Wait for 10ms for the servo to process the command
  }

  // Make the pos variabele go from 180 to 0
  for (pos = 180; pos >= 0; pos--) {
    servo.write(pos);  // Set the position of the servo
    delay(10);         // Wait for 10ms for the servo to process the command
  }
 
}
