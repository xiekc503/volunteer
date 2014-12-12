#include "stdafx.h"
#include "UtilFunc.h"


void strSplit(const char * str, const char * format,char *** strData,int* nDataNum)
{
	if(strlen(str)==0)
	{
		(* nDataNum)=0;
		return;
	}
	CString strSource;
	strSource.Format("%s",str);
	if(strcmp(strSource.Mid(strSource.GetLength()-strlen(format)),format)!=0)
	{
		strSource+=format;
	}

	int nIndex;
	int nPos=0;
	int nFLen = strlen(format);
	(* nDataNum)=0;
	while(true)
	{
		nIndex=strSource.Find(format,nPos);
		if(nIndex<0)
		{
			break;
		}
		else
		{
			(* nDataNum)++;
			nPos=nIndex+nFLen;
		}
	}
	if((* nDataNum)>0)
	{
		(*strData)=new char*[(*nDataNum)+1];
	}
	nPos = 0;
	CString tmp;
	for(int i=0; i<*nDataNum; i++)
	{
		nIndex = strSource.Find(format,nPos);
		tmp = strSource.Mid(nPos, nIndex-nPos);
		tmp.TrimLeft();
		tmp.TrimRight();
		(*strData)[i] = new char[tmp.GetLength()+1];
		sprintf((*strData)[i], "%s", tmp);
		nPos = nIndex+nFLen;
	}
}

void myFree(char***pack,int& num)
{
	if(num<=0)return;
	for(int i=0;i<num;i++)
	{
		//delete[]pack[i];
		free((*pack)[i]);
	}
	//delete pack;
	free(*pack);
}

int  getRandomNumber(int min, int max)
{
	srand((unsigned int)time(NULL));
	return rand()%(max-min) + min;
}

void getBirthdayFormIdCode(const char* idcode, char* birthday)
{
	memcpy(birthday, idcode+6, 4);
	strcat(birthday, "-");
	memcpy(birthday+5, idcode+10, 2);
	strcat(birthday, "-");
	memcpy(birthday+8, idcode+12, 2);
}