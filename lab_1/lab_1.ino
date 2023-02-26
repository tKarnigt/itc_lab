#define pin1 12
#define pin2 11
#define pin3 10
#define numdelay 250
void setup()
{
}

void led1()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void led2()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void led3()
{
  pinMode(pin1, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, LOW);
  digitalWrite(pin3, HIGH);
}

void led4()
{
  pinMode(pin1, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, LOW);
}

void led5()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin1, LOW);
  digitalWrite(pin3, HIGH);
}

void led6()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, OUTPUT);
  digitalWrite(pin1, HIGH);
  digitalWrite(pin3, LOW);
}


void loop()
{
  led1();
  delay(numdelay);
  led2();
  delay(numdelay);
  led3();
  delay(numdelay);
  led4();
  delay(numdelay);
  led5();
  delay(numdelay);
  led6();
  delay(numdelay);
  led5();
  delay(numdelay);
  led4();
  delay(numdelay);
  led3();
  delay(numdelay);
  led2();
  delay(numdelay);
}
