#define _CRT_SECUSE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

// #pragma warning(default, 4996)


#include	"ShowTime.h"

/*
1.0 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialShowTime(ShowTime * systime)
{
	// for error
	if (NULL == systime)
	{
		return -1;
	}

	systime->timeNow = time((time_t *)NULL);

	return -1;
}

/*
1.1 显示时间
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int PrintTime(ShowTime * systime)
{
	if (NULL == systime)
	{
		return -1;
	}

	systime->timeNow = time((time_t *)NULL);
	printf("%s", ctime(&systime->timeNow));

	return 0;
}

/*
1.2 显示时间格式二
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int PrintTimeTwo(ShowTime * systime)
{
	if (NULL == systime)
	{
		return -1;
	}

	systime->timeNow = time((time_t *)NULL);
	struct tm * tblock = localtime(&systime->timeNow);

	printf("%s", asctime(tblock));

	return 0;
}

/*
1.3 显示时间格式三
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int PrintTimeThree(ShowTime * systime)
{
	if (NULL == systime)
	{
		return -1;
	}

	systime->timeNow = time((time_t *)NULL);
	struct tm * tblock = localtime(&systime->timeNow);

	char week[3];
	switch (tblock->tm_wday)
	{
	case 0:
		strcpy(week, "日");
		break;
	case 1:
		strcpy(week, "一");
		break;
	case 2:
		strcpy(week, "二");
		break;
	case 3:
		strcpy(week, "三");
		break;
	case 4:
		strcpy(week, "四");
		break;
	case 5:
		strcpy(week, "五");
		break;
	case 6:
		strcpy(week, "六");
		break;
	default:
		break;
	}

	printf("%d年%d月%d号 星期%s %02d:%02d:%02d\n",
			tblock->tm_year + 1900,
			tblock->tm_mon + 1,
			tblock->tm_mday,
			week,
			tblock->tm_hour,
			tblock->tm_min,
		tblock->tm_sec);

	return 0;
}

/*
1.X 功能测试函数
函数功能：打开配置文件，修改配置文件
函数参数：
函数返回值：
*/
void TestShowTime()
{
	ShowTime * systime = (ShowTime *)malloc(sizeof(ShowTime));
	memset(systime, 0, sizeof(ShowTime));

	InitialShowTime(systime);
	PrintTimeThree(systime);
}
