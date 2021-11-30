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
  if(y > 0.7){
    nav = 1;
  }
  else if(y < -0.7){
    nav = 2;
  }
  else{
    nav = 0;
  }
  
  //move arrow when accelerator is moved
  if(nav == 1){
    spot += 1;
    lcd.clear();
    lcd.print(" STP   ELV   UR");    
  }
  if(nav == 2){
    spot += -1;
    lcd.clear();
    lcd.print(" STP   ELV   UR");    
  }
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
  lcd.setCursor(spot, 1);
  lcd.write((unsigned char)1);

  if (spot == 2 && digitalRead(8) == HIGH || spot == 3 && digitalRead(8) == HIGH || spot == 1 && digitalRead(8) == HIGH){
    return(0);
  }
  if (spot == 7 && digitalRead(8) == HIGH || spot == 8 && digitalRead(8) == HIGH || spot == 9 && digitalRead(8) == HIGH){
    return(1);
  }
  if (spot == 13 && digitalRead(8) == HIGH || spot == 14 && digitalRead(8) == HIGH){
    return(2);
  }
  delay(100);
}
