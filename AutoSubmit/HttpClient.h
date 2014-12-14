#pragma once

class CHttpClient
{
public:
	CHttpClient(void);
	virtual ~CHttpClient(void);

	/*
	* 发送Http Post请求
	* strUrl - HTTP请求地址
	* strParam - POST数据
	* strResponse - 返回结果内容
	*/
	int Post(const std::string& strUrl, const std::string& strParam, std::string& strResponse, BOOL bUseCookie=FALSE);

	/*
	* 发送Http Get请求
	* strUrl - HTTP请求地址
	* strResponse - 返回结果内容
	*/
	int Get(const std::string & strUrl, std::string & strResponse, BOOL bUseCookie = FALSE);

	void SetDebug(bool debug);

	char* GetErrorMsg();

	static unsigned int m_nRefCount;

private:
	bool m_bDebug;
	char m_strMsg[1024];
};

