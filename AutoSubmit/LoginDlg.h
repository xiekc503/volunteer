#pragma once

#include "HttpClient.h"
// CLoginDlg 对话框

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginDlg();

// 对话框数据
	enum { IDD = IDD_LOGIN_DIALOG };

private:
	BOOL m_bIsLogining;

public:
	int  doLogin();
	void SetMsg(const char* msg);
	static UINT WINAPI LoginThread(LPVOID pParam);

	LRESULT OnLoginResult( WPARAM wParam, LPARAM lParam);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CString m_strUserName;
	CString m_strPwd;
	afx_msg void OnBnClickedButtonLgn();
	afx_msg void OnBnClickedButtonCan();
	virtual BOOL OnInitDialog();
};
