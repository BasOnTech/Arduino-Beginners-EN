// Bas on Tech 
// This code is part of the Arduino tutorials for beginners video series
// http://BasOnTech.com

// The setup() function only runs when the program starts
void setup() {
  // Initilize the digital pin LED_BUILTIN as output
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop() function runs infinitely
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the built-in LED on
  delay(1000);                       // Pause for 1 second (1000 milliseconds)
  
  digitalWrite(LED_BUILTIN, LOW);    // Turn the built-in LED on
  delay(1000);                       // Pause for 1 second (1000 milliseconds)
}