int blinks = 0;
bool started = false;
 
int button1stat = 0;
int button1read = 0;
int delay_ = 20;
int ellapsed1 = 0;
int lastread1 = 0;
 
int button2stat = 0;
int button2read = 0;
 
int ellapsed2 = 0;
int lastread2 = 0;
 
int guess = 0;
 
void setup()
{
 
  Serial.begin(9600);
 
  for (int i = 9; i<= 13; i++){
    pinMode(i, OUTPUT);
     digitalWrite(i, HIGH);
 
   }
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
 
}
 
void show_binary_leds(int number, int firstled, int lastled){
  for (int i = firstled; i<= lastled; i++)
  	if (bitRead(number, i-9))
    	digitalWrite(i, HIGH);
   	else
    	digitalWrite(i, LOW);
 
}
 
 
void loop()
{
  char data1 = Serial.read();
  if (data1 != -1){
    if (data1 == 'S'){
      guess = 0;
      blinks = 3;
      started = true;
    }
    if (data1 == 'Y'){
      guess = 0;
      started = false;
      show_binary_leds(31,9,13);
    }
    if (data1 == 'N'){
      guess = 0;
    }
  }
 
  if (blinks > 0){
    blinks -= 1;
    for (int i = 9; i<= 13; i++){
      digitalWrite(i, HIGH);}
    delay(100);
    for (int i = 9; i<= 13; i++){
      digitalWrite(i, LOW);
    }
    delay(100);
  }  
  if (started){
    button1read = !digitalRead(6);
 
    if (button1read != lastread1)
      ellapsed1 = millis();
 
    if ((button1stat != button1read) && ((millis() - ellapsed1) > delay_)){
      button1stat = button1read;
      if (button1stat){
        guess++;
      }
    }
 
    lastread1 = button1read;
    //-----
    button2read = !digitalRead(7);
    if (button2read != lastread2){
      ellapsed2 = millis();
    }
 
 
    if ((button2stat != button2read) && ((millis() - ellapsed2) > delay_)){
      button2stat = button2read;
      if (button2stat){
        Serial.write(guess);
      }
    }
 
    lastread2 = button2read;
 
    show_binary_leds(guess, 9, 13);
 
  }
}