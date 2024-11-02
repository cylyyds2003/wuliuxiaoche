/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "app.h"
#include "data.h"
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include "separate_button.h"
#include "pid.h"
#include "usart.h"
/* ˽�����Ͷ��� --------------------------------------------------------------*/
uint8_t flag = 0;uint16_t t=0;int16_t speed;uint8_t count = 0;int16_t distance;
uint8_t lj = 0;
int32_t one,two,three,four;
uint8_t sportflag;
uint8_t state = ready_to_scan_QRcode;
uint8_t xuanzhuan_num = 0;
//uint8_t run_state1 = 1;uint8_t run_state2 = 1;uint8_t run_state3 = 1;uint8_t run_state4 = 1;
/* ˽�б��� ------------------------------------------------------------------*/
/*******6ͨ�����ģ����������*******/
SteeringEngine6CHDef_t Servo_Device_S;
//uint16_t AngleValue[SERVO_NUM_MAX] = {1500,1500,1000,1500,2500,500};
uint16_t AngleValue[SERVO_NUM_MAX] = {1500,1500,1000,1500,500,1000};    //arm3��arm2�ֱ�Ϊ900��1500ʱopenmvˮƽ
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
/*******ֱ���������ģ����������*******/
DCMotorMiniwattDef_t DCMotorMiniwatt1_S;
DCMotorMiniwattDef_t DCMotorMiniwatt2_S;
DCMotorMiniwattDef_t DCMotorMiniwatt3_S;
DCMotorMiniwattDef_t DCMotorMiniwatt4_S;
/*******���̿�����������*******/
UnderpanPostureDef_t UnderpanPosture_S;
/* ��չ���� ------------------------------------------------------------------*/
<<<<<<< HEAD
PID position_id1;//id   1
PID position_id2;//id   1
PID position_id3;//id   1
PID position_id4;//id   1
PID	yaw_control;//�ǶȻ�pid�ṹ��
PID x_control;//������ƽṹ��
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
/* ������ --------------------------------------------------------------------*/
/***********************************************************************************************

                                       Ӳ�����ú���

************************************************************************************************/
<<<<<<< HEAD
void PID_out(uint8_t flag,int16_t setcm ,float angle,uint8_t x,uint8_t y);
=======
void PID_out(uint8_t flag,int16_t set);
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671

static uint8_t Wireless_UP(void)
{
    if(PS2_Data.DATE.key1_U.bit.UP == 0)return 1; //��������
	else return 0;
}
static uint8_t Wireless_DOWN(void)
{
    if(PS2_Data.DATE.key1_U.bit.DOWN == 0)return 1;//��������
	else return 0;
}
static uint8_t Wireless_LEFT(void)
{
    if(PS2_Data.DATE.key1_U.bit.LEFT == 0)return 1;//��������
	else return 0;
}
static uint8_t Wireless_RIGHT(void)
{
    if(PS2_Data.DATE.key1_U.bit.RIGHT == 0) return 1;//�������� 
	else return 0;
}
static uint8_t Wireless_TRI(void)
{//������
    if(PS2_Data.DATE.key2_U.bit.TRI == 0)return 1;//��������
	else return 0;
}
static uint8_t Wireless_CIRCLE(void)
{//Բ
    if(PS2_Data.DATE.key2_U.bit.CIRCLE == 0)return 1;//��������
	else return 0;	
}
static uint8_t Wireless_FORK(void)
{//��
    if(PS2_Data.DATE.key2_U.bit.FORK == 0)return 1;//��������
	else return 0;
}
static uint8_t Wireless_REC(void)
{//����
    if(PS2_Data.DATE.key2_U.bit.REC == 0)return 1;//��������
	else return 0;
}
static uint8_t Wireless_L1(void)
{//L1
    if(PS2_Data.DATE.key2_U.bit.L1 == 0)return 1;//��������
	else return 0;
}
static uint8_t Wireless_R1(void)
{//R1
    if(PS2_Data.DATE.key2_U.bit.R1 == 0)return 1;//��������
	else return 0;
}
/***********************************************************************************************

                                       Ӧ��������

************************************************************************************************/
/*******�������*******/
<<<<<<< HEAD
static void ServoSetPluseAndTime(uint8_t mode, uint16_t pwmval,uint16_t time)//������ƺ���
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
    )//�жϵ���Ŀ��λ�ã�������0.3cm
	{
		count++;
    if(count > 100)//�����־λ�ۼƵ���120
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
/***********��ת270��ʱ����Ҫ�޸�Ŀ��ֵ***********/
void forward_hanshu(int16_t distance,float set_angle) //ǰ���ĺ���
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

void back_hanshu(int16_t distance,float set_angle) //���˵ĺ���
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

void left_hanshu(int16_t distance,float set_angle) //����ĺ���
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

void right_hanshu(int16_t distance,float set_angle) //���ҵĺ���
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
void stop_hanshu(uint16_t stop_time,float set_angle,uint8_t x,uint8_t y) //ֹͣ�ĺ���
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
    HAL_Delay(stop_time);     //Ҳ���԰�����ע�͵������� sportflag = stop����
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

                                       Ӧ���¼����жϣ�����

************************************************************************************************/
/** @brief  ��ʱ�ж��¼�
  * @param  None
  * @retval None
  */
<<<<<<< HEAD
static void TimeBreakExecution_Handler(void) //1ms
{
	static uint16_t time = 0;
										/*���ò��ÿ������Լ���װһ�������������*/  
  
      PID_out(ID1,one,angle,x_set,y_set);
      PID_out(ID2,two,angle,x_set,y_set);
      PID_out(ID3,three,angle,x_set,y_set);
      PID_out(ID4,four,angle,x_set,y_set); 
    /*    sportflag�Ƿ���lj��Ϊ��ֻ�����Ŀ�긳һ��ֵ�趨��      */ 
=======
static void TimeBreakExecution_Handler(void) 
{
	static uint16_t time = 0;
	PID_out(ID1,4000);
	PID_out(ID2,4000);
	PID_out(ID3,4000);
	PID_out(ID4,4000);
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
	//=========������ƺ���==============================
	time++;
	if(time == 20)
	{//20MS����һ�ζ������ָ��
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
	//=========����ɨ�躯��==============================
	button_ticks();
	//==========���̿���ɨ�躯��=====================
	//UnderpanControl_Scan(&UnderpanPosture_S);       //scan������ˣ��ᶥ��pid�����
=======
                                           AngleValue[0],AngleTimeValue[0],
									       AngleValue[1],AngleTimeValue[1],
                                           AngleValue[2],AngleTimeValue[2],
										   AngleValue[3],AngleTimeValue[3],
									       AngleValue[4],AngleTimeValue[4],
                                           AngleValue[5],AngleTimeValue[5]); 
	}
	//=========����ɨ�躯��==============================
	button_ticks();
	//==========���̿���ɨ�躯��=====================
	//UnderpanControl_Scan(&UnderpanPosture_S); 
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
	//=========CANͨѶЭ��============================
	Tim_GetCurrentTimeAdd_Scan1MS();    //����1ms����ɨ��˺���
	CANCommunication_Scan();            //���Ҳ1ms����ɨ��
}
<<<<<<< HEAD
=======
/**
  * @brief  ���������¼�
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

                                       Ӧ��������

************************************************************************************************/
/**
  * @brief  Ӧ�ó�ʼ��
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
  
	PID_Calc(&yaw_control,angle,yaw);//�ǶȻ�
  
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
								/***************************ǰ�����˻������ƶ��������ֲ��ٿ��ƽǶ�*******************************/
								/***************************��ÿ���ƶ�ֻ����������������ǶȻ�***********************************/
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

//�����ȡ����    
/*Ŀǰ�����������뷨
����һ����ʱ���Ӿ�һֱ���ŵ���ɨ�裬��е�۲����������ƶ�ֱ����׼��Ȼ���е�����¼�ȡ
��������дһ�����������˶�ѧ���㣬����openmv�õ�������ֱ�Ӳٿض���Ƕ�*/    //2024.10.31 ���ݳ˷� ����ע��ϣ�������Ժ��ѧ��ѧ��
//ע�����ƶ�arm1���ƶ��ϲ�����Ȼ���ܻ�ײ������
void get_from_tray()
{
  xuanzhuan_num++;
  //�����������ͨ����
    //arm3��arm2�ֱ�Ϊ900��1500ʱopenmvˮƽ
    /*�������̵ı�4*/ AngleValue[SERVO_ARM1]        = 1500; //����ֱ�������
    /*�м�Ķ��3*/   AngleValue[SERVO_ARM2]        = 1000; //��ʼ����
    /*������ת���5*/ AngleValue[SERVO_ROTARY]      = 2300; //��ת��������
  
    HAL_Delay(2000);      //��ʱ���Ҹģ�Ҫ��Ȼ��������ײ�������֪����
  
    /*�������̵ı�4*/ AngleValue[SERVO_ARM1]        = 2150; //��ʼ����
//    HAL_Delay(300);
    /*������צ2*/     AngleValue[SERVO_ARM3]        = 900;  //��ʼ����
//    HAL_Delay(300);
    /*�м�Ķ��3*/   AngleValue[SERVO_ARM2]        = 1500; //��ʼ����
    HAL_Delay(300);
    /*��צ�ſ�1*/     AngleValue[SERVO_CLAW]        = 1000; //�ɿ�צ��
    
    ///*������ת���6*/ AngleValue[SERVO_wuliaopan]   = 1000; //��������
  if(xuanzhuan_num == 1)
    {
      AngleValue[SERVO_wuliaopan]   = 1500;//1700
    }
  if(xuanzhuan_num == 2)
    {
      AngleValue[SERVO_wuliaopan]   = 1500-889;//2400����
    }
  if(xuanzhuan_num == 3)
    {
      AngleValue[SERVO_wuliaopan]   = 1500+889;//1000����
      xuanzhuan_num = 0;
    }

              
    HAL_Delay(1500);

    /*��צ*/          AngleValue[SERVO_CLAW]        = 1500; //SERVO_CLAW    //��צ���

}
//��2500-500��*angle/180+500
void put_to_plate()
{
    //arm3��arm2�ֱ�Ϊ900��1500ʱopenmvˮƽ
    /*�������̵ı�4*/ AngleValue[SERVO_ARM1]        = 1500; //�ֱ���ֱ
    HAL_Delay(300);
    /*������ת���5*/ AngleValue[SERVO_ROTARY]      = 700-50;  //��������
    HAL_Delay(600);
    /*�������̵ı�4*/ AngleValue[SERVO_ARM1]        = 800+100+50+50;  //����
    HAL_Delay(300);
    /*������צ2*/     AngleValue[SERVO_ARM3]        = 1500+100+100;  //SERVO_ARM3    //��3�����������צ�ı�
    HAL_Delay(300);
    /*�м�Ķ��3*/   AngleValue[SERVO_ARM2]        = 1500; //SERVO_ARM2    //��2������м�ı�
    HAL_Delay(1500);
    /*��צ�ſ�1*/     AngleValue[SERVO_CLAW]        = 1300; //���Ϸŵ�������
    HAL_Delay(500);
    
//    /*������צ2*/     AngleValue[SERVO_ARM3]        = 900;  //SERVO_ARM3    //��3�����������צ�ı�
//    HAL_Delay(300);
//    /*�м�Ķ��3*/   AngleValue[SERVO_ARM2]        = 1500; //SERVO_ARM2    //��2������м�ı�
//    HAL_Delay(300);

//    
//    /*������ת���6*/ AngleValue[SERVO_wuliaopan]   = 1000; //SERVO_ARM2    //���̶��     
//              
//    HAL_Delay(1500);

//    /*��צ*/          AngleValue[SERVO_CLAW]        = 1500; //SERVO_CLAW    //��צ���


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
	/**********************������ʼ��**************************/  
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
	/**********************PS2ң�س�ʼ��***********************/
	PS2_SetInit();
	/**********************���ݳ�ʼ��**************************/
	SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt1_S,1);//ID��1
	SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt2_S,2);//ID��2
    SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt3_S,3);//ID��3
	SLAVE_DCMotorMiniwatt_Init(&DCMotorMiniwatt4_S,4);//ID��4
	
	SLAVE_SteeringEngine6CH_Init(&Servo_Device_S,1); //��ʼ���ģ������,IDΪ1
	
	UnderpanControl_Init(&UnderpanPosture_S,
<<<<<<< HEAD
                         FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90,
=======
                         FOUR_DRIVE_OMNIDIRECTIONALWHEEL_90_AUTO,
>>>>>>> 21cb47735d7f375d8cec3fc12fde12452cbe2671
						 400,
						 &DCMotorMiniwatt1_S,  //1��
						 &DCMotorMiniwatt2_S,  //2��
						 &DCMotorMiniwatt3_S,  //3��
						 &DCMotorMiniwatt4_S); //4��
	/**********************CAN��ʼ��***************************/
	CANCommunication_Init();
	PID_Cascade_Init();
	/********************��ʱ����ʼ��**************************/
	/*
	��TimeBreakExecution_Handler���ݵ���ʱ���жϺ�����ִ�У�
	���ǰѶ�ʱ���Ѿ����ó�1msһ�δ����жϣ�
	˵��TimeBreakExecution_HandlerҲ��1msִ��һ�Ρ�
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
		{//�ж��ֱ��Ƿ�Ϊ���ģʽ���ǣ�ָʾ��LED����
			HAL_Delay(50);	 //��ʱ����Ҫ����ȥ
			LED1(bright);
			for(a=0; a<8; a++)//������ݻ�����
				PS2_Data.byte[a] = 0x00;
			PS2_ReadData();
			y_axisbuff = (128 - PS2_Data.DATE.PSS_LY)*2;//����ٶ�256
			x_axisbuff = (PS2_Data.DATE.PSS_LX - 128)*2;
			yawbuff = (128 - PS2_Data.DATE.PSS_RY)*2;
			
			upperyawbuff = (PS2_Data.DATE.PSS_RX - 128)*2;
			
			if(ABS(y_axisbuff) < 50) y_axisbuff = 0; //����ң���м�λ�õ����
		    if(ABS(yawbuff) < 50) yawbuff = 0;
		    if(ABS(x_axisbuff) < 50) x_axisbuff = 0;
			if(ABS(upperyawbuff) < 50) upperyawbuff = 0;
			
		}
		else
		{//�ж��ֱ����Ǻ��ģʽ��ָʾ��LEDϨ��
			LED1(extinguish);
			y_axisbuff = 0;
			x_axisbuff = 0;
			yawbuff = 0;
			PS2_ClearData();
		}
<<<<<<< HEAD
		HAL_Delay(50);//��ɾ��ɾ�˿��ܳ�����
    
    /*���·���߼��ܳ������ò��ÿ����Է�װһ��*///cyl�ѷ�װ
    //·���߼������������
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
/////***************************************************��һȦ��ʽ����**************************************************************************///
/////*************************************************�����ǵڶ�Ȧ�Ĵ���**************************************************************************///
//        
//    second_path();    
//        
///************************************************************ǰ����ͣ�����������***********************************************************************/        
//		right_hanshu(70,0);
//		back_hanshu(150,0);
    while(1);//���Ӹ�while(1)���������λ�ã���ֹ������ͷ���лص�ԭλ        
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
