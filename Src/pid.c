#include "pid.h"
void PID_Init(PID *pid, float p, float i, float d, float maxI, float maxOut , char mode)
{
		pid->kp = p;
    pid->ki = i;
    pid->kd = d;
	  pid->error = 0.0f;
	  pid->lastError = 0.0f;
	  pid->last_last_error = 0.0f;
		pid->output = 0.0f;
	  pid->lastout = 0.0f;
    pid->maxiout= maxI;//输入上限
    pid->maxOutput = maxOut;//输出上限
		pid->mode = mode;
}
 /*单级pid*/
void PID_Calc(PID *pid, float set, float now)
{
	pid->last_last_error = pid->lastError ;
	
	pid->lastError = pid->error; //储存误差
  
	pid->error = set - now; //更新误差
	
	if(pid->mode == 1)//位置式
	{
   

    float dout = (pid->error - pid->lastError) * pid->kd;//计算微分

    float pout = pid->error * pid->kp;//计算比例

    pid->iout += pid->error * pid->ki;//计算积分
/*积分限幅*/
    if(pid->iout > pid->maxiout) pid->iout = pid->maxiout;
    else if(pid->iout < -pid->maxiout) pid->iout = -pid->maxiout;

    pid->output = pout + dout + pid->iout ;

	}
	else if(pid->mode == 2)//增量式
	{
		float pout = pid->kp * (pid->error - pid->lastError);
		
    pid->iout = pid->ki * pid->error;
		
    float dout = pid->kd * (pid->error - 2 * pid->lastError + pid->last_last_error);
		
    if(pid->iout > pid->maxiout) pid->iout = pid->maxiout;
		
    else if(pid->iout < -pid->maxiout) pid->iout = -pid->maxiout;
    
		pid->out = pout + pid->iout + dout;
    
		pid->plus_out = pid->last_plus_out + pid->out;
    
		pid->output = pid->plus_out;
    
		pid->last_plus_out = pid->plus_out; 
	}
	
	if(pid->output > pid->maxOutput) pid->output =   pid->maxOutput;
    else if(pid->output < -pid->maxOutput) pid->output = -pid->maxOutput;
}
/*串级pid*/
void PID_CascadeCalc(CascadePID *pid, float outerset, float outernow, float innernow)
{
    PID_Calc(&pid->outer, outerset, outernow);//外环 
    PID_Calc(&pid->inner, pid->outer.output, innernow);//内环，将外环计算结果作为内环目标值
    pid->output = pid->inner.output; 
}
