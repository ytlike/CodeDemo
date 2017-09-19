#pragma once
#ifndef PRINTALL_H
#define PRINTALL_H

//#include "ControlAll.h"
//extern struct _ControlALL;
//extern ControlAll;

#ifdef __cplusplus
extern	"C" {
#endif

	// 输出模块
	
	/*
	1.0 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	//int InitialPrintAll(ControlAll * allControl);


	/*
	1.1 整体画面输出
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int MainPicPrintAll(ControlAll * allControl);

	/*
	1.2 输出当前时间
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintTimeNow(ControlAll * allControl);

	/*
	1.3 输出当前安检窗口状态 上边栏
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintGateState(ControlAll * allControl);

	/*
	1.4 输出当前安检窗口状态 上边栏
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintSeqQueuePassenger(ControlAll * allControl);



#ifdef __cplusplus
}
#endif

#endif // !PRINTALL_H
