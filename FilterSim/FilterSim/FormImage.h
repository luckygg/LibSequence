#pragma once

#include <vector>
#include "EImage.h"
#include "FormImgCvl.h"
#include "FormImgMpl.h"
#include "FormImgThd.h"
#include "FormImgArh.h"
#include "FormImgScl.h"
// CFormImg form view

class CFormImg : public CFormView
{
	enum eProcessing {EConvolution=0, EMorphology, EThreshold, EArith, EScale, EGain, ENone};

	DECLARE_DYNCREATE(CFormImg)

protected:
	CFormImg();           // protected constructor used by dynamic creation
	virtual ~CFormImg();

private :
	CView* m_pFormCvl;
	CView* m_pFormMpl;
	CView* m_pFormThd;
	CView* m_pFormArh;
	CView* m_pFormScl;
	void FormSwitching(eProcessing eType);

public :
	CRect m_wndRc;
	
	
	void InitControls();

	bool IsConvolution(CString strValue);
	bool IsMorphology(CString strValue);
	bool IsArtihemetic(CString strValue);
	bool IsThreshold(CString strValue);

	void GetParameter(StLibrary& info);
	void SetParameter(StLibrary info);
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
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnCbnSelchangeTab1CbProcessing();
};


