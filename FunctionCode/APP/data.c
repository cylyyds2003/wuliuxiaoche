/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "data.h"
#include "app.h"
#include "UnderpanControl_Motor/UnderpanControl_Motor.h"
#include "separate_button.h"
#include "pid.h"
#include "usart.h"

/* ˽�����Ͷ��� --------------------------------------------------------------*/

/* ˽�к궨�� ----------------------------------------------------------------*/

/* ˽�б��� ------------------------------------------------------------------*/


/* ��չ���� ------------------------------------------------------------------*/


/* ˽�к���ԭ�� --------------------------------------------------------------*/
/* ������ --------------------------------------------------------------------*/
void first_get_from_tray(void)  /*��ԭ����ȡ����*/     //�����Ѽ�ȡ���õĴ���Ҳ��װһ�£�����ڼ������ϵĲ���
{
          /*********************ȡ��һ����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************ȡ�ڶ�����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************ȡ��������****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
  
}

void first_work_in_rough_area(void)  /*�����Ϸŵ��ּӹ�����ȡ����*/
{
          /***************************ȡ��һ����****************/
          /*ִ�м�ȡ��������*/
        
          /*ִ�м�ȡ��������*/
          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
          /*********************ȡ�ڶ�����****************/
          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
          /*********************ȡ��������****************/
          /*ִ�м�ȡ��������*/
        
          /*ִ�м�ȡ��������*/
          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
    /****************************************�����ϴӴּӹ���ȡ����*************************************/
          /*********************ȡ��һ����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************ȡ�ڶ�����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************ȡ��������****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/

}

void first_work_in_temporary_area(void)/*�����Ϸŵ��ݴ���*/
{
  
    /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
      /***************************ȡ��һ����****************/
      /*ִ�м�ȡ��������*/
    
      /*ִ�м�ȡ��������*/
      /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
      /*ִ�з��ö�������*/
    
      /*ִ�з��ö�������*/
    
      /*********************ȡ�ڶ�����****************/
      /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
      /*ִ�з��ö�������*/
    
      /*ִ�з��ö�������*/
    
      /*********************ȡ��������****************/
      /*ִ�м�ȡ��������*/
    
      /*ִ�м�ȡ��������*/
      /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
      /*ִ�з��ö�������*/
    
      /*ִ�з��ö�������*/
}
void first_path(void)   /*���-->ԭ����-->�ּӹ���-->�ݴ���*/
{
	
	/*****************���ſ�**********************************************/
		left_hanshu(10,0);
  /*****************ǰ����ɨ��ĵط�*************************************/
		forward_hanshu(60,0);
  /*****************ͣ����ɨ��*************************************/
    state = ready_to_scan_QRcode;
    HAL_UART_Transmit(&huart3,&state,2,1000);
//		while(first_pick[0]==0	&&	first_pick[1]==0	&&	first_pick[2]==0
//			&&	second_pick[0]==0	&&	second_pick[1]==0	&&	second_pick[2]==0)
//		{}
					
  /*****************��ɨ����ǰ��ԭ����*************************************/
    forward_hanshu(50,0);    
  /*****************ͣ����ȡ��*************************************/
    stop_hanshu(1000,0,stuff_position_x,stuff_position_y);
    first_get_from_tray();
  /*****************��ԭ����ǰ���ּӹ���*************************************/
		back_hanshu(35,0);  
		left_hanshu(150,0);
  /****************************************ͣ�������ϵ��ּӹ���*************************************/
    stop_hanshu(0,0,circles_x,circles_y);//������Բ���ͣ������ʱ������Ϊ����ֱ��ִ��ȡ�ϴ���
  
  /*���ϵ��ּӹ�����ȡ����*/
    first_work_in_rough_area();
  
  /****************************************�Ӵּӹ���ǰ���ݴ���*************************************/
    forward_hanshu(70,0);  
    right_hanshu(70,0);
  /**********************************ͣ�������ϵ��ݴ���*************************************/
    stop_hanshu(0,0,circles_x,circles_x);
  /*�����Ϸŵ��ݴ���*/
    first_work_in_temporary_area();
}


void second_get_from_tray(void)
{
          /***********�ڶ���   ȡ��һ����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************ȡ�ڶ�����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************ȡ��������****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/

}
void second_work_in_rough_area(void)  /*�����Ϸŵ��ּӹ�����ȡ����*/
{
        /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
          /***************************������ȡ��һ����****************/
          /*ִ�м�ȡ��������*/
        
          /*ִ�м�ȡ��������*/
          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
          /*********************������ȡ�ڶ�����****************/
          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
          /*********************������ȡ��������****************/
          /*ִ�м�ȡ��������*/
        
          /*ִ�м�ȡ��������*/
          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
    /****************************************�����ϴӴּӹ���ȡ����*************************************/
          /*********************�Ӵּӹ���ȡ��һ����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************�Ӵּӹ���ȡ�ڶ�����****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/
          /*********************�Ӵּӹ���ȡ��������****************/
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
          /*ִ�м�ȡ����ö�������*/
        
          /*ִ�м�ȡ����ö�������*/

}
void second_work_in_temporary_area(void)/*�����Ϸŵ��ݴ���*/
{
        /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
          /***************************������ȡ��һ����****************/
          /*ִ�м�ȡ��������*/
        
          /*ִ�м�ȡ��������*/
          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
          /*********************������ȡ�ڶ�����****************/
          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
          /*********************������ȡ��������****************/
          /*ִ�м�ȡ��������*/
        
          /*ִ�м�ȡ��������*/
          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
          /*ִ�з��ö�������*/
        
          /*ִ�з��ö�������*/
        
 
}
void second_path(void)
{
  /****************************************�ݴ���ǰ��ԭ�����ڶ���ȡ��*************************************/
    right_hanshu(70,0);   
        
 		back_hanshu(50,0);
    /*****************�ڶ���  ͣ����ȡ��*************************************/
    second_get_from_tray();
		stop_hanshu(0,0,stuff_position_x,stuff_position_y);
    /*****************��ԭ����ǰ���ּӹ���*************************************/
 		back_hanshu(35,0);
    
 		left_hanshu(150,0);
    /****************************************ͣ��������*************************************/
    stop_hanshu(0,0,circles_x,circles_y);
      
    second_work_in_rough_area();  
    /***********************************�ڶ���    �Ӵּӹ���ǰ���ݴ���*************************************/
 		forward_hanshu(70,0);
    
 		right_hanshu(70,0);
    /****************************************ͣ�������ϵ��ݴ���*************************************/
    stop_hanshu(0,0,circles_x,circles_y);
  
    second_work_in_temporary_area();

}





/*=====================================================����Ϊ���뱸��*============================================/

/***********************************************������pid���д�ڶ�ʱ���ж�����********************************************************/
//    switch (sportflag)
//    {  
//      case left:	   PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case right:    PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case forward:  PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case back:     PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      case stop:     PID_out(ID1,one);PID_out(ID2,two);PID_out(ID3,three);PID_out(ID4,four);    break;
//      
//    }
/********************************************************������·��********************************************************/

///*****************ǰ����ɨ��ĵط�*************************************/
//     forward_hanshu(80);
//  /*****************ͣ����ɨ��*************************************/
//    state = ready_to_scan_QRcode;
//    HAL_UART_Transmit(&huart3,&state,2,1000);
//    stop_hanshu(2500);
//  /*****************��ɨ����ǰ��ԭ����*************************************/
//    forward_hanshu(90);    
//  /*****************ͣ����ȡ��*************************************/
//          /*********************ȡ��һ����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************ȡ�ڶ�����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************ȡ��������****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//  /*****************��ԭ����ǰ���ּӹ���*************************************/
//		back_hanshu(50);
//    
//		left_hanshu(215);
//    /****************************************ͣ��������*************************************/
//    stop_hanshu(0);//������Բ���ͣ������ʱ������Ϊ����ֱ��ִ��ȡ�ϴ���
//        /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
//          /***************************ȡ��һ����****************/
////        switch (first_pick[0])
////        {    
////          case red: 
////                state = search_red;                             /*����д���ˣ�����ֱ�������鴢�������������ϵ�λ�ã�����Ҫ�Ӿ�*/
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
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************ȡ�ڶ�����****************/
//          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************ȡ��������****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//    /****************************************�����ϴӴּӹ���ȡ����*************************************/
//          /*********************ȡ��һ����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************ȡ�ڶ�����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************ȡ��������****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//  /****************************************�Ӵּӹ���ǰ���ݴ���*************************************/
//    forward_hanshu(80);  

//    right_hanshu(100
//        );
//  /**********************************��һ��     ͣ�������ϵ��ݴ���*************************************/
//    stop_hanshu(0);
//        /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
//          /***************************ȡ��һ����****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************ȡ�ڶ�����****************/
//          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************ȡ��������****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
/////***************************************************��һȦ��ʽ����**************************************************************************///
/////*************************************************�����ǵڶ�Ȧ�Ĵ���**************************************************************************///
//        
//        
//        
//  /****************************************�ݴ���ǰ��ԭ�����ڶ���ȡ��*************************************/
//    right_hanshu(100);   
//        
// 		back_hanshu(50);
//    /*****************�ڶ���  ͣ����ȡ��*************************************/
//          /***********�ڶ���   ȡ��һ����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************ȡ�ڶ�����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************ȡ��������****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//    /*****************��ԭ����ǰ���ּӹ���*************************************/
// 		back_hanshu(10);
//    
// 		left_hanshu(10);
//    /****************************************ͣ��������*************************************/
//    stop_hanshu(0);
//        /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
//          /***************************������ȡ��һ����****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************������ȡ�ڶ�����****************/
//          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************������ȡ��������****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//    /****************************************�����ϴӴּӹ���ȡ����*************************************/
//          /*********************�Ӵּӹ���ȡ��һ����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************�Ӵּӹ���ȡ�ڶ�����****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//          /*********************�Ӵּӹ���ȡ��������****************/
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
//          /*ִ�м�ȡ����ö�������*/
//        
//          /*ִ�м�ȡ����ö�������*/
//  /***********************************�ڶ���    �Ӵּӹ���ǰ���ݴ���*************************************/
// 		forward_hanshu(100);
//    
// 		right_hanshu(50);
//    /****************************************ͣ�������ϵ��ݴ���*************************************/
//    stop_hanshu(0);
//        /*****************����ָ���openmvѰ�ҵ�һ����ɫ������*************************************/
//          /***************************������ȡ��һ����****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�һ����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************������ȡ�ڶ�����****************/
//          /***************����ָ���openmvѰ�ҵڶ�����ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//          /*********************������ȡ��������****************/
//          /*ִ�м�ȡ��������*/
//        
//          /*ִ�м�ȡ��������*/
//          /***************����ָ���openmvѰ�ҵ�������ɫ��Ȧ****************************/
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
//          /*ִ�з��ö�������*/
//        
//          /*ִ�з��ö�������*/
//        
//        
//        
//        
///************************************************************ǰ����ͣ�����������***********************************************************************/        
// 		back_hanshu(100);
