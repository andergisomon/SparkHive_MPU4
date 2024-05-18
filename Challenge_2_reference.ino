// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(A0, INPUT); //Analog input from LDR
  pinMode(7, OUTPUT); //Digital output for LED
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
}

void loop() {
  digitalWrite(7, 0);
  int lightlevel = analogRead(A0);
  String showlightlevel = String(lightlevel);

  if (lightlevel > 25) {
    lcd.setCursor(0, 0);
    lcd.print("LED OFF");
    lcd.setCursor(0, 1);
    lcd.print("Brightness: " + showlightlevel);
  }

  else {
    digitalWrite(7, 1);
    lcd.setCursor(0, 0);
    lcd.print("LED ON");
    lcd.setCursor(0, 1);
    lcd.print("Brightness: " + showlightlevel);
  }

  delay(300);
  lcd.clear();
}