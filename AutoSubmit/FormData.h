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

	stdext::hash_map<const char*, std::string>  m_Fields;//��ֵ���б�

	std::vector<CODE_NAME> m_JobList;//��Ը��ְҵ�б�
	std::vector<CODE_NAME> m_UnitIdList;//��Ը�ߵ�λ���
	std::vector<CODE_NAME> m_SexList;//�Ա��б�

	std::vector<const char*> m_strServiceMode;//����ʽ�б�
	std::vector<const char*> m_strZyzSpecialty;//��Ը���س��б�
	std::vector<const char*> m_strServiceTarget;//��������б�
	std::vector<const char*> m_strCanServiceTime;//���ṩ�����ʱ���б�
};

