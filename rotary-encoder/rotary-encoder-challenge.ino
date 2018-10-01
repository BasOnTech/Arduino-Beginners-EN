/*
 * Bas on Tech - https://arduino-lessen.nl
 * 
 * Meer informatie over Rotary Encoder: 
 *   https://nl.wikipedia.org/wiki/Encoder
 *   https://en.wikipedia.org/wiki/Rotary_encoder
 *
 * Meer informatie over interrupts:
 *   https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 *
 *
 * PIN AANSLUITINGEN
 *
 * GND --> GND zwart
 *  +  --> 5V  rood
 * SW  --> 12  geel
 * DT  --> 3   groen (data)
 * CLK --> 2   blauw (clock)
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

int xPos = 10;                                      // midden van LCD

volatile int pinA = 2;                              // Rotary encoder Pin A
int pinB = 3;                                       // Rotary encoder Pin B
volatile int pinAstateCurrent = LOW;                // Huidige staat van Pin A
volatile int pinAStateLast = pinAstateCurrent;      // Laatst gelezen staat van Pin A

void setup() {
  Serial.begin (9600);                              // Stel de seriële monitor in

  pinMode(pinA, INPUT);                             // Stel pinA in als invoer

  // Koppel een interrupt op PinA voor als deze veranderd (CHANGE) en voer de update functie
  // uit als deze verandering plaatsvindt.
  attachInterrupt(digitalPinToInterrupt(pinA), update, CHANGE);
  
  pinMode (pinB, INPUT);        // Stel de pinB in als invoer

  // LCD scherm
  lcd.init();                   // initialiseer het LCD scherm
  lcd.backlight();              // zet de backlight aan
  
}

void loop() {

  // LCD scherm
  lcd.clear();                  // wis het scherm
  lcd.setCursor(xPos, 1);       // zet de cursor op positie xPos, regel 1
  lcd.print("#");               // schrijf op scherm

  delay(100);                   // geef LCD de tijd om karakter op scherm te tonen
  
}

void update() {

  // ROTATIE RICHTING
  pinAstateCurrent = digitalRead(pinA);    // Lees de huidige staat van Pin A
  
  // Als er minimaal 1 tik gedraaid is
  if ((pinAStateLast == LOW) && (pinAstateCurrent == HIGH)) {
    
    if (digitalRead(pinB) == HIGH) {       // Als Pin B vervolgens HIGH is
      xPos--;                              // Verlaag de x positie met 1
    } else {
      xPos++;                              // Verhoog de x positie met 1
    }
    
  }
  
  pinAStateLast = pinAstateCurrent;        // Stel de laatst gelezen staat in op de huidige staat

}