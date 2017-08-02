#pragma once

#include "Base.h"

// CFormThdAdt form view

class CFormThdAdt : public CFormView
{
	enum eMethod {EMean=0, EMedian, EMiddle, ENone};

	DECLARE_DYNCREATE(CFormThdAdt)

protected:
	CFormThdAdt();           // protected constructor used by dynamic creation
	virtual ~CFormThdAdt();

public:
	enum { IDD = IDD_FORM_THD_ADAPTIVE };
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
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnBnClickedThdAdtRBtnMethod(UINT ID);
	virtual void OnInitialUpdate();
};


