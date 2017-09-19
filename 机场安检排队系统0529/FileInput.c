#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"FileInput.h"

// �ļ��������
/*
1.0 ��ʼ��
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int InitialFileInput(FileInput * fileinput)
{
	// for error
	if (NULL == fileinput)
	{
		return -1;
	}
	strcpy(fileinput->inputPath, FileInputTxtPath);
	fileinput->fp = fopen(fileinput->inputPath, "r");
	if (!fileinput->fp)
	{
		fileinput->isOpen = false;
		printf("���ļ�ʧ��\n");
		return -1;
	}
	fileinput->isOpen = true;
	memset(fileinput->orderStr, 0, sizeof(fileinput->orderStr));
	fileinput->isHaveOrderInfo = false;


	return 0;
}

/*
1.1 �ļ������ȡ
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int GetValueFileInput(FileInput * fileinput)
{
	// for error
	if (NULL == fileinput)
	{
		return -1;
	}

	if (fileinput->isOpen == false)
	{
		return -1;
	}
	// �����ļ���β
	if (feof(fileinput->fp))
	{
		fclose(fileinput->fp);
		fileinput->isOpen = false;
		return -1;
	}

	// ��ȡһ���ļ���Ϣ
	if (fgets(fileinput->orderStr, BUFFFILEINPUT, fileinput->fp) != NULL)
	{
		//PrintOrderStrFileInput(fileinput);
	}
	else
	{
		fclose(fileinput->fp);
		fileinput->isOpen = false;
		return -1;
	}

	DisposeInfoFileInput(fileinput);
	// �������
	PrintOrderStrFileInput(fileinput);

	return 0;
}

/*
1.2 �ļ������ַ�������
�������ܣ��������ַ�������
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int DisposeInfoFileInput(FileInput * fileinput)
{
	// for error
	if (NULL == fileinput)
	{
		return -1;
	}
	if (fileinput->isOpen == false)
	{
		return -1;
	}

	// ȥ��ĩβ '\n'
	int len = strlen(fileinput->orderStr);
	if (fileinput->orderStr[len - 1] == '\n')
	{
		fileinput->orderStr[len - 1] = '\0';
	}

	// ���Ķ��Ŵ��� '��'
	char * pChineseChar = strstr(fileinput->orderStr, "��");
	if (pChineseChar != NULL)
	{
		*pChineseChar = ',';
		*pChineseChar++;
		*pChineseChar = ' ';
	}
	//PrintOrderStrFileInput(fileinput);
	
	// ȥ���ո�
	for (int i = 0; fileinput->orderStr[i] != '\0'; ++i)
	{
		if (fileinput->orderStr[i] == ' ')
		{
			for (int j = i; fileinput->orderStr[j] != '\0'; ++j )
			{
				fileinput->orderStr[j] = fileinput->orderStr[j + 1];
			}
			i--;
		}
	}

	return 0;
}

/*
1.3 ��ӡ����ַ���
�������ܣ�����ַ��� fileinput->orderStr
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int PrintOrderStrFileInput(FileInput * fileinput)
{
	if (NULL == fileinput)
	{
		return -1;
	}

	printf("%s\n", fileinput->orderStr);

	return 0;
}

/*
1.4 �����ļ�������Ϣ
�������ܣ�
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int isSendValueFileInput(FileInput * fileinput)
{
	if (NULL == fileinput)
	{
		return -1;
	}



	return 0;
}

/*
1.X ���ܲ��Ժ���
�������ܣ�
����������
��������ֵ��
*/
void TestValueFileInput()
{
	FileInput * fileinput = (FileInput *)malloc(sizeof(FileInput));
	memset(fileinput, 0, sizeof(FileInput));

	// ��ʼ��
	InitialFileInput(fileinput);

	// 
	while (fileinput->isOpen == true)
	{
		GetValueFileInput(fileinput);
	}
}

