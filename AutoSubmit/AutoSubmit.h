// AutoSubmit.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAutoSubmitApp:
// �йش����ʵ�֣������ AutoSubmit.cpp
//

class CAutoSubmitApp : public CWinApp
{
public:
	CAutoSubmitApp();

	CString m_strModulePath;
// ��д
	public:
	virtual BOOL InitInstance();
	
	static CString GetModulePath(HMODULE hModule);
// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CAutoSubmitApp theApp;