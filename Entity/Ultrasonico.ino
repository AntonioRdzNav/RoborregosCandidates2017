double sensor(int trigPin, int echoPin){
  long tiempo;
  double distancia;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  tiempo = (pulseIn(echoPin, HIGH)/2); 
  distancia = float(tiempo * 0.0343);
  if (distancia > 300){
    return 300.0;
  }
  else{                                                                
    return distancia;
  }
}
 
/*void calculaDistanciaGiros(double &der, double &izq, double &fren, double &pel){               
  double sum_D = 0, sum_I = 0, sum_A = 0, sum_P = 0;
  for(int cont = 0; cont < 500; cont++){
    sum_A += sensor(disparador_enfrente, entrada_enfrente);                         
    sum_I += sensor(disparador_izquierda, entrada_izquierda);
    sum_D += sensor(disparador_derecha, entrada_derecha);
    sum_P += sensor(disparador_derecha, entrada_derecha);
  }
  der = sum_D/500.0;
  izq = sum_I/500.0;
  fren = sum_A/500.0;
  pel = sum_P/500.0;
}*/

void calculaDistancia(){
  DISTANCIA_DERECHA = sensor(disparador_derecha, entrada_derecha);
  DISTANCIA_IZQUIERDA = sensor(disparador_izquierda, entrada_izquierda);
  DISTANCIA_FRENTE = sensor(disparador_enfrente, entrada_enfrente);
  delay(10);
  if(DISTANCIA_FRENTE > 200){
    back();
    delay(100);
  }
    
  DISTANCIA_FRENTE = DISTANCIA_FRENTE > 200 ? 0 : DISTANCIA_FRENTE;
  
  
  if(DISTANCIA_FRENTE <= 7) frente = true;
  else frente = false;
  if(DISTANCIA_DERECHA <= 20) derecha = true;
  else derecha = false;
  if(DISTANCIA_IZQUIERDA <= 20) izquierda = true;
  else izquierda = false;
  /*if(DISTANCIA_PELOTA <= 7) pelota = true;
  else pelota = false;*/
}

bool adondeGiro() { //true derehca - false izquierda
  calculaDistancia();
  DISTANCIA_DERECHA = DISTANCIA_DERECHA > 20 ? 0 : DISTANCIA_DERECHA;
  DISTANCIA_IZQUIERDA = DISTANCIA_IZQUIERDA > 20 ? 0 : DISTANCIA_IZQUIERDA;
  if(DISTANCIA_DERECHA > DISTANCIA_IZQUIERDA) 
    return true;
  else
    return false;
}

void calculaDistanciaPelota(){
  DISTANCIA_PELOTA = sensor(disparador_pelota, entrada_pelota);
  DISTANCIA_FRENTE = sensor(disparador_enfrente, entrada_enfrente);
  delay(10);
  
  if(DISTANCIA_PELOTA <= 30) pelotaEnfrente = true;
  else pelotaEnfrente = false;
  if(DISTANCIA_FRENTE <= 20) porteriaEnfrente = true;
  else porteriaEnfrente = false;
  if(DISTANCIA_FRENTE <= 7) paredEnfrente = true;
  else paredEnfrente = false;
}


