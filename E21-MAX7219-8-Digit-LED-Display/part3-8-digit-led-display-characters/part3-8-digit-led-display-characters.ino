/*
 * Bas on Tech - 8 segment LED display
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
 * ----------------------------------------------------------------------
 * 
 * LedControl library: https://github.com/wayoda/LedControl
 * 
 */

#include "LedControl.h"

// Initialise the LedControl library
// pin 7 on DIN, 
// pin 6 on Clk, 
// pin 5 on LOAD
// number of displays: 1
LedControl lc = LedControl(7, 6, 5, 1);

int i = 0;

String charString = "0123456789ABCDEFGHIJLNOPQRSTUYabcdefghijlnopqrstuy,-/\[]._";
char charBuf[60];

void setup() {
  // On startup, the MAX72XX chip is in power-safe mode
  // we are waking this chip for device 0 with the shutdown command
  lc.shutdown(0, false);

  // Set the intensity of the screen on device 0 with a value between 0 and 15
  lc.setIntensity(0, 5);
  
  // Clear the display of device 0
  lc.clearDisplay(0);

  // Copy the charString to an array of characters in charBuf
  charString.toCharArray(charBuf, 60);
}

void loop() { 

  // Show character of device 0,
  // On LED position i % 8 (the remainder of a division by 8)
  // with the character of charBuf[i]
  // without decimal dot
  lc.setChar(0, i % 8, charBuf[i], false);
  i++;

  // If we have iterated over all 60 characters
  if (i > 60) {
    i = 0;
  }
  
  delay(250);
}
