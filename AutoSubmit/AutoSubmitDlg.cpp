// AutoSubmitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AutoSubmit.h"
#include "AutoSubmitDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAutoSubmitDlg �Ի���




CAutoSubmitDlg::CAutoSubmitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoSubmitDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutoSubmitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_ListCtrl);
}

BEGIN_MESSAGE_MAP(CAutoSubmitDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_SUBMIT_RESULT, OnSubmitResult)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_SEL_FILE, &CAutoSubmitDlg::OnBnClickedButtonSelFile)
	ON_BN_CLICKED(IDC_BUTTON_SUBMIT, &CAutoSubmitDlg::OnBnClickedButtonSubmit)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_SAVE_FAILED, &CAutoSubmitDlg::OnBnClickedButtonSaveFailed)
END_MESSAGE_MAP()


// CAutoSubmitDlg ��Ϣ�������

BOOL CAutoSubmitDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CImageList   m_l;
	m_l.Create(1,22,TRUE|ILC_COLOR32,1,0);
	m_ListCtrl.SetImageList(&m_l,LVSIL_SMALL);
	m_ListCtrl.SetExtendedStyle(m_ListCtrl.GetExtendedStyle()|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	
	m_ListCtrl.InsertColumn( 0, _T("���"), LVCFMT_LEFT, 50);
	m_ListCtrl.InsertColumn( 1, _T("����"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn( 2, _T("���֤����"), LVCFMT_LEFT, 180);
	m_ListCtrl.InsertColumn( 3, _T("��ϵ�绰"), LVCFMT_LEFT, 120);
	m_ListCtrl.InsertColumn( 4, _T("�Ա�"), LVCFMT_LEFT, 50);
	m_ListCtrl.InsertColumn( 5, _T("��¼�û���"), LVCFMT_LEFT, 100);
	m_ListCtrl.InsertColumn( 6, _T("ְҵ"), LVCFMT_LEFT, 260);
	m_ListCtrl.InsertColumn( 7, _T("��λ���"), LVCFMT_LEFT, 120);
	m_ListCtrl.InsertColumn( 8, _T("�ύ���"), LVCFMT_LEFT, 200);
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_ListCtrl.SetItemState(0,  LVIS_ACTIVATING|LVIS_FOCUSED|LVIS_SELECTED,LVIS_SELECTED|LVIS_FOCUSED);
	CenterWindow();

	PostMessage(WM_SIZE);

	formData.InitData();

	GetDlgItem(IDC_BUTTON_SUBMIT)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_SAVE_FAILED)->EnableWindow(FALSE);
	m_bStop = TRUE;
	m_bIsSubmiting = FALSE;
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CAutoSubmitDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CAutoSubmitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CAutoSubmitDlg::PreTranslateMessage(MSG* pMsg)
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

void CAutoSubmitDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialog::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if( ::IsWindow(GetDlgItem(IDC_LIST)->GetSafeHwnd()) )
	{
		CRect rect;
		CRect rectListCtrlNewSize;
		GetClientRect( &rect);
		CListCtrl* pList = (CListCtrl*)GetDlgItem( IDC_LIST );

		rectListCtrlNewSize.top = rect.top;
		rectListCtrlNewSize.left = rect.left;
		rectListCtrlNewSize.bottom = rect.bottom - 50;
		rectListCtrlNewSize.right = rect.right - 1;
		m_ListCtrl.MoveWindow( &rectListCtrlNewSize, TRUE);


		CRect rtButton;
		GetDlgItem( IDC_STATIC_FILE )->GetWindowRect(&rtButton);
		ScreenToClient(&rtButton);
		CRect rtNew = rtButton;
		rtNew.left = rectListCtrlNewSize.left + 13;
		rtNew.top = rectListCtrlNewSize.bottom + 15;
		rtNew.right = rtNew.left + rtButton.Width();
		rtNew.bottom = rtNew.top + rtButton.Height();
		GetDlgItem( IDC_STATIC_FILE)->MoveWindow(&rtNew);

		int right = rtNew.right;

		GetDlgItem( IDC_EDIT_FILE )->GetWindowRect(&rtButton);
		ScreenToClient(&rtButton);
		rtNew.left = right + 2; 
		rtNew.right = rtNew.left + rtButton.Width();
		rtNew.top = rectListCtrlNewSize.bottom + 13;
		rtNew.bottom = rtNew.top + rtButton.Height();
		GetDlgItem( IDC_EDIT_FILE)->MoveWindow(&rtNew);

		right = rtNew.right;
		GetDlgItem(IDC_BUTTON_SEL_FILE)->GetWindowRect(&rtButton);
		ScreenToClient(&rtButton);
		rtNew.left = right + 8; 
		rtNew.right = rtNew.left + rtButton.Width();
		rtNew.top = rectListCtrlNewSize.bottom + 13;
		rtNew.bottom = rtNew.top + rtButton.Height();
		GetDlgItem( IDC_BUTTON_SEL_FILE )->MoveWindow(&rtNew);
 
		right = rtNew.right;
		GetDlgItem(IDC_BUTTON_SUBMIT)->GetWindowRect(&rtButton);
		ScreenToClient(&rtButton);
		rtNew.left = right + 8; 
		rtNew.right = rtNew.left + rtButton.Width();
		rtNew.top = rectListCtrlNewSize.bottom + 13;
		rtNew.bottom = rtNew.top + rtButton.Height();
		GetDlgItem( IDC_BUTTON_SUBMIT )->MoveWindow(&rtNew);

		right = rtNew.right;
		GetDlgItem(IDC_BUTTON_SAVE_FAILED)->GetWindowRect(&rtButton);
		ScreenToClient(&rtButton);
		rtNew.left = right + 8; 
		rtNew.right = rtNew.left + rtButton.Width();
		rtNew.top = rectListCtrlNewSize.bottom + 13;
		rtNew.bottom = rtNew.top + rtButton.Height();
		GetDlgItem( IDC_BUTTON_SAVE_FAILED )->MoveWindow(&rtNew);

		right = rtNew.right;
		GetDlgItem(IDC_STATIC_INFO)->GetWindowRect(&rtButton);
		ScreenToClient(&rtButton);
		rtNew.left = right + 10; 
		rtNew.right = rtNew.left + rtButton.Width();
		rtNew.top = rectListCtrlNewSize.bottom + 15;
		rtNew.bottom = rtNew.top + rtButton.Height();
		GetDlgItem( IDC_STATIC_INFO )->MoveWindow(&rtNew);
	}
}


void CAutoSubmitDlg::SetMsg(const char* msg)
{
	m_strMsg.Format("��ǰ״̬��%s ", msg);
	GetDlgItem(IDC_STATIC_INFO)->SetWindowText(m_strMsg);
	UpdateWindow();
}

BOOL CAutoSubmitDlg::GetToken()
{
	m_strToken = "";
	std::string url = "http://app.chinavolunteer.gov.cn/zyzmanage/main/zyz_manager/volBifAdd.do?method=prepAdd";
	std::string response;
	if( g_pHttp == NULL )
	{
		return FALSE;
	}
	if( g_pHttp->Get(url, response, TRUE) != CURLE_OK )
	{
		return FALSE;
	}
	std::string::size_type pos = response.find("\"org.apache.struts.taglib.html.TOKEN\" value=\"", 0);
	if( pos == std::string::npos )
	{
		return FALSE;
	}
	pos += 45;
	m_strToken = response.substr(pos, 32);
	return TRUE;
}


int CAutoSubmitDlg::doSubmit()
{
	std::string posturl = "http://app.chinavolunteer.gov.cn/zyzmanage/main/zyz_manager/volBifInsert.do?method=add&type=1";
	std::string queryurl = "http://app.chinavolunteer.gov.cn/zyzmanage/main/zyz_manager/volBifList.do?method=list";
	std::string response;
	if( g_pHttp == NULL )
	{
		AfxMessageBox(_T("�����ʼ��ʧ�ܣ��������������򣡣�"));
		return -1;
	}
	size_t size = submit_list.size();
	char birthday[12] =  {0};
	std::string zyzServiceMode;
	std::string zyzSpecialty;
	std::string zyzServiceTarget;
	std::string zyzCanServiceTime;

	PZYZ_INFO pInfo = NULL;
	CString msg;

	CDbSQLite* pDb = new CDbSQLite;
	if( !pDb->Open(g_pStrDBFile) )
	{
		delete pDb;
		pDb = NULL;
		MessageBox("�����ݿ�ʧ��", _T("��ʾ"), MB_OK|MB_ICONEXCLAMATION);
		return -1;
	}

	CString strSql;
	strSql.Format("INSERT INTO RECORDS VALUES(:v1, :v2, :v3)");
	CSqlStatement* pInsertStmt = pDb->Statement(strSql);
	if( pInsertStmt == NULL )
	{
		delete pDb;
		pDb = NULL;
		MessageBox( "���ݿ����ʧ�ܣ�", _T("��ʾ"), MB_OK|MB_ICONINFORMATION);
		return -1;
	}
	std::string find_str = "";
	pDb->Begin();
	m_bIsSubmiting = TRUE;
	for(size_t i=0; i<size; i++)
	{
		pInfo = &(submit_list[i]);
		if( pInfo->handled )
		{
			continue;
		}
		if( m_bStop )
		{
			m_bIsSubmiting = FALSE;
			pDb->ReleaseStatement(pInsertStmt);
			delete pDb;
			pDb = NULL;
			return 0;
		}
		msg.Format("������� (%d / %d)", i+1, size);
		SetMsg(msg);

		strSql.Format("SELECT COUNT(IDCARD) FROM RECORDS WHERE IDCARD='%s'", pInfo->idcard);
		CSqlStatement* pStmt = pDb->Statement(strSql);
		if( pStmt == NULL )
		{
			pDb->ReleaseStatement(pInsertStmt);
			pDb->Close();
			delete pDb;
			pDb = NULL;
			m_bIsSubmiting = FALSE;
			MessageBox( "���ݿ����ʧ�ܣ�", _T("��ʾ"), MB_OK|MB_ICONEXCLAMATION);
			return -1;
		}
		pStmt->NextRow();
		int count = pStmt->getInt(0);
		pDb->ReleaseStatement(pStmt);
	
		if( count > 0 )
		{
			PostMessage(WM_SUBMIT_RESULT, i, 2);
			Sleep(1000);
			continue;
		}

		if( GetToken() == FALSE )
		{
			SetMsg("����¼�����ʧ�ܣ�δ��ȡ��Token����");
			PostMessage(WM_SUBMIT_RESULT, i, 3);
			continue;
		}
		if( m_bStop )
		{
			m_bIsSubmiting = FALSE;
			pDb->ReleaseStatement(pInsertStmt);
			delete pDb;
			pDb = NULL;
			return 0;
		}
		
		formData.SetFieldValue("org.apache.struts.taglib.html.TOKEN", m_strToken);
		formData.SetFieldValue("zyzCnName", pInfo->name);
		formData.SetFieldValue("zyzPapersNumber", pInfo->idcard);
		formData.SetFieldValue("zyzMobile", pInfo->mobile);
		formData.SetFieldValue("zyzSex", formData.GetCodeByName(formData.m_SexList, pInfo->sex));//119-�� 120-Ů
		formData.SetFieldValue("zyzUsername", pInfo->username);
		formData.SetFieldValue("zyzJob", formData.GetCodeByName(formData.m_JobList, pInfo->job));
		formData.SetFieldValue("unitID", formData.GetCodeByName(formData.m_UnitIdList, pInfo->dwcode));

		memset(birthday, 0, sizeof(birthday));
		getBirthdayFormIdCode(pInfo->idcard, birthday);
		formData.SetFieldValue("zyzBirthStr", birthday);

		zyzServiceMode  = formData.GetRandomValue(formData.m_strServiceMode);
		formData.SetFieldValue("show_zyzServiceMode", zyzServiceMode);
		formData.SetFieldValue("zyzServiceMode", zyzServiceMode);

		zyzSpecialty  = formData.GetRandomValue(formData.m_strZyzSpecialty);
		formData.SetFieldValue("show_zyzSpecialty", zyzSpecialty);
		formData.SetFieldValue("zyzSpecialty", zyzSpecialty);
 
		zyzServiceTarget  = formData.GetRandomValue(formData.m_strServiceTarget);
		formData.SetFieldValue("show_zyzServiceTarget", zyzServiceTarget);
		formData.SetFieldValue("zyzServiceTarget", zyzServiceTarget);
	 
		zyzCanServiceTime  = formData.GetRandomValue(formData.m_strCanServiceTime);
		formData.SetFieldValue("show_zyzCanServiceTime", zyzCanServiceTime);
		formData.SetFieldValue("zyzCanServiceTime", zyzCanServiceTime);

		formData.BuildPostString();
	

		if( g_pHttp->Post(posturl, formData.m_strPostParam, response, TRUE) != CURLE_OK )
		{
			PostMessage(WM_SUBMIT_RESULT, i, 0);
			continue;
		}
		else
		{
			if( response.find("<title>�Ǽ���Ϣ�б�</title>") != std::string::npos )
			{
				formData.BuildQueryString(pInfo->idcard);
				SmartSleep(10, 30);
				if( g_pHttp->Post(queryurl, formData.m_strQueryParam, response, TRUE) != CURLE_OK )
				{
					PostMessage(WM_SUBMIT_RESULT, i, -1);
					continue;
				}
				else
				{
					find_str = "bgcolor=\"#FFFFFF\">";
					find_str += pInfo->idcard;
					find_str += "</td>";
					if( response.find("<title>�Ǽ���Ϣ�б�</title>") != std::string::npos && response.find(find_str) != std::string::npos )
					{
						PostMessage(WM_SUBMIT_RESULT, i, 1);
						pInsertStmt->Bind(0, pInfo->idcard);
						pInsertStmt->Bind(1, pInfo->name);
						pInsertStmt->Bind(2, pInfo->username);
						if(!pInsertStmt->Execute())
						{
							pDb->Rollback();
							pDb->ReleaseStatement(pInsertStmt);
							delete pDb;
							pDb = NULL;
							m_bIsSubmiting = FALSE;
							MessageBox( "���ݿ����ʧ�ܣ�", _T("��ʾ"), MB_OK|MB_ICONINFORMATION);
							return -1;
						}
						pDb->Commit();
					}
					else
					{
						FILE* fp = fopen(theApp.m_strModulePath + "result.txt", "a+");
						fputs(response.c_str(), fp);
						fputs("\r\n\r\n=====================================================================================\r\n\r\n\r\n", fp);
						fclose(fp);
						PostMessage(WM_SUBMIT_RESULT, i, 0);
					}
				}
			}
			else
			{
				FILE* fp = fopen(theApp.m_strModulePath + "result.txt", "a+");
				fputs(response.c_str(), fp);
				fputs("\r\n\r\n=====================================================================================\r\n\r\n\r\n", fp);
				fclose(fp);
				PostMessage(WM_SUBMIT_RESULT, i, 0);
			}
		}
		Sleep(1000);
	}
	m_bIsSubmiting = FALSE;
	pDb->ReleaseStatement(pInsertStmt);
	delete pDb;
	pDb = NULL;
	SetMsg("������ϣ��������¼��վ�鿴��");
	return 0;
}

LRESULT CAutoSubmitDlg::OnSubmitResult( WPARAM wParam, LPARAM lParam)
{
	int index = (int)wParam;
	int ret = (int)lParam;
	int size = submit_list.size();
	switch( ret )
	{
	case -1:
		m_ListCtrl.SetItemText(index, 8, "δ֪¼����");
		break;
	case 0:
		m_ListCtrl.SetItemText(index, 8, "¼��ʧ��");
		break;
	case 1:
		m_ListCtrl.SetItemText(index, 8, "¼��ɹ�");
		submit_list[index].success = TRUE;
		break;
	case 2:
		m_ListCtrl.SetItemText(index, 8, "�Ѵ��ڣ�����");
		submit_list[index].success = TRUE;
		break;
	case 3:
		m_ListCtrl.SetItemText(index, 8, "����¼�����ʧ��");
		break;
	}
//	if( index < size-1 )
//	{
//		m_ListCtrl.SetItemState(index+1,  LVIS_ACTIVATING|LVIS_FOCUSED|LVIS_SELECTED,LVIS_SELECTED|LVIS_FOCUSED);
//		m_ListCtrl.Scroll( CSize( index,   index+1 ));   
//	}
	submit_list[index].handled = TRUE;
	UpdateWindow();
	return TRUE;
}

UINT WINAPI  CAutoSubmitDlg::StopThread( LPVOID pParam)
{
	CAutoSubmitDlg* pDlg = (CAutoSubmitDlg*) pParam;
	__try
	{
		pDlg->m_bStop = TRUE;
		pDlg->SetMsg("���ڵȴ�¼�빤�����������Ժ�...");
		while(pDlg->m_bIsSubmiting)
		{
			Sleep(200);
		}
		pDlg->SetMsg("¼�빤����ֹͣ����");
		pDlg->GetDlgItem(IDC_BUTTON_SUBMIT)->EnableWindow(TRUE);
		return TRUE;
	}
	__except(EXCEPTION_ACCESS_VIOLATION, EXCEPTION_EXECUTE_HANDLER)
	{
		AfxMessageBox(_T("�����쳣��......"));
	}
	::_endthreadex(997);
	return 997;
}


UINT WINAPI CAutoSubmitDlg::AutoSubmitThread(LPVOID pParam)
{
	CAutoSubmitDlg* pDlg = (CAutoSubmitDlg*) pParam;
	__try
	{
		pDlg->doSubmit();
	}
	__except(EXCEPTION_ACCESS_VIOLATION, EXCEPTION_EXECUTE_HANDLER)
	{
		AfxMessageBox(_T("�����쳣��......"));
	}
	pDlg->m_bIsSubmiting = FALSE;
	pDlg->GetDlgItem(IDC_BUTTON_SUBMIT)->SetWindowText(_T("��ʼ¼��"));
	pDlg->GetDlgItem(IDC_BUTTON_SUBMIT)->EnableWindow(TRUE);
	pDlg->GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(TRUE);
	pDlg->GetDlgItem(IDC_BUTTON_SAVE_FAILED)->EnableWindow(TRUE);
	::_endthreadex(998);
	return 998;
}

UINT WINAPI CAutoSubmitDlg::LoadDataThread(LPVOID pParam)
{
	CAutoSubmitDlg* pDlg = (CAutoSubmitDlg*) pParam;
	__try
	{
		pDlg->ParaseFile();
	}
	__except(EXCEPTION_ACCESS_VIOLATION, EXCEPTION_EXECUTE_HANDLER)
	{
		AfxMessageBox(_T("�����쳣��......"));
	}
	::_endthreadex(997);
	return 998;
}


void CAutoSubmitDlg::OnBnClickedButtonSubmit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if( m_bStop )
	{
		if( submit_list.size() == 0 )
		{
			AfxMessageBox("û����Ҫ¼������ݣ���");
			return;
		}
		m_bStop = FALSE;
		HANDLE h = (HANDLE) ::_beginthreadex(NULL, 0, AutoSubmitThread, this, 0, NULL);
		if( h == NULL )
		{
			AfxMessageBox("�����߳�ʧ��!");
			return;
		}
		CloseHandle(h);
		GetDlgItem(IDC_BUTTON_SUBMIT)->SetWindowText(_T("ֹͣ¼��"));
		GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_SAVE_FAILED)->EnableWindow(FALSE);
	}
	else
	{
		UINT ret = MessageBox( "ȷ��ֹͣ¼����", _T("��ʾ"), MB_YESNO|MB_ICONQUESTION);
		if( ret == IDYES )
		{	
			GetDlgItem(IDC_BUTTON_SUBMIT)->SetWindowText(_T("��ʼ¼��"));
			GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_SUBMIT)->EnableWindow(FALSE);
			HANDLE h = (HANDLE) ::_beginthreadex(NULL, 0, StopThread, this, 0, NULL);
			if( h == NULL )
			{
				AfxMessageBox("�����߳�ʧ��!");
				return;
			}
			CloseHandle(h);
		}
	}
}

void CAutoSubmitDlg::OnBnClickedButtonSelFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFilter;
	strFilter = "csv�ļ�(*.csv)|*.csv|�����ļ�(*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_EXPLORER, strFilter);

	if(dlg.DoModal() != IDOK)
	{
		return;
	}
	m_strFileName = dlg.GetPathName();
	SetDlgItemText(IDC_EDIT_FILE, m_strFileName);

	HANDLE h = (HANDLE) ::_beginthreadex(NULL, 0, LoadDataThread, this, 0, NULL);
	if( h == NULL )
	{
		AfxMessageBox("�����߳�ʧ��!");
		return;
	}
	SetMsg("���ڼ�������......");
	GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(FALSE);
	CloseHandle(h);
}


BOOL CAutoSubmitDlg::ParaseFile()
{
	if( m_strFileName.IsEmpty() )
	{
		return FALSE;
	}

	char strLineBuf[1000] = {0};
	FILE* fp = NULL;
	fp = fopen(m_strFileName, "r");
	if( fp == NULL )
	{
		AfxMessageBox("���ļ�ʧ�ܣ�");
		GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(TRUE); 
		return FALSE;
	}

	int startRow = 2;
	//���Ա�������ǰ����
	for(int lineNo=1; lineNo<startRow-1; lineNo++)
	{
		if( fgets(strLineBuf, sizeof(strLineBuf), fp)==NULL )
		{
			fclose(fp);
			AfxMessageBox("�ļ���ʽ���������ļ�(�����д���)��");
			GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(TRUE); 
			return FALSE;
		}
	}
	//��ȡ������
	if( fgets(strLineBuf, sizeof(strLineBuf), fp)==NULL )
	{
		fclose(fp);
		AfxMessageBox("�ļ���ʽ���������ļ�(�����д���)��");
		GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(TRUE); 
		return FALSE;
	}

	char** strData;
	int nDataNum;
	strSplit(strLineBuf, ",", &strData, &nDataNum);
	myFree(&strData, nDataNum);
	if( nDataNum != 8 )
	{
		fclose(fp);
		AfxMessageBox("�ļ���ʽ���������ļ�(�����д���)��");
		GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(TRUE); 
		return FALSE;
	}
	int index = 1;
	submit_list.clear();
	CString strCheck;
	while (true)
	{
		if( fgets(strLineBuf, sizeof(strLineBuf), fp) == NULL )
		{
			break;
		}
		strSplit(strLineBuf, ",", &strData, &nDataNum);
		if( nDataNum != 8 )//���������У�����
		{
			myFree(&strData, nDataNum);
			continue;
		}
		strCheck.Format("%s", strData[2]);
		strCheck = strCheck.TrimLeft();
		strCheck = strCheck.TrimRight();
		if(strCheck.IsEmpty() )
		{
			myFree(&strData, nDataNum);
			continue;
		}
		ZYZ_INFO info;
		memset(&info, 0, sizeof(info));
		info.index = atoi(strData[0]);
		sprintf(info.name, "%s", strData[1]);
		sprintf(info.idcard,"%s", strData[2]);
		sprintf(info.mobile, "%s", strData[3]);
		sprintf(info.sex, "%s", strData[4]);
		sprintf(info.username, "%s", strData[5]);
		//sprintf(info.username, "gyj%06d", info.index);
		sprintf(info.job, "%s", strData[6]);
		sprintf(info.dwcode, "%s", strData[7]);
		info.success = FALSE;
		submit_list.push_back(info);
		index++;
		myFree(&strData, nDataNum);
	}
	fclose(fp);

	ShowSubmitList();

	return TRUE;
}

BOOL CAutoSubmitDlg::ShowSubmitList()
{
	m_ListCtrl.DeleteAllItems();
	m_ListCtrl.SetRedraw(FALSE);
	PZYZ_INFO pInfo = NULL;
	CString strTmp;
	for(size_t i=0; i<submit_list.size(); i++)
	{
		pInfo = &(submit_list[i]);
		strTmp.Format("%d", pInfo->index);
		m_ListCtrl.InsertItem(i, strTmp);
		m_ListCtrl.SetItemText(i, 1, pInfo->name);
		m_ListCtrl.SetItemText(i, 2, pInfo->idcard);
		m_ListCtrl.SetItemText(i, 3, pInfo->mobile);
		m_ListCtrl.SetItemText(i, 4, pInfo->sex);
		m_ListCtrl.SetItemText(i, 5, pInfo->username);
		m_ListCtrl.SetItemText(i, 6, pInfo->job);
		m_ListCtrl.SetItemText(i, 7, pInfo->dwcode);
	}
	m_ListCtrl.SetRedraw(TRUE);
	m_ListCtrl.ShowVerticalScrollBar(22);

	SetMsg("���ݼ�����ϣ�������ʼ¼�룡");
	GetDlgItem(IDC_BUTTON_SEL_FILE)->EnableWindow(TRUE); 
	GetDlgItem(IDC_BUTTON_SUBMIT)->EnableWindow(TRUE);
	return TRUE;
}


BOOL CAutoSubmitDlg::SaveFailedList()
{
	size_t size = submit_list.size();
	ZYZ_INFO* pInfo = NULL;
	FILE* fp = fopen(theApp.m_strModulePath + "failed.csv", "w+");
	if( fp == NULL )
	{
		MessageBox( "�����¼ʧ�ܣ����ļ�ʧ�ܣ�", _T("��ʾ"), MB_OK|MB_ICONINFORMATION);
		return FALSE;
	}
	fputs("���,����,���֤����,�绰,�Ա�,��¼�û���,ְҵ,��λ���\r\n", fp);
	CString strTmp;
	for(size_t i=0; i<size; i++)
	{
		pInfo = &(submit_list[i]);
		if( pInfo->success )
		{
			continue;
		}
		strTmp.Format("%d,%s,%s,%s,%s,%s,%s,%s\r\n", pInfo->index, pInfo->name, pInfo->idcard, pInfo->mobile, pInfo->sex, pInfo->username, pInfo->job, pInfo->dwcode);
		fputs(strTmp, fp);
	}
	fclose(fp);
	MessageBox( "������ϣ�", _T("��ʾ"), MB_OK|MB_ICONINFORMATION);
	return TRUE;
}

void CAutoSubmitDlg::SmartSleep(int minSeconds, int maxSeconds)
{
	int random = getRandomNumber(minSeconds, maxSeconds);
	Sleep(random * 1000);
}


void CAutoSubmitDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT ret = MessageBox( "ȷ���˳���", _T("��ʾ"), MB_YESNO|MB_ICONQUESTION);
	if( ret == IDYES )
	{
		if( m_bIsSubmiting )
		{
			AfxMessageBox(_T("��ǰ����δ���������Ժ��˳���"));
			return;
		}
		CDialog::OnClose();
	}
}

void CAutoSubmitDlg::OnBnClickedButtonSaveFailed()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SaveFailedList();
}
