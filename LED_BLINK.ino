int ledWhite  = 7;  // LED connected to digital pin 7
int ledRed    = 8;  // LED connected to digital pin 8 
void setup() {
  // initialize digital pin 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledWhite, OUTPUT);  // sets the digital pin 7 as output
  pinMode(ledRed, OUTPUT);  // sets the digital pin 8 as output

}
void loop() {
    digitalWrite(LED_BUILTIN, LOW);  
    digitalWrite(ledWhite, HIGH); 
    digitalWrite(ledRed, LOW);
    delay(500);                       
    digitalWrite(LED_BUILTIN, HIGH); 
    digitalWrite(ledWhite, LOW);   
    digitalWrite(ledRed, HIGH);   
    delay(500);
}
