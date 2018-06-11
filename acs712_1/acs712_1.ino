/*
Measuring AC Current Using ACS712
*/
int sensorIn = A5;
int mVperAmp = 200; // use 100 for 20A Module and 66 for 30A Module

//double Voltage,VRMS,AmpsRMS;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;



void setup(){ 
 Serial.begin(9600);
 pinMode(sensorIn,INPUT);
}

void loop(){
 
//int data= analogRead(sensorIn);
 Voltage = getVPP();
 VRMS = (Voltage/2.0) *0.707; 
 AmpsRMS = (VRMS * 1000)/mVperAmp;
// Serial.print(AmpsRMS);
//Serial.print(Voltage);
 //Serial.println(" Amps RMS");

}

float getVPP()
{
  float result=0.0;
  int readValue=0;             //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 1024;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the maximum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;
   Serial.println(readValue);
   Serial.println(maxValue);
   Serial.println(minValue);
   Serial.println(readValue);
   Serial.println("---------------------------------");
   return result;
 }
