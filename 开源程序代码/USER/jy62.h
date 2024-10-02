#ifndef __JY62_H
#define __JY62_H
#include "stm32f4xx.h"                  // Device header

extern u8 v831_y[3];
extern u8 v831_RxFlag;

void jy62_init(void);
void v831_SendByte(u8 Byte);
	

#endif
