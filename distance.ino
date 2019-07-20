#include <LiquidCrystal.h>
#include<EEPROM.h>

LiquidCrystal lcd(4,5,6,7,8,9);
LiquidCrystal lcd1(2,3,10,11,12,13);
unsigned long int begin_time = millis();
unsigned long int end_time = 0;
unsigned long int end_time1 = 0;
#define speed_pin A4
int carspeed = 0;
int count = 0;
int count1 = 0;
int pulse_to_distance = 50;
int EngineSpeed = 0;
#define EngineRPM 1
void setup() 
{
  pinMode(speed_pin , INPUT);
  analogWrite(speed_pin , HIGH);
  pinMode(EngineRPM, INPUT);
  digitalWrite(EngineRPM, HIGH);
}

void loop() 
{
  if(analogRead(speed_pin) == 0)
  {
    count ++;
    end_time = millis();
  }
  if(digitalRead(EngineRPM == HIGH))
  {
    count1++;
  end_time1 = millis();
  }
  unsigned long int total_time = end_time - begin_time;
  unsigned long int total_time1 = end_time1 - begin_time;
  int carspeed = 2*count * pulse_to_distance;
  if(total_time1 == 60000)
  EngineSpeed = count1/14;
  lcd1.setCursor(0,0);
  lcd1.print("SPEED = ");
  lcd1.print(carspeed);
  lcd1.print("m/s");
  lcd1.setCursor(0,1);
  lcd1.print("Engine RPM");
  lcd1.print(EngineSpeed);
 int distance = carspeed*total_time;
if(distance%50 == 0)
writeInit(0,distance);
int k = readInit(0);
lcd.setCursor(0,0);
lcd.print("DISTANCE");
lcd.print(k); 
}

int readInit(unsigned int add)
{
  union
  {
    byte b[2];
    int f;
    }
    data;
    for(int i = 0;i<2;i++)
    {
      data.b[i] = EEPROM.read(add+i);
    }
    return data.f;
  }
  void writeInit(unsigned int add, int x)
  {
    union
    {
      byte b[2];
      int f;
    }data;
    data.f = x;
    for(int i = 0;i<2;i++)
    {
      EEPROM.write(add+i,data.b[i]);
    }
    }
  


