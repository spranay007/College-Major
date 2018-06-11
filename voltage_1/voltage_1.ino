float raw_data=0,raw_data_sample,v_5,v_12,v_220;
void setup() {
  Serial.begin(9600);
  pinMode(A5,INPUT);
}

void loop() {
//raw_data=analogRead(A5);
//Serial.println(raw_data);
//delay(10);
 for(int i=0;i<10;i++)
  {
    raw_data+=analogRead(A5);  //read the voltage from the sensor
    //sample2+=analogRead(A3); //read the current from sensor
    
    delay(2);
  }
   raw_data=raw_data/10;
   //Serial.println(raw_data);
   //Serial.println(raw_data_sample);
   delay(10);
   v_5=(5*raw_data)/900;
   v_12=(12*v_5)/5;
   v_220=(220*v_12)/12;
   Serial.println(v_220);
   delay(20);
// raw_data=0;

}
