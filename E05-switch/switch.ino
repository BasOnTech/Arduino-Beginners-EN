// Bas on Tech 
// This code is part of the Arduino tutorials for beginners video series
// http://BasOnTech.com

int switchPin = 12;                     // switch pin
int ledPin = LED_BUILTIN;               // Builtin LED pin
int switchState = LOW;                  // State of the switch

// Voer uit bij de start van programma
void setup() {
    Serial.begin(9600);                 // Start the serial monitor at 9600 baud
    pinMode(ledPin, OUTPUT);            // Set ledPin as output
    pinMode(switchPin, INPUT);          // Set the switchPin (12) as input
}

// The loop() function runs infinitely
void loop() {

    switchState = digitalRead(switchPin);    // Read the digital value of the switch (LOW/HIGH)
    Serial.println(switchState);             // Print the read value in the serial monitor

    if (switchState == HIGH) {               // When the button is pressed
        digitalWrite(ledPin, HIGH);          // Turn the built-in LED on
    } else {
        digitalWrite(ledPin, LOW);           // Turn the built-in LED off
    }

}
