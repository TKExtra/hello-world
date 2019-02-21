class Knipperled
  {
  int LedPin;
  int LedState;
  long OnTime;
  long OffTime;
  unsigned long Lasttime;
  int LedButton;

  public:
    Knipperled(int pin, long on, long off, int button){
      LedPin = pin;
      LedButton = button;
      pinMode(pin, OUTPUT);
      pinMode(button, INPUT_PULLUP);
      OnTime = on;
      OffTime = off;
      LedState = LOW;
      Lasttime = 0;
      }

    void Update(){
      if(digitalRead(LedButton) == LOW && LedState == HIGH && (millis() - Lasttime >= OnTime)){
        LedState = LOW;
        Lasttime = millis();
        digitalWrite(LedPin, LedState);
        }

      if(digitalRead(LedButton) == LOW && LedState == LOW && (millis() - Lasttime >= OffTime)){
        LedState = HIGH;
        Lasttime = millis();
        digitalWrite(LedPin, LedState);
        }
      }
  };


Knipperled Led1(2, 100, 400, 6);
Knipperled Led2(3, 200, 100, 7);  
  
void setup() {}

void loop() {
Led1.Update();
Led2.Update();
}
