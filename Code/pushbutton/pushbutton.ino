void setup()
{
  // setup pins as input or output
 pinMode(7, OUTPUT);
 pinMode(2, INPUT);
}
void loop()
{
  // read the state of the button
 if(digitalRead(2) == HIGH)
  { // turn on the LED since the button is pressed
    digitalWrite(7, HIGH);
  }else
  { // turn off the LED since the button is not pressed
    digitalWrite(7, LOW);
  }
}
