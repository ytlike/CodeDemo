#pragma once
#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H

#ifdef __cplusplus
extern "C" {
#endif
	// �������봦��ģ��
#include <stdbool.h>
#define BUFFKEYBOARD 1024
	typedef struct _KeyBoard
	{
		bool isHaveInput;
		char orderStr[BUFFKEYBOARD + 1];
	}KeyBoard;


	/*
	1.0 ��ʼ����������
	�������ܣ����ռ������봦�������������������
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialKeyBoard(KeyBoard * keyboard);

	/*
	1.1 ��ȡ��������
	�������ܣ����ռ������봦�������������������
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int GetValueOfKeyBoard(KeyBoard * keyboard);

	/*
	1.2 �Լ��������ַ�������
	�������ܣ��ַ���������
	����������key ������ַ�
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int DisposeInfoKeyBoard(KeyBoard * keyboard);

	/*
	1.3 ��ӡ����ַ���
	�������ܣ�����ַ��� keyboard->orderStr
	����������
	��������ֵ��
	*/
	int PrintOrderStrKeyBoard(KeyBoard * keyboard);

	/*
	1.4 ���ͼ�����Ϣ
	�������ܣ����ռ������봦�������������������
	����������
	��������ֵ��
	*/
	int isSendValueKeyBoard(KeyBoard * keyboard);

	/*
	1.X ���ܲ��Ժ���
	�������ܣ����ռ������봦�������������������
	����������
	��������ֵ��
	*/
	void TestValueKeyBoard();

#ifdef __cplusplus
}
#endif

#endif // KEYBOARDINPUT_H
