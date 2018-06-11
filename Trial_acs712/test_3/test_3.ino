void setup() {
 
Serial.begin(9600);
}
 
void loop() {
 
float average = 0;
 
for(int i = 0; i &amp;lt; 1000; i++) {
        average = average + (.0264 * analogRead(A0) -13.51);
        delay(1);
                                 }
Serial.print(average);
Serial.println("mA");
 
}
