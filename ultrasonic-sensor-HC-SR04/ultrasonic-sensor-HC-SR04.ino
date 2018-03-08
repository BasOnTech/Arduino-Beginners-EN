/*
 * Bas on Tech - Arduino tutorial 7
 * http://BasOnTech.com
 * 
 * Original code from:
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 *
 * PIN CONNECTIONS
 *
 * Vcc  --> 5V
 * Trig --> 12
 * Echo --> 8
 * GND  --> GND
 *
 */

const int trigPin = 12;   // trigger pin
const int echoPin = 8;    // echo pin

float duration;           // variable to store the duration as float
float distance;           // variable to store the distance as float

void setup() {
  Serial.begin(9600);               // initialize the serial monitor
  pinMode(trigPin, OUTPUT);         // set the trigger pin as output
  pinMode(echoPin, INPUT);          // set the echo pin as input
}

void loop() {
  digitalWrite(trigPin, LOW);       // set the trigPin to LOW
  delayMicroseconds(2);             // wait 2ms to make sure the trigPin is LOW

  digitalWrite(trigPin, HIGH);      // set the trigPin to HIGH to start sending ultrasonic sound
  delayMicroseconds(10);            // pause 10ms
  digitalWrite(trigPin, LOW);       // set the trigPin to LOW to stop sending ultrasonic sound

  duration = pulseIn(echoPin, HIGH);     // request how long the echoPin has been HIGH
  distance = (duration * 0.0343) / 2;    // calculate the distance based on the speed of sound
                                         // we need to divide by 2 since the sound travelled the distance twice
  Serial.print("Distance: ");             // Print the result to the serial monitor
  Serial.println(distance);

  delay(100);                            // pause 100ms till the next measurement
}