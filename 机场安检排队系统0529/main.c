#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<time.h>

#include	"ControlAll.h"




int main(int argc, char * argv[])
{
	CaseOneControlAll();
	//TestConfig();
	do
	{
		//TestSeqQueueList();
		//TestValueKeyBoard();
		//TestValueFileInput();
		//TestGateList();
		//TestShowTime();
		//CaseOneControlAll();
	} while (getchar() != EOF);
	

	return 0;
}