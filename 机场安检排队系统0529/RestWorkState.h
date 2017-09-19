#ifndef RESTWORKSTATE_H
#define	RESTWORKSTATE_H

#include	<time.h>
#ifdef __cplusplus
extern "C" {
#endif
	// 安检口休息、下班控制模块

	// 1、基本休息请求信息链表结点
	typedef struct _RestWorkState
	{
		char	orderRequestStr[3];			// 每个窗口的请求命令
		time_t  startRequestTime;			// 请求的开始时间

		struct _RestWorkState * next;		// 指向链表下一结点
	}RestWorkStateNode;

	// 2、结点控制
	typedef struct _RestWorkStateList
	{
		int size;							// 请求命令个数

		RestWorkStateNode * pfront;			// 请求队列头指针
		RestWorkStateNode * ptail;			// 请求队列尾指针
	}RestWorkStateList;

	// 3、安检口休息、下班控制模块，链表相关操作
	/*
	3.1 初始化
	函数功能：
	函数参数：
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int InitialRestWorkStateList(RestWorkStateList * restRequestlist);

	/*
	3.2 进队列
	函数功能：
	函数参数： const char * restRequestStr 传入指令字符串
	函数返回值：成功返回 0，失败返回 -1；
	*/
	int IntoRestWorkStateList(RestWorkStateList * restRequestlist, const char * restRequestStr);

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


#ifdef __cplusplus
}
#endif
#endif // RESTWORKSTATE_H