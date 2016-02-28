void setup()
{
  // Set Pin 7 to output
  pinMode(7, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // Write a HIGH signal to Pin 7 turing the LED on
  digitalWrite(7, HIGH);
  // delay is in miliseconds
  Serial.write("LED is ON"); // write to serial port
  delay(1000);
  // Write a LOW signal to Pin 7 turning the LED off
  digitalWrite(7, LOW);
  Serial.write("LED is OFF"); // write to serial port
  delay(1000);
}
