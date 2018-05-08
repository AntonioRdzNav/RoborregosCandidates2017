void maze(){  
  calculaDistancia();
  readColor(r, g, b);
  showRGB(); 
  if(!derecha){ 
    if(DISTANCIA_FRENTE < 30){
      while(!frente){                                                              
        avanza(); 
        readColor(r, g, b);
        showRGB();
        calculaDistancia();
      }
    }
    else{
      readColor(r, g, b);
      showRGB();
      if(special == true){
        delay(1400);
        special = false;
      }
      readColor(r, g, b);
      showRGB();
      calculaDistancia();
    }
    readColor(r, g, b);
    showRGB();
    calculaDistancia();
    if(izquierda){ 
      vueltaDerecha();
      back();
      delay(1700);
      miniAvanzaBack();
      calculaDistancia();
      readColor(r, g, b);
      showRGB();
    }
    else{
      vueltaDerecha();
      miniAvanzaFree();
      readColor(r, g, b);
      showRGB(); 
      calculaDistancia();
      
    }
  }
  else if (!frente){
    avanza();
    readColor(r, g, b);
    special = true;
    readColor(r, g, b);
    showRGB();
    calculaDistancia();
  }
  else if(!izquierda){
    calculaDistancia();
    if(DISTANCIA_FRENTE < 30){
      while(!frente){
        avanza();
        readColor(r, g, b);
        showRGB();
        calculaDistancia();
      }
    }
    else{
      //delay(200);
      readColor(r, g, b);
      showRGB();
      calculaDistancia();
    }
    showRGB(); 
    calculaDistancia();
    if(derecha){
      vueltaIzquierda();
      back();
      delay(1700);
      miniAvanzaBack();
      calculaDistancia();
      readColor(r, g, b);
      showRGB();
    }
    else{
      vueltaDerecha();
      miniAvanzaFree();  
      readColor(r, g, b);
      showRGB(); 
      calculaDistancia();
    }
  }
  else{
    showRGB(); 
    calculaDistancia();
    vueltaTotal();
    stop();
    readColor(r, g, b);
    showRGB(); 
    calculaDistancia();
  }  
}

void mazeIzquierdo(){  
  calculaDistancia();
  readColor(r, g, b);
  showRGB(); 
  if(!izquierda){ 
    if(DISTANCIA_FRENTE < 30){
      while(!frente){                                                              
        avanza(); 
        readColor(r, g, b);
        showRGB();
        calculaDistancia();
      }
    }
    else{
      readColor(r, g, b);
      showRGB();
      if(special == true){
        delay(1400);
        special = false;
      }
      readColor(r, g, b);
      showRGB();
      calculaDistancia();
    }
    readColor(r, g, b);
    showRGB();
    calculaDistancia();
    if(derecha){ 
      vueltaIzquierda();
      back();
      delay(1700);
      miniAvanzaBack();
      calculaDistancia();
      readColor(r, g, b);
      showRGB();
    }
    else{
      vueltaIzquierda();
      miniAvanzaFree();
      readColor(r, g, b);
      showRGB(); 
      calculaDistancia();
    }
  }
  else if (!frente){
    avanza();
    readColor(r, g, b);
    special = true;
    readColor(r, g, b);
    showRGB();
    calculaDistancia();
  }
  else if(!derecha){
    calculaDistancia();
//    if(DISTANCIA_FRENTE < 30){
    while(!frente){
      avanza();
      readColor(r, g, b);
      showRGB();
      calculaDistancia();
    }
//    }
//    else{
//      //delay(200);
//      readColor(r, g, b);
//      showRGB();
//      calculaDistancia();
//    }
    showRGB(); 
    calculaDistancia();
//    if(derecha){
    vueltaDerecha();
    back();
    delay(1700);
    miniAvanzaBack();
    calculaDistancia();
    readColor(r, g, b);
    showRGB();
//    }
//    else{
//      vueltaDerecha();
//      miniAvanzaFree();  
//      readColor(r, g, b);
//      showRGB(); 
//      calculaDistancia();
//    }
  }
  else{
    showRGB(); 
    calculaDistancia();
    vueltaTotal();
    stop();
    readColor(r, g, b);
    showRGB(); 
    calculaDistancia();
  }  
}
