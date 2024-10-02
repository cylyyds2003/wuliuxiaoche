#ifndef __ZHI_H__
#define __ZHI_H__
#include "stm32f4xx.h"           // Device header
#include "key.h"
#include "lcd.h"
#include "code.h"
#include "ziku.h"
#include "text.h"
#include "jy62.h"
#include "duoji.h"
#include "openmv.h"
#include "delay.h"
#include "motor.h"
#include "motor_init.h"

/*//��̨  ����  ����
����ƫ������
��Сƫ��ת��
*/
#define  OUT     222  
#define  IN      94
/*//ת��  �� �� ��  
������ʱ��  ��С˳ʱ��
*/
#define  LV      259//259
#define  HONG    141//141
#define  LAN      22//22
/*//צ��  �� �� ץ   
���� �ս�
��С �ɿ�
*/
#define  ZKAI      30//������Ӱ
#define  OPEN      70//70
#define  DROP      139
#define  GRAB      156

/*
//DXIANΪƽ�е���ת��ת
//JULIΪ�������
*/
#define  DXIAN      -1
#define  JULI       88
/*ƽ�е���ת��ת*/
#define  PXING      -1
/*
�� ����
�� ��С
�� ����
�� ��С
*/
//�ж�2 ���Ű��ӵ�  Ŀ��ֵ
#define  CX2      63//60
#define  CY2      72//74
//�ж�3 ��������  Ŀ��ֵ
#define  CX3      63//65
#define  CY3      71//69

void duixian(void);
void control(void);
void jiaqu(int i);
void jiaqu2(int i);
void fangzhi(int i);
void fangzhi2(int i);
void PanDuan2(u8 i);
void PanDuan(u8 i);
void PanDuan3(u8 i);

void bazi1(u8 index,u8 i);
void bazi2(u8 index,u8 i);

void move(int mubiao,int xianzai);
void pingxing(void);

void code_again(void);

extern uint32_t set_speed;          // ����ٶ����� ��λΪ0.1rad/sec
extern uint32_t step_accel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern uint32_t step_decel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern int acr;

extern uint32_t sigan_speed;         // ����ٶ����� ��λΪ0.1rad/sec
extern uint32_t sigan_accel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern uint32_t sigan_decel;         // ���ٶ� ��λΪ0.1rad/sec^2

/**********************************����****************************************************/

void code_again_back(void);
void PanDuan2_fancheng(u8 i);
void jiaqu_maduo(int i);
void PanDuan2_dcwl(u8 i);
#endif





