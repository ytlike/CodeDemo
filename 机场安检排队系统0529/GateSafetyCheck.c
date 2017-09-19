#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"GateSafetyCheck.h"



// 3、安检门操作
/*
3.1 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
3.2 进入安检门队列
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int IntoGateList(GateList * gatelist, int dataID)
{
	// for error
	if (NULL == gatelist)
	{
		return -1;
	}

	// 队列人员控制
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
3.3 出安检门队列
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
3.4 获取安检门队列人数
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
3.5 获取安检门队列队首元素信息
函数功能：
函数参数：
函数返回值：成功返回 dataID，失败返回 -1；
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
3.6 销毁安检门队列
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
3.7 遍历获取安检门队列人员信息不销毁
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
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
3.X 测试函数
函数功能：整体功能测试
函数参数：
函数返回值：
*/
void TestGateList()
{
	GateList * gatelist = (GateList *)malloc(sizeof(GateList));
	memset(gatelist, 0, sizeof(GateList));

	// 初始化
	InitialGateList(gatelist);
	// 排队人员 dataID 输入
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