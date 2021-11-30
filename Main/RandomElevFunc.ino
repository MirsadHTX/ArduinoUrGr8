void Elev(){
  String elev[31]={"Mie","Rasmus","Nelisa","Thøger","Ismail","Nicolai","Jeppe","William","gusse","Anders","Pernille","Emil","Mathias","Freja","Tobias","Haris","Silas","Kasper","Taaha","Jens","Gustav","Simon","Lovro","Mohammad","Sarah","Jacob","Fahmi","Jabriil","Robert","Jonatan","Mirsad"};
  int x = random(0,30);
  if(digitalRead(8) == HIGH){
    lcd.clear();
    lcd.print(elev[x]);
  }
}
