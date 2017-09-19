#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"ControlAll.h"
//#include	"PrintAll.h"


/*
1.1 整体画面输出-控制台
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int MainPicPrintAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// 输出当前时间
	PrintTimeNow(allControl);

	// 输出当前安检窗口状态+安检窗口状态
	PrintGateState(allControl);

	// 输出排队缓冲区
	PrintSeqQueuePassenger(allControl);

	// 输出当前命令行-直观测试用


	return 0;
}


/*
1.2 输出当前时间
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
1.3 输出当前安检窗口状态 上边栏
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int PrintGateState(ControlAll * allControl)
{
	if (NULL == allControl)
	{
		return -1;
	}

	char isWorkStr[] = { "正在服务" };
	char noWorkStr[] = { "停止服务" };
	char isCloseStr[] = { "关闭" };
	char noCloseStr[] = { "开启" };
	char isRestStr[] = { "正在休息" };
	char noRestStr[] = { "休息结束" };
	char showWorkStr[10] = { 0 };
	char showQueueStr[256] = { 0 };// 长度开小了 debug 1 solved
	int tempdataID = 0;
	// 输出当前安检窗口状态 上边栏
	char gateNumberStr[] = { "窗口号码" };
	char serviceStr[] = { "服务状态" };
	char passengerStr[] = { "排队人员" };
	char serverTimeStr[] = { "服务时间" };
	char passengerNumberStr[] = { "排队人数" };
	//printf("窗口号码\t服务状态\t排队人员\t\t服务时间\t排队人数\n");
	printf("%-16s%-16s%-36s%-16s%-16s\n", gateNumberStr, serviceStr, passengerStr, serverTimeStr, passengerNumberStr);

	char showWindowNumber[100] = { 0 };
	// 输出安监窗口 + 窗口队列
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		// 工作状态处理
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

		// 安检窗口队列排队状态处理
		memset(showQueueStr, 0, sizeof(showQueueStr));
		DealGataQueueStrALL(allControl, showQueueStr, i);

		// 获取队首乘客的dataID
		tempdataID = GetInfoGateList(allControl->gatelist);
		if (-1 == tempdataID)
		{
			tempdataID = 0;
		}
		sprintf(showWindowNumber, "Window[%d]", i + 1);
		printf("%-16s%-16s%-36s%-16d%-16d\n", showWindowNumber, showWorkStr, showQueueStr, allControl->passenger[tempdataID].servicedTimes, allControl->gatelist[i].size);

		//printf("Window[%d]\t%s\t%s\t\t%d\t%d\n", i + 1, showWorkStr, showQueueStr, allControl->passenger[tempdataID].servicedTimes, allControl->gatelist[i].size);
	}



	// 测试输出
	//printf("%s\n", allControl->keyboard.orderStr);


	return 0;
}




/*
1.4 输出当前安检窗口状态 上边栏
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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

	printf("排队缓冲区：");

	SeqQueueNode * pcur = allControl->Seqlist.pfront;

	while (pcur != NULL)
	{
		printf("G%d ", pcur->dataID);
		pcur = pcur->next;
	}

	printf("\n");
	return 0;
}
