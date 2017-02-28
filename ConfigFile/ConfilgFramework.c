#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config.h"

//#define FileName "F:/test/myConfig.ini";

void displayUI()
{
	printf("----------------------\n");
	printf("一个微小的程序\n");
	printf("请输入功能编号：\n");
	printf("1:写配置文件\n");
	printf("2:读配置文件\n");
	printf("0:关闭程序\n");
}

///<summary>
///读取value
///</summary>
void readFile()
{
	int length = 0;
	char *readValue = NULL;
	char writeKey[1024] = { 0 };
	char *FileName = "F:/test/myConfig.ini";
	printf("请输入key:");
	scanf("%s", writeKey);
    int ret = getConfigFile(FileName, writeKey, &readValue, &length);
	if (ret != 0)
	{
		printf("The func getConfigFile() err:%d\n", ret);
	}
	else
	{
		printf("%s", readValue);
		printf("\n读取配置文件成功！");
	}
	printf("\n------------------\n");
	printf("请输入功能编号:");
}

void writeFile()
{
	int length = 0;
	char *fileName = "F:/test/myConfig.ini";
	char Key[1024] = { 0 };
	char value[1024] = { 0 };
	printf("请输入key:");
	scanf("%s", Key);
	printf("\n请输入value:");
	scanf("%s", value);
    int ret = writeConfigFile(fileName, Key, value, &length);
	if (ret != 0)
	{
		printf("The func writeFile() err:%d\n", ret);
	}
	else
	{
		printf("\n写入配置文件成功");
	}
	printf("\n------------------\n");
	printf("请输入功能编号:");
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