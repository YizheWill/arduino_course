#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define JOY_X A0         // Joystick X-axis analog pin
#define JOY_Y A1         // Joystick Y-axis analog pin
#define JOY_SW 2         // Joystick switch pin
#define TRIG_PIN 3       // Ultrasound sensor trigger pin
#define ECHO_PIN 4       // Ultrasound sensor echo pin
#define LED_UP 5         // First LED pin
#define LED_DOWN 6       // Second LED pin
#define MAX_DISTANCE 200 // Sonar sensor max distance

LiquidCrystal_I2C lcd(0x27, 20, 4);
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

int interation = 5;
float distance_cm, distance_in, duration;
int joystickY;

void setup()
{
    Serial.begin(9600);
    pinMode(JOY_SW, INPUT_PULLUP);
    pinMode(LED_UP, OUTPUT);
    pinMode(LED_DOWN, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    digitalWrite(LED_UP, LOW);
    digitalWrite(LED_DOWN, LOW);

    lcd.init();
    lcd.backlight();
    lcd.begin(20, 4);
    lcd.setCursor(0, 0);
    lcd.print("Joystick: ");
    lcd.print(joystickY);
    lcd.print("    ");
}

void loop()
{
    int joystickY = analogRead(JOY_Y);
    bool joystickSW = digitalRead(JOY_SW);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = sonar.ping_median(interation);
    distance_cm = (duration / 2) * 0.0343;
    distance_in = distance_cm / 2.54;
    lcd.setCursor(0, 1);
    lcd.print("Distance:");
    lcd.setCursor(0, 2);
    lcd.print(distance_in);
    lcd.print("inches.  ");
    lcd.setCursor(0, 3);
    lcd.print(distance_cm);
    lcd.print("cm.  ");
    if (distance_cm > 0 && distance_cm < 20)
    {
        digitalWrite(LED_UP, HIGH);
        digitalWrite(LED_DOWN, HIGH);
        delay(100);
    }
    else
    {
        digitalWrite(LED_DOWN, LOW);
        digitalWrite(LED_UP, LOW);
        lcd.setCursor(0, 0);
        lcd.print("Joystick: ");
        lcd.print(joystickY);
        lcd.print("    ");
        // since the joystick is not very accurate, the "middle position"
        // can range from 490 - 520 on my device, so I set it up as if the
        // value is between 490 and 520, then it shall be recognized as "middle position".
        if (joystickY > 520)
        {
            blinkLed(LED_UP, joystickY);
        }
        else if (joystickY < 490)
        {
            blinkLed(LED_DOWN, joystickY);
        }
    }
}
void blinkLed(int pin, int level)
{
    int delay_time;
    int val;
    val = level > 512 ? level - 512 : 512 - level;
    delay_time = map(val, 0, 512, 1000, 0);
    digitalWrite(pin, HIGH);
    delay(delay_time);
    digitalWrite(pin, LOW);
    delay(delay_time);
}