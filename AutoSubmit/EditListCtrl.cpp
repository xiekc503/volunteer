// EditListCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "EditListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditListCtrl

CEditListCtrl::CEditListCtrl()
{
	m_iItem = -1;
	m_iSubItem = -1;
	m_nEditCol = -1;
	m_nEditCol2 = -1;
	m_parentWnd = NULL;
	m_bFocus = FALSE;
	m_pRedrawItemListHead = NULL;
	m_pRedrawItemListTail = NULL;
	m_pEditColListHead = NULL;
	m_pEditColListTail = NULL;
}

CEditListCtrl::~CEditListCtrl()
{
	ResetRedrawItemList();
	ResetEditColsList();
}

void CEditListCtrl::ResetRedrawItemList()
{
	if( m_pRedrawItemListHead )
	{
		while( m_pRedrawItemListHead != NULL )
		{
			m_pRedrawItemListTail = m_pRedrawItemListHead;
			m_pRedrawItemListHead = m_pRedrawItemListHead->next;
			delete m_pRedrawItemListTail;
			m_pRedrawItemListTail = NULL;
		}
	}
	m_pRedrawItemListHead = m_pRedrawItemListTail = NULL;
}

void CEditListCtrl::AddRedrawItem(int nItem)
{
	REDRAW_ITEMS* pTemp = m_pRedrawItemListHead;
	if( nItem >= 0 )
	{
		while( pTemp != NULL )
		{
			if( pTemp->nItem == nItem )
			{
				return;
			}
			pTemp = pTemp->next;
		}
		pTemp = new REDRAW_ITEMS;
		memset(pTemp, 0, sizeof(REDRAW_ITEMS));
		pTemp->nItem = nItem;
		if( m_pRedrawItemListHead == NULL )
		{
			m_pRedrawItemListHead = m_pRedrawItemListTail = pTemp;
		}
		else
		{
			m_pRedrawItemListTail->next = pTemp;
			m_pRedrawItemListTail = pTemp;
		}
	}
}

BOOL CEditListCtrl::IsRedrawItem(int nItem)
{
	REDRAW_ITEMS* pTemp = m_pRedrawItemListHead;
	while( pTemp != NULL )
	{
		if( pTemp->nItem == nItem )
		{
			return TRUE;
		}
		pTemp = pTemp->next;
	}
	return FALSE;
}

void CEditListCtrl::ResetEditColsList()
{
	if( m_pEditColListHead )
	{
		while( m_pEditColListHead != NULL )
		{
			m_pEditColListTail = m_pEditColListHead;
			m_pEditColListHead = m_pEditColListHead->next;
			delete m_pEditColListTail;
			m_pEditColListTail = NULL;
		}
	}
	m_pEditColListHead = m_pEditColListTail = NULL;
}

void CEditListCtrl::AddEditCol(int nCol)
{
	EDIT_COLS* pTemp = m_pEditColListHead;
	if( nCol >= 0 )
	{
		while( pTemp != NULL )
		{
			if( pTemp->nCol == nCol )
			{
				return;
			}
			pTemp = pTemp->next;
		}
		pTemp = new EDIT_COLS;
		memset(pTemp, 0, sizeof(EDIT_COLS));
		pTemp->nCol = nCol;
		if( m_pEditColListHead == NULL )
		{
			m_pEditColListHead = m_pEditColListTail = pTemp;
		}
		else
		{
			m_pEditColListTail->next = pTemp;
			m_pEditColListTail = pTemp;
		}
	}
}

BOOL CEditListCtrl::IsEditCol(int nCol)
{
	EDIT_COLS* pTemp = m_pEditColListHead;
	while( pTemp != NULL )
	{
		if( pTemp->nCol == nCol )
		{
			return TRUE;
		}
		pTemp = pTemp->next;
	}
	return FALSE;
}

void CEditListCtrl::ShowVerticalScrollBar(int oneRowHeight)
{
	CSize size;
	size.cx = 0;
	size.cy = oneRowHeight;
	Scroll(size);
	size.cy = oneRowHeight*-1;
	Scroll(size);
}

BEGIN_MESSAGE_MAP(CEditListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CEditListCtrl)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditListCtrl message handlers

void CEditListCtrl::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CListCtrl::OnLButtonDown(nFlags, point);

	LVHITTESTINFO  lvhit;
	lvhit.pt = point;
	SubItemHitTest(&lvhit);
	m_iItem = lvhit.iItem;
	m_iSubItem = lvhit.iSubItem;
	if( !IsEditCol(m_iSubItem))
	{
		return;
	}
	if (lvhit.flags & LVHT_ONITEMLABEL)
	{
		CRect rectCell;
		GetSubItemRect(m_iItem, m_iSubItem, LVIR_BOUNDS, rectCell);
		m_edtItemEdit.m_nItem = m_iItem;
		m_edtItemEdit.m_nSubItem = m_iSubItem;
		m_edtItemEdit.m_strText = GetItemText(m_iItem, m_iSubItem);
		m_edtItemEdit.MoveWindow(&rectCell, TRUE);
		m_edtItemEdit.SetFocus();
		//m_edtItemEdit.CreateSolidCaret(1, rectCell.Height()-5);//创建一个光标
		//m_edtItemEdit.ShowCaret();//显示光标
		m_edtItemEdit.SetSel(0, -1);
		m_edtItemEdit.ShowWindow(SW_SHOW);
	}
}


void CEditListCtrl::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{
	//draw each item.set txt color,bkcolor....
	NMLVCUSTOMDRAW* pNMLVCustomDraw = (NMLVCUSTOMDRAW*)pNMHDR;
	int nRow = (int)pNMLVCustomDraw->nmcd.dwItemSpec;

	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;
	
	// First thing - check the draw stage. If it's the control's prepaint
	// stage, then tell Windows we want messages for every item.
	
	if (pNMLVCustomDraw->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMLVCustomDraw->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
		// This is the notification message for an item.  We'll request
		// notifications before each subitem's prepaint stage.
		if(IsRedrawItem(nRow) )
		{
			pNMLVCustomDraw->clrText   = RGB(0xFF,0x00,0x00);
		}
		else
		{
			pNMLVCustomDraw->clrText   = RGB(0x00,0x00,0x00);
		}
		if(nRow & 1)   // 单行
		{
			pNMLVCustomDraw->clrTextBk = RGB(0xFF,0xFF,0xFF);
			*pResult          = CDRF_NEWFONT; 
		}
		else
		{
			pNMLVCustomDraw->clrTextBk = RGB(0xF0,0xF4,0xF7);
			*pResult          = CDRF_NEWFONT;
		}

		if( GetItemState(nRow, CDIS_SELECTED) )
		{  
			pNMLVCustomDraw->nmcd.uItemState = CDIS_SELECTED;
			pNMLVCustomDraw->clrTextBk = RGB(221, 243, 254);
			pNMLVCustomDraw->clrText   = RGB(0, 0, 0);    
			*pResult = CDRF_NEWFONT;
		}
		 
	}
}


void CEditListCtrl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CListCtrl::OnHScroll(nSBCode, nPos, pScrollBar);
	if( m_bFocus )
	{
		CRect rectCell;
		GetSubItemRect(m_iItem, m_iSubItem, LVIR_BOUNDS, rectCell);
		m_edtItemEdit.m_nItem = m_iItem;
		m_edtItemEdit.m_nSubItem = m_iSubItem;
		m_edtItemEdit.m_strText = GetItemText(m_iItem, m_iSubItem);
		m_edtItemEdit.MoveWindow(&rectCell, TRUE);
		m_edtItemEdit.SetFocus();
		//m_edtItemEdit.CreateSolidCaret(1, rectCell.Height()-5);//创建一个光标
		//m_edtItemEdit.ShowCaret();//显示光标
		m_edtItemEdit.SetSel(0, -1);
		m_edtItemEdit.ShowWindow(SW_SHOW);
		Invalidate();
	}
}

void CEditListCtrl::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CListCtrl::OnVScroll(nSBCode, nPos, pScrollBar);
	if( m_bFocus )
	{
		CRect rectCell;
		GetSubItemRect(m_iItem, m_iSubItem, LVIR_BOUNDS, rectCell);
		//TRACE(" %d %d %d %d\n", rectCell.left, rectCell.top, rectCell.right, rectCell.bottom);
		m_edtItemEdit.m_nItem = m_iItem;
		m_edtItemEdit.m_nSubItem = m_iSubItem;
		m_edtItemEdit.m_strText = GetItemText(m_iItem, m_iSubItem);
		m_edtItemEdit.MoveWindow(&rectCell, TRUE);
		m_edtItemEdit.SetFocus();
		//m_edtItemEdit.CreateSolidCaret(1, rectCell.Height()-5);//创建一个光标
		//m_edtItemEdit.ShowCaret();//显示光标
		m_edtItemEdit.SetSel(0, -1);
		m_edtItemEdit.ShowWindow(SW_SHOW);
		Invalidate();
	}
}


BOOL CEditListCtrl::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if( m_bFocus )
	{
		CRect rectCell;
		GetSubItemRect(m_iItem, m_iSubItem, LVIR_BOUNDS, rectCell);
		//TRACE(" %d %d %d %d\n", rectCell.left, rectCell.top, rectCell.right, rectCell.bottom);
		m_edtItemEdit.m_nItem = m_iItem;
		m_edtItemEdit.m_nSubItem = m_iSubItem;
		m_edtItemEdit.m_strText = GetItemText(m_iItem, m_iSubItem);
		m_edtItemEdit.MoveWindow(&rectCell, TRUE);
		m_edtItemEdit.SetFocus();
		//m_edtItemEdit.CreateSolidCaret(1, rectCell.Height()-5);//创建一个光标
		//m_edtItemEdit.ShowCaret();//显示光标
		m_edtItemEdit.SetSel(0, -1);
		m_edtItemEdit.ShowWindow(SW_SHOW);
		Invalidate();
	}
	return CListCtrl::OnMouseWheel(nFlags, zDelta, pt);
}


void CEditListCtrl::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_edtItemEdit.Create(WS_CHILD|WS_CLIPSIBLINGS|WS_EX_TOOLWINDOW|WS_BORDER,
		CRect(0,40,10,50), this, ID_ITEM_EDIT);
	m_edtItemEdit.SetParent(this);
	CListCtrl::PreSubclassWindow();
}

void CEditListCtrl::SendValueChangedMsg()
{
	if( m_parentWnd )
	{
		::PostMessage(m_parentWnd, WM_LIST_VALUE_CHANAGED, (WPARAM)m_iItem, (LPARAM)m_iSubItem);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CItemEdit

CItemEdit::CItemEdit()
{
	m_TextBkColor = RGB(255,255,0);
	m_TextColor = RGB(255,0, 2555);
	m_brush.CreateSolidBrush(m_TextBkColor);
}

CItemEdit::~CItemEdit()
{
}


BEGIN_MESSAGE_MAP(CItemEdit, CEdit)
    //{{AFX_MSG_MAP(CItemEdit)
    //}}AFX_MSG_MAP
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_CTLCOLOR()
	ON_WM_CHAR()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CItemEdit message handlers

void CItemEdit::OnKillFocus(CWnd* pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);

	// TODO: 在此处添加消息处理程序代码
	CString strTmp;
	GetWindowText(strTmp);
	((CEditListCtrl*)m_pParent)->SetItemText(m_nItem, m_nSubItem, strTmp);
	((CEditListCtrl*)m_pParent)->m_bFocus = FALSE;
	ShowWindow(SW_HIDE);
	if( strTmp.CompareNoCase(m_strText) != 0 )
	{
		((CEditListCtrl*)m_pParent)->SendValueChangedMsg();
	}
}

void CItemEdit::OnSetFocus(CWnd* pOldWnd)
{
	CEdit::OnSetFocus(pOldWnd);

	((CEditListCtrl*)m_pParent)->m_bFocus = TRUE;
	// TODO: 在此处添加消息处理程序代码
	SetWindowText(m_strText);
}

HBRUSH CItemEdit::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CEdit::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	HBRUSH   hbr;
	pDC->SetTextColor(m_TextColor);
	pDC->SetBkColor(m_TextBkColor);
	hbr   =   (HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void CItemEdit::SetParent(CWnd* pWnd)
{
	m_pParent = pWnd;
}


void CItemEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if( nChar == '-' || nChar == '.' || (nChar>='0'&&nChar<='9') || nChar == 8 || nChar == 127)
	{
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
}
