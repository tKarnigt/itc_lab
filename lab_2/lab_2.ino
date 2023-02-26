#define but1 13
#define but2 12
#define but3 11

#define led1 4
#define led2 3
#define led3 2

unsigned long timeled1 = 0, timeled2 = 0, timeled3 = 0;

int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  //=====================LED 1=============================
  if(digitalRead(but1)== HIGH && millis()-timeled1>250)
  {
    timeled1 = millis();
    if(digitalRead(led1)==LOW)
    {
      digitalWrite(led1, HIGH);
    }
    else
    {
      digitalWrite(led1, LOW);
    }
  }
  if(digitalRead(but1)==LOW && millis()-timeled1>=3000)
    {
      digitalWrite(led1, LOW);
    }
  
  //=====================LED 2=============================
  if(digitalRead(but2)==LOW && millis()-timeled2>250 && digitalRead(led1)==LOW && digitalRead(led3)==LOW)
  {
    timeled2 = millis();
    count = 1;
  }
  if(millis()-timeled2<2000 && count == 1)
  {
      if(millis()-timeled2 < 500) digitalWrite(led2, HIGH);
      else if(millis()-timeled2 < 1000) digitalWrite(led2, LOW);
      else if(millis()-timeled2 < 1500) digitalWrite(led2, HIGH);
      else if(millis()-timeled2 < 1950) digitalWrite(led2, LOW);
      else count = 0;
  }
  
  //=====================LED 3=============================
  if(digitalRead(but3)==LOW && millis()-timeled3>250 && digitalRead(led1)==LOW)
  {
    timeled3 = millis();
    if(digitalRead(led3)==LOW)
    {
      digitalWrite(led3, HIGH);
    }
    else if(digitalRead(led3)==HIGH)
    {
      digitalWrite(led3, LOW);
    }
  }
  if(digitalRead(but3)==HIGH && millis()-timeled3>=3000 )
    {
      digitalWrite(led3, LOW);
    }
}
