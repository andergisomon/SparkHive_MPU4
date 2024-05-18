// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int count = 0;
int hmm, j, k = 0;
bool last_state, current_state;

void setup() {
  pinMode(6, OUTPUT); //Digital output for LED1
  pinMode(7, OUTPUT); //Digital output for LED2
  pinMode(8, INPUT); //Digital input for button
  pinMode(9, OUTPUT); //Digital output for buzzer
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  bool button = digitalRead(8);

  lcd.setCursor(0, 0);
  lcd.print("SELECTED MODE");

  if (button) {
    current_state = true;
  }
  else {
    current_state = false;
  }

  if (last_state != current_state) {
    if (current_state == true) {
      count++;
    }
  }

  last_state = current_state;

  if (count > 2) {
    count = 0;
  }
  
  if (count == 0) {
    j, k = 0;
    digitalWrite(6, 0);
    digitalWrite(7, 0);

    lcd.setCursor(0, 1);
    lcd.print("NORMAL");

    if (hmm < 1) {
      tone(9, 1000);
      delay(300);
      tone(9, 820);
      delay(300);
      hmm++;
    }
  }

  if (count == 1) {
    hmm = 0;
    k = 0;
    digitalWrite(6, 1);
    digitalWrite(7, 0);

    lcd.setCursor(0, 1);
    lcd.print("LOW EMISSIONS");

    if (j < 1) {
      tone(9, 800);
      delay(300);
      tone(9, 880);
      delay(300);
      j++;
    }
  }

  if (count == 2) {
    hmm = 0;
    j = 0;
    digitalWrite(6, 0);
    digitalWrite(7, 1);

    lcd.setCursor(0, 1);
    lcd.print("PERFORMANCE");

    if (k < 1) {
      tone(9, 500);
      delay(300);
      tone(9, 800);
      delay(300);
      k++;
    }
  }

  noTone(9);
  delay(700);
  lcd.clear();
}