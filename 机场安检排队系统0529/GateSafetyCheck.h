#ifndef GATESAFETYCHECK_H
#define GATESAFETYCHECK_H

#ifdef __cplusplus
extern "C" {
#endif

#include	<stdbool.h>

#define MAXNUMBERPASSENGER 6

	enum WindowWorkState {
		isWork,
		noWork,
		isRest,
		noRest,
		isClose,
		noClose
	};


	// 1��������6�˶��л���������
	typedef struct _GateNode
	{
		int dataID;
		struct _GateNode * next;
	}GateNode;

	// 2��������������ṹ��
	typedef struct _GateList
	{
		int size;
		bool isNeedPassenger;
		bool isGoOffWork;
		int	WorkState;
		time_t startRestTime;
		time_t endRestTime;
		time_t tatolRestTime;
		GateNode * pfront;
		GateNode * ptail;
	}GateList;

	// 3�������Ų���

	/*
	3.1 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialGateList(GateList * gatelist);

	/*
	3.2 ���밲���Ŷ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int IntoGateList(GateList * gatelist, int dataID);

	/*
	3.3 �������Ŷ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int OutGateList(GateList * gatelist);

	/*
	3.4 ��ȡ�����Ŷ�������
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int GetCountGateList(GateList * gatelist);

	/*
	3.5 ��ȡ�����Ŷ��ж���Ԫ����Ϣ
	�������ܣ�
	����������
	��������ֵ���ɹ����� dataID��ʧ�ܷ��� -1��
	*/
	int GetInfoGateList(GateList * gatelist);

	/*
	3.6 ���ٰ����Ŷ���
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int DestroyGateList(GateList * gatelist);

	/*
	3.7 ������ȡ�����Ŷ�����Ա��Ϣ������
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintGateList(GateList * gatelist);


	/*
	3.X ���Ժ���
	�������ܣ����幦�ܲ���
	����������
	��������ֵ��
	*/
	void TestGateList();


#ifdef __cplusplus
}
#endif

#endif // GATESAFETYCHECK_H