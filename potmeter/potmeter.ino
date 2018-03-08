// Bas on Tech 
// This code is part of the Arduino tutorials for beginners video series
// http://BasOnTech.com

int potPin = 2;               // Potmeter pin
int ledPin = LED_BUILTIN;     // Builtin LED pin
int potVal = 0;               // Potmeter's value (0 by default)

void setup() {
  Serial.begin(9600);         // Start the serial monitor at 9600 baud
  pinMode(ledPin, OUTPUT);    // Set ledPin as output
}

// The loop() function runs infinitely
void loop() {
  
  potVal = analogRead(potPin);       // Read the analog value of the potmeter (0-1023)
  Serial.println(potVal);            // Write the value to the serial monitor
  
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the built-in LED on
  delay(potVal);                     // Pause for the length of the potval value (0-1023) milliseconds
  
  digitalWrite(LED_BUILTIN, LOW);    // Turn the built-in LED on
  delay(potVal);                     // Pause for the length of the potval value (0-1023) milliseconds
  
}

