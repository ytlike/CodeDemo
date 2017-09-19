#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"RestWorkState.h"


// 3���������Ϣ���°����ģ�飬������ز���
/*
3.1 ��ʼ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
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
3.2 ������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
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
3.3 ������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int OutRestWorkStateList(RestWorkStateList * restRequestlist);

/*
3.3 ��ȡ���ж���Ԫ����Ϣ
�������ܣ�
����������const char * restRequestStr ͨ����������ָ��
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int GetValueRestWorkStateList(RestWorkStateList * restRequestlist, const char * restRequestStr);

/*
3.4 ���ٰ�����Ϣģ������
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int DestroyWorkStateList(RestWorkStateList * restRequestlist);

/*
3.X ���Ժ���
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int TestWorkStateList();