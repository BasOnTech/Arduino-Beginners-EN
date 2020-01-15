/*
   Bas on Tech - Traffic light step 4

   This course is part of the courses on https://arduino-tutorials.net

   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   This code and course is copyrighted. It is not allowed to use these courses commercially
   without explicit written approval

   YouTube:    https://www.youtube.com/c/BasOnTech
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech

*/

const int PIN_RED = 8;
const int PIN_YELLOW = 9;
const int PIN_GREEN = 10;

const int DELAY_RED = 5000;
const int DELAY_YELLOW = 1000;
const int DELAY_GREEN = 5000;

void setup()
{
  // Set pin 8 t/m 10 as output
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_YELLOW, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);

  allOff();
}

void loop()
{
  toggleLED(PIN_RED, DELAY_RED);
  toggleLED(PIN_GREEN, DELAY_GREEN);
  toggleLED(PIN_YELLOW, DELAY_YELLOW);
}

// Toggles the given LED with the given delay
void toggleLED(int led_pin, int led_delay)
{
  digitalWrite(led_pin, HIGH);
  delay(led_delay);
  digitalWrite(led_pin, LOW);
}

// Set all output to LOW in order to turn all LEDs off
void allOff()
{
  digitalWrite(PIN_RED, LOW);
  digitalWrite(PIN_YELLOW, LOW);
  digitalWrite(PIN_GREEN, LOW);
}
