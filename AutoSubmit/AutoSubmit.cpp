// AutoSubmit.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "AutoSubmit.h"
#include "AutoSubmitDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoSubmitApp

BEGIN_MESSAGE_MAP(CAutoSubmitApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()



char*  g_pStrDBFile = NULL;
CHttpClient* g_pHttp = NULL;


// CAutoSubmitApp ����

CAutoSubmitApp::CAutoSubmitApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAutoSubmitApp ����

CAutoSubmitApp theApp;


// CAutoSubmitApp ��ʼ��

BOOL CAutoSubmitApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	
	m_strModulePath = this->GetModulePath(NULL);
	CString dbFile = m_strModulePath + "autosubmit.db";
	g_pStrDBFile = new char[dbFile.GetLength()+1];
	if( g_pStrDBFile == NULL )
	{
		AfxMessageBox("Ӧ�ó����ʼ��ʧ�ܣ�");
		return FALSE;
	}
	sprintf(g_pStrDBFile, "%s", dbFile);

	g_pHttp = new CHttpClient();
	if( g_pHttp == NULL )
	{
		AfxMessageBox("Ӧ�ó����ʼ��ʧ�ܣ�");
		return FALSE;
	}
	g_pHttp->SetDebug(false);

	INT_PTR nResponse;
	{
		CLoginDlg logindlg;
		nResponse = logindlg.DoModal();
		if( nResponse != IDOK )
		{
			return FALSE;
		}
	}
	CAutoSubmitDlg dlg;
	m_pMainWnd = &dlg;
	nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

CString CAutoSubmitApp::GetModulePath(HMODULE hModule)
{

	CString strPath;
	LPTSTR lpModule = strPath.GetBuffer(MAX_PATH);
	GetModuleFileName(hModule, lpModule, MAX_PATH);
	LPTSTR lpPos = _tcsrchr(lpModule, _T('\\'));
	if (lpPos != NULL)
	{
		*(lpPos + 1) = _T('\0');
	}
	strPath.ReleaseBuffer();
	return strPath;
}

int CAutoSubmitApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
	if( g_pStrDBFile )
	{
		delete g_pStrDBFile;
		g_pStrDBFile = NULL;
	}
	if( g_pHttp )
	{
		delete g_pHttp;
		g_pHttp = NULL;
	}
	return CWinApp::ExitInstance();
}
