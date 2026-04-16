#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"
LiquidCrystal_I2C lcd(0x3F, 16, 2);
RTC_DS1307 RTC;
int buzzer = 2;

void setup()


    
{

  Serial.begin(9600);

  Wire.begin();

  RTC.begin();  // load the time from your computer.

  // Set the time to a default value (January 1, 1970, 00:00:00)
  RTC.adjust(DateTime(2025, 2, 19, 14, 0, 0));
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,HIGH);
  // Start the RTC clock
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  // Get current date and time from RTC
  DateTime now = RTC.now();

  // Format date as DD/MM/YYYY
  char dateStr[11];
  snprintf(dateStr, sizeof(dateStr), "%02d/%02d/%04d", now.day(), now.month(), now.year());

  // Format time as HH:MM:SS
  char timeStr[9];
  snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d", now.hour(), now.minute(), now.second());

  // Display date on the first row of the LCD
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(dateStr);

  // Display time on the second row of the LCD
  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(timeStr);

  // Optional: Print the same to the Serial Monitor
  Serial.print("Date: ");
  Serial.print(dateStr);
  Serial.print(" | Time: ");
  Serial.println(timeStr);

  // Update every second
  delay(1000);

  Serial.println(now.hour());
  if (now.hour() == 9 && now.minute() == 30 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class starts !!!!");
  }
  if (now.hour() == 10 && now.minute() == 20 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class 2 !!!");
  }
  if (now.hour() == 11 && now.minute() == 10 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class 3 !!!!");
  }
  if (now.hour() == 12 && now.minute() == 0 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("BREAK !!!!");
  }
  if (now.hour() == 12 && now.minute() == 50 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class 4 !!!!");
  }
  if (now.hour() == 13 && now.minute() == 40 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class 5 !!!!");
  }
  if (now.hour() == 14 && now.minute() == 20 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class 6 !!!!");
  }
  if (now.hour() == 15 && now.minute() == 0 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("class 7 !!!!");
  }
  if (now.hour() == 15 && now.minute() == 40 && now.second() == 0) {
    digitalWrite(buzzer, LOW);
    delay(3000);
    digitalWrite(buzzer, HIGH);
    Serial.println("END !!!!");
  }
}
