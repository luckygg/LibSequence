#pragma once

#include "Base.h"

// CFormImgArh form view

class CFormImgArh : public CFormView
{
	DECLARE_DYNCREATE(CFormImgArh)

protected:
	CFormImgArh();           // protected constructor used by dynamic creation
	virtual ~CFormImgArh();

public:
	enum { IDD = IDD_FORM_IMG_ARITHMETIC };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private :
	CRect m_wndRc;

public :
	void InitControls();
	void GetParameter(StLibrary &info);
	void SetParameter(StLibrary info);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public :
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeImgArhCbOper();
};


