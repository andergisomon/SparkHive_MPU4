unsigned long start_time;
unsigned long stop_time;
bool pressed = false;

void setup() {
  pinMode(6, OUTPUT); //Digital output for LED1
  pinMode(7, OUTPUT); //Digital output for LED2
  pinMode(8, INPUT); //Digital input for button
  digitalWrite(6, 0);
  digitalWrite(7, 0);
}

void loop() {
  bool button = digitalRead(8);

  if (button) {
    pressed = true;
    start_time = millis();
    while (button) {
      stop_time = millis();
      button = digitalRead(8);
    }
  }
  else {
    pressed = false;
  }

  if (stop_time - start_time >= 3000) {
    digitalWrite(6, 1);
    digitalWrite(7, 0);
  }
  else if (pressed == true) {
    digitalWrite(7, 1);
    digitalWrite(6, 0);
  }
  
}