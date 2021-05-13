#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;
int ledWhite = 8;  // LED connected to digital pin 13
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
}

void loop () {
    DateTime now = rtc.now();
    Serial.println("Current Date & Time: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    Serial.println("Unix Time: ");
    Serial.print("elapsed ");
    Serial.print(now.unixtime());
    Serial.print(" seconds/");
    Serial.print(now.unixtime() / 86400L);
    Serial.println(" days since 1/1/1970");
    
    // calculate a date which is 7 days & 30 seconds into the future
    DateTime future (now + TimeSpan(7,0,0,30));
    
    Serial.println("Future Date & Time (Now + 7days & 30s): ");
    Serial.print(future.year(), DEC);
    Serial.print('/');
    Serial.print(future.month(), DEC);
    Serial.print('/');
    Serial.print(future.day(), DEC);
    Serial.print(' ');
    Serial.print(future.hour(), DEC);
    Serial.print(':');
    Serial.print(future.minute(), DEC);
    Serial.print(':');
    Serial.print(future.second(), DEC);
    Serial.println();
    Serial.println();
    delay(10000);
}
