/****************************************Copyright (c)**************************************************
**                               福建师范大学物理与能源学院
**------------------------------------------------------------------------------------------------------
** 文件: Timer.c
** 版本: v1.0
**------------------------------------------------------------------------------------------------------
** 描述:
**     本模块主要涉及定时器操作函数
** Author:HE
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#include "config.h"
#include "Timer.h"

#define TIM_CLOCK      	(1000)                						// 定时器计数值 约1ms                                               
#define TIM_VALUE   	(0Xffff-TIM_CLOCK) 							// 预分频值
#define TIM_SEC      	(1000)                						// 定时时间约1S   


unsigned long g_TaskTimer_10s=10000;


/*******************************************************************************************************
** 函数: TimerBase0_Init：时基定时器TB0初始化
********************************************************************************************************/
void TimerBase0_Init(void)
{
	//fPSC0=fSYS/4,週期=2048*(1/fPSC0),致能TB0中斷
	//当系统时钟fSYS为8M时，超时周期为1.024ms
	_psc0r=0x01; //TB0计数时钟,fPSC0=fSYS/4
	_tb0c=0x83;//使能TB0计数，TB0超时周期设为2^11/fPSC0
	_tb0e=1;//TB0中断使能
	_emi=1;	//使能全局中断				
}

/*******************************************************************************************************
** 函数: ISR_TB0：时基定时器TB0中断函数

********************************************************************************************************/

DEFINE_ISR(ISR_TB0,0x24)
{									
	//时基定时器TB0
	///////////////////////////////////
	//补充相关中断处理代码
	if(Usart0Time) Usart0Time--;
	if(Usart1Time) Usart1Time--;
	if(Usart2Time) Usart2Time--;
	
	////////////////////////////////
}






#define STM2_fSYS  8000000
#define STM2_fINT  (STM2_fSYS/4)
#define STM2_TIME_1MS (STM2_fINT/1000)
/*******************************************************************************************************
** 函数: STM2_Init:定时器STM2初始化
********************************************************************************************************/
void STM2_Init(void)
{
	_stm2c0=0; 	//继续计数，当fSYS=8M,fINT=fSYS/4=8MHz/4
	_stm2c1=0b11000001;   //设置STM2为定时/计数模式,比较器A吻合时清除
	              
	_stm2al=(unsigned char)STM2_TIME_1MS;	         		//計數時間常數
	_stm2ah=(unsigned char)(STM2_TIME_1MS>>8);         
	_st2on=1;
	
	_stm2ae=1; //致能STM2中斷
	_mf4e=1;  
	_emi=1;						//EMI總開關		
}
/*******************************************************************************************************
** 函数:STM2：定时器STM2中断函数
********************************************************************************************************/
DEFINE_ISR(ISR_STM2,0x38)
{		
	
	_stm2al=(unsigned char)STM2_TIME_1MS;	         		//計數時間常數
	_stm2ah=(unsigned char)(STM2_TIME_1MS>>8);  
	///////////////////////////////////
	//补充相关中断处理代码
	
	
	
	//////////////////////////////////
	
	_stm2af=0;										//清除STM2AF
}
/********************************************************************************************************
**                            End Of File
********************************************************************************************************/
