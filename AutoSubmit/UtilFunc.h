#pragma once

extern void strSplit(const char * str,const char * format,char *** strData,int* nDataNum);
extern void myFree(char***pack,int& num);
extern int  getRandomNumber(int min, int max);
extern void getBirthdayFormIdCode(const char* idcode, char* birthday);
