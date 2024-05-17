#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int led1 = 2;
int led2 = 4;
const int solar = 34;
int sol = 0;

LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}


void loop(){
  sol = analogRead(solar);
  Serial.println(sol);
  if(sol >= 3200){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    Serial.println("SOLAR POWER");
    lcd.setCursor(0,0);
    lcd.println("SOLAR POWER");
  }
  else{
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    Serial.println("NORMAL POWER");
    lcd.setCursor(0,0);
    lcd.println("NORMAL POWER");
  }
  delay(500);
}