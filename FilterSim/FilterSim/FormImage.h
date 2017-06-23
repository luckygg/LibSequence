#pragma once

#include <vector>
#include "EImage.h"

// CFormImg form view

class CFormImg : public CFormView
{
	DECLARE_DYNCREATE(CFormImg)

protected:
	CFormImg();           // protected constructor used by dynamic creation
	virtual ~CFormImg();

public :
	CRect m_wndRc;
	void UpdateControls(StItemInfo info);
	void ResetControls();
	CString GetTextCBSelectedType();
public:
	enum { IDD = IDD_FORM_IMAGE };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
};


