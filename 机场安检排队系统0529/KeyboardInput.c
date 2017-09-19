#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<conio.h>
#include	<Windows.h>
#include	"KeyboardInput.h"

/*
1.0 ��ʼ����������
�������ܣ����ռ������봦�������������������
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int InitialKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}

	keyboard->isHaveInput = false;
	memset(keyboard->orderStr, 0, sizeof(keyboard->orderStr));

	return 0;
}

/*
1.1 ��ȡ��������
�������ܣ����ռ������봦�������������������
����������
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int GetValueOfKeyBoard(KeyBoard * keyboard)
{
	// �ȴ���������
	// kbhit()
	// ���ܣ���鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
	// vc 6.0++ ��Ϊ _kbhit()
	// ͷ�ļ���conio.h

	while (_kbhit())
	{
		//���Ի�ȡ�ַ�
		// getcha() �����Ի�ȡ�����ַ�
		// ͷ�ļ���conio.h
		char * flagOrderStr = fgets(keyboard->orderStr, BUFFKEYBOARD, stdin);
		keyboard->isHaveInput = true;
		if (flagOrderStr != NULL)
		{
			//Sleep(1000);
			break;
		}
	}

	//// �������
	//if (keyboard->isHaveInput == true)
	//{
	//	// here1 is test print keyboard->orderStr
	//	printf("\n�ַ�������ǰ:\n");
	//	PrintOrderStrKeyBoard(keyboard);
	//}

	// ���������ַ�����
	int isOrderStr = DisposeInfoKeyBoard(keyboard);

	if (-1 == isOrderStr)
	{
		keyboard->isHaveInput = false;
		memset(keyboard->orderStr, 0, sizeof(keyboard->orderStr));
		return -1;
	}
	else
	{
		//// here2 is test print keyboard->orderStr
		//printf("�ַ��������:\n");
		//PrintOrderStrKeyBoard(keyboard);
		return 0;
	}
}

/*
1.2 �Լ������봦�����������
�������ܣ��ַ���������
����������key ������ַ�
��������ֵ���ɹ����� 0��ʧ�ܷ��� -1��
*/
int DisposeInfoKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}
	if (keyboard->isHaveInput == false)
	{
		return -1;
	}
	// ���� ������ �ַ��� ���Ե�����ָ��

	// ������ʽ T=<������ʱ��>,EVENT=<�¼�|�¼�><\n>
	/* ����
		T = 8�� EVENT = G | G | G |
		T = 10��EVENT = G | G |
		T = 15��EVENT = R1
		T = 50��EVENT = G | G | G | G | G | R3
		T = 60��EVENT = C1
		T = 80��EVENT = G | G | G |
		T = 150��EVENT = Q
	*/

	// T = 0�� EVENT = G | G | G | 

	// �ַ���ĩβ'\n'����
	int len = strlen(keyboard->orderStr);
	if (keyboard->orderStr[len-1] == '\n')
	{
		keyboard->orderStr[len-1] = '\0';
	}

	// ʱ��
	int timeT = 0;
	// ��ʱ�洢�������ַ���
	char orderStrTemp[BUFFKEYBOARD + 128];
	memset(orderStrTemp, 0, sizeof(orderStrTemp));

	// �ַ����ϳ� 1
	// T = 0�� EVENT = G | G | G |
	// �������
	//sprintf(orderStrTemp, "T=%d,EVENT=", timeT);

	// �ַ����ϳ� 2
	// �м�洢 �����ֽ� �������
	char TwoCharOrder[3] = { 0 };
	int posOrderChar = 0;
	int isFirst = 1;
	for (int i = 0; keyboard->orderStr[i] != '\0'; i++)
	{
		// �����ֽ������
		if (keyboard->orderStr[i] == 'R' || keyboard->orderStr[i] == 'C')
		{
			if (posOrderChar >= 1)
			{
				posOrderChar = 0;
				memset(TwoCharOrder, 0, sizeof(TwoCharOrder));
				continue;
			}
			TwoCharOrder[posOrderChar++] = keyboard->orderStr[i];
		}
		else if (keyboard->orderStr[i] >= '1' && keyboard->orderStr[i] <= '8')
		{
			if (posOrderChar != 1)
			{
				posOrderChar = 0;
				memset(TwoCharOrder, 0, sizeof(TwoCharOrder));
				continue;
			}
			else if (posOrderChar == 1)
			{
				TwoCharOrder[posOrderChar++] = keyboard->orderStr[i];
			}

			if (posOrderChar == 2)
			{
				if (isFirst)
				{
					sprintf(orderStrTemp, "%s%s", orderStrTemp, TwoCharOrder);
					isFirst = 0;
				}
				else
				{
					sprintf(orderStrTemp, "%s|%s", orderStrTemp, TwoCharOrder);
				}

				posOrderChar = 0;
				memset(TwoCharOrder, 0, sizeof(TwoCharOrder));
			}
		}
		// һ���ֽ������
		else
		{
			switch (keyboard->orderStr[i])
			{
			case 'G':
				if (isFirst)
				{
					sprintf(orderStrTemp, "%s%c", orderStrTemp, keyboard->orderStr[i]);
					isFirst = 0;
				}
				else
				{
					sprintf(orderStrTemp, "%s|%c", orderStrTemp, keyboard->orderStr[i]);
				}
				break;
			case 'Q':
				if (isFirst)
				{
					sprintf(orderStrTemp, "%s%c", orderStrTemp, keyboard->orderStr[i]);
					isFirst = 0;
				}
				else
				{
					sprintf(orderStrTemp, "%s|%c", orderStrTemp, keyboard->orderStr[i]);
				}
				break;
			default:
				break;
			}
		}

	}

	if (isFirst != 1)
	{
		sprintf(keyboard->orderStr, "T=0,EVENT=%s", orderStrTemp);
		//strcpy(keyboard->orderStr, orderStrTemp);
	}
	else
	{
		return -1;
	}

	return 0;
}

/*
1.3 ��ӡ������̽��յ��ַ���
�������ܣ�������̽��ܵ��ַ��� keyboard->orderStr
����������
��������ֵ��
*/
int PrintOrderStrKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}
	if (keyboard->isHaveInput == false)
	{
		return -1;
	}
	printf("%s\n", keyboard->orderStr);
	return 0;
}

/*
1.4 ���ͼ�����Ϣ
�������ܣ����ռ������봦�������������������
����������
��������ֵ��
*/
int isSendValueKeyBoard(KeyBoard * keyboard)
{
	// for error
	if (NULL == keyboard)
	{
		return -1;
	}

	keyboard->isHaveInput = false;
	return 0;
}

/*
1.X ���ܲ��Ժ���
�������ܣ����ռ������봦�������������������
����������
��������ֵ��
*/
void TestValueKeyBoard()
{
	KeyBoard * keyboard = (KeyBoard *)malloc(sizeof(KeyBoard));
	memset(keyboard, 0, sizeof(KeyBoard));

	// ��ʼ����������
	InitialKeyBoard(keyboard);

	// ��ȡ��������
	while (1)
	{
		GetValueOfKeyBoard(keyboard);
		isSendValueKeyBoard(keyboard);
	}
	// ��ȡ��������

}

