int ButtonState = 0;
int ButtonRead = 0;
int Delay = 20;
int Ellapsed = 0;
int LastRead = 0;

int Random_Number = 31;

void mostra_leds_binario(int Number, int Firstled, int Lastled) {
  for (int i = Firstled; i <= Lastled; i++)
    if (bitRead(Number, i - 8))
      digitalWrite(i, HIGH);
    else
      digitalWrite(i, LOW);
}
void setup() {

  Serial.begin(9600);
  for (int i = 8; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(7, INPUT_PULLUP);
}

void loop() {

  ButtonRead = !digitalRead(7);

  if (ButtonRead != LastRead)
    Ellapsed = millis();

  if ((ButtonState != ButtonRead) && ((millis() - Ellapsed) > Delay)) {
    ButtonState = ButtonRead;
    if (ButtonState) {
      Random_Number = random(0, 32);
      Serial.println(Random_Number);
      Serial.write('S');
      Serial.println();
    }
  }

  mostra_leds_binario(Random_Number, 8, 12);



  LastRead = ButtonRead;

  if (Serial.available() > 0) {
    int incomingByte = Serial.read();

    if (incomingByte == Random_Number) {

      Serial.write('Y');
      Random_Number = 31;

    }

    else if (incomingByte != Random_Number) {

      Serial.write('N');
    }
  }
}