#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"GateSafetyCheck.h"



// 3�������Ų���
/*
3.1 ��ʼ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int InitialGateList(GateList * gatelist)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}

	gatelist->size = 0;
	gatelist->isNeedPassenger = true;
	gatelist->isGoOffWork = true;
	gatelist->WorkState = isWork;
	gatelist->startRestTime = 0;
	gatelist->endRestTime = 0;
	gatelist->tatolRestTime = 0;
	gatelist->pfront = NULL;
	gatelist->ptail = NULL;

	return 0;
}


/*
3.2 ���밲���Ŷ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int IntoGateList(GateList * gatelist, int dataID)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}

	// ������Ա����
	if (gatelist->size >= MAXNUMBERPASSENGER)
	{
		gatelist->isNeedPassenger = false;
		return -1;
	}

	GateNode * pnew = (GateNode *)malloc(sizeof(GateNode));
	pnew->dataID = dataID;
	pnew->next = NULL;

	if (gatelist->pfront == NULL && gatelist->ptail == NULL && gatelist->size == 0)
	{
		gatelist->pfront = pnew;
		gatelist->ptail = pnew;
	}
	else
	{
		gatelist->ptail->next = pnew;
		gatelist->ptail = pnew;
	}

	gatelist->size++;

	if (gatelist->size == MAXNUMBERPASSENGER)
	{
		gatelist->isNeedPassenger = false;
	}


	return 0;
}

/*
3.3 �������Ŷ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int OutGateList(GateList * gatelist)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}
	if (gatelist->size <= 0)
	{
		return -1;
	}

	GateNode * pOut = gatelist->pfront;

	if (gatelist->size == 1)
	{
		gatelist->pfront = NULL;
		gatelist->ptail = NULL;
	}
	else
	{
		gatelist->pfront = pOut->next;
	}

	free(pOut);
	pOut = NULL;

	gatelist->size--;

	if (gatelist->size <= 5)
	{
		gatelist->isNeedPassenger = true;
	}


	return 0;
}

/*
3.4 ��ȡ�����Ŷ�������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int GetCountGateList(GateList * gatelist)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}

	return gatelist->size;
}

/*
3.5 ��ȡ�����Ŷ��ж���Ԫ����Ϣ
�������ܣ�
����������
��������ֵ���ɹ����� dataID��ʧ�ܷ��� -1��
*/
int GetInfoGateList(GateList * gatelist)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}
	if (0 == gatelist->size)
	{
		return -1;
	}
	return gatelist->pfront->dataID;
}

/*
3.6 ���ٰ����Ŷ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int DestroyGateList(GateList * gatelist)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}

	while (gatelist->size)
	{
		OutGateList(gatelist);
	}

	return 0;
}

/*
3.7 ������ȡ�����Ŷ�����Ա��Ϣ������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int PrintGateList(GateList * gatelist)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}

	GateNode * pcur = gatelist->pfront;
	while (pcur != NULL)
	{
		printf("%d ", pcur->dataID);
		pcur = pcur->next;
	}

	return 0;
}


/*
3.X ���Ժ���
�������ܣ����幦�ܲ���
����������
��������ֵ��
*/
void TestGateList()
{
	GateList * gatelist = (GateList *)malloc(sizeof(GateList));
	memset(gatelist, 0, sizeof(GateList));

	// ��ʼ��
	InitialGateList(gatelist);
	// �Ŷ���Ա dataID ����
	for (int i = 0; i < 10; i++)
	{
		IntoGateList(gatelist, i);
	}

	while (gatelist->size)
	{
		PrintGateList(gatelist);
		OutGateList(gatelist);
		printf("\n");
	}


}