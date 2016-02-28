void setup()
{
  // Set Pin 7 to output
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}

void loop() // Setup is the same as before
{
    char command = 0; //char to hold command byte
    //if a byte is waiting in the serial buffer
    if (Serial.available() > 0)
    {
      command = Serial.read(); //read the byte and store it.
    }
    switch(command)
    {
       case 'H':
       digitalWrite(7, HIGH); // Turn on LED
       break;
       case 'L':
       digitalWrite(7, LOW); // Turn off LED
      break;
    }
}
