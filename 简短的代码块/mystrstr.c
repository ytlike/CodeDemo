/*************************************************************************
    > File Name: mystrstr.c
    > Author: yutao
    > Mail: 1052249521@qq.com 
    > Created Time: Tue 12 Sep 2017 02:01:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

/*
 成功 > 0
 失败 = 0
 */
int mystrstr(char* str, char* substr)
{
	int strnum = 0;
	int subnum = 0;
	//暴力破解
	while(str[strnum])
	{
		if(str[strnum] == substr[subnum])
		{
			++strnum;
			++subnum;
			if(substr[subnum] == '\0')
				return strnum - subnum + 1;
		}
		else
		{
			strnum = strnum - subnum + 1;
			subnum = 0;
		}
	}

	return 0;
}


int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("./a.out src subsrc\n");
		return 0;
	}

	int pos = mystrstr(argv[1], argv[2]);
	if(pos > 0)
	{
		printf("匹配成功，在第%d位置\n", pos);
	}
	else
	{
		printf("匹配失败\n");
	}
	return 0;
}

