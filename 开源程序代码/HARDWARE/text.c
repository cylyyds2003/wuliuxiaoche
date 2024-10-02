/**********************************************************************************/
#include "lcd.h"
#include "text.h"													   
#include "font.h" 
/*****************************************************************************
** 函数名称: LCD_DrawSquare
** 功能描述: 绘制5x5像素大小的正方形像素点
** x, y: 起点坐标  
** c,k: 长方形的长、宽
** Color: 长方形的颜色
*****************************************************************************/
void LCD_DrawSquare(u16 x, u16 y, u8 c, u8 k, u16 Color)
{
    u8 i, j;
    for (i = 0; i < c; i++)
    {
        for (j = 0; j <k; j++)
        {
            LCD_DrawPoint(x + i, y + j, Color);
        }
    }
}

/*****************************************************************************
** 函数名称: LCD_ShowChar
** 功能描述: 在指定位置显示一个字符
**在指定位置显示一个字符
**x:0~234
**y:0~308
**num:要显示的字符:" "--->"~"
**size:字体大小 12/16
**mode:叠加方式(1)还是非叠加方式(0)
*****************************************************************************/
void LCD_ShowChar(u16 x,u16 y,u8 num,u8 size,u8 mode,u16 Color)
{  

    u8 temp;
    u8 j,t;
	  u8 count;
	u16 x0=x;   
    if(x>MAX_CHAR_POSX||y>MAX_CHAR_POSY)return;	    
	//设置窗口		   
	num=num-' ';//得到偏移后的值
	if(mode==0) //正常显示
	{
		for(j=0;j<size;j++)
		{
			
		  if(size==12)
			{
				temp=asc2_1206[num][j];
				count=6;
			}//调用1206字体
			else if(size==16)
			{
				temp=asc2_1608[num][j];	
				count=8;
			}				//调用1608字体
			else if(size==24)
			{
				temp=asc2_2412[num][j];	
				count=36;
			}				//调用1608字体
			for(t=0;t<count;t++)
		    {                 
		    if(temp&0x01)
				{
				LCD_DrawPoint(x,y,Color);	
				}
				else 
				{
				LCD_DrawPoint(x,y,BACK_COLOR);	
				}
				temp>>=1; 
				x++;
		    }
			x=x0;
			y++;
		}	
	}   	   	 	  
}   


/*****************************************************************************
** 函数名称: LCD_ShowString
** 功能描述: 显示字符串函数
** x,y:起点坐标  
** *p:字符串起始地址
** 用16字体
*****************************************************************************/
void LCD_ShowString(u16 x,u16 y,const u8 *pstr,u16 Color)
{         
    while(*pstr!='\0')
    {       
        if(x>MAX_CHAR_POSX)
        {
         x=0;
				 y+=STR_HEIGHT;
        }
        if(y>MAX_CHAR_POSY)
        {
         y=x=0;
        LCD_Clear(WHITE);
        }
        LCD_ShowChar(x,y,*pstr,16,0,Color);
        x+=STR_WIDTH;
        pstr++;
    }  
}

/*****************************************************************************
** 函数名称: LCD_ShowNumber
** 功能描述: 显示数字函数
** x,y:起点坐标  
** num:字符串起始地址
** size: 字体号数
**Color：字体颜色
*****************************************************************************/
void LCD_ShowNumber(u16 x, u16 y, int num, u8 size, u16 Color) 
{
    char str[5]; // 5个字符数组
    sprintf(str, "%04d", num); // 显示四位，补0
    LCD_ShowString(x, y, (u8 *)str, Color); // 利用字符串将其显示出来
}

/*****************************************************************************
** 函数名称: LCD_ShowNumber
** 功能描述: 显示数字函数
** x,y:起点坐标  
** num: 浮点数的值
** size: 字体号数
**Color：字体颜色
*****************************************************************************/

void LCD_ShowFloat(u16 x, u16 y, float num, u8 size, u16 Color) 
{
    char str[10]; // 足够大的字符转换成字符串

    // 将浮点数转换成字符串
    sprintf(str, "%.2f", num);

    // 显示
    LCD_ShowString(x, y, (u8 *)str, Color);
}



