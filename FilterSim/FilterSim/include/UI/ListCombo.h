#pragma once


// CListCombo

class CListCombo : public CComboBox
{
	DECLARE_DYNAMIC(CListCombo)

private :
	CListCombo();
	
	CListCombo (CListCombo&) {}
	
	CListCombo& operator = (CListCombo) {}

	virtual ~CListCombo();

	int m_idxRow;
	int m_idxCol;
	BOOL m_bESC;
	static CListCombo* m_pCombo;
	CString m_strWndText;
	CStringList m_DropDownList;

public :
	static CListCombo* GetInstance();
	static void DeleteInstance();

	BOOL OnShowCtrl(DWORD dwStyle, const CRect& rCellRect, CWnd* pParentWnd, UINT uiResourceID,
		int iRowIndex, int iColumnIndex, CStringList* pDropDownList, CString strCurSelecetion = _T(""), int iCurSel = -1);

	virtual BOOL PreTranslateMessage(MSG* pMsg);

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnCloseup();
	DECLARE_MESSAGE_MAP()
};


