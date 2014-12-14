
#pragma once

// EditListCtrl.h : header file
//
/////////////////////////////////////////////////////////////////////////////
//CItemEdit window

#define  ID_ITEM_EDIT 1001
#define  WM_LIST_VALUE_CHANAGED (WM_USER+0x03)

class CItemEdit : public CEdit
{
	// Construction
public:
	CItemEdit();
	
	// Attributes
public:
	
	// Operations
public:
	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CItemEdit)
	//}}AFX_VIRTUAL
	
	void SetParent(CWnd* pWnd);
	CString m_strText;
	int m_nItem;
	int m_nSubItem;

	CBrush   m_brush;
	COLORREF m_TextBkColor;
	COLORREF m_TextColor;

	CWnd* m_pParent;
	// Implementation
public:
	int m_iXPos;
	virtual ~CItemEdit();
	
	// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKillFocus(CWnd* pNewWnd);
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// CEditListCtrl window

typedef struct redraw_item_list_t
{
	int nItem;
	redraw_item_list_t* next;
}REDRAW_ITEMS;

typedef struct edit_col_list_t
{
	int nCol;
	edit_col_list_t* next;
}EDIT_COLS;

class CEditListCtrl : public CListCtrl
{
// Construction
public:
	CEditListCtrl();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditListCtrl)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL
	
// Implementation
public:
	virtual ~CEditListCtrl();

	HWND  m_parentWnd;
	int m_nEditCol;
	int m_nEditCol2;
	
	REDRAW_ITEMS* m_pRedrawItemListHead;
	REDRAW_ITEMS* m_pRedrawItemListTail;
	void ResetRedrawItemList();
	void AddRedrawItem(int nItem);
	BOOL IsRedrawItem(int nItem);

	EDIT_COLS* m_pEditColListHead;
	EDIT_COLS* m_pEditColListTail;
	void ResetEditColsList();
	void AddEditCol(int nCol);
	BOOL IsEditCol(int nCol);

	void ShowVerticalScrollBar(int oneRowHeight);
	void SendValueChangedMsg();
	// Generated message map functions
protected:
	//{{AFX_MSG(CEditListCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	DECLARE_MESSAGE_MAP()
private:
	int m_iSubItem;            //子项标识符
	int m_iItem;      //主项标识符
	CItemEdit m_edtItemEdit;   // 用于子类化EditLabel函数返回的CEdit*指针

public:
	BOOL m_bFocus;
public:
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

