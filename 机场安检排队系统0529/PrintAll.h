#pragma once
#ifndef PRINTALL_H
#define PRINTALL_H

//#include "ControlAll.h"
//extern struct _ControlALL;
//extern ControlAll;

#ifdef __cplusplus
extern	"C" {
#endif

	// ���ģ��
	
	/*
	1.0 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	//int InitialPrintAll(ControlAll * allControl);


	/*
	1.1 ���廭�����
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int MainPicPrintAll(ControlAll * allControl);

	/*
	1.2 �����ǰʱ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintTimeNow(ControlAll * allControl);

	/*
	1.3 �����ǰ���촰��״̬ �ϱ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintGateState(ControlAll * allControl);

	/*
	1.4 �����ǰ���촰��״̬ �ϱ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintSeqQueuePassenger(ControlAll * allControl);



#ifdef __cplusplus
}
#endif

#endif // !PRINTALL_H
