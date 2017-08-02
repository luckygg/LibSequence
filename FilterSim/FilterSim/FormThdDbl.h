#pragma once

#include "Base.h"

// CFormThdDbl form view

class CFormThdDbl : public CFormView
{
	DECLARE_DYNCREATE(CFormThdDbl)

protected:
	CFormThdDbl();           // protected constructor used by dynamic creation
	virtual ~CFormThdDbl();

public:
	enum { IDD = IDD_FORM_THD_DOUBLE };
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
	CRect m_wndRc;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
};


