/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////    SPUTNIK    ///////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#include <MPU6050.h>
//#include <I2Cdev.h>
//#include<Wire.h>
#include<String.h>
 
//MPU6050 mpu;
//int16_t ax, ay, az;
//int16_t gx, gy, gz;

struct color{
  String nombre;
  double red;
  double green;
  double blue;
};

#define disparador_derecha 44
#define disparador_izquierda  48
#define disparador_enfrente 46 
#define disparador_pelota 42
#define entrada_derecha 45
#define entrada_izquierda 49
#define entrada_enfrente 47
#define entrada_pelota 43
#define motorD1 4
#define motorD2 5
#define motorI1 9
#define motorI2 10
#define infraDer A0
#define infraIzq A1
#define BotonColores 38
#define LED_red 22
#define LED_blue 23
#define LED_green 24

#define S0 34
#define S1 35
#define S2 53
#define S3 52
#define sensorOut 51
double r = 0, g = 0, b = 0;
const int num_col = 8;
const int range = 7;
int color_position;           //  0        1       2       3         4          5          6        7   
String color_names[num_col] = {"blanco", "rosa", "rojo", "azul", "naranja", "amarillo", "negro", "verde"};
color color_position_arr[num_col];
double readInfraIzq;
double readInfraDer;
bool estadoBoton;    
const double range_Giros = 2.5;
double der = 0, fren = 0, izq = 0;                                                      
double DISTANCIA_DERECHA, DISTANCIA_IZQUIERDA, DISTANCIA_FRENTE;
double DISTANCIA_PELOTA;
bool frente, derecha, izquierda, pelota;                                                            
bool derecha_0, izquierda_0;
int frente_IMU, derecha_IMU, izquierda_IMU, atras_IMU;
int tempAnterior;
bool special;
bool pelotaEnfrente = false, tengoPelota = false, paredEnfrente = false, estoyGirado = false, porteriaEnfrente = false;
bool estoyEsquina = false, acabe = false, gol = false;
int gradoGiro = 0;
bool contDer;
bool contFrente;
bool tunel;
 
void setup(){
  Serial.begin(9600);
  pinMode(disparador_pelota, OUTPUT);
  pinMode(entrada_pelota, INPUT);
  pinMode(disparador_derecha, OUTPUT);
  pinMode(disparador_izquierda, OUTPUT);
  pinMode(disparador_enfrente, OUTPUT);
  pinMode(entrada_izquierda, INPUT);
  pinMode(entrada_derecha, INPUT);
  pinMode(entrada_enfrente, INPUT);
  pinMode(motorD1,OUTPUT);
  pinMode(motorD2,OUTPUT);
  pinMode(motorI1,OUTPUT);
  pinMode(motorI2,OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(LED_blue, OUTPUT);
  pinMode(LED_red, OUTPUT);
  pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  pinMode(BotonColores,INPUT);
}
 
void loop(){
// Codigo 
  estadoBoton = digitalRead(BotonColores);
  stop();
  if (estadoBoton == 1){
    readColor(r, g, b);
    calibrarColores();
    while(true){
      estadoBoton = digitalRead(BotonColores);
      if(estadoBoton == 1){
        while(true){
        digitalWrite(LED_green, HIGH);
         //calibrarMPU();
        digitalWrite(LED_green, LOW);
        estadoBoton = digitalRead(BotonColores);
          if(estadoBoton == 1){
            while(true){
              stop();
              digitalWrite(LED_green, HIGH);
              delay(1000);
              readColor(r, g, b);
              estadoBoton = digitalRead(BotonColores);
              switch(currentColor(r, g, b)){
                case 0:                       //Zona 0
                  contDer = false;
                  contFrente = false;
                  while((currentColor(r, g, b) != 1) && estadoBoton == 0){
                    digitalWrite(LED_green, LOW);
                    tunel = false;
                    readColor(r, g, b);
                    estadoBoton = digitalRead(BotonColores);
                    zona_0();
                  }
                break;
                case 1:                       //Maze
                  special = false;
                  while((currentColor(r, g, b) != 4) && estadoBoton == 0){
                    digitalWrite(LED_green, LOW);
                    readColor(r, g, b);
                    calculaDistancia();
                    estadoBoton = digitalRead(BotonColores);
                    maze();
                  }
                break;
                case 4:                       //Puerta Giratoria
                  while((currentColor(r, g, b) != 5) && estadoBoton == 0){
                    digitalWrite(LED_green, LOW);
                    abrirPuerta();
                    readColor(r, g, b);
                    estadoBoton = digitalRead(BotonColores);
                  }
                break;
                case 5:                       //Rampa
                  while((currentColor(r, g, b) != 6) && estadoBoton == 0){
                    digitalWrite(LED_green, LOW);
                    rampa();
                    estadoBoton = digitalRead(BotonColores);
                    readColor(r, g, b);
                  }    
                break;
                case 6:                       //Pelota
                  while((currentColor(r, g, b) != 7) && estadoBoton == 0){
                    digitalWrite(LED_green, LOW);
                    GOL();
                    estadoBoton = digitalRead(BotonColores);
                    readColor(r, g, b);
                  }    
                break;
                default: 
                  digitalWrite(LED_green, LOW);
                  stop();
              }
            }
          } 
        } // seconda while
      } // second if
    } // first while
  } // first if
} // void loop
