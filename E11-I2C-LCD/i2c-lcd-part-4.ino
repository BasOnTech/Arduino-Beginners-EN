/*
 * Bas on Tech - I2C LCD
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
 * More info about I2C: https://en.wikipedia.org/wiki/I%C2%B2C
 *
 *
 * PIN CONNECTIONS
 * 
 * SDA is the serial data
 * SCL is the serial clock
 *
 * GND --> GND white
 * VCC --> 5V  grey
 * SDA --> A4  red
 * SCL --> A5  blue
 * 
 * 
 * I2C connections for each Arduino:
 * Uno, Ethernet    A4 (SDA), A5 (SCL)
 * Mega2560         20 (SDA), 21 (SCL)
 * Leonardo          2 (SDA),  3 (SCL)
 * Due              20 (SDA), 21 (SCL) or SDA1, SCL1
 *
 */

// Library for I2C / TWI device communication
#include <Wire.h> 

// Library to control the LCD screen
#include <LiquidCrystal_I2C.h>

/* 
 * Set the correct chip for your LCD
 * Use 0x27 when you have the PCF8574 chip made by NXP
 * Use 0x3F when you have the PCF8574A chip made by Ti (Texas Instruments)
 * The last two digits represent the LCD size
 * e.g. 20x4 or 16x2
 *  
 */  
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);


const int trigPin = 12;   // trigger pin
const int echoPin = 8;    // echo pin

float duration;           // variable to store duration as floating point (float)
float distance;           // variable to store distance as floating point (float)

void setup() {
  Serial.begin(9600);                    // initialise the serial monitor

  // Ultrasonic sensor
  pinMode(trigPin, OUTPUT);              // set the trigger pin as output
  pinMode(echoPin, INPUT);               // set the echo pin as input

  // LCD screen
  lcd.init();                            // initialise the LCD
  lcd.backlight();                       // turn backlight on
}

void loop() {

  // Ultrasonic sensor
  digitalWrite(trigPin, LOW);            // set the trigPin to LOW
  delayMicroseconds(2);                  // wait 2ms to make sure the trigPin is LOW
     
  digitalWrite(trigPin, HIGH);           // set the trigPin to HIGH to start sending ultrasonic sound
  delayMicroseconds(10);                 // pause 10ms
  digitalWrite(trigPin, LOW);            // set the trigPin to LOW to stop sending ultrasonic sound

  duration = pulseIn(echoPin, HIGH);     // request how long the echoPin has been HIGH
  distance = (duration * 0.0343) / 2;    // calculate the distance based on the speed of sound
                                         // we need to divide by 2 since the sound travelled the distance twice
  Serial.print("Distance: ");            // print the result to the serial monitor
  Serial.println(distance);

  // LCD screen
  lcd.clear();                           // clear screen
  lcd.setCursor(0, 0);                   // set the cursor to position 1, line 1
  lcd.print(distance);                   // write to screen
  lcd.print(" cm");                      // write to screen

  delay(100);                            // pause 100ms till the next measurement
}