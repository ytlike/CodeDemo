#pragma once
#ifndef FILEINPUT_H
#define FILEINPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

#define FileInputTxtPath "./input.txt"
#define BUFFFILEINPUT	1024
#define MAXPATH			1024

	// 管理文件结构体
	typedef struct _FileInput
	{
		FILE * fp;
		char inputPath[MAXPATH];
		bool isOpen;
		bool isHaveOrderInfo;
		char orderStr[BUFFFILEINPUT + 1];
	}FileInput;




	// 文件输入操作
	/*
	1.0 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialFileInput(FileInput * fileinput);

	/*
	1.1 文件命令读取
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int GetValueFileInput(FileInput * fileinput);

	/*
	1.2 文件命令字符串处理
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int DisposeInfoFileInput(FileInput * fileinput);

	/*
	1.3 打印输出字符串
	函数功能：输出字符串 fileinput->orderStr
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int PrintOrderStrFileInput(FileInput * fileinput);

	/*
	1.4 发送文件输入信息
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int isSendValueFileInput(FileInput * fileinput);

	/*
	1.X 功能测试函数
	函数功能：
	函数参数：
	函数返回值：
	*/
	void TestValueFileInput();

#ifdef __cplusplus
}
#endif

#endif // FILEINPUT_H
