/*
 * Bas on Tech - RFID reader
 *
 * This course is part of the courses on https://arduino-tutorials.net
 *  
 * (c) Copyright 2019 - Bas van Dijk / Bas on Tech
 * This code and course is copyrighted. It is not allowed to use these courses commercially
 * without explicit written approval
 * 
 * YouTube:    https://www.youtube.com/c/BasOnTech
 * Facebook:   https://www.facebook.com/BasOnTechChannel
 * Instagram:  https://www.instagram.com/BasOnTech
 * Twitter:    https://twitter.com/BasOnTech
 *
 * ---------------------------------------------------------------------------
 *
 * WARNING: The security of these RFID cards are WEAK. Do not use them for serious security.
 * The card numbers don't have to be unqiue. Some Chinese cards allow their number to 
 * be changed.
 * 
 * Pin layout:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */

#include <SPI.h>                      // SPI library
#include <MFRC522.h>                  // MFRC522 library

const int pinRST =  9;                // Reset pin
const int pinSS =  10;                // Serial data pin

MFRC522 mfrc522(pinSS, pinRST);       // Initialise the MFRC522 on pinSS and pinRST

// Print all card data to the serial monitor
void dumpCardData() {
  
  // If there is a new card found AND
  // If card data is read
  // PICC = Proximity Integrated Circuit Card
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      // Dump the card data to the serial monitor
      mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  }

}

void setup() {
  Serial.begin(9600);   // Initialise the serial monitor

  SPI.begin();          // Initialise the SPI bus
  mfrc522.PCD_Init();   // Initialise the MFRC522 reader

  // Print MFRC522 Card Reader details to the serial monitor
  mfrc522.PCD_DumpVersionToSerial();

  Serial.println("Present card to the RFID scanner...");
}

void loop() {
  dumpCardData();
}