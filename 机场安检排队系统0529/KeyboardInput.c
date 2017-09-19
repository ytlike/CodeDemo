#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<conio.h>
#include	<Windows.h>
#include	"KeyboardInput.h"

/*
1.0 初始化键盘输入
函数功能：接收键盘输入处理函数，键盘输入命令处理
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}

	keyboard->isHaveInput = false;
	memset(keyboard->orderStr, 0, sizeof(keyboard->orderStr));

	return 0;
}

/*
1.1 获取键盘输入
函数功能：接收键盘输入处理函数，键盘输入命令处理
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int GetValueOfKeyBoard(KeyBoard * keyboard)
{
	// 等待键盘输入
	// kbhit()
	// 功能：检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
	// vc 6.0++ 下为 _kbhit()
	// 头文件：conio.h

	while (_kbhit())
	{
		//无显获取字符
		// getcha() 不回显获取键盘字符
		// 头文件：conio.h
		char * flagOrderStr = fgets(keyboard->orderStr, BUFFKEYBOARD, stdin);
		keyboard->isHaveInput = true;
		if (flagOrderStr != NULL)
		{
			//Sleep(1000);
			break;
		}
	}

	//// 测试输出
	//if (keyboard->isHaveInput == true)
	//{
	//	// here1 is test print keyboard->orderStr
	//	printf("\n字符串处理前:\n");
	//	PrintOrderStrKeyBoard(keyboard);
	//}

	// 键盘输入字符处理
	int isOrderStr = DisposeInfoKeyBoard(keyboard);

	if (-1 == isOrderStr)
	{
		keyboard->isHaveInput = false;
		memset(keyboard->orderStr, 0, sizeof(keyboard->orderStr));
		return -1;
	}
	else
	{
		//// here2 is test print keyboard->orderStr
		//printf("字符串处理后:\n");
		//PrintOrderStrKeyBoard(keyboard);
		return 0;
	}
}

/*
1.2 对键盘输入处理，输出命名行
函数功能：字符处理函数，
函数参数：key 输入的字符
函数返回值：成功返回 0，失败返回 -1；
*/
int DisposeInfoKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}
	if (keyboard->isHaveInput == false)
	{
		return -1;
	}
	// 生成 命令行 字符串 忽略掉错误指令

	// 处理后格式 T=<请求发生时间>,EVENT=<事件|事件><\n>
	/* 例子
		T = 8， EVENT = G | G | G |
		T = 10，EVENT = G | G |
		T = 15，EVENT = R1
		T = 50，EVENT = G | G | G | G | G | R3
		T = 60，EVENT = C1
		T = 80，EVENT = G | G | G |
		T = 150，EVENT = Q
	*/

	// T = 0， EVENT = G | G | G | 

	// 字符串末尾'\n'处理
	int len = strlen(keyboard->orderStr);
	if (keyboard->orderStr[len-1] == '\n')
	{
		keyboard->orderStr[len-1] = '\0';
	}

	// 时间
	int timeT = 0;
	// 临时存储命令行字符串
	char orderStrTemp[BUFFKEYBOARD + 128];
	memset(orderStrTemp, 0, sizeof(orderStrTemp));

	// 字符串合成 1
	// T = 0， EVENT = G | G | G |
	// 输出测试
	//sprintf(orderStrTemp, "T=%d,EVENT=", timeT);

	// 字符串合成 2
	// 中间存储 两个字节 命令变量
	char TwoCharOrder[3] = { 0 };
	int posOrderChar = 0;
	int isFirst = 1;
	for (int i = 0; keyboard->orderStr[i] != '\0'; i++)
	{
		// 两个字节命令处理
		if (keyboard->orderStr[i] == 'R' || keyboard->orderStr[i] == 'C')
		{
			if (posOrderChar >= 1)
			{
				posOrderChar = 0;
				memset(TwoCharOrder, 0, sizeof(TwoCharOrder));
				continue;
			}
			TwoCharOrder[posOrderChar++] = keyboard->orderStr[i];
		}
		else if (keyboard->orderStr[i] >= '1' && keyboard->orderStr[i] <= '8')
		{
			if (posOrderChar != 1)
			{
				posOrderChar = 0;
				memset(TwoCharOrder, 0, sizeof(TwoCharOrder));
				continue;
			}
			else if (posOrderChar == 1)
			{
				TwoCharOrder[posOrderChar++] = keyboard->orderStr[i];
			}

			if (posOrderChar == 2)
			{
				if (isFirst)
				{
					sprintf(orderStrTemp, "%s%s", orderStrTemp, TwoCharOrder);
					isFirst = 0;
				}
				else
				{
					sprintf(orderStrTemp, "%s|%s", orderStrTemp, TwoCharOrder);
				}

				posOrderChar = 0;
				memset(TwoCharOrder, 0, sizeof(TwoCharOrder));
			}
		}
		// 一个字节命令处理
		else
		{
			switch (keyboard->orderStr[i])
			{
			case 'G':
				if (isFirst)
				{
					sprintf(orderStrTemp, "%s%c", orderStrTemp, keyboard->orderStr[i]);
					isFirst = 0;
				}
				else
				{
					sprintf(orderStrTemp, "%s|%c", orderStrTemp, keyboard->orderStr[i]);
				}
				break;
			case 'Q':
				if (isFirst)
				{
					sprintf(orderStrTemp, "%s%c", orderStrTemp, keyboard->orderStr[i]);
					isFirst = 0;
				}
				else
				{
					sprintf(orderStrTemp, "%s|%c", orderStrTemp, keyboard->orderStr[i]);
				}
				break;
			default:
				break;
			}
		}

	}

	if (isFirst != 1)
	{
		sprintf(keyboard->orderStr, "T=0,EVENT=%s", orderStrTemp);
		//strcpy(keyboard->orderStr, orderStrTemp);
	}
	else
	{
		return -1;
	}

	return 0;
}

/*
1.3 打印输出键盘接收的字符串
函数功能：输出键盘接受的字符串 keyboard->orderStr
函数参数：
函数返回值：
*/
int PrintOrderStrKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}
	if (keyboard->isHaveInput == false)
	{
		return -1;
	}
	printf("%s\n", keyboard->orderStr);
	return 0;
}

/*
1.4 发送键盘信息
函数功能：接收键盘输入处理函数，键盘输入命令处理
函数参数：
函数返回值：
*/
int isSendValueKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}

	keyboard->isHaveInput = false;
	return 0;
}

/*
1.X 功能测试函数
函数功能：接收键盘输入处理函数，键盘输入命令处理
函数参数：
函数返回值：
*/
void TestValueKeyBoard()
{
	KeyBoard * keyboard = (KeyBoard *)malloc(sizeof(KeyBoard));
	memset(keyboard, 0, sizeof(KeyBoard));

	// 初始化键盘输入
	InitialKeyBoard(keyboard);

	// 获取键盘输入
	while (1)
	{
		GetValueOfKeyBoard(keyboard);
		isSendValueKeyBoard(keyboard);
	}
	// 获取键盘输入

}

