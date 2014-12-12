#pragma once

#include "structdef.h"
#include "UtilFunc.h"

class CFormData
{
public:
	CFormData(void);
	virtual ~CFormData(void);

	void BuildPostString();
	void BuildQueryString(const char* idcard);

	void InitData();

	void SetFieldValue(const char* key, std::string value);

	const char* GetCodeByName(std::vector<CODE_NAME>& list, const char* name);
	const char* GetRandomValue(std::vector<const char*>& list);
public:

	std::string m_strPostParam;
	std::string m_strQueryParam;

	stdext::hash_map<const char*, std::string>  m_Fields;//表单值域列表

	std::vector<CODE_NAME> m_JobList;//自愿者职业列表
	std::vector<CODE_NAME> m_UnitIdList;//自愿者单位编号
	std::vector<CODE_NAME> m_SexList;//性别列表

	std::vector<const char*> m_strServiceMode;//服务方式列表
	std::vector<const char*> m_strZyzSpecialty;//自愿者特长列表
	std::vector<const char*> m_strServiceTarget;//服务对象列表
	std::vector<const char*> m_strCanServiceTime;//可提供服务的时间列表
};

