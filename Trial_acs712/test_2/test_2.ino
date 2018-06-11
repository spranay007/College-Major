int calVal=518;
int mVpa=61;
void setup()
{
    Serial.begin(9600);
    pinMode(A5,INPUT);
}

void loop()
{
    int val=analogRead(A5);
    int valAdj=val-calVal;
    float milliVolts=((valAdj*5.00)*1000);
    float Amps= milliVolts/mVpa;
    Serial.println(val);
    Serial.println(milliVolts);
    Serial.println(Amps);
    delay(500);
}
