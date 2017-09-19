#pragma once
#ifndef SEQUALQUEUE_LINEMANAGER_H
#define SEQUALQUEUE_LINEMANAGER_H

#ifdef __cplusplus
extern "C" {
#endif
	// 链表实现排队缓冲区管理（队列）
	// 1、基本链表结点结构体
	typedef struct _SeqQueue
	{
		int dataID;							// 存储对应排队序号
		struct _SeqQueue * next;			// 指向下一结点
	}SeqQueueNode;

	// 2、管理链表结构体
	typedef struct _SeqQueueList
	{
		int size;							// 队列中链表结点个数，即排队人数
		int num;							// 排队号码计数
		SeqQueueNode * pfront;				// 队列头结点
		SeqQueueNode * ptail;				// 队列尾结点
	}SeqQueueList;

	// 3、函数接口实现

	/*
	3.1 初始化
	函数功能：实现队列初始化，初始化排队号码num，初始化队列排队人数size
	函数参数：SeqQueueList * list，要初始化的管理队列头结点
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialSeqQueueList(SeqQueueList * list);

	/*
	3.2 入队列
	函数功能：链表实现入队列管理，data存储排队人数编号
	函数参数：SeqQueueList * list，队列头结点
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int IntoSeqQueue(SeqQueueList * list);

	/*
	3.3 出队列
	函数功能：队首元素出队列，删除队首链表结点
	函数参数：SeqQueueList * list，管理队列头结点
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int OutSeqQueue(SeqQueueList * list);

	/*
	3.4 取得队列人数
	函数功能：获取队列当时排队人数
	函数参数：SeqQueueList * list，管理队列头结点
	函数返回值：成功返回 实际人数 numbers，失败返回 -1；
	*/
	int getCountSeqQueue(SeqQueueList * list);

	/*
	3.5 销毁队列
	函数功能：销毁队列链表结点
	函数参数：SeqQueueList * list，管理队列头结点
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int DestroySeqQueue(SeqQueueList * list);

	/*
	3.6 重置排队号码
	函数功能：重置排队号码，从1号开始
	函数参数：SeqQueueList * list，管理队列头结点
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int ResetNumSeqQueue(SeqQueueList * list);

	/*
	3.7 打印输出dataID
	函数功能：遍历输出队列排队的号码
	函数参数：SeqQueueList * list，管理队列头结点
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintSeqQueue(SeqQueueList * list);

	/*
	3.8 获取队列队首元素值 dataID
	函数功能：
	函数参数：SeqQueueList * list，要初始化的管理队列头结点
	函数返回值：成功返回 dataID，失败返回 -1；
	*/
	int GetValueSeqQueueList(SeqQueueList * list);

	/*
	3.X 测试函数
	函数功能：整体功能测试
	函数参数：
	函数返回值：
	*/
	void TestSeqQueueList();

#ifdef __cplusplus
}
#endif

#endif // SEQUALQUEUE_LINEMANAGER_H
