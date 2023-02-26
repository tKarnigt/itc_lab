#define btn1 13
#define btn2 12

int seg[]={10,9,8,7,6,5,4,3};
int r = random(1,9),count = 1;
int num[]={192,249,164,176,153,146,130,248,128,144,194,199};
unsigned long debounce = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.println(r);
  for(int i = 0;i<8;i++) pinMode(seg[i], OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
}

void loop() 
{
  int readbtn1 = digitalRead(btn1);
  int readbtn2 = digitalRead(btn2);
  
  int bit = 0;
  for(int i = 0;i<8;i++)
  {
    bit = bitRead(num[count], i);
    digitalWrite(seg[i], bit);
  }
  
  if(readbtn1 == HIGH && millis()-debounce>100 && count != 0 && count != 10 && count != 11)
  {
    debounce = millis();
    count++;
    if(count > 9) count = 1;
  }
  if(readbtn2 == HIGH && millis()-debounce>100)
  {
    debounce = millis();
    if(count == r)count = 0;
    else if(count > r)count = 10;
    else count = 11;
  }
  if(readbtn1 == HIGH && millis()-debounce>100 && count == 0)
  {
    debounce = millis();
    r = random(1,9);
    count = 1;
    Serial.println(r);
  }
  if(readbtn1 == HIGH && millis()-debounce>100 && (count == 10||count == 11))
  {
    debounce = millis();
    count = 1;
  }
}
