#include "stdio.h"
#include "text.h"
#include "lcd.h"
#include "ziku.h"
#include "duoji.h"
#include "delay.h"
#include "motor.h"
#include "code.h"
#include <math.h>

//����Ҳ�Ǵ������ͷ����ͨ�ų�ʼ���Լ��������ݵĴ���

u8 Openmv_Column_RxPacket[4]; //���openmv�����������ϵ�����
u8 Openmv_Column_TxPacket[4];
u8 Openmv_Annular_RxPacket[4];//���openmv��������ɫ��������
u8 Openmv_Annular_TxPacket[4];

u8 duixian_y[3];

u32 middle_y;

u8 Column_RxFlag;
u8 Annular_RxFlag;

//openmv���ڳ�ʼ��
void Openmv_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitTStructure;
	NVIC_InitTypeDef NVIC_InitStruvture;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//TX
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//RX
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_USART3); 
	GPIO_PinAFConfig(GPIOB,GPIO_PinSource11,GPIO_AF_USART3); 
	
	USART_InitTStructure.USART_BaudRate = 115200;
	USART_InitTStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitTStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_InitTStructure.USART_Parity = USART_Parity_No;
	USART_InitTStructure.USART_StopBits = USART_StopBits_1;
	USART_InitTStructure.USART_WordLength = USART_WordLength_8b;
	USART_Init(USART3, &USART_InitTStructure);
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

	NVIC_InitStruvture.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStruvture.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruvture.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStruvture.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruvture);
	
	USART_Cmd(USART3, ENABLE);
}

void USART3_IRQHandler(void) 
{
	static u8 RxState = 0;
	static u8 pRxPacket = 0;
	if(USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == SET)
	{
		u8 RxData = USART_ReceiveData(USART3);
		
		//�ȴ��������ݰ�֡ͷ
		if (RxState == 0)	 
		{
			if (RxData == 0xFF)//����֡ͷ
			{
				RxState = 1;
				pRxPacket = 0;
			}
			if (RxData == 0x01)//ɫ��֡ͷ
			{
				RxState = 3;
				pRxPacket = 0;
			}
			if (RxData == 0x03)//����֡ͷ
			{
				RxState = 5;
				pRxPacket = 0;
			}
		}
		
		//���ܵ����ݰ��ˣ��������ݰ�
		else if (RxState == 1)
		{	
			
			Openmv_Column_RxPacket[pRxPacket] = RxData;	
			pRxPacket ++;
			if(pRxPacket >=3)
			{
				RxState = 2;
			}
			
		}
		else if (RxState == 3)
		{	
			
			Openmv_Annular_RxPacket[pRxPacket] = RxData;	
			pRxPacket ++;
			if(pRxPacket >=3)
			{
				RxState = 4;
			}
			
		}
		else if (RxState == 5)
		{	
			
			duixian_y[pRxPacket] = RxData;	
			pRxPacket ++;
			if(pRxPacket >=2)
			{
				RxState = 6;
			}
			
		}
		
		//���ݽ������
		else if (RxState == 2)
		{
			if (RxData == 0xFE)
			{
//			�ж����治Ҫ����ʾ��������delayȻ��������ģ�ʡ����ʱ����һ�Σ��Թ�һ�ο�
//			LCD_ShowNumber(230, 5, Openmv_Column_RxPacket[0]+ Openmv_Column_RxPacket[1], 24, BLUE);
//			LCD_ShowNumber(230, 25, Openmv_Column_RxPacket[2]+ Openmv_Column_RxPacket[3], 24, BLUE);
				RxState = 0;
				Column_RxFlag = 1;
			}
		}
		else if (RxState == 4)
		{
			if (RxData == 0xFE)
			{
//			�ж����治Ҫ����ʾ��������delayȻ��������ģ�ʡ����ʱ����һ�Σ��Թ�һ�ο�
//			LCD_ShowNumber(280, 1, Openmv_Annular_RxPacket[0] + Openmv_Annular_RxPacket[1], 24, MAGENTA);
//			LCD_ShowNumber(280, 30, Openmv_Annular_RxPacket[2]+ Openmv_Annular_RxPacket[3], 24, MAGENTA);
				RxState = 0;
				Annular_RxFlag = 1;
			}
		}
		else if (RxState == 6)
		{
			if (RxData == 0xFE)
			{
//			LCD_ShowNumber(200, 30, duixian_y[1], 24, MAGENTA);
//			LCD_ShowNumber(200, 80, duixian_y[0], 24, MAGENTA);
//			LCD_ShowNumber(200, 170, (duixian_y[1] - duixian_y[0]), 24, MAGENTA);
//      LCD_ShowNumber(280, 170, ((duixian_y[1] + duixian_y[0])/2), 24, BLUE);
				RxState = 0;
				Column_RxFlag = 1;
			}
		}
		USART_ClearFlag(USART3, USART_FLAG_RXNE);
	}
}

/**
 * @brief ��openmv�����ֽ�
 * 
 * ��openmv�����ֽڣ������л�ģʽ
 * 
 * @param Byte ��Ҫ���͵��ֽ�
 *
 */
void Openmv_SendByte(u8 Byte)
{
	USART_SendData(USART3, Byte);
	while(USART_GetFlagStatus(USART3,USART_FLAG_TXE) == RESET);
}

/**
 * @brief ��openmv��������
 * 
 * ��openmv��������
 * 
 * @param Array  ��Ҫ���͵�����
 * @param Length ��Ҫ���͵����鳤��
 */
void Openmv_SendArray(u8 *Array, s16 Length)
{
	u16 i;
	for (i = 0; i < Length; i++)
	{
		Openmv_SendByte(Array[i]);
	}

}

/**
 * @brief �ѽ��ܵ�openmv�������ݷ��ͳ�ȥ
 * 
 * �ѽ��ܵ�openmv�������ݷ��ͳ�ȥ����������
 * 
 */
void Openmv_Column_SendPacket(void)
{
	Openmv_SendArray(Openmv_Column_TxPacket, 4);
}

/**
 * @brief �ѽ��ܵ�openmvɫ�����ݷ��ͳ�ȥ
 * 
 * �ѽ��ܵ�openmvɫ�����ݷ��ͳ�ȥ����������
 * 
 */
void Openmv_Annular_SendPacket(void)
{
	Openmv_SendArray(Openmv_Annular_TxPacket, 4);
}

/**
 * @brief ��ʼ��ɫ�����͵İ�
 * 
 * ��������
 * 
 */
void Packet_Annular_Init(void)
{
	Openmv_Annular_TxPacket[0] = Openmv_Annular_RxPacket[0];
	Openmv_Annular_TxPacket[1] = Openmv_Annular_RxPacket[1];
	Openmv_Annular_TxPacket[2] = Openmv_Annular_RxPacket[2];
	Openmv_Annular_TxPacket[3] = Openmv_Annular_RxPacket[3];
	
}

/**
 * @brief ��ʼ�����Ϸ��͵İ�
 * 
 * ��������
 * 
 */
void Packet_Column_Init(void)
{
	Openmv_Column_TxPacket[0] = Openmv_Column_RxPacket[0];
	Openmv_Column_TxPacket[1] = Openmv_Column_RxPacket[1];
	Openmv_Column_TxPacket[2] = Openmv_Column_RxPacket[2];
	Openmv_Column_TxPacket[3] = Openmv_Column_RxPacket[3];
	
}

/**
 * @brief ���ϱ�־λ����
 * 
 * ���ܵ����ϵ����ݺ󣬱�־λ����
 * 
 */
u8 Column_GetRxFlag(void)
{
	if(Column_RxFlag == 1)
	{
		Column_RxFlag = 0;
		return 1;
	}
	
	return 0;
}

/**
 * @brief ɫ����־λ����
 * 
 * ���ܵ�ɫ�������ݺ󣬱�־λ����
 * 
 */
u8 Annular_GetRxFlag(void)
{
	if(Annular_RxFlag == 1)
	{
		Annular_RxFlag = 0;
		return 1;
	}
	
	return 0;
}

/**
 * @brief �ѽ��ܵ�openmv�������ݷ��ͳ�ȥ
 * 
 * �ѽ��ܵ�openmv�������ݷ��ͳ�ȥ����������
 * 
 */
void Openmv_SendPacket(void)
{
	Openmv_SendArray(Openmv_Column_TxPacket, 4);
}


/**
 * @brief ���ܷ���
 * 
 * �ѽ��ܵ�openmv���ݷ��ͳ�ȥ����������
 * 
 */
void Receive_Send(void)
{
	if(Column_GetRxFlag() == 1)
	{
		Packet_Column_Init();
		Openmv_SendByte(0xFF);
		Openmv_Column_SendPacket();
		Openmv_SendByte(0xFE);
	}
	if(Annular_GetRxFlag() == 1)
	{
		Packet_Annular_Init();
		Openmv_SendByte(0x01);
		Openmv_Annular_SendPacket();
		Openmv_SendByte(0xFE);
	}
}


