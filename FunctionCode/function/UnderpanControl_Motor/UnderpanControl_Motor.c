/* 包含头文件 ----------------------------------------------------------------*/
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include <math.h>
/* 私有类型定义 --------------------------------------------------------------*/

/* 私有宏定义 ----------------------------------------------------------------*/

/* 私有变量 ------------------------------------------------------------------*/

/* 扩展变量 ------------------------------------------------------------------*/

/* 私有函数原形 --------------------------------------------------------------*/

/* 函数体 --------------------------------------------------------------------*/
static uint16_t Absolute_Value(int16_t val)
{
    uint16_t valbuf;
    
    if(val < 0)
    {
        valbuf = (-val);
    }
    else
    {
        valbuf = val;
    }
    
	return valbuf;
}
static void UnderpanControl_SetEachMotorSpeed( UnderpanPostureDef_t* handle)
{
	int16_t speed1buff;
    int16_t speed2buff;
    int16_t speed3buff;
    int16_t speed4buff;
	
	if(handle->mode != DEBUG_COMMONWHEEL) //正常模式
	{
		speed1buff = handle->speed1;
		speed2buff = handle->speed2;
		speed3buff = handle->speed3;
		speed4buff = handle->speed4;
	#if (DCMOTOR1_DIR == REV)
		 speed1buff = -speed1buff;
	#endif
	#if (DCMOTOR2_DIR == REV)
		 speed2buff = -speed2buff;
	#endif
	#if (DCMOTOR3_DIR == REV)
		 speed3buff = -speed3buff;
	#endif
	#if (DCMOTOR4_DIR == REV)
		 speed4buff = -speed4buff;
	#endif
		if(handle->Motor1 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor1,speed1buff);
		if(handle->Motor2 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor2,speed2buff);
		if(handle->Motor3 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor3,speed3buff);
		if(handle->Motor4 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor4,speed4buff);
	}
	else  //调试模式
	{
		if(handle->Motor1 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor1,0);
		if(handle->Motor2 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor2,0);
		if(handle->Motor3 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor3,0);
		if(handle->Motor4 != 0) SLAVE_DCMotorMiniwatt_SpeedSet(handle->Motor4,0);
	}
	#ifdef UnderpanControl_READSPEED
		if(handle->Motor1 != 0)
		{
			handle->speed1now = SLAVE_DCMotorMiniwatt_SpeedRead(handle->Motor1);
		}
		if(handle->Motor2 != 0)
		{
			handle->speed2now = -SLAVE_DCMotorMiniwatt_SpeedRead(handle->Motor2);
		}
		if((handle->mode == FOUR_DRIVE_COMMONWHEEL)||handle->mode == FOUR_DRIVE_McNamara)
		{
			if(handle->Motor3 != 0)
			{
				handle->speed3now = -SLAVE_DCMotorMiniwatt_SpeedRead(handle->Motor3);
			}
			if(handle->Motor4 != 0)
			{
				handle->speed4now = SLAVE_DCMotorMiniwatt_SpeedRead(handle->Motor4);
			}
		}
		switch(handle->mode)
		{
			case FOUR_DRIVE_COMMONWHEEL:
			case FOUR_DRIVE_McNamara:
				handle->ynow_axis = (handle->speed1now+handle->speed4now+handle->speed2now+handle->speed3now)>>2;
				if(handle->mode == FOUR_DRIVE_COMMONWHEEL)
				{
					handle->xnow_axis = 0;
				}
				handle->yawnow =  ((handle->speed1now+handle->speed4now)-(handle->speed2now+handle->speed3now))>>2;      
				break;
			case TWO_DRIVE_COMMONWHEEL:
				handle->ynow_axis = (handle->speed1now+handle->speed2now)>>1;
				handle->xnow_axis = 0;
				handle->yawnow =  ((handle->speed1now)-(handle->speed2now))>>1;
				break;
			default:
				break;
		}
	#endif
}

void UnderpanControl_Scan(UnderpanPostureDef_t* handle)
{
    uint16_t SpeedMax;
    uint16_t AbsSpeed1;
    uint16_t AbsSpeed2;
    uint16_t AbsSpeed3;
    uint16_t AbsSpeed4;
    int16_t yawbuf;
	int16_t x_axisbuf;
	int16_t y_axisbuf;
	
	yawbuf = handle->yaw;
	x_axisbuf = handle->x_axis;
    y_axisbuf = handle->y_axis;
    if(handle->mode == FOUR_DRIVE_COMMONWHEEL)
	{
		x_axisbuf = 0;
	}
    switch(handle->mode)
    {
		case FOUR_DRIVE_COMMONWHEEL:
		case FOUR_DRIVE_OMNIDIRECTIONALWHEEL:
		case FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90:
        case FOUR_DRIVE_McNamara:{
				if(handle->mode == FOUR_DRIVE_COMMONWHEEL)
				{//4个普通胶轮模式
					handle->speed1 = y_axisbuf - x_axisbuf + yawbuf;
					handle->speed2 = y_axisbuf + x_axisbuf - yawbuf;
					handle->speed3 = y_axisbuf - x_axisbuf - yawbuf;
					handle->speed4 = y_axisbuf + x_axisbuf + yawbuf;
				}
				else if(handle->mode == FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90)
				{//四轮90度安装式全向轮
					handle->speed1 = y_axisbuf + (yawbuf*handle->yawfac);
					handle->speed2 = -x_axisbuf + (yawbuf*handle->yawfac);
					handle->speed3 = -y_axisbuf + (yawbuf*handle->yawfac);
					handle->speed4 = x_axisbuf + (yawbuf*handle->yawfac);
				}
				else if(handle->mode == FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90_AUTO)
				{
					
				}
				else
				{//麦克纳姆轮&四轮45度安装式全向轮
					
					handle->speed1 = y_axisbuf - x_axisbuf + (yawbuf*handle->yawfac);
					handle->speed2 = y_axisbuf + x_axisbuf - (yawbuf*handle->yawfac);
					handle->speed3 = y_axisbuf - x_axisbuf - (yawbuf*handle->yawfac);
					handle->speed4 = y_axisbuf + x_axisbuf + (yawbuf*handle->yawfac);
				}
				AbsSpeed1 = Absolute_Value(handle->speed1);
				AbsSpeed2 = Absolute_Value(handle->speed2);
				AbsSpeed3 = Absolute_Value(handle->speed3);
				AbsSpeed4 = Absolute_Value(handle->speed4);
				
				if(AbsSpeed1 > AbsSpeed2) SpeedMax = AbsSpeed1;
				else                      SpeedMax = AbsSpeed2;
				if(SpeedMax < AbsSpeed3)  SpeedMax = AbsSpeed3;
				if(SpeedMax < AbsSpeed4)  SpeedMax = AbsSpeed4;
				
				if(SpeedMax > handle->MaxLinearSpeed)
				{
					handle->speed1 = handle->speed1 * handle->MaxLinearSpeed / SpeedMax;
					handle->speed2 = handle->speed2 * handle->MaxLinearSpeed / SpeedMax;
					handle->speed3 = handle->speed3 * handle->MaxLinearSpeed / SpeedMax;
					handle->speed4 = handle->speed4 * handle->MaxLinearSpeed / SpeedMax;
				}
            }break;
			case THREE_DRIVE_OMNIDIRECTIONALWHEEL:{//三式全向轮  
				float motor_one,abs_motor_one;
				float motor_two,abs_motor_two;
				float motor_there,abs_motor_there;
				float motor_spd_max;
				
				motor_one = (-0.5f*x_axisbuf) - (sqrt(3)*y_axisbuf/2.0f) + (handle->yawfac*yawbuf);
				motor_two = x_axisbuf + (handle->yawfac*yawbuf);
				motor_there   = (-0.5f*x_axisbuf) + (sqrt(3)*y_axisbuf/2.0f) + (handle->yawfac*yawbuf);

				if(motor_one < 0) 
					abs_motor_one = -motor_one;
				else 
					abs_motor_one = motor_one;
				if(motor_two < 0) 
					abs_motor_two = -motor_two;
				else 
					abs_motor_two = motor_two;
				if(motor_there < 0) 
					abs_motor_there = -motor_there;
				else 
					abs_motor_there = motor_there;
				
				if(abs_motor_one > abs_motor_two)    
					motor_spd_max = abs_motor_one;
				else                                 
					motor_spd_max = abs_motor_two;
				if(motor_spd_max < abs_motor_there)  
					motor_spd_max = abs_motor_there;
				
				if(motor_spd_max > handle->MaxLinearSpeed)
				{
					motor_one = motor_one * handle->MaxLinearSpeed / motor_spd_max;
					motor_two = motor_two * handle->MaxLinearSpeed / motor_spd_max;
					motor_there = motor_there * handle->MaxLinearSpeed / motor_spd_max;
				}
				
				handle->speed1 = motor_one;
				handle->speed2 = motor_two;
				handle->speed3 = motor_there;
			}break;
        case TWO_DRIVE_COMMONWHEEL:{//2个普通胶轮模式
				handle->speed1 = y_axisbuf + yawbuf;
				handle->speed2 = y_axisbuf - yawbuf;
				AbsSpeed1 = Absolute_Value(handle->speed1);
				AbsSpeed2 = Absolute_Value(handle->speed2);
				if(AbsSpeed1 > AbsSpeed2) SpeedMax = AbsSpeed1;
				else                      SpeedMax = AbsSpeed2;
				if(SpeedMax > handle->MaxLinearSpeed)
				{
					handle->speed1 = handle->speed1 * handle->MaxLinearSpeed / SpeedMax;
					handle->speed2 = handle->speed2 * handle->MaxLinearSpeed / SpeedMax;
				}
	    	}break;
        default:
            handle->x_axis = 0;
            handle->y_axis = 0;
            handle->yaw = 0;
            break;
    }
    
    UnderpanControl_SetEachMotorSpeed(handle);
}

void UnderpanControl_Init(  UnderpanPostureDef_t* handle,
                            UnderpanControlMode_e mode,
                            uint16_t Maxlinearspeed,
                            DCMotorMiniwattDef_t *Motor1,
                            DCMotorMiniwattDef_t *Motor2,
                            DCMotorMiniwattDef_t *Motor3,
                            DCMotorMiniwattDef_t *Motor4
                         )
{
//	float fac;
    memset(handle, 0, sizeof(UnderpanPostureDef_t));
    
    handle->mode = mode;
    
    handle->MaxLinearSpeed = Maxlinearspeed;
    
    handle->Motor1 = Motor1;
    handle->Motor2 = Motor2;
    handle->Motor3 = Motor3;
    handle->Motor4 = Motor4;
    
    if(handle->mode == TWO_DRIVE_COMMONWHEEL)
    {
        handle->Motor3 = 0;
        handle->Motor4 = 0;
    }
	else if(handle->mode == THREE_DRIVE_OMNIDIRECTIONALWHEEL)
	{
		handle->Motor4 = 0;
	}
//	fac = ((WHEEL_DIS+AXLE_DIS)/2.0f)/57.3f;
	handle->yawfac = 1;//fac;
}








