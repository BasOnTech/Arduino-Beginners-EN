/*
 * Bas on Tech - Rotary Encoder
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
 * More info about the Rotary Encoder: 
 * https://en.wikipedia.org/wiki/Rotary_encoder
 * 
 * PIN CONNECTIONS
 *
 * GND --> GND black
 *  +  --> 5V  red
 * SW  --> 12  yellow
 * DT  --> 3   green (data)
 * CLK --> 4   blue (clock)
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

int xPos = 10;                                      // midden van LCD

volatile int pinA = 4;                              // Rotary encoder Pin A
int pinB = 3;                              // Rotary encoder Pin B
volatile int pinAstateCurrent = LOW;                // Current state of Pin A
volatile int pinAStateLast = pinAstateCurrent;      // Last read value of Pin A

void setup() {
  Serial.begin (9600);                              // Stel de seriële monitor in

  pinMode (pinA, INPUT);                   // Set PinA as input
  pinMode (pinB, INPUT);                   // Set PinB as input

  // Atach a CHANGE interrupt to PinB and exectute the update function when this change occurs.
  attachInterrupt(digitalPinToInterrupt(pinB), update, CHANGE);

  // LCD
  lcd.init();                  // initialise the LCD
  lcd.backlight();             // turn backlight on
  
}

void loop() {

  // LCD scherm
  lcd.clear();                  // clear the screen
  lcd.setCursor(xPos, 1);       // zet de cursor op positie xPos, regel 1
  lcd.print("#");               // schrijf op scherm

  delay(100);                   // geef LCD de tijd om karakter op scherm te tonen
  
}

void update() {

  // ROTATION DIRECTION
  pinAstateCurrent = digitalRead(pinA);    // Read the current state of Pin A
  
  // If there is a minimal movement of 1 step
  if ((pinAStateLast == LOW) && (pinAstateCurrent == HIGH)) {
    
    if (digitalRead(pinB) == HIGH) {      // If Pin B is HIGH
      xPos++;            
    } else {
      xPos--;
    }
    
  }
  
  pinAStateLast = pinAstateCurrent;        // Store the latest read value in the currect state variable

}