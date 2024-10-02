#include "stm32f4xx.h"                  // Device header
#include "Motor_Init.h"  
#include "Motor.h"

//����ļ��Ǵ�ŵ����ʼ������

//���ӵ��GPIO�ڳ�ʼ��
void MOTOR_GPIO_Init(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	/* ����������������������PA6 */
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;	//�������
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9; 
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_TIM3); 
  GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_TIM3); 
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource8,GPIO_AF_TIM3); 
  GPIO_PinAFConfig(GPIOC,GPIO_PinSource9,GPIO_AF_TIM3);
	
	
	/* ���������������������� PB6*/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_3);
	
}

//���ӵ����ʱ����ʼ��
void MOTOR_TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	
	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;			//ʱ�ӷ�Ƶ���ӣ������˲�����Ƶ�ʵĲ���
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536-1;									//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = TIM_PRESCALER;				//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; 						//�߼���ʱ������
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);
		
	TIM_OCStructInit(&TIM_OCInitStructure);	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;  						//��תģʽ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;															//CCR �Ƚ�ֵ
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Disable);    						//�ر�Ԥװ��1
	TIM_CCxCmd(TIM3,TIM_Channel_1,TIM_CCx_Disable);
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Disable);    						//�ر�Ԥװ��2
	TIM_CCxCmd(TIM3,TIM_Channel_2,TIM_CCx_Disable);
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Disable);    						//�ر�Ԥװ��3
	TIM_CCxCmd(TIM3,TIM_Channel_3,TIM_CCx_Disable);
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Disable);    						//�ر�Ԥװ��4
	TIM_CCxCmd(TIM3,TIM_Channel_4,TIM_CCx_Disable);
	
	TIM_ClearFlag(TIM3,TIM_FLAG_CC1);																//�����ʱ��3��ͨ��1�ı�־λ
	TIM_ITConfig(TIM3,TIM_IT_CC1,ENABLE);														//������ʱ��3��ͨ��1�ж�

	TIM_ClearFlag(TIM3,TIM_FLAG_CC2);																//�����ʱ��3��ͨ��2�ı�־λ
	TIM_ITConfig(TIM3,TIM_IT_CC2,ENABLE);														//������ʱ��3��ͨ��2�ж�

	TIM_ClearFlag(TIM3,TIM_FLAG_CC3);																//�����ʱ��3��ͨ��3�ı�־λ
	TIM_ITConfig(TIM3,TIM_IT_CC3,ENABLE);														//������ʱ��3��ͨ��3�ж�

	TIM_ClearFlag(TIM3,TIM_FLAG_CC4);																//�����ʱ��3��ͨ��4�ı�־λ
	TIM_ITConfig(TIM3,TIM_IT_CC4,ENABLE);														//������ʱ��3��ͨ��4�ж�

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);									//����
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
}




//���˿��GPIO�ڳ�ʼ��
void SIGAN_GPIO_Init(void) 
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);	//����PB�˿�ʱ��
	
	/* ����������������������PA6 */
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;						//�������
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;					//�������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource1,GPIO_AF_TIM2);
	
	/* ���������������������� C2*/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	 /* ���������������ʹ�ܿ���C0 */
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOC, GPIO_Pin_0);
	
}

//˿�˵����ʱ����ʼ��
void SIGAN_TIM_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;	
	TIM_OCStructInit(&TIM_OCInitStructure);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;			//ʱ�ӷ�Ƶ���ӣ������˲�����Ƶ�ʵĲ���
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 65536-1;									//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = TIM_PRESCALER;				//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0; 						//�߼���ʱ������
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
		
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;  						//��תģʽ
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;															//CCR �Ƚ�ֵ
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2,TIM_OCPreload_Disable);    						//�ر�Ԥװ��
	TIM_CCxCmd(TIM2,TIM_Channel_2,TIM_CCx_Disable);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_CC2);																//�����ʱ��3��ͨ��1�ı�־λ
	TIM_ITConfig(TIM2,TIM_IT_CC2,ENABLE);														//������ʱ��3��ͨ��1�ж�
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);									//����
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_Init(&NVIC_InitStructure);
	
}









