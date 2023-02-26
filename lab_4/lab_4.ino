#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET -1
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32
#define buzzer 11
Adafruit_SSD1306 OLED(OLED_RESET);
double sensor = 0, move;
double dirX = 0, dirY = 1;
bool gameOver = false;
struct POSITION
{
  double x,y;
} ballPos;

void setup() 
{
  pinMode(buzzer, OUTPUT);
  ballPos = {64,16};
  OLED.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  OLED.drawCircle(ballPos.x,ballPos.y,2,WHITE);
  Serial.begin(9600);
}

void moveBall()
{
  if(ballPos.x >= move-10 && ballPos.x <= move+10 && ballPos.y >= 28)
  {
    dirX = (ballPos.x - move)/21.f;
    dirY = -1;
    tone(buzzer,500,25);
  }
  if(ballPos.x < 2 || ballPos.x > 126)
  {
    dirX = -dirX;
    tone(buzzer,400,25);
  }
  if(ballPos.y < 2)
  {
    dirY = -dirY;
    tone(buzzer,400,25);
  } 
  if(ballPos.y >= 31)
  {
    gameOver = true;
    tone(buzzer,700,25);
  }
  ballPos.y += dirY;
  ballPos.x += dirX*15;
  OLED.drawCircle(ballPos.x,ballPos.y,2,WHITE);
}

void loop() 
{
  sensor = analogRead(A0);
  move = ((sensor*108)/1023)+10;
  Serial.println(sensor);
  OLED.clearDisplay();
  if(!gameOver)
  {
    moveBall();
    OLED.drawLine(move-10,31,move+10,31,WHITE);
  }
  else 
  {
    OLED.setTextColor(WHITE);
    OLED.setCursor(10,1);
    OLED.setTextSize(2);
    OLED.println(" GameOver");
    
  }
  OLED.display();
  delay(30);
}
