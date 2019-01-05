/*
 * Bas on Tech
 * This course is part of the courses on https://arduino-lessons.com
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
 * PIN CONNECTIONS DHT11 & DHT22
 *
 * Vcc  --> 3.3V
 * Data --> 12
 * NC
 * GND  --> GND
 *
 * 4K7 (4700) Ohm resistor between 3.3V and Data pin
 *
 *
 * PIN CONNECTIONS LCD
 * 
 * SDA is serial data
 * SCL is serial clock
 *
 * GND --> GND white
 * VCC --> 5V  grey
 * SDA --> A4  red
 * SCL --> A5  blue
 * 
 * I2C connections per Arduino:
 * Uno, Ethernet    A4 (SDA), A5 (SCL)
 * Mega2560         20 (SDA), 21 (SCL)
 * Leonardo          2 (SDA),  3 (SCL)
 * Due              20 (SDA), 21 (SCL) of SDA1, SCL1
 *
 */

// Bibliotheek voor communicatie met I2C / TWI apparaten
#include <Wire.h> 

// Bibliotheek voor het LCD scherm
#include <LiquidCrystal_I2C.h>

/* 
 * Stel hier in welke chip en foromaat LCD je hebt
 * Gebruik 0x27 als je chip PCF8574 hebt van NXP
 * Gebruik 0x3F als je chip PCF8574A hebt van Ti (Texas Instruments)
 * De laatste twee getallen geven het formaat van je LCD aan
 * bijvoorbeeld 20x4 of 16x2
 *  
 */  
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

/* 
 * De onderstaande symbolen zijn online gemaakt met de LCD symbool generator op:
 * https://maxpromer.github.io/LCD-Character-Creator/
 */

// Graden symbool
byte degree[] = {
  0x07,
  0x05,
  0x07,
  0x00,
  0x00,
  0x00,
  0x00,
  0x00
};

// Druppel
byte humid[] = {
  0x04,
  0x04,
  0x0E,
  0x0E,
  0x1F,
  0x1F,
  0x1F,
  0x0E
};

// Thermometer
byte temp[] = {
  0x04,
  0x0A,
  0x0A,
  0x0A,
  0x0E,
  0x1F,
  0x1F,
  0x0E
};

#include "DHT.h"             // Bibliotheek voor DHT sensoren

#define dhtPin 12            // data pin

/*
 * Stel hier in welke DHT chip je gebruikt
 */
#define dhtType DHT11        // DHT 11
//#define dhtType DHT22      // DHT 22  (AM2302), AM2321
//#define dhtType DHT21      // DHT 21 (AM2301)

DHT dht(dhtPin, dhtType);    // Initialiseer de DHT bibliotheek

float humidityVal;           // luchtvochtigheid
float tempValC;              // temperatuur in graden Celcius
float tempValF;              // temperatuur in graden Fahrenheit
float heatIndexC;            // gevoelstemperatuur in graden Celcius
float heatIndexF;            // gevoelstemperatuur in graden Fahrenheit

void setup() {
  Serial.begin(9600);        // stel de seriële monitor in

  // LCD
  lcd.init();                  // initialiseer het LCD scherm
  lcd.backlight();             // zet de backlight aan
  lcd.createChar(1, degree);   // definieer een symbool in geheugen positie 1
  lcd.createChar(2, humid);   // definieer een symbool in geheugen positie 1
  lcd.createChar(3, temp);   // definieer een symbool in geheugen positie 1

  // DHT sensor
  dht.begin();               // start het DHT sensor uitlezen
}

void loop() {

  humidityVal = dht.readHumidity();        // vraag de luchtvochtigheid aan de DHT sensor
  tempValC = dht.readTemperature();        // vraag de temperatuur in graden Celcius aan de DHT sensor
  tempValF = dht.readTemperature(true);    // vraag de temperatuur in graden Fahrenheit aan de DHT sensor

  // Controleer of alle waarden goed zijn uitgelezen, zo niet probeer het opnieuw
  if (isnan(humidityVal) || isnan(tempValC) || isnan(tempValF)) {
    Serial.println("Uitlezen van DHT sensor mislukt!");

    // Beëindig de loop() functie
    return;
  }

  lcd.clear();                 // wis het scherm
  
  // Bereken de gevoelstemperatuur in graden Celcius
  heatIndexC = dht.computeHeatIndex(tempValC, humidityVal, false);

  // Bereken de gevoelstemperatuur in graden Fahrenheit
  heatIndexF = dht.computeHeatIndex(tempValF, humidityVal);

  // Print alle waarden naar de LCD
  lcd.setCursor(0, 0);         // zet de cursor op positie 1, regel 1
  lcd.write(2);
  lcd.print(" ");
  lcd.print(humidityVal);
  lcd.print("%");

  lcd.setCursor(0, 1);         // zet de cursor op positie 1, regel 2
  lcd.write(3);
  lcd.print(" ");
  lcd.print(tempValC);
  lcd.write(1);
  lcd.print("C ");

  lcd.setCursor(0, 3);         // zet de cursor op positie 1, regel 4
  lcd.write(3);
  lcd.print(" ");
  lcd.print(heatIndexC);
  lcd.write(1);
  lcd.print("C ");
  
  delay(2000);
}