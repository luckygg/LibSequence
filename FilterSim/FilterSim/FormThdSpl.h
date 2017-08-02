#pragma once

#include "Base.h"

// CFormThdSpl form view

class CFormThdSpl : public CFormView
{
	enum eMethod {EAbsolute=0, ERelative, EMinResidue, EMaxEntropy, EIsoData, ENone};

	DECLARE_DYNCREATE(CFormThdSpl)

protected:
	CFormThdSpl();           // protected constructor used by dynamic creation
	virtual ~CFormThdSpl();

public:
	enum { IDD = IDD_FORM_THD_SIMPLE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

public :
	void InitControls();

	void GetParameter(StLibrary &info);
	void SetParameter(StLibrary info);

private :
	int m_rbtnMethod;
	CRect m_wndRc;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnBnClickedThdSplRBtnMethod(UINT ID);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDeltaposThdSplSpinAbsolute(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


