# -*- coding: utf-8 -*-
import http.client
import urllib
import base64
import os
import sys
import cv2
import numpy as np
import json
import math
import time
import serial

def send_emotion(emo):
    #flag = bytes('a','utf-8')
    #ser.write(flag)
    if emo == 'anger':
        time.sleep(0.5)
        ser.write(b'a')
        time.sleep(1)
    elif emo == 'contempt':
        time.sleep(0.5)
        ser.write(b'a')
        time.sleep(1)
    elif emo == 'disgust':
        time.sleep(0.5)
        ser.write(b'a')
        time.sleep(1)
    elif emo == 'fear':
        time.sleep(0.5)
        ser.write(b'a')
        time.sleep(1)
    elif emo == 'happiness':
        time.sleep(0.5)
        ser.write(b'b')
        time.sleep(1)
    elif emo == 'neutral':
        time.sleep(0.5)
        ser.write(b'c')
        time.sleep(1)
    elif emo == 'sadness':
        time.sleep(0.5)
        ser.write(b'd')
        time.sleep(1)
    elif emo == 'surprise':
        time.sleep(0.5)
        ser.write(b'e')
        time.sleep(1)





def get_emotion(file_path, headers):
    try:
        conn = http.client.HTTPSConnection('api.projectoxford.ai')
        conn.request("POST", "/emotion/v1.0/recognize?",
                     open(file_path, 'rb'), headers)
        response = conn.getresponse()
        data = response.read()
        conn.close()
        return data
    except Exception as e:
        print("[Errno {0}] {1}".format(e.errno, e.strerror))
        print(e.message)

def display_expression(data,img):
    font = cv2.FONT_HERSHEY_PLAIN
    text = "test cyber"
    font_size = 1
    data = json.loads(data.decode('utf-8'))
    for face in data:
        f_rec  =  face['faceRectangle']
        width  =  f_rec['width']
        height =  f_rec['height']
        left   =  f_rec['left']
        top    =  f_rec['top']
        f_rec  =  face['scores']
        f_rec = sorted(f_rec.items(), key=lambda x:x[1],reverse = True)
        # draw a rectangle around the face
        cv2.rectangle(img,(left,top),(left+width,top+height),(130,130,130),2) 
        # display the resulting frame (img,upper left point,size,color,thickness)
        cv2.rectangle(img,(left+width,top),(left+width+150,top+50),(130,130,130),-1) 

        emo = f_rec[0][0]
        send_emotion(emo)
        
        
        for i in range(0,5):
            #表情の点数を数字として取り出す
            val = round(f_rec[i][1],3)
            #表情の名称を取り出す anger,contempt,disgust,fear,happiness,neutral,sadness,and surprise
            emo = f_rec[i][0]
            cv2.rectangle(img,(left+width,top+10*i),(left+width+int(val*150),top+10*(i+1)),(180,180,180),-1)
            cv2.putText(img, emo+" "+str(val),(left+width,top+10*(i+1)),font, font_size,(255,255,255),1)
        

if __name__ == '__main__':
    ser = serial.Serial("COM3", 9600, timeout = 1)
    #with serial.Serial("COM3", 9600, timeout = 1) as ser:

    with open('api_key.txt', 'r') as f:
        key = f.read().rstrip('\n')
    f.close()
    headers = {
        'Content-Type': 'application/octet-stream',
        'Ocp-Apim-Subscription-Key': key,
    }
    #API keyを４つ取得してkey1,key2...とやって、headers1,headers2...として時間指定
    #1秒ごとに違うAPIをリクエストする
    cap = cv2.VideoCapture(0) 

    while True:
        ret, frame = cap.read()
        cv2.imshow('frame',frame)
        k = cv2.waitKey(1)
        path = "emotion.jpg"
        if k == ord('q'):
            break
        
        
        if k == ord('s'):
            cv2.imwrite(path,frame)
            data = get_emotion(path, headers)
            img = cv2.imread(path, -1)
            display_expression(data, img)
            cv2.imshow('image', img)
            cv2.imwrite(path, img)
            cv2.waitKey(7000)
            cv2.destroyAllWindows()
            
        
        

    cap.release()
    cv2.destroyAllWindows()

    ser.close()