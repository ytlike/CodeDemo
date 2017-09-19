#define _CRT_SECURE_NO_WARNINGS
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"config.h"


/*
1.0 初始化
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int InitialConfig(Config * config)
{
	// for error
	if (NULL == config)
	{
		return -1;
	}

	strcpy(config->ConfigPath, STRCONFIGPAHT);
	config->pConfig = fopen(config->ConfigPath, "r");

	if (!config->pConfig)
	{
		printf("打开配置文件失败！\n");
		config->isOpen = false;
		return -1;
	}

	config->isOpen = true;

	char buff[128];
	memset(buff, 0, sizeof(buff));

	char info[128];
	memset(info, 0, sizeof(info));

	int tempValue;

	while ((fgets(buff, BUFFCONFIG, config->pConfig)) != NULL)
	{
		char *phead = NULL;
		char *ptail = NULL;

		phead = strstr(buff, "[");
		ptail = strstr(buff, "]");

		phead++;
		int len = ptail - phead;

		strncpy(info, phead, len);

		sscanf(ptail + 1, "%d", &tempValue);

		if (strcmp(info, "MinSec") == 0)
		{
			config->MinSec = tempValue;
		}
		else if (strcmp(info, "MaxSec") == 0)
		{
			config->MaxSec = tempValue;
		}
		else if (strcmp(info, "MinRestSec") == 0)
		{
			config->MinRestSec = tempValue;
		}
		else if (strcmp(info, "MaxRestSec") == 0)
		{
			config->MaxRestSec = tempValue;
		}
		else if (strcmp(info, "MaxCustSingleLine") == 0)
		{
			config->MaxCustSingleLine = tempValue;
		}
		else if (strcmp(info, "MaxLines") == 0)
		{
			config->MaxLines = tempValue;
		}
		else if (strcmp(info, "MaxSeqLen") == 0)
		{
			config->MaxSeqLen = tempValue;
		}
		else if (strcmp(info, "MinTimeLen") == 0)
		{
			config->MinTimeLen = tempValue;
		}
		else if (strcmp(info, "MaxTimeLen") == 0)
		{
			config->MaxTimeLen = tempValue;
		}

		memset(buff, 0, sizeof(buff));
		memset(info, 0, sizeof(info));
	}

	fclose(config->pConfig);
	config->isOpen = false;

	return 0;
}

/*
1.1 修改配置信息
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int ChangeConfig(Config * config)
{
	// for error
	if (NULL == config)
	{
		return -1;
	}

	char ConfigTxtPath[] = { "./config2.txt" };

	FILE * fp2 = fopen(ConfigTxtPath, "w");
	config->pConfig = fopen(config->ConfigPath, "r");

	if (!fp2)
	{
		printf("修改文件时，打开config2文件失败！");
		return -1;
	}
	if (!config->pConfig)
	{
		printf("修改文件时，打开config文件失败！");
		return -1;
	}


	char buff[128];
	memset(buff, 0, sizeof(buff));

	char info[128];
	memset(info, 0, sizeof(info));

	int tempValue;

	while ((fgets(buff, BUFFCONFIG, config->pConfig)) != NULL)
	{
		char * ptail = NULL;

		ptail = strstr(buff, "]");

		int len = ptail - buff + 1;
		strncpy(info, buff, len);

		sscanf(ptail + 1, "%d", &tempValue);

		printf("\n请输入正整数%s=", info);
		scanf("%d", &tempValue);
		fflush(NULL);

		sprintf(buff, "%s%d\n", info, tempValue);

		len = strlen(buff);
		fwrite(buff, len, 1, fp2);

		//int isSuccess = fputs(buff, fp2);
		//printf("%d\n", isSuccess);

		memset(buff, 0, sizeof(buff));
		memset(info, 0, sizeof(info));
	}

	fclose(config->pConfig);
	fclose(fp2);

	fp2 = fopen(ConfigTxtPath, "r");
	config->pConfig = fopen(config->ConfigPath, "w");

	if (!fp2)
	{
		printf("修改文件时，打开config2文件失败！");
		return -1;
	}
	if (!config->pConfig)
	{
		printf("修改文件时，打开config文件失败！");
		return -1;
	}

	while (!feof(fp2))
	{
		memset(buff, 0, sizeof(buff));
		int len = fread(buff, 1, sizeof(buff)-1, fp2);
		fwrite(buff, len, 1, config->pConfig);
	}

	fclose(config->pConfig);
	fclose(fp2);

	InitialConfig(config);
	printf("修改成功！\n");
	return 0;
}

/*
1.2 输出配置信息
函数功能：
函数参数：
函数返回值：成功返回 0，失败返回 -1；
*/
int PrintConfig(Config * config)
{
	// for error
	if (NULL == config)
	{
		return -1;
	}

	printf("[MinSec]%d\n", config->MinSec);
	printf("[MaxSec]%d\n", config->MaxSec);
	printf("[MinRestSec]%d\n", config->MinRestSec);
	printf("[MaxRestSec]%d\n", config->MaxRestSec);
	printf("[MaxCustSingleLine]%d\n", config->MaxCustSingleLine);
	printf("[MaxLines]%d\n", config->MaxLines);
	printf("[MaxSeqLen]%d\n", config->MaxSeqLen);
	printf("[MinTimeLen]%d\n", config->MinTimeLen);
	printf("[MaxTimeLen]%d\n", config->MaxTimeLen);

	return 0;
}

/*
1.X 功能测试函数
函数功能：打开配置文件，修改配置文件
函数参数：
函数返回值：
*/
void TestConfig()
{
	Config * config = (Config *)malloc(sizeof(Config));
	memset(config, 0, sizeof(Config));

	// 
	InitialConfig(config);
	PrintConfig(config);

	ChangeConfig(config);
	PrintConfig(config);

}
