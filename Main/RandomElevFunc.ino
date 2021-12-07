void elev()
{
  String elev[31]={"Mie","Rasmus","Nelisa","Th0ger","Ismail","Jeppe","William","Anders","Pernille","Emil","Mathias","Freja","Tobias","Haris","Silas","Kasper","Taaha","Jens","Simon","Lovro","Mohammad","Sarah","Jacob","Fahmi","Jabriil","Robert","Jonatan","Mirsad"};
  
  //takes random name from the string and prints it
  int x = random(0,27); 
  if(digitalRead(8) == HIGH)
  {
    lcd.clear();
    lcd.print(elev[x]);
  }
}
