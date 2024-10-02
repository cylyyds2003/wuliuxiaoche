#ifndef __Motor_H
#define __Motor_H
#include "stm32f4xx.h"                  // Device header
#include "math.h"

typedef struct
{
	 uint8_t run_state;    //�����ת״̬
	 uint8_t dir ;         //�����ת����
	 int step_delay;   //�¸��������ڣ�ʱ����������ʱΪ���ٶ�
	 int decel_start;  //��������λ��
	 int decel_val;    //���ٽ׶β���
	 int min_delay;    //��С�������ڣ�����ٶȣ������ٶε��ٶȣ�
	 int accel_count;  //���ٽ׶μ���ֵ
}speedRampData;


#define TRUE     1
#define FALSE    0

/*����ٶȾ����е��ĸ�״̬*/
#define STOP              0 // ֹͣ״̬
#define ACCEL             1 // ����״̬
#define DECEL             2 // ����״̬
#define RUN               3 // ����״̬

#define TIM_PRESCALER      64
#define T1_FREQ            (SystemCoreClock/(TIM_PRESCALER+1))     //��ʱ��Ƶ��

/*�����Ȧ����*/
#define STEP_ANGLE				1.8									//��������Ĳ���� ��λ����
#define FSPR              6400        //���������Ȧ����

#define MICRO_STEP        32         				//ϸ����ϸ���� 
#define SPR               (FSPR*MICRO_STEP)  //16ϸ�ֵĲ���

//��ѧ����������MSD_MOVE�����ļ򻯼���
#define ALPHA             ((float)(2*3.14159/SPR))       // ��= 2*pi/spr    
#define A_T_x10           ((float)(10*ALPHA*T1_FREQ))
#define T1_FREQ_148       ((float)((T1_FREQ*0.676)/10)) // 0.69Ϊ�������ֵ(������̣��ĵ�����д)
#define A_SQ              ((float)(2*100000*ALPHA)) 
#define A_x200            ((float)(200*ALPHA))
    
void MOTOR_Move(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);

extern void speed_decision(void);	
extern uint8_t  motor_sta;//���״̬
extern uint8_t  sigan_sta;//���״̬

void go(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
void back(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
void left(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
void right(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
void turn_left(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
void turn_right(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
	
void rise(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);
void down(int32_t step, uint32_t accel, uint32_t decel, uint32_t speed);

void bazi1(u8 index,u8 i);
void bazi2(u8 index,u8 i);
extern int act[];
#endif

