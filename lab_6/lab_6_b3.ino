#include <Wire.h>

#define slave 3

char x[6];
int count;

void receive(int index)
{
  int i = 0;
  while(Wire.available()>1)
  {
    x[i] = Wire.read();
    i++;
  }
  count = Wire.read();
}

void send()
{
  Wire.write(x);
  count++;
  if(count>9) count = 1;
  Wire.write(count);
}

void setup()
{
  Wire.begin(slave);                
  Wire.onReceive(receive); 
  Serial.begin(9600);
  Wire.onRequest(send);
}

void loop()
{
}

