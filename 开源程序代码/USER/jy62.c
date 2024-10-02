#include "string.h"
#include "text.h"
#include "lcd.h"
#include "jy62.h"

//这里是存放摄像头串口通信初始化以及处理数据的代码
//为什么叫JY62呢，原本是想用陀螺仪的，陀螺仪效果太差啦就去掉了，纪念一下就懒得改名了
//下面改用V831摄像头识别中间正方形了

u8 v831_y[3];		//数组存放V831的数据
u8 v831_RxFlag; //V831串口接受标志位

//jy62初始化
void jy62_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitTStructure;
	NVIC_InitTypeDef NVIC_InitStruvture;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOG,GPIO_PinSource14,GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOG,GPIO_PinSource9,GPIO_AF_USART6); 

	USART_InitTStructure.USART_BaudRate = 115200;
	USART_InitTStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitTStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitTStructure.USART_Parity = USART_Parity_No;
	USART_InitTStructure.USART_StopBits = USART_StopBits_1;
	USART_InitTStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART6, &USART_InitTStructure);

	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE);
	
	NVIC_InitStruvture.NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStruvture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruvture);

	USART_Cmd(USART6, ENABLE);
}

void USART6_IRQHandler(void) 
{
  static u8 RxState = 0;
	static u8 pRxPacket = 0;
	if(USART_GetFlagStatus(USART6, USART_FLAG_RXNE) == SET)
	{
		u8 RxData = USART_ReceiveData(USART6);
		
		//等待接受数据包帧头
		if (RxState == 0)	 
		{
			if (RxData == 0x03)
			{
				RxState = 1;
				pRxPacket = 0;
			}
		}
		//接受到数据包了，处理数据包
		else if (RxState == 1)
		{	
			v831_y[pRxPacket] = RxData;	
			pRxPacket ++;
			if(pRxPacket >=2)
			{
				RxState = 2;
			}
			
		}
		//数据接受完成
		else if (RxState == 2)
		{
			if (RxData == 0xFE)
			{
//			中断里面不要放显示，里面有delay然后卡死程序的，省赛的时候卡死一次，吃过一次亏
//			LCD_ShowNumber(200, 30, v831_y[1], 24, MAGENTA);
//			LCD_ShowNumber(200, 80, v831_y[0], 24, MAGENTA);
//			LCD_ShowNumber(200, 170, (v831_y[1] - v831_y[0]), 24, MAGENTA);
				RxState = 0;
				v831_RxFlag = 1;
			}
		}
		USART_ClearFlag(USART6, USART_FLAG_RXNE);
	}
}

/**
 * @brief 给V831发送字节
 * 
 * 给V831发送字节，用来调试的
 * 
 * @param Byte 需要发送的字节
 *
 */
void v831_SendByte(u8 Byte)
{
	USART_SendData(USART6, Byte);
	while(USART_GetFlagStatus(USART6,USART_FLAG_TXE) == RESET);
	
}

