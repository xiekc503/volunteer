#pragma once

class CHttpClient
{
public:
	CHttpClient(void);
	virtual ~CHttpClient(void);

	/*
	* ����Http Post����
	* strUrl - HTTP�����ַ
	* strParam - POST����
	* strResponse - ���ؽ������
	*/
	int Post(const std::string& strUrl, const std::string& strParam, std::string& strResponse, BOOL bUseCookie=FALSE);

	/*
	* ����Http Get����
	* strUrl - HTTP�����ַ
	* strResponse - ���ؽ������
	*/
	int Get(const std::string & strUrl, std::string & strResponse, BOOL bUseCookie = FALSE);

	void SetDebug(bool debug);

	char* GetErrorMsg();

	static unsigned int m_nRefCount;

private:
	bool m_bDebug;
	char m_strMsg[1024];
};

