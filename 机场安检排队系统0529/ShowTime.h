#pragma once
#ifndef SHOWTIME_H
#define SHOWTIME_H

#ifdef __cplusplus
extern "C" {
#endif


#include	<time.h>

	// 时间显示
	// 1 系统配置参数结构体
	typedef struct _ShowTime
	{
		time_t timeNow;

	}ShowTime;


	/*
	1.0 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialShowTime(ShowTime * systime);

	/*
	1.1 显示时间
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintTime(ShowTime * systime);

	/*
	1.2 显示时间格式二
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintTimeTwo(ShowTime * systime);

	/*
	1.3 显示时间格式三
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintTimeThree(ShowTime * systime);

	/*
	1.X 功能测试函数
	函数功能：打开配置文件，修改配置文件
	函数参数：
	函数返回值：
	*/
	void TestShowTime();


#ifdef __cplusplus
}
#endif

#endif // SHOWTIME_H
