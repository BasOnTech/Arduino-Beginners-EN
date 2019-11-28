/*
 * Bas on Tech - Schuif potmeter
 * Deze les is onderdeel van de lessen op https://arduino-lessen.nl
 *  
 * (c) Copyright 2019 - Bas van Dijk / Bas on Tech
 * Deze code en inhoud van de lessen mag zonder schriftelijke toestemming 
 * niet voor commerciele doeleinden worden gebruikt
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTechNL
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 * 
 */

int potmeterPin = A0;              // Schuif potmeter pin op A0
int potmeterVal = 0;               // Waarde van potmeter

void setup() {
  Serial.begin(9600);              // Stel de seriële monitor in
}

// Herhaal oneindig
void loop() {
  
  potmeterVal = analogRead(potmeterPin);    // Lees de analoge waarde van de Schuif potmeter

  // Het totale bereik is 1024 stappen: 0 t/m 1023
  // In de opdracht vraag ik je van 512 t/m -512 te maken
  // Dit zijn 1025 stappen: 2 x 512 = 1024, en dan nog 1 stap voor de 0
  // Daarom moeten we controleren of het getal groter is dan 0
  // Als dit zo is dan tellen we er 1 bij op om zo op 512 uit te komen
  // in plaats van 511
  if (potmeterVal > 0) {
    potmeterVal++;
  }
  
  Serial.println(potmeterVal - 512);        // Toon de waarde in de seriële monitor

  delay(100);                               // Pauzeer 100ms
  
}
