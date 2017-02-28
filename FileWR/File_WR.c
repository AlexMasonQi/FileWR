#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int putFile(char *filename, char *source, FILE *fp)
{
	int ret = 0;
	if (filename == NULL || source == NULL)
	{
		ret = -1;
	}
	char *fName = filename;
	char *str = source;
	FILE *pFile = fp;
	pFile = fopen(fName, "w+");
	if (pFile == NULL)
	{
		printf("File open failed!");
		return -1;
	}
	fputs(str, pFile);
	printf("Open file successfully!\n");
	fclose(pFile);
	return ret;
}


int getFile(char *filename, char *buf, FILE *fp)
{
	int ret = 0;
	if (filename == NULL || buf == NULL)
	{
		ret = -1;
	}
	char *fName = filename;
	FILE *pFile = fp;
	pFile = fopen(fName, "r+");
	if (pFile == NULL)
	{
		printf("Open file failed!");
		return -1;
	}
	while (!feof(pFile))
	{
		fgets(buf, 1024, pFile);
		printf("%s", buf);
	}
	if (pFile != NULL)
	{
		fclose(pFile);
	}
	return ret;
}

int main()
{
	//char *buf = "Microsoft Windows 10";
	char *fileStr = "F:/test/test03.txt";
	char buf[1024] = { 0 };
	FILE *fp = NULL;
	int ret = 0;
	ret = getFile(fileStr, buf, fp);
	if (ret == -1)
	{
		printf("The func getFile() err:%d\n", ret);
	}
	printf("\n");

	system("pause");
	return ret;
}