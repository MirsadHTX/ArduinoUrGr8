#include <DS1307.h>
#include <Wire.h>
#include <rgb_lcd.h>
#include <MMA7660.h>

MMA7660 acc;
int currentState;
bool runNav = true;
rgb_lcd lcd;
DS1307 ur;

void setup() 
{
  acc.init();
  lcd.begin(16,2);
  clockSetup(ur);
  counterSetup(8);
  navsetup();
  lcd.clear();

  
}

void loop() 
{
  if(runNav == true){
  currentState = navigation();
  delay(100);
  }
  /*
  counterLoop(8, lcd, 0, 1);
  lcd.setCursor(0,0);
  clocking(ur, lcd, true);
*/
  if(currentState == 2)
  {
    clocking(ur, lcd, true);
    runNav = false;
    }
  else if(currentState == 0)
  {
    counterLoop(8, lcd, 0, 1);
    runNav = false;
  }
  else if(currentState == 1)
  {
    Elev();
    runNav = false;
  }
  else{
    currentState = 3;
  }
}
