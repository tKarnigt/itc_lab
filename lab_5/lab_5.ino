#define greenW 5

#define redN 10
#define yellowN 9
#define greenN 8

#define redWalk 4
#define greenWalk 3

#define goW 0
#define waitW 1
#define goN 2
#define waitN 3
#define Walk 4
#define blink1 5
#define blink2 6
#define blink3 7
#define blink4 8
#define blink5 9

struct state
{
  unsigned long STout;  
  unsigned long Time; 
  unsigned long Next[8];
};
 typedef const struct state SType;
 SType FSM[10] =
{
  //                 000    001     010     100     011     101     110     111
  {B01001100, 1500, {goW,	waitW,	waitW,	waitW,	goW,	waitW,	waitW,	waitW}},
  {B01001010, 300, 	{goN,	Walk,	goN,	goN,	goN,	Walk,	goN,	goN}},
  {B01100001, 1500, {goN,	waitN,	goN,	waitN,	waitN,	waitN,	waitN,	waitN}},
  {B01010001, 300, 	{goW,	Walk,	goW,	Walk,	goW,	goW,	goW,	Walk}},
  {B10001001, 1500, {Walk,	Walk,	blink1,	blink1,	blink1,	blink1,	blink1,	blink1}},
  {B00001001, 300, 	{blink2,blink2,	blink2,	blink2,	blink2,	blink2,	blink2,	blink2}},
  {B10001001, 300,	{blink3,blink3,	blink3,	blink3,	blink3,	blink3,	blink3,	blink3}},
  {B00001001, 300, 	{blink4,blink4,	blink4,	blink4,	blink4,	blink4,	blink4,	blink4}},
  {B00001001, 300, 	{blink5,blink5,	blink5,	blink5,	blink5,	blink5,	blink5,	blink5}},
  {B00001001, 300, 	{goW,	goW,	goN,	goW,	goN,	goW,	goW,	goW}}
};

void setup()
{
  Serial.begin(9600);
  
  pinMode(Wsw, INPUT_PULLUP);
  pinMode(Nsw, INPUT_PULLUP);
  pinMode(Walksw, INPUT_PULLUP);
  
  pinMode(redW, OUTPUT);
  pinMode(yellowW, OUTPUT);
  pinMode(greenW, OUTPUT);
 
  pinMode(redN, OUTPUT);
  pinMode(yellowN, OUTPUT);
  pinMode(greenN, OUTPUT);
  
  pinMode(redWalk, OUTPUT);
  pinMode(greenWalk, OUTPUT);
}

int input, input1, input2, input3;
unsigned S = 0;

void loop()
{
  digitalWrite(redW,      FSM[S].STout& B00000001);
  digitalWrite(yellowW,   FSM[S].STout& B00000010);
  digitalWrite(greenW,    FSM[S].STout& B00000100);
  digitalWrite(redN,      FSM[S].STout& B00001000);
  digitalWrite(yellowN,   FSM[S].STout& B00010000);
  digitalWrite(greenN,    FSM[S].STout& B00100000);
  digitalWrite(redWalk,   FSM[S].STout& B01000000);
  digitalWrite(greenWalk, FSM[S].STout& B10000000);
  delay(FSM[S].Time);
  Serial.println(FSM[S].Time);
  //Serial.println(digitalRead(Walksw));
  
  
  input1 = !digitalRead(Wsw);
  Serial.print(input1);

  input2 = !digitalRead(Nsw);
  Serial.print(input2);
    
  input3 = !digitalRead(Walksw);
  Serial.println(input3);
  input = input3+input2*2+input1*4;
  
  S = FSM[S].Next[input];
}
