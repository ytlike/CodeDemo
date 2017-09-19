#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#include	<stdio.h>
#include	<stdbool.h>
#define		BUFFCONFIG		1024
#define		STRCONFIGPAHT	"./config.txt"

// 系统配置
// 1 系统配置参数结构体
typedef struct _Config
{
	FILE			*pConfig;
	char			ConfigPath[BUFFCONFIG];
	bool			isOpen;

	int				MinSec;					// 最短业务办理时间
	int				MaxSec;					// 最长业务办理时间
	int				MinRestSec;				// 最短窗口休息时间
	int				MaxRestSec;				// 最长窗口休息时间

											
	int				MaxCustSingleLine;		// 单队列最大等待乘客数
	int				MaxLines;				// 蛇形缓冲区最多由MaxLines个直队组成
	int				MaxSeqLen;				// 最大允许等待长度
	int				MinTimeLen;				// 一次安检最短时间，单位分钟
	int				MaxTimeLen;				// 一次安检最长时间，单位分钟
}Config;

#ifdef __cplusplus
extern "C" {
#endif
	/*
	1.0 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialConfig(Config * config);

	/*
	1.1 修改配置信息
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int ChangeConfig(Config * config);

	/*
	1.2 输出配置信息
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintConfig(Config * config);

	/*
	1.X 功能测试函数
	函数功能：打开配置文件，修改配置文件
	函数参数：
	函数返回值：
	*/
	void TestConfig();


#ifdef __cplusplus
}
#endif

#endif // CONFIG_H
