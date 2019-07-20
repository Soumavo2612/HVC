#include<LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);
const int trigpin = 10;
volatile int c = 0;
unsigned long int begin_time = 0;
unsigned long int end_time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(10,INPUT);
digitalWrite(10,HIGH);
begin_time = millis();
lcd.begin(16,2);
lcd.setCursor(4,0);
lcd.print("ENGINE RPM");
}

void loop() {
  int revolutions = 0;

if(digitalRead(10) == LOW)
 c++;
end_time = millis();
unsigned long int time_taken = end_time - begin_time;
begin_time = end_time;
if(time_taken == 60000)
  revolutions = c/14;
 lcd.setCursor(6,1);
 lcd.print(revolutions);
 delay(500);

}
