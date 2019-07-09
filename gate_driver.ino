#include <Arduino.h>

#define CH_1 8
#define CH_2 9

void setup()
{
	pinMode(CH_1, OUTPUT);
	pinMode(CH_2, OUTPUT);
    digitalWrite(CH_1, LOW);
    digitalWrite(CH_2, LOW);
}

void loop()
{
	delay(1000);
    digitalWrite(CH_1, !digitalRead(CH_1));
}
