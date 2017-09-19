#ifndef RESTWORKSTATE_H
#define	RESTWORKSTATE_H

#include	<time.h>
#ifdef __cplusplus
extern "C" {
#endif
	// �������Ϣ���°����ģ��

	// 1��������Ϣ������Ϣ������
	typedef struct _RestWorkState
	{
		char	orderRequestStr[3];			// ÿ�����ڵ���������
		time_t  startRequestTime;			// ����Ŀ�ʼʱ��

		struct _RestWorkState * next;		// ָ��������һ���
	}RestWorkStateNode;

	// 2��������
	typedef struct _RestWorkStateList
	{
		int size;							// �����������

		RestWorkStateNode * pfront;			// �������ͷָ��
		RestWorkStateNode * ptail;			// �������βָ��
	}RestWorkStateList;

	// 3���������Ϣ���°����ģ�飬������ز���
	/*
	3.1 ��ʼ��
	�������ܣ�
	����������
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int InitialRestWorkStateList(RestWorkStateList * restRequestlist);

	/*
	3.2 ������
	�������ܣ�
	���������� const char * restRequestStr ����ָ���ַ���
	��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
	*/
	int IntoRestWorkStateList(RestWorkStateList * restRequestlist, const char * restRequestStr);

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


#ifdef __cplusplus
}
#endif
#endif // RESTWORKSTATE_H