#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"ControlAll.h"
//#include	"PrintAll.h"


/*
1.1 ���廭�����-����̨
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int MainPicPrintAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// �����ǰʱ��
	PrintTimeNow(allControl);

	// �����ǰ���촰��״̬+���촰��״̬
	PrintGateState(allControl);

	// ����Ŷӻ�����
	PrintSeqQueuePassenger(allControl);

	// �����ǰ������-ֱ�۲�����


	return 0;
}


/*
1.2 �����ǰʱ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int PrintTimeNow(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// show time
	PrintTimeThree(&allControl->systime);

	return 0;
}


/*
1.3 �����ǰ���촰��״̬ �ϱ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int PrintGateState(ControlAll * allControl)
{
	if (NULL == allControl)
	{
		return -1;
	}

	char isWorkStr[] = { "���ڷ���" };
	char noWorkStr[] = { "ֹͣ����" };
	char isCloseStr[] = { "�ر�" };
	char noCloseStr[] = { "����" };
	char isRestStr[] = { "������Ϣ" };
	char noRestStr[] = { "��Ϣ����" };
	char showWorkStr[10] = { 0 };
	char showQueueStr[256] = { 0 };// ���ȿ�С�� debug 1 solved
	int tempdataID = 0;
	// �����ǰ���촰��״̬ �ϱ���
	char gateNumberStr[] = { "���ں���" };
	char serviceStr[] = { "����״̬" };
	char passengerStr[] = { "�Ŷ���Ա" };
	char serverTimeStr[] = { "����ʱ��" };
	char passengerNumberStr[] = { "�Ŷ�����" };
	//printf("���ں���\t����״̬\t�Ŷ���Ա\t\t����ʱ��\t�Ŷ�����\n");
	printf("%-16s%-16s%-36s%-16s%-16s\n", gateNumberStr, serviceStr, passengerStr, serverTimeStr, passengerNumberStr);

	char showWindowNumber[100] = { 0 };
	// ������ര�� + ���ڶ���
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		// ����״̬����
		memset(showWorkStr, 0, sizeof(showWorkStr));
		switch (allControl->gatelist[i].WorkState)
		{
		case isWork:
			strcpy(showWorkStr, isWorkStr);
			break;
		case noWork:
			strcpy(showWorkStr, noWorkStr);
			break;
		case isClose:
			strcpy(showWorkStr, isCloseStr);
			break;
		case noClose:
			strcpy(showWorkStr, noCloseStr);
			break;
		case isRest:
			strcpy(showWorkStr, isRestStr);
			break;
		case noRest:
			strcpy(showWorkStr, noRestStr);
			break;
		default:
			break;
		}

		// ���촰�ڶ����Ŷ�״̬����
		memset(showQueueStr, 0, sizeof(showQueueStr));
		DealGataQueueStrALL(allControl, showQueueStr, i);

		// ��ȡ���׳˿͵�dataID
		tempdataID = GetInfoGateList(allControl->gatelist);
		if (-1 == tempdataID)
		{
			tempdataID = 0;
		}
		sprintf(showWindowNumber, "Window[%d]", i + 1);
		printf("%-16s%-16s%-36s%-16d%-16d\n", showWindowNumber, showWorkStr, showQueueStr, allControl->passenger[tempdataID].servicedTimes, allControl->gatelist[i].size);

		//printf("Window[%d]\t%s\t%s\t\t%d\t%d\n", i + 1, showWorkStr, showQueueStr, allControl->passenger[tempdataID].servicedTimes, allControl->gatelist[i].size);
	}



	// �������
	//printf("%s\n", allControl->keyboard.orderStr);


	return 0;
}




/*
1.4 �����ǰ���촰��״̬ �ϱ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int PrintSeqQueuePassenger(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	//if (allControl->Seqlist.size <= 0)
	//{
	//	return -1;
	//}

	printf("�Ŷӻ�������");

	SeqQueueNode * pcur = allControl->Seqlist.pfront;

	while (pcur != NULL)
	{
		printf("G%d ", pcur->dataID);
		pcur = pcur->next;
	}

	printf("\n");
	return 0;
}
