#include <cww_MorseTx.h>

#define CW_SPEED 15

#define TONE_FREQ 1000

#ifdef ESP32
#define PIN_LED 2
#define PIN_SND 16
#define PIN_BTN 4
#else
#define PIN_LED 13
#define PIN_SND 3
#define PIN_BTN 4
#endif

//Configuration
String morseMessage = "ZS6STN";
int repeatTimes = 3;
int delayBetweenRepeatsSeconds = 2;
int delaySilentTimeSeconds = 10;
  
cww_MorseTx morseWithTone(PIN_LED, CW_SPEED, PIN_SND, TONE_FREQ);

void setup() {}

void loop() {
  for (int i = 0; i < repeatTimes; i++)
  {
    morseWithTone.send(morseMessage.c_str());
    delay(delayBetweenRepeatsSeconds * 1000);
  }

  delay(delaySilentTimeSeconds * 1000);
}
