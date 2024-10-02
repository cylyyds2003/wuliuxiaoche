#include "stdio.h"
#include "text.h"
#include "lcd.h"
#include "ziku.h"
#include "code.h"

//�����Ǵ�Ŷ�ά��ģ�鴮��ͨ�ų�ʼ���Լ������ά�����ݵĴ���

u8 Code_RxPacket[8]={0};
u8 Code_TxPacket[7];

u8 Code_RxFlag;

void Code_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitTStructure;
	NVIC_InitTypeDef NVIC_InitStruvture;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2); 
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART2); 

	USART_InitTStructure.USART_BaudRate = 115200;
	USART_InitTStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitTStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitTStructure.USART_Parity = USART_Parity_No;
	USART_InitTStructure.USART_StopBits = USART_StopBits_1;
	USART_InitTStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART2, &USART_InitTStructure);
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	
	NVIC_InitStruvture.NVIC_IRQChannel = USART2_IRQn;
	NVIC_InitStruvture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruvture);

	USART_Cmd(USART2, ENABLE);
}

//����ע�͸�openmv.c����Ĳ�࣬����ȥ����
void Code_SendByte(u8 Byte)
{
	USART_SendData(USART2, Byte);
	while(USART_GetFlagStatus(USART2,USART_FLAG_TXE) == RESET);
}


void Code_SendArray(u8 *Array, s16 Length)
{
	u16 i;
	for (i = 0; i < Length; i++)
	{
		Code_SendByte(Array[i]);
	}

}


void Code_SendPacket(void)
{
	Code_SendArray(Code_RxPacket, 7);
}

void Code_Packet_Init(void)
{
	Code_TxPacket[0] = Code_RxPacket[0];
	Code_TxPacket[1] = Code_RxPacket[1];
	Code_TxPacket[2] = Code_RxPacket[2];
	Code_TxPacket[3] = Code_RxPacket[3];
	Code_TxPacket[4] = Code_RxPacket[4];
	Code_TxPacket[5] = Code_RxPacket[5];
	Code_TxPacket[6] = Code_RxPacket[6];
	
}

u8 Code_GetRxFlag(void)
{
	if(Code_RxFlag == 1)
	{
		Code_RxFlag = 0;
		return 1;
	}
	
	return 0;

}

void USART2_IRQHandler(void) 
{
	static u8 pRxPacket = 0;
	if(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == SET)
	{
		u8 RxData = USART_ReceiveData(USART2);
		Code_RxPacket[pRxPacket] = RxData;
		pRxPacket ++;
		if(pRxPacket >=8)
		{
			pRxPacket = 0;
			Code_RxFlag = 1;
		}
		USART_ClearFlag(USART2, USART_FLAG_RXNE);
	}
}

//������������������ݷ���100�Σ�����д��������
void Identifysend(int x)
{
	int i;
	if(x == 1)
	{	
		for(i = 0; i <= 100; i ++)
		{
			Code_SendByte(0x01);
		}
	}
	if(x == 2)
	{
		for(i = 0; i <= 100; i ++)
		{
			Code_SendByte(0x02);
		}
	}
	if(x == 3)
	{
		for(i = 0; i <= 100; i ++)
		{
			Code_SendByte(0x03);
		}
	}
	if(x == 4)
	{
		for(i = 0; i <= 100; i ++)
		{
			Code_SendByte(0x04);
		}
	}
	if(x == 5)
	{
		for(i = 0; i <= 100; i ++)
		{
			Code_SendByte(0x05);
		}
	}
	if(x == 6)
	{
		for(i = 0; i <= 100; i ++)
		{
			Code_SendByte(0x06);
		}
	}
}




