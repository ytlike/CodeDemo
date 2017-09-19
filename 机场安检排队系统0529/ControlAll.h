#pragma once
#ifndef CONTROLALL_H
#define CONTROLALL_H

#include	"FileInput.h"							// NO.1.1 �ļ�����ģ��		ͷ�ļ�
#include	"KeyboardInput.h"						// NO.1.2 ��������ģ��		ͷ�ļ�
#include	"SequalQueue.h"							// NO.2 �Ŷӻ�����ģ��		ͷ�ļ�
#include	"GateSafetyCheck.h"						// NO.3 �����ģ��			ͷ�ļ�
#include	"PassengerInfo.h"						// NO.4 �˿���Ա��Ϣģ��	ͷ�ļ�
#include	"Config.h"								// NO.5 ������Ϣģ��		ͷ�ļ�
#include	"ShowTime.h"							// NO.6 ʱ����ʾģ��		ͷ�ļ�


#define PASSENGERMAXN		2048
#define BUFFCONTROL			1024
#define GATENUMBERMAXN		8
#define GATEQUEUEMAXN		6

// �������ģ��
// 1 �������ģ��ṹ��
typedef struct _ControlALL
{
	// ���ģ������
	FileInput		fileInput;					// NO.1.1 �ļ�����ģ��
	KeyBoard		keyboard;					// NO.1.2 ��������ģ��
	SeqQueueList	Seqlist;					// NO.2 �Ŷӻ�����ģ��
	GateList		gatelist[GATENUMBERMAXN];	// NO.3 �����ģ��
	Passenger		passenger[PASSENGERMAXN];	// NO.4 �˿���Ա��Ϣģ��
	Config			config;						// NO.5 ������Ϣģ��
	ShowTime		systime;					// NO.6 ʱ����ʾģ��
	//PrintAll		printall;					// NO.7 ���ģ��


	// �������ַ���
	char			orderStr[BUFFCONTROL + 1];	// ������
	int				orderT;						// �����в���T

	//// ϵͳ���ò���
	//int				MinSec;						// ���ҵ�����ʱ��
	//int				MaxSec;						// �ҵ�����ʱ��
	//int				MinRestSec;					// ��̴�����Ϣʱ��
	//int				MaxRestSec;					// �������Ϣʱ��

	//// ���г��Ȳ���
	//int				MaxCustSingleLine;			// ���������ȴ��˿���
	//int				MaxLines;					// ���λ����������MaxLines��ֱ�����
	//int				MaxSeqLen;					// �������ȴ�����
	//int				MinTimeLen;					// һ�ΰ������ʱ�䣬��λ����
	//int				MaxTimeLen;					// һ�ΰ����ʱ�䣬��λ����

}ControlAll;

#include	"PrintAll.h"


#ifdef __cplusplus
extern "C" {
#endif


	// 2 �����ļ���ȡ

	// 3����ز���
	/*
	3.1 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialControlAll(ControlAll * allControl);

	/*
	3.2 �����Ŷӻ�������Ա����
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int SeqQueueControlAll(ControlAll * allControl);

	/*
	3.3 ���밲�촰����Ա����
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int GateWindowControlAll(ControlAll * allControl);

	/*
	3.4 �ַ��������д���
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int orderStrControlAll(ControlAll * allControl);

	/*
	3.5 ȡ�ü�����������
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int GetValueOfKeyBoardInputALL(ControlAll * allControl);

	/*
	3.6 ����������
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� - 1��
	*/
	int DealOrderLineALL(ControlAll * allControl);

	/*
	3.7 ���촰�ڶ����Ŷ�״̬����
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� - 1��
	*/
	int DealGataQueueStrALL(ControlAll * allControl, char * showQueueStr, int GateWindowNumber);

	/*
	3.8 �˿ͽ��밲�촰�ڷ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� ���ں��� ��ʧ�ܷ��� - 1��
	*/
	DealBeChoosedGateWindowNumber(ControlAll * allControl);

	/*
	3.9 �˿��뿪���촰�ڿ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� ���ں��� ��ʧ�ܷ��� - 1��
	*/
	LeaveGateWindowControAll(ControlAll * allControl);




	// 4��ʵ��
	/*
	4.1 ʵ��1 �����������
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int CaseOneControlAll();




#ifdef __cplusplus
}
#endif

#endif // CONTROLALL_H