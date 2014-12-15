#pragma once

#include "HttpClient.h"
// CLoginDlg �Ի���

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
	enum { IDD = IDD_LOGIN_DIALOG };

private:
	BOOL m_bIsLogining;

public:
	int  doLogin();
	void SetMsg(const char* msg);
	static UINT WINAPI LoginThread(LPVOID pParam);

	LRESULT OnLoginResult( WPARAM wParam, LPARAM lParam);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_strUserName;
	CString m_strPwd;
	afx_msg void OnBnClickedButtonLgn();
	afx_msg void OnBnClickedButtonCan();
	virtual BOOL OnInitDialog();
};
