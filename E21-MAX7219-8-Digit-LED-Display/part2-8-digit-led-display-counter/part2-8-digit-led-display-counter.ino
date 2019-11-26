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

void setup() {

  // On startup, the MAX72XX chip is in power-safe mode
  // we are waking this chip for device 0 with the shutdown command
  lc.shutdown(0, false);

  // Set the intensity of the screen on device 0 with a value between 0 and 15
  lc.setIntensity(0, 5);
  
  // Clear the display of device 0
  lc.clearDisplay(0);
}

// Show a number of max 4 positions, so 0...9999
void printNumber(int number) {  
    int ones;
    int tens;
    int hundreds;
    int thousands;

    // Calculate the number of ones
    // we take the remainder when the number is divided by 10
    ones = number % 10;
    // Save the number of divides without remainder
    number = number / 10;

    // Calculate the number of tens
    // we take the remainder when the number is divided by 10
    tens = number % 10;  
    number = number / 10; 

    // Calculate the number of hundreds
    // we take the remainder when the number is divided by 10
    hundreds = number % 10;
    number = number / 10;
    
    thousands = number;

    // Show the digits on the display
    lc.setDigit(0, 3, thousands, false);
    lc.setDigit(0, 2, hundreds, false);
    lc.setDigit(0, 1, tens, false); 
    lc.setDigit(0, 0, ones, false); 
} 

void printNumber2(long number) {

  // Array of 8 bytes for each postion on the LED display
  byte digits[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  // Loop over each position to determine the number to show
  for (int i; i < 8; i++) {
      digits[i] = number % 10;
      number = number / 10;   
  }

  // Loop over all LED positions
  for (int i; i < 8; i++) {
    // Show digit on position i on the LED display
    lc.setDigit(0, i, digits[i], false);
  }
  
}


void printNumber3(long number) {

  // Array of 8 bytes for each postion on the LED display
  byte digits[8] = {0, 0, 0, 0, 0, 0, 0, 0};

  // Loop over each position to determine the number to show
  for (int i; i < 8; i++) {
      digits[i] = number % 10;
      number = number / 10;   
  }

  // True when we've found the first non-zero digit
  bool firstNonZeroFound = false;

  // Loop backwards from 7 to 0
  for (int i = 7; i >= 0; i--) {

      // If the number is not equal to 0
      if(digits[i] != 0) {
        firstNonZeroFound = true;
      } 

      // If the first non-zero number is found show this on the LED display
      if (firstNonZeroFound) {
        lc.setDigit(0, i, digits[i], false);
      }
  }
  
}

void loop() { 
  lc.clearDisplay(0);
  printNumber3(i);
  i++;
  delay(100);
}
