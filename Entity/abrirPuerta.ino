void abrirPuerta() {
    avanza();
    delay(3000);
    stop();
    delay(1000);
    vueltaPuerta();
    delay(9000);
    readColor(r, g, b);
    showRGB();
    readColor(r, g, b);
    estadoBoton = digitalRead(BotonColores);
    special = false;
    while((currentColor(r, g, b) != 4) && estadoBoton == 0){
      readColor(r, g, b);
      calculaDistancia();
      estadoBoton = digitalRead(BotonColores);
      maze();
    }
    readColor(r, g, b);
    while((currentColor(r, g, b) != 5) && estadoBoton == 0){
      estabilizar();
      estadoBoton = digitalRead(BotonColores);
      readColor(r, g, b);
    }
}

