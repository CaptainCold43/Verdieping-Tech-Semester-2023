// C++ code
//

const int Green_Right_light = 2;
const int Orange_Right_light = 3;
const int Red_Right_light = 4;
const int Object_Right_Button = 9;
int ObjectPresentRight;

const int Green_Left_light = 5;
const int Orange_Left_light = 6;
const int Red_Left_light = 7;
const int Object_Left_Button = 8;
int ObjectPresentLeft;

unsigned long oldMillis = 0;
enum actie { StandaardActie, Orange,  Transitie, Green};
actie Actie= Orange;
bool Object = false;
bool GreenRight = false;
bool GreenLeft = false;

void setup()
{
    Serial.begin(9600);

    pinMode(Green_Right_light, OUTPUT);
    pinMode(Orange_Right_light, OUTPUT);
    pinMode(Red_Right_light, OUTPUT);
    pinMode(Green_Left_light, OUTPUT);
    pinMode(Orange_Left_light, OUTPUT);
    pinMode(Red_Left_light, OUTPUT);

    pinMode(Object_Right_Button, INPUT);
    pinMode(Object_Left_Button, INPUT);

    digitalWrite(Green_Right_light, LOW);
    digitalWrite(Orange_Right_light, LOW);
    digitalWrite(Red_Right_light, HIGH);

    digitalWrite(Green_Left_light, LOW);
    digitalWrite(Orange_Left_light, LOW);
    digitalWrite(Red_Left_light, HIGH);
}

void loop()
{
    Readstates();
    if (ObjectPresentRight == HIGH && GreenRight == false)
    {
        GreenRight = true;
        GreenLeft = false;
        oldMillis = millis();
        Object = true;
        Object_Right_Present();
    }
    if (ObjectPresentLeft == HIGH && GreenLeft == false)
    {
        oldMillis = millis();
        Object = true;
        GreenRight = false;
        GreenLeft = true;
        Object_Left_Present();
    }
}
void Readstates()
{
    ObjectPresentRight = digitalRead(Object_Right_Button);
    ObjectPresentLeft = digitalRead(Object_Left_Button);
}

void Object_Right_Present()
{
    while (Object == true)
    {
        if (millis() - oldMillis > 1000)
        {
            oldMillis = millis();
            switch (Actie)
            {
            case StandaardActie:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, HIGH);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, HIGH);
                Actie = Orange;
                break;
            case Orange:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, HIGH);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, HIGH);
                digitalWrite(Red_Left_light, LOW);
                Actie = Transitie;
                break;

            case Transitie:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, HIGH);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, HIGH);
                Actie = Green;
                break;
            case Green:
                // Lights on the right
                digitalWrite(Green_Right_light, HIGH);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, LOW);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, HIGH);

                Object = false;
                Actie = Orange;
                break;
            default:
                Actie = StandaardActie;
                break;
            }
        }
    }
}

void Object_Left_Present()
{
    while (Object == true)
    {
        if (millis() - oldMillis > 1000)
        {
            oldMillis = millis();
            switch (Actie)
            {
            case StandaardActie:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, HIGH);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, HIGH);
                Actie = Orange;
                break;
            case Orange:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, HIGH);
                digitalWrite(Red_Right_light, LOW);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, HIGH);
                Actie = Transitie;
                break;

            case Transitie:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, HIGH);
                // Lights on the left
                digitalWrite(Green_Left_light, LOW);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, HIGH);
                Actie = Green;
                break;
            case Green:
                // Lights on the right
                digitalWrite(Green_Right_light, LOW);
                digitalWrite(Orange_Right_light, LOW);
                digitalWrite(Red_Right_light, HIGH);
                // Lights on the left
                digitalWrite(Green_Left_light, HIGH);
                digitalWrite(Orange_Left_light, LOW);
                digitalWrite(Red_Left_light, LOW);

                Object = false;
                Actie = Orange;
                break;
            default:
                Actie = StandaardActie;
                break;
            }
        }
    }
}