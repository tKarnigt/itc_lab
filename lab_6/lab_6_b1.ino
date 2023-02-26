#include <Wire.h>

char x[6] = "HELLO";
int count = 1;

void setup()
{
  Serial.begin(9600);
  Wire.begin(); 
}

void loop()
{
  
  for(int i = 2; i<=3 ; i++)
  {
    Wire.beginTransmission(i);   
    Wire.write(x); 
    Wire.write(count);
    Wire.endTransmission();  
	
    Wire.requestFrom(i, 6);
    int j = 0;
    while(Wire.available()>1)
    {
      x[j] = Wire.read();
      j++;
    }
    count = Wire.read();
    delay(500);
    
    Serial.print("Arduino ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.print(x);
    Serial.println(count);
  }
}
