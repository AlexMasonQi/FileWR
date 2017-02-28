
#ifndef _CONFIG_H_
#define _CONFIG_H_

#ifdef _cplusplus
extern "C" {
#endif

///<summary>
///读配置文件
///</summary>
int getConfigFile(char *pfilename/*in*/, char *pkey/*in*/, char **pvalue/*out*/, int *valuelen/*out*/);


///<summary>
///写配置文件
///</summary>
int writeConfigFile(char *pfilename/*in*/, char *pkey/*in*/, char *pvalue/*in*/, int *valuelen/*out*/);


#ifdef _cplusplus
}
#endif


#endif