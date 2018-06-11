// 1C007AF455C7 tag id

int count = 0;                                          // count = 0
char input[12];                                         // character array of size 12 
char card[]="1C007AF455C7";
boolean flag = 0;                                       // flag =0
void setup()
{
   Serial.begin(9600);                                  // begin serial port with baud rate 9600bps
}
void loop()
{

   
   if(Serial.available())
   {
      count = 0;
      while(Serial.available() && count < 12)          // Read 12 characters and store them in input array
      {
         input[count] = Serial.read();
         count++;
         delay(5);
      }
      Serial.print(input);                             // Print RFID tag number 
      
//      if((input[0] ^ input[2] ^ input[4] ^ input[6] ^ input[8] == input[10]) && 
//         (input[1] ^ input[3] ^ input[5] ^ input[7] ^ input[9] == input[11]))
//            Serial.println("No Error");
//      else
//            Serial.println("Error");      
if (input[0]==card[0] && input[1]==card[1] && input[2]==card[2] && input[3]==card[3] && input[4]==card[4] && input[5]==card[5] && input[6]==card[6] && input[7]==card[7] && input[8]==card[8] && input[9]==card[9] && input[10]==card[10] && input[11]==card[11])
{  
  Serial.println("matched");
 
}
else
{
  Serial.println("error");
}
   }
}
