void setup() {
Serial.begin(9600);
pinMode(2,INPUT);
pinMode(4,INPUT);
}

void loop() {
if(digitalRead(2)==1)
{
  Serial.println("2 is high");
  delay(1000);
}
if(digitalRead(2)==0)
{
  Serial.println("2 is low");
  delay(1000);
}

}
