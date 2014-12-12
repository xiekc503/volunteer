#include "stdafx.h"
#include "HttpClient.h"

unsigned int CHttpClient::m_nRefCount = 0;

static int OnDebug(CURL *, curl_infotype itype, char * pData, size_t size, void *)
{
	if(itype == CURLINFO_TEXT) 
	{
	}
	else if(itype == CURLINFO_HEADER_IN)  
	{  
		TRACE("[HEADER_IN]%s\n", pData);  
	}  
	else if(itype == CURLINFO_HEADER_OUT)  
	{  
		TRACE("[HEADER_OUT]%s\n", pData);  
	}  
	else if(itype == CURLINFO_DATA_IN)  
	{  
		TRACE("[DATA_IN]%s\n", pData);  
	}  
	else if(itype == CURLINFO_DATA_OUT)  
	{  
		TRACE("[DATA_OUT]%s\n", pData);  
	}  
	return 0;  
}


static size_t OnWriteData(void* buffer, size_t size, size_t nmemb, void* lpVoid)
{
	 std::string* str = dynamic_cast<std::string*>((std::string *)lpVoid);
	 if( NULL == str || NULL == buffer )
	 {
		  return -1;
	 }
	 char* pData = (char*)buffer;
	 str->append(pData, size * nmemb);
	 return nmemb;
}


CHttpClient::CHttpClient(void)
{
	memset(m_strMsg, 0, sizeof(m_strMsg));
	m_bDebug = false;

	if( m_nRefCount == 0 )
	{
		curl_global_init(CURL_GLOBAL_WIN32);
	}
	m_nRefCount++;
}

CHttpClient::~CHttpClient(void)
{
	m_nRefCount--;
	if( m_nRefCount == 0 )
	{
		curl_global_cleanup();
	}
}

void CHttpClient::SetDebug(bool debug)
{
	m_bDebug = debug;
}

char* CHttpClient::GetErrorMsg()
{
	return m_strMsg;
}

int CHttpClient::Post(const std::string& strUrl, const std::string& strParam, std::string& strResponse, BOOL bUseCookie)
{
	strResponse = "";
	CURLcode return_code;
	long http_response_code = 0;
	long timeout = 90;

	CURL* curl = curl_easy_init();
	if( curl == NULL )
	{
		return  CURLE_FAILED_INIT;
	}
	if( m_bDebug )
	{
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
	}
	if( bUseCookie )
	{
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE,"cookie.txt");
		curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
	}
	curl_easy_setopt(curl, CURLOPT_URL, strUrl.c_str());
	curl_easy_setopt(curl, CURLOPT_POST, 1);
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, strParam.c_str());
	curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&strResponse);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
	//curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);//不重用连接

	return_code = curl_easy_perform(curl);
	if(return_code != CURLE_OK)
	{
		sprintf_s(m_strMsg, "curl_easy_perform() failed: %s\n", curl_easy_strerror(return_code));
		curl_easy_cleanup(curl);
		return return_code;
	}
	return_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE , &http_response_code);
	if(return_code != CURLE_OK)
	{
		sprintf_s(m_strMsg, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(return_code));
		curl_easy_cleanup(curl);
		return return_code;
	}
	
	curl_easy_cleanup(curl);
	return return_code;
}

int CHttpClient::Get(const std::string & strUrl, std::string & strResponse, BOOL bUseCookie)
{
	strResponse = "";
	CURLcode return_code;
	long http_response_code = 0;
	long timeout = 90;

	CURL* curl = curl_easy_init();
	if( curl == NULL )
	{
		return  CURLE_FAILED_INIT;
	}
	if( m_bDebug )
	{
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, OnDebug);
	}
	if( bUseCookie )
	{
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE,"cookie.txt");
		curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookie.txt");
	}
	curl_easy_setopt(curl, CURLOPT_URL, strUrl.c_str());
	curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, OnWriteData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&strResponse);
	curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1);
	curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10);
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
	//curl_easy_setopt(curl, CURLOPT_FORBID_REUSE, 1);//不重用连接
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

	return_code = curl_easy_perform(curl);
	if(return_code != CURLE_OK)
	{
		sprintf_s(m_strMsg, "curl_easy_perform() failed: %s\n", curl_easy_strerror(return_code));
		curl_easy_cleanup(curl);
		return return_code;
	}
	return_code = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE , &http_response_code);
	if(return_code != CURLE_OK)
	{
		sprintf_s(m_strMsg, "curl_easy_getinfo() failed: %s\n", curl_easy_strerror(return_code));
		curl_easy_cleanup(curl);
		return return_code;
	}
	curl_easy_cleanup(curl);
	return return_code;
}
