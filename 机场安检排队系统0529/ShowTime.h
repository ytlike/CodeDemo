#pragma once
#ifndef SHOWTIME_H
#define SHOWTIME_H

#ifdef __cplusplus
extern "C" {
#endif


#include	<time.h>

	// ʱ����ʾ
	// 1 ϵͳ���ò����ṹ��
	typedef struct _ShowTime
	{
		time_t timeNow;

	}ShowTime;


	/*
	1.0 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialShowTime(ShowTime * systime);

	/*
	1.1 ��ʾʱ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintTime(ShowTime * systime);

	/*
	1.2 ��ʾʱ���ʽ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintTimeTwo(ShowTime * systime);

	/*
	1.3 ��ʾʱ���ʽ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintTimeThree(ShowTime * systime);

	/*
	1.X ���ܲ��Ժ���
	�������ܣ��������ļ����޸������ļ�
	����������
	��������ֵ��
	*/
	void TestShowTime();


#ifdef __cplusplus
}
#endif

#endif // SHOWTIME_H
