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
  //setup classes
  acc.init();
  lcd.begin(16,2);
  clockSetup(ur);
  counterSetup(8);
  navSetup();
  lcd.clear();
}

void loop() 
{
  //opens navigation menu
  if(runNav == true)
  {
    currentState = navigation();
    delay(100);
  }
  //opens function if arrow is under funciton name and button is pressed
  if(currentState == 2)
  {
    lcd.clear();
    clocking(ur, lcd);
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
    elev();
    runNav = false;
  }
  else{
    currentState = 3;
  }
  //returns to menu if accelerometors x axis is changed drastically
  if(toMenu() == true && currentState != 3){
    lcd.clear();
    runNav = true;
  }
  delay(50);
}
