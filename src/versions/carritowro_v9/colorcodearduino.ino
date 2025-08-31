//Inclusion of Libraries
#include <Wire.h>
#include <Servo.h>
#include <L298N.h>
#include <NewPing.h>
//Variable declaration
#define IN2 10
#define IN1 11
#define IN3 6
#define IN4 3
#define I2C_DEVICE_ADDRESS 0x8
#define EN 8
String entradai2c="";
char te="";
int echo= 45;
int triger= 44;
int echo2=25;
int triger2=24;
int echo3=31;
int triger3=30;
int echo4=37;
int triger4=36;
int pulsador=40;
int maxd=450;
int atras=0;
int no=0;
int esq2=0,esq3=0;
int esqderatr=0;
int esquinadertrs=0;
int valorpulsador=0;
int esquinaderalt=0;
bool ra1,ra2,rm1,rm2,rm3,rm4,rm5,rm6,rm7,rm8,rm9,ra3,ra4,ra5,ra6,ra7,ra8,ra9,va1,va2,vm1,vm2,vm3,vm4,vm5,vm6,vm7,vm8,vm9,va3,va4,va5,va6,va7,va8,va9,rd1,rd2,rd3,rd4,rd5,rd6,rd7,rd8,rd9,vd1,vd2,vd3,vd4,vd5,vd6,vd7,vd8,vd9;
bool noconos,conorojoder,cnr,cnv;
int distanciaatr,distanciapasada;
int ciclo=0,vgn;
float distanciaade,distanciaizq,distanciader;
int cruzconorojo,cruzconorojoizq=0,cruzconorojoizq2=0,cruzconorojoizq3=0,cruzconorojonc=0,cruzconorojo2,cruzconoverde,cruzconoverde2=0,cuzconoverde3=0,cruzconoverdeizq,cruzconoverdeizq2=0,cuzconoverdeizq3=0;
int crucecono = 0,cruceconor2 = 0,cruceconocent=0,cruceconov=0,cruceconov2,cruceconovnc;
int esq=0;
int motors=1;
bool cnrojo=0,cnverde=0,rc=0,vc=0;
int lineas=0;
bool pared=0;
int paredizq=0;
int paredizqpeg=0;
int paredizqalt=0;
int paredder=0;
int paredderpeg=0;
int esquina=0,esquina2=0;
int esquinader=0,esquinader2=0,esquinader3=0;
bool esquinaderv=0,esquinaizqv=0;
bool esquinaizqr=0;
int pareder2=0;
int pared2=0;
int izq=0;
int der=0;
int esqc=0;
int si=0;
bool conorfin=0,conorcont=0,conovfin=0,conovcont=0,nc=0;
bool conorp=0,conovp=0,nconos;
int intervalocono = 1000,intervaloconov=1000;
int intervalodespuescono=1000;
const int intervalopared=200;
unsigned long cont;
unsigned long antespared=0;
unsigned long antesparedder=0;
unsigned long tiempoantesdelcont=0;
unsigned long tiempoantesdelcontder=0;
unsigned long valorantesconor = 0;
unsigned long valorantesconov = 0;
unsigned long valordespuesconor=0;
unsigned long valordespuesconov=0;
unsigned long contfincono=0,contfinconov=0;
unsigned long contnoconos=0;
int intervalo=2000;
int intervaloder=2200;
int esquinatrs=0;
//Motors and ultrasonics declaration
NewPing ultrasonidoade(triger,echo,maxd);
NewPing ultrasonidoder(triger3,echo3,maxd);
NewPing ultrasonidoizq(triger2,echo2,maxd);
NewPing ultrasonidoatr(triger4,echo4,maxd);
L298N motor(EN, IN2, IN1);
Servo servo;
void setup() {
  //Serial Monitor startup
  Serial.begin(115200);
  //I2c direction assignment
  Wire.begin(I2C_DEVICE_ADDRESS);
  Wire.onReceive(recibirm);
  Wire.onRequest(enviarM);
  //Servo pin assignment 
  servo.attach(39);
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
  pinMode(triger4, OUTPUT);
  pinMode(echo4, INPUT);
  pinMode(pulsador,INPUT_PULLUP);
  //Definition of motor speed
  motor.setSpeed(120);
  motor.stop();
  servo.write(90);
}
// principal loop start 
void loop() {
//Assignment of variable values
  cont = millis();
  distanciaade = ultrasonidoade.ping_cm();
  delay(30);
  distanciaizq = ultrasonidoizq.ping_cm();
  delay(30);
  distanciader = ultrasonidoder.ping_cm();
  delay(30);
  distanciaatr = ultrasonidoatr.ping_cm();
  if(lineas<12){
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  Serial.print("cont: ");
  Serial.println(cont);
  Serial.print("sensor adelante: ");
  Serial.println(distanciaade);
  Serial.print("sensor derecha: ");
  Serial.println(distanciader);
  Serial.print("sensor izquierda: ");
  Serial.println(distanciaizq);
  Serial.print("lineas");
  Serial.println(lineas);
  Serial.print("no: ");
  Serial.println(no);
  int centro=(distanciaizq+distanciader);
  if(motors==1){
    carrorect();
  }
  //Corner crossing conditions
  if((distanciaizq>100&&distanciaizq<300&&der==0&&izq==0&&distanciaade<=10&&si==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0)||esquina==1){
    if((cont-tiempoantesdelcont>intervalo)||esq==0){
      tiempoantesdelcont=cont;
      if(esq==0){
        noconos=0;
        ra1=0;
        ra2=0;
        ra3=0;
        ra4=0;
        ra5=0;
        ra6=0;
        ra7=0;
        ra8=0;
        ra9=0;
        rm1=0;
        rm2=0;
        rm3=0;
        rm4=0;
        rm5=0;
        rm6=0;
        rm7=0;
        rm8=0;
        rm9=0;
        rd1=0;
        rd2=0;
        rd3=0;
        rd4=0;
        rd5=0;
        rd6=0;
        rd7=0;
        rd8=0;
        rd9=0;
        va1=0;
        va2=0;
        va3=0;
        va4=0;
        va5=0;
        va6=0;
        va7=0;
        va8=0;
        va9=0;
        vm1=0;
        vm2=0;
        vm3=0;
        vm4=0;
        vm5=0;
        vm6=0;
        vm7=0;
        vm8=0;
        vm9=0;
        vd1=0;
        vd2=0;
        vd3=0;
        vd4=0;
        vd5=0;
        vd6=0;
        vd7=0;
        vd8=0;
        vd9=0;
        esquina=1;
        carrorect();
        stopcar();
        intervalo=1800;
        si=1;
        esq=1;
        servo.write(35);
        motor.backward(); 
        izq=1;
        motors=0;
      }
       else if(esq==1){
       stopcar();
       servo.write(85);
       motor.stop();
       motor.forward();
       intervalo=600;
       esq=2;
      }
      else if(esq==2){
        
       stopcar();
       servo.write(85);
       motor.stop();
       no=1;
       if(no==0){
          no=1;
       }
        intervalo=1000;
       esq=3;
      }
       else if(esq==3){
        carrorect();
        motors=1;
        lineas++;
        esquina=0;
        no=0;
        izq=1;
        enviarM();
        tiempoantesdelcont=0;
        esq=0;if(ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0){
          noconos=1;
        }
        else{
          noconos=0;
        }
       }
       
  }
  }
 //Initial turn
if((distanciader>100&&esquina==0&&distanciaade<=15&&izq==0&&der==0&&si==0)||esquinader==1){
    if((cont-tiempoantesdelcont>intervaloder)||esq3==0){
      tiempoantesdelcont=cont;
      if(esq3==0){
        noconos=0;
        ra1=0;
        ra2=0;
        rm1=0;
        rm2=0;
        rd1=0;
        rd2=0;
        va1=0;
        va2=0;
        vm1=0;
        vm2=0;
        vd1=0;
        vd2=0;
        esquinader=1;
        carrorect();
        stopcar();
        intervaloder=1700;
        si=1;
        esq3=1;
        servo.write(140);
        motor.backward(); 
        der=1;
        motors=0;
      }
      else if(esq3==1){
        
       stopcar();
       servo.write(85);
       motor.stop();
       motor.forward();
       intervaloder=600;
       esq3=2;
      }
      else if(esq3==2){
        
       stopcar();
       servo.write(85);
       motor.stop();
       no=1;
       if(no==0){
          no=1;
       }
        intervaloder=1200;
       esq3=3;
      }
      else if(esq3==3){
        carrorect();
        motors=1;
        esq3=0;
        lineas++;
        no=0;
        if(no==1){
          no=0;
        }
        intervaloder=1000;
        esquinader=0;
        tiempoantesdelcont=0;
        si=1;
        enviarM();
        if(ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0){
          noconos=1;
        }
        else{
          noconos=0;
        }
      }   
    }     
  }
  if((distanciader>100&&esquinadertrs==0&&esquinader3==0&&esquina==0&&distanciaade<=15&&izq==0&&der==1&&si==0&&cruzconorojo2==0&&conorfin==1&&conovfin==0)||esquinaderalt==1){
    Serial.println("esquina despues de esquivar cono rojo");
   if((cont-tiempoantesdelcont)>intervaloder||esq==0){
    tiempoantesdelcont=cont;
   Serial.println(tiempoantesdelcont); 
    if(esq==0){
      noconos=0;
        ra1=0;
        ra2=0;
        rm1=0;
        rm2=0;
        rd1=0;
        rd2=0;
        va1=0;
        va2=0;
        vm1=0;
        vm2=0;
        vd1=0;
        vd2=0;
        Serial.println("Hola");
        esquinaderalt=1;
        carrorect();
        stopcar();
        intervaloder=1900;
        si=1;
        esq=1;
        servo.write(140);
        motor.backward();
        motors=0;
      }
      else if(esq==1){
        no=1;
        if(no==0){
          no=1;
        }
       stopcar();
       servo.write(85);
       motor.stop();
        intervaloder=1200;
       esq=2;
      }
      else if(esq==2){
        carrorect();
        motors=1;
        esq=0;
        lineas++;
        no=0;
        intervaloder=1000;
        esquinaderalt=0;
        tiempoantesdelcont=0;
        enviarM();
        conorfin=0;
        if(ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0){
          noconos=1;
        }
        else{
          noconos=0;
        }
      }   
        
   }
  }
  if((distanciader>100&&distanciaade<=36&&izq==0&&der==1&&si==0&&cruzconorojo2==0&&conovfin==1&&conorfin==0)||esquinaderv==1){
   if((cont-tiempoantesdelcont)>intervaloder||esq==0){
    tiempoantesdelcont=cont;
    if(esq==0){
      noconos=0;
        ra1=0;
        ra2=0;
        rm1=0;
        rm2=0;
        rd1=0;
        rd2=0;
        va1=0;
        va2=0;
        vm1=0;
        vm2=0;
        vd1=0;
        vd2=0;
        esquinaderv=1;
        carrorect();
        stopcar();
        intervaloder=1200;
        si=1;
        esq=1;
        servo.write(85);
       motor.backward();
        motors=0;
      }
      
      else if(esq==1){
       stopcar();
       
       servo.write(30);
        motor.forward();
        intervaloder=1800;
       esq=2;
      }
      else if(esq==2){
        no=1;
        if(no==0){
          no=1;
        }
        
       stopcar();
       no=1;
       servo.write(85);
       motor.stop();
        intervaloder=1200;
       esq=3;
      }
      else if(esq==3){
        carrorect();
        motors=1;
        esq=0;
        lineas++;
        no=0;
        intervaloder=1000;
        esquinaderv=0;
        tiempoantesdelcont=0;
        enviarM();
        conovp=0;
        conorp=0;
        conovfin=0;
        if(ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0){
          noconos=1;
        }
        else{
          noconos=0;
        }
      }   
        
   }
  }
  if((distanciaizq>100&&distanciaade<=15&&izq==1&&der==0&&si==0&&cruzconorojo2==0&&conorfin==1&&conovfin==0)||esquinaizqr==1){
    tiempoantesdelcont=cont;
    if(esq==0){
      noconos=0;
        ra1=0;
        ra2=0;
        rm1=0;
        rm2=0;
        rd1=0;
        rd2=0;
        va1=0;
        va2=0;
        vm1=0;
        vm2=0;
        vd1=0;
        vd2=0;
        esquinaizqr=1;
        carrorect();
        stopcar();
        intervaloder=1800;
        si=1;
        esq=1;
        servo.write(85);
       motor.backward();
        motors=0;
      }
      
      else if(esq==1){
       stopcar();
       
       servo.write(140);
        motor.forward();
        intervaloder=1600;
       esq=2;
      }
      else if(esq==2){
       stopcar();
       no=1;
       servo.write(85);
       motor.backward();
        intervaloder=600;
       esq=3;
      }
      else if(esq==3){
        no=1;
        if(no==0){
          no=1;
        }
        Serial.println("se detuvo");
       stopcar();
       no=1;
       servo.write(85);
       motor.stop();
        intervaloder=1200;
       esq=4;
      }
      else if(esq==4){
        carrorect();
        motors=1;
        esq=0;
        lineas++;
        no=0;
        intervaloder=1000;
        esquinaizqr=0;
        tiempoantesdelcont=0;
        enviarM();
        conorfin=0;
        conovp=0;
        conorp=0;
        if(ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0){
          noconos=1;
        }
        else{
          noconos=0;
        }
      }   
        
   }
  }
  if((distanciaizq>100&&esquinadertrs==0&&esquinader3==0&&esquina==0&&distanciaade<=15&&izq==1&&der==0&&si==0&&cruzconorojo2==0&&conovfin==1&&conorfin==0)||esquinaizqv==1){
    Serial.println("esquina despues de esquivar cono verde anti horario");
   if((cont-tiempoantesdelcont)>intervaloder||esq==0){
    tiempoantesdelcont=cont;
   Serial.println(tiempoantesdelcont); 
    if(esq==0){
      noconos=0;
        ra1=0;
        ra2=0;
        rm1=0;
        rm2=0;
        rd1=0;
        rd2=0;
        va1=0;
        va2=0;
        vm1=0;
        vm2=0;
        vd1=0;
        vd2=0;
        Serial.println("Hola");
        esquinaizqv=1;
        carrorect();
        stopcar();
        intervaloder=1700;
        si=1;
        esq=1;
        servo.write(30);
        motor.backward();
        motors=0;
      }
      
      else if(esq==1){
       stopcar();
       servo.write(85);
       motor.backward();
        intervaloder=300;
       esq=2;
      }
      else if(esq==2){
       stopcar();
       no=1;
       if(no==0){
        no=1;
       }
       servo.write(85);
       motor.stop();
        intervaloder=1200;
       esq=3;
      }
      else if(esq==3){
        carrorect();
        motors=1;
        esq=0;
        lineas++;
        no=0;
        intervaloder=1000;
        esquinaizqv=0;
        tiempoantesdelcont=0;
        enviarM();
        conovfin=0;
        if(ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0){
          noconos=1;
        }
        else{
          noconos=0;
        }
      }   
        
   }
  }
  //Obstacle avoiding conditions
  if((((ra1!=0||ra2!=0)||cruzconorojoizq==1)&&der==0&&izq==1)&&esquinaizqr==0&&esquinaizqv==0&&esquinaderv==0&&esquina==0&&esquina2==0&&esq==0){
    Serial.println("cono rojo izq");
    noconos=0;
    if((((cont-valorantesconor)>intervalocono)||crucecono==0)&&cnrojo==0){
      valorantesconor=cont;
      if(crucecono==0){
          intervalocono=900;
          Serial.println("Hola b1");
         crucecono=1;
        cruzconorojoizq=1;
        carroesqder();
        motors=0;
        
        }
        else if(crucecono==1){
          Serial.println("Hola b2");
         crucecono=2;
         motor.stop();
         carroesqizq();
         intervalocono=1000;
        }
        else if(crucecono==2){
          Serial.println("Hola b3");
        crucecono=0;
        carrorect();
        valorantesconor=0;
        intervalocono=900;
        cnrojo=1;
        if(cnrojo==0){
          cnrojo=1;
        }
        crucecono=0;
        
        }
    }
    if(cnrojo==1){
      Serial.println("mantenerse derecho");
      
     if(((((cont-contfincono)>=1000)&&conorcont==1)||rc==1)&&cnr==0){
          Serial.println("centrar adios cono 3");
          
          if(((cont-valordespuesconor)>intervalodespuescono)||vgn==0){
            Serial.println("Hola mundo");
            valordespuesconor=cont;
        if(vgn==0){
          carrorect();
          motor.stop();
          no=1;
          rc=1;
          vgn=1;
          ciclo=1;
          
        }
        else if(vgn==1&&(vd1!=0||vd2!=0)){
          Serial.println("pp");
          no=0;
          cruzconorojoizq=0;
          crucecono=0;
          ra1=0;
          ra2=0;
          cnrojo=0;
          conorcont=0;
          valordespuesconor=0;
          vgn=0;
          rc=0;
          conorp=1;
          conorfin=0;
        }
        else if(vgn==1&&(vd1==0&&vd2==0)){
          Serial.println("ii");
          carrorect();
          cnr=1;
          conorcont=0;
          valordespuesconor=0;
          conorp=0;
          conorcont=0;
          no=0;
          ciclo=0;
        }
        
     }
    
     
    }
  
     else if(distanciaade<=100&&(((cont-contfincono)>=1000)&&conorcont==1)&&cnr==1){
      carrorect();
        cruzconorojoizq=0;
        crucecono=0;
        ra1=0;
        ra2=0;
        ra3=0;
        ra4=0;
        ra5=0;
        ra6=0;
        ra7=0;
        ra8=0;
        ra9=0;
        rm1=0;
        rm2=0;
        rm3=0;
        rm4=0;
        rm5=0;
        rm6=0;
        rm7=0;
        rm8=0;
        rm9=0;
        rd1=0;
        rd2=0;
        rd3=0;
        rd4=0;
        rd5=0;
        rd6=0;
        rd7=0;
        rd8=0;
        rd9=0;
        motors=1;
        cnrojo=0;
        conorfin=1;
        conorp=1;
        conorcont=0;
        rc=0;
        si=0;
     }
     else{
      if(conorcont==0){
        Serial.println("cont activated");
        contfincono=cont;
        conorcont=1;
      }
       conorojo();
        motors=0;
     }
    }
  }
  if((((rd1!=0||rd2!=0)||cruzconorojonc==1)&&der==0&&izq==1&&nc==1)&&esquinaizqr==0&&esquinaizqv==0&&esquinaderv==0&&esquina==0&&esquina2==0&&esq==0){
    noconos=0;
    if((((cont-valorantesconor)>intervalocono)||crucecono==0)&&cnrojo==0){
      valorantesconor=cont;
      if(crucecono==0){
          intervalocono=900;
         crucecono=1;
        cruzconorojonc=1;
        carroesqder();
        motors=0;
        
        }
        else if(crucecono==1){
         crucecono=2;
         motor.stop();
         carroesqizq();
         intervalocono=1100;
        }
        else if(crucecono==2){
        crucecono=0;
        carrorect();
        valorantesconor=0;
        intervalocono=900;
        cnrojo=1;
        nc=0;
        ciclo=0;
        si=0;
        cruzconorojonc=0;
        conorfin=1;
        rd1=0;
        rd2=0;
        rd3=0;
        rd4=0;
        rd5=0;
        rd6=0;
        rd7=0;
        rd8=0;
        rd9=0;
        if(cnrojo==0){
          cnrojo=1;
        }
        crucecono=0;
        
        }
    }
  }
    if((((rm1!=0||rm2!=0)||cruzconorojo2==1)&&der==0&&izq==1)&&esquinaizqr==0&&esquinaizqv==0&&esquinaderalt==0&&esquinaderv==0&&esquina==0&&va2==0&&va1==0&&ra2==0&&ra1==0){
    noconos=0;
    if((((cont-valorantesconor)>intervalocono)||cruceconocent==0)&&cnrojo==0){
      valorantesconor=cont;
      if(cruceconocent==0){
          intervalocono=1000;
         cruceconocent=1;
        cruzconorojo2=1;
        carroesqder();
        motors=0;
        }
        else if(cruceconocent==1){
          motors=0;
         cruceconocent=2;
         motor.stop();
         servo.write(145);
         motor.forward();
         valorantesconor=cont;
         intervalocono=1000;
        }
        else if(cruceconocent==2){
        cruceconocent=0;
        carrorect();
        valorantesconor=0;
        intervalocono=800;
        cnrojo=1;
        crucecono=0;
        conorfin=1;
        
        }
    }
    if(cnrojo==1){
      
     if((distanciaade<=100&&((cont-contfincono)>=2000)&&conorcont==1)){
        carrorect();
        cruzconorojo2=0;
        crucecono=0;
        cruceconocent=0;
        rm1=0;
        rm2=0;
        rm3=0;
        rm4=0;
        rm5=0;
        rm6=0;
        rm7=0;
        rm8=0;
        rm9=0;
        motors=1;
        cnrojo=0;
        conorfin=1;
        paredder=0;
       pareder2=0;
       motors=1;
       paredizq=0;
      si=0;
      pared2=0;
      conorcont=0;
     }
     else{
      if(conorcont==0){
        contfincono=cont;
        conorcont=1;
      }
       conorojo();
        motors=0;
     }
    }
  }
  else if((rm1!=0||rm2!=0)&&vd1==1||vd2==1||va1==1||va2==1||ra2==1||ra1==1||rd1==1||rd2==1){
    rm1=0;
        rm2=0;
        cruzconorojo2=0;
  }
  if((((rd1!=0||rd2!=0)||cruzconorojoizq3==1)&&der==0&&izq==1&&conovp==1)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0){
    noconos=0;
    if((((cont-valorantesconor)>intervalocono)||cruceconor2==0)){
      valorantesconor=cont;
      if(cruceconor2==0){
          intervalocono=1200;
         cruzconorojoizq3=1;
         cruceconor2=1;
        carroesqder();
        motors=0;
        }
        else if(cruceconor2==1){
          motors=0;
         cruceconor2=2;
         motor.stop();
         carrorect();
         servo.write(145);
         intervalocono=1500;
        }
        else if(cruceconor2==2){
        carrorect();
        valorantesconor=0;
        cruceconor2=0;
        intervalocono=1500;
        cruzconorojoizq3=0;
        conorfin=1;
        rd1=0;
        rd2=0;
        rd3=0;
        rd4=0;
        rd5=0;
        rd6=0;
        rd7=0;
        rd8=0;
        rd9=0;
        ciclo=0;
        si=0;
        }
    }
  }
  //Red obstacle in front
  if((((ra1!=0||ra2!=0)||cruzconorojo==1)&&der==1&&izq==0&&conorp==0)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0&&esquina==0&&esquina2==0){
    noconos=0;
    if((((cont-valorantesconor)>intervalocono)||crucecono==0)&&cnrojo==0){
      valorantesconor=cont;
      if(crucecono==0){
          intervalocono=900;
         crucecono=1;
        cruzconorojo=1;
        carroesqder();
        motors=0;
        }
        else if(crucecono==1){
         crucecono=2;
         motor.stop();
         carroesqizq();
         intervalocono=900;
        }
        else if(crucecono==2){
        crucecono=0;
        carrorect();
        valorantesconor=0;
        intervalocono=900;
        cnrojo=1;
        if(cnrojo==0){
          cnrojo=1;
        }
        crucecono=0;
        }
        
    }
    if(cnrojo==1){
      
     if(((((cont-contfincono)>=1500)&&conorcont==1)||rc==1)&&cnr==0){
          
          if(((cont-valordespuesconor)>intervalodespuescono)||vgn==0){
            valordespuesconor=cont;
        if(vgn==0){
          carrorect();
          motor.stop();
          no=1;
          rc=1;
          
          vgn=1;
          ciclo=1;
        }
        else if(vgn==1&&(vd1!=0||vd2!=0)){
          no=0;
          cruzconorojo=0;
          crucecono=0;
          ra1=0;
          ra2=0;
          cnrojo=0;
          conorcont=0;
          valordespuesconor=0;
          vgn=0;
          rc=0;
          conorp=1;
          conorcont=0;
          conorfin=0;
        }
        else if(vgn==1&&(vd1==0&&vd2==0)){
          carrorect();
          cnr=1;
          conorcont=0;
          valordespuesconor=0;
          conorp=0;
          conorcont=0;
          no=0;
          ciclo=0;
        }
        
     }
    
     
    }
  
     else if(distanciaade<=100&&(((cont-contfincono)>=1000)&&conorcont==1)&&cnr==1){
      carrorect();
        cruzconorojo=0;
        crucecono=0;
        ra1=0;
        ra2=0;
        rm1=0;
        rm2=0;
        rd1=0;
        rd2=0;
        motors=1;
        cnrojo=0;
        conorfin=1;
        conorp=1;
        conorcont=0;
        rc=0;
        si=0;
     }
     else{
      if(conorcont==0){
        contfincono=cont;
        conorcont=1;
      }
       conorojo();
        motors=0;
     }
    }
    }
  
  if((((rm1!=0||rm2!=0)||cruzconorojo2==1)&&der==1&&izq==0)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0&&conorp==0&&va2==0&&va1==0&&ra2==0&&ra1==0){
    noconos=0;
    if((((cont-valorantesconor)>intervalocono)||cruceconocent==0)&&cnrojo==0){
      valorantesconor=cont;
      if(cruceconocent==0){
          intervalocono=800;
         cruceconocent=1;
        cruzconorojo2=1;
        carroesqder();
        motors=0;
        }
        else if(cruceconocent==1){
          motors=0;
         cruceconocent=2;
         motor.stop();
         carrorect();
         servo.write(145);
         valorantesconor=cont;
         intervalocono=900;
        }
        else if(cruceconocent==2){
        cruceconocent=0;
        carrorect();
        valorantesconor=0;
        intervalocono=800;
        cnrojo=1;
        crucecono=0;
        
        }
    }
    if(cnrojo==1){
      
     if((distanciaade<=100&&((cont-contfincono)>=4000)&&conorcont==1)){
        carrorect();
        cruzconorojo2=0;
        crucecono=0;
        cruceconocent=0;
        ra1=0;
        ra2=0;
        rd1=0;
        rd2=0;
        rm1=0;
        rm2=0;
        motors=1;
        cnrojo=0;
        conorfin=1;
        paredder=0;
       pareder2=0;
       motors=1;
       paredizq=0;
      si=0;
      pared2=0;
      conorcont=0;
     }
     else{
      if(conorcont==0){
        contfincono=cont;
        conorcont=1;
      }
       conorojo();
        motors=0;
     }
    }
  }
  if((((va1!=0||va2!=0)||cruzconoverde==1)&&der==0&&izq==1&&conovp==0&&nc==0)&&esquinaizqr==0&&esquinaizqv==0&&esquinader==0&&esquinaderv==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov==0){
        rm1=0;
        rm2=0;
        vm1=0;
        vm2=0;
          intervaloconov=1000;
         cruceconov=1;
        cruzconoverde=1;
        carroesqizq();
        motors=0;
        }
        else if(cruceconov==1){
          motors=0;
         cruceconov=2;
         motor.stop();
         carrorect();
         servo.write(25);
         valorantesconov=cont;
         intervaloconov=900;
        }
        else if(cruceconov==2){
        carrorect();
        cruzconoverde=1;
        valorantesconov=0;
        intervalocono=600;
        cnverde=1;
        cruceconov=0;
       
        }
    }
    if(cnverde==1){
      if(((((cont-contfinconov)>=1300)&&conovcont==1)||vc==1)&&cnv==0){
        if(((cont-valordespuesconov)>intervalodespuescono)||vgn==0){
          valordespuesconov=cont;
        if(vgn==0){
          carrorect();
          motor.stop();
          no=1;
          vc=1;
          vgn=1;
          ciclo=1;
          motors=0;
          rm1=0;
        rm2=0;
        vm1=0;
        vm2=0;
        }
        else if(vgn==1&&(rd1!=0||rd2!=0)){
          no=0;
          cruzconoverde=0;
          ciclo=0;
          cruceconov=0;
          va1=0;
          va2=0;
          cnverde=0;
          conovcont=0;
          valordespuesconov=0;
          vgn=0;
          vc=0;
          conovp=1;
          conovcont=0;
          conovfin=0;
          va1=0;
        va2=0;
        va3=0;
        va4=0;
        va5=0;
        va6=0;
        va7=0;
        va8=0;
        va9=0;
        vm1=0;
        vm2=0;
        vm3=0;
        vm4=0;
        vm5=0;
        vm6=0;
        vm7=0;
        vm8=0;
        vm9=0;
        vd1=0;
        vd2=0;
        vd3=0;
        vd4=0;
        vd5=0;
        vd6=0;
        vd7=0;
        vd8=0;
        vd9=0;
        }
        else if(vgn==1&&(rd1==0&&rd2==0)){
          carrorect();
          cnv=1;
          conovcont=0;
          valordespuesconov=0;
          conovp=0;
          conovcont=0;
          no=0;
          ciclo=0;
          vc=0;
          vgn=0;
        }
        }
      }
     else if((distanciaade<=100&&((cont-contfinconov)>=3000)&&conovcont==1)&&cnv==1){
        carrorect();
        cruzconoverde=0;
        cruceconov=0;
        conovp=1;
        va1=0;
        va2=0;
        va3=0;
        va4=0;
        va5=0;
        va6=0;
        va7=0;
        va8=0;
        va9=0;
        vm1=0;
        vm2=0;
        vm3=0;
        vm4=0;
        vm5=0;
        vm6=0;
        vm7=0;
        vm8=0;
        vm9=0;
        vd1=0;
        vd2=0;
        vd3=0;
        vd4=0;
        vd5=0;
        vd6=0;
        vd7=0;
        vd8=0;
        vd9=0;
        motors=1;
        cnverde=0;
        conovfin=1;
        paredder=0;
       pareder2=0;
       motors=1;
       paredizq=0;
      si=0;
      pared2=0;
      conovcont=0;
     }
     else{
      if(conovcont==0){
          contfinconov=cont;
          conovcont=1;
      }
       conoverde();
        motors=0;
     }
    }
  }
  if((((vm1!=0||vm2!=0)||cruzconoverde2==1)&&der==0&&izq==1)&&esquina==0&&esquinaizqr==0&&esquinader2==0&&esquinaderalt==0&&esquinaizqv==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov2==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov2==0){
          intervaloconov=700;
         cruceconov2=1;
        cruzconoverde2=1;
        carroesqizq();
        motors=0;
        }
        else if(cruceconov2==1){
          motors=0;
         cruceconov2=2;
         motor.stop();
         servo.write(25);
         motor.forward();
         valorantesconov=cont;
         intervaloconov=900;
        }
        else if(cruceconov2==2){
        carrorect();
        cruzconoverde2=1;
        valorantesconov=0;
        intervaloconov=600;
        cnverde=1;
        cruceconov2=0;
       
        }
    }
    if(cnverde==1){
      
     if((distanciaade<=95&&((cont-contfinconov)>=2900)&&conovcont==1)){
        carrorect();
        cruzconoverde2=0;
        cruceconov2=0;
        va1=0;
        va2=0;
        va3=0;
        va4=0;
        va5=0;
        va6=0;
        va7=0;
        va8=0;
        va9=0;
        vm1=0;
        vm2=0;
        vm3=0;
        vm4=0;
        vm5=0;
        vm6=0;
        vm7=0;
        vm8=0;
        vm9=0;
        vd1=0;
        vd2=0;
        vd3=0;
        vd4=0;
        vd5=0;
        vd6=0;
        vd7=0;
        vd8=0;
        vd9=0;
        motors=1;
        cnverde=0;
        conovfin=1;
        paredder=0;
       pareder2=0;
       motors=1;
       paredizq=0;
      si=0;
      pared2=0;
      conovcont=0;
     }
     else{
      if(conovcont==0){
        contfinconov=cont;
        conovcont=1;
      }
       conoverde();
        motors=0;
     }
    }
  }
  if((((vd1!=0||vd2!=0)||cuzconoverdeizq3==1)&&der==0&&izq==1&&conorp==1)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov2==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov2==0){
          intervaloconov=1500;
         cuzconoverdeizq3=1;
         cruceconov2=1;
        carroesqizq();
        motors=0;
        }
        else if(cruceconov2==1){
          motors=0;
         cruceconov2=2;
         motor.stop();
         carrorect();
         servo.write(25);
         intervaloconov=1600;
        }
        else if(cruceconov2==2){
        carrorect();
        valorantesconov=0;
        cruceconov2=0;
        intervalocono=1900;
        cuzconoverdeizq3=0;
        conovfin=1;
        ciclo=0;
        si=0;
        va1=0;
        va2=0;
        va3=0;
        va4=0;
        va5=0;
        va6=0;
        va7=0;
        va8=0;
        va9=0;
        vm1=0;
        vm2=0;
        vm3=0;
        vm4=0;
        vm5=0;
        vm6=0;
        vm7=0;
        vm8=0;
        vm9=0;
        vd1=0;
        vd2=0;
        vd3=0;
        vd4=0;
        vd5=0;
        vd6=0;
        vd7=0;
        vd8=0;
        vd9=0;
        }
    }
  }
  if((((vd1!=0||vd2!=0)||cruceconovnc==1)&&der==0&&izq==1&&nc==1)&&esquinaizqr==0&&esquinaizqv==0&&esquinader==0&&noconos==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov==0){
          intervaloconov=800;
         cruceconovnc=1;
        cruceconov=1;
        carroesqizq();
        motors=0;
        }
        else if(cruceconov==1){
          motors=0;
         motor.stop();
         carrorect();
         servo.write(25);
         valorantesconov=cont;
         intervaloconov=1000;
         cruceconov=2;
        }
        else if(cruceconov==2){
        carrorect();
        cruceconovnc=0;
        valorantesconov=0;
        intervalocono=600;
        cnverde=0;
        nc=0;
        cruceconov=0;
        conovfin=1;
        va1=0;
        va2=0;
        va3=0;
        va4=0;
        va5=0;
        va6=0;
        va7=0;
        va8=0;
        va9=0;
        vm1=0;
        vm2=0;
        vm3=0;
        vm4=0;
        vm5=0;
        vm6=0;
        vm7=0;
        vm8=0;
        vm9=0;
        vd1=0;
        vd2=0;
        vd3=0;
        vd4=0;
        vd5=0;
        vd6=0;
        vd7=0;
        vd8=0;
        vd9=0;
        motors=1;
        si=0;
        ciclo=0;
        }
    }
     }
  if((((va1!=0||va2!=0)||cruzconoverde==1)&&der==1&&izq==0&&conovp==0)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov==0){
          intervaloconov=800;
         cruceconov=1;
        cruzconoverde=1;
        carroesqizq();
        motors=0;
        }
        else if(cruceconov==1){
          motors=0;
         cruceconov=2;
         motor.stop();
         carrorect();
         servo.write(25);
         valorantesconov=cont;
         intervaloconov=900;
        }
        else if(cruceconov==2){
        carrorect();
        cruzconoverde=1;
        valorantesconov=0;
        intervalocono=600;
        cnverde=1;
        cruceconov=0;
        si=0;
        }
    }
    if(cnverde==1){
      
     if((distanciaade<=100&&((cont-contfinconov)>=3000)&&conovcont==1)){
        carrorect();
        cruzconoverde=0;
        cruceconov=0;
        conovp=1;
        va1=0;
        va2=0;
        vd1=0;
        vd2=0;
        vm1=0;
        vm2=0;
        motors=1;
        cnverde=0;
        conovfin=1;
        paredder=0;
       pareder2=0;
       motors=1;
       paredizq=0;
      si=0;
      pared2=0;
      conovcont=0;
     }
     else{
      if(conovcont==0){
        contfinconov=cont;
        conovcont=1;
      }
       conoverde();
        motors=0;
     }
    }
  }
  if((((vm1!=0||vm2!=0)||cruzconoverde2==1)&&der==1&&izq==0)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov2==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov2==0){
          intervaloconov=1100;
         cruceconov2=1;
        cruzconoverde2=1;
        carroesqizq();
        motors=0;
        }
        else if(cruceconov2==1){
          motors=0;
         cruceconov2=2;
         motor.stop();
         carrorect();
         servo.write(25);
         valorantesconov=cont;
         intervaloconov=1000;
        }
        else if(cruceconov2==2){
        carrorect();
        cruzconoverde2=1;
        valorantesconov=0;
        intervalocono=600;
        cnverde=1;
        cruceconov2=0;
        }
    }
    if(cnverde==1){
     if((distanciaade<=95&&((cont-contfinconov)>=2900)&&conovcont==1)){
        carrorect();
        cruzconoverde2=0;
        cruceconov2=0;
        va1=0;
        va2=0;
        vd1=0;
        vd2=0;
        vm1=0;
        vm2=0;
        motors=1;
        cnverde=0;
        conovfin=1;
        paredder=0;
       pareder2=0;
       motors=1;
       paredizq=0;
      si=0;
      pared2=0;
      conovcont=0;
     }
     else{
      if(conovcont==0){
        contfinconov=cont;
        conovcont=1;
      }
       conoverde();
        motors=0;
     }
    }
  }
  if((((vd1!=0||vd2!=0)||cuzconoverde3==1)&&der==1&&izq==0&&conorp==1)&&esquinader==0&&esquinader2==0&&esquinaderalt==0&&esquinaderv==0){
    noconos=0;
    if((((cont-valorantesconov)>intervaloconov)||cruceconov2==0)&&cnverde==0){
      valorantesconov=cont;
      if(cruceconov2==0){
          intervaloconov=1400;
         cuzconoverde3=1;
        carroesqizq();
        motors=0;
        cruceconov2=1;
        }
        else if(cruceconov2==1){
          motors=0;
         cruceconov2=2;
         motor.stop();
         carrorect();
         servo.write(25);
         intervaloconov=1400;
        }
        else if(cruceconov2==2){
        carrorect();
        valorantesconov=0;
        intervalocono=600;
        cuzconoverde3=0;
        conovfin=1;
        conorp=0;
        ciclo=0;
        si=0;
        }
    }
  }
  //Car alignment conditions
  if(centro<95&&esquinader==0&&esquinader2==0&&esquinaizqr==0&&esquinaizqv==0&&esquina==0&&distanciader>0&&distanciaizq>0){
   if((noconos==1&&ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0)||nconos==1){
    if(((cont-contnoconos)>1300)&&conorcont==1){
      contnoconos=cont;
      if(nconos==0){
        ciclo=1;
        no=1;
        servo.write(85);
        motor.stop();
        nconos=1;
        motors=0;
      }
      else if(nconos==1&&(vd1!=0||vd2!=0||rd1!=0||rd2!=0)){
        no=0;
        noconos=0;
        conorcont=0;
        nconos=0;
        nc=1;}
      }
      else if((vd1==0||vd2==0||rd1==0||rd2==0)&&nconos==1){
        motor.forward();
        delay(1000);
        no=0;
        noconos=0;
        conorcont=0;
        nconos=0;
        nc=1;
      }
    }
    else if(conorcont==0){
      contnoconos=cont;
      conorcont=1;
    }
   if(((distanciaizq<40&&distanciaizq>0&&distanciaade>100)&&nconos==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0&&ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0)||paredizq==1){
    if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared2==0&&(esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0)){
      paredizq=1;
      si=0;
      pared2=1;
      centrarizq();
      motors=0;
    }
    else if(pared2==1){
      paredizq=0;
      si=0;
      pared2=0;
      carrorect();
      motors=1;
      antespared=0;
    }
  }
 }
 if(((distanciader<40&&distanciader>0&&distanciaade>100)&&esquinadertrs==0&&nconos==0&&esquinader==0&&esquinatrs==0&&esquina==0&&ra1==0&&ra2==0&&rm1==0&&rm2==0&&rd1==0&&rd2==0&&va1==0&&va2==0&&vm1==0&&vm2==0&&vd1==0&&vd2==0)||paredder==1){
    if((cont-antesparedder)>intervalopared){
      antesparedder=cont;
      if(pareder2==0&&esquinadertrs==0&&esquinader==0&&esquinatrs==0&&esquina==0){
        paredder=1;
        pareder2=1;
        centrarder();
        motors=0;
        si=0;
      }
      else if(pareder2==1){
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
  //End of the 3rd lap
  else{
    fin();
  }
  
}
//Declaraton of functions
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
  servo.write(45);
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
  servo.write(145);
  motor.forward();
}
void carrorect() {
  motor.stop();
  servo.write(85);
  motor.forward();
}
void stopcar() {
  motor.stop();
}
void fin() {
  motor.forward();
  servo.write(85);
  delay(3400);
  motor.stop();
  delay(1000000);
}
void conorojo(){
    Serial.println("que fue");
    if((((distanciaizq<=65&&distanciaizq>20))||paredizq==1)){
    if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared2==0){
      paredizq=1;
      pared2=1;
      centrarizq();
     Serial.println("sep izq 1");
      motors=0;
    }
    else if(pared2==1){
      pared2=2;
      servo.write(100);
      Serial.println("sep izq 2");
      motors=0;
    }
    else if(pared2==2){
      paredizq=0;
      pared2=0;
      carrorect();
      motors=1;
      antespared=0;
      Serial.println("sep izq 3");
    }
  }
 }
 if(((distanciader<=10))||paredder==1){
    if((cont-antesparedder)>intervalopared){
      antesparedder=cont;
      if(pareder2==0&&esquinadertrs==0){
        Serial.println("sep der 1");
        paredder=1;
        pareder2=1;
        centrarder();
        motors=0;
      }
      else if(pareder2==1){
         Serial.println("sep der 2");
        pareder2=2;
        servo.write(80);
        motors=0;
      }
      else if(pareder2==2){
        Serial.println("sep der 3");
        paredder=0;
        pareder2=0;
        carrorect();
        motors=1;
      }
    }
  }
    
  }
 
  
void conoverde(){
    if((((distanciader<=63&&distanciader>40))||paredizq==1)){
    if(cont-antespared>intervalopared){
    antespared=cont;
    if(pared2==0){
      paredizq=1;
      pared2=1;
      centrarder();
      motors=0;
    }
    else if(pared2==1){
      pared2=2;
      servo.write(70);
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
 if(((distanciaizq<=10))||paredder==1){
    if((cont-antesparedder)>intervalopared){
      antesparedder=cont;
      if(pareder2==0&&esquinadertrs==0){
        paredder=1;
        pareder2=1;
        centrarizq();
        motors=0;
      }
      else if(pareder2==1){
        pareder2=2;
        servo.write(100);
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
void recibirm() {
    if (Wire.available()) {
    char c = Wire.read();
    if((c!=te&&entradai2c.length()<3)){
     Serial.println(c);
    te=c;
    entradai2c+=c;
    Serial.print(entradai2c);
    }
    
    if((entradai2c=="ra1"&&ciclo==0)){
      Serial.println("ra1si");
      entradai2c="";
      ra1=1;
      c="";
      te="";
      
     }
      if((entradai2c=="ra2")&&ciclo==0){
      Serial.println("ra2 am");
      entradai2c="";
      ra2=1;
      c="";
      te="";
      
     }
      if((entradai2c=="rm1")&&ciclo==0&&vgn==0){
     Serial.println("rm1 am");
      entradai2c="";
      rm1=1;
      c="";
      te="";
      
     }
       if((entradai2c=="rm2")&&ciclo==0&&vgn==0){
     Serial.println("rm2 am");
      entradai2c="";
      rm2=1;
      c="";
      te="";
      
     }
      if((entradai2c=="ra1")&&ciclo==1){
     Serial.println("rd1 am");
      entradai2c="";
      rd1=1;
      Serial.println(rd1);
      c="";
      te="";
      
     }
       if((entradai2c=="ra2")&&ciclo==1){
      Serial.println("rd2 r");
      entradai2c="";
      c="";
      rd2=1;
      te="";
      
     }
     if((entradai2c=="va1")&&ciclo==0&&vm1==0&&vm2==0){
     Serial.println("va1 am");
      entradai2c="";
      va1=1;
      c="";
      te="";
      
     }
      if((entradai2c=="va2")&&ciclo==0&&vm1==0&&vm2==0){
      Serial.println("va2 am");
      entradai2c="";
      va2=1;
      c="";
      te="";
      
     }
      if((entradai2c=="vm1")&&ciclo==0&&vgn==0){
      Serial.println("vm1 am");
      entradai2c="";
      vm1=1;
      c="";
      te="";
      
     }
      if((entradai2c=="vm2")&&ciclo==0&&vgn==0){
      Serial.println("vm2 am");
      entradai2c="";
      vm2=1;
      c="";
      te="";
      
     }
      if(entradai2c=="va1"&&ciclo==1){
      Serial.println("vd1 am");
      entradai2c="";
      vd1=1;
      c="";
      te="";
      
     }
      if(entradai2c=="va2"&&ciclo==1){
      Serial.println("vd2 am");
      entradai2c="";
      vd2=1;
      c="";
      te="";
     
     }
     }
  }


void enviarM(){
  if(no==1){
  Wire.write(1);
  }
  else{
    Wire.write(0);
  }
}
