#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);
  Serial.println("START");
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
  for (int i = 0; i < str.length(); i++) {
    lcd.write(str[i]);
    delay(delayMillis);
  }
}

void printRandomized(String str, int minDelay, int maxDelay) {
  for (int i = 0; i < str.length(); i++) {
    lcd.write(str[i]);
    int delayMillis = rand() % (maxDelay-minDelay+1) + minDelay;
    Serial.print("Delay: ");
    Serial.println(delayMillis);
    delay(delayMillis);
  }
}
