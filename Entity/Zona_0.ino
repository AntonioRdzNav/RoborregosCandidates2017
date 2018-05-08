////Colocar robot SIEMPRE en lado derecho
//void zona_0(){
//  readInfrarrojos();
//  calculaDistancia();
//  estadoBoton = digitalRead(BotonColores);
//  /*Serial.print("Derecha = ");
//  Serial.println(readInfraDer);
//  Serial.print("Izquierda = ");
//  Serial.println(readInfraDer);*/
//  avanza0();  
//  if(frente) {
//     vueltaIzquierda0();
//     back();
//     delay(2000);
//     estadoBoton = digitalRead(BotonColores);
////     contFrente = true;
//    while(currentColor()
//  }
//  if(derecha_0 || izquierda_0){
//    Serial.print("SI");
//    stop();
//    delay(600);
////    if(contFrente){
////      back();
////      delay(600);
////      vueltaIzquierda0();
////      back();
////      delay(2000);
////      miniAvanzaBack();
////      vueltaDerecha0();
////      back();
////      delay(2000);
////      while(!frente){
////        avanza0();
////        calculaDistancia();
////      }
////      vueltaDerecha0();
////      while(!frente){
////        avanza0();
////        calculaDistancia();
////      }
////      vueltaIzquierda0();
////    }
//    contDer = true;
//    back();
//    delay(600);
//    estadoBoton = digitalRead(BotonColores);
//    calculaDistancia();
//    if(DISTANCIA_DERECHA < DISTANCIA_IZQUIERDA){
//      vueltaIzquierda0();
//      back();
//      delay(2000);
//      stop();
//      estadoBoton = digitalRead(BotonColores);
//      calculaDistancia();
//      while(!frente){
//        readInfrarrojos();
//        avanza0();
//        calculaDistancia();
//        if((derecha_0 || izquierda_0) && contDer == true){
//          back();
//          delay(700);
//          vueltaIzquierda0();
//          miniAvanza0();
//          vueltaDerecha0();
//          contDer = false;
//          calculaDistancia();
//        }
//      }
//      vueltaDerecha0();
//    }
//    else if(DISTANCIA_IZQUIERDA < DISTANCIA_DERECHA){
//      vueltaDerecha0();
//       back();
//      delay(2000);
//      stop();
//      estadoBoton = digitalRead(BotonColores);
//      calculaDistancia();
//      while(!frente){
//          readInfrarrojos();
//          calculaDistancia();
//          avanza0();
//          if((derecha_0 || izquierda_0) && contDer == true){
//            avanza0();
//            back();
//            delay(700);
//            vueltaDerecha0();
//            miniAvanzaFree();
//            vueltaIzquierda0();
//            contDer = false;
//            calculaDistancia();
//          }
//      }
//      estadoBoton = digitalRead(BotonColores);
//      vueltaIzquierda0(); 
//      
//     
//    }
//  }
//}
//Colocar robot SIEMPRE en lado derecho

void zona_0(){
  readInfrarrojos();
  calculaDistancia();
  avanza0();  
  if(frente) {
     vueltaIzquierda0();
     back();
     delay(2000);
     estadoBoton = digitalRead(BotonColores);
  }
  if(derecha_0 || izquierda_0){
    back();
    delay(600);
    estadoBoton = digitalRead(BotonColores);
    calculaDistancia();
    //contDer = true;
    if(DISTANCIA_DERECHA < DISTANCIA_IZQUIERDA){
      vueltaIzquierda0();
      back();
      delay(2000);
      stop();
      calculaDistancia();
      while(!frente){
        avanza0();
        calculaDistancia();
      }
      vueltaDerecha0();
    }
    else if(DISTANCIA_IZQUIERDA < DISTANCIA_DERECHA){
      vueltaDerecha0();
      back();
      delay(2000);
      stop();
      tunel = true;
      estadoBoton = digitalRead(BotonColores);
      calculaDistancia();
      while(tunel){
        calculaDistancia();
        readInfrarrojos();
         back();
         delay(2000);
         vueltaDerechaTunel();
         avanza0();
         delay(500);
         vueltaIzquierda0();
         back();
         delay(2000);
         readInfrarrojos();
         while((!derecha_0 || !izquierda_0) && !frente){
          avanza0();
          calculaDistancia();
          tunel = !frente;
          readInfrarrojos();
         }
      }
      vueltaIzquierda0();
    }
          
          /*if((derecha_0 || izquierda_0) && contDer == true){
            avanza0();
            back();
            delay(700);
            vueltaDerecha0();
            miniAvanzaFree();
            vueltaIzquierda0();
            contDer = false;
            calculaDistancia();
          }*/
      }
      
     
    }

