#inclusion of libraries
from smbus import SMBus
import cv2 
import numpy as np  
import serial  
import time
#declaration of variables
b=""
w=0
zv=0
zr=0
y=0
r=""
v=""
mp1=""
data=""
clientAddr = 0x8
bus = SMBus(1)
i=1
t=0
vgn=0;
global arear
global areav
arear=2000
areav=2000
cap=cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_FRAME_WIDTH,1920)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT,1080)
redbajo1=np.array([0,120,80],np.uint8) 
redalto1=np.array([5,255,255],np.uint8) 
redbajo2=np.array([160,120,60],np.uint8) 
redalto2=np.array([179,255,255],np.uint8) 
verdebajo=np.array([30,120,50],np.uint8) 
vaerdealto=np.array([90,255,255],np.uint8)
olav=""
olar=""
pp=0;
#function declaration
def i2cWrite(msg):
  for c in msg:
    bus.write_byte(clientAddr, ord(c))
  return -1
def dibujo(mask,color): 
    contornos,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE) 
    for c in contornos : 
            area=cv2.contourArea(c) 
            if area>arear: 
                 #print("rojo encontrado") 
                #ser.write(b"rojo\n")
                m=cv2.moments(c) 
                if(m["m00"]==0):m["m00"]=1 
                x=int(m["m10"]/m["m00"]) 
                y=int(m['m01']/m["m00"]) 
                nuevocontorno=cv2.convexHull(c) 
                global posicion
                print("area roja:")
                print(area)
                if t==0 and x>214 and x<1712:
                  cv2.drawContours(imagennegra,[nuevocontorno],0,color,3)
                  if x<214 and area>arear and area<7000 and t!=0: 
                     posicion="m1"
                  elif x>=214 and x<428 and area>arear and area<6000 : 
                     posicion="m2"
                  elif x>=428 and x<642 and area>arear and area<6000: 
                     posicion="m3"
                  elif x>=642 and x<856 and area>arear and area<6000: 
                     posicion="m4"
                  elif x>=856 and x<1070 and area>arear and area<6000:
                    posicion="m5"
                  elif x>=1070 and x<1284 and area>arear and area<6000:
                    posicion="m6"
                  elif x>=1284 and x<1498 and area>arear and area<6000:
                    posicion="m7"
                  elif x>=1498 and x<1712 and area>arear and area<6000:
                    posicion="m8"
                  elif x>=1712 and area>arear and area<6000:
                    posicion="m9"
                  elif x<214 and area>6000 and t!=0: 
                     posicion="a1"
                  elif x>=214 and x<428 and area>6000 : 
                     posicion="a2"
                  elif x>=428 and x<642 and area>6000 :
                    posicion="a3"
                  elif x>=642 and x<856 and area>6000 : 
                     posicion="a4"
                  elif x>=856 and x<1070 and area>6000 :
                    posicion="a5"
                  elif x>=1070 and x<1284 and area>6000 :
                    posicion="a6"
                  elif x>=1284 and x<1498 and area>7000 :
                    posicion="a7"
                  elif x>=1498 and x<1712 and area>6000 :
                    posicion="a8"
                  elif x>=1712 and area>7000 :
                    posicion="a9"
                  else:
                    posicion="0"
                  return posicion
                if t!=0:
                  cv2.drawContours(imagennegra,[nuevocontorno],0,color,3)
                  if x<214 and area>arear and area<7000 and t!=0: 
                     posicion="m1"
                  elif x>=214 and x<428 and area>arear and area<6000 : 
                     posicion="m2"
                  elif x>=428 and x<642 and area>arear and area<6000: 
                     posicion="m3"
                  elif x>=642 and x<856 and area>arear and area<6000: 
                     posicion="m4"
                  elif x>=856 and x<1070 and area>arear and area<6000:
                    posicion="m5"
                  elif x>=1070 and x<1284 and area>arear and area<6000:
                    posicion="m6"
                  elif x>=1284 and x<1498 and area>arear and area<6000:
                    posicion="m7"
                  elif x>=1498 and x<1712 and area>arear and area<6000:
                    posicion="m8"
                  elif x>=1712 and area>arear and area<6000:
                    posicion="m9"
                  elif x<214 and area>6000 and t!=0: 
                     posicion="a1"
                  elif x>=214 and x<428 and area>6000 : 
                     posicion="a2"
                  elif x>=428 and x<642 and area>6000 :
                    posicion="a3"
                  elif x>=642 and x<856 and area>6000 : 
                     posicion="a4"
                  elif x>=856 and x<1070 and area>6000 :
                    posicion="a5"
                  elif x>=1070 and x<1284 and area>6000 :
                    posicion="a6"
                  elif x>=1284 and x<1498 and area>7000 :
                    posicion="a7"
                  elif x>=1498 and x<1712 and area>6000 :
                    posicion="a8"
                  elif x>=1712 and area>7000 :
                    posicion="a9"
                  else:
                    posicion="0"
                  return posicion

def dibujov(mask,color): 
    contornos,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE) 
    for c in contornos : 
            area=cv2.contourArea(c) 
            if area>areav:      
                m=cv2.moments(c) 
                if(m["m00"]==0):m["m00"]=1 
                x=int(m["m10"]/m["m00"]) 
                y=int(m['m01']/m["m00"])
                nuevocontorno=cv2.convexHull(c) 
                global posicion
                print("area verde")
                print(area)
                if t==0 and x>214:
                  cv2.drawContours(imagennegra,[nuevocontorno],0,color,3)
                  if x<214 and area>arear and area<7000 and t!=0: 
                     posicion="m1"
                  elif x>=214 and x<428 and area>arear and area<6000: 
                     posicion="m2"
                  elif x>=428 and x<642 and area>arear and area<6000: 
                     posicion="m3"
                  elif x>=642 and x<856 and area>arear and area<6000: 
                     posicion="m4"
                  elif x>=856 and x<1070 and area>arear and area<6000:
                    posicion="m5"
                  elif x>=1070 and x<1284 and area>arear and area<6000:
                    posicion="m6"
                  elif x>=1284 and x<1498 and area>arear and area<6000:
                    posicion="m7"
                  elif x>=1498 and x<1712 and area>arear and area<6000:
                    posicion="m8"
                  elif x>=1712 and area>arear and area<6000:
                    posicion="m9"
                  elif x<214 and area>7000 and t!=0 : 
                     posicion="a1"
                  elif x>=214 and x<428 and area>6000 : 
                     posicion="a2"
                  elif x>=428 and x<642 and area>6000 :
                    posicion="a3"
                  elif x>=642 and x<856 and area>6000 : 
                     posicion="a4"
                  elif x>=856 and x<1070 and area>6000 :
                    posicion="a5"
                  elif x>=1070 and x<1284 and area>6000 :
                    posicion="a6"
                  elif x>=1284 and x<1498 and area>6000 :
                    posicion="a7"
                  elif x>=1498 and x<1712 and area>6000 :
                    posicion="a8"
                  elif x>=1712 and area>7000 :
                    posicion="a9"
                  else:
                    posicion="0"
                  return posicion
                if t!=0 :
                  cv2.drawContours(imagennegra,[nuevocontorno],0,color,3)
                  if x<214 and area>arear and area<7000 and t!=0: 
                     posicion="m1"
                  elif x>=214 and x<428 and area>arear and area<6000: 
                     posicion="m2"
                  elif x>=428 and x<642 and area>arear and area<6000: 
                     posicion="m3"
                  elif x>=642 and x<856 and area>arear and area<6000: 
                     posicion="m4"
                  elif x>=856 and x<1070 and area>arear and area<6000:
                    posicion="m5"
                  elif x>=1070 and x<1284 and area>arear and area<6000:
                    posicion="m6"
                  elif x>=1284 and x<1498 and area>arear and area<6000:
                    posicion="m7"
                  elif x>=1498 and x<1712 and area>arear and area<6000:
                    posicion="m8"
                  elif x>=1712 and area>arear and area<6000:
                    posicion="m9"
                  elif x<214 and area>7000 and t!=0 : 
                     posicion="a1"
                  elif x>=214 and x<428 and area>6000 : 
                     posicion="a2"
                  elif x>=428 and x<642 and area>6000 :
                    posicion="a3"
                  elif x>=642 and x<856 and area>6000 : 
                     posicion="a4"
                  elif x>=856 and x<1070 and area>6000 :
                    posicion="a5"
                  elif x>=1070 and x<1284 and area>6000 :
                    posicion="a6"
                  elif x>=1284 and x<1498 and area>6000 :
                    posicion="a7"
                  elif x>=1498 and x<1712 and area>6000 :
                    posicion="a8"
                  elif x>=1712 and area>7000 :
                    posicion="a9"
                  else:
                    posicion="0"
                  return posicion

#start of the main code loop
while True:
    
    ret,frame=cap.read()
    recorte=frame[480:480+1080]
    imagennegra=cv2.subtract(recorte,np.ones(recorte.shape,dtype=np.uint8)*40)
    if ret==True: 
        frameHSV=cv2.cvtColor(imagennegra,cv2.COLOR_BGR2HSV) 
        maskred1=cv2.inRange(frameHSV,redbajo1,redalto1) 
        maskred2=cv2.inRange(frameHSV,redbajo2,redalto2) 
        maskred=cv2.add(maskred1,maskred2) 
        maskredvis=cv2.bitwise_and(imagennegra,imagennegra,mask=maskred) 
        maskverd=cv2.inRange(frameHSV,verdebajo,vaerdealto)
        dibujo(maskred,(0,0,255 ))
        
        dibujov(maskverd,(0,255,50))
        rojo=dibujo(maskred,(0,0,255 ))
        verde=dibujov(maskverd,(0,255,50))
        cv2.line(imagennegra,(214,0),(214,1080),(0,255,255),2)
        cv2.line(imagennegra,(428,0),(428,1080),(0,255,255),2)
        cv2.line(imagennegra,(642,0),(642,1080),(0,255,255),2)
        cv2.line(imagennegra,(856,0),(856,1080),(0,255,255),2)
        cv2.line(imagennegra,(1070,0),(1070,1080),(0,255,255),2)
        cv2.line(imagennegra,(1284,0),(1284,1080),(0,255,255),2)
        cv2.line(imagennegra,(1498,0),(1498,1080),(0,255,255),2)
        cv2.line(imagennegra,(1712,0),(1712,1080),(0,255,255),2)
        cv2.imshow('normal',imagennegra)
        data=bus.read_byte(clientAddr)
        i=int(data)
        print(data)
        if i==1:
          print("t:")
          print(t)
          if verde!=None :
            print("verde de3tect")
            mp=str(verde)
            mp2="v"+mp
            mp2=str(mp2)
            i2cWrite(mp2)
            if (verde=="m1" or verde=="m2" or verde=="m3" or verde=="m4" or verde=="m5" or verde=="m6" or verde=="m7" or verde=="m8" or verde=="m9")and t==0 :
              print("paso 1 verde")
              vgn=1
            if (verde=="a1" or verde=="a2" or verde=="a3" or verde=="a4" or verde=="a5" or verde=="a6" or verde=="a7" or verde=="a8" or verde=="a9")and t==0 :
              print("paso 1 verde")
              t=1
              arear=19000
              areav=19000
              vgn=0
            if (verde=="a1" or verde=="a2" or verde=="a3" or verde=="a4" or verde=="a5" or verde=="a6" or verde=="a7" or verde=="a8" or verde=="a9")and t==2 or t==6 :
              print("paso fin verde")
              t=3
              vgn=0
            print(mp2)
          if rojo!=None:
            mp=str(rojo) 
            mp1="r"+mp
            mp1=str(mp1)
            print("rojo")
            print(mp1)
            i2cWrite(mp1)
            if (rojo=="a1" or rojo=="a2" or rojo=="a3" or rojo=="a4" or rojo=="a5" or rojo=="a6" or rojo=="a7" or rojo=="a8" or rojo=="a9" ) and t==0:
              print("paso 1 rojo")
              t=1
              arear=19000
              areav=19000
            if (rojo=="a1" or rojo=="a2" or rojo=="a3" or rojo=="a4" or rojo=="a5" or rojo=="a6" or rojo=="a7" or rojo=="a8" or rojo=="a9" ) and t==2:
              print("paso fin rojo")
              t=5
              
            print(w)
          elif i==1 and vgn==0 and t==2 and(rojo==None or rojo==0)and(verde==None or verde==0):
              print("solo cono alante")
              t=4
          elif i==1 and vgn==0 and t==0 and(rojo==None or rojo==0)and(verde==None or verde==0):
              t=6
              arear=19000
              areav=19000
              print("no detecto nada en la primera posicion")
        else:
            if i==0 and t==7:
              t=0
            if i==0 and t==1:
              t=2
              print("paso 2")
            if i==0 and t==3:
              t=0
              arear=2000
              areav=2000
            if i==0 and t==4:
              t=0
              print("pp")
              arear=2000
              areav=2000
            if i==0 and t==5:
              t=0
              arear=2000
              areav=2000
            print("esperando...")
        if cv2.waitKey(1)&0xFF==ord('b'):
            break 
#end of the program
cap.release() 
cv2.destroyAllWindows
