/****************************************Copyright (c)**************************************************
**                               福建师范大学物理与能源学院
**------------------------------------------------------------------------------------------------------
** 文件: Protocol.h
** 版本: v1.0
**------------------------------------------------------------------------------------------------------
** 描述:
**     本模块主要涉及电力载波通信操作函数
** Author:HE
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef __PROTOCOL__H__
#define __PROTOCOL__H__

//-------------------------------------------------------------------------------
// 操作命令字
typedef enum
{
	//本地操作指令
	CMD_RST_MODULE = 0x01	,										  			// 模块重启的操作指令
	CMD_RDVER_MODULE = 0x02	,	 												// 读取模块版本信息的操作指令
	CMD_RDMAC_MODULE = 0x03	,													// 读取模块MAC地址的操作指令
	CMD_RDAddr_MODULE = 0x0B	,												// 读取模块通信地址的操作指令
	CMD_SetAddr_MODULE = 0x0C	,												// 设置模块通信地址的操作指令
	CMD_RDNetPara_MODULE = 0x0D	,										 	// 读取模块网络参数的操作指令
	CMD_SetNetPara_MODULE = 0x0E	,										//设置模块网络参数的操作指令
  
	
	//信道操作指令
	CMD_TXData_CHANNEL = 0x14	,															// 发送数据的操作指令
	CMD_RXData_CHANNEL = 0x15	,															// 接收数据的操作指令
	CMD_SearchDev_CHANNEL = 0x17	,													// 发起设备搜索的操作指令
	CMD_StopSearchDev_CHANNEL = 0x18	,											// 停止设备搜索的操作指令
	CMD_ReportSearchResult_CHANNEL = 0x19	,									// 上报搜索结果的操作指令
	CMD_NotifySearch_CHANNEL = 0x1A	,												// 通知设备搜索的操作指令
	CMD_ResponseSearch_CHANNEL = 0x1B	,											// 响应设备搜索的操作指令
	CMD_SetNetPwd_CHANNEL = 0x1C	,													// 响应本地及远程模块网络口令的操作指令
	CMD_NotifySetNetPwd_CHANNEL = 0x1D	,										// 通知网络口令设置的操作指令
	CMD_NotifySetNetResult_CHANNEL = 0x1F	,									// 上报网络口令设置结果的操作指令
	
  //远程调试指令
	CMD_RDVER_DEBUG = 0x52	,												// 远程读取版本信息的操作指令
	CMD_RDMAC_DEBUG = 0x53	,												// 远程读取MAC地址的操作指令
	CMD_RDNetPara_DEBUG = 0x5D	,										// 远程读取网络参数的操作指令
	
	//保留指令
	CMD_RSV=0xFF,										// 保留
}PtlCmd_t;

#define  Ctrl_PrmBit_0     0  //指令响应，该标志只对发送数据指令(14H)有效
#define  Ctrl_PrmBit_1     1  //主动响应，该标志只对发送数据指令(14H)有效
#define  Ctrl_PrmPosition  6   //Prm位在Ctrl域中的位置为6

#define  Ctrl_RespondBit_0     0  //正常应答，该位为0标志模块回复给设备的应答是正常响应
#define  Ctrl_RespondBit_1     1  //异常应答，该位为1标志模块回复给设备的应答是异常响应
#define  Ctrl_RespondPosition  5   //Respond位在Ctrl域中的位置为5




int UsartPtlSend( unsigned char Ctrl,unsigned char Cmd,unsigned char *UserData,unsigned char UserDataLen);
BOOL UsartPtlRec( unsigned char * buf , unsigned short len );
BOOL UsartPackValid( unsigned char * buf , unsigned short len );
#endif




/********************************************************************************************************
**                            End Of File
********************************************************************************************************/
