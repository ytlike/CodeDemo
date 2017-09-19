#define _CRT_SECUSE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"SequalQueue.h"

// ����ʵ���Ŷӻ������������У�

// 3�������ӿ�ʵ��

/*
3.1 ��ʼ��
�������ܣ�ʵ�ֶ��г�ʼ������ʼ���ŶӺ���num����ʼ�������Ŷ�����size
����������SeqQueueList * list��Ҫ��ʼ���Ĺ������ͷ���
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int InitialSeqQueueList(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}
	list->size = 0;					// ����������
	list->num = 1;					// �ŶӺ���
	list->pfront = NULL;			// �����׽��
	list->ptail = NULL;				// ����β���

	return 0;
}

/*
3.2 �����
�������ܣ�����ʵ������й���data�洢�Ŷ��������
����������SeqQueueList * list������ͷ���
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int IntoSeqQueue(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}

	SeqQueueNode * pnew = (SeqQueueNode *)malloc(sizeof(SeqQueueNode));
	memset(pnew, 0, sizeof(SeqQueueNode));
	pnew->dataID = list->num;
	pnew->next = NULL;

	if (list->pfront == NULL && list->ptail == NULL && list->size == 0)
	{
		list->pfront = pnew;
		list->ptail = pnew;
	}
	else
	{
		list->ptail->next = pnew;
		list->ptail = pnew;
	}

	list->size++;
	list->num++;

	return 0;
}

/*
3.3 ������
�������ܣ�����Ԫ�س����У�ɾ������������
����������SeqQueueList * list���������ͷ���
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1, ����Ϊ�շ��� -2��
*/
int OutSeqQueue(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}

	if (list->size == 0)
	{
		return -2;
	}

	if (list->size == 1)
	{
		SeqQueueNode * pdel = list->pfront;
		list->pfront = NULL;
		list->ptail = NULL;
		free(pdel);
		pdel = NULL;
	}
	else
	{
		SeqQueueNode * pdel = list->pfront;
		list->pfront = pdel->next;
		free(pdel);
		pdel = NULL;
	}

	list->size--;

	return 0;
}

/*
3.4 ȡ�ö�������
�������ܣ���ȡ���е�ʱ�Ŷ�����
����������SeqQueueList * list���������ͷ���
��������ֵ���ɹ����� ʵ������ numbers��ʧ�ܷ��� -1��
*/
int getCountSeqQueue(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}

	return list->size;
}

/*
3.5 ���ٶ���
�������ܣ����ٶ���������
����������SeqQueueList * list���������ͷ���
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int DestroySeqQueue(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}
	while (list->size)
	{
		OutSeqQueue(list);
	}
	return 0;
}

/*
3.6 �����ŶӺ���
�������ܣ������ŶӺ��룬��1�ſ�ʼ
����������SeqQueueList * list���������ͷ���
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int ResetNumSeqQueue(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}

	list->num = 1;
	return 0;
}

/*
3.7 ��ӡ���dataID
�������ܣ�������������Ŷӵĺ���
����������SeqQueueList * list���������ͷ���
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int PrintSeqQueue(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}

	SeqQueueNode * pcur = list->pfront;
	while (pcur != NULL)
	{
		printf("%d ", pcur->dataID);
		pcur = pcur->next;
	}

	return 0;
}


/*
3.8 ��ȡ���ж���Ԫ��ֵ dataID
�������ܣ�
����������SeqQueueList * list��Ҫ��ʼ���Ĺ������ͷ���
��������ֵ���ɹ����� dataID��ʧ�ܷ��� -1��
*/
int GetValueSeqQueueList(SeqQueueList * list)
{
	//for error
	if (NULL == list)
	{
		return -1;
	}


	return list->pfront->dataID;
}


/*
3.X ���Ժ���
�������ܣ����幦�ܲ���
����������
��������ֵ��
*/
void TestSeqQueueList()
{
	SeqQueueList * list = (SeqQueueList *)malloc(sizeof(SeqQueueList));
	memset(list, 0, sizeof(SeqQueueList));

	InitialSeqQueueList(list);

	int n = 10;
	for (int i = 0; i < n; i++)
	{
		IntoSeqQueue(list);
	}

	OutSeqQueue(list);

	PrintSeqQueue(list);

	DestroySeqQueue(list);

	free(list);
	list = NULL;

}