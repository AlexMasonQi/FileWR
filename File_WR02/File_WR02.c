#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Teacher
{
	char Name[64];
	int Age;
}Teacher;

int getFile(char *filename, FILE *fp, Teacher *p, int num)
{
	int ret = 0;
	int i = 0;
	if (filename == NULL)
	{
		ret = -1;
	}
	char *fName = filename;
	//char *str = source;
	FILE *pFile = fp;
	pFile = fopen(fName, "rb+");
	if (pFile == NULL)
	{
		printf("Open file failed!");
		return -1;
	}
	for (i = 0; i < num; i++)
	{
		fread(&p[i], sizeof(Teacher), 1, pFile);
	}
	if (pFile != NULL)
	{
		fclose(pFile);
	}
	return ret;
}

int main()
{
	Teacher Array[3];
	int i = 0;
	int num = 3;
	FILE *fp = NULL;
	char *fileName = "F:/test/test04.dll";
	int ret = getFile(fileName, fp, Array, num);
	if (ret == -1)
	{
		printf("The func putFile() err:%d\n", ret);
	}
	for (i = 0; i < num; i++)
	{
		printf("Array[i].Name:%s ,Array[i].Age:%d\n", Array[i].Name, Array[i].Age);
	}
	//printf("Open file successfully!\n");

	system("pause");
	return 0;
}