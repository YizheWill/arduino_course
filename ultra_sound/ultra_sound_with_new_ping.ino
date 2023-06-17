#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include <NewPing.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 13
#define MAX_DISTANCE 20

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float duration, distance;
int interation = 5;
int red_light_pin = 7;
int green_light_pin = 8;

void setup()
{
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

void loop()
{
    duration = sonar.ping_median(interation);
    distance = (duration / 2) * 0.0343;
    Serial.print("Distance: ");
    if (distance >= 20 || distance <= 0)
    {
        lcd.clear();
        digitalWrite(red_light_pin, LOW);
        digitalWrite(green_light_pin, HIGH);
        lcd.setCursor(0, 0);
        lcd.print("Safe Range");
        lcd.setCursor(0, 1);
    }
    else
    {
        lcd.clear();
        digitalWrite(red_light_pin, HIGH);
        digitalWrite(green_light_pin, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Danger Range");
        lcd.setCursor(0, 1);
        lcd.print(distance);
        lcd.print(" cm");
    }
    delay(1000);
}