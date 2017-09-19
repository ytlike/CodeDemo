#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"FileInput.h"

// 文件输入操作
/*
1.0 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialFileInput(FileInput * fileinput)
{
	// for error
	if (NULL == fileinput)
	{
		return -1;
	}
	strcpy(fileinput->inputPath, FileInputTxtPath);
	fileinput->fp = fopen(fileinput->inputPath, "r");
	if (!fileinput->fp)
	{
		fileinput->isOpen = false;
		printf("打开文件失败\n");
		return -1;
	}
	fileinput->isOpen = true;
	memset(fileinput->orderStr, 0, sizeof(fileinput->orderStr));
	fileinput->isHaveOrderInfo = false;


	return 0;
}

/*
1.1 文件命令读取
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int GetValueFileInput(FileInput * fileinput)
{
	// for error
	if (NULL == fileinput)
	{
		return -1;
	}

	if (fileinput->isOpen == false)
	{
		return -1;
	}
	// 读到文件结尾
	if (feof(fileinput->fp))
	{
		fclose(fileinput->fp);
		fileinput->isOpen = false;
		return -1;
	}

	// 读取一行文件信息
	if (fgets(fileinput->orderStr, BUFFFILEINPUT, fileinput->fp) != NULL)
	{
		//PrintOrderStrFileInput(fileinput);
	}
	else
	{
		fclose(fileinput->fp);
		fileinput->isOpen = false;
		return -1;
	}

	DisposeInfoFileInput(fileinput);
	// 输出测试
	PrintOrderStrFileInput(fileinput);

	return 0;
}

/*
1.2 文件命令字符串处理
函数功能：命令行字符串处理
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int DisposeInfoFileInput(FileInput * fileinput)
{
	// for error
	if (NULL == fileinput)
	{
		return -1;
	}
	if (fileinput->isOpen == false)
	{
		return -1;
	}

	// 去除末尾 '\n'
	int len = strlen(fileinput->orderStr);
	if (fileinput->orderStr[len - 1] == '\n')
	{
		fileinput->orderStr[len - 1] = '\0';
	}

	// 中文逗号处理 '，'
	char * pChineseChar = strstr(fileinput->orderStr, "，");
	if (pChineseChar != NULL)
	{
		*pChineseChar = ',';
		*pChineseChar++;
		*pChineseChar = ' ';
	}
	//PrintOrderStrFileInput(fileinput);
	
	// 去除空格
	for (int i = 0; fileinput->orderStr[i] != '\0'; ++i)
	{
		if (fileinput->orderStr[i] == ' ')
		{
			for (int j = i; fileinput->orderStr[j] != '\0'; ++j )
			{
				fileinput->orderStr[j] = fileinput->orderStr[j + 1];
			}
			i--;
		}
	}

	return 0;
}

/*
1.3 打印输出字符串
函数功能：输出字符串 fileinput->orderStr
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int PrintOrderStrFileInput(FileInput * fileinput)
{
	if (NULL == fileinput)
	{
		return -1;
	}

	printf("%s\n", fileinput->orderStr);

	return 0;
}

/*
1.4 发送文件输入信息
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int isSendValueFileInput(FileInput * fileinput)
{
	if (NULL == fileinput)
	{
		return -1;
	}



	return 0;
}

/*
1.X 功能测试函数
函数功能：
函数参数：
函数返回值：
*/
void TestValueFileInput()
{
	FileInput * fileinput = (FileInput *)malloc(sizeof(FileInput));
	memset(fileinput, 0, sizeof(FileInput));

	// 初始化
	InitialFileInput(fileinput);

	// 
	while (fileinput->isOpen == true)
	{
		GetValueFileInput(fileinput);
	}
}

