#ifndef __APP_H
#define __APP_H
<<<<<<< HEAD
void ApplicationProgram_main(void);
#endif
/* 引入头文件 ----------------------------------------------------------------*/
#include "data.h"
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include "separate_button.h"
#include "pid.h"
#include "usart.h"

/* 私有宏定义 ----------------------------------------------------------------*/
#define SERVO_NUM_MAX 6  

#define SERVO_CH1   0
#define SERVO_CH2   1
#define SERVO_CH3   2
#define SERVO_CH4   3
#define SERVO_CH5   4
#define SERVO_CH6   5

#define SERVO_CLAW      SERVO_CH1 //手爪舵机
#define SERVO_ARM3      SERVO_CH2 //臂3舵机，靠近手爪的臂
#define SERVO_ARM2      SERVO_CH3 //臂2舵机，中间的臂
#define SERVO_ARM1      SERVO_CH4 //臂1舵机，靠近底盘的臂
#define SERVO_ROTARY    SERVO_CH5 //底盘旋转舵机
#define SERVO_wuliaopan SERVO_CH6 //底盘旋转舵机


#define ID1 1
#define ID2 2
#define ID3 3
#define ID4 4

#define L 0.0418879f

#define forward 1
#define back 2
#define left 3
#define right 4
#define stop 5
#define zuozhuan 6
#define youzhuan 7



#define ready_to_scan_QRcode 0x10
#define search_red 0x20             //找红色物料
#define search_green 0x21           //找绿色物料
#define search_blue 0x22            //找蓝色物料
#define search_red_circles 0x30     //找红圈，下同
#define search_green_circles 0x31
#define search_blue_circles 0x32

#define red 0
#define green 1
#define bule 2  


/*变量声明*/
extern uint8_t first_pick[3];
extern uint8_t second_pick[3];        /**这些是和算法通信用的变量*/
extern uint8_t stuff_position_x;
extern uint8_t stuff_position_y;
extern uint8_t circles_x;
extern uint8_t circles_y;

extern int32_t one,two,three,four;    
extern uint8_t state;
extern float yaw;

/*函数声明*/
uint8_t judge(void);
void forward_hanshu(int16_t distance,float set_angle);//前进的函数
void back_hanshu(int16_t distance,float set_angle); //后退的函数
void left_hanshu(int16_t distance,float set_angle); //向左的函数
void right_hanshu(int16_t distance,float set_angle);//向右的函数
void stop_hanshu(uint16_t stop_time,float	set_angle,uint8_t x,uint8_t y);//停止的函数

void first_get_from_tray(void);  /*从原料区取物料*/
void first_work_in_rough_area(void);  /*把物料放到粗加工区再取回来*/
void first_work_in_temporary_area(void);/*把物料放到暂存区*/
void first_path(void);   /*起点-->原料区-->粗加工区-->暂存区*/

void second_get_from_tray(void);
void second_work_in_rough_area(void);  /*把物料放到粗加工区再取回来*/
void second_work_in_temporary_area(void);/*把物料放到暂存区*/
void second_path(void);
=======








void ApplicationProgram_main(void);


#endif
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
