// ListCombo.cpp : implementation file
//

#include "stdafx.h"
#include "ListCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
// CListCombo

IMPLEMENT_DYNAMIC(CListCombo, CComboBox)

CListCombo* CListCombo::m_pCombo = NULL; 

CListCombo::CListCombo()
{
	m_idxRow = -1;
	m_idxCol = -1;
	m_bESC	 = FALSE;
}

CListCombo::~CListCombo()
{
}


BEGIN_MESSAGE_MAP(CListCombo, CComboBox)
	ON_WM_CREATE()
	ON_WM_KILLFOCUS()
	ON_WM_CHAR()
	ON_CONTROL_REFLECT(CBN_CLOSEUP, OnCloseup)
END_MESSAGE_MAP()

// CListCombo message handlers


int CListCombo::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
	{
		return -1;
	}

	// Set the proper font
	CFont* pFont = GetParent()->GetFont();
	SetFont(pFont);

	SetFocus();

	ResetContent(); 
	
	for (POSITION Pos_ = m_DropDownList.GetHeadPosition(); Pos_ != NULL;)
	{
		AddString((LPCTSTR) (m_DropDownList.GetNext(Pos_)));
	}

	return 0;
}

BOOL CListCombo::PreTranslateMessage(MSG* pMsg) 
{
	// If the message if for "Enter" or "Esc"
	// Do not process
	if (pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
		{
			::TranslateMessage(pMsg);
			::DispatchMessage(pMsg);
			// DO NOT process further
			return TRUE;				
		}
	}

	return CComboBox::PreTranslateMessage(pMsg);
}

void CListCombo::OnKillFocus(CWnd* pNewWnd) 
{
	CComboBox::OnKillFocus(pNewWnd);

	// Get the current selection text
	CString str;
	GetWindowText(str);

	// Send Notification to parent of ListView ctrl
	LV_DISPINFO dispinfo;
	dispinfo.hdr.hwndFrom = GetParent()->m_hWnd;
	dispinfo.hdr.idFrom = GetDlgCtrlID();
	dispinfo.hdr.code = LVN_ENDLABELEDIT;

	dispinfo.item.mask = LVIF_TEXT;
	dispinfo.item.iItem = m_idxRow;
	dispinfo.item.iSubItem = m_idxCol;
	dispinfo.item.pszText = m_bESC ? LPTSTR((LPCTSTR)m_strWndText) : LPTSTR((LPCTSTR)str);
	dispinfo.item.cchTextMax = m_bESC ? m_strWndText.GetLength() : str.GetLength();

	GetParent()->SendMessage(WM_NOTIFY, GetParent()->GetDlgCtrlID(), (LPARAM)&dispinfo);

	// Close the control
	PostMessage(WM_CLOSE);
}

void CListCombo::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// If the key is "Esc" set focus back to the list control
	if (nChar == VK_ESCAPE || nChar == VK_RETURN)
	{
		if (nChar == VK_ESCAPE)
		{
			m_bESC = TRUE;
		}

		GetParent()->SetFocus();
		return;
	}

	CComboBox::OnChar(nChar, nRepCnt, nFlags);
}

void CListCombo::OnCloseup() 
{
	// Set the focus to the parent list control
	GetParent()->SetFocus();
}

CListCombo* CListCombo::GetInstance()
{
	if(m_pCombo == NULL)
	{
		m_pCombo = new CListCombo;
	}
	return m_pCombo;
}

void CListCombo::DeleteInstance()
{
	delete m_pCombo;
	m_pCombo = NULL;
}

BOOL CListCombo::OnShowCtrl(DWORD dwStyle, const CRect &rCellRect, CWnd* pParentWnd, UINT uiResourceID,
	int iRowIndex, int iColumnIndex, CStringList* pDropDownList, 
	CString strCurSelecetion /*= ""*/, int iCurSel /*= -1*/)
{

	m_idxRow = iRowIndex;
	m_idxCol = iColumnIndex;
	m_bESC = FALSE;

	m_DropDownList.RemoveAll(); 
	m_DropDownList.AddTail(pDropDownList);

	BOOL bRetVal = TRUE;

	if (-1 != iCurSel)
	{
		GetLBText(iCurSel, m_strWndText);
	}
	else if (!strCurSelecetion.IsEmpty()) 
	{
		m_strWndText = strCurSelecetion;
	}

	if (NULL == m_pCombo->m_hWnd) 
	{
		bRetVal = m_pCombo->Create(dwStyle, rCellRect, pParentWnd, uiResourceID); 
	}

	SetCurSel(iCurSel);

	return bRetVal;
}