#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char student_name[] = "Yizhe Wang";
char class_name[] = "Robo & Embed Sys";
int time = 250;

void setup()
{
    lcd.init();
    lcd.backlight();
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print(student_name);
    lcd.setCursor(0, 1);
    lcd.print(class_name);
}
void loop() {}