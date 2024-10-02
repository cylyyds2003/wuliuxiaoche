#include "stm32f4xx.h"                  // Device header
#include "duoji.h"

//这里是存放舵机的初始化以及控制代码
//duoji就是舵机哈哈哈哈哈，不会起名字
//这里很多拼音的命名

/******************************************爪子************************************************************/
//手爪舵机初始化
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
 * @brief 控制爪子舵机的角度
 * 
 * 控制爪子舵机的角度，这个舵机是270度舵机哈
 * 
 * @param Angle 角度度数
 * @return null
 */
void ZhuaZi(uint16_t Angle) 
{
	uint16_t compare = (500 + (Angle / 270.0) *2000.0);
	TIM_SetCompare1(TIM13, compare);
}

/**
 * @brief 控制爪子舵机的角度带加减速
 * 
 * 控制爪子舵机的角度，这里带模拟了一下减速，
 * 让他慢慢放，防止放太快，把物块推动了一下导致精度没有了
 * 
 * @param xian 原先的舵机角度度数
 * @param hou  后面的舵机角度度数
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


/******************************************云台*********************************************************/
//云台舵机初始化
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
 * @brief 控制云台舵机的角度
 * 
 * 控制云台舵机的角度，这个舵机是270度舵机哈
 * 
 * @param Angle 角度度数
 * @return null
 */
void YunTai(uint16_t Angle) 
{
	uint16_t compare = (500 + (Angle / 270.0) *2000.0);
  TIM_SetCompare1(TIM14, compare);
}

/*******************************************转盘****************************************************/
//转盘舵机初始化
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
 * @brief 控制转盘舵机的角度
 * 
 * 控制爪子转盘的角度，这个舵机是270度舵机哈
 * 
 * @param Angle 角度度数
 * @return null
 */
void ZhuanPan(uint16_t Angle) 
{
	uint16_t compare = (500 + (Angle / 270.0) *2000.0);
  TIM_SetCompare1(TIM10, compare);
}

