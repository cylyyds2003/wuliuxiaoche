/* 包含头文件 ----------------------------------------------------------------*/
#include "app.h"
#include "data.h"
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include "separate_button.h"
#include "pid.h"
#include "usart.h"
/* 私有类型定义 --------------------------------------------------------------*/
uint8_t flag = 0;uint16_t t=0;int16_t speed;uint8_t count = 0;int16_t distance;
uint8_t lj = 0;
int32_t one,two,three,four;
uint8_t sportflag;
uint8_t state = ready_to_scan_QRcode;
uint8_t xuanzhuan_num = 0;
//uint8_t run_state1 = 1;uint8_t run_state2 = 1;uint8_t run_state3 = 1;uint8_t run_state4 = 1;
/* 私有变量 ------------------------------------------------------------------*/
/*******6通道舵机模块数据声明*******/
SteeringEngine6CHDef_t Servo_Device_S;
//uint16_t AngleValue[SERVO_NUM_MAX] = {1500,1500,1000,1500,2500,500};
uint16_t AngleValue[SERVO_NUM_MAX] = {1500,1500,1000,1500,500,1000};    //arm3和arm2分别为900，1500时openmv水平
uint16_t AngleTimeValue[SERVO_NUM_MAX] = {150,400,400,400,700,400};  //
static KEY_T WirelessUP_S;
static KEY_T WirelessDOWN_S;
static KEY_T WirelessLEFT_S;
static KEY_T WirelessRIGHT_S;
static KEY_T WirelessTRI_S;
static KEY_T WirelessCIRCLE_S;
static KEY_T WirelessFORK_S;
static KEY_T WirelessREC_S;
static KEY_T WirelessL1_S;
static KEY_T WirelessR1_S;
/*******直流电机驱动模块数据声明*******/
DCMotorMiniwattDef_t DCMotorMiniwatt1_S;
DCMotorMiniwattDef_t DCMotorMiniwatt2_S;
DCMotorMiniwattDef_t DCMotorMiniwatt3_S;
DCMotorMiniwattDef_t DCMotorMiniwatt4_S;
/*******底盘控制数据声明*******/
UnderpanPostureDef_t UnderpanPosture_S;
/* 扩展变量 ------------------------------------------------------------------*/
<<<<<<< HEAD
PID position_id1;//id   1
PID position_id2;//id   1
PID position_id3;//id   1
PID position_id4;//id   1
PID	yaw_control;//角度环pid结构体
PID x_control;//坐标控制结构体
PID y_control;
uint8_t x_set,y_set;


float angle = 0;
float _abs(float num)
{
	return num < 0 ? -num : num;
}
=======
CascadePID position_id1;//id   1
CascadePID position_id2;//id   1
CascadePID position_id3;//id   1
CascadePID position_id4;//id   1


>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
/* 函数体 --------------------------------------------------------------------*/
/***********************************************************************************************

                                       硬件配置函数

************************************************************************************************/
<<<<<<< HEAD
void PID_out(uint8_t flag,int16_t setcm ,float angle,uint8_t x,uint8_t y);
=======
void PID_out(uint8_t flag,int16_t set);
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671

static uint8_t Wireless_UP(void)
{
    if(PS2_Data.DATE.key1_U.bit.UP == 0)return 1; //按键按下
	else return 0;
}
static uint8_t Wireless_DOWN(void)
{
    if(PS2_Data.DATE.key1_U.bit.DOWN == 0)return 1;//按键按下
	else return 0;
}
static uint8_t Wireless_LEFT(void)
{
    if(PS2_Data.DATE.key1_U.bit.LEFT == 0)return 1;//按键按下
	else return 0;
}
static uint8_t Wireless_RIGHT(void)
{
    if(PS2_Data.DATE.key1_U.bit.RIGHT == 0) return 1;//按键按下 
	else return 0;
}
static uint8_t Wireless_TRI(void)
{//三角形
    if(PS2_Data.DATE.key2_U.bit.TRI == 0)return 1;//按键按下
	else return 0;
}
static uint8_t Wireless_CIRCLE(void)
{//圆
    if(PS2_Data.DATE.key2_U.bit.CIRCLE == 0)return 1;//按键按下
	else return 0;	
}
static uint8_t Wireless_FORK(void)
{//叉
    if(PS2_Data.DATE.key2_U.bit.FORK == 0)return 1;//按键按下
	else return 0;
}
static uint8_t Wireless_REC(void)
{//矩形
    if(PS2_Data.DATE.key2_U.bit.REC == 0)return 1;//按键按下
	else return 0;
}
static uint8_t Wireless_L1(void)
{//L1
    if(PS2_Data.DATE.key2_U.bit.L1 == 0)return 1;//按键按下
	else return 0;
}
static uint8_t Wireless_R1(void)
{//R1
    if(PS2_Data.DATE.key2_U.bit.R1 == 0)return 1;//按键按下
	else return 0;
}
/***********************************************************************************************

                                       应用任务函数

************************************************************************************************/
/*******舵机控制*******/
<<<<<<< HEAD
static void ServoSetPluseAndTime(uint8_t mode, uint16_t pwmval,uint16_t time)//舵机控制函数
=======
static void ServoSetPluseAndTime(uint8_t mode, uint16_t pwmval,uint16_t time)
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
{
	if(mode > SERVO_CH6)
	{
		mode = SERVO_CH6;
	}
	if(pwmval < 500)
	{
		pwmval = 500;
	}
	else if(pwmval > 2500)
	{
		pwmval = 2500;
	}
	if(time < 20)
	{
		time = 20;
	}
	else if(time > 30000)
	{
		time = 30000;
	}
	AngleValue[mode] = pwmval;
	AngleTimeValue[mode] = time;
}
<<<<<<< HEAD
uint8_t judge(void)
{
	if
    (
        _abs(one-DCMotorMiniwatt1_S.Motor_UploadData.DATE.Fault*L)    < 0.58
      &&_abs(two-DCMotorMiniwatt2_S.Motor_UploadData.DATE.Fault*L)    < 0.58
      &&_abs(three-DCMotorMiniwatt3_S.Motor_UploadData.DATE.Fault*L)  < 0.58
      &&_abs(four-DCMotorMiniwatt4_S.Motor_UploadData.DATE.Fault*L)   < 0.58
    )//判断到达目标位置，误差不超过0.3cm
	{
		count++;
    if(count > 100)//到达标志位累计到达120
    {
      count = 0;
      lj = 0;
      return 0;
    }
	}
	else 
	{
		count = 0;
		return 1;
	}
  return 1;
}
/***********左转270°时，需要修改目标值***********/
void forward_hanshu(int16_t distance,float set_angle) //前进的函数
{
		angle=	set_angle;
    sportflag = forward;
		if(!lj)
		{
		one += -distance;
		two += 0;
    three += distance;
		four += 0;
		lj = 1;
		}
    while(judge());
}

void back_hanshu(int16_t distance,float set_angle) //后退的函数
{
		angle=	set_angle;
    sportflag = back;
  	if(!lj)								
		{
		one += distance;
		two +=0;
    	three += -distance ;
		four +=0;									
		lj = 1;
		}
    while(judge());
}

void left_hanshu(int16_t distance,float set_angle) //向左的函数
{
		angle=	set_angle;
    sportflag = left;
		if(!lj)													
		{
		one +=0;
		two += -distance ;
		three +=0;
		four += distance ;
		lj = 1;
		}
    while(judge());
}

void right_hanshu(int16_t distance,float set_angle) //向右的函数
{
		angle=	set_angle;
    sportflag = right;
		if(!lj)
		{
		one += 0;
		two += distance ;
    	three += 0 ;
		four += -distance ;
		lj = 1;
		}
    while(judge());
}
void stop_hanshu(uint16_t stop_time,float set_angle,uint8_t x,uint8_t y) //停止的函数
{
		x_set = x;
		y_set =y;
		angle=	set_angle;
    sportflag = stop;
		if(!lj)
		{
		one += 0;
		two += 0 ;
    three += 0 ;
		four += 0 ;
		lj = 1;
		}
    HAL_Delay(stop_time);     //也可以把这行注释掉，反正 sportflag = stop就行
    lj=0;
}


void zuozhuan_hanshu(float set_angle)
{
  angle = set_angle;
  sportflag = zuozhuan;
  
  while(_abs( set_angle-yaw) > 1 );
		one =  DCMotorMiniwatt1_S.Motor_UploadData.DATE.Fault*L;
		two = DCMotorMiniwatt2_S.Motor_UploadData.DATE.Fault*L;
    three = DCMotorMiniwatt3_S.Motor_UploadData.DATE.Fault*L;
		four =  DCMotorMiniwatt4_S.Motor_UploadData.DATE.Fault*L;
}
=======
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
/***********************************************************************************************

                                       应用事件（中断）函数

************************************************************************************************/
/** @brief  定时中断事件
  * @param  None
  * @retval None
  */
<<<<<<< HEAD
static void TimeBreakExecution_Handler(void) //1ms
{
	static uint16_t time = 0;
										/*觉得不好看可以自己封装一下下面这个函数*/  
  
      PID_out(ID1,one,angle,x_set,y_set);
      PID_out(ID2,two,angle,x_set,y_set);
      PID_out(ID3,three,angle,x_set,y_set);
      PID_out(ID4,four,angle,x_set,y_set); 
    /*    sportflag是方向，lj是为了只给电机目标赋一次值设定的      */ 
=======
static void TimeBreakExecution_Handler(void) 
{
	static uint16_t time = 0;
	PID_out(ID1,4000);
	PID_out(ID2,4000);
	PID_out(ID3,4000);
	PID_out(ID4,4000);
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
	//=========舵机控制函数==============================
	time++;
	if(time == 20)
	{//20MS发送一次舵机控制指令
		time = 0;
		SLAVE_SteeringEngine6CH_MoreMotorControl(&Servo_Device_S,
<<<<<<< HEAD
                                             AngleValue[0],AngleTimeValue[0],
                                             AngleValue[1],AngleTimeValue[1],
                                             AngleValue[2],AngleTimeValue[2],
                                             AngleValue[3],AngleTimeValue[3],
                                             AngleValue[4],AngleTimeValue[4],
                                             AngleValue[5],AngleTimeValue[5]);
                      }
	//=========按键扫描函数==============================
	button_ticks();
	//==========底盘控制扫描函数=====================
	//UnderpanControl_Scan(&UnderpanPosture_S);       //scan别加上了，会顶掉pid的输出
=======
                                           AngleValue[0],AngleTimeValue[0],
									       AngleValue[1],AngleTimeValue[1],
                                           AngleValue[2],AngleTimeValue[2],
										   AngleValue[3],AngleTimeValue[3],
									       AngleValue[4],AngleTimeValue[4],
                                           AngleValue[5],AngleTimeValue[5]); 
	}
	//=========按键扫描函数==============================
	button_ticks();
	//==========底盘控制扫描函数=====================
	//UnderpanControl_Scan(&UnderpanPosture_S); 
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
	//=========CAN通讯协议============================
	Tim_GetCurrentTimeAdd_Scan1MS();    //必须1ms进行扫描此函数
	CANCommunication_Scan();            //最好也1ms进行扫描
}
<<<<<<< HEAD
=======
/**
  * @brief  按键触发事件
  * @param  None
  * @retval None
  */
static void Arm1PWMAdd(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ARM1, AngleValue[SERVO_ARM1]+ServoPrecision,20);
}
static void Arm3PWMAdd(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ARM3, AngleValue[SERVO_ARM3]+ServoPrecision,20);
}
static void Arm2PWMAdd(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ARM2, AngleValue[SERVO_ARM2]+ServoPrecision,20);
}

static void ClawPWMAdd(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_CLAW, AngleValue[SERVO_CLAW]+ServoPrecision,20);
}
static void RotaryPWMAdd(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ROTARY, AngleValue[SERVO_ROTARY]+ServoPrecision,20);
}
static void ClawPWMMinus(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_CLAW, AngleValue[SERVO_CLAW]-ServoPrecision,20);
}

static void Arm2PWMMinus(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ARM2, AngleValue[SERVO_ARM2]-ServoPrecision,20);
}
static void Arm1PWMMinus(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ARM1, AngleValue[SERVO_ARM1]-ServoPrecision,20);
}
static void Arm3PWMMinus(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ARM3, AngleValue[SERVO_ARM3]-ServoPrecision,20);
}
static void RotaryPWMMinus(void* btn)
{
	uint16_t ServoPrecision = 0;
	
	switch(((KEY_T*)btn)->event_flg)
	{
		case SIGNAL_PRESS_DOWN: 
			ServoPrecision = 10;
			break;
		case SIGNAL_LONG_PRESS_HOLD: 
			ServoPrecision = 20;
			break;
	}
	ServoSetPluseAndTime(SERVO_ROTARY, AngleValue[SERVO_ROTARY]-ServoPrecision,20);
}
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
/***********************************************************************************************

                                       应用主函数

************************************************************************************************/
/**
  * @brief  应用初始化
  * @param  None
  * @retval None
  */
void PID_Cascade_Init()
{
<<<<<<< HEAD
	PID_Init(&position_id1,0.9f , 0.0f , 0.0f , 70.0f ,70.0f , 1);
	PID_Init(&position_id2,0.9f , 0.0f , 0.0f , 70.0f ,70.0f , 1);
	PID_Init(&position_id3,0.5f , 0.0f , 0.0f , 70.0f ,70.0f , 1);
	PID_Init(&position_id4,0.8f , 0.0f , 0.0f , 70.0f ,70.0f , 1);//p 0.8
	PID_Init(&yaw_control,1.50f,0.0f,0.0f,0.0f,15.0f,1);
	PID_Init(&x_control,0.0f,0.0f,0.0f,100.0f,10.0f,1);
	PID_Init(&y_control,0.0f,0.0f,0.0f,100.0f,10.0f,1);
}




void PID_out(uint8_t flag , int16_t setcm , float angle	,uint8_t	x,uint8_t	y)
{
  
	PID_Calc(&yaw_control,angle,yaw);//角度环
  
	if(sportflag	==	stop)
	{
		PID_Calc(&x_control,0,x);
		PID_Calc(&y_control,0,y);
	}
	else
	{
		x_control.output	=	0;
		y_control.output	=	0;
	}
  if(sportflag != zuozhuan && sportflag != youzhuan)
  {
			switch(flag)
      {
			
				case ID1:	PID_Calc(&position_id1,setcm/L,DCMotorMiniwatt1_S.Motor_UploadData.DATE.Fault) ;
								/***************************前进后退或左右移动采用两轮差速控制角度*******************************/
								/***************************故每种移动只启用两个轮子输出角度环***********************************/
									if(sportflag != stop )
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,position_id1.output+(sportflag%2)*yaw_control.output);
									}
									else if(sportflag==stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,-x_control.output);
										one = DCMotorMiniwatt1_S.Motor_UploadData.DATE.Fault/L;
									}
                  
									break;
			
				case ID2:	PID_Calc(&position_id2,setcm/L,DCMotorMiniwatt2_S.Motor_UploadData.DATE.Fault) ;
									if(sportflag != stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt2_S,position_id2.output-(1-sportflag%2)*yaw_control.output);
									}
									else if(sportflag==stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,-x_control.output);
										two = DCMotorMiniwatt2_S.Motor_UploadData.DATE.Fault/L;
									}
									break;
				
				case ID3: PID_Calc(&position_id3,setcm/L,DCMotorMiniwatt3_S.Motor_UploadData.DATE.Fault) ;
									if(sportflag != stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt3_S,position_id3.output+(sportflag%2)*yaw_control.output);
									}
									else if(sportflag==stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,-x_control.output);
										three = DCMotorMiniwatt3_S.Motor_UploadData.DATE.Fault/L;
									}
                  
									break;
				
				case ID4:	PID_Calc(&position_id4,setcm/L,DCMotorMiniwatt4_S.Motor_UploadData.DATE.Fault) ;
									if(sportflag != stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt4_S,position_id4.output-(1-sportflag%2)*yaw_control.output);
									}
									else if(sportflag==stop)
									{
										SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,-x_control.output);
										four = DCMotorMiniwatt4_S.Motor_UploadData.DATE.Fault/L;
									}                  
									break;
      }
  }
  else 
  {
			switch(flag)
      {
			
				case ID1:SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,-yaw_control.output);
				case ID2:SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt2_S,-yaw_control.output);
				case ID3:SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt3_S,-yaw_control.output);
				case ID4:SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt4_S,-yaw_control.output);
      }
  }
  
			
		
}

//舵机夹取函数    
/*目前就是有两个想法
方案一：到时候视觉一直对着底下扫描，机械臂不动，底盘移动直到对准，然后机械臂向下夹取
方案二：写一个函数做逆运动学解算，根据openmv得到的坐标直接操控舵机角度*/    //2024.10.31 凌逸乘风 留下注释希望帮助以后的学弟学妹
//注意先移动arm1再移动上部，不然可能会撞掉物料
void get_from_tray()
{
  xuanzhuan_num++;
  //舵驱五号六号通道损坏
    //arm3和arm2分别为900，1500时openmv水平
    /*靠近底盘的臂4*/ AngleValue[SERVO_ARM1]        = 1500; //先竖直避免干涉
    /*中间的舵机3*/   AngleValue[SERVO_ARM2]        = 1000; //开始屈臂
    /*底盘旋转舵机5*/ AngleValue[SERVO_ROTARY]      = 2300; //旋转面向物料
  
    HAL_Delay(2000);      //延时别乱改，要不然把陀螺仪撞断了你就知道错
  
    /*靠近底盘的臂4*/ AngleValue[SERVO_ARM1]        = 2150; //开始屈臂
//    HAL_Delay(300);
    /*靠近手爪2*/     AngleValue[SERVO_ARM3]        = 900;  //开始屈臂
//    HAL_Delay(300);
    /*中间的舵机3*/   AngleValue[SERVO_ARM2]        = 1500; //开始屈臂
    HAL_Delay(300);
    /*手爪张开1*/     AngleValue[SERVO_CLAW]        = 1000; //松开爪子
    
    ///*料盘旋转舵机6*/ AngleValue[SERVO_wuliaopan]   = 1000; //面向料盘
  if(xuanzhuan_num == 1)
    {
      AngleValue[SERVO_wuliaopan]   = 1500;//1700
    }
  if(xuanzhuan_num == 2)
    {
      AngleValue[SERVO_wuliaopan]   = 1500-889;//2400能用
    }
  if(xuanzhuan_num == 3)
    {
      AngleValue[SERVO_wuliaopan]   = 1500+889;//1000能用
      xuanzhuan_num = 0;
    }

              
    HAL_Delay(1500);

    /*手爪*/          AngleValue[SERVO_CLAW]        = 1500; //SERVO_CLAW    //手爪舵机

}
//（2500-500）*angle/180+500
void put_to_plate()
{
    //arm3和arm2分别为900，1500时openmv水平
    /*靠近底盘的臂4*/ AngleValue[SERVO_ARM1]        = 1500; //手臂竖直
    HAL_Delay(300);
    /*底盘旋转舵机5*/ AngleValue[SERVO_ROTARY]      = 700-50;  //面向料盘
    HAL_Delay(600);
    /*靠近底盘的臂4*/ AngleValue[SERVO_ARM1]        = 800+100+50+50;  //屈臂
    HAL_Delay(300);
    /*靠近手爪2*/     AngleValue[SERVO_ARM3]        = 1500+100+100;  //SERVO_ARM3    //臂3舵机，靠近手爪的臂
    HAL_Delay(300);
    /*中间的舵机3*/   AngleValue[SERVO_ARM2]        = 1500; //SERVO_ARM2    //臂2舵机，中间的臂
    HAL_Delay(1500);
    /*手爪张开1*/     AngleValue[SERVO_CLAW]        = 1300; //物料放到料盘上
    HAL_Delay(500);
    
//    /*靠近手爪2*/     AngleValue[SERVO_ARM3]        = 900;  //SERVO_ARM3    //臂3舵机，靠近手爪的臂
//    HAL_Delay(300);
//    /*中间的舵机3*/   AngleValue[SERVO_ARM2]        = 1500; //SERVO_ARM2    //臂2舵机，中间的臂
//    HAL_Delay(300);

//    
//    /*料盘旋转舵机6*/ AngleValue[SERVO_wuliaopan]   = 1000; //SERVO_ARM2    //料盘舵机     
//              
//    HAL_Delay(1500);

//    /*手爪*/          AngleValue[SERVO_CLAW]        = 1500; //SERVO_CLAW    //手爪舵机


=======
	PID_Init(&position_id1.inner,0.45f , 0.02f , 0.24f , 290.0f ,290.0f , 1);
	PID_Init(&position_id1.outer,0.4f , 0.0f , 0.0f , 290.0f ,290.0f , 1);
	PID_Init(&position_id2.inner,0.45f , 0.005f , 0.05f , 290.0f ,290.0f , 1);
	PID_Init(&position_id2.outer,0.4f , 0.0f , 0.35f , 290.0f ,290.0f , 1);
	PID_Init(&position_id3.inner,0.45f , 0.005f , 0.05f , 290.0f ,290.0f , 1);
	PID_Init(&position_id3.outer,0.4f , 0.0f , 0.35f , 290.0f ,290.0f , 1);
	PID_Init(&position_id4.inner,0.45f , 0.005f , 0.05f , 290.0f ,290.0f , 1);//p 1.2
	PID_Init(&position_id4.outer,0.4f , 0.0f , 0.35f , 290.0f ,290.0f , 1);//p 0.8
}

void PID_out(uint8_t flag , int16_t set)
{
	
	switch(flag)
	{
		case ID1:	speed = SLAVE_DCMotorMiniwatt_SpeedRead(&DCMotorMiniwatt1_S) ;
							PID_CascadeCalc(&position_id1,set ,DCMotorMiniwatt1_S.Motor_UploadData.DATE.Fault,speed) ;
							SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt1_S,position_id1.output);
	
		case ID2:	speed = SLAVE_DCMotorMiniwatt_SpeedRead(&DCMotorMiniwatt2_S) ;
							PID_CascadeCalc(&position_id2,set,DCMotorMiniwatt2_S.Motor_UploadData.DATE.Fault,speed) ;
							SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt2_S,position_id2.output);
		
		case ID3: speed = SLAVE_DCMotorMiniwatt_SpeedRead(&DCMotorMiniwatt3_S) ;
							PID_CascadeCalc(&position_id3,set,DCMotorMiniwatt3_S.Motor_UploadData.DATE.Fault,speed) ;
							SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt3_S,position_id3.output);
		
		case ID4: speed = SLAVE_DCMotorMiniwatt_SpeedRead(&DCMotorMiniwatt4_S) ;
							PID_CascadeCalc(&position_id4,set,DCMotorMiniwatt4_S.Motor_UploadData.DATE.Fault,speed) ;
							SLAVE_DCMotorMiniwatt_SpeedSet(&DCMotorMiniwatt4_S,position_id4.output);
	}
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
}

static void ApplicationProgram_Iint(void)
{ 
	/**********************按键初始化**************************/  
<<<<<<< HEAD
//	button_init(&WirelessUP_S,Wireless_UP,1,300,200);
//	button_init(&WirelessDOWN_S,Wireless_DOWN,1,300,200);
//	button_init(&WirelessLEFT_S,Wireless_LEFT,1,300,200);
//	button_init(&WirelessRIGHT_S,Wireless_RIGHT,1,300,200);
//	button_init(&WirelessTRI_S,Wireless_TRI,1,300,200);
//	button_init(&WirelessCIRCLE_S,Wireless_CIRCLE,1,300,200);
//	button_init(&WirelessFORK_S,Wireless_FORK,1,300,200);
//	button_init(&WirelessREC_S,Wireless_REC,1,300,200);
//	
//	button_init(&WirelessL1_S,Wireless_L1,1,300,200);
//	button_init(&WirelessR1_S,Wireless_R1,1,300,200);
//	
//	button_attach(&WirelessUP_S, PRESS_DOWN,Arm3PWMAdd);
//	button_attach(&WirelessDOWN_S, PRESS_DOWN,Arm3PWMMinus);
//	button_attach(&WirelessLEFT_S, PRESS_DOWN,Arm2PWMAdd);
//	button_attach(&WirelessRIGHT_S, PRESS_DOWN,Arm2PWMMinus);
//	button_attach(&WirelessTRI_S, PRESS_DOWN,Arm1PWMAdd);
//	button_attach(&WirelessFORK_S, PRESS_DOWN,Arm1PWMMinus);
//	button_attach(&WirelessCIRCLE_S, PRESS_DOWN,ClawPWMAdd);
//	button_attach(&WirelessREC_S, PRESS_DOWN,ClawPWMMinus);
//	button_attach(&WirelessL1_S, PRESS_DOWN,RotaryPWMAdd);
//	button_attach(&WirelessR1_S, PRESS_DOWN,RotaryPWMMinus);
//	
//	button_attach(&WirelessUP_S, LONG_PRESS_HOLD,Arm3PWMAdd);
//	button_attach(&WirelessDOWN_S, LONG_PRESS_HOLD,Arm3PWMMinus);
//	button_attach(&WirelessLEFT_S, LONG_PRESS_HOLD,Arm2PWMAdd);
//	button_attach(&WirelessRIGHT_S, LONG_PRESS_HOLD,Arm2PWMMinus);
//	button_attach(&WirelessTRI_S, LONG_PRESS_HOLD,Arm1PWMAdd);
//	button_attach(&WirelessFORK_S, LONG_PRESS_HOLD,Arm1PWMMinus);
//	button_attach(&WirelessCIRCLE_S, LONG_PRESS_HOLD,ClawPWMAdd);
//	button_attach(&WirelessREC_S, LONG_PRESS_HOLD,ClawPWMMinus);
//	button_attach(&WirelessL1_S, LONG_PRESS_HOLD,RotaryPWMAdd);
//	button_attach(&WirelessR1_S, LONG_PRESS_HOLD,RotaryPWMMinus);
//	
//	button_start(&WirelessUP_S);
//	button_start(&WirelessDOWN_S);
//	button_start(&WirelessLEFT_S);
//	button_start(&WirelessRIGHT_S);
//	button_start(&WirelessTRI_S);
//	button_start(&WirelessCIRCLE_S);
//	button_start(&WirelessFORK_S);
//	button_start(&WirelessREC_S);
//	button_start(&WirelessL1_S);
//	button_start(&WirelessR1_S);
=======
	button_init(&WirelessUP_S,Wireless_UP,1,300,200);
	button_init(&WirelessDOWN_S,Wireless_DOWN,1,300,200);
	button_init(&WirelessLEFT_S,Wireless_LEFT,1,300,200);
	button_init(&WirelessRIGHT_S,Wireless_RIGHT,1,300,200);
	button_init(&WirelessTRI_S,Wireless_TRI,1,300,200);
	button_init(&WirelessCIRCLE_S,Wireless_CIRCLE,1,300,200);
	button_init(&WirelessFORK_S,Wireless_FORK,1,300,200);
	button_init(&WirelessREC_S,Wireless_REC,1,300,200);
	
	button_init(&WirelessL1_S,Wireless_L1,1,300,200);
	button_init(&WirelessR1_S,Wireless_R1,1,300,200);
	
	button_attach(&WirelessUP_S, PRESS_DOWN,Arm3PWMAdd);
	button_attach(&WirelessDOWN_S, PRESS_DOWN,Arm3PWMMinus);
	button_attach(&WirelessLEFT_S, PRESS_DOWN,Arm2PWMAdd);
	button_attach(&WirelessRIGHT_S, PRESS_DOWN,Arm2PWMMinus);
	button_attach(&WirelessTRI_S, PRESS_DOWN,Arm1PWMAdd);
	button_attach(&WirelessFORK_S, PRESS_DOWN,Arm1PWMMinus);
	button_attach(&WirelessCIRCLE_S, PRESS_DOWN,ClawPWMAdd);
	button_attach(&WirelessREC_S, PRESS_DOWN,ClawPWMMinus);
	button_attach(&WirelessL1_S, PRESS_DOWN,RotaryPWMAdd);
	button_attach(&WirelessR1_S, PRESS_DOWN,RotaryPWMMinus);
	
	button_attach(&WirelessUP_S, LONG_PRESS_HOLD,Arm3PWMAdd);
	button_attach(&WirelessDOWN_S, LONG_PRESS_HOLD,Arm3PWMMinus);
	button_attach(&WirelessLEFT_S, LONG_PRESS_HOLD,Arm2PWMAdd);
	button_attach(&WirelessRIGHT_S, LONG_PRESS_HOLD,Arm2PWMMinus);
	button_attach(&WirelessTRI_S, LONG_PRESS_HOLD,Arm1PWMAdd);
	button_attach(&WirelessFORK_S, LONG_PRESS_HOLD,Arm1PWMMinus);
	button_attach(&WirelessCIRCLE_S, LONG_PRESS_HOLD,ClawPWMAdd);
	button_attach(&WirelessREC_S, LONG_PRESS_HOLD,ClawPWMMinus);
	button_attach(&WirelessL1_S, LONG_PRESS_HOLD,RotaryPWMAdd);
	button_attach(&WirelessR1_S, LONG_PRESS_HOLD,RotaryPWMMinus);
	
	button_start(&WirelessUP_S);
	button_start(&WirelessDOWN_S);
	button_start(&WirelessLEFT_S);
	button_start(&WirelessRIGHT_S);
	button_start(&WirelessTRI_S);
	button_start(&WirelessCIRCLE_S);
	button_start(&WirelessFORK_S);
	button_start(&WirelessREC_S);
	button_start(&WirelessL1_S);
	button_start(&WirelessR1_S);
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
	/**********************PS2遥控初始化***********************/
	PS2_SetInit();
	/**********************数据初始化**************************/
	SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt1_S,1);//ID号1
	SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt2_S,2);//ID号2
    SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt3_S,3);//ID号3
	SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt4_S,4);//ID号4
	
	SLAVE_SteeringEngine6CH_Init(&Servo_Device_S,1); //初始舵机模块数据,ID为1
	
	UnderpanControl_Init(&UnderpanPosture_S,
<<<<<<< HEAD
                         FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90,
=======
                         FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90_AUTO,
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
						 400,
						 &DCMotorMiniwatt1_S,  //1号
						 &DCMotorMiniwatt2_S,  //2号
						 &DCMotorMiniwatt3_S,  //3号
						 &DCMotorMiniwatt4_S); //4号
	/**********************CAN初始化***************************/
	CANCommunication_Init();
	PID_Cascade_Init();
	/********************定时器初始化**************************/
	/*
	把TimeBreakExecution_Handler传递到定时器中断函数内执行，
	我们把定时器已经设置成1ms一次触发中断，
	说明TimeBreakExecution_Handler也被1ms执行一次。
	*/
    Timer_SetHandler(TimeBreakExecution_Handler);//1ms
		
}

void ApplicationProgram_main(void)
{
	uint8_t a;
	int16_t yawbuff = 0;
<<<<<<< HEAD
  int16_t y_axisbuff = 0;
=======
   int16_t y_axisbuff = 0;
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
	int16_t x_axisbuff = 0;
	
	int16_t upperyawbuff = 0;
	
<<<<<<< HEAD
  ApplicationProgram_Iint();
  
  while(1)
  {	
=======
    ApplicationProgram_Iint();

    while(1)
	{	
		
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
		t=SLAVE_DCMotorMiniwatt_PlaceRead(&DCMotorMiniwatt1_S);
		if( !PS2_RedLight()) 
		{//判断手柄是否为红灯模式，是，指示灯LED点亮
			HAL_Delay(50);	 //延时很重要不可去
			LED1(bright);
			for(a=0; a<8; a++)//清除数据缓冲区
				PS2_Data.byte[a] = 0x00;
			PS2_ReadData();
			y_axisbuff = (128 - PS2_Data.DATE.PSS_LY)*2;//最高速度256
			x_axisbuff = (PS2_Data.DATE.PSS_LX - 128)*2;
			yawbuff = (128 - PS2_Data.DATE.PSS_RY)*2;
			
			upperyawbuff = (PS2_Data.DATE.PSS_RX - 128)*2;
			
			if(ABS(y_axisbuff) < 50) y_axisbuff = 0; //限制遥控中间位置的误差
		    if(ABS(yawbuff) < 50) yawbuff = 0;
		    if(ABS(x_axisbuff) < 50) x_axisbuff = 0;
			if(ABS(upperyawbuff) < 50) upperyawbuff = 0;
			
		}
		else
		{//判断手柄不是红灯模式，指示灯LED熄灭
			LED1(extinguish);
			y_axisbuff = 0;
			x_axisbuff = 0;
			yawbuff = 0;
			PS2_ClearData();
		}
<<<<<<< HEAD
		HAL_Delay(50);//别删，删了可能出问题
    
    /*这个路径逻辑很长，觉得不好看可以封装一下*///cyl已封装
    //路径逻辑在主函数里加
    while(1)
    {
      get_from_tray();
      HAL_Delay(1500);
      put_to_plate();

    }
    forward_hanshu(30,0);
    zuozhuan_hanshu(90);
    forward_hanshu(30,90);
//    
    
//    first_path();
//    
/////***************************************************第一圈正式结束**************************************************************************///
/////*************************************************以下是第二圈的代码**************************************************************************///
//        
//    second_path();    
//        
///************************************************************前往启停区，完结撒花***********************************************************************/        
//		right_hanshu(70,0);
//		back_hanshu(150,0);
    while(1);//最后加个while(1)控制在这个位置，防止程序重头运行回到原位        
	}
}
    

=======
//		UnderpanPosture_S.y_axis = y_axisbuff;
//		UnderpanPosture_S.x_axis = x_axisbuff;
//		UnderpanPosture_S.yaw = yawbuff;
		
		if(upperyawbuff > 0)
		{
			AngleValue[4]+=40;
			if(AngleValue[4]>2500)
			{
				AngleValue[4]=2500;
			}
		}
		else if(upperyawbuff < 0)
		{
			AngleValue[4]-=40;
			if(AngleValue[4]<500)
			{
				AngleValue[4]=500;
			}
		}
		if(yawbuff > 0)
		{
			AngleValue[3]+=40;
			if(AngleValue[3]>2500)
			{
				AngleValue[3]=2500;
			}
		}
		else if(yawbuff < 0)
		{
			AngleValue[3]-=40;
			if(AngleValue[3]<500)
			{
				AngleValue[3]=500;
			}
		}
		if(y_axisbuff> 0)
		{
			AngleValue[2]+=40;
			if(AngleValue[2]>2500)
			{
				AngleValue[2]=2500;
			}
		}
		else if(y_axisbuff < 0)
		{
			AngleValue[2]-=40;
			if(AngleValue[2]<500)
			{
				AngleValue[2]=500;
			}
		}
		if(x_axisbuff>0)
		{
			AngleValue[1]+=40;
			if(AngleValue[1]>2500)
			{
				AngleValue[1]=2500;
			}
		}
		else if(x_axisbuff < 0)
		{
			AngleValue[1]-=40;
			if(AngleValue[1]<500)
			{
				AngleValue[1]=500;
			}
		}
		if(PS2_Data.DATE.key2_U.bit.R2  == 0)
		{
			HAL_Delay(20);
			flag++;
			if(flag%2==1)
			{
			AngleValue[0]=2500;
			AngleTimeValue [0] = 700;
			}
			else if(flag%2==0)
			{
				AngleValue[0]=1500;
			AngleTimeValue [0] = 700;
			}
			if(flag==2)
			{
				flag=0;
			}
		}
		HAL_Delay(50);
	}
}
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
