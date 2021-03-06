/****************************************Copyright (c)**************************************************
**                               福州卓群杰能信息科技有限公司
**------------------------------------------------------------------------------------------------------
** 文件: tool.h
** 版本: v1.0
**------------------------------------------------------------------------------------------------------
** 描述:
**     本模块主要收集一些常用的工具函数，其中包含CRC校验计算等各种功能
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef __TOOL_H__
#define __TOOL_H__

//-------------------------------------------------------------------------------
// 常量、变量声明


//-------------------------------------------------------------------------------
// 字节序转换接口


//-------------------------------------------------------------------------------
// 对外函数声明

unsigned char 	ToolCalcXor8( unsigned char *Xor_buf, unsigned int count );
unsigned char ToolCalcSum( unsigned char *Sum_buf, unsigned int count );


#endif

/********************************************************************************************************
**                            End Of File
********************************************************************************************************/
