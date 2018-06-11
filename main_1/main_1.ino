//voltage assumptions
float raw_data = 0, raw_data_sample, v_5, v_12, v_220;
//power and energy
float data_power = 0;
float energy = 0;
float cost;
long time;
//liquid crystal
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//current sensor assumptions
int sensorIn = A4;
int mVperAmp = 200; // use 100 for 20A Module and 66 for 30A Module
float avgamps = 0;
float amphr = 0;
double correction_value = 0.04;

//double Voltage,VRMS,AmpsRMS;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;
double AmpsRMS_final = 0;

void setup() {

  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(6,OUTPUT);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  pinMode(A5, INPUT); //voltage sensor
  pinMode(sensorIn, INPUT); //current sensor
  lcd.begin(16, 2);
  lcd.print("PAYMENT METHOD ?");
  
  analogWrite(6,50);
  pinMode(A2, INPUT); //reading pins
  pinMode(A3, INPUT); //reading pins
  
}

void loop() {
if(digitalRead(A2)==1 && digitalRead(A3)==1) //postpaid
  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("POSTPAID SELECTED");
      delay(2000);
      lcd.clear();
  lcd.print("Voltage--Current--Power--Energy--Cost");
    digitalWrite(13,HIGH); //postpaid
  //automatic changeover  
  int aflag;
  int bflag;
  int a,b;
  //time calculations
  long milisec = millis(); // calculate time in milliseconds
  long time = milisec / 1000; // convert milliseconds to seconds

  /* voltage calculations */
  //raw_data=analogRead(A5);
  //Serial.println(raw_data);
  //delay(10);
//  analogWrite(10, 50); //brightness
  for (int i = 0; i < 10; i++)
  {
    raw_data += analogRead(A5); //read the voltage from the sensor
    delay(2);
  }
  raw_data = raw_data / 10;
  //Serial.println(raw_data);
  //Serial.println(raw_data_sample);
  delay(10);
  v_5 = (5 * raw_data) / 900;
  v_12 = (12 * v_5) / 5;
  v_220 = (220 * v_12) / 12;
  //Serial.println(v_220); //to check voltage
  //  lcd.print("Voltage");
  lcd.setCursor(0, 1);
  lcd.print(v_220);

  // raw_data=0;
  /*end of voltage calculations*/

  /*current calculations*/

  Voltage = getVPP();
  VRMS = (Voltage / 2.0) * 0.707;
  AmpsRMS = (VRMS * 1000) / mVperAmp;
  AmpsRMS_final = AmpsRMS - correction_value;
  //  Serial.println(AmpsRMS);
  //  Serial.println(correction_value);
  //  Serial.println(AmpsRMS_final); // to check current
  //Serial.print(Voltage);
  //  Serial.println(" Amps RMS");
  lcd.setCursor(9, 1);
  lcd.print(AmpsRMS_final);
  //delay(1000);
  /*end of current calculations*/

  //calculations for the power



  //energy and power
 
  avgamps = AmpsRMS_final / time; // average amps
  amphr = (avgamps * time) / 3600; // amp-hour
  data_power = (AmpsRMS_final * v_220); //power calculation i.e. VXI
  lcd.setCursor(18, 1);
  lcd.print(data_power);
  energy = (data_power * time) / 3600; //Watt-sec is again convert to Watt-Hr by dividing 1hr(3600sec)
  lcd.setCursor(25, 1);
  lcd.print(energy);
  cost=energy*4;
  Serial.print(data_power);
  Serial.print("a");
  lcd.setCursor(33, 1);
  Serial.println(cost);
  lcd.println(cost);
  //delay(200);
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 21; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 21; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  // for (int positionCounter = 0; positionCounter < 7; positionCounter++) {
  // scroll one position left:
  // lcd.scrollDisplayLeft();
  // wait a bit:
  //delay(1000);
  //}

  // delay at the end of the full loop:
  delay(200);
}







if(digitalRead(A2)==0 && digitalRead(A3)==1) // INPUT CARD
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("PREPAID SELECTED");
  lcd.setCursor(0, 1);
  lcd.print("INPUT CARD");
  delay(2000);

}





if(digitalRead(A2)==1 && digitalRead(A3)==0) // prepaid with credit 1000
{
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Rs.1000 CREDITED");
  delay(2000);
  lcd.clear();
  lcd.print("Voltage--Current--Power--Energy--Cost");
  digitalWrite(13,LOW);
  //automatic changeover  
  int aflag;
  int bflag;
  int a,b;

  //time calculations
  long milisec = millis(); // calculate time in milliseconds
  long time = milisec / 1000; // convert milliseconds to seconds

  /* voltage calculations */
  //raw_data=analogRead(A5);
  //Serial.println(raw_data);
  //delay(10);
  //analogWrite(10, 50); //brightness
  for (int i = 0; i < 10; i++)
  {
    raw_data += analogRead(A5); //read the voltage from the sensor
    delay(2);
  }
  raw_data = raw_data / 10;
  //Serial.println(raw_data);
  //Serial.println(raw_data_sample);
  delay(10);
  v_5 = (5 * raw_data) / 900;
  v_12 = (12 * v_5) / 5;
  v_220 = (220 * v_12) / 12;
  //Serial.println(v_220); //to check voltage
  //  lcd.print("Voltage");
  lcd.setCursor(0, 1);
  lcd.print(v_220);

  // raw_data=0;
  /*end of voltage calculations*/

  /*current calculations*/

  Voltage = getVPP();
  VRMS = (Voltage / 2.0) * 0.707;
  AmpsRMS = (VRMS * 1000) / mVperAmp;
  AmpsRMS_final = AmpsRMS - correction_value;
  //  Serial.println(AmpsRMS);
  //  Serial.println(correction_value);
  //  Serial.println(AmpsRMS_final); // to check current
  //Serial.print(Voltage);
  //  Serial.println(" Amps RMS");
  lcd.setCursor(9, 1);
  lcd.print(AmpsRMS_final);
  //delay(1000);
  /*end of current calculations*/

  //calculations for the power



  //energy and power
 
  avgamps = AmpsRMS_final / time; // average amps
  amphr = (avgamps * time) / 3600; // amp-hour
  data_power = (AmpsRMS_final * v_220); //power calculation i.e. VXI
  lcd.setCursor(18, 1);
  lcd.print(data_power);
  energy = (data_power * time) / 3600; //Watt-sec is again convert to Watt-Hr by dividing 1hr(3600sec)
  lcd.setCursor(25, 1);
  lcd.print(energy);
  cost=1000-energy*4;
  lcd.setCursor(33, 1);
  lcd.print(cost);
  Serial.print(data_power);
  Serial.print("a");
  Serial.println(cost);
  //delay(200);
  // scroll 13 positions (string length) to the left
  // to move it offscreen left:
  for (int positionCounter = 0; positionCounter < 22; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(300);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 22; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(300);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  // for (int positionCounter = 0; positionCounter < 7; positionCounter++) {
  // scroll one position left:
  // lcd.scrollDisplayLeft();
  // wait a bit:
  //delay(1000);
  //}

  // delay at the end of the full loop:
  delay(200);
} 
}

float getVPP()
{
  float result = 0.0;
  int readValue = 0;           //value read from the sensor
  int maxValue = 0;          // store max value here
  int minValue = 1024;          // store min value here

  uint32_t start_time = millis();
  while ((millis() - start_time) < 1000) //sample for 1 Sec
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
  result = ((maxValue - minValue) * 5.0) / 1024.0;
  // Serial.println(readValue);
  // Serial.println(maxValue);
  // Serial.println(minValue);
  //Serial.println(readValue);
  //Serial.println("---------------------------------");
  return result;
}

