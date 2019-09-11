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

/* 
 * The heart symbol has been made with the online LCD symbol generator:
 * https://maxpromer.github.io/LCD-Character-Creator/
 */
byte heart[] = {
  0x00,
  0x0A,
  0x1F,
  0x1F,
  0x0E,
  0x04,
  0x00,
  0x00
};
 
void setup() {
  lcd.init();                  // initialise the LCD
  lcd.backlight();             // turn backlight on
  lcd.clear();                 // clear the screen

  lcd.createChar(1, heart);    // define a symbol for memory position 1
  lcd.setCursor(0, 1);         // set the cursor to position 1, line 2
  lcd.print("  I ");           // write on the screen
  lcd.write(1);                // write symbol from memory position 1
  lcd.print(" BasOnTech.com"); // write on the screen
}
 
void loop() {}