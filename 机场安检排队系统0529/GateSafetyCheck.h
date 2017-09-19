#ifndef GATESAFETYCHECK_H
#define GATESAFETYCHECK_H

#ifdef __cplusplus
extern "C" {
#endif

#include	<stdbool.h>

#define MAXNUMBERPASSENGER 6

	enum WindowWorkState {
		isWork,
		noWork,
		isRest,
		noRest,
		isClose,
		noClose
	};


	// 1、安检门6人队列基本链表结点
	typedef struct _GateNode
	{
		int dataID;
		struct _GateNode * next;
	}GateNode;

	// 2、管理安检门链表结构体
	typedef struct _GateList
	{
		int size;
		bool isNeedPassenger;
		bool isGoOffWork;
		int	WorkState;
		time_t startRestTime;
		time_t endRestTime;
		time_t tatolRestTime;
		GateNode * pfront;
		GateNode * ptail;
	}GateList;

	// 3、安检门操作

	/*
	3.1 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialGateList(GateList * gatelist);

	/*
	3.2 进入安检门队列
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int IntoGateList(GateList * gatelist, int dataID);

	/*
	3.3 出安检门队列
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int OutGateList(GateList * gatelist);

	/*
	3.4 获取安检门队列人数
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int GetCountGateList(GateList * gatelist);

	/*
	3.5 获取安检门队列队首元素信息
	函数功能：
	函数参数：
	函数返回值：成功返回 dataID，失败返回 -1；
	*/
	int GetInfoGateList(GateList * gatelist);

	/*
	3.6 销毁安检门队列
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int DestroyGateList(GateList * gatelist);

	/*
	3.7 遍历获取安检门队列人员信息不销毁
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintGateList(GateList * gatelist);


	/*
	3.X 测试函数
	函数功能：整体功能测试
	函数参数：
	函数返回值：
	*/
	void TestGateList();


#ifdef __cplusplus
}
#endif

#endif // GATESAFETYCHECK_H