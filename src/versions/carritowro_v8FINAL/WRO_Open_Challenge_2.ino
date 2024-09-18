//Inclusion of Libraries
#include <Servo.h>
#include <L298N.h>
#include <NewPing.h>
//Variable declaration
int IN2= 10;
int IN1= 11;
int IN3= 6;
int IN4= 3;
int EN= 8;
int echo= 53;
int triger= 52;
int echo2=45;
int triger2=31;
int echo3=37;
int triger3=49;
int buzz=11;
int maxd=450;
int atras=0;
int no=0;
int esq2=0;
int esqderatr=0;
int esquinadertrs=0;
int esquina=0;
int esq=0;
int motors=1;
int lineas=0;
bool pared=0;
int paredizq=0;
int paredizqpeg=0;
int paredizqalt=0;
int paredder=0;
int paredderpeg=0;
int paredderalt=0;
bool pareder=0;
int esquinader=0;
int pareder2=0;
int pared2=0;
int izq=0;
int der=0;
int si=0;
const int intervalopared=200;
unsigned long antespared=0;
unsigned long antesparedder=0;
unsigned long tiempoantesdelcont=0;
unsigned long tiempoantesdelcontder=0;
const  int intervalo=2000;
const int intervaloatr=1850;
const int intervaloder=1900;
const int intervaloderatr=1800;
int esquinatrs=0;
//Motors and ultrasonic declaration
Servo servo;
NewPing ultrasonidoade(triger,echo,maxd);
NewPing ultrasonidoder(triger3,echo3,maxd);
NewPing ultrasonidoizq(triger2,echo2,maxd);
L298N motor(EN, IN2, IN1);

void setup() {
  //Serial monitor startup
  Serial.begin(9600);
  //Servo pin assignment
  servo.attach(7);
  //Definition of input and output pins
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(triger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(triger2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(triger3, OUTPUT);
  pinMode(echo3, INPUT);
  pinMode(buzz,OUTPUT);
  //Definition of motor speed
  motor.setSpeed(120);
  motor.stop();
  servo.write(90);
  
}

void loop() {
  //Loop start
  if(lineas<12){
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  //Assignment of variable values
  unsigned long cont = millis();
  float distanciaade = ultrasonidoade.ping_cm();
  float distanciaizq = ultrasonidoizq.ping_cm();
  float distanciader = ultrasonidoder.ping_cm();

  }
  if(motors==1){
    carrorect();
  }
//Corner crossing conditions
if((distanciaizq>100&&distanciaizq<300&&der==0&&izq==0&&si==0&&no==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&distanciaade>50&&distanciaade<80)||esquina==1){
    if((cont-tiempoantesdelcont>intervalo)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0&&esquinadertrs==0){
        esquina=1;
        si=1;
        no=1;
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
if((distanciaizq>100&&distanciaizq<300&&izq==1&&der==0&&si==0&&no==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&distanciaade>50&&distanciaade<80)||esquina==1){
    if((cont-tiempoantesdelcont>intervalo)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0&&esquinadertrs==0){
        esquina=1;
        si=1;
        no=1;
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
if((distanciaizq>=100&&distanciaizq<=300&&esquinadertrs==0&&esquinader==0&&esquina==0&&izq==0&&der==0&&si==0&&no==0&&distanciaade<=50)||esquinatrs==1){
    if((cont-tiempoantesdelcont>intervaloatr)||esq2==0){
      tiempoantesdelcont=cont;
      if(esq2==0&&esquinadertrs==0){
        esquinatrs=1;
        si=1;
        esq2=1;
        carroesqizq2();
        motors=0;
        izq=1;
        no=1;
      }
      else if(esq2==1&&esquinadertrs==0){
        esq2=0;
        carrorect();
        esquinatrs=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  } 
if((distanciaizq>=100&&distanciaizq<=300&&esquinadertrs==0&&esquinader==0&&esquina==0&&izq==1&&der==0&&si==0&&no==0&&distanciaade<=50)||esquinatrs==1){
    if((cont-tiempoantesdelcont>intervaloatr)||esq2==0){
      tiempoantesdelcont=cont;
      if(esq2==0&&esquinadertrs==0){
        esquinatrs=1;
        si=1;
        esq2=1;
        carroesqizq2();
        motors=0;
        izq=1;
        no=1;
      }
      else if(esq2==1&&esquinadertrs==0){
        esq2=0;
        carrorect();
        esquinatrs=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  } 
if((distanciader>100&&distanciader<300&&esquinadertrs==0&&esquinatrs==0&&esquina==0&&distanciaade>50&&distanciaade<80&&izq==0&&der==0&&si==0&&no==0)||esquinader==1){
    if((cont-tiempoantesdelcont>intervaloder)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0&&esquinadertrs==0){
        esquinader=1;
        si=1;
        esq=1;
        carroesqder();
        motors=0;
        der=1;
        no=1;
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
if((distanciader>100&&distanciader<300&&esquinadertrs==0&&esquinatrs==0&&esquina==0&&distanciaade>50&&distanciaade<80&&izq==0&&der==1&&si==0&&no==0)||esquinader==1){
    if((cont-tiempoantesdelcont>intervaloder)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0&&esquinadertrs==0){
        esquinader=1;
        si=1;
        esq=1;
        carroesqder();
        motors=0;
        der=1;
        no=1;
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
if((distanciader>100&&distanciader<300&&esquinader==0&&esquinatrs==0&&esquina==0&&izq==0&&der==0&&si==0&&no==0&&distanciaade<=50)||esquinadertrs==1){
    if((cont-tiempoantesdelcontder>intervaloderatr)||esqderatr==0){
      tiempoantesdelcontder=cont;
      if(esqderatr==0){
        esquinadertrs=1;
        si=1;
        esqderatr=1;
        carroesqder2();
        motors=0;
        der=1;
        no=1;
      }
      else if(esqderatr==1){
        esqderatr=0;
        carrorect();
        esquinadertrs=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }
if((distanciader>100&&distanciader<300&&esquinader==0&&esquinatrs==0&&esquina==0&&izq==0&&der==1&&si==0&&no==0&&distanciaade<=65)||esquinadertrs==1){
    if((cont-tiempoantesdelcontder>intervaloderatr)||esqderatr==0){
      tiempoantesdelcontder=cont;
      if(esqderatr==0){
        esquinadertrs=1;
        si=1;
        esqderatr=1;
        carroesqder2();
        motors=0;
        der=1;
        no=1;
      }
      else if(esqderatr==2){
        esqderatr=0;
        carrorect();
        esquinadertrs=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }
  
  //Center car
  int centro=(distanciaizq+distanciader);
  if(centro<95&&centro>55&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
   if(distanciaade>100){
    si=0;
    no=0;
   }
   
    //Separating left wall
    if(((distanciaizq<40&&distanciaizq>0&&distanciaade>45)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)||paredizq==1){
    if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared2==0&&(esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)){
      paredizq=1;
      pared2=1;
      centrarizq();
      motors=0;
    }
    else if(pared2==1){
      pared2=2;
      servo.write(100);
      motors=0;
    }
    else if(pared2==2){
      paredizq=0;
      pared2=0;
      carrorect();
      motors=1;
      antespared=0;
    }
  }
 }
    
    if(((distanciader<40&&distanciader>0&&distanciaade>45)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)||paredder==1){
    if((cont-antesparedder)>intervalopared){
      antesparedder=cont;
      if(pareder2==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
        paredder=1;
        pareder2=1;
        centrarder();
        motors=0;
      }
      else if(pareder2==1){
        pareder2=2;
        servo.write(80);
        motors=0;
      }
      else if(pareder2==2){
        paredder=0;
        pareder2=0;
        carrorect();
        motors=1;
      }
    }
  }
    }

  if(centro<55&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
    si=0;
    no=0;
    if(((distanciaizq<20&&distanciaizq>0&&distanciaade>45)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)||paredizqalt==1){
  if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
      paredizqalt=1;
      pared=1;
      centrarizq();
      motors=0;
    }

    else if(pared==1){
      paredizqalt=0;
      pared=0;
      carrorect();
      antesparedder=cont;
      motors=1;
  }
 }
    }
    
  if(((distanciader<20&&distanciader>0&&distanciaade>45)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)||paredderalt==1){
  if(cont-antespared>intervalopared){
    antespared=cont;
    if(pareder==0&&(esquinadertrs==0||esquinader==0||esquinatrs==0||esquina==0)){
      paredderalt=1;
      pareder=1;
      centrarder();
      motors=0;
    }
  
    else if(pareder==1){
      paredderalt=0;
      pareder=0;
      carrorect();
      antespared=0;
      motors=1;
    }
  }
 }
    }
  }
  
 else{
  stopcar();
 }
}

//Function creation
void carroalante() {
  motor.stop();
  motor.forward();
}
void carroatras() {
  motor.stop();
  motor.backward();
}
void carropeqizq() {
  motor.stop();
  servo.write(120);
  motor.forward();
}
void carropeqder() {
  motor.stop();
  servo.write(60);
  motor.forward();
}
void carromedder() {
  motor.stop();
  servo.write(135);
  motor.forward();
}
void carromedizq() {
  motor.stop();
  servo.write(35);
  motor.forward();
}
void centrarizq(){
  motor.stop();
  servo.write(55);
  motor.forward();
}
void centrarder(){
  motor.stop();
  servo.write(120);
  motor.forward();
}
void carroesqder() {
  motor.stop();
  servo.write(30);
  motor.forward();
}
void carroesqder2() {
  motor.stop();
  servo.write(15);
  motor.forward();
}
void carroesqizq() {
  motor.stop();
  servo.write(145);
  motor.forward();
}
void carroesqizq2() {
  motor.stop();
  servo.write(150);
  motor.forward();
}
void carrorect() {
  motor.stop();
  servo.write(85);
  motor.forward();
}
void stopcar() {
  motor.forward();
  servo.write(85);
  delay(1600);
  motor.stop();
  delay(1000000);
}
