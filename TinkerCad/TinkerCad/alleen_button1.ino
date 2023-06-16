// C++ code
//
const int Button = 2;
unsigned long oldMillis = 0;

void setup()
{
  pinMode(Button, INPUT);
  pinMode(LED_BUILTIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  int buttonState = digitalRead(Button);
  if (millis()-oldMillis>1000){
  if (buttonState == HIGH)
  {
    oldMillis = millis();
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }}
}