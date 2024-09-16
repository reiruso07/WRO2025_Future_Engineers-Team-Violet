//Inclusión de librerias
#include <Servo.h>
#include <L298N.h>
#include <SR04.h>
#include <math.h>
//Declaración de servos y ultrasonidos con las librerias
SR04 sr04adel = SR04(echo, triger);
SR04 sr04izq = SR04(echo2, triger2);
SR04 sr04der = SR04(echo3, triger3);
//Declaración de variables
#define IN4 9
#define IN3 8
#define echo 47
#define triger 46
#define echo2 48
#define triger2 49
#define echo3 51
#define triger3 50
#define EN 11
L298N motor(EN, IN4, IN3);
Servo servo;
int esquina=0;
int esq=0;
int motors=1;
int lineas=0;
int pared=0;
int paredizq=0;
int paredder=0;
int esquinader=0;
int izq=0;
int der=0;
int si=0;
const int intervalopared=250;
unsigned long antespared=0;
unsigned long antesparedder=0;
unsigned long tiempoantesdelcont=0;
const int intervalo=2500;
const int intervaloder=1900;
int esquinaf=0;
void setup() {
  Serial.begin(9600);
  servo.attach(33);
   //Configuración de los pines de ultrasonido y del driver L298N
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(triger2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(triger3, OUTPUT);
  pinMode(echo3, INPUT);
  //Definición de la velocidad del motor del carro
  motor.setSpeed(180);
  //Función para detener el motor del carro
  motor.stop();
  //Servo en posición inicial
  servo.write(90);
 
}

void loop() {
    //Inicio del ciclo 
//Indicador de esquinas (para saber cuantas vueltas a dado el carro)
 if(lineas<12){
  unsigned long cont = millis();
  float distanciaade = sr04adel.Distance();
  float distanciaizq = sr04izq.Distance();
  float distanciader = sr04der.Distance();
  if(motors==1){
    carrorect();
  }
   //Condición de cruzar esquinas (en sentido antihorario)
  if((distanciaizq>100&&distanciaizq<300&&der==0&&si==0)||esquina==1){
    if((cont-tiempoantesdelcont>intervalo)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0){
        esquina=1;
        si=1;
        esq=1;
        carroesqizq();
        motors=0;
        izq=1;
      }
      else{
        esq=0;
        carrorect();
        esquina=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  } 
   //Condición de cruzar esquinas (en sentido horario)
    if((distanciader>100&&distanciader<300&&izq==0&&si==0)||esquinader==1){
    if((cont-tiempoantesdelcont>intervaloder)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0){
        esquinader=1;
        si=1;
        esq=1;
        carroesqder();
        motors=0;
        der=1;
      }
      else{
        esq=0;
        carrorect();
        esquinader=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }
//Condiciones para centrar el carro
  if((distanciaizq<40&&esquina==0&&esquinader==0&&paredder==0)||paredizq==1){
    if(cont-antespared>intervalopared){
      antespared=cont;
      if(pared==0&&esquina==0&&esquinader==0){
        pared=1;
        si=0;
        carroizq();
        paredizq=1;
      }
      
      else if(pared==1&&esquina==0&&esquinader==0){
        pared=0;
        carrorect();
        paredizq=0;
        antespared=0;
      }
    }
  }
  if((distanciader<40&&esquina==0&&esquinader==0&&paredizq==0)||paredder==1){
    if(cont-antesparedder>intervalopared){
      antesparedder=cont;
      if(pared==0&&esquina==0&&esquinader==0){
        pared=1;
        si=0;
        carroder();
        paredder=1;
      }
      else if(pared==1&&esquina==0&&esquinader==0){
        pared=0;
        carrorect();
        paredder=0;
        antesparedder=0;
      }
    }
  }
 }
 else{
  stopcar();
 }
}
//Funciones fundamentales del carro
void carroalante() {
  motor.stop();
  motor.forward();
}
void carroatras() {
  motor.stop();
  motor.backward();
}
void carromedder() {
  motor.stop();
  servo.write(105);
  motor.forward();
}
void carromedizq() {
  motor.stop();
  servo.write(85);
  motor.forward();
}
void carroder() {
  motor.stop();
  servo.write(70);
  motor.forward();
}
void carroizq() {
  motor.stop();
  servo.write(110);
  motor.forward();
}
void carroesqder() {
  motor.stop();
  servo.write(110);
  motor.forward();
}
void carroesqizq() {
  motor.stop();
  servo.write(65);
  motor.forward();
}
void carrorect() {
  motor.stop();
  servo.write(90);
  motor.forward();
}
void stopcar() {
  motor.forward();
  servo.write(90);
  delay(1000);
  motor.stop();
  delay(1000000);
}
