#ifndef __CONTROL_H__
#define __CONTROL_H__
#include "stm32f4xx.h"                  // Device header
#include "zhi.h"
extern uint32_t set_speed;         // 最大速度设置 单位为0.1rad/sec
extern uint32_t step_accel;         // 加速度 单位为0.1rad/sec^2
extern uint32_t step_decel;         // 减速度 单位为0.1rad/sec^2
extern int acr;

extern uint32_t sigan_speed;         // 最大速度设置 单位为0.1rad/sec
extern uint32_t sigan_accel;         // 加速度 单位为0.1rad/sec^2
extern uint32_t sigan_decel;         // 减速度 单位为0.1rad/sec^2
extern uint32_t heny_speed;         // 最大速度设置 单位为0.1rad/sec  //240
extern uint32_t heny_accel;       // 加速度 单位为0.1rad/sec^2    //40
extern uint32_t heny_decel;         // 减速度 单位为0.1rad/sec^2  //30

void control(void);
void fancheng(void);
#endif

