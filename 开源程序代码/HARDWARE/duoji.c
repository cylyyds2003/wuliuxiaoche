#include "stm32f4xx.h"                  // Device header
#include "duoji.h"

//�����Ǵ�Ŷ���ĳ�ʼ���Լ����ƴ���
//duoji���Ƕ������������������������
//����ܶ�ƴ��������

/******************************************צ��************************************************************/
//��צ�����ʼ��
void ZhuaZi_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM13, ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	               
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_TIM13);                       
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;      
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 84 - 1;              
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;            
	TIM_TimeBaseInit(TIM13, &TIM_TimeBaseInitStructure);            
	
	TIM_OCStructInit(&TIM_OCInitStructure);                
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;      
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
	TIM_OCInitStructure.TIM_Pulse = 0;                     
	TIM_OC1Init(TIM13, &TIM_OCInitStructure);             
	
	TIM_OC1PreloadConfig(TIM13, TIM_OCPreload_Enable);
	TIM_Cmd(TIM13, ENABLE);  

}

/**
 * @brief ����צ�Ӷ���ĽǶ�
 * 
 * ����צ�Ӷ���ĽǶȣ���������270�ȶ����
 * 
 * @param Angle �Ƕȶ���
 * @return null
 */
void ZhuaZi(uint16_t Angle) 
{
	uint16_t compare = (500 + (Angle / 270.0) *2000.0);
	TIM_SetCompare1(TIM13, compare);
}

/**
 * @brief ����צ�Ӷ���ĽǶȴ��Ӽ���
 * 
 * ����צ�Ӷ���ĽǶȣ������ģ����һ�¼��٣�
 * ���������ţ���ֹ��̫�죬������ƶ���һ�µ��¾���û����
 * 
 * @param xian ԭ�ȵĶ���Ƕȶ���
 * @param hou  ����Ķ���Ƕȶ���
 * @return null
 */
void zhuazi(uint16_t xian,uint16_t hou)
{
	if(xian <= hou)
	{
		for(xian;xian <= hou;xian ++)
		{	
			ZhuaZi(xian);
			delay_ms(2);
		}
	}
	else
	{
		for(xian;xian >= hou;xian --)
			{	
				ZhuaZi(xian);
				delay_ms(2);
			}
	}
}


/******************************************��̨*********************************************************/
//��̨�����ʼ��
void YunTai_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	               
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_TIM14);                       
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;      
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInitStructure.TIM_Period = 20000- 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 84 - 1;              
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;            
	TIM_TimeBaseInit(TIM14, &TIM_TimeBaseInitStructure);            
	
	TIM_OCStructInit(&TIM_OCInitStructure);                
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;      
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
	TIM_OCInitStructure.TIM_Pulse = 0;                     
	TIM_OC1Init(TIM14, &TIM_OCInitStructure);             
	
	TIM_OC1PreloadConfig(TIM14, TIM_OCPreload_Enable);
	TIM_Cmd(TIM14, ENABLE);  

}

/**
 * @brief ������̨����ĽǶ�
 * 
 * ������̨����ĽǶȣ���������270�ȶ����
 * 
 * @param Angle �Ƕȶ���
 * @return null
 */
void YunTai(uint16_t Angle) 
{
	uint16_t compare = (500 + (Angle / 270.0) *2000.0);
  TIM_SetCompare1(TIM14, compare);
}

/*******************************************ת��****************************************************/
//ת�̶����ʼ��
void ZhuanPan_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure; 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	               
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource6,GPIO_AF_TIM10);                       
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;      
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInitStructure.TIM_Period = 20000 - 1;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 168 - 1;              
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;            
	TIM_TimeBaseInit(TIM10, &TIM_TimeBaseInitStructure);            
	
	TIM_OCStructInit(&TIM_OCInitStructure);                
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;      
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;  
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;  
	TIM_OCInitStructure.TIM_Pulse = 0;                     
	TIM_OC1Init(TIM10, &TIM_OCInitStructure);             
	
	TIM_OC1PreloadConfig(TIM10, TIM_OCPreload_Enable);
	TIM_Cmd(TIM10, ENABLE);  

}

/**
 * @brief ����ת�̶���ĽǶ�
 * 
 * ����צ��ת�̵ĽǶȣ���������270�ȶ����
 * 
 * @param Angle �Ƕȶ���
 * @return null
 */
void ZhuanPan(uint16_t Angle) 
{
	uint16_t compare = (500 + (Angle / 270.0) *2000.0);
  TIM_SetCompare1(TIM10, compare);
}

