#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<Windows.h>
#include	<time.h>

#include	"ControlAll.h"
#include	"PrintAll.h"
// 3����ز���
/*
3.1 ��ʼ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int InitialControlAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// initial all
	InitialFileInput(&allControl->fileInput);										// NO.1.1 �ļ�����ģ��
	InitialKeyBoard(&allControl->keyboard);											// NO.1.2 ��������ģ��
	InitialSeqQueueList(&allControl->Seqlist);										// NO.2 �Ŷӻ�����ģ��
	for (int i = 0; i < GATENUMBERMAXN; i++)												// NO.3 �����ģ��
	{
		InitialGateList(&allControl->gatelist[i]);
	}
	for (int i = 4; i < GATENUMBERMAXN; i++)	// �رպ�4������
	{
		allControl->gatelist[i].WorkState = isClose;
	}
	memset(allControl->passenger, 0, sizeof(allControl->passenger));				// NO.4 �˿���Ա��Ϣģ��
	InitialConfig(&allControl->config);												// NO.5 ������Ϣģ��(��ʼ�� ���ò�������)
	InitialShowTime(&allControl->systime);											// NO.6 ʱ����ʾģ��

	memset(allControl->orderStr, 0, sizeof(allControl->orderStr));					// ������
	allControl->orderT = -1;														// �����в���T

	return 0;
}

/*
3.2 �����Ŷӻ�������Ա����
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int SeqQueueControlAll(ControlAll * allControl)
{
	srand((unsigned int)time((time_t *)NULL));
	// ���� orderT��orderStr
	// ���ܣ�
	// ����Ψһ���ŶӺ���
	// ��������˿Ͱ���ʱ��
	// for error
	if (NULL == allControl)
	{
		return -1;
	}


	// orderStr ����
	int dataID;
	for (int i = 0; allControl->orderStr[i] != '\0'; i++)
	{
		if ('G' == allControl->orderStr[i])
		{
			dataID = allControl->Seqlist.num;
			// �˿� dataID
			allControl->passenger[dataID].dataID = dataID;
			// �����������ʱ��
			allControl->passenger[dataID].servicedTimes = rand() % (allControl->config.MaxSec - allControl->config.MinSec + 1) + allControl->config.MinSec;
			// ������л�����
			IntoSeqQueue(&allControl->Seqlist);
			// ��ȡ��ǰʱ�䣬���Ǹս�����е���ʼʱ��
			allControl->passenger[dataID].startIntoSeqQueue = time((time_t *)NULL);
			//allControl->Seqlist.num++;//IntoSeqQueue allControl->Seqlist.num�Ѿ�++
		}
		else if ('R' == allControl->orderStr[i])
		{
			// ��Ϣ����ģ��
		}
		else if ('C' == allControl->orderStr[i])
		{
			// ��Ϣ����ģ��
		}
		else if ('Q' == allControl->orderStr[i])
		{
			// �°ദ��ģ��
		}
	}

	memset(allControl->orderStr, 0, sizeof(allControl->orderStr));
	memset(allControl->keyboard.orderStr, 0, sizeof(allControl->keyboard.orderStr));

	return 0;
}

/*
3.3 ���밲�촰����Ա����
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int GateWindowControlAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// �����л���������Ϊ 0 ������ 0
	if (allControl->Seqlist.size <= 0)
	{
		return 0;
	}

	// ���� �������������
	int needNumberOfPassenger = 0;
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		if (allControl->gatelist[i].isNeedPassenger == true && allControl->gatelist[i].WorkState == isWork)
		{
			needNumberOfPassenger += (GATEQUEUEMAXN - allControl->gatelist[i].size);
		}
	}

	// �Ӷ����л�ȡ�˿�
	int tempdataID = -1;							// �˿� dataID
	int beChoosedGateWindow = -1;					// ��ѡ��Ĵ��ڣ��˿ͽ���İ��촰�ں���
	for (int i = 0; i < needNumberOfPassenger; i++)
	{
		// ��������Ա <=0 ����
		if (0 >= allControl->Seqlist.size)
		{
			break;
		}

		// ��ȡ �˿�dataID
		tempdataID = GetValueSeqQueueList(&allControl->Seqlist);

		// ��ȡ �˿ͽ���İ��촰�ں���
		beChoosedGateWindow = DealBeChoosedGateWindowNumber(allControl);

		// ��һ���ڴ���˿�
		if (IntoGateList(&allControl->gatelist[beChoosedGateWindow], tempdataID) == -1)
		{
			break;
		}

		// �˿ʹӶ��л������ɹ����뵽���촰�ڶ��У����л�����������1
		OutSeqQueue(&allControl->Seqlist);
		// �˿��뿪���л�������ʱ��
		allControl->passenger[tempdataID].endOutSeqQueue = time((time_t *)NULL);
		// �˿�ͣ���ڶ��л�������ʱ��
		allControl->passenger[tempdataID].StaySeqQueueTimeAll = allControl->passenger[tempdataID].endOutSeqQueue - allControl->passenger[tempdataID].startIntoSeqQueue;

		// �� �����������ڵ���������� ����
		if (GATEQUEUEMAXN <= allControl->gatelist[beChoosedGateWindow].size)
		{
			break;
		}

	}


	return 0;
}

/*
3.4 �ַ��������д���
�������ܣ���ȡ�����У���ָ��ʱ��T
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int orderStrControlAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	char tempOrderStr[BUFFCONTROL + 1] = { 0 };
	int  tempOrderT;

	sscanf(allControl->orderStr, "T = %d, EVENT = %s", &tempOrderT, tempOrderStr);

	if (tempOrderT >= 0)
	{
		allControl->orderT = tempOrderT;
	}
	else
	{
		allControl->orderT = -1;
		return -1;
	}

	if (NULL != tempOrderStr)
	{
		strcpy(allControl->orderStr, tempOrderStr);
	}
	else
	{
		allControl->orderT = -1;
		return -1;
	}

	return 0;
}

/*
3.5 ȡ�ü�����������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int GetValueOfKeyBoardInputALL(ControlAll * allControl)
{
	return GetValueOfKeyBoard(&allControl->keyboard);
}

/*
3.6 ����������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� - 1��
*/
int DealOrderLineALL(ControlAll * allControl)
{
	// �������
	//printf("%s\n", allControl->keyboard.orderStr);
	//printf("%s\n", allControl->orderStr);

	memset(allControl->orderStr, 0, sizeof(allControl->orderStr));
	strcpy(allControl->orderStr, allControl->keyboard.orderStr);
	//printf("%s\n", allControl->orderStr);

	orderStrControlAll(allControl);

	// �������
	//if (-1 != allControl->orderT)
	//{
	//	printf("%d\t", allControl->orderT);
	//	printf("%s\n", allControl->orderStr);
	//}
}

/*
3.7 �����촰�ڶ����Ŷ�״̬
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� - 1��
*/
int DealGataQueueStrALL(ControlAll * allControl, char * showQueueStr, int GateWindowNumber)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// showQueueStr ����ǰ�Ѿ���ʼ��0
	int tempDataID;
	// ����������л�ȡ�Ŷ���Ϣ
	GateNode * pcur = allControl->gatelist[GateWindowNumber].pfront;
	for (int i = 0; i < allControl->gatelist[GateWindowNumber].size; i++)
	{
		tempDataID = pcur->dataID;
		sprintf(showQueueStr, "%sG%d ", showQueueStr, tempDataID);
		pcur = pcur->next;
	}

	return 0;
}

/*
3.8 �˿ͽ��밲�촰�ڷ���
�������ܣ�
����������
��������ֵ���ɹ����� ���ں��� ��ʧ�ܷ��� - 1��
*/
DealBeChoosedGateWindowNumber(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	int minSizeNum = 0;

	// minSizeNum ��ʼֵ����ȡһ�����ڹ����Ĵ���
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		if (allControl->gatelist[i].WorkState == isWork)
		{
			minSizeNum = i;
			break;
		}
	}

	// �Ƚϴ�С��ѡ�����ڹ����еĴ����������ٵ�
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		if (allControl->gatelist[i].WorkState == isWork)
		{
			if (allControl->gatelist[minSizeNum].size > allControl->gatelist[i].size)
			{
				minSizeNum = i;
			}
		}
	}

	// ���������������ٵĴ��ں���
	return minSizeNum;

}

/*
3.9 �˿��뿪���촰�ڿ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� - 1��
*/
LeaveGateWindowControAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// ��ȡ��ʼ����˿͵�dataID,���ǻ�ȡ������еĶ���Ԫ��dataID
	int tempDataID = -1;

	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		tempDataID = GetInfoGateList(&allControl->gatelist[i]);
		if (-1 == tempDataID)
		{
			continue;
		}

		// ��ȡ����ʼʱ��
		if (allControl->passenger[tempDataID].isStartService == false)
		{
			allControl->passenger[tempDataID].startGataList = time((time_t *)NULL);
			allControl->passenger[tempDataID].isStartService = true;
		}
		// ��ȡ���������ʱ��
		else
		{
			allControl->passenger[tempDataID].endGataList = time((time_t *)NULL);
		}

		// ������ε�ʱ��� ���ڵ��� ����ʱ�䣬���������
		if (allControl->passenger[tempDataID].servicedTimes <= allControl->passenger[tempDataID].endGataList - allControl->passenger[tempDataID].startGataList)
		{
			OutGateList(&allControl->gatelist[i]);
		}
	}


	return 0;
}




// 4��ʵ��
/*
4.1 ʵ��1 �����������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int CaseOneControlAll()
{
	ControlAll * allControl = (ControlAll *)malloc(sizeof(ControlAll));
	memset(allControl, 0, sizeof(ControlAll));

	// initial all
	InitialControlAll(allControl);

	// for error
	if (NULL == allControl)
	{
		return -1;
	}
	/*-----------------------------------------------------------------------------
	�������� ÿ�ζ�һ��������������
	1����ȡָ����̻����ļ�
	2��ָ������ɳ˿���Ϣ�������������ʱ�䣬Passenger�洢��Ψһ��dataID
	3��������л�����
	4�����봰�ڷ�����
	5����������뿪�����

	-----------------------------------------------------------------------------*/

	system("color f0");

	while (1)
	{
		MainPicPrintAll(allControl);
		GetValueOfKeyBoardInputALL(allControl);			// 1����ȡָ��
		DealOrderLineALL(allControl);					// 2��ָ���
		SeqQueueControlAll(allControl);					// 3��������л�����
		system("cls");
		MainPicPrintAll(allControl);
		GateWindowControlAll(allControl);				// 4�����밲�촰�ڶ�����
		LeaveGateWindowControAll(allControl);			// 5����������뿪�����
		Sleep(1000);
		system("cls");

	}




	return 0;
}