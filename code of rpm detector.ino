//==================================================================================||
//Monitoring RPM with LM393 module and LCD with I2C module                          ||
//Author; SLAMET SUPARLAN, instagram @slamets.7 , WhatsApp: +62 858 7000 8869   ||
//DATE  ; MAY 25th, 2019                                                            ||
//==================================================================================||

#include <Wire.h>                 // librarie of wire
#include <LiquidCrystal_I2C.h>    // librarie of LCD I2C
LiquidCrystal_I2C lcd(0x27,20,4); // define I2C address, may be ur I2C addres is different as 0x3F or 0x29, and ur LCD maybe 16,2
int nowstate, paststate;          // condition of pin input
float deteksi;                     // detection of lm393 module for a rotation
unsigned long pasttime;           // previous millis
float rpm;                         // get initial for rpm
int pindetect = 7;                //define pin from lm393 module
void setup()
{
  lcd.init();             //initialitation LCD
  lcd.init();
  lcd.backlight();      
  pinMode(pindetect, INPUT);      //define input pin from lm393 module
}
void loop()
{
  lcd.setCursor(3,0); lcd.print("RPM  DETECTION");   //print to LCD
  lcd.setCursor(5,1); lcd.print("R P M : ");        
  nowstate=digitalRead(7);  //compare the condition
  if(nowstate!=paststate)
  {  
    if(digitalRead(pindetect)==LOW) // this "if" only for adding detection value if input is LOW 
    {
      deteksi++;
    }
    paststate=nowstate;   // calibration condition
  }
  if(millis()-pasttime>5000) //this "if" for delaying 5 seconds without delay()
  {
    pasttime=millis();
    lcd.clear(); lcd.setCursor(13,1); lcd.print(rpm,0); //print to LCD
    deteksi=0;
    deteksi=0;
    rpm=0;
  }
  rpm=deteksi*12;         //calibration, 12 only for delaying 5 s, other value is different value
}
