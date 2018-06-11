float raw_data=0,raw_data_sample,v_5,v_12,v_220,raw_data_c=0,val,final_current,final_current_amps;

void setup() {
  Serial.begin(9600);
  pinMode(A5,INPUT);
   pinMode(3,INPUT);

}

void loop() {
//raw_data=analogRead(A5);
//Serial.println(raw_data);
//delay(10);
 for(int i=0;i<10;i++)
  {
    raw_data+=analogRead(A5);  //read the voltage from the sensor
    raw_data_c+=analogRead(3); //read the current from sensor
    
    delay(2);
  }
  //voltage calib
   raw_data=raw_data/10;
   //Serial.println(raw_data);
   //Serial.println(raw_data_sample);
   delay(10);
   v_5=(5*raw_data)/900;
   v_12=(12*v_5)/5;
   v_220=(220*v_12)/12;
   Serial.print("\t volts = "); // shows the voltage measured 
   Serial.println(v_220);
   delay(100);
// raw_data=0;
//current calib
raw_data_c=raw_data_c/10;
val =(5.0*raw_data_c)/1024.0;
final_current =val-2.5; // offset voltage is 2.5v
final_current_amps = final_current*10;
Serial.print("\t Amps = "); // shows the voltage measured 
Serial.println(final_current_amps,3);
delay(100);

}
