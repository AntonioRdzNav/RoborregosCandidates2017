bool buscarPelota(){
  readColor(r, g, b);
  while((currentColor(r, g, b) != 7)) {
    avanzaNegro();
    readColor(r, g, b);
  }
  avanzaBuscar();
  delay(2800);
  stop();
  delay(500);
  readColor(r, g, b);
  if(currentColor(r, g, b) == 4)
    return true;
  else
    return false;
}

void GOL(){
  if(buscarPelota()){
      vueltaPelotaEnfrente();
      stop();
      calculaDistanciaPelota();
      while(!porteriaEnfrente){
        avanzaGol();
        calculaDistanciaPelota();
      }
  }
  else{
    readColor(r, g, b);
    while((currentColor(r, g, b) != 6)) {
      backBuscar();
      readColor(r, g, b);
    }
    backBuscar();
    delay(700);
    vueltaDerecha();
    back();
    delay(2500);
    if(buscarPelota()){
      vueltaPelotaDerecha();
      while(!porteriaEnfrente){
        avanzaGol();
        calculaDistanciaPelota();
      }
    }
    estadoBoton = digitalRead(BotonColores);
    readColor(r, g, b);
    while((currentColor(r, g, b) != 6) && estadoBoton == 0){
      readColor(r, g, b);
      calculaDistancia();
      maze();
    }
    stop();
    delay(5000);
  }
}

         
