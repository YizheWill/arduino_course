const int main_red_pin = 3;
const int main_yellow_pin = 4;
const int main_green_pin = 5;

const int side_red_pin = 6;
const int side_yellow_pin = 7;
const int side_green_pin = 8;
void setup()
{
    // set the pinmode for all the related pins to be OUTPUT
    pinMode(main_red_pin, OUTPUT);
    pinMode(main_yellow_pin, OUTPUT);
    pinMode(main_green_pin, OUTPUT);

    pinMode(side_red_pin, OUTPUT);
    pinMode(side_yellow_pin, OUTPUT);
    pinMode(side_green_pin, OUTPUT);
    
    // set initial state, where main green is on, side red is on, else all off
    digitalWrite(main_red_pin, LOW);
    digitalWrite(main_yellow_pin, LOW);
    digitalWrite(main_green_pin, HIGH);

    digitalWrite(side_red_pin, HIGH);
    digitalWrite(side_yellow_pin, LOW);
    digitalWrite(side_green_pin, LOW);
}

void loop()
{
    delay(5000);
    // after the main green be on for 5 seconds
    // 1. we turn off the main green
    // 2. we turn on the main yellow
    // 3. side red maintains to be on
    // 4. keep the rest to be off
    digitalWrite(main_green_pin, LOW);
    digitalWrite(main_yellow_pin, HIGH);

    delay(1000);
    // after the main yellow be on for 1 second
    // 1. we turn off the main yellow.
    // 2. we turn on the main red.
    // 3. we turn on the side green.
    // 4. keep the rest to be off
    digitalWrite(main_yellow_pin, LOW);
    digitalWrite(main_red_pin, HIGH);
    digitalWrite(side_green_pin, HIGH);
    digitalWrite(side_red_pin, LOW);


    delay(3000);
    // after the side green be on for 3 seconds
    // 1. we turn off the side green.
    // 2. we turn on the side yellow.
    // 3. main red maintains to be on.
    // 4. rest off
    digitalWrite(side_green_pin, LOW);
    digitalWrite(side_yellow_pin, HIGH);


    delay(1000);
    // after the side yellow be on for 1 second
    // 1. we turn off the side yellow.
    // 2. turn on the side red.
    // 3. turn off the main red.
    // 4. turn on the main green.
    digitalWrite(side_yellow_pin, LOW);
    digitalWrite(side_red_pin, HIGH);
    digitalWrite(main_red_pin, LOW);
    digitalWrite(main_green_pin, HIGH);
}
