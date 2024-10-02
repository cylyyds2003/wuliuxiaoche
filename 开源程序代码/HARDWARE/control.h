#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "stm32f4xx.h"                  // Device header
#include "zhi.h"
extern uint32_t set_speed;         // ����ٶ����� ��λΪ0.1rad/sec
extern uint32_t step_accel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern uint32_t step_decel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern int acr;

extern uint32_t sigan_speed;         // ����ٶ����� ��λΪ0.1rad/sec
extern uint32_t sigan_accel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern uint32_t sigan_decel;         // ���ٶ� ��λΪ0.1rad/sec^2
extern uint32_t heny_speed;         // ����ٶ����� ��λΪ0.1rad/sec  //240
extern uint32_t heny_accel;       // ���ٶ� ��λΪ0.1rad/sec^2    //40
extern uint32_t heny_decel;         // ���ٶ� ��λΪ0.1rad/sec^2  //30

void control(void);
void fancheng(void);
#endif

