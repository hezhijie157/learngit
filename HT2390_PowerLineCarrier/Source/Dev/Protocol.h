/****************************************Copyright (c)**************************************************
**                               ����ʦ����ѧ��������ԴѧԺ
**------------------------------------------------------------------------------------------------------
** �ļ�: Protocol.h
** �汾: v1.0
**------------------------------------------------------------------------------------------------------
** ����:
**     ��ģ����Ҫ�漰�����ز�ͨ�Ų�������
** Author:HE
**------------------------------------------------------------------------------------------------------
********************************************************************************************************/
#ifndef __PROTOCOL__H__
#define __PROTOCOL__H__

//-------------------------------------------------------------------------------
// ����������
typedef enum
{
	//���ز���ָ��
	CMD_RST_MODULE = 0x01	,										  			// ģ�������Ĳ���ָ��
	CMD_RDVER_MODULE = 0x02	,	 												// ��ȡģ��汾��Ϣ�Ĳ���ָ��
	CMD_RDMAC_MODULE = 0x03	,													// ��ȡģ��MAC��ַ�Ĳ���ָ��
	CMD_RDAddr_MODULE = 0x0B	,												// ��ȡģ��ͨ�ŵ�ַ�Ĳ���ָ��
	CMD_SetAddr_MODULE = 0x0C	,												// ����ģ��ͨ�ŵ�ַ�Ĳ���ָ��
	CMD_RDNetPara_MODULE = 0x0D	,										 	// ��ȡģ����������Ĳ���ָ��
	CMD_SetNetPara_MODULE = 0x0E	,										//����ģ����������Ĳ���ָ��
  
	
	//�ŵ�����ָ��
	CMD_TXData_CHANNEL = 0x14	,															// �������ݵĲ���ָ��
	CMD_RXData_CHANNEL = 0x15	,															// �������ݵĲ���ָ��
	CMD_SearchDev_CHANNEL = 0x17	,													// �����豸�����Ĳ���ָ��
	CMD_StopSearchDev_CHANNEL = 0x18	,											// ֹͣ�豸�����Ĳ���ָ��
	CMD_ReportSearchResult_CHANNEL = 0x19	,									// �ϱ���������Ĳ���ָ��
	CMD_NotifySearch_CHANNEL = 0x1A	,												// ֪ͨ�豸�����Ĳ���ָ��
	CMD_ResponseSearch_CHANNEL = 0x1B	,											// ��Ӧ�豸�����Ĳ���ָ��
	CMD_SetNetPwd_CHANNEL = 0x1C	,													// ��Ӧ���ؼ�Զ��ģ���������Ĳ���ָ��
	CMD_NotifySetNetPwd_CHANNEL = 0x1D	,										// ֪ͨ����������õĲ���ָ��
	CMD_NotifySetNetResult_CHANNEL = 0x1F	,									// �ϱ�����������ý���Ĳ���ָ��
	
  //Զ�̵���ָ��
	CMD_RDVER_DEBUG = 0x52	,												// Զ�̶�ȡ�汾��Ϣ�Ĳ���ָ��
	CMD_RDMAC_DEBUG = 0x53	,												// Զ�̶�ȡMAC��ַ�Ĳ���ָ��
	CMD_RDNetPara_DEBUG = 0x5D	,										// Զ�̶�ȡ��������Ĳ���ָ��
	
	//����ָ��
	CMD_RSV=0xFF,										// ����
}PtlCmd_t;

#define  Ctrl_PrmBit_0     0  //ָ����Ӧ���ñ�־ֻ�Է�������ָ��(14H)��Ч
#define  Ctrl_PrmBit_1     1  //������Ӧ���ñ�־ֻ�Է�������ָ��(14H)��Ч
#define  Ctrl_PrmPosition  6   //Prmλ��Ctrl���е�λ��Ϊ6

#define  Ctrl_RespondBit_0     0  //����Ӧ�𣬸�λΪ0��־ģ��ظ����豸��Ӧ����������Ӧ
#define  Ctrl_RespondBit_1     1  //�쳣Ӧ�𣬸�λΪ1��־ģ��ظ����豸��Ӧ�����쳣��Ӧ
#define  Ctrl_RespondPosition  5   //Respondλ��Ctrl���е�λ��Ϊ5




int UsartPtlSend( unsigned char Ctrl,unsigned char Cmd,unsigned char *UserData,unsigned char UserDataLen);
BOOL UsartPtlRec( unsigned char * buf , unsigned short len );
BOOL UsartPackValid( unsigned char * buf , unsigned short len );
#endif




/********************************************************************************************************
**                            End Of File
********************************************************************************************************/
