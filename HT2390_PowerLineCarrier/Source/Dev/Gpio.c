/****************************************Copyright (c)**************************************************
**                               ����ʦ����ѧ��������ԴѧԺ
**------------------------------------------------------------------------------------------------------
** �ļ�: Gpio.c
** �汾: v1.0
**------------------------------------------------------------------------------------------------------
** ����:
**     ��ģ����Ҫ�漰ͨ��IO�ڲ�������
** Author:HE
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#include "config.h"
#include "Gpio.h"

#define LED_Port  _ph							
#define LED_PortC _phc

void Gpio_Init(void)
{
	LED_PortC=0x0;									//�O�� LED_Port ��ݔ��ģʽ
	LED_Port=0xFE;									//�O�� LED_Port ��ֵ
	
	
}

static void DelayUs(unsigned int us)
{	
	while(us--);
}

void Gpio_Operate(void)
{
	LED_Port = 0x00;
	DelayUs(1000);
	LED_Port = 0xff;
	DelayUs(1000);
}


/********************************************************************************************************
**                            End Of File
********************************************************************************************************/