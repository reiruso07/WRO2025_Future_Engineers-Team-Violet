#include  <Servo.h>
#include <math.h> 
String option="";
Servo servo;
bool entradaCompleta=false;
int botoni=0;
#define pulsador 12
#define IN2 10
#define IN1  11     
#define echo 2
#define triger 3
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
#define echo2 32
#define triger2 33
#define echo3 30
#define triger3 31
int ronda=0;
int vuelta=0;
int redMin = 20; // Red minimum value
int redMax = 177; // Red maximum value
int greenMin = 23; // Green minimum value
int greenMax = 217; // Green maximum value
int blueMin = 20; // Blue minimum value
int blueMax = 190; // Blue maximum value
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
pinMode(IN2,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(triger,OUTPUT);
pinMode(echo,INPUT);
pinMode(S0, OUTPUT);
pinMode(S1, OUTPUT);
pinMode(S2, OUTPUT);
pinMode(S3, OUTPUT);
pinMode(sensorOut, INPUT);
digitalWrite(S0,HIGH);
digitalWrite(S1,LOW);
pinMode(triger2,OUTPUT);
pinMode(echo2,INPUT);
pinMode(triger3,OUTPUT);
pinMode(echo3,INPUT); 
pinMode(pulsador,INPUT); 
}

void loop() {
int valorp=digitalRead(pulsador);
if(valorp==HIGH){
  botoni++;
  Serial.println("si funciona");
}
if(botoni==1){
  digitalWrite(IN2,HIGH);
  float distancia=calculard();
  float distancia2=calculard2();
  float distancia3=calculard3();
  servo.write(95);

  Serial.println(distancia);
  Serial.println("");
  Serial.println(distancia2);
  Serial.println("");
  Serial.println(distancia3);
  int redv=getRedPW();
  int greenv=getGreenPW();
  int bluev=getBluePW();


  if(distancia<20.0){
    digitalWrite(IN2,LOW);
   if(option=="rojo\n"){
    ronda=1;
      float hipotenusa=sqrt(pow((distancia3-20),2)+pow(13,2));
      float ang=acos(hipotenusa/(distancia3-20));
      float tiempo=(hipotenusa/vel)*1000;
      int angulo =90+ang;
      servo.write(angulo);
      digitalWrite(IN2,HIGH);
      delay(tiempo);
      digitalWrite(IN2,LOW);
      angulo=90-ang;
      digitalWrite(IN2,HIGH);
      delay(tiempo);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      delay(1500);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH); 
      if(lineas==7){
          vuelta==1;
      }
      else{
        digitalWrite(IN2,LOW);
        if(sentido==1){
          digitalWrite(IN1,HIGH);
          delay(2000);
          digitalWrite(IN1,LOW);
          servo.write(60);
          digitalWrite(IN2,HIGH);
          delay(3000);
          servo.write(95);
        }
        if(sentido==2){
          digitalWrite(IN1,HIGH);
          delay(2000);
          digitalWrite(IN1,LOW);
          servo.write(110);
          digitalWrite(IN2,HIGH);
          delay(3000);
          servo.write(95);
        }
      }     
     }
     

     if(option=="verde\n"){
      ronda=1;
      float hipotenusa=sqrt(pow((distancia2-20),2)+pow(13,2));
      float ang=acos(hipotenusa/(distancia2-20));
      float tiempo=(hipotenusa/vel)*1000;
      int angulo =90-ang;
      servo.write(angulo);
      digitalWrite(IN2,HIGH);
      delay(tiempo);
      digitalWrite(IN2,LOW);
      angulo=90+ang;
      digitalWrite(IN2,HIGH);
      delay(tiempo);
      digitalWrite(IN2,LOW);
      digitalWrite(IN1,HIGH);
      delay(1500);
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      if(lineas==7){
        vuelta=2;
      } 
      }
     if(option=="morado\n"){
      ronda=2;
      if(lineas==12&&ronda==1){
          if(sentido==1){
            float hipotenusa=sqrt(pow(distancia2,2)+pow(12.75,2));
            float ang=acos(hipotenusa/distancia2);
            float tiempo=(hipotenusa/vel)*1000;
            int angulo =90-ang;
            servo.write(angulo);
            delay(tiempo);
          }
          if(sentido==2){
            float hipotenusa=sqrt(pow(distancia3,2)+pow(12.75,2));
            float ang=acos(hipotenusa/distancia3);
            float tiempo=(hipotenusa/vel)*1000;
            int angulo=90+ang;
            servo.write(angulo);
            delay(tiempo);
          }
        }
     }   
 }   

  option= "";
  Serial.print("Red = ");
  Serial.print(redv);
  Serial.print(" - Green = ");
  Serial.print(greenv);
  Serial.print(" - Blue = ");
  Serial.println(bluev);
  if(redv>=240&&redv<=250&&redv>greenv&&redv>bluev&&sentido==0){
    sentido=1;
      servo.write(120);
      delay(2000);
      servo.write(90);
      lineas++;
  }
    if(bluev>=189&&bluev<=204&&bluev>redv&&bluev>greenv&&sentido==0){
    sentido=2;
    servo.write(60);
    delay(2000);
    servo.write(90);
    lineas++;
  }
    if(redv>=240&&redv<=250&&redv>greenv&&redv>bluev&&sentido==1&&lineas<12){
    servo.write(120);
    delay(3000);
    servo.write(90);
    lineas++;
  }
    if(bluev>=189&&bluev<=204&&bluev>redv&&bluev>greenv&&sentido==2&&lineas<12){
      digitalWrite(IN2,LOW);
      servo.write(110);
      digitalWrite(IN2,HIGH);
      delay(2000);
      digitalWrite(IN2,LOW);
      servo.write(60);
      digitalWrite(IN1,HIGH);
      delay(2000);
      digitalWrite(IN1,LOW);
      servo.write(110);
      digitalWrite(IN2,HIGH);
      delay(2000);
      digitalWrite(IN2,LOW);
      servo.write(90);
      digitalWrite(IN2,HIGH);
      sentido=1;
     lineas++;   
  }
  if(redv>=240&&redv<=260&&redv>greenv&&redv>bluev&&sentido==1&&lineas==7&&ronda==1){
      digitalWrite(IN2,LOW);
      servo.write(60);
      digitalWrite(IN2,HIGH);
      delay(2000);
      digitalWrite(IN2,LOW);
      servo.write(110);
      digitalWrite(IN1,HIGH);
      delay(2000);
      digitalWrite(IN1,LOW);
      servo.write(60);
      digitalWrite(IN2,HIGH);
      delay(2000);
      digitalWrite(IN2,LOW);
      servo.write(90);
      digitalWrite(IN2,HIGH);
      sentido=2;
     lineas++;  
  }
    if(bluev>=189&&bluev<=204&&bluev>redv&&bluev>greenv&&sentido==2&&lineas==7&&ronda==1){
    servo.write(60);
     delay(3000);
     servo.write(90);
     delay(2000);
    digitalWrite(IN2,LOW);
    delay(300000);   
  }
   if(redv>=240&&redv<=260&&redv>greenv&&redv>bluev&&sentido==1&&lineas==12&&ronda==0){
    servo.write(120);
    delay(3000);
    servo.write(90);
    delay(2000);
    digitalWrite(IN2,LOW);
    delay(300000);
  }
    if(bluev>=189&&bluev<=204&&bluev>redv&&bluev>greenv&&sentido==2&&lineas==12&&ronda==0){
    servo.write(60);
     delay(3000);
     servo.write(90);
     delay(2000);
    digitalWrite(IN2,LOW);
    delay(300000);   
  }
  if(distancia2<35){
    Serial.println("gire pared");
   /* float cata=distancia2;
    float hipotenusa=sqrt(pow(cata,2)+pow(12.75,2));
    float ang=acos(hipotenusa/cata);
    float tiempo=(hipotenusa/vel)*1000;
    int angulo=90+ang;
    servo.write(angulo);
    Serial.print("Este es el angulo:");
    Serial.println(ang);
    Serial.println("");*/
    servo.write(60);
    delay(1000);
    servo.write(90);
  }
  if(distancia3<35){
    /*Serial.println("gire otra pared");
    float cata=distancia3;
    float hipotenusa=sqrt(pow(cata,2)+pow(12.75,2));
    float ang=acos(hipotenusa/cata);
    float tiempo=(hipotenusa/vel)*100;
    int angulo=90-ang;*/
    servo.write(110);
    //Serial.println(angulo);
    delay(1000);
    servo.write(90);
  }
  
digitalWrite(IN2,HIGH);
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
int getRedPW() {
 
  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
    redPW = PW;
  // Map to value from 0-255
  redValue = map(redPW, redMin,redMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  return redValue;
 
}
 
// Function to read Green Pulse Widths 
int getGreenPW() {
 
  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
    
  // Read Green value
  greenPW = PW;
  // Map to value from 0-255
  greenValue = map(greenPW, greenMin,greenMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  return greenValue;
 
}
 
// Function to read Blue Pulse Widths
int getBluePW() {
 
  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
   // Read Blue value
  bluePW = PW;
  // Map to value from 0-255
  blueValue = map(bluePW, blueMin,blueMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  return blueValue;
 
}