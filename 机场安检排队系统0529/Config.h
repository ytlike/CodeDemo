#pragma once
#ifndef CONFIG_H
#define CONFIG_H

#include	<stdio.h>
#include	<stdbool.h>
#define		BUFFCONFIG		1024
#define		STRCONFIGPAHT	"./config.txt"

// ϵͳ����
// 1 ϵͳ���ò����ṹ��
typedef struct _Config
{
	FILE			*pConfig;
	char			ConfigPath[BUFFCONFIG];
	bool			isOpen;

	int				MinSec;					// ���ҵ�����ʱ��
	int				MaxSec;					// �ҵ�����ʱ��
	int				MinRestSec;				// ��̴�����Ϣʱ��
	int				MaxRestSec;				// �������Ϣʱ��

											
	int				MaxCustSingleLine;		// ���������ȴ��˿���
	int				MaxLines;				// ���λ����������MaxLines��ֱ�����
	int				MaxSeqLen;				// �������ȴ�����
	int				MinTimeLen;				// һ�ΰ������ʱ�䣬��λ����
	int				MaxTimeLen;				// һ�ΰ����ʱ�䣬��λ����
}Config;

#ifdef __cplusplus
extern "C" {
#endif
	/*
	1.0 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialConfig(Config * config);

	/*
	1.1 �޸�������Ϣ
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int ChangeConfig(Config * config);

	/*
	1.2 ���������Ϣ
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintConfig(Config * config);

	/*
	1.X ���ܲ��Ժ���
	�������ܣ��������ļ����޸������ļ�
	����������
	��������ֵ��
	*/
	void TestConfig();


#ifdef __cplusplus
}
#endif

#endif // CONFIG_H
