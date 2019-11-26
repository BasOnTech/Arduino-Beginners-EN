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

void setup() {

  // On startup, the MAX72XX chip is in power-safe mode
  // we are waking this chip for device 0 with the shutdown command
  lc.shutdown(0, false);

  // Set the intensity of the screen on device 0 with a value between 0 and 15
  lc.setIntensity(0, 5);
  
  // Clear the display of device 0
  lc.clearDisplay(0);

  // On device 0, position 0, show an 8, without decimal dot
  lc.setDigit(0, 0, 8, false);

  // On device 0, position 2, show a 5, with decimal dot
  lc.setDigit(0, 2, 5, true);

  // On device 0, position 4, show an A, without decimal dot
  lc.setChar(0, 4, 'A', false);

  //
  //      N
  //   NW   NE
  //      M
  //   SW   SE
  //      S      D
  //
  // D N NE SE S SW NW M
  lc.setRow(0, 6, B01001001);
}

void loop() {}
