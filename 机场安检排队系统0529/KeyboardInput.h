#pragma once
#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#ifdef __cplusplus
extern "C" {
#endif
	// 键盘输入处理模块
#include <stdbool.h>
#define BUFFKEYBOARD 1024
	typedef struct _KeyBoard
	{
		bool isHaveInput;
		char orderStr[BUFFKEYBOARD + 1];
	}KeyBoard;


	/*
	1.0 初始化键盘输入
	函数功能：接收键盘输入处理函数，键盘输入命令处理
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialKeyBoard(KeyBoard * keyboard);

	/*
	1.1 获取键盘输入
	函数功能：接收键盘输入处理函数，键盘输入命令处理
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int GetValueOfKeyBoard(KeyBoard * keyboard);

	/*
	1.2 对键盘输入字符串处理
	函数功能：字符处理函数，
	函数参数：key 输入的字符
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int DisposeInfoKeyBoard(KeyBoard * keyboard);

	/*
	1.3 打印输出字符串
	函数功能：输出字符串 keyboard->orderStr
	函数参数：
	函数返回值：
	*/
	int PrintOrderStrKeyBoard(KeyBoard * keyboard);

	/*
	1.4 发送键盘信息
	函数功能：接收键盘输入处理函数，键盘输入命令处理
	函数参数：
	函数返回值：
	*/
	int isSendValueKeyBoard(KeyBoard * keyboard);

	/*
	1.X 功能测试函数
	函数功能：接收键盘输入处理函数，键盘输入命令处理
	函数参数：
	函数返回值：
	*/
	void TestValueKeyBoard();

#ifdef __cplusplus
}
#endif

#endif // KEYBOARDINPUT_H
