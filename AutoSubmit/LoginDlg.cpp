// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutoSubmit.h"
#include "LoginDlg.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
	, m_strUserName(_T(""))
	, m_strPwd(_T(""))
	, m_bIsLogining(FALSE)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	DDV_MaxChars(pDX, m_strUserName, 20);
	DDX_Text(pDX, IDC_EDIT_PWD, m_strPwd);
	DDV_MaxChars(pDX, m_strPwd, 20);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LGN, &CLoginDlg::OnBnClickedButtonLgn)
	ON_BN_CLICKED(IDC_BUTTON_CAN, &CLoginDlg::OnBnClickedButtonCan)
	ON_MESSAGE(WM_LOGIN_RESULT, OnLoginResult)
END_MESSAGE_MAP()

BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//m_strUserName = "500113001011";
	//m_strPwd = "123456";

	m_strUserName = "500113001006";
	m_strPwd = "66214238";

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


// CLoginDlg ��Ϣ�������

BOOL CLoginDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pMsg->message == WM_KEYDOWN)
	{
		switch(pMsg->wParam)
		{
		case VK_ESCAPE:
			return TRUE;
		case VK_RETURN:
			return TRUE;
		default:
			break;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CLoginDlg::SetMsg(const char* msg)
{
	GetDlgItem(IDC_STATIC_LOGINMSG)->SetWindowText(msg);
}

LRESULT CLoginDlg::OnLoginResult( WPARAM wParam, LPARAM lParam)
{
	m_bIsLogining = FALSE;
	int result = (int)lParam;
	if( lParam == 0 )
	{
		GetDlgItem(IDC_BUTTON_LGN)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_PWD)->EnableWindow(TRUE);
		return FALSE;
	}
	else
	{
		CDialog::OnOK();
		return TRUE;
	}
}


int CLoginDlg::doLogin()
{
	std::string url = "http://app.chinavolunteer.gov.cn/zyzmanage/login.do?action=login";
	std::string param = "username=";
	param.append(m_strUserName);
	param.append("&password=");
	param.append(m_strPwd);

	std::string response;
	if( g_pHttp == NULL )
	{
		MessageBox( _T("�����ʼ��ʧ�ܣ��������������򣡣�"), _T("��ʾ"), MB_OK|MB_ICONEXCLAMATION);
		SendMessage(WM_LOGIN_RESULT, 0, 0);
		return -1;
	}
	if( g_pHttp->Post(url, param, response, TRUE) != CURLE_OK )
	{
		AfxMessageBox(g_pHttp->GetErrorMsg());
		SendMessage(WM_LOGIN_RESULT, 0, 0);
		SetMsg("��¼ʧ�ܣ������ԣ�����");
		return -1;
	}
	else
	{
		if( response.find("<title>ȫ��־Ը�߶��齨�������Ϣϵͳ</title>") != std::string::npos ) 
		{
			
		}
		else
		{
			SetMsg("��¼ʧ�ܣ������ԣ���");
			SendMessage(WM_LOGIN_RESULT, 0, 0);
			return -1;
		}
	}
	
	SendMessage(WM_LOGIN_RESULT, 0, 1);
	return 0;
}



UINT WINAPI CLoginDlg::LoginThread(LPVOID pParam)
{
	CLoginDlg* pDlg = (CLoginDlg*) pParam;
	__try
	{
		pDlg->doLogin();
	}
	__except(EXCEPTION_ACCESS_VIOLATION, EXCEPTION_EXECUTE_HANDLER)
	{
		AfxMessageBox(_T("�����쳣��......"));
		pDlg->SetMsg("�����쳣�ˣ���������������!");
		pDlg->SendMessage(WM_LOGIN_RESULT, 0, 0);
	}
	::_endthreadex(999);
	return 999;
}

void CLoginDlg::OnBnClickedButtonLgn()
{
	m_bIsLogining = TRUE;
	UpdateData(TRUE);
	GetDlgItem(IDC_BUTTON_LGN)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_USERNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT_PWD)->EnableWindow(FALSE);
	HANDLE h = (HANDLE) ::_beginthreadex(NULL, 0, LoginThread, this, 0, NULL);
	if( h == NULL )
	{
		MessageBox( _T("�����߳�ʧ�ܣ�"), _T("��ʾ"), MB_OK|MB_ICONEXCLAMATION);
		SendMessage(WM_LOGIN_RESULT, 0, 0);
		m_bIsLogining = FALSE;
		return;
	}
	SetMsg("���ڵ�¼ϵͳ,���Ժ�......");
	CloseHandle(h);
}

void CLoginDlg::OnBnClickedButtonCan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if( m_bIsLogining )
	{
		AfxMessageBox(_T("���ڵ�¼������ȡ����"));
		return;
	}
	CDialog::OnCancel();
}

