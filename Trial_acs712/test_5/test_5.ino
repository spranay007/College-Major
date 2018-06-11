float sample2=0,val=0,actualval=0,amps=0;
void setup()
{
  Serial.begin(9600);
  pinMode(A2,INPUT);
}
void loop(){
  
// taking 150 samples from sensors with a interval of 2sec and then average the samples data collected
for(int i=0;i<150;i++)
{
sample2+=analogRead(A2); //read the current from sensor
delay(2);
}
sample2=sample2/150;
val =(5.0*sample2)/1024.0;
actualval =val-2.5; // offset voltage is 2.5v
amps =actualval*10;
Serial.println(amps);
}
