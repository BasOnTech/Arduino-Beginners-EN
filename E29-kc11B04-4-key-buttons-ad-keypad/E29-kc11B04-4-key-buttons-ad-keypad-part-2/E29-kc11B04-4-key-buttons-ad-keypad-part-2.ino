/*
   Bas on Tech

   This course is part of the courses on https://arduino-tutorials.net

   (c) Copyright 2020 - Bas van Dijk / Bas on Tech
   This code and course is copyrighted. It is not allowed to use these courses commercially
   without explicit written approval

   YouTube:    https://www.youtube.com/c/BasOnTech
   Facebook:   https://www.facebook.com/BasOnTechChannel
   Instagram:  https://www.instagram.com/BasOnTech
   Twitter:    https://twitter.com/BasOnTech
   

   Button values:
   
   K4 1023
   K3  800
   K2  600
   K1  400
   
*/

const int AD_PIN = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {

  int adValue = analogRead(AD_PIN);
  Serial.println(buttonFromValue(adValue));

}

// Returns the button number based on the analog value
byte buttonFromValue(int adValue) {

  if (adValue > 300 && adValue < 500) {
    return 1;
  }

  if (adValue > 500 && adValue < 700) {
    return 2;
  }

  if (adValue > 700 && adValue < 900) {
    return 3;
  }

  if (adValue > 900) {
    return 4;
  }

  return 0;
  
}
