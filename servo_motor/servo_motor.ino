#include <Servo.h>

Servo servo1;

const int sw = 2;
const int ycord = 0;
const int xcord = 1;
const int led = 11;
const int servo = 9;

int joyValX;
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
    joyValX = analogRead(xcord);

    brightness = analogRead(ycord);
    joyValX = map(joyValX, 0, 1023, 180, 0);
    servo1.write(joyValX);
    brightness = map(brightness, 0, 1023, 0, 255);
    analogWrite(led, brightness);
    delay(5);
}