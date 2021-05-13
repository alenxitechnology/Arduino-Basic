//impor library arduino 
#include <Wire.h>
#include "RTClib.h"

//mendeklarasikan library RTC dan pin digital LED
RTC_DS3231 rtc;
int ledWhite  = 7; 
int ledRed    = 8; 

void setup() {
//Memuat serial dan library
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();


//menginisialisasi pin digital sebagai output
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ledWhite, OUTPUT); 
  pinMode(ledRed, OUTPUT); 
}
void loop() { 
   DateTime now = rtc.now(); // Menginisialisasi waktu dari library RTC

    //Membuat looping LED pada board arduino
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);                      
    digitalWrite(LED_BUILTIN, HIGH);     
    delay(500);
    
    //mencetak atau memonitor waktu sekarang untuk dijadikan parameter lampu LED menyala dan mati
    Serial.println("Current Date & Time: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

   // Membuat Kondisi lampu LED menyala dan mati
   if(now.minute() >= 5 && now.minute() < 6)  // Sebagai contoh parameter dibuat dengan menit sehingga tidak terlalu lama
   {  
      digitalWrite(ledWhite, HIGH); 
      digitalWrite(ledRed, LOW);
   }
   else if(now.minute() >= 6 && now.minute() < 7)  
   {  
      digitalWrite(ledWhite, LOW);  
      digitalWrite(ledRed, HIGH); 
   }    
   else
   {
      digitalWrite(ledRed, LOW);    
      digitalWrite(ledWhite, LOW);
   }

// Jika parameternya adalah jam maka parameter kondisi now.minute diganti dengan now.hour 
//Contoh untuk parameter jam

     if(now.hour() >= 17 && now.hour() < 20){
      digitalWrite(ledWhite, HIGH);
      digitalWrite(ledRed, LOW);
   }

}
