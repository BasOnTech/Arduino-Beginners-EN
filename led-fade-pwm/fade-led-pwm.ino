// Bas on Tech 
// This code is part of the Arduino tutorials for beginners video series
// http://BasOnTech.com

// Define the pin used for our LED
int ledPin = 11;

// The setup() function only runs when the program starts
void setup() {
  // Initilize the digital pin LED_BUILTIN as output
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop() function runs infinitely
void loop() {

  // Fade in
  for(int ledVal = 0; ledVal <= 255; ledVal +=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  }  

  // Fade uit
  for(int ledVal = 255; ledVal >= 0; ledVal -=1) {
    analogWrite(ledPin, ledVal);
    delay(15);
  } 
  
  // Pause for 1 second (1000 milliseconds)
  delay(1000);
  
}
