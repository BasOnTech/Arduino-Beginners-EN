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
 * PIN CONNECTIONS
 *
 * GND  --> GND
 * 5V --> 5V
 * Data --> 12
 *
 */

// Import the pitches per tone
#include "pitches.h"

// set the variable "buzzerPin" to 12
int buzzPin = 12;             

// Melody notes
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note duration: 4 = quarter note, 8 = eighth note etc.
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup(void) {
  pinMode(buzzPin, OUTPUT);         //  set the buzzerPin as output
}

void loop() {
  playMelody();                     // call the "playMelody" function
  delay(10000);                     // pause 10 seconds
}

void playMelody() {
  
  // iterate over all notes in melody[]
  for (int i = 0; i <= 8; i++) {

    // In order to calculate the correct note length we take 1 second and divide it by the type of note
    // for example: a quarter note is 1000 / 4, an eighth note 1000 / 8 etc.
    int noteDuration = 1000 / noteDurations[i];

    // Call tone() with the current note of the melody with the calculated duration of the note.
    tone(buzzPin, melody[i], noteDuration);

    // in order to distinguish the notes, we set a minimal pause between two notes
    // it turned out the note length plus 30% works fine.
    int pauseBetweenNotes = noteDuration * 1.30;

    // pause for the calculated duration
    delay(pauseBetweenNotes);
    
    // stop playing the current note
    noTone(buzzPin);
  }
}