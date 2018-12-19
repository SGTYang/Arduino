#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);

void init_lcd(){
  lcd.begin();
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("SPEED");
  lcd.setCursor(1,1);
  lcd.print("0");
}

void display_lcd(int speed){
  static int prev_speed = 0;
  
  if(speed != prev_speed){
    lcd.setCursor(0,1);
    lcd.print("     ");
    lcd.setCursor(1,1);
    lcd.print(speed);
    prev_speed = speed;
  }
}
