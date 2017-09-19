#pragma once
#ifndef FILEINPUT_H
#define FILEINPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdbool.h>

#define FileInputTxtPath "./input.txt"
#define BUFFFILEINPUT	1024
#define MAXPATH			1024

	// �����ļ��ṹ��
	typedef struct _FileInput
	{
		FILE * fp;
		char inputPath[MAXPATH];
		bool isOpen;
		bool isHaveOrderInfo;
		char orderStr[BUFFFILEINPUT + 1];
	}FileInput;




	// �ļ��������
	/*
	1.0 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialFileInput(FileInput * fileinput);

	/*
	1.1 �ļ������ȡ
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int GetValueFileInput(FileInput * fileinput);

	/*
	1.2 �ļ������ַ�������
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int DisposeInfoFileInput(FileInput * fileinput);

	/*
	1.3 ��ӡ����ַ���
	�������ܣ�����ַ��� fileinput->orderStr
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int PrintOrderStrFileInput(FileInput * fileinput);

	/*
	1.4 �����ļ�������Ϣ
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int isSendValueFileInput(FileInput * fileinput);

	/*
	1.X ���ܲ��Ժ���
	�������ܣ�
	����������
	��������ֵ��
	*/
	void TestValueFileInput();

#ifdef __cplusplus
}
#endif

#endif // FILEINPUT_H
