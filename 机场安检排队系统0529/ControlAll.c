#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<Windows.h>
#include	<time.h>

#include	"ControlAll.h"
#include	"PrintAll.h"
// 3、相关操作
/*
3.1 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialControlAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// initial all
	InitialFileInput(&allControl->fileInput);										// NO.1.1 文件输入模块
	InitialKeyBoard(&allControl->keyboard);											// NO.1.2 键盘输入模块
	InitialSeqQueueList(&allControl->Seqlist);										// NO.2 排队缓冲区模块
	for (int i = 0; i < GATENUMBERMAXN; i++)												// NO.3 安检口模块
	{
		InitialGateList(&allControl->gatelist[i]);
	}
	for (int i = 4; i < GATENUMBERMAXN; i++)	// 关闭后4个窗口
	{
		allControl->gatelist[i].WorkState = isClose;
	}
	memset(allControl->passenger, 0, sizeof(allControl->passenger));				// NO.4 乘客人员信息模块
	InitialConfig(&allControl->config);												// NO.5 配置信息模块(初始化 配置参数数据)
	InitialShowTime(&allControl->systime);											// NO.6 时间显示模块

	memset(allControl->orderStr, 0, sizeof(allControl->orderStr));					// 命令行
	allControl->orderT = -1;														// 命令行参数T

	return 0;
}

/*
3.2 进入排队缓冲区人员控制
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int SeqQueueControlAll(ControlAll * allControl)
{
	srand((unsigned int)time((time_t *)NULL));
	// 传入 orderT，orderStr
	// 功能：
	// 生产唯一的排队号码
	// 生成随机乘客安检时间
	// for error
	if (NULL == allControl)
	{
		return -1;
	}


	// orderStr 处理
	int dataID;
	for (int i = 0; allControl->orderStr[i] != '\0'; i++)
	{
		if ('G' == allControl->orderStr[i])
		{
			dataID = allControl->Seqlist.num;
			// 乘客 dataID
			allControl->passenger[dataID].dataID = dataID;
			// 产生随机服务时间
			allControl->passenger[dataID].servicedTimes = rand() % (allControl->config.MaxSec - allControl->config.MinSec + 1) + allControl->config.MinSec;
			// 进入队列缓冲区
			IntoSeqQueue(&allControl->Seqlist);
			// 获取当前时间，即是刚进入队列的起始时间
			allControl->passenger[dataID].startIntoSeqQueue = time((time_t *)NULL);
			//allControl->Seqlist.num++;//IntoSeqQueue allControl->Seqlist.num已经++
		}
		else if ('R' == allControl->orderStr[i])
		{
			// 休息处理模块
		}
		else if ('C' == allControl->orderStr[i])
		{
			// 休息处理模块
		}
		else if ('Q' == allControl->orderStr[i])
		{
			// 下班处理模块
		}
	}

	memset(allControl->orderStr, 0, sizeof(allControl->orderStr));
	memset(allControl->keyboard.orderStr, 0, sizeof(allControl->keyboard.orderStr));

	return 0;
}

/*
3.3 进入安检窗口人员控制
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int GateWindowControlAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// 若队列缓冲区人数为 0 ，返回 0
	if (allControl->Seqlist.size <= 0)
	{
		return 0;
	}

	// 计算 安检口所需人数
	int needNumberOfPassenger = 0;
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		if (allControl->gatelist[i].isNeedPassenger == true && allControl->gatelist[i].WorkState == isWork)
		{
			needNumberOfPassenger += (GATEQUEUEMAXN - allControl->gatelist[i].size);
		}
	}

	// 从队列中获取乘客
	int tempdataID = -1;							// 乘客 dataID
	int beChoosedGateWindow = -1;					// 被选择的窗口，乘客进入的安检窗口号码
	for (int i = 0; i < needNumberOfPassenger; i++)
	{
		// 若队列人员 <=0 跳出
		if (0 >= allControl->Seqlist.size)
		{
			break;
		}

		// 获取 乘客dataID
		tempdataID = GetValueSeqQueueList(&allControl->Seqlist);

		// 获取 乘客进入的安检窗口号码
		beChoosedGateWindow = DealBeChoosedGateWindowNumber(allControl);

		// 单一窗口处理乘客
		if (IntoGateList(&allControl->gatelist[beChoosedGateWindow], tempdataID) == -1)
		{
			break;
		}

		// 乘客从队列缓冲区成功进入到安检窗口队列，队列缓冲区出队列1
		OutSeqQueue(&allControl->Seqlist);
		// 乘客离开队列缓冲区的时间
		allControl->passenger[tempdataID].endOutSeqQueue = time((time_t *)NULL);
		// 乘客停留在队列缓冲区的时间
		allControl->passenger[tempdataID].StaySeqQueueTimeAll = allControl->passenger[tempdataID].endOutSeqQueue - allControl->passenger[tempdataID].startIntoSeqQueue;

		// 若 窗口人数大于等于最大人数 跳出
		if (GATEQUEUEMAXN <= allControl->gatelist[beChoosedGateWindow].size)
		{
			break;
		}

	}


	return 0;
}

/*
3.4 字符串命令行处理
函数功能：提取命令行，和指令时间T
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
3.5 取得键盘输入内容
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int GetValueOfKeyBoardInputALL(ControlAll * allControl)
{
	return GetValueOfKeyBoard(&allControl->keyboard);
}

/*
3.6 处理命令行
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 - 1；
*/
int DealOrderLineALL(ControlAll * allControl)
{
	// 测试输出
	//printf("%s\n", allControl->keyboard.orderStr);
	//printf("%s\n", allControl->orderStr);

	memset(allControl->orderStr, 0, sizeof(allControl->orderStr));
	strcpy(allControl->orderStr, allControl->keyboard.orderStr);
	//printf("%s\n", allControl->orderStr);

	orderStrControlAll(allControl);

	// 测试输出
	//if (-1 != allControl->orderT)
	//{
	//	printf("%d\t", allControl->orderT);
	//	printf("%s\n", allControl->orderStr);
	//}
}

/*
3.7 处理安检窗口队列排队状态
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 - 1；
*/
int DealGataQueueStrALL(ControlAll * allControl, char * showQueueStr, int GateWindowNumber)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// showQueueStr 进入前已经初始化0
	int tempDataID;
	// 遍历安检队列获取排队信息
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
3.8 乘客进入安检窗口分配
函数功能：
函数参数：
函数返回值：成功返回 窗口号码 ，失败返回 - 1；
*/
DealBeChoosedGateWindowNumber(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	int minSizeNum = 0;

	// minSizeNum 初始值，获取一个正在工作的窗口
	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		if (allControl->gatelist[i].WorkState == isWork)
		{
			minSizeNum = i;
			break;
		}
	}

	// 比较大小，选择正在工作中的窗口人数最少的
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

	// 返回人数窗口最少的窗口号码
	return minSizeNum;

}

/*
3.9 乘客离开安检窗口控制
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 - 1；
*/
LeaveGateWindowControAll(ControlAll * allControl)
{
	// for error
	if (NULL == allControl)
	{
		return -1;
	}

	// 获取开始安检乘客的dataID,即是获取安检队列的队首元素dataID
	int tempDataID = -1;

	for (int i = 0; i < GATENUMBERMAXN; i++)
	{
		tempDataID = GetInfoGateList(&allControl->gatelist[i]);
		if (-1 == tempDataID)
		{
			continue;
		}

		// 获取服务开始时间
		if (allControl->passenger[tempDataID].isStartService == false)
		{
			allControl->passenger[tempDataID].startGataList = time((time_t *)NULL);
			allControl->passenger[tempDataID].isStartService = true;
		}
		// 获取结束服务的时间
		else
		{
			allControl->passenger[tempDataID].endGataList = time((time_t *)NULL);
		}

		// 如果两次的时间差 大于等于 服务时间，出安检队列
		if (allControl->passenger[tempDataID].servicedTimes <= allControl->passenger[tempDataID].endGataList - allControl->passenger[tempDataID].startGataList)
		{
			OutGateList(&allControl->gatelist[i]);
		}
	}


	return 0;
}




// 4、实例
/*
4.1 实例1 键盘输入控制
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
	处理流程 每次对一个命令行做处理
	1、获取指令：键盘或者文件
	2、指令处理：生成乘客信息，随机产生服务时间，Passenger存储，唯一的dataID
	3、进入队列缓冲区
	4、进入窗口服务区
	5、安检完毕离开安检口

	-----------------------------------------------------------------------------*/

	system("color f0");

	while (1)
	{
		MainPicPrintAll(allControl);
		GetValueOfKeyBoardInputALL(allControl);			// 1、获取指令
		DealOrderLineALL(allControl);					// 2、指令处理
		SeqQueueControlAll(allControl);					// 3、进入队列缓冲区
		system("cls");
		MainPicPrintAll(allControl);
		GateWindowControlAll(allControl);				// 4、进入安检窗口队列区
		LeaveGateWindowControAll(allControl);			// 5、安检完毕离开安检口
		Sleep(1000);
		system("cls");

	}




	return 0;
}