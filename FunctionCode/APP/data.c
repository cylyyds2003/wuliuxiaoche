/* 包含头文件 ----------------------------------------------------------------*/
#include "data.h"
#include "app.h"
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include "separate_button.h"
#include "pid.h"
#include "usart.h"

/* 私有类型定义 --------------------------------------------------------------*/

/* 私有宏定义 ----------------------------------------------------------------*/

/* 私有变量 ------------------------------------------------------------------*/


/* 扩展变量 ------------------------------------------------------------------*/


/* 私有函数原形 --------------------------------------------------------------*/
/* 函数体 --------------------------------------------------------------------*/
void first_get_from_tray(void)  /*从原料区取物料*/     //后续把夹取放置的代码也封装一下，传入第几个物料的参数
{
          /*********************取第一个料****************/
        switch (first_pick[0])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************取第二个料****************/
        switch (first_pick[1])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************取第三个料****************/
        switch (first_pick[2])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
  
}

void first_work_in_rough_area(void)  /*把物料放到粗加工区再取回来*/
{
          /***************************取第一个料****************/
          /*执行夹取动作代码*/
        
          /*执行夹取动作代码*/
          /***************发送指令给openmv寻找第一个颜色的圈****************************/
        switch (first_pick[0])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
          /*********************取第二个料****************/
          /***************发送指令给openmv寻找第二个颜色的圈****************************/
        switch (first_pick[1])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
          /*********************取第三个料****************/
          /*执行夹取动作代码*/
        
          /*执行夹取动作代码*/
          /***************发送指令给openmv寻找第三个颜色的圈****************************/
        switch (first_pick[2])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
    /****************************************把物料从粗加工区取回来*************************************/
          /*********************取第一个料****************/
        switch (first_pick[0])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************取第二个料****************/
        switch (first_pick[1])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************取第三个料****************/
        switch (first_pick[2])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/

}

void first_work_in_temporary_area(void)/*把物料放到暂存区*/
{
  
    /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
      /***************************取第一个料****************/
      /*执行夹取动作代码*/
    
      /*执行夹取动作代码*/
      /***************发送指令给openmv寻找第一个颜色的圈****************************/
    switch (first_pick[0])
    {    
      case red: 
            state = search_red_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);
          break;
      case green:
            state = search_green_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);
          break;
      default:
            state = search_blue_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);          
    }
      /*执行放置动作代码*/
    
      /*执行放置动作代码*/
    
      /*********************取第二个料****************/
      /***************发送指令给openmv寻找第二个颜色的圈****************************/
    switch (first_pick[1])
    {    
      case red: 
            state = search_red_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);
          break;
      case green:
            state = search_green_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);
          break;
      default:
            state = search_blue_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);          
    }
      /*执行放置动作代码*/
    
      /*执行放置动作代码*/
    
      /*********************取第三个料****************/
      /*执行夹取动作代码*/
    
      /*执行夹取动作代码*/
      /***************发送指令给openmv寻找第三个颜色的圈****************************/
    switch (first_pick[2])
    {    
      case red: 
            state = search_red_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);
          break;
      case green:
            state = search_green_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);
          break;
      default:
            state = search_blue_circles;
            HAL_UART_Transmit(&huart3,&state,2,1000);          
    }
      /*执行放置动作代码*/
    
      /*执行放置动作代码*/
}
void first_path(void)   /*起点-->原料区-->粗加工区-->暂存区*/
{
	
	/*****************出门口**********************************************/
		left_hanshu(10,0);
  /*****************前进到扫码的地方*************************************/
		forward_hanshu(60,0);
  /*****************停下来扫码*************************************/
    state = ready_to_scan_QRcode;
    HAL_UART_Transmit(&huart3,&state,2,1000);
//		while(first_pick[0]==0	&&	first_pick[1]==0	&&	first_pick[2]==0
//			&&	second_pick[0]==0	&&	second_pick[1]==0	&&	second_pick[2]==0)
//		{}
					
  /*****************从扫码区前往原料区*************************************/
    forward_hanshu(50,0);    
  /*****************停下来取料*************************************/
    stop_hanshu(1000,0,stuff_position_x,stuff_position_y);
    first_get_from_tray();
  /*****************从原料区前往粗加工区*************************************/
		back_hanshu(35,0);  
		left_hanshu(150,0);
  /****************************************停下来放料到粗加工区*************************************/
    stop_hanshu(0,0,circles_x,circles_y);//这里可以不给停下来的时间是因为可以直接执行取料代码
  
  /*放料到粗加工区再取回来*/
    first_work_in_rough_area();
  
  /****************************************从粗加工区前往暂存区*************************************/
    forward_hanshu(70,0);  
    right_hanshu(70,0);
  /**********************************停下来放料到暂存区*************************************/
    stop_hanshu(0,0,circles_x,circles_x);
  /*把物料放到暂存区*/
    first_work_in_temporary_area();
}


void second_get_from_tray(void)
{
          /***********第二次   取第一个料****************/
        switch (second_pick[0])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************取第二个料****************/
        switch (second_pick[1])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************取第三个料****************/
        switch (second_pick[2])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/

}
void second_work_in_rough_area(void)  /*把物料放到粗加工区再取回来*/
{
        /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
          /***************************从料盘取第一个料****************/
          /*执行夹取动作代码*/
        
          /*执行夹取动作代码*/
          /***************发送指令给openmv寻找第一个颜色的圈****************************/
        switch (second_pick[0])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
          /*********************从料盘取第二个料****************/
          /***************发送指令给openmv寻找第二个颜色的圈****************************/
        switch (second_pick[1])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
          /*********************从料盘取第三个料****************/
          /*执行夹取动作代码*/
        
          /*执行夹取动作代码*/
          /***************发送指令给openmv寻找第三个颜色的圈****************************/
        switch (second_pick[2])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
    /****************************************把物料从粗加工区取回来*************************************/
          /*********************从粗加工区取第一个料****************/
        switch (second_pick[0])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************从粗加工区取第二个料****************/
        switch (second_pick[1])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/
          /*********************从粗加工区取第三个料****************/
        switch (second_pick[2])
        {    
          case red: 
                state = search_red;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行夹取与放置动作代码*/
        
          /*执行夹取与放置动作代码*/

}
void second_work_in_temporary_area(void)/*把物料放到暂存区*/
{
        /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
          /***************************从料盘取第一个料****************/
          /*执行夹取动作代码*/
        
          /*执行夹取动作代码*/
          /***************发送指令给openmv寻找第一个颜色的圈****************************/
        switch (second_pick[0])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
          /*********************从料盘取第二个料****************/
          /***************发送指令给openmv寻找第二个颜色的圈****************************/
        switch (second_pick[1])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
          /*********************从料盘取第三个料****************/
          /*执行夹取动作代码*/
        
          /*执行夹取动作代码*/
          /***************发送指令给openmv寻找第三个颜色的圈****************************/
        switch (second_pick[2])
        {    
          case red: 
                state = search_red_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          case green:
                state = search_green_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);
              break;
          default:
                state = search_blue_circles;
                HAL_UART_Transmit(&huart3,&state,2,1000);          
        }
          /*执行放置动作代码*/
        
          /*执行放置动作代码*/
        
 
}
void second_path(void)
{
  /****************************************暂存区前往原料区第二次取料*************************************/
    right_hanshu(70,0);   
        
 		back_hanshu(50,0);
    /*****************第二次  停下来取料*************************************/
    second_get_from_tray();
		stop_hanshu(0,0,stuff_position_x,stuff_position_y);
    /*****************从原料区前往粗加工区*************************************/
 		back_hanshu(35,0);
    
 		left_hanshu(150,0);
    /****************************************停下来放料*************************************/
    stop_hanshu(0,0,circles_x,circles_y);
      
    second_work_in_rough_area();  
    /***********************************第二次    从粗加工区前往暂存区*************************************/
 		forward_hanshu(70,0);
    
 		right_hanshu(70,0);
    /****************************************停下来放料到暂存区*************************************/
    stop_hanshu(0,0,circles_x,circles_y);
  
    second_work_in_temporary_area();

}





/*=====================================================以下为代码备份*============================================/

/***********************************************下面是pid输出写在定时器中断里面********************************************************/
//    switch (sportflag)
//    {  
//      case left:	   PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case right:    PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case forward:  PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case back:     PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case stop:     PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      
//    }
/********************************************************下面是路径********************************************************/

///*****************前进到扫码的地方*************************************/
//     forward_hanshu(80);
//  /*****************停下来扫码*************************************/
//    state = ready_to_scan_QRcode;
//    HAL_UART_Transmit(&huart3,&state,2,1000);
//    stop_hanshu(2500);
//  /*****************从扫码区前往原料区*************************************/
//    forward_hanshu(90);    
//  /*****************停下来取料*************************************/
//          /*********************取第一个料****************/
//        switch (first_pick[0])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************取第二个料****************/
//        switch (first_pick[1])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************取第三个料****************/
//        switch (first_pick[2])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//  /*****************从原料区前往粗加工区*************************************/
//		back_hanshu(50);
//    
//		left_hanshu(215);
//    /****************************************停下来放料*************************************/
//    stop_hanshu(0);//这里可以不给停下来的时间是因为可以直接执行取料代码
//        /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
//          /***************************取第一个料****************/
////        switch (first_pick[0])
////        {    
////          case red: 
////                state = search_red;                             /*这里写错了，可以直接用数组储存物料在料盘上的位置，不需要视觉*/
////                HAL_UART_Transmit(&huart3,&state,2,1000);
////              break;
////          case green:
////                state = search_green;
////                HAL_UART_Transmit(&huart3,&state,2,1000);
////              break;
////          default:
////                state = search_blue;
////                HAL_UART_Transmit(&huart3,&state,2,1000);          
////        }
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第一个颜色的圈****************************/
//        switch (first_pick[0])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************取第二个料****************/
//          /***************发送指令给openmv寻找第二个颜色的圈****************************/
//        switch (first_pick[1])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************取第三个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第三个颜色的圈****************************/
//        switch (first_pick[2])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//    /****************************************把物料从粗加工区取回来*************************************/
//          /*********************取第一个料****************/
//        switch (first_pick[0])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************取第二个料****************/
//        switch (first_pick[1])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************取第三个料****************/
//        switch (first_pick[2])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//  /****************************************从粗加工区前往暂存区*************************************/
//    forward_hanshu(80);  

//    right_hanshu(100
//        );
//  /**********************************第一次     停下来放料到暂存区*************************************/
//    stop_hanshu(0);
//        /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
//          /***************************取第一个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第一个颜色的圈****************************/
//        switch (first_pick[0])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************取第二个料****************/
//          /***************发送指令给openmv寻找第二个颜色的圈****************************/
//        switch (first_pick[1])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************取第三个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第三个颜色的圈****************************/
//        switch (first_pick[2])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
/////***************************************************第一圈正式结束**************************************************************************///
/////*************************************************以下是第二圈的代码**************************************************************************///
//        
//        
//        
//  /****************************************暂存区前往原料区第二次取料*************************************/
//    right_hanshu(100);   
//        
// 		back_hanshu(50);
//    /*****************第二次  停下来取料*************************************/
//          /***********第二次   取第一个料****************/
//        switch (second_pick[0])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************取第二个料****************/
//        switch (second_pick[1])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************取第三个料****************/
//        switch (second_pick[2])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//    /*****************从原料区前往粗加工区*************************************/
// 		back_hanshu(10);
//    
// 		left_hanshu(10);
//    /****************************************停下来放料*************************************/
//    stop_hanshu(0);
//        /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
//          /***************************从料盘取第一个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第一个颜色的圈****************************/
//        switch (second_pick[0])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************从料盘取第二个料****************/
//          /***************发送指令给openmv寻找第二个颜色的圈****************************/
//        switch (second_pick[1])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************从料盘取第三个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第三个颜色的圈****************************/
//        switch (second_pick[2])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//    /****************************************把物料从粗加工区取回来*************************************/
//          /*********************从粗加工区取第一个料****************/
//        switch (second_pick[0])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************从粗加工区取第二个料****************/
//        switch (second_pick[1])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//          /*********************从粗加工区取第三个料****************/
//        switch (second_pick[2])
//        {    
//          case red: 
//                state = search_red;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行夹取与放置动作代码*/
//        
//          /*执行夹取与放置动作代码*/
//  /***********************************第二次    从粗加工区前往暂存区*************************************/
// 		forward_hanshu(100);
//    
// 		right_hanshu(50);
//    /****************************************停下来放料到暂存区*************************************/
//    stop_hanshu(0);
//        /*****************发送指令给openmv寻找第一个颜色的物料*************************************/
//          /***************************从料盘取第一个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第一个颜色的圈****************************/
//        switch (second_pick[0])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************从料盘取第二个料****************/
//          /***************发送指令给openmv寻找第二个颜色的圈****************************/
//        switch (second_pick[1])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//          /*********************从料盘取第三个料****************/
//          /*执行夹取动作代码*/
//        
//          /*执行夹取动作代码*/
//          /***************发送指令给openmv寻找第三个颜色的圈****************************/
//        switch (second_pick[2])
//        {    
//          case red: 
//                state = search_red_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          case green:
//                state = search_green_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);
//              break;
//          default:
//                state = search_blue_circles;
//                HAL_UART_Transmit(&huart3,&state,2,1000);          
//        }
//          /*执行放置动作代码*/
//        
//          /*执行放置动作代码*/
//        
//        
//        
//        
///************************************************************前往启停区，完结撒花***********************************************************************/        
// 		back_hanshu(100);
