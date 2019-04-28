/****************************************Copyright (c)**************************************************
**                               福建师范大学物理与能源学院
**------------------------------------------------------------------------------------------------------
** 文件: Usart.h 
** 版本: v1.0
**------------------------------------------------------------------------------------------------------
** 描述:
**      用于声明串口相关函数及变量
** Author:HE
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef __USART__H__
#define __USART__H__

extern unsigned char Usart0Buf[64];
extern unsigned int Usart0Len;
extern unsigned int Usart0Time;

extern unsigned char Usart1Buf[64];
extern unsigned int Usart1Len;
extern unsigned int Usart1Time;

extern unsigned char Usart2Buf[64];
extern unsigned int Usart2Len;
extern unsigned int Usart2Time;

void Usart0_Init(void);
void Usart0_SendCh(unsigned char ch);
BOOL Usart0_SendBuf(unsigned char *dat , unsigned int len);
unsigned char Usart0_Read(void);


void Usart1_Init(void);
void Usart1_SendCh(unsigned char ch);
BOOL Usart1_SendBuf(unsigned char *dat , unsigned int len);


void Usart2_Init(void);
void Usart2_SendCh(unsigned char ch);
BOOL Usart2_SendBuf(unsigned char *dat , unsigned int len);




#endif
/********************************************************************************************************
**                            End Of File
********************************************************************************************************/


