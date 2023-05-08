#include <cww_MorseTx.h>

#define CW_SPEED 15

#define TONE_FREQ 1000

#ifdef ESP32
#define PIN_LED 2
#define PIN_SND 16
#define PIN_BTN 4
#define PIN_PTT 5
#else
#define PIN_LED 13
#define PIN_SND 2  // To MIC +
#define PIN_PTT 5 // To PTT
#define PIN_BTN 4
#endif

//Configuration
String morseMessage = "ZS6STN";
int repeatTimes = 3;
int delayBetweenRepeatsSeconds = 2;
int delaySilentTimeSeconds = 10;
  
cww_MorseTx morseWithTone(PIN_LED, CW_SPEED, PIN_SND, TONE_FREQ);

void setup() {
  pinMode(PIN_PTT, OUTPUT);
  digitalWrite(PIN_PTT, LOW);
}

void loop() {
  for (int i = 0; i < repeatTimes; i++)
  {
    digitalWrite(PIN_PTT, LOW);
    delay(500);
    morseWithTone.send(morseMessage.c_str());
    
    delay(delayBetweenRepeatsSeconds * 1000);
    digitalWrite(PIN_PTT, HIGH);
  }
  digitalWrite(PIN_PTT, HIGH);
  delay(delaySilentTimeSeconds * 1000);
}
