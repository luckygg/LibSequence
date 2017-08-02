#pragma once

#include "FormThdSpl.h"
#include "FormThdDbl.h"
#include "FormThdAdt.h"
#include "FilterSimDlg.h"

// CFormImgThd form view

class CFormImgThd : public CFormView
{
	enum eMethod {ESimple=0, EDouble, EAdaptive, ENone};

	DECLARE_DYNCREATE(CFormImgThd)

protected:
	CFormImgThd();           // protected constructor used by dynamic creation
	virtual ~CFormImgThd();

public:
	enum { IDD = IDD_FORM_IMG_THRESHOLD };
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
	CView* m_pFormSpl;
	CView* m_pFormDbl;
	CView* m_pFormAdt;
	void FormSwitching(int nMethod);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedThdRBtnMethod(UINT ID);
};


