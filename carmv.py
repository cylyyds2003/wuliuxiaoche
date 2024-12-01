#实验名称�?2024物流机器人视觉代�?
#版本：v1.0
#日期�?2024.10
#翻译和注释：张恩�?
import sensor, image, time,pyb
from pyb import UART

#测试223
#127821121


#状态机 0为寻找二维码 1为物块识�? 2为靶心识�?
flag = 2
#颜色标志�? 0为红�? 1为绿�? 2为蓝�?
color_flag = 0
#颜色识别阈�?
thresholds = [(21, 39, 10, 62, 8, 127), # 红色阈�?
              (35, 75, -128, -4, -128, 127), # 绿色阈�?
              (17, 39, -128, 127, -128, 0)] # 蓝色阈�?

#寻找最大色块函数定�?
def find_max(blobs):
    max_size=0
    for blob in blobs:
        if blob[2]*blob[3] > max_size:
            max_blob=blob
            max_size = blob[2]*blob[3]
    return max_blob
#寻找最小半径的圆函数定�?
def find_min_circle(circles):
    min_radius = circles[0].r()
    min_circle = circles[0]
    for circle in circles:
        if circle.r() < min_radius:
            min_radius = circle.r()
            min_circle = circle
    return min_circle

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)

uart = UART(3,115200)#设置串口波特�?

clock = time.clock()

while(True):
    clock.tick()
    img = sensor.snapshot()
    img.erode(1, threshold = 1)

    if uart.any():
        data = uart.readchar()
        if data == 10:
            flag = 0
        elif data == 20:
            flag = 1
            color_flag = 0
        elif data == 21:
            flag = 1
            color_flag = 1
        elif data == 22:
            flag = 1
            color_flag = 2
        elif data == 30:
            flag = 2
            color_flag = 0
        elif data == 31:
            flag = 2
            color_flag = 1
        elif data == 32:
            flag = 2
            color_flag = 2


    if flag == 0:
        res = img.find_qrcodes() #寻找二维�?
        if len(res) > 0:
            img.draw_rectangle(res[0].rect())
            QRcode = res[0].payload()
            txbuff = bytearray([0xA5,int(QRcode[0]),int(QRcode[1]),int(QRcode[2]),int(QRcode[4]),int(QRcode[5]),int(QRcode[6]),0xFF])
            uart.write(txbuff)
            print(res[0].payload())
    elif flag == 1:
        if color_flag == 0:
            blobs = img.find_blobs([thresholds[0]],merge=True) # 0,1,2分别表示红，绿，蓝色�?
            if blobs:
                max_blob = find_max(blobs)
                txbuff = bytearray([0xA6,int(max_blob.cx()),int(max_blob.cy()),0xFF])
                uart.write(txbuff)
                img.draw_rectangle((max_blob.x(),max_blob.y(),max_blob.w(),max_blob.h()),color=(255,0,0))#用红色框出最大色�?
        elif color_flag == 1:
            blobs = img.find_blobs([thresholds[1]],merge=True) # 0,1,2分别表示红，绿，蓝色�?
            if blobs:
                max_blob = find_max(blobs)
                txbuff = bytearray([0xA6,int(max_blob.cx()),int(max_blob.cy()),0xFF])
                uart.write(txbuff)
                img.draw_rectangle((max_blob.x(),max_blob.y(),max_blob.w(),max_blob.h()),color=(255,0,0))#用红色框出最大色�?
        elif color_flag == 2:
            blobs = img.find_blobs([thresholds[2]],merge=True) # 0,1,2分别表示红，绿，蓝色�?
            if blobs:
                max_blob = find_max(blobs)
                txbuff = bytearray([0xA6,int(max_blob.cx()),int(max_blob.cy()),0xFF])
                uart.write(txbuff)
                img.draw_rectangle((max_blob.x(),max_blob.y(),max_blob.w(),max_blob.h()),color=(255,0,0))#用红色框出最大色�?
    elif flag == 2:
        if color_flag == 0:
            blobs = img.find_blobs([thresholds[0]],merge=True) # 0,1,2分别表示红，绿，蓝色�?
            if blobs:
                circles = img.find_circles(threshold = 5000, x_margin = 10, y_margin = 10, r_margin = 10,
                                               r_min = 20, r_max = 40, r_step = 2)
                if circles:
                    min_circle=find_min_circle(circles)
                    # 可以在这里对最小半径的圆min_circle进行其他操作，比如绘�?
                    img.draw_circle(min_circle.x(), min_circle.y(), min_circle.r(), color=(255, 0, 0))
                    txbuff = bytearray([0xA7,int(min_circle.x()),int(min_circle.y()),0xFF])
        elif color_flag == 1:
            blobs = img.find_blobs([thresholds[1]],merge=True) # 0,1,2分别表示红，绿，蓝色�?
            if blods:
                circles = img.find_circles(threshold = 5000, x_margin = 10, y_margin = 10, r_margin = 10,
                                               r_min = 20, r_max = 40, r_step = 2)
                if circles:
                    min_circle=find_min_circle(circles)
                    # 可以在这里对最小半径的圆min_circle进行其他操作，比如绘�?
                    img.draw_circle(min_circle.x(), min_circle.y(), min_circle.r(), color=(255, 0, 0))
                    txbuff = bytearray([0xA7,int(min_circle.x()),int(min_circle.y()),0xFF])
        elif color_flag == 2:
            blobs = img.find_blobs([thresholds[2]],merge=True) # 0,1,2分别表示红，绿，蓝色�?
            if blobs:
                circles = img.find_circles(threshold = 5000, x_margin = 10, y_margin = 10, r_margin = 10,
                                               r_min = 20, r_max = 40, r_step = 2)
                if circles:
                    min_circle=find_min_circle(circles)
                    # 可以在这里对最小半径的圆min_circle进行其他操作，比如绘�?
                    img.draw_circle(min_circle.x(), min_circle.y(), min_circle.r(), color=(255, 0, 0))
                    txbuff = bytearray([0xA7,int(min_circle.x()),int(min_circle.y()),0xFF])
    #print(clock.fps())
    #img.draw_circle(int(mean_x), int(mean_y), int(mean_radius), color = (255, 0, 0))
