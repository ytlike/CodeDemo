#pragma once
#ifndef SEQUALQUEUE_LINEMANAGER_H
#define SEQUALQUEUE_LINEMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif
	// ����ʵ���Ŷӻ������������У�
	// 1������������ṹ��
	typedef struct _SeqQueue
	{
		int dataID;							// �洢��Ӧ�Ŷ����
		struct _SeqQueue * next;			// ָ����һ���
	}SeqQueueNode;

	// 2����������ṹ��
	typedef struct _SeqQueueList
	{
		int size;							// ��������������������Ŷ�����
		int num;							// �ŶӺ������
		SeqQueueNode * pfront;				// ����ͷ���
		SeqQueueNode * ptail;				// ����β���
	}SeqQueueList;

	// 3�������ӿ�ʵ��

	/*
	3.1 ��ʼ��
	�������ܣ�ʵ�ֶ��г�ʼ������ʼ���ŶӺ���num����ʼ�������Ŷ�����size
	����������SeqQueueList * list��Ҫ��ʼ���Ĺ������ͷ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialSeqQueueList(SeqQueueList * list);

	/*
	3.2 �����
	�������ܣ�����ʵ������й���data�洢�Ŷ��������
	����������SeqQueueList * list������ͷ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int IntoSeqQueue(SeqQueueList * list);

	/*
	3.3 ������
	�������ܣ�����Ԫ�س����У�ɾ������������
	����������SeqQueueList * list���������ͷ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int OutSeqQueue(SeqQueueList * list);

	/*
	3.4 ȡ�ö�������
	�������ܣ���ȡ���е�ʱ�Ŷ�����
	����������SeqQueueList * list���������ͷ���
	��������ֵ���ɹ����� ʵ������ numbers��ʧ�ܷ��� -1��
	*/
	int getCountSeqQueue(SeqQueueList * list);

	/*
	3.5 ���ٶ���
	�������ܣ����ٶ���������
	����������SeqQueueList * list���������ͷ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int DestroySeqQueue(SeqQueueList * list);

	/*
	3.6 �����ŶӺ���
	�������ܣ������ŶӺ��룬��1�ſ�ʼ
	����������SeqQueueList * list���������ͷ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int ResetNumSeqQueue(SeqQueueList * list);

	/*
	3.7 ��ӡ���dataID
	�������ܣ�������������Ŷӵĺ���
	����������SeqQueueList * list���������ͷ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintSeqQueue(SeqQueueList * list);

	/*
	3.8 ��ȡ���ж���Ԫ��ֵ dataID
	�������ܣ�
	����������SeqQueueList * list��Ҫ��ʼ���Ĺ������ͷ���
	��������ֵ���ɹ����� dataID��ʧ�ܷ��� -1��
	*/
	int GetValueSeqQueueList(SeqQueueList * list);

	/*
	3.X ���Ժ���
	�������ܣ����幦�ܲ���
	����������
	��������ֵ��
	*/
	void TestSeqQueueList();

#ifdef __cplusplus
}
#endif

#endif // SEQUALQUEUE_LINEMANAGER_H
