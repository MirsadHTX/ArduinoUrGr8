#include "rgb_lcd.h"

rgb_lcd lcd;

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Hej Mirsad!");
}

void loop()
{
  
}
