#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.blink();
  delay(1000);
  printRandomized("Langsamer Text", 200, 500);
  lcd.setCursor(0, 1);
  delay(1000);
  printRandomized("Schneller Text", 100, 200);
  delay(2000);

  lcd.noBlink();
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(100);
  }
  delay(500);
}

void printSlowely(String str, int delayMillis) {
  for (unsigned short i = 0; i < str.length(); i++) {
    lcd.write(str[i]);
    delay(delayMillis);
  }
}

void printRandomized(String str, int minDelay, int maxDelay) {
  for (unsigned short i = 0; i < str.length(); i++) {
    lcd.write(str[i]);
    int delayMillis = rand() % (maxDelay-minDelay+1) + minDelay;
    Serial.print("Delay: ");
    Serial.println(delayMillis);
    delay(delayMillis);
  }
}
