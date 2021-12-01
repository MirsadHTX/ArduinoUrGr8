#include <DS1307.h>
#include <Wire.h>
#include <rgb_lcd.h>
#include <MMA7660.h>

rgb_lcd lcd;
DS1307 ur;
MMA7660 acc;
int currentState;
bool runNav = true;

void setup() 
{
  //setup klasser 
  acc.init();
  lcd.begin(16,2);
  clockSetup(ur);
  counterSetup(8);
  navsetup();
  lcd.clear();
}

void loop() 
{
  //går ind på menu
  if(runNav == true)
  {
    currentState = navigation();
    delay(100);
  }
  if(currentState == 2)
  {
    lcd.clear();
    clocking(ur, lcd, false);
    runNav = false;
  }
  else if(currentState == 0)
  {
    lcd.clear();
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
  if(ToMenu() == true && currentState != 3){
    lcd.clear();
    runNav = true;
  }
  delay(50);
}
