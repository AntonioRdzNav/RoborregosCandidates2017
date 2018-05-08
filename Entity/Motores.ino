void stop(){                                                                                          
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 0);
}

void miniAvanza0(){
  avanza();
  delay(2100);
  stop();
  delay(500);
}

void miniAvanzaBack(){                                                                                 
  avanza();
  delay(2550);
  stop();
  delay(500);
}

void miniAvanzaFree(){
  avanza();
  delay(2100);
  stop();
  delay(500);
}

void avanza() {
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 144);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 144);
}

void avanza0() {
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 144);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 145);
}

void avanzaRampa() {
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 255);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 240);
}

void avanzaRampaLento() {
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 255);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 0);
}

void avanzaNegro() {
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 70);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 60);
}

void backRampa() {
  analogWrite(motorD1, 200);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 180);
  analogWrite(motorI2, 0);
}

void vueltaPuerta() {
  analogWrite(motorD1, 70);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 190);
  analogWrite(motorI2, 0);
}

void back() {
  showRGB(); 
  analogWrite(motorD1, 149);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 140);
  analogWrite(motorI2, 0);
}

void back0() {
  showRGB(); 
  analogWrite(motorD1, 149);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 140);
  analogWrite(motorI2, 0);
}

void backBuscar(){
  analogWrite(motorD1, 70);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 60);
  analogWrite(motorI2, 0);
}

void vueltaDerecha(){                                                                              
    analogWrite(motorD1, 90);
    analogWrite(motorD2, 0);
    analogWrite(motorI1, 0);
    analogWrite(motorI2, 80);
    delay(1240);
    stop();
}

void vueltaDerecha0(){                                                                              
    analogWrite(motorD1, 90);
    analogWrite(motorD2, 0);
    analogWrite(motorI1, 0);
    analogWrite(motorI2, 80);
    delay(1200);
    stop();
}

void vueltaDerechaTunel(){                                                                              
    analogWrite(motorD1, 90);
    analogWrite(motorD2, 0);
    analogWrite(motorI1, 0);
    analogWrite(motorI2, 80);
    delay(1600);
    stop();
}

void vueltaIzquierda0(){                                                                              
    analogWrite(motorD1, 0);
    analogWrite(motorD2, 90);
    analogWrite(motorI1, 80);
    analogWrite(motorI2, 0);
    delay(1200);
    stop();
}

void vueltaIzquierda(){                                                                              
    analogWrite(motorD1, 0);
    analogWrite(motorD2, 80);
    analogWrite(motorI1, 90);
    analogWrite(motorI2, 0);
    delay(1250);
    stop();
}

void vueltaTotal(){
  calculaDistancia();
  if(adondeGiro()) {
    stop();
    readColor(r, g, b);
    showRGB();
    analogWrite(motorD1, 130);
    delay(2200); 
    stop(); 
    analogWrite(motorI2, 130);
    delay(1500);
    stop();
  }
  else {
    stop();
    showRGB();
    analogWrite(motorI1, 130);
    delay(2200); 
    stop();
    analogWrite(motorD2, 130);
    delay(1500);
    stop();
  }
  back();
  delay(2500);
  showRGB();
  miniAvanzaBack();
  showRGB();
}

void estabilizar(){
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 160);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 144);
}

void avanzaGol() {
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 245);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 255);
}

void avanzaBuscar(){
  analogWrite(motorD1, 0);
  analogWrite(motorD2, 60);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 53);
}

void vueltaPelotaEnfrente() {
  analogWrite(motorD1, 60);
  analogWrite(motorD2, 0);
  analogWrite(motorI1, 0);
  analogWrite(motorI2, 60);
  delay(1200);
}

void vueltaPelotaDerecha() {
    analogWrite(motorD1, 0);
    analogWrite(motorD2, 62);
    analogWrite(motorI1, 0);
    analogWrite(motorI2, 33);
    delay(7500);
}

