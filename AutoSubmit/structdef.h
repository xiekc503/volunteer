#pragma once


typedef struct code_name_t{
	char code[8];
	char name[60];
	code_name_t()
	{
		memset(code, 0, sizeof(code));
		memset(name, 0, sizeof(name));
	}
	code_name_t(const struct code_name_t& codename)
	{
		memcpy(code, codename.code, sizeof(code));
		memcpy(name, codename.name, sizeof(name));
	}
	code_name_t& operator=(const struct code_name_t& codename)
	{
		memcpy(code, codename.code, sizeof(code));
		memcpy(name, codename.name, sizeof(name));
		return *this;
	}
}CODE_NAME,*PCODE_NAME;


typedef struct zyz_info_t{
	unsigned int index;
	char name[20];
	char idcard[20];
	char mobile[20];
	char sex[10];
	char username[20];
	char job[80];
	char dwcode[20];
	BOOL success;
	BOOL handled;
}ZYZ_INFO, *PZYZ_INFO;
