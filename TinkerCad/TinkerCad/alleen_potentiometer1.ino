// C++ code
//

const int potentiometer = A5;
unsigned long oldMillis = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(potentiometer, INPUT);
}

void loop()
{
  if (millis() - oldMillis > 5)
  {
    oldMillis = millis();
  Serial.println(analogRead(potentiometer));
  }
}