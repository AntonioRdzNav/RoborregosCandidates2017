void readInfrarrojos(){                                                                 /***********************/
  readInfraDer = analogRead(infraDer);
  readInfraIzq = analogRead(infraIzq);
  delay(10);
  
  if(readInfraDer > 300) derecha_0 = true;
  else derecha_0 = false;
  if(readInfraIzq > 300) izquierda_0 = true;
  else izquierda_0 = false;
}

