#define IN A0
#define LED 9

const unsigned int TOL = 15; //analog readings are subject to noise so we use a tolerance
const unsigned int THRESHOLD = 512; //threshold for LED to turn on

void setup() 
{
    //pinMode(IN, INPUT); //we are reading in an Analog voltage
    pinMode(LED, OUTPUT); //we are output a voltage to the LED
}

void loop() 
{
    int vin = analogRead(IN); //read the analog voltage

    //if vin is within the threshold +- tolerance we will turn on an LED
    if(vin < (THRESHOLD + TOL) && vin > (THRESHOLD - TOL))
        digitalWrite(LED, HIGH);
    else
        digitalWrite(LED, LOW);
}
