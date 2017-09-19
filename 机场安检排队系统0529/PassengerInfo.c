#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"PassengerInfo.h"

// 3、相关操作
/*
3.1 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialPassenger(Passenger * passenger)
{
	if (NULL == passenger)
	{
		return -1;
	}

	passenger->dataID = -1;
	passenger->servicedTimes = -1;
	passenger->startIntoSeqQueue = -1;
	passenger->endOutSeqQueue = -1;
	passenger->StaySeqQueueTimeAll = -1;
	passenger->startGataList = -1;
	passenger->endGataList = -1;
	passenger->isStartService = false;

	return 0;
}