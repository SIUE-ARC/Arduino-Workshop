#define LED 9 //this pin must be a PWM pin (indicated by ~)

byte fadeStep = 15; //how much to increase PWM timer by each step
byte brightness = 0;
boolean limit = false; //flag for when the PWM is an an extreme point (0, 255)

void setup() 
{
    pinMode(LED, OUTPUT);
}

void loop() 
{
    analogWrite(LED, brightness); //always update the LED brightness
    brightness += (limit) ? (-1 * fadeStep):fadeStep; //increase brightness
    limit = (brightness == 0 || brightness == 255) ? !limit:limit; //if we reach an extreme flip the flag
    delay(25);
}
