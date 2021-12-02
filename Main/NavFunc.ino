int nav;
int spot = 0;
float x, y, z;

void navsetup()
{
  //create custom arrow
  byte pointer[8] = {
    0b00000,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b00100,
    0b00100,
    0b00000
  };
  lcd.createChar(1,pointer);
}
int navigation(){
  //detect variation in rotation on the x axis
  acc.getAcceleration(&x, &y, &z);
  lcd.setCursor(0, 0);
  lcd.print(" STP   ELV   UR");
  if(y > 0.7){
    nav = 1;
  }
  else if(y < -0.7){
    nav = 2;
  }  
  
  //detect if user wants to go back to the  main menu
  else if(x > 0.7){
    return 3;
  }
  else{
    nav = 0;
  }
  
  //movex arrow to the right when accelerometor is moved
  if(nav == 1){
    spot += 1;
    lcd.clear();
    lcd.print(" STP   ELV   UR");    
  }
  //moves arrow to the left when accelerometor is moved
  if(nav == 2){
    spot += -1;
    lcd.clear();
    lcd.print(" STP   ELV   UR");    
  }
  
  //prevents arrow from going off screen
  if(spot > 15){
    spot = 0;
    lcd.clear();
    lcd.print(" STP   ELV   UR");    
  }
  if(spot < 0){
    spot = 15;
    lcd.clear();
    lcd.print(" STP   ELV   UR");    
  }
  
  //determines arrows position and writes it
  lcd.setCursor(spot, 1);
  lcd.write((unsigned char)1);

  //detects if button is pressed while arrow is under a program
  if (spot == 2 && digitalRead(8) == HIGH || spot == 3 && digitalRead(8) == HIGH || spot == 1 && digitalRead(8) == HIGH)
  {
    return(0);
  }
  if (spot == 7 && digitalRead(8) == HIGH || spot == 8 && digitalRead(8) == HIGH || spot == 9 && digitalRead(8) == HIGH)
  {
    return(1);
  }
  if (spot == 13 && digitalRead(8) == HIGH || spot == 14 && digitalRead(8) == HIGH)
  {
    return(2);
  }
  delay(100);
}
