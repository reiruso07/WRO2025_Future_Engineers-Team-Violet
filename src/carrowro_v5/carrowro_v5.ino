#include <Servo.h>
#include <L298N.h>
#include<SR04.h>
#define IN4 10
#define IN3  11   
#define echo 53
#define triger 52
#define echo2 51
#define triger2 50
#define echo3 49
#define triger3 48
/*#define S0 6
#define S1 5
#define S2 8
#define S3 9
#define sensorOut 7*/
int atras=0;
int cruzizq=0;
int cruzder=0;
String option="";
bool entradaCompleta=false;
int motors=1;
int der=0;
int izq=0;
int ders=0;
int izqs=0;
int lineas=0;
int lineaizq=0;
int lineader=0;
int cruzlineader=0;
int cruzlineaizq=0;
int cruzlineader2=0;
int cruzlineaizq2=0;
int cruzlineader3=0;
int cruzlineaizq3=0;
int cruzconorojo=0;
int cruzconoverde=0;
int estacionamiento=0;
int estacionamientoizq=0;
int estacionamientoctr=0;
int estacionamientoder=0;
int cruce=0;
int crucecono=0;
int crucestacionamiento=0;
const int intervalo =1750;
const int intervalopared =400;
const int intervalolinea=2500;
const int intervalocono=2000;
const int intervaloe=2000;
unsigned long valorantesdeli=0;
unsigned long valorantesdelider=0;
unsigned long valorantesdeliizq=0;
unsigned long valoranteslinea=0;
unsigned long valorantesconor=0;
unsigned long valorantesconov=0;
unsigned long valorantesestacionamientoizq=0;
unsigned long valorantesestacionamientoctr=0;
unsigned long valorantesestacionamientoder=0;
unsigned long valoranteslinea2=0;
SR04 sr04adel=SR04(echo,triger);
SR04 sr04izq=SR04(echo2,triger2);
SR04 sr04der=SR04(echo3,triger3);
#define EN 13
L298N motor(EN,IN4,IN3);
Servo servo;
int patras=0;
int redMin = 29; // Red minimum value
int redMax = 247; // Red maximum value
int greenMin = 32; // Green minimum value
int greenMax = 268; // Green maximum value
int blueMin = 26; // Blue minimum value
int blueMax = 242; // Blue maximum value
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
int redValue;
int greenValue;
int blueValue;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(12);
pinMode(IN4,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(triger,OUTPUT);
pinMode(echo,INPUT);
pinMode(triger2,OUTPUT);
pinMode(echo2,INPUT);
pinMode(triger3,OUTPUT);
pinMode(echo3,INPUT); 
// Set S0 - S3 as outputs
/*pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
// Set Sensor output as input
pinMode(sensorOut, INPUT);
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);*/
motor.setSpeed(180);
motor.stop();
servo.write(90); 
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long cont=millis();
  //Serial.println(cont);
  if(motors==1){
    motor.forward();
  }
  float distanciaade=sr04adel.Distance();
  float distanciaizq=sr04izq.Distance();
  float distanciader=sr04der.Distance();
  // Read Red value
 /* redValue = getRedPW();
  // Read Green value
  greenValue = getGreenPW();
  // Read Blue value
  blueValue = getBluePW();*/
  //Map to value from 0-255
  // Print output to Serial Monitor
  /*Serial.print("Red = ");
  Serial.print(redValue);
  Serial.print(" - Green = ");
  Serial.print(greenValue);
  Serial.print(" - Blue = ");
  Serial.println(blueValue);*/
  //Sensor de distancia
  Serial.print("sensor adelante: ");
  Serial.println(distanciaade);
 Serial.print("sensor derecha");
  Serial.println(distanciader);
  Serial.print("sensor izquierda");
  Serial.println(distanciaizq);
  if(distanciaade<20||patras==1){
   // Serial.println("si funciona");
    if(cont-valorantesdeli>intervalo){
      valorantesdeli=cont;
      Serial.print("el valor antes del intervalo es:");
      Serial.println(valorantesdeli);
      Serial.println("si funciona");
      if(motors==1){
        Serial.println("hecha patra");
        patras=1;
        carroatras();
        motors=0;
        atras++;
      }
      /*else if(motors==2&&distanciaizq>200){
        Serial.println("hecha patra izq");
        patras=1;
        carroesqizq();
        motors=0;
      }*/
      else{
        Serial.println("palante");
        patras=0;
        carroalante();
        motors=1;
        valorantesdeli=0;
        atras=0;
      }
    }
    
  }
   if(distanciader<20||ders==1){
   // Serial.println("si funciona");
    if(cont-valorantesdelider>intervalopared){
      valorantesdelider=cont;
      Serial.print("el valor antes del intervalo es:");
      Serial.println(valorantesdelider);
      Serial.println("si funciona");
      if(der==0){
        Serial.println("cruze der");
        ders=1;
        carroder();
        der=1;
      }
      else{
        Serial.println("recto again");
        ders=0;
        carrorect();
        der=0;
        valorantesdelider=0;
      }
    }
    
  }
     if(distanciaizq<20||izqs==1){
   // Serial.println("si funciona");
    if(cont-valorantesdeliizq>intervalopared){
      valorantesdeliizq=cont;
      Serial.print("el valor antes del intervalo es:");
      Serial.println(valorantesdeliizq);
      Serial.println("si funciona");
      if(izq==0){
        Serial.println("cruze izq");
        izqs=1;
        carroizq();
        izq=1;
      }
      else{
        Serial.println("recto again");
        izqs=0;
        carrorect();
        izq=0;
        valorantesdelider=0;
      }
    }
    
  }
    if((distanciaizq>200||cruzlineaizq==1)&&atras==0&&cruzder==0&&cruzizq==0){
      if(cont-valoranteslinea>intervalolinea){
        Serial.println("cruce izq");
        valoranteslinea=cont;
        if(lineas==0){
          lineas=1;
          carroesqizq();
          cruzlineaizq=1;
          cruzizq=1;
        }
        else{
          lineas=0;
          carrorect();
          cruzlineaizq=0;
          valoranteslinea=0;
          lineas++;
        }
      }
    }
    if((distanciader>200||cruzlineader==1)&&cruzizq==0&&atras==0){
      if(cont-valoranteslinea>intervalolinea){
        Serial.println("cruce der");
        valoranteslinea=cont;
        if(lineas==0){
          lineas=1;
          carroesqder();
          cruzlineader=1;
          cruzder=1;
        }
        else{
          lineas=0;
          carrorect();
          cruzlineader=0;
          lineas++;
        }
      }
    }

        /*if((distanciaizq>200||cruzlineaizq2==1)&&atras==0&&cruzder==0&&cruzizq==1){
            if(cont-valoranteslinea2>intervalolinea){
        Serial.println("cruce izq2");
        valoranteslinea2=cont;
        Serial.print("valor del cont: ");
        Serial.println(cont);        
        Serial.print("valor del intervalo: ");
        Serial.println(valoranteslinea2);
        if(lineas==0){
          lineas=1;
          carroesqizq();
          cruzlineaizq2=1;
          cruzizq=1;
        }
        else{
          lineas=0;
          carrorect();
          cruzlineaizq2=0;
          valoranteslinea2=0;
          lineas++;
        }
      }
    }*/
    if((distanciader>200||cruzlineader==1)&&cruzizq==0&&atras==0){
      if(cont-valoranteslinea>intervalolinea){
        Serial.println("cruce der");
        valoranteslinea=cont;
        if(lineas==0){
          lineas=1;
          carroesqder();
          cruzlineader=1;
          cruzder=1;
        }
        else{
          lineas=0;
          carrorect();
          cruzlineader=0;
          lineas++;
        }
      }
    }
    
        if((distanciaizq>200||cruzlineaizq==1)&&cruzizq==1&&atras==0&&cruzder==0/*&&lineas==12*/){
          if(cont-valoranteslinea>intervalolinea){
        Serial.println("cruce izq3");
        valoranteslinea=cont;
        if(lineas==0){
          lineas=1;
          carroesqizq();
          cruzlineaizq=1;
          cruzizq=1;
        }
        else{
          lineas=0;
          carrorect();
          cruzlineaizq=0;
          valoranteslinea=0;
          lineas++;
        }
      }
    }
    if((distanciader>200||cruzlineader==1)&&cruzizq==0&&atras==0&&lineas==12){
      if(cont-valoranteslinea>intervalolinea){
        Serial.println("cruce der");
        valoranteslinea=cont;
        if(lineas==0){
          lineas=1;
          carroesqder();
          cruzlineader=1;
          cruzder=1;
        }
        else{
          lineas=0;
          carrofin();
         // carrostop();
          cruzlineader=0;
          lineas++;
        }
      }
    }
    
  if(option=="rojo\n"||cruzconorojo==1){
    //ronda=1;
        if(cont-valorantesconor>intervalocono){
      valorantesconor=cont;
      Serial.println("cono rojo");
      if(crucecono==0){
        crucecono=1;
        carroizq();
        cruzconorojo=1;
      }
      else{
        crucecono=0;
        carrorect();
        cruzconorojo=0;

      }
    }
   option= "";
  }    
    if(option=="verde\n"||cruzconoverde==1){
    //ronda=1;
        if(cont-valorantesconov>intervalocono){
      valorantesconov=cont;
      Serial.println("cono verde");
      if(crucecono==0){
        crucecono=1;
        carroder();
        cruzconoverde=1;
      }
      else{
        crucecono=0;
        carrorect();
        cruzconoverde=0;

      }
    }
   option= "";
  } 
  if(option=="morado\n"||estacionamiento==1){
 
        if (option == "izq\n"||estacionamientoizq==1) {
          if(cont-valorantesestacionamientoizq>intervaloe){
            valorantesestacionamientoizq=cont;
            Serial.println("estacionamiento");
            if(crucestacionamiento==0){
            estacionamiento=1;
            estacionamientoizq=1;
            carroder();
            crucestacionamiento=1;
            }
            else{
              estacionamiento=0;
              estacionamientoizq=0;
              carrorect();
              crucestacionamiento=0;
              }
            }
            }

      else if (option == "ctr\n"||estacionamientoctr==1) {
          if(cont-valorantesestacionamientoctr>intervaloe){
            valorantesestacionamientoctr=cont;
            Serial.println("estacionamiento");
            if(crucestacionamiento==0){
            estacionamiento=1;
            estacionamientoctr=1;
            carroder();
            crucestacionamiento=1;
            }
            else{
              estacionamiento=0;
              estacionamientoctr=0;
              carrorect();
              crucestacionamiento=0;
              }
            }
    }
    else if (option == "der\n"||estacionamientoder==1) {
        if(cont-valorantesestacionamientoder>intervaloe){
            valorantesestacionamientoder=cont;
            Serial.println("estacionamiento");
            if(crucestacionamiento==0){
            estacionamiento=1;
            estacionamientoder=1;
            carroder();
            crucestacionamiento=1;
            }
            else{
              estacionamiento=0;
              estacionamientoder=0;
              carrorect();
              crucestacionamiento=0;
              }
            }
    }
  }
  option= "";
              
       

}
void carroalante(){
motor.stop();
motor.forward();
}
void carroatras(){
motor.stop();
motor.backward();
}
void carroder(){
  motor.stop();
  servo.write(70);
  motor.forward();
}
void carroizq(){
  motor.stop();
  servo.write(110);
  motor.forward();
}
void carroesqder(){
  motor.stop();
  servo.write(115);
  motor.forward();
}
void carroesqizq(){
  motor.stop();
  servo.write(65);
  motor.forward();
}
void carrorect(){
  motor.stop();
  servo.write(90);
  motor.forward();
}
void stopcar(){
  motor.stop();
  delay(1000000);
}
void carrofin(){
  servo.write(90);
  motor.forward();
  delay(1000);
  motor.stop();
}
void serialEvent() {
  while (Serial.available()) {
    // Obtener bytes de entrada:
    char inChar = (char)Serial.read();
    // Agregar al String de entrada:
    option += inChar;
    // Para saber si el string está completo, se detendrá al recibir
    // el caracter de retorno de línea ENTER \n
    if (inChar == '\n') {
      break;
    }
  }
}