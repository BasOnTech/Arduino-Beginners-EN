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

// Library for I2C / TWI device communication
#include <Wire.h> 

// Library to control the LCD screen
#include <LiquidCrystal_I2C.h>

/* 
 * Set the correct chip for your LCD
 * Use 0x27 when you have the PCF8574 chip made by NXP
 * Use 0x3F when you have the PCF8574A chip made by Ti (Texas Instruments)
 * The last two digits represent the LCD size
 * e.g. 20x4 or 16x2
 *  
 */  
LiquidCrystal_I2C lcd(0x27, 20, 4);
//LiquidCrystal_I2C lcd(0x3F, 16, 2);

/* 
 * De onderstaande symbolen zijn online gemaakt met de LCD symbool generator op:
 * https://maxpromer.github.io/LCD-Character-Creator/
 */

// Degree symbol
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

// Water drop
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

#include "DHT.h"             // Library for DHT sensors

#define dhtPin 12            // data pin

/*
 * Uncomment the correct DHT chip
 */
#define dhtType DHT11        // DHT 11
//#define dhtType DHT22      // DHT 22 (AM2302), AM2321
//#define dhtType DHT21      // DHT 21 (AM2301)

DHT dht(dhtPin, dhtType);    // Initialise the DHT library

float humidityVal;           // humidity
float tempValC;              // temperature in degrees Celcius
float tempValF;              // temperature in degrees Fahrenheit
float heatIndexC;            // windchill in degrees Celcius
float heatIndexF;            // windchill in degrees Fahrenheit

void setup() {
  Serial.begin(9600);        // Initialise the serial monitor

  // LCD screen
  lcd.init();                // initialise the LCD
  lcd.backlight();           // turn backlight on
  lcd.createChar(1, degree); // define a symbol for memory position 1
  lcd.createChar(2, humid);  // define a symbol for memory position 2
  lcd.createChar(3, temp);   // define a symbol for memory position 3

  // DHT sensor
  dht.begin();               // start with reading the DHT sensor
}

void loop() {

  humidityVal = dht.readHumidity();        // get the humidity from the DHT sensor
  tempValC = dht.readTemperature();        // get the temperature in degrees Celcius from the DHT sensor
  tempValF = dht.readTemperature(true);    // get the temperature in degrees Fahrenheit from the DHT sensor

  // Check if all values are read correctly, if not try again and exit loop()
  if (isnan(humidityVal) || isnan(tempValC) || isnan(tempValF)) {
    Serial.println("Reading DHT sensor failed!");

    // end the loop() function
    return;
  }

  lcd.clear();                 // clear the screen
  
  // Calculate the windchill in degrees Celcius
  heatIndexC = dht.computeHeatIndex(tempValC, humidityVal, false);

  // Calculate the windchill in degrees Fahrenheit
  heatIndexF = dht.computeHeatIndex(tempValF, humidityVal);

  // Print all values on the LCD
  lcd.setCursor(0, 0);         // set the cursor to position 1, line 1
  lcd.write(2);
  lcd.print(" ");
  lcd.print(humidityVal);
  lcd.print("%");

  lcd.setCursor(0, 1);         // set the cursor to position 1, line 2
  lcd.write(3);
  lcd.print(" ");
  lcd.print(tempValC);
  lcd.write(1);
  lcd.print("C ");

  lcd.setCursor(0, 3);         // set the cursor to position 1, line 4
  lcd.write(3);
  lcd.print(" ");
  lcd.print(heatIndexC);
  lcd.write(1);
  lcd.print("C ");
  
  delay(2000);
}