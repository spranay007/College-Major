int raw_data=0, v_5=0;
void setup() {
pinMode(A0,INPUT);
Serial.begin(9600);

}

void loop() {
raw_data=analogRead(A0);
//Serial.println(data);
   //raw_data=raw_data/10;
   //Serial.println(raw_data);
   //Serial.println(raw_data_sample);
   //delay(10);
   v_5=(5*raw_data)/1024;
   //v_12=(12*v_5)/5;
   //v_220=(220*v_12)/12;
   Serial.println(v_5);
   Serial.println(raw_data);
   delay(20);

//delay(200);

}
