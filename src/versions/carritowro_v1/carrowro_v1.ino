#include  <Servo.h>
#include <math.h> 
String option="";
Servo servo;
bool entradaCompleta=false;
int botoni=0;
#define pulsador 12
#define IN4 6
#define IN3  7    
#define echo 2
#define triger 3
#define echo2 52
#define triger2 53
#define echo3 32
#define triger3 33
int ronda=0;
int vuelta=0;
int redMin = 56; // Red minimum value
int redMax = 211; // Red maximum value
int greenMin = 56; // Green minimum value
int greenMax = 225; // Green maximum value
int blueMin = 48; // Blue minimum value
int blueMax = 201; // Blue maximum value
int redPW = 0;
int greenPW = 0;
int bluePW = 0;
int redValue;
int greenValue;
int blueValue;
int lineas=0;
byte sentido=0;
const float vel=21.35;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo.attach(9);
pinMode(IN4,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(triger,OUTPUT);
pinMode(echo,INPUT);
pinMode(triger2,OUTPUT);
pinMode(echo2,INPUT);
pinMode(triger3,OUTPUT);
pinMode(echo3,INPUT); 
pinMode(pulsador,INPUT); 
}

void loop() {
int valorp=digitalRead(pulsador);
if(valorp==HIGH&&botoni==0){
  botoni++;
  Serial.println("si funciona");
}
if(botoni==1){
  digitalWrite(IN4,HIGH);
  float distancia=calculard();
  float distancia2=calculard2();
  float distancia3=calculard3();
  servo.write(90);

  Serial.println(distancia);
  Serial.println("");
  Serial.println(distancia2);
  Serial.println("");
  Serial.println(distancia3);


  if(distancia<20.0){
   if(option=="rojo\n"){
    ronda=1;
      servo.write(115);
      digitalWrite(IN4,HIGH);
      delay(1500);
  /*    digitalWrite(IN4,LOW);
      servo.write(65);
      delay(250);
      digitalWrite(IN4,HIGH);
      delay(1500);
      digitalWrite(IN4,LOW);
      servo.write(90);
      digitalWrite(IN3,HIGH);
      delay(1500);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);*/
        option= "";
 /*     if(lineas==7){
          vuelta==1;
      }*/
      
      }     
     
     

     else if(option=="verde\n"){
      ronda=1;
      servo.write(65);
      digitalWrite(IN4,HIGH);
      delay(1500);
      /*digitalWrite(IN4,LOW);
      delay(250);
      servo.write(115);
      digitalWrite(IN4,HIGH);
      delay(1500);
      digitalWrite(IN4,LOW);
      servo.write(90);
      digitalWrite(IN3,HIGH);
      delay(1000);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);*/
        option= "";
      /*if(lineas==7){
        vuelta=2;
      } */
      }
     else if(option=="morado\n"){
      ronda=2;
      if(lineas==12&&ronda==1){
        if (option == "izq\n") {
          Serial.print("0 grados\n");
      // Mandamos escribir el angulo deseado del giro.
        servo.write(130);
          }

      else if (option == "ctr\n") {
        Serial.print("60 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo.write(90);
    }
    else if (option == "der\n") {
      Serial.print("Centro 90 grados\n");
      // Mandamos escribir el angulo deseado del giro.
      servo.write(50);
    }
        }
      option= "";
         }   
     else {
      Serial.println("sensor alfrente");
      if(sentido==1){
     digitalWrite(IN4,LOW);
     digitalWrite(IN3,HIGH);  
     delay(1000);  
     digitalWrite(IN3,LOW);
     delay(100);
     servo.write(60); 
     digitalWrite(IN4,HIGH);
     delay(1000); 
     servo.write(90);
      }
      else if(sentido==2){
      digitalWrite(IN4,LOW);
     digitalWrite(IN3,HIGH);  
     delay(1000);  
     digitalWrite(IN3,LOW);
     delay(100);
     servo.write(120); 
     digitalWrite(IN4,HIGH); 
     delay(1000);
     servo.write(90);
      }
     }
 }   
  option= "";

   if(distancia2>110&&sentido==0){
    delay(1000);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    servo.write(115);
    delay(2500);
    servo.write(90);
    sentido=1;
    lineas++;
  }
   else if(distancia3>110&&sentido==0){
    delay(1000);
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    servo.write(65);
    delay(2500);
    servo.write(90);
    sentido=2;
    lineas++;
  }
     if(distancia2>110&&sentido==1){
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    servo.write(115);
    delay(2500);
    servo.write(90);
    lineas++;
  }
   else if(distancia3>110&&sentido==2){
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    servo.write(65);
    delay(2500);
    servo.write(90);
    lineas++;
  }
   else if(distancia2>100&&lineas==12){
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    servo.write(115);
    delay(2000);
    servo.write(90);
    delay(2500);
    digitalWrite(IN4,LOW);
    }
  
   else if(distancia3>100&&lineas==12){
    digitalWrite(IN4,LOW);
    digitalWrite(IN3,HIGH);
    delay(1000);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    servo.write(65);
    delay(2000);
    servo.write(90);
    delay(2500);
    digitalWrite(IN4,LOW);
  }
  if(distancia2<15){
    Serial.println("gire pared");
    servo.write(120);
    delay(1000);
    servo.write(90);
  }
  if(distancia3<15){
    Serial.println("gire otra pared");
    servo.write(60);
    //Serial.println(angulo);
    delay(1000);
    servo.write(90);
  }
  /*if(distancia2<7){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    delay(1000);
     digitalWrite(IN1,LOW);
    servo.write(110);
    digitalWrite(IN2,HIGH);
    delay(1000);
    servo.write(90);    
  }
    if(distancia3<7){
    digitalWrite(IN2,LOW);
    digitalWrite(IN1,HIGH);
    delay(1000);
    servo.write(60);
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    delay(1000);
    servo.write(90);    
  }*/
  
digitalWrite(IN4,HIGH);
}
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
//funcion de calcular distancia
float calculard(){
 digitalWrite(triger,LOW); 
  delay(2);
  digitalWrite(triger,HIGH); 
  delay(10);
  digitalWrite(triger,LOW); 
 float tiempo=pulseIn(echo,HIGH);
 float distancia=tiempo*0.000001*34300.0/2.0;
  return distancia;
}
float calculard2(){
 digitalWrite(triger2,LOW); 
  delay(2);
  digitalWrite(triger2,HIGH); 
  delay(10);
  digitalWrite(triger2,LOW); 
 float tiempo=pulseIn(echo2,HIGH);
 float distancia=tiempo*0.000001*34300.0/2.0;
  return distancia;
  
}
float calculard3(){
 digitalWrite(triger3,LOW); 
  delay(2);
  digitalWrite(triger3,HIGH); 
  delay(10);
  digitalWrite(triger3,LOW); 
 float tiempo=pulseIn(echo3,HIGH);
 float distancia=tiempo*0.000001*34300.0/2.0;
  return distancia;
}
