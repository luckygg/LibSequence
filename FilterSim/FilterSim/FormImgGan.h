#pragma once

#include "Base.h"

// CFormImgGan form view

class CFormImgGan : public CFormView
{
	DECLARE_DYNCREATE(CFormImgGan)

protected:
	CFormImgGan();           // protected constructor used by dynamic creation
	virtual ~CFormImgGan();

public:
	enum { IDD = IDD_FORM_IMG_GAINOFFSET };
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
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};


