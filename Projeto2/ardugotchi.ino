int LED_Dormir = 13;
int LED_Brincar = 12;
int LED_Comer = 11;

int Button_Dormir = 4;
int Button_Brincar = 3;
int Button_Comer = 2;

int Delay = 20;

int LastRead1 = 0;
int LastRead2 = 0;
int LastRead3 = 0;

int Ellapsed1 = 0;
int Ellapsed2 = 0;
int Ellapsed3 = 0;

int ButtonState1 = 0;
int ButtonState2 = 0;
int ButtonState3 = 0;

int ButtonRead1 = 0;
int ButtonRead2 = 0;
int ButtonRead3 = 0;

int PontosVida = 0;


void setup() {
  pinMode(LED_Dormir, OUTPUT);
  pinMode(LED_Brincar, OUTPUT);
  pinMode(LED_Comer, OUTPUT);

  pinMode(Button_Dormir, INPUT_PULLUP);
  pinMode(Button_Brincar, INPUT_PULLUP);
  pinMode(Button_Comer, INPUT_PULLUP);
}

void loop() {

  ButtonRead1 = !digitalRead(Button_Dormir);
  ButtonRead2 = !digitalRead(Button_Brincar);
  ButtonRead3 = !digitalRead(Button_Comer);

  if ((millis() != 0) && (millis() % 600000) == 0) {
    digitalWrite(LED_Dormir, HIGH);
  }

  if ((millis() != 0) && (millis() % 180000) == 0) {
    digitalWrite(LED_Brincar, HIGH);
  }

  if ((millis() != 0) && (millis() % 240000) == 0) {
    digitalWrite(LED_Comer, HIGH);
  }

  if (ButtonRead1 != LastRead1) {
    Ellapsed1 = millis();
  }
  if ((ButtonState1 != ButtonRead1) && ((millis() - Ellapsed1) > Delay)) {
    ButtonState1 = ButtonRead1;
    if ((!ButtonState1) && ((millis() - Ellapsed1) % 60000 == 0)) {
      PontosVida = PontosVida + 5;
    }
    if (ButtonState1) {
      if ((millis() - Ellapsed1 < 15000) && (PontosVida != 0)) {
        PontosVida = PontosVida - 5;
        digitalWrite(LED_Dormir, LOW);
      } else {
        digitalWrite(LED_Dormir, LOW);
      }
    }
  }

  LastRead1 = ButtonRead1;

  if (ButtonRead2 != LastRead2) {
    Ellapsed2 = millis();
  }

  if ((ButtonState2 != ButtonRead2) && ((millis() - Ellapsed2) > Delay)) {
    ButtonState2 = ButtonRead2;
    if ((ButtonState2 == 0) && ((millis() - Ellapsed2) % 60000 == 0)) {
      PontosVida = PontosVida + 5;
      if (ButtonState2) {
        digitalWrite(LED_Brincar, LOW);
      }
    }
  }
  LastRead2 = ButtonRead2;

  if (ButtonRead3 != LastRead3) {
    Ellapsed3 = millis();
  }

  if ((ButtonState3 != ButtonRead3) && ((millis() - Ellapsed3) > Delay)) {
    ButtonState3 = ButtonRead3;
    if (ButtonState3) {
      digitalWrite(LED_Comer, LOW);
    }
  }

  LastRead3 = ButtonRead3;
}