#ifndef __APP_H
#define __APP_H
<<<<<<< HEAD
void ApplicationProgram_main(void);
#endif
/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "data.h"
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include "separate_button.h"
#include "pid.h"
#include "usart.h"

/* ˽�к궨�� ----------------------------------------------------------------*/
#define SERVO_NUM_MAX 6  

#define SERVO_CH1   0
#define SERVO_CH2   1
#define SERVO_CH3   2
#define SERVO_CH4   3
#define SERVO_CH5   4
#define SERVO_CH6   5

#define SERVO_CLAW      SERVO_CH1 //��צ���
#define SERVO_ARM3      SERVO_CH2 //��3�����������צ�ı�
#define SERVO_ARM2      SERVO_CH3 //��2������м�ı�
#define SERVO_ARM1      SERVO_CH4 //��1������������̵ı�
#define SERVO_ROTARY    SERVO_CH5 //������ת���
#define SERVO_wuliaopan SERVO_CH6 //������ת���


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
#define search_red 0x20             //�Һ�ɫ����
#define search_green 0x21           //����ɫ����
#define search_blue 0x22            //����ɫ����
#define search_red_circles 0x30     //�Һ�Ȧ����ͬ
#define search_green_circles 0x31
#define search_blue_circles 0x32

#define red 0
#define green 1
#define bule 2  


/*��������*/
extern uint8_t first_pick[3];
extern uint8_t second_pick[3];        /**��Щ�Ǻ��㷨ͨ���õı���*/
extern uint8_t stuff_position_x;
extern uint8_t stuff_position_y;
extern uint8_t circles_x;
extern uint8_t circles_y;

extern int32_t one,two,three,four;    
extern uint8_t state;
extern float yaw;

/*��������*/
uint8_t judge(void);
void forward_hanshu(int16_t distance,float set_angle);//ǰ���ĺ���
void back_hanshu(int16_t distance,float set_angle); //���˵ĺ���
void left_hanshu(int16_t distance,float set_angle); //����ĺ���
void right_hanshu(int16_t distance,float set_angle);//���ҵĺ���
void stop_hanshu(uint16_t stop_time,float	set_angle,uint8_t x,uint8_t y);//ֹͣ�ĺ���

void first_get_from_tray(void);  /*��ԭ����ȡ����*/
void first_work_in_rough_area(void);  /*�����Ϸŵ��ּӹ�����ȡ����*/
void first_work_in_temporary_area(void);/*�����Ϸŵ��ݴ���*/
void first_path(void);   /*���-->ԭ����-->�ּӹ���-->�ݴ���*/

void second_get_from_tray(void);
void second_work_in_rough_area(void);  /*�����Ϸŵ��ּӹ�����ȡ����*/
void second_work_in_temporary_area(void);/*�����Ϸŵ��ݴ���*/
void second_path(void);
=======








void ApplicationProgram_main(void);


#endif
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
