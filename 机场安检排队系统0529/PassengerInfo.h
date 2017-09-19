#pragma once
#ifndef PASSENGEMANAGE_H
#define PASSENGEMANAGE_H

#include	<time.h>
#include	<stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

	// 排队人员信息管理
	// 基本人员信息结构体
	typedef struct _Passenger
	{
		int dataID;
		int servicedTimes;
		time_t startIntoSeqQueue;
		time_t endOutSeqQueue;
		time_t StaySeqQueueTimeAll;
		time_t startGataList;
		time_t endGataList;
		bool isStartService;
	}Passenger;

	// 3、相关操作
	/*
	3.1 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialPassenger(Passenger * passenger);

#ifdef __cplusplus
}
#endif

#endif // PASSENGEMANAGE_H