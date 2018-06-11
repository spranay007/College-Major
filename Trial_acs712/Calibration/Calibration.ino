//includes
#include <Filters.h>.
//defines
#define NPOINTS 8 //numer of reads for each average
#define NMAX 10   //max number of points that can be stored

//structs
struct data{
  float analogPoints[NPOINTS];
  float average;
  float real;
  };
  
//global variables
float testFrequency = 50;                     // test signal frequency (Hz)
float windowLength = 20.0/testFrequency;     // how long to average the signal, for statistist
int sensorValue = 0;
//float intercept = -0.1310; // to be adjusted based on calibration testing
//float slope = 0.04099; // to be adjusted based on calibration testing
//float current_amps; // actual measure current
data collection[NMAX];
int i=0,j=0,c=0,c1=0,c2=0;
char Continue;
float ch;
unsigned long printPeriod = 3000; // in milliseconds
// Track time in milliseconds since last reading 
unsigned long previousMillis = 0;
float sumX=0,sumY=0,par=0,par1=0,m,q,avgX,avgY;

//functions
float average(data a);
void stampa(data a);

void setup() {
  Serial.begin( 9600 );    // start the serial port
}

void loop() {
 
  do{
    
    c=0;
    c1=0;
    c2=0;
    ch=-1;
    i=0;
    Serial.println("Intert 'e' to start recording:");
    while(c1==0){
    if(Serial.available()){
    if(Serial.read()=='e'){
      c1=1;
      }//end if the value is accettable
    }//end if something is coming   
    delay(100);
    }
    
    // create statistics to look at the raw test signal
     RunningStatistics inputStats;                 
    inputStats.setWindowSecs( windowLength );
    previousMillis = millis();
  //collect NPOINTS value to average  
  while( i<NPOINTS ) {   
    sensorValue = analogRead(A1);  // read the analog in value:
    inputStats.input(sensorValue);  // log to Stats function
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) {
      previousMillis = millis();   // update time
      
      // display current values to the screen
      Serial.print( "\n" );
      // output sigma or variation values associated with the inputValue itsel
      Serial.print( inputStats.sigma() );
      collection[j].analogPoints[i]=inputStats.sigma();
      i++;
    }
    
  }
  //calculate averge
  collection[j].average=average(collection[j]);
  //ask for real value
  Serial.println("\n");
  Serial.println("Insert the multimeter value [A] and press enter");
  while(c==0){
  if(Serial.available()){
    ch=Serial.parseFloat();
    if(ch>0){
      collection[j].real=ch;
      c=1;
      }//end if the value is accettable
    }//end if something is coming
    delay(100);
  }
  Serial.println("Point Collected");
  stampa(collection[j]);
  j++;
  //do you wonna collect another point?
   Continue='0';
 Serial.println("Do you wonna insert another point? y*n");
  while(c2==0){
  if(Serial.available()){
    Continue=Serial.read();
    if(Continue=='y'||Continue=='n'){
      c2=1;
      }//end if the value is accettable
    }//end if something is coming
    delay(100);
  }
  Serial.println("\n\n");
  //force to insert atleast two points
  if(j==1&&Continue=='n'){
    Continue='y';
    Serial.println("You have to insert at the very least 2 points");
    Serial.println("\n");
    }
  }while(Continue='y');//end while collecting points

  //calculate the results

  for(i==0;i<=j;i++){ //oss recycle i varible
    sumX=sumX+collection[i].average;
    sumY=sumY+collection[i].real;
    }
    avgX=sumX/i;
    avgY=sumY/i;
  for(i==0;i<=j;i++){
    par=par+(collection[i].average-avgX)*(collection[i].real-avgY);
    par1=par1+(collection[i].average-avgX)*(collection[i].average-avgX);
    
  }
  m=par/par1;
  q=avgY-m*avgX;



  
  delay(10000);
}

//functions
float average(data a){
  float sum=0;
  float r;
  for(int k=0;k<NPOINTS;k++){
    sum=sum+a.analogPoints[k];
    }
  r=sum/NPOINTS;
  return(r);
  }

void stampa(data a){
  Serial.println("\n");
    Serial.print("The value measured is: ");
    Serial.println(a.average);
    Serial.print("The real value is: ");
    Serial.println(a.real,3);
Serial.println("\n");
  }


