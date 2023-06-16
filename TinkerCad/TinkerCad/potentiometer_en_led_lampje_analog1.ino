// C++ code
//

const int potentiometer = A5;
const int led = 9;
unsigned long oldMillis = 0;
int potentiometerValue =100;

void setup()
{
  Serial.begin(9600);
  pinMode(potentiometer, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (millis() - oldMillis > 5)
  {
    oldMillis = millis();
    int potentiometerValue = map(analogRead(potentiometer), 0, 1023, 0, 255);
    Serial.println(potentiometerValue);
    analogWrite(led,potentiometerValue);
  }
}