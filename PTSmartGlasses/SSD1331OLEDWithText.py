#!/usr/bin/env python3
import serial
import pyautogui

ser = serial.Serial('/dev/cu.wchusbserialfa130', 9600)

PTSceneString =[
"Hello", "Everyone", "This is", "Smart", "Glasses", "For PT"
]

ptScene = -1
while(True) :
    readData = ser.read()  
    if(readData == b'+') :
        #print(readData)
        if(ptScene >= 5) :
            ptScene = 0
            pyautogui.press(['up','up','up','up','up']) 
        else :
            #pyautogui.click()
            pyautogui.press('down') 
            ptScene = ptScene + 1
        value = PTSceneString[ptScene]
        print(value, ptScene,sep=" / ")
        ser.write(value.encode())
    
ser.close()
