
#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef _cplusplus
extern "C" {
#endif

///<summary>
///�������ļ�
///</summary>
int getConfigFile(char *pfilename/*in*/, char *pkey/*in*/, char **pvalue/*out*/, int *valuelen/*out*/);


///<summary>
///д�����ļ�
///</summary>
int writeConfigFile(char *pfilename/*in*/, char *pkey/*in*/, char *pvalue/*in*/, int *valuelen/*out*/);


#ifdef _cplusplus
}
#endif


#endif