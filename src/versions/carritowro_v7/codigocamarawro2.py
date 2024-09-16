import cv2 
import numpy as np  
import serial  
import time 
 
ser=serial.Serial('/dev/ttyUSB0',9600,timeout=1) 
time.sleep(2) 
if not ser.isOpen(): 
    ser.open() 
    print('com3 is open', ser.isOpen()) 
rojo=0 
verde=0 
def dibujo(mask,color): 
    contornos,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE) 
    for c in contornos : 
            area=cv2.contourArea(c) 
            if area>15000: 
                 #print("rojo encontrado") 
 #               ser.write(b"rojo\n") 
                 
                m=cv2.moments(c) 
                if(m["m00"]==0):m["m00"]=1 
                x=int(m["m10"]/m["m00"]) 
                y=int(m['m01']/m["m00"]) 
                cv2.circle(frame,(x,y),7,(0,255,0),-1) 
                font=cv2.FONT_HERSHEY_SIMPLEX 
                cv2.putText(frame,'{},{}'.format(x,y),(x+10,y),font,0.75,(0,255,0),1,cv2.LINE_AA) 
                nuevocontorno=cv2.convexHull(c) 
                cv2.drawContours(frame,[nuevocontorno],0,color,3) 
                global posicion 
                if x<=640: 
                     posicion=1 
                if x>640: 
                     posicion=2  
                return posicion 
def dibujov(mask,color): 
    contornos,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE) 
    for c in contornos : 
            area=cv2.contourArea(c) 
            if area>15000: 
                #print("verde encontrado") 
   #             ser.write(b"verde\n")              
                m=cv2.moments(c) 
                if(m["m00"]==0):m["m00"]=1 
                x=int(m["m10"]/m["m00"]) 
                y=int(m['m01']/m["m00"]) 
                cv2.circle(frame,(x,y),7,(0,255,0),-1) 
                font=cv2.FONT_HERSHEY_SIMPLEX 
                cv2.putText(frame,'{},{}'.format(x,y),(x+10,y),font,0.75,(0,255,0),1,cv2.LINE_AA) 
                nuevocontorno=cv2.convexHull(c) 
                cv2.drawContours(frame,[nuevocontorno],0,color,3) 
                global posicion 
                if x<=640: 
                     posicion=1 
                if x>640: 
                     posicion=2 
                return posicion 
def dibujom(mask,color): 
    contornos,_=cv2.findContours(mask,cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE) 
    for c in contornos : 
            area=cv2.contourArea(c) 
            if area>6000: 
                print("morado encontrado") 
            #    ser.write(b"verde\n") 
                 
                m=cv2.moments(c) 
                if(m["m00"]==0):m["m00"]=1 
                x=int(m["m10"]/m["m00"]) 
                y=int(m['m01']/m["m00"]) 
                cv2.circle(frame,(x,y),7,(0,255,0),-1) 
                font=cv2.FONT_HERSHEY_SIMPLEX 
                cv2.putText(frame,'{},{}'.format(x,y),(x+10,y),font,0.75,(0,255,0),1,cv2.LINE_AA) 
                nuevocontorno=cv2.convexHull(c) 
                cv2.drawContours(frame,[nuevocontorno],0,color,3) 
cap=cv2.VideoCapture(0) 
redbajo1=np.array([0,100,20],np.uint8) 
redalto1=np.array([5,255,255],np.uint8) 
redbajo2=np.array([175,100,20],np.uint8) 
redalto2=np.array([179,255,255],np.uint8) 
verdebajo=np.array([35,100,20],np.uint8) 
vaerdealto=np.array([80,255,255],np.uint8) 
#moradobajo=np.array([145,100,20],np.uint8) 
#moradoalto=np.array([155,255,255],np.uint8) 
while True: 
    ret,frame=cap.read() 
    if ret==True: 
        frameHSV=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV) 
        maskred1=cv2.inRange(frameHSV,redbajo1,redalto1) 
        maskred2=cv2.inRange(frameHSV,redbajo2,redalto2) 
        maskred=cv2.add(maskred1,maskred2) 
        maskredvis=cv2.bitwise_and(frame,frame,mask=maskred) 
        maskverd=cv2.inRange(frameHSV,verdebajo,vaerdealto) 
 #       maskmord=cv2.inRange(frameHSV,moradobajo,moradoalto) 
        dibujo(maskred,(0,0,255 )) 
        dibujov(maskverd,(0,255,50))
  #      dibujom(maskmord,(255,0,255))
        rojo=dibujo(maskred,(0,0,255 ))
        verde=dibujov(maskverd,(0,255,50))
        if rojo!= None:
            mip=str(rojo) 
            mip1="rojo"+mip+"\n"
            print(mip1)
            ser.write(mip1.encode('ascii'))
            time.sleep(1)
            rojo=None
        if verde!= None:
            mip=str(verde) 
            mip1="verde"+mip+"\n"
            print(mip1)
            ser.write(mip1.encode('ascii'))
            time.sleep(1)
            verde=None
        cv2.imshow('mipene1',frame) 
        if cv2.waitKey(1)&0xFF==ord('b'):
            cap.release() 
            cv2.destroyAllWindows
            break 

