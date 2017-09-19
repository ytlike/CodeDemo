#define _CRT_SECUSE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"SequalQueue.h"

// 链表实现排队缓冲区管理（队列）

// 3、函数接口实现

/*
3.1 初始化
函数功能：实现队列初始化，初始化排队号码num，初始化队列排队人数size
函数参数：SeqQueueList * list，要初始化的管理队列头结点
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialSeqQueueList(SeqQueueList * list)
{
	// for error
	if (NULL == list)
	{
		return -1;
	}
	list->size = 0;					// 队列中人数
	list->num = 1;					// 排队号码
	list->pfront = NULL;			// 队列首结点
	list->ptail = NULL;				// 队列尾结点

	return 0;
}

/*
3.2 入队列
函数功能：链表实现入队列管理，data存储排队人数编号
函数参数：SeqQueueList * list，队列头结点
函数返回值：成功返回 0，失败返回 -1；
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
3.3 出队列
函数功能：队首元素出队列，删除队首链表结点
函数参数：SeqQueueList * list，管理队列头结点
函数返回值：成功返回 0，失败返回 -1, 队列为空返回 -2；
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
3.4 取得队列人数
函数功能：获取队列当时排队人数
函数参数：SeqQueueList * list，管理队列头结点
函数返回值：成功返回 实际人数 numbers，失败返回 -1；
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
3.5 销毁队列
函数功能：销毁队列链表结点
函数参数：SeqQueueList * list，管理队列头结点
函数返回值：成功返回 0，失败返回 -1；
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
3.6 重置排队号码
函数功能：重置排队号码，从1号开始
函数参数：SeqQueueList * list，管理队列头结点
函数返回值：成功返回 0，失败返回 -1；
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
3.7 打印输出dataID
函数功能：遍历输出队列排队的号码
函数参数：SeqQueueList * list，管理队列头结点
函数返回值：成功返回 0，失败返回 -1；
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
3.8 获取队列队首元素值 dataID
函数功能：
函数参数：SeqQueueList * list，要初始化的管理队列头结点
函数返回值：成功返回 dataID，失败返回 -1；
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
3.X 测试函数
函数功能：整体功能测试
函数参数：
函数返回值：
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