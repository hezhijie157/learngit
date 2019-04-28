/****************************************Copyright (c)**************************************************
**                               福建师范大学物理与能源学院
**------------------------------------------------------------------------------------------------------
** 文件: Usart.c
** 版本: v1.0
**------------------------------------------------------------------------------------------------------
** 描述:
**     本模块主要涉及串口操作函数
** Author:HE
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#include "config.h"
#include "Usart.h"


unsigned char Usart0Buf[64]={0};	
unsigned int Usart0Len=0;
unsigned int Usart0Time=0;

unsigned char Usart1Buf[64]={0};	
unsigned int Usart1Len=0;
unsigned int Usart1Time=0;


unsigned char Usart2Buf[64]={0};	
unsigned int Usart2Len=0;
unsigned int Usart2Time=0;


#define	fH		8000000							//MCU HIRC Frequency
#define BR0		19200							//串口0 Baud Rate
#define BR1		19200							//串口1 Baud Rate
#define BR2		19200							//串口2 Baud Rate


	
	
void Usart0_Init(void)
{
	
	
	_pas1=0xF0;									//設置腳位功能 TX0->PA7,RX0->PA6
	_u0cr1=0b10000000;							//UARTEN0/8-Bit/No_parity//1 Stop Bit///
	_u0cr2=0b11100100;							//TXEN0/RXEN0/BRGH0/RIE0//	
	_mf5e=1; _ur0e=1;	
	_brg0=fH/((u32)16*BR0)-1;                    //BRGH0=1				
}


void Usart1_Init(void)
{
	
	
	_pds0=0b00101000;						    //設置腳位功能 TX1->PD2,RX1->PD1
	_u1cr1=0b10000000;							//UARTEN1/8-Bit/No_parity//1 Stop Bit///
	_u1cr2=0b11100100;							//TXEN1/RXEN1/BRGH1/RIE1//	
	_mf5e=1; _ur1e=1;	
	_brg1=fH/((u32)16*BR1)-1;                    //BRGH1=1				
}

void Usart2_Init(void)
{
	
	
	_pbs0=0b00101100;						    //設置腳位功能 TX2->PB1,RX2->PB2
	_u2cr1=0b10000000;							//UARTEN2/8-Bit/No_parity//1 Stop Bit///
	_u2cr2=0b11100100;							//TXEN2/RXEN2/BRGH2/RIE2//
	_mf5e=1; _ur2e=1;		
	_brg2=fH/((u32)16*BR2)-1;                    //BRGH2=1				
}


void Usart0_SendCh(unsigned char ch)
{
	_txr_rxr0 = ch;						//傳送結果低八位元
	while(!_txif0);	
//	_txif0=0;
}


void Usart1_SendCh(unsigned char ch)
{
	_txr_rxr1 = ch;						//傳送結果低八位元
	while(!_txif1);	
//	_txif1=0;
}


void Usart2_SendCh(unsigned char ch)
{
	_txr_rxr2 = ch;						//傳送結果低八位元
	while(!_txif2);	
//	_txif2=0;
}



/*******************************************************************************************************
** 函数: Usart_SendBuf, 串口发送帧
**------------------------------------------------------------------------------------------------------
** 参数: 字符串	, 长度
** 返回: 无
** Author:HE
********************************************************************************************************/
BOOL Usart0_SendBuf(unsigned char *dat , unsigned int len)
{		  
	while(len--)
	{
		Usart0_SendCh(*(dat++));
	}
	return TRUE;
}	

BOOL Usart1_SendBuf(unsigned char *dat , unsigned int len)
{		  
	while(len--)
	{
		Usart1_SendCh(*(dat++));
	}
	return TRUE;
}	

BOOL Usart2_SendBuf(unsigned char *dat , unsigned int len)
{		  
	while(len--)
	{
		Usart2_SendCh(*(dat++));
	}
	return TRUE;
}	


unsigned char Usart0_Read(void)
{
	unsigned int i=0;
	if(Usart0Time)			return FALSE;
	if(!Usart0Len)			return FALSE;
	for(i=0;i<Usart0Len;i++)
	{
		Usart0_SendCh(Usart0Buf[i]);
	}
//	UsartPtlRec( UsartBuf , UsartLen );
	Usart0Len=0;
	
	return TRUE;
}

unsigned char Usart1_Read(void)
{
	unsigned int i=0;
	if(Usart1Time)			return FALSE;
	if(!Usart1Len)			return FALSE;
	for(i=0;i<Usart1Len;i++)
	{
		Usart1_SendCh(Usart1Buf[i]);
	}
//	UsartPtlRec( UsartBuf , UsartLen );
	Usart1Len=0;
	
	return TRUE;
}


unsigned char Usart2_Read(void)
{
	unsigned int i=0;
	if(Usart2Time)			return FALSE;
	if(!Usart2Len)			return FALSE;
	for(i=0;i<Usart2Len;i++)
	{
		Usart2_SendCh(Usart2Buf[i]);
	}
//	UsartPtlRec( UsartBuf , UsartLen );
	Usart2Len=0;
	
	return TRUE;
}

//串口接收中断函数


///*******************************************************************************************************
//** 函数: USART0：串口0接收中断函数
//** Author:HE
//********************************************************************************************************/
//DEFINE_ISR(UART0,0x3C)
//{	
//	if(_ur0f == 0)	return;
//	Usart0Time=10;									  // 串口计时器计时
//								        	
//	Usart0Buf[Usart0Len++%64]=_txr_rxr0;						// 读取字符
//	_ur0f=0;									//清除UR0F旗標(共享型)	
//}


/*******************************************************************************************************
** 函数: USART012：串口012接收中断函数
** Author:HE
********************************************************************************************************/
DEFINE_ISR(UART012,0x3C)
{	
	if((_ur0f == 0)&& (_ur1f == 0) && (_ur2f == 0))	return;
	
	if(_ur0f == 1)
	{
		Usart0Time=10;									  // 串口计时器计时					        
		Usart0Buf[Usart0Len++%64]=_txr_rxr0;						// 读取字符
		_ur0f=0;									//清除UR0F旗標(共享型)	
	}
	
	if(_ur1f == 1)
	{
		Usart1Time=10;									  // 串口计时器计时					        
		Usart1Buf[Usart1Len++%64]=_txr_rxr1;						// 读取字符
		_ur1f=0;									//清除UR1F旗標(共享型)	
	}
	
	if(_ur2f == 1)
	{
		Usart2Time=10;									  // 串口计时器计时					        
		Usart2Buf[Usart2Len++%64]=_txr_rxr2;						// 读取字符
		_ur2f=0;									//清除UR2F旗標(共享型)	
	}
}


/********************************************************************************************************
**                            End Of File
********************************************************************************************************/
