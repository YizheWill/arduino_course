#include <LiquidCrystal.h>
#include <string.h>
char str[] = "Yizhe Wang";
int time = 250;

LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup()
{
    lcd.begin(16, 2);
}

void loop()
{
    lcd.setCursor(16, 0);
    for (int pos = 0; pos < 16; pos++)
    {
        lcd.scrollDisplayLeft();
        char c = pos >= strlen(str) ? ' ' : str[pos];
        lcd.print(c);
        delay(time);
    }
    lcd.clear();
}