#define IN A0
#define LED 9

const unsigned int THRESHOLD = 512; //threshold for analog read
const unsigned int TOL = 15; //tolerance for analog read

void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600); //statrt UART at 9.6 KB/s
    while(!Serial); //wait for UART to initialize
}

void loop()
{
    char msg[8];
    //if there is data in the buffer, read it out and do the
    //appropriate routine for that command.
    if(Serial.available() > 0)
    {   
        //read the whole buffer into msg     
        Serial.readBytesUntil('\n', msg, 8);

        //convert all bytes after the first to int
        int data = atoi(&msg[1]);
        
        switch(msg[0])
        {
            case 'A':
            case 'a':
                analogRoutine();
                break;
            case 'P':
            case 'p':
                pwmRoutine(data);
                break;
            case 'D':
            case 'd':
                digitalRoutine(data);
                break;
            default:
                Serial.println("Why has my god forsaken me!");
        }
    }
    Serial.flush();
}

void analogRoutine()
{
    float voltage = ((float)analogRead(IN)) * (5.0/1023.0);

    Serial.print("Analog voltage is: ");
    Serial.println(voltage);
}

void digitalRoutine(int data)
{
    if(data == 0 || data == 1)
        digitalWrite(LED, data);
    else
    {
        Serial.print("An digital pin can only be on or off. 1 or 0. Not: ");
        Serial.println(data);
    }
}

void pwmRoutine(int data)
{
    if(data >= 0 && data <= 255)
        analogWrite(LED, data);
    else
        Serial.println("Only enter integers between 0 and 255 kthxbai");
}

