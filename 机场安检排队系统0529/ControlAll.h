#pragma once
#ifndef CONTROLALL_H
#define CONTROLALL_H

#include	"FileInput.h"							// NO.1.1 文件输入模块		头文件
#include	"KeyboardInput.h"						// NO.1.2 键盘输入模块		头文件
#include	"SequalQueue.h"							// NO.2 排队缓冲区模块		头文件
#include	"GateSafetyCheck.h"						// NO.3 安检口模块			头文件
#include	"PassengerInfo.h"						// NO.4 乘客人员信息模块	头文件
#include	"Config.h"								// NO.5 配置信息模块		头文件
#include	"ShowTime.h"							// NO.6 时间显示模块		头文件


#define PASSENGERMAXN		2048
#define BUFFCONTROL			1024
#define GATENUMBERMAXN		8
#define GATEQUEUEMAXN		6

// 总体控制模块
// 1 总体控制模块结构体
typedef struct _ControlALL
{
	// 相关模块整合
	FileInput		fileInput;					// NO.1.1 文件输入模块
	KeyBoard		keyboard;					// NO.1.2 键盘输入模块
	SeqQueueList	Seqlist;					// NO.2 排队缓冲区模块
	GateList		gatelist[GATENUMBERMAXN];	// NO.3 安检口模块
	Passenger		passenger[PASSENGERMAXN];	// NO.4 乘客人员信息模块
	Config			config;						// NO.5 配置信息模块
	ShowTime		systime;					// NO.6 时间显示模块
	//PrintAll		printall;					// NO.7 输出模块


	// 命令行字符串
	char			orderStr[BUFFCONTROL + 1];	// 命令行
	int				orderT;						// 命令行参数T

	//// 系统配置参数
	//int				MinSec;						// 最短业务办理时间
	//int				MaxSec;						// 最长业务办理时间
	//int				MinRestSec;					// 最短窗口休息时间
	//int				MaxRestSec;					// 最长窗口休息时间

	//// 队列长度参数
	//int				MaxCustSingleLine;			// 单队列最大等待乘客数
	//int				MaxLines;					// 蛇形缓冲区最多由MaxLines个直队组成
	//int				MaxSeqLen;					// 最大允许等待长度
	//int				MinTimeLen;					// 一次安检最短时间，单位分钟
	//int				MaxTimeLen;					// 一次安检最长时间，单位分钟

}ControlAll;

#include	"PrintAll.h"


#ifdef __cplusplus
extern "C" {
#endif


	// 2 配置文件读取

	// 3、相关操作
	/*
	3.1 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialControlAll(ControlAll * allControl);

	/*
	3.2 进入排队缓冲区人员控制
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int SeqQueueControlAll(ControlAll * allControl);

	/*
	3.3 进入安检窗口人员控制
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int GateWindowControlAll(ControlAll * allControl);

	/*
	3.4 字符串命令行处理
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int orderStrControlAll(ControlAll * allControl);

	/*
	3.5 取得键盘输入内容
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int GetValueOfKeyBoardInputALL(ControlAll * allControl);

	/*
	3.6 处理命令行
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 - 1；
	*/
	int DealOrderLineALL(ControlAll * allControl);

	/*
	3.7 安检窗口队列排队状态处理
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 - 1；
	*/
	int DealGataQueueStrALL(ControlAll * allControl, char * showQueueStr, int GateWindowNumber);

	/*
	3.8 乘客进入安检窗口分配
	函数功能：
	函数参数：
	函数返回值：成功返回 窗口号码 ，失败返回 - 1；
	*/
	DealBeChoosedGateWindowNumber(ControlAll * allControl);

	/*
	3.9 乘客离开安检窗口控制
	函数功能：
	函数参数：
	函数返回值：成功返回 窗口号码 ，失败返回 - 1；
	*/
	LeaveGateWindowControAll(ControlAll * allControl);




	// 4、实例
	/*
	4.1 实例1 键盘输入控制
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int CaseOneControlAll();




#ifdef __cplusplus
}
#endif

#endif // CONTROLALL_H