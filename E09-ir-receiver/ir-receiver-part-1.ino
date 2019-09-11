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
 * Original code by:
 * http://arcfn.com door Ken Shirriff
 *
 */

// Import the IR-remote library
#include <IRremote.h>

int IrReceiverPin = 12;                 // Turn the variable "IrReceiverPin" to pin 12
IRrecv irrecv(IrReceiverPin);           // create a new instance of "irrecv" and save this instance in variabele "IRrecv"
decode_results results;                 // define the variable "results" to store the received button code

void setup()
{
    Serial.begin(9600);                 // Initialise the serial monitor

    pinMode(LED_BUILTIN, OUTPUT);       // Initialise digitale pin LED_BUILTIN as output

    // When the IR-remote library crashes we can see it from the shown text
    Serial.println("Starting IR-receiver...");

    irrecv.enableIRIn();                // start the IR-receiver

    Serial.println("IR-receiver active");

    digitalWrite(LED_BUILTIN, LOW);     // Turn off the builtin LED
}


void loop() {

    // When the IR-receiver receives a signal
    if (irrecv.decode(&results)) {

        // Print the received value as a hexadecimal value
        Serial.println(results.value, HEX);

        // Resume the IR-receiver to listen for new signals
        irrecv.resume();

        // Determine which button has been pressed
        switch (results.value) {
            case 0xFF42BD:  // button *
                digitalWrite(LED_BUILTIN, HIGH);   // Turn LED on
                break;

            case 0xFF52AD:  // button #
                digitalWrite(LED_BUILTIN, LOW);    // Turn LED off
                break;        
        }

    }
  
    delay(100);      // pause 100ms
}