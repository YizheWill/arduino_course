#include <Servo.h>

Servo servo1;

const int sw = 2;
const int xcoord = 0;
const int led = 11;
const int servo = 9;

int joyVal;
int brightness;

void setup()
{
    pinMode(sw, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    digitalWrite(sw, HIGH);
    servo1.attach(servo);
    Serial.begin(115200);
}

void loop()
{
    joyVal = analogRead(xcoord);
    brightness = analogRead(xcoord);
    joyVal = map(joyVal, 0, 1023, 0, 180);
    servo1.write(joyVal);
    brightness = map(brightness, 0, 1023, 0, 255);
    analogWrite(led, brightness);
    delay(5);
}