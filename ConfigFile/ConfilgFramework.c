#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

//#define FileName "F:/test/myConfig.ini";

void displayUI()
{
	printf("----------------------\n");
	printf("һ��΢С�ĳ���\n");
	printf("�����빦�ܱ�ţ�\n");
	printf("1:д�����ļ�\n");
	printf("2:�������ļ�\n");
	printf("0:�رճ���\n");
}

///<summary>
///��ȡvalue
///</summary>
void readFile()
{
	int length = 0;
	char *readValue = NULL;
	char writeKey[1024] = { 0 };
	char *FileName = "F:/test/myConfig.ini";
	printf("������key:");
	scanf("%s", writeKey);
    int ret = getConfigFile(FileName, writeKey, &readValue, &length);
	if (ret != 0)
	{
		printf("The func getConfigFile() err:%d\n", ret);
	}
	else
	{
		printf("%s", readValue);
		printf("\n��ȡ�����ļ��ɹ���");
	}
	printf("\n------------------\n");
	printf("�����빦�ܱ��:");
}

void writeFile()
{
	int length = 0;
	char *fileName = "F:/test/myConfig.ini";
	char Key[1024] = { 0 };
	char value[1024] = { 0 };
	printf("������key:");
	scanf("%s", Key);
	printf("\n������value:");
	scanf("%s", value);
    int ret = writeConfigFile(fileName, Key, value, &length);
	if (ret != 0)
	{
		printf("The func writeFile() err:%d\n", ret);
	}
	else
	{
		printf("\nд�������ļ��ɹ�");
	}
	printf("\n------------------\n");
	printf("�����빦�ܱ��:");
}

int main()
{
	int choice = 0;
	displayUI();

	while (1)
	{
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: writeFile();
			break;
		case 2: readFile();
			break;
		case 0: exit(0);
			break;
		}
	}
	
	system("pause");
	return 0;
}