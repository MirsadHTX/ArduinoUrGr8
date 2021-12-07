// Declaring scopes and default values
bool pinState;
bool pressedOnce, toggle = false; 
double counter = 0;
double a = millis();
double b;
int counterTime[]={};
String seco,minu;
bool minuOnce = false;

// Function to setup the pin of certain pin as argument
void counterSetup(int pinN)
{
  pinMode(pinN, INPUT);
}


void counterLoop(int pinN, rgb_lcd rgbLcd, int x, int y) // Declare function with parameter of pin number of button, Rgb lcd screen object and x, y for position on screen
{
  pinState = digitalRead(pinN); // Reads the pin state given from parameter

  if(pinState == true && pressedOnce == false)  // Button click
  {
    if(toggle == false) // Defines toggle, if clicked once before change to other one
    {
      toggle = true;
    }
    else if(toggle == true) // Resets
    {
      toggle = false;
      rgbLcd.clear();
      rgbLcd.setCursor(x,y);
    }
  }
  if(toggle == true)  // if toggle is true it will keep counting up
  {
    b = millis();
    counter = (b - a)/1000;
  }
  else    // millis function running outside of, toggle if loop, which subtracs b, a value
  {
    a = millis();
  }
  pressedOnce = pinState; // Set pressed once to pin state so first if statement would be false after first loop if hold


  minu = String((int)counter/60); // Converts counter to minutes
  
  if((int)counter/60 < 10) // add 0 infront to keep 2 digit and 2 decimal on display
  {
    minu = 0+minu;
  }


  seco = String(fmod(counter,60),2); // Converts double to string with 2 decimals
  
  if(fmod(counter,60) < 9.99) // add 0 infront to keep 2 digit and 2 decimal on display
  {
    seco = 0+seco;
  }
  rgbLcd.setCursor(x,y);    // sets Cursor where needed
  rgbLcd.print(minu + ":" + seco); // Prints output for stoptimer
}
