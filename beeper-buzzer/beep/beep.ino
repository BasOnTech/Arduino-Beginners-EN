/*
 * Bas on Tech - Arduino tutorial
 * http://BasOnTech.com
 * 
 *
 * PIN CONNECTIONS
 *
 * GND  --> GND
 * 5V --> 5V
 * Data --> 12
 *
 */

static const int buzzerPin = 12;    // set the variable "buzzerPin" to pin 12

void setup(void) {
  pinMode(buzzerPin, OUTPUT);       // set the buzzerPin as output
}

void loop() {
  beep();                           // execute the "beep" function
  delay(5000);                      // pause 5s
}

void beep() {
  tone(buzzerPin, 196, 200);        // give a tone on the buzzerPin, at 196hz for, 200ms  
}
