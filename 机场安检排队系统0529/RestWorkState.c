#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RestWorkState.h"


// 3、安检口休息、下班控制模块，链表相关操作
/*
3.1 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialRestWorkStateList(RestWorkStateList * restRequestlist)
{
	// for error
	if (NULL == restRequestlist)
	{
		return -1;
	}

	restRequestlist->size = 0;
	restRequestlist->pfront = NULL;
	restRequestlist->ptail = NULL;

	return 0;
}

/*
3.2 进队列
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int IntoRestWorkStateList(RestWorkStateList * restRequestlist)
{
	// for error
	if (NULL == restRequestlist)
	{
		return -1;
	}




	return 0;
}

/*
3.3 出队列
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int OutRestWorkStateList(RestWorkStateList * restRequestlist);

/*
3.3 获取队列队首元素信息
函数功能：
函数参数：const char * restRequestStr 通过参数返回指令
函数返回值：成功返回 0，失败返回 -1；
*/
int GetValueRestWorkStateList(RestWorkStateList * restRequestlist, const char * restRequestStr);

/*
3.4 销毁安监休息模块链表
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int DestroyWorkStateList(RestWorkStateList * restRequestlist);

/*
3.X 测试函数
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int TestWorkStateList();