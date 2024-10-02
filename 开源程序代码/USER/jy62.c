#include "string.h"
#include "text.h"
#include "lcd.h"
#include "jy62.h"

//�����Ǵ������ͷ����ͨ�ų�ʼ���Լ��������ݵĴ���
//Ϊʲô��JY62�أ�ԭ�������������ǵģ�������Ч��̫������ȥ���ˣ�����һ�¾����ø�����
//�������V831����ͷʶ���м���������

u8 v831_y[3];		//������V831������
u8 v831_RxFlag; //V831���ڽ��ܱ�־λ

//jy62��ʼ��
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
		
		//�ȴ��������ݰ�֡ͷ
		if (RxState == 0)	 
		{
			if (RxData == 0x03)
			{
				RxState = 1;
				pRxPacket = 0;
			}
		}
		//���ܵ����ݰ��ˣ��������ݰ�
		else if (RxState == 1)
		{	
			v831_y[pRxPacket] = RxData;	
			pRxPacket ++;
			if(pRxPacket >=2)
			{
				RxState = 2;
			}
			
		}
		//���ݽ������
		else if (RxState == 2)
		{
			if (RxData == 0xFE)
			{
//			�ж����治Ҫ����ʾ��������delayȻ��������ģ�ʡ����ʱ����һ�Σ��Թ�һ�ο�
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
 * @brief ��V831�����ֽ�
 * 
 * ��V831�����ֽڣ��������Ե�
 * 
 * @param Byte ��Ҫ���͵��ֽ�
 *
 */
void v831_SendByte(u8 Byte)
{
	USART_SendData(USART6, Byte);
	while(USART_GetFlagStatus(USART6,USART_FLAG_TXE) == RESET);
	
}

