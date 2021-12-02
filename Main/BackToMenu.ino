float x2, y2, z2;
int ToMenu()
{
  acc.getAcceleration(&x2, &y2, &z2);
  
  if(x2 > 0.7)  //detects if accelerometer is changed towards the x axis
  {
    return true;
  }
  else
  {
    return false;
  }
  if(x2 < 0.6)
  {
    return false;
  }
}
