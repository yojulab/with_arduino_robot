#!/usr/bin/env python3
import serial
import pyautogui
from time import sleep

ser = serial.Serial('/dev/cu.wchusbserialfa130', 9600)

PTSceneString =[
"Hello", "Everyone", "This is", "Smart", "Glasses", "For PT"
]

ptScene = -1
while(True) :
    ptScene += 1
    value = PTSceneString[ptScene]
    print(value, ptScene,sep=" / ")
    #ser.write(value.encode())
    #ser.write('A'.encode())
    #ser.write(0x0100)
    ser.write(1)
    sleep(1)
    if(ptScene >= 5) :
        ptScene = 0
    
ser.close()
