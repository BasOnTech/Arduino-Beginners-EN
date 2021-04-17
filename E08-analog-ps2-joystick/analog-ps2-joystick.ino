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
 * PIN CONNECTIONS
 *
 * GND --> GND
 * +5V --> 5V
 * VRX --> A5
 * VRY --> A0
 * SW  --> 12
 *
 */


// Define the pin numbers
const int swPin = 12;
const int VrxPin = A5;
const int VryPin = A0;

// Set the initial variable values
int xDirection = 0;
int yDirection = 0;
int switchState = 1;

void setup() {
    Serial.begin(9600);

    pinMode(swPin, INPUT);

    // The joystick button is always HIGH, unless the button is pressed
    digitalWrite(swPin, HIGH);
}

void loop() {

    // Read the analog joystick values
    xDirection = analogRead(VryPin);
    yDirection = analogRead(VrxPin);

    // Read the push button state
    switchState = digitalRead(swPin);

    // Print the values read to the serial monitor
    Serial.print("Switch:  ");
    Serial.println(switchState);

    Serial.print("X-axis:        ");
    Serial.println(xDirection);

    Serial.print("Y-axis:        ");
    Serial.println(yDirection);

    Serial.println("");

    // Because the switch is HIGH when it is NOT pressed we have to invert the read values
    // We use the exclamation mark in front of the variable name which converts HIGH in LOW and vice versa
    if (!switchState) {
        Serial.println("Switch pressed");
    }

    // We do not exacty use 512 as the center of the joystick position, since the analogue value can
    // fluctuate. The center is approx. 500, therefore we use a margin of 20.

    // Determine the joystick direction on the X-axis
    if (xDirection < 480) {
        Serial.println("Left");
    } else if (xDirection > 520) {
        Serial.println("Right");
    }

    // Determine the joystick direction on the Y-axis
    if (yDirection < 480) {
        Serial.println("Down");
    } else if (yDirection > 520) {
        Serial.println("Up");
    }

    delay(500);
}
