// AutoSubmitDlg.h : ͷ�ļ�
//

#pragma once

#include "EditListCtrl.h"
#include "HttpClient.h"
#include "UtilFunc.h"
#include "FormData.h"
#include "DbSqlite.h"
#include "afxcmn.h"

// CAutoSubmitDlg �Ի���
class CAutoSubmitDlg : public CDialog
{
// ����
public:
	CAutoSubmitDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_AUTOSUBMIT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	CString m_strMsg;
	BOOL m_bStop;
	BOOL m_bIsSubmiting;
	std::string m_strToken;
	CFormData formData;
	std::vector<ZYZ_INFO> submit_list;
	CString m_strFileName;

	BOOL GetToken();
	int  doSubmit();
	static UINT WINAPI AutoSubmitThread(LPVOID pParam);
	static UINT WINAPI LoadDataThread(LPVOID pParam);
	static UINT WINAPI StopThread(LPVOID pParam);

	LRESULT OnSubmitResult( WPARAM wParam, LPARAM lParam);

	void SetMsg(const char* msg);
	BOOL ParaseFile();
	BOOL ShowSubmitList();
	BOOL SaveFailedList();
	void SmartSleep(int minSeconds, int maxSeconds);

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEditListCtrl m_ListCtrl;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButtonSelFile();
	afx_msg void OnBnClickedButtonSubmit();
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonSaveFailed();
};
