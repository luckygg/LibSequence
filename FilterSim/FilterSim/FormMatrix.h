#pragma once



// CFormMtx form view

class CFormMtx : public CFormView
{
	DECLARE_DYNCREATE(CFormMtx)

protected:
	CFormMtx();           // protected constructor used by dynamic creation
	virtual ~CFormMtx();

private :
	CRect m_wndRc;
public:
	enum { IDD = IDD_FORM_MATRIX };
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
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


