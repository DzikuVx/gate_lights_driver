#include <Arduino.h>

#define CH_1 8
#define CH_2 9
#define PIN_INPUT 10

void setup()
{
    pinMode(PIN_INPUT, INPUT_PULLUP);
	pinMode(CH_1, OUTPUT);
	pinMode(CH_2, OUTPUT);
    digitalWrite(CH_1, LOW);
    digitalWrite(CH_2, LOW);
    Serial.begin(115200);
}

int candidates = 0;

unsigned long channelOff; 

void loop()
{

    int rawValue = digitalRead(PIN_INPUT);

    if (rawValue == LOW) {
        candidates++;
    } else {
        candidates = 0;
    }

    if (candidates > 2) {
        digitalWrite(CH_1, HIGH);
        channelOff = millis() + 300000;
    }

    if (channelOff < millis()) {
        digitalWrite(CH_1, LOW);
    }

    delay(1);
}
