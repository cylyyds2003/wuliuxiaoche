#ifndef PID_H
#define PID_H
typedef struct
{
   	float kp, ki, kd; 
    float error, lastError; 
    float iout, maxiout;
    float output, maxOutput , out, plus_out, last_plus_out;
		char mode;
		float lastout,last_last_error;
}PID;
typedef struct
{
    PID inner; 
    PID outer; 
    float output; 
}CascadePID;
extern void PID_Init(PID *pid, float p, float i, float d, float maxI, float maxOut , char mode);
extern void PID_Calc(PID *pid, float set, float now);//单级pid计算
extern void PID_CascadeCalc(CascadePID *pid, float outerset, float outernow, float innernow);//串级pid计算

#endif
