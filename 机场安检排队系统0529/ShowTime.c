#define _CRT_SECUSE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

// #pragma warning(default, 4996)


#include	"ShowTime.h"

/*
1.0 ��ʼ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
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
1.1 ��ʾʱ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
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
1.2 ��ʾʱ���ʽ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
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
1.3 ��ʾʱ���ʽ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
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
		strcpy(week, "��");
		break;
	case 1:
		strcpy(week, "һ");
		break;
	case 2:
		strcpy(week, "��");
		break;
	case 3:
		strcpy(week, "��");
		break;
	case 4:
		strcpy(week, "��");
		break;
	case 5:
		strcpy(week, "��");
		break;
	case 6:
		strcpy(week, "��");
		break;
	default:
		break;
	}

	printf("%d��%d��%d�� ����%s %02d:%02d:%02d\n",
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
1.X ���ܲ��Ժ���
�������ܣ��������ļ����޸������ļ�
����������
��������ֵ��
*/
void TestShowTime()
{
	ShowTime * systime = (ShowTime *)malloc(sizeof(ShowTime));
	memset(systime, 0, sizeof(ShowTime));

	InitialShowTime(systime);
	PrintTimeThree(systime);
}
