// The next three lines are optional and are used to change the tone channel from the default of channel 0.
//#ifdef ESP32
//#define TONE_CHANNEL 15
//#endif

#include <cww_MorseTx.h>

#define CW_SPEED 15

#define TONE_FREQ 1000

#ifdef ESP32
#define PIN_LED 2
#define PIN_SND 16
#define PIN_BTN 4
#else
#define PIN_LED 2
#define PIN_SND 3
#define PIN_BTN 4
#endif

// Construct a cww_MorseTx instance that will send Morse Code at 15 words
// per minute on I/O pin 2. Output is active HIGH.
cww_MorseTx morse(PIN_LED, CW_SPEED);

// Construct a cww_MorseTx instance that will send Morse Code at 15 words
// per minute on I/O pin 2. Output is active LOW.
cww_MorseTx morseInverted(PIN_LED, CW_SPEED, true);

// Construct a cww_MorseTx instance that will send Morse Code at 15 words
// per minute on I/O pin 2 with a 1000 Hz sidetone on I/O pin 3. Output
// is active HIGH.
cww_MorseTx morseWithTone(PIN_LED, CW_SPEED, PIN_SND, TONE_FREQ);

// Construct a cww_MorseTx instance that will send Morse Code at 15 words
// per minute on I/O pin 2 with a 1000 Hz sidetone on I/O pin 3. Output
// is active LOW.
cww_MorseTx morseWithToneInverted(PIN_LED, CW_SPEED, PIN_SND, TONE_FREQ, true);

void setup() {
}

void loop() {
  string morseMessage = "ZS6STN";
  int repeatTimes = 3;
  
  // Send a string in Morse Code
  for (int i = 0; i < repeatTimes; i++)
  {
    morseWithTone.send(morseMessage);
    delay(2000);
  }

  delay(5000);
}
