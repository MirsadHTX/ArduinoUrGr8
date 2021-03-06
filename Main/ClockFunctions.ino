String dayofweek[7]= {"Mand", "Tirs", "Onds", "Tors", "Fred", "Loer", "Soen"};
void clockSetup(DS1307 ur)  // Parameter object of clock
{
  ur.begin(); // Starts the clock 
}

void clockDateSetup(DS1307 ur, int y, int m, int d, int h, int mi, int s) // Parameter obj of clock and year, month, day, hour, minute and seconds
{
  ur.begin(); // Starts the clock 
  ur.fillByYMD(y,m,d);  //Filling in YMDHMS
  ur.fillByHMS(h,mi,s);
  ur.setTime(); // Set the clock to the filled date
}

void clocking(DS1307 ur, rgb_lcd lcdobj) 
{
  ur.getTime(); // Get the time from RTC module
  lcd.setCursor(0,0);
  if(ur.hour < 10)  //Hours, minutes and seconds display on lcd screen, if statement for under 10 to add a zero
  {
    lcdobj.print("0");
    lcdobj.print(ur.hour);
  }
  else
  {
    lcdobj.print(ur.hour);
  }
  lcdobj.print(":");
  if(ur.minute < 10)
  {
    lcdobj.print("0");
    lcdobj.print(ur.minute);
  }
  else
  {
    lcdobj.print(ur.minute);
  }
  lcdobj.print(":");
  if(ur.second < 10)
  {
    lcdobj.print("0");
    lcdobj.print(ur.second);
  }
  else
  {
    lcdobj.print(ur.second);
  }
  lcdobj.setCursor(0,1); // Writes on next line date
  lcdobj.print(ur.dayOfMonth);
  lcdobj.print("/");
  lcdobj.print(ur.month);
  lcdobj.print("/");
  lcdobj.print(ur.year);
  lcdobj.setCursor(12,1); // Further on next line, day
  lcdobj.print(dayofweek[ur.dayOfWeek-1]);
  delay(100); // Add small delay for no flicking screen effect
}
