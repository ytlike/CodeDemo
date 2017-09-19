#pragma once
#ifndef PASSENGEMANAGE_H
#define PASSENGEMANAGE_H

#include	<time.h>
#include	<stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

	// �Ŷ���Ա��Ϣ����
	// ������Ա��Ϣ�ṹ��
	typedef struct _Passenger
	{
		int dataID;
		int servicedTimes;
		time_t startIntoSeqQueue;
		time_t endOutSeqQueue;
		time_t StaySeqQueueTimeAll;
		time_t startGataList;
		time_t endGataList;
		bool isStartService;
	}Passenger;

	// 3����ز���
	/*
	3.1 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialPassenger(Passenger * passenger);

#ifdef __cplusplus
}
#endif

#endif // PASSENGEMANAGE_H