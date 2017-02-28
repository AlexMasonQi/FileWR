#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Maxline 2048

///<summary>
///ȥ���ո�(��֧���м�Ŀո�ȥ��)
///</summary>
int trimSpace(char *inbuf, char *outbuf)
{
	int ret = 0;
	char *inTemp = inbuf;
	char *outTemp = outbuf;
	int j = strlen(inTemp) - 1;
	/*char *temp = &(inTemp[j]);*/
	if (inbuf == NULL)
	{
		ret = -1;
	}
	int i = 0;

	while (isspace(inTemp[i]))
	{
		i++;
	}
	while (isspace(inTemp[j]))
	{
		j--;
	}
	int len = j - i + 1;
	inTemp = &inTemp[i];
	strncpy(outTemp, inTemp, len);
}

///<summary>
///�������ļ�
///</summary>
int getConfigFile(char *pfilename/*in*/, char *pkey/*in*/, char **pvalue/*out*/, int *valuelen/*out*/)
{
	int ret = 0;
	char fileBuf[1024];
	char *temp = NULL;
	char value[128] = { 0 };
	memset(fileBuf, 0, 1024);
	if (pfilename == NULL || pkey == NULL)
	{
		ret = -1;
	}
	char *fileName = pfilename;
	char *Key = pkey;
	FILE *fp = NULL;
	fp = fopen(fileName, "r+");
	if (fp == NULL)
	{
		printf("Open file failed!");
		//goto END;
	}
	while (!feof(fp))
	{
		fgets(fileBuf, sizeof(fileBuf), fp);
		temp = strstr(fileBuf, Key);
		if (temp == NULL)
		{
			continue;
		}
		temp += strlen(Key);
		temp = strchr(temp, '=');
		if (temp == NULL)
		{
			continue;
		}
		temp++;
		trimSpace(temp, value);
		strcat(Key, " = ");
		strcat(Key, value);
		*pvalue = Key;
		*valuelen = strlen(value);
	}
	if (fp != NULL)
	{
		fclose(fp);
	}
//END:
//	{
//		fclose(fp);
//		return -1;
//	}
	return ret;
}

///<summary>
///д�����ļ�
///</summary>
int writeConfigFile(char *pfilename/*in*/, char *pkey/*in*/, char *pvalue/*in*/, int *valuelen/*out*/)
{
	int ret = 0;
	int flag = 0;
	int fileLen = 0;
	char fileBuf[Maxline] = { 0 };
	char lineBuf[1024] = { 0 };
	char *temp = NULL;

	if (pfilename == NULL || pkey == NULL || pvalue == NULL)
	{
		ret = -1;
	}
	char *fileName = pfilename;
	char *Key = pkey;
	char *Value = pvalue;
	FILE *fp = NULL;
	fp = fopen(fileName, "r+");
	if (fp == NULL)
	{
		fp = fopen(fileName, "wt+");
		if (fp == NULL)
		{
			printf("Open file failed!");
			return -1;
		}
	}

	//��ȡ�ļ�����
	fseek(fp, 0L, SEEK_END);
	fileLen = ftell(fp);
	fseek(fp, 0L, SEEK_SET);
	if (fileLen > 1024 * 8)
	{
		printf("The file length is overflow!");
		//goto END;
	}

	while (!feof(fp))
	{
		fgets(lineBuf, sizeof(lineBuf), fp);
		if (lineBuf == NULL)
		{
			break;
		}
		temp = strstr(lineBuf, Key);
		if (temp)//��������key����(flag = 1)
		{
			sprintf(lineBuf, "%s = %s\n", Key, Value);//�滻���У���һͬcopy��fileBuf��
			strcat(fileBuf, lineBuf);
			flag = 1;
		}
		else     //key������
		{
			strcat(fileBuf, lineBuf);
			continue;
		}
	}

	switch (flag)
	{
		//key������
	case 0: fprintf(fp, "%s = %s\n", Key, Value);
		break;
		//key����
	case 1:
	{
		if (fp != NULL)
		{
			fclose(fp);
			fp == NULL;//����Ұָ��
		}
		fp = fopen(fileName, "wt+");
		if (fp == NULL)
		{
			printf("Open file failed!");
			return -1;
		}
		fputs(fileBuf, fp);
	}
		break;
	}

//END:
//	{
//		fclose(fp);
//		return -1;
//	}
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}