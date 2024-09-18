#include <Wire.h>
#include <Servo.h>
#include <L298N.h>
#include <NewPing.h>
#define IN2 10
#define IN1 11
#define IN3 6
#define IN4 3
#define I2C_DEVICE_ADDRESS 0x8
String entradaSerial = "";
String entradai2c="";
char te="";
int echo= 53;
int triger= 52;
int echo2=45;
int triger2=31;
int echo3=37;
int triger3=49;
int pulsador=40;
int maxd=450;
int atras=0;
int no=0;
int esq2=0;
int esqderatr=0;
int esquinadertrs=0;
int micaracuando=0;
int valorpulsador=0;
bool r1,r2,r3,r4,v1,v2,v3,v4;
int cruzconorojo,cruzconorojo2,cruzconorojo3,cruzconorojo4,cruzconoverde,cruzconoverde2,cruzconoverde3,cruzconoverde4;
int crucecono = 0;
bool cn=0;
#define EN 8
NewPing ultrasonidoade(triger,echo,maxd);
NewPing ultrasonidoder(triger3,echo3,maxd);
NewPing ultrasonidoizq(triger2,echo2,maxd);
L298N motor(EN, IN2, IN1);
Servo servo;
int esquina=0;
int xd=0;
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
int intervalocono = 900;
int intervalocono2 = 1100;
int intervalocono3= 500;
const int intervalopared=200;
unsigned long antespared=0;
unsigned long antesparedder=0;
unsigned long tiempoantesdelcont=0;
unsigned long tiempoantesdelcontder=0;
unsigned long valorantesconor = 0;
unsigned long valorantesconov = 0;
int intervalo=2000;
int intervaloder=1900;
int esquinatrs=0;
void setup() {
 Serial.begin(9600);
 Wire.begin(I2C_DEVICE_ADDRESS);
  Wire.onReceive(receiveMsg);
  servo.attach(7);
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
  pinMode(pulsador,INPUT_PULLUP);
  motor.setSpeed(120);
  motor.stop();
  servo.write(90);
}

void loop() {
 valorpulsador=digitalRead(pulsador);
   unsigned long cont = millis();
  float distanciaade = ultrasonidoade.ping_cm();
  float distanciaizq = ultrasonidoizq.ping_cm();
  float distanciader = ultrasonidoder.ping_cm();
 if(valorpulsador==LOW){
   micaracuando=1;
   xd=distanciaade;
 }
 if(micaracuando==1){
 if(lineas<12){
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    //  Serial.println(lineas);
    //  Serial.println(xd);
  /*Serial.print("sensor adelante: ");
  Serial.println(distanciaade);
  Serial.print("sensor derecha: ");
  Serial.println(distanciader);
  Serial.print("sensor izquierda: ");
  Serial.println(distanciaizq);
  Serial.print("contador");
  Serial.println(cont);*/
  if(motors==1){
    carrorect();
  }
if((distanciaizq>100&&distanciaizq<300&&der==0&&izq==0&&si==0&&no==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&distanciaade<50&&cruzconorojo4==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo==0&&cruzconoverde==0&&cruzconoverde2==0
  &&cruzconoverde3==0&&cruzconoverde==0)||esquina==1){
    //Serial.println("hola izq");
    if((cont-tiempoantesdelcont>intervalo)||esq==0){
      tiempoantesdelcont=cont;
      //Serial.print("esquina izq");
      if(esq==0&&esquinadertrs==0){
        intervalo=1000;
        esquina=1;
        si=1;
        no=1;
        esq=1;
        carroesqizq();
        motors=0;
        izq=1;
        //Serial.println("ala berga0");
      }
      else if(esq==1){
        intervalo=2000;
        esquina=1;
        si=1;
        no=1;
        esq=1;
        motor.stop();
        servo.write(50);
        motor.backward();
        motors=0;
        izq=1;
        //Serial.println("ala berga0");
      }
      else if(esq=2){
        intervalo=1000;
        esq=0;
        carrorect();
        esquina=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }
if((distanciaizq>100&&distanciaizq<300&&izq==1&&der==0&&si==0&&no==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&distanciaade<50&&cruzconorojo4==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo==0&&cruzconoverde==0&&cruzconoverde2==0
  &&cruzconoverde3==0&&cruzconoverde==0)||esquina==1){
   // Serial.println("hola izq");
    if((cont-tiempoantesdelcont>intervalo)||esq==0){
      tiempoantesdelcont=cont;
      //Serial.print("esquina izq");
      if(esq==0&&esquinadertrs==0){
        intervalo=1000;
        esquina=1;
        si=1;
        no=1;
        esq=1;
        carroesqizq();
        motors=0;
        izq=1;
        //Serial.println("ala berga0");
      }
      else if(esq==1){
        intervalo=2000;
        esquina=1;
        si=1;
        no=1;
        esq=1;
        motor.stop();
        servo.write(50);
        motor.backward();
        motors=0;
        izq=1;
        //Serial.println("ala berga0");
      }
      else if(esq==2){
        intervalo=1000;
        esq=0;
        carrorect();
        esquina=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }
 
if((distanciader>100&&distanciader<300&&esquinadertrs==0&&esquinatrs==0&&esquina==0&&distanciaade<50&&izq==0&&der==0&&si==0&&no==0&&cruzconorojo4==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo==0&&cruzconoverde==0&&cruzconoverde2==0
  &&cruzconoverde3==0&&cruzconoverde==0)||esquinader==1){
   // Serial.println("hola der");
    if((cont-tiempoantesdelcont>intervaloder)||esq==0){
      tiempoantesdelcont=cont;
    //  Serial.print("esquina der");
      if(esq==0&&esquinadertrs==0){
        intervaloder=1000;
        esquinader=1;
        si=1;
        esq=1;
        carroesqder();
        motors=0;
        der=1;
        no=1;
      }
       else if(esq==1){
        intervaloder=1500;
        esquinader=1;
        si=1;
        esq=2;
        motor.stop();
        servo.write(150);
        motor.backward();
        motors=0;
        der=1;
        no=1;
      }
      else if(esq==2){
        intervaloder=1000;
        esq=0;
        carrorect();
        esquinader=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }
if((distanciader>100&&distanciader<300&&esquinadertrs==0&&esquinatrs==0&&esquina==0&&distanciaade<50&&izq==0&&der==1&&si==0&&no==0)||esquinader==1){
   // Serial.println("hola der");
    if((cont-tiempoantesdelcont>intervaloder)||esq==0){
      tiempoantesdelcont=cont;
      //Serial.print("esquina der");
      if(esq==0&&esquinadertrs==0){
        intervaloder=1000;
        esquinader=1;
        si=1;
        esq=1;
        carroesqder();
        motors=0;
        der=1;
        no=1;
      }
      else if(esq==1){
        intervaloder=1500;
        esquinader=1;
        si=1;
        esq=2;
        motor.stop();
        servo.write(150);
        motor.backward();
        motors=0;
        der=1;
        no=1;
      }
      else if(esq==2){
        intervaloder=1000;
        esq=0;
        carrorect();
        esquinader=0;
        motors=1;
        lineas++;
        tiempoantesdelcont=0;
      }
    }
  }

   if((r1!=0&&cn==0)||cruzconorojo==1){
    if(cont-valorantesconor>intervalocono){
      valorantesconor=cont;
      if(crucecono==0){
        Serial.println("1");
        crucecono=1;
        cn=1;
        r1=0;
        cruzconorojo=1;
        cruzconor();
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("0");
        crucecono=0;
        cn=0;
        carrorect();
        cruzconorojo=0;
        motors=1;
        cn=0;
        valorantesconor=0;
        r1=0;
      }
    }
  }
  if((r2!=0&&cn==0)||cruzconorojo2==1){
    if(cont-valorantesconor>intervalocono){
      valorantesconor=cont;
      if(crucecono==0){
        Serial.println("1");
        r2=0;
        crucecono=1;
        cruzconorojo2=1;
        cruzconor();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("0");
        crucecono=0;
        cruzconorojo2=0;
        carrorect();
        motors=1;
        cn=0;
        valorantesconor=0;
        r2=0;
      }
    }
  }
    if((r3!=0&&cn==0)||cruzconorojo3==1){
    if(cont-valorantesconor>intervalocono2){
      valorantesconor=cont;
      if(crucecono==0){
        Serial.println("1");
        r3=0;
        crucecono=1;
        cruzconorojo3=1;
        cruzconor2();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("0");
        crucecono=0;
        cruzconorojo3=0;
        carrorect();
        motors=1;
        cn=0;
        valorantesconor=0;
        r3=0;
      }
    }
  }
    if((r4!=0&&cn==0)||cruzconorojo4==1){
    if(cont-valorantesconor>intervalocono){
      valorantesconor=cont;
      if(crucecono==0){
        Serial.println("1");
        r4=0;
        intervalocono3=400;
        crucecono=1;
        cruzconorojo4=1;
        carroatras();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
       // Serial.println("rojo4 b");
        intervalocono3=1200;
        
        crucecono=2;
        cruzconor();
        cn=1;
        motors=0;
      }
      else if(crucecono==2){
        Serial.println("0");
        intervalocono3=400;
        crucecono=0;
        cruzconorojo4=0;
        carrorect();
        motors=0;
        valorantesconor=0;
        cn=0;
        r4=0;
      }
    }
  }
  if((v1!=0&&cn==0)||cruzconoverde==1){
    if(cont-valorantesconov>intervalocono3){
      valorantesconov=cont;
      if(crucecono==0){
        Serial.println("1");
        v1=0;
        intervalocono3=400;
        crucecono=1;
        cruzconoverde=1;
        carroatras();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        //Serial.println("verde1 b");
        intervalocono3=1200;
        crucecono=2;
        cruzconoverde=1;
        cruzconov();
        cn=1;
        motors=0;
      }
      else if(crucecono==2){
        Serial.println("0");
        intervalocono3=400;
        crucecono=0;
        cruzconoverde=0;
        carrorect();
        motors=0;
        valorantesconov=0;
        cn=0;
        v1=0;
      }
    }
  }
  if((v2!=0&&cn==0)||cruzconoverde2==1){
    if(cont-valorantesconov>intervalocono2){
      valorantesconov=cont;
      if(crucecono==0){
        Serial.println("1");
        v2=0;
        crucecono=1;
        cruzconoverde2=1;
        cruzconov();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("0");
        crucecono=0;
        cruzconoverde2=0;
        carrorect();
        motors=0;
        valorantesconov=0;
        cn=0;
        v2=0;
      }
    }
  }
    if((v3!=0&&cn==0)||cruzconoverde3==1){
    if(cont-valorantesconov>intervalocono){
      valorantesconov=cont;
      if(crucecono==0){
        Serial.println("1");
        v3=0;
        crucecono=1;
        cruzconoverde3=1;
        cruzconov();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("0");
        crucecono=0;
        cruzconoverde3=0;
        carrorect();
        motors=0;
        valorantesconov=0;
        cn=0;
        v3=0;
      }
    }
  }
  if((v4!=0&&cn==0)||cruzconoverde4==1){
    if(cont-valorantesconov>intervalocono){
      valorantesconov=cont;
      if(crucecono==0){
        Serial.println("1");
        v4=0;
        crucecono=1;
        cruzconoverde4=1;
        cruzconov();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("0");
        crucecono=0;
        cruzconoverde4=0;
        carrorect();
        motors=0;
        valorantesconov=0;
        cn=0;
        v4=0;
      }
    }
  }
/*    if((rojo1!=0&&cn==0&&distanciader<35)||cruzconorojo==1){
    if(cont-valorantesconor>intervalocono2){
      valorantesconor=cont;
      if(crucecono==0){
        Serial.println("rojo1 a");
        crucecono=1;
        cn=1;
        rojo1=0;
        cruzconorojo=1;
        cruzconor();
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("rojo1 b");
        crucecono=0;
        cruzconorojo=0;
        carrorect();
        motors=1;
        cn=0;
        valorantesconor=0;
        rojo1=0;
      }
    }
  }
  if((rojo2!=0&&cn==0&&distanciader<35)||cruzconorojo2==1){
    if(cont-valorantesconor>intervalocono){
      valorantesconor=cont;
      if(crucecono==0){
        Serial.println("rojo2 a");
        rojo2=0;
        crucecono=1;
        cruzconorojo2=1;
        cruzconor2();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("rojo2 b");
        crucecono=0;
        cruzconorojo2=0;
        carrorect();
        motors=1;
        cn=0;
        valorantesconor=0;
        rojo2=0;
      }
    }
  }
  if((verde1!=0&&cn==0&&distanciader<35)||cruzconoverde==1){
    if(cont-valorantesconov>intervalocono2){
      valorantesconov=cont;
      if(crucecono==0){
        Serial.println("verde1 a");
        verde1=0;
        crucecono=1;
        cruzconoverde=1;
        cruzconov2();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("verde1 b");
        crucecono=0;
        cruzconoverde=0;
        carrorect();
        motors=0;
        valorantesconov=0;
        cn=0;
        verde1=0;
      }
    }
  }
  if((verde2!=0&&cn==0&&distanciader<35)||cruzconoverde2==1){
    if(cont-valorantesconov>intervalocono){
      valorantesconov=cont;
      if(crucecono==0){
        Serial.println("verde2 a");
        verde2=0;
        crucecono=1;
        cruzconoverde2=1;
        cruzconov();
        cn=1;
        motors=0;
      }
      else if(crucecono==1){
        Serial.println("verde2 b");
        crucecono=0;
        cruzconoverde2=0;
        carrorect();
        motors=0;
        valorantesconov=0;
        cn=0;
        verde2=0;
      }
    }
  }*/
  //centrar carro
  int centro=(distanciaizq+distanciader);
  if(centro<95&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
   if(distanciaade>100){
    si=0;
    no=0;
   }
    //separar pared izq
    
    if(((distanciaizq<40&&distanciaizq>0&&distanciaade>100)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0&&cruzconorojo==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo4==0&&cruzconoverde==0&&cruzconoverde2==0&&cruzconoverde3==0&&cruzconoverde==0)||paredizq==1){
    if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared2==0&&(esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)){
     // intervalopared=200;
      paredizq=1;
      pared2=1;
      centrarizq();
     // Serial.println("sep izq 1");
      motors=0;
    }
    else if(pared2==1){
    //  intervalopared=180;
      pared2=2;
      servo.write(100);
      //Serial.println("sep izq 2");
      motors=0;
    }
    else if(pared2==2){
      //intervalopared=200;
      paredizq=0;
      pared2=0;
      carrorect();
      motors=1;
      antespared=0;
     // Serial.println("sep izq 3");
    }
  }
 }
    
    if(((distanciader<40&&distanciader>0&&distanciaade>100)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0&&cruzconorojo==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo4==0&&cruzconoverde==0&&cruzconoverde2==0&&cruzconoverde3==0&&cruzconoverde==0)||paredder==1){
    if((cont-antesparedder)>intervalopared){
     // Serial.println("separacion der");
      antesparedder=cont;
      if(pareder2==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
      //  intervalopared=200;
        //Serial.println("sep der 1");
        paredder=1;
        pareder2=1;
        centrarder();
        motors=0;
      }
      else if(pareder2==1){
      //  intervalopared=180;
       //  Serial.println("sep der 2");
        pareder2=2;
        servo.write(80);
        motors=0;
      }
      else if(pareder2==2){
        //intervalopared=200;
       // Serial.println("sep der 3");
        paredder=0;
        pareder2=0;
        carrorect();
        motors=1;
      }
    }
  }
    }
  }
  
 else{
  //Serial.println("no se chamo");
  if(distanciaade<xd){
  stopcar();
  }
  else{
  if(((distanciaizq<40&&distanciaizq>0&&distanciaade>100)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0&&cruzconorojo==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo4==0&&cruzconoverde==0&&cruzconoverde2==0&&cruzconoverde3==0&&cruzconoverde==0)||paredizq==1){
    if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared2==0&&(esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)){
     // intervalopared=200;
      paredizq=1;
      pared2=1;
      centrarizq();
     // Serial.println("sep izq 1");
      motors=0;
    }
    else if(pared2==1){
    //  intervalopared=180;
      pared2=2;
      servo.write(100);
      //Serial.println("sep izq 2");
      motors=0;
    }
    else if(pared2==2){
      //intervalopared=200;
      paredizq=0;
      pared2=0;
      carrorect();
      motors=1;
      antespared=0;
     // Serial.println("sep izq 3");
    }
  }
 }
    
    if(((distanciader<40&&distanciader>0&&distanciaade>100)&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0&&cruzconorojo==0&&cruzconorojo2==0&&cruzconorojo3==0&&cruzconorojo4==0&&cruzconoverde==0&&cruzconoverde2==0&&cruzconoverde3==0&&cruzconoverde==0)||paredder==1){
    if((cont-antesparedder)>intervalopared){
     // Serial.println("separacion der");
      antesparedder=cont;
      if(pareder2==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
      //  intervalopared=200;
        //Serial.println("sep der 1");
        paredder=1;
        pareder2=1;
        centrarder();
        motors=0;
      }
      else if(pareder2==1){
      //  intervalopared=180;
       //  Serial.println("sep der 2");
        pareder2=2;
        servo.write(80);
        motors=0;
      }
      else if(pareder2==2){
        //intervalopared=200;
       // Serial.println("sep der 3");
        paredder=0;
        pareder2=0;
        carrorect();
        motors=1;
      }
    }
  }
  }
 }
}
}

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
void cruzconor(){
  motor.stop();
  servo.write(55);
  motor.forward();
}
void cruzconov (){
  motor.stop();
  servo.write(120);
  motor.forward();
}
void cruzconor2(){
  motor.stop();
  servo.write(25);
  motor.forward();
}
void cruzconov2 (){
  motor.stop();
  servo.write(140);
  motor.forward();
}
void carrorect() {
  motor.stop();
  servo.write(85);
  motor.forward();
}
void stopcar() {
  motor.stop();
  delay(1000000);
}
/*void serialEvent() {
  while (Serial.available()) {
    // Obtener bytes de entrada:
    char inChar = (char)Serial.read();
    // Agregar al String de entrada:
    entradaSerial += inChar;
    // Para saber si el string est� completo, se detendr� al recibir
    // el caracter de retorno de l�nea ENTER \n
    if (inChar == '\n') {
     //if(cn==0){
     if(entradaSerial=="rojo1\n"){
      rojo1=1;
      entradaSerial="";
     // Serial.println("r1");
     }
      else if(entradaSerial=="rojo2\n"){
      rojo2=1;
      entradaSerial="";
    //  Serial.println("r2");
     }
     else if(entradaSerial=="rojo3\n"){
      rojo3=1;
      entradaSerial="";
    //  Serial.println("r3");
     }
     else if(entradaSerial=="rojo4\n"){
      rojo4=1;
      entradaSerial="";
   //   Serial.println("r4");
     }
      else if(entradaSerial=="verde1\n"){
      verde1=1;
      entradaSerial="";
  //    Serial.println("v1");
     }
     else if(entradaSerial=="verde2\n"){
      verde2=1;
      entradaSerial="";
 //     Serial.println("v2");
     }
     else if(entradaSerial=="verde3\n"){
      verde3=1;
      entradaSerial="";
    //  Serial.println("v3");
     }
     else if(entradaSerial=="verde4\n"){
      verde4=1;
      entradaSerial="";
    //  Serial.println("v4");
     }
     }
    //}
  }
}*/
void receiveMsg() {
  if (Wire.available()) {
    char c = Wire.read();
    if(c!=te&&entradai2c.length()<=2){
     // Serial.println("e");
    te=c;
    entradai2c+=c;
    
    }
    
    //Serial.println("si");
    
      //Serial.println("ee");
     if(entradai2c=="r1"){
      r1=1;
      
      entradai2c="";
      c="";
      
      Serial.println("rojo1");
     }
      else if(entradai2c=="r2"){
      r2=1;
      entradai2c="";
      c="";
      
      Serial.println("rojo2");
     }
     else if(entradai2c=="r3"){
      r3=1;
      entradai2c="";
      c="";
      
      Serial.println("rojo3");
     }
     else if(entradai2c=="r4"){
      r4=1;
      entradai2c="";
      c="";
      
      Serial.println("rojo4");
     }
      else if(entradai2c=="v1"){
      v1=1;
      entradai2c="";
      c="";
    
      Serial.println("verde1");
     }
     else if(entradai2c=="v2"){
      v2=1;
      entradai2c="";
      c="";
      Serial.println("verde2");
     }
     else if(entradai2c=="v3"){
      v3=1;
      entradai2c="";
      c="";
      Serial.println("v3");
     }
     else if(entradai2c=="v4"){
      v4=1;
      entradai2c="";
      c="";
      Serial.println("verde4");
     }
     else {
      if(entradai2c.length()>=2){
        entradai2c="";
      }
     }
    
    ///Serial.print(entradai2c);
    //entradai2c="";
  }
}
void sendMesage(char hola){
  Wire.write(hola);
}
