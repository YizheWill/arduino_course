int red_light_pin = 7;
int green_light_pin = 8;
int ultra_sound_trig_pin = 10;
int ultra_sound_echo_pin = 13;

float duration, distance;

void setup()
{
    pinMode(red_light_pin, OUTPUT);
    pinMode(green_light_pin, OUTPUT);
    pinMode(ultra_sound_trig_pin, OUTPUT);
    pinMode(ultra_sound_echo_pin, INPUT);
    Serial.begin(9600);
}
void loop()
{
    // digitalWrite(ultra_sound_trig_pin, LOW);
    // delayMicroseconds(2);
    // digitalWrite(ultra_sound_trig_pin, HIGH);
    // delayMicroseconds(10);
    // digitalWrite(ultra_sound_trig_pin, LOW);
    // duration = pulseIn(ultra_sound_echo_pin, HIGH);
    // distance = (duration / 2) / 29.1;
    // Serial.println(distance);
    // if (distance < 20)
    // {
    //     digitalWrite(red_light_pin, HIGH);
    //     digitalWrite(green_light_pin, LOW);
    // }
    // else
    // {
    //     digitalWrite(red_light_pin, LOW);
    //     digitalWrite(green_light_pin, HIGH);
    // }
    digitalWrite(ultra_sound_trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(ultra_sound_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultra_sound_trig_pin, LOW);

    duration = pulseIn(ultra_sound_echo_pin, HIGH);
    distance = (duration / 2) / 29.1;

    Serial.print("Distance: ");
    if (distance >= 200 || distance <= 0)
    {
        digitalWrite(red_light_pin, LOW);
        digitalWrite(green_light_pin, HIGH);
        Serial.println("Out of range");
    }
    else
    {
        digitalWrite(red_light_pin, HIGH);
        digitalWrite(green_light_pin, LOW);
        Serial.print(distance);
        Serial.println(" cm");
    }
    delay(1000);
}