#include<LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);
volatile int count = 0;
volatile int count2 = 0;
const int rpm_pin= 14;
#define time_in_distance 50
#define speed_pin A2
 unsigned long int begin_time = millis();
 unsigned long int begin_time1 = begin_time;
 unsigned long int end_time = 0;
unsigned long int end_time1 = 0;
 
void setup() {
 lcd.begin(16,2);
 pinMode(14,INPUT);
 digitalWrite(14,HIGH);
}

void loop() {
 unsigned long int end_time;
 if(digitalRead(14) != HIGH)
 {count++;
 //this one revolution will give c=14
 //thus total number of revolution = count/14
unsigned long int end_time = millis();}
unsigned long int time_taken = end_time - begin_time;
//now we get total time in distance from the constants
//so ditance covered in one pulse = x;
if(analogRead(A2) !=HIGH)
{count2++;
unsigned long int end_time1 = millis();}
unsigned long int time_taken1 = end_time1 - begin_time1;
lcd.setCursor(0,0);
lcd.print ("total speed = ");
if(time_taken == 1000)
lcd.print (count2*time_in_distance);
lcd.setCursor(1,0);
lcd.print("Engine RPM");
if(time_taken == 60000)
lcd.print(count/14);
}
