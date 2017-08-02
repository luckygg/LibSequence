// FormThdAdt.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormThdAdt.h"


// CFormThdAdt

IMPLEMENT_DYNCREATE(CFormThdAdt, CFormView)

CFormThdAdt::CFormThdAdt()
	: CFormView(CFormThdAdt::IDD)
	, m_rbtnMethod(0)
{

}

CFormThdAdt::~CFormThdAdt()
{
}

void CFormThdAdt::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_THD_ADT_RBTN_MEAN, m_rbtnMethod);
}

BEGIN_MESSAGE_MAP(CFormThdAdt, CFormView)
	ON_WM_SIZE()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_THD_ADT_RBTN_MEAN, IDC_THD_ADT_RBTN_MIDDLE, CFormThdAdt::OnBnClickedThdAdtRBtnMethod)
END_MESSAGE_MAP()


// CFormThdAdt diagnostics

#ifdef _DEBUG
void CFormThdAdt::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormThdAdt::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormThdAdt message handlers


void CFormThdAdt::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormThdAdt::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormThdAdt::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	InitControls();
}

void CFormThdAdt::InitControls()
{
	CheckRadioButton(IDC_THD_ADT_RBTN_MEAN, IDC_THD_ADT_RBTN_MIDDLE, IDC_THD_ADT_RBTN_MEAN);

	SetDlgItemInt(IDC_THD_ADT_EDIT_KERNEL, 1);

	SetDlgItemInt(IDC_THD_ADT_EDIT_OFFSET, 0);

	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_ADT_SPIN_KERNEL);
	pSpin->SetRange(0,255);
	pSpin->SetPos(1);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_ADT_SPIN_OFFSET);
	pSpin->SetRange(0,255);
	pSpin->SetPos(0);
}

void CFormThdAdt::GetParameter(StLibrary &info)
{
	int nKernel=0, nOffset=0;
	nKernel = GetDlgItemInt(IDC_THD_ADT_EDIT_KERNEL);
	nOffset = GetDlgItemInt(IDC_THD_ADT_EDIT_OFFSET);

	info.stImg.stThreshold.stAdaptive.nKernel = nKernel;
	info.stImg.stThreshold.stAdaptive.nOffset = nOffset;

	CString strMethod=_T("");
	switch (m_rbtnMethod)
	{
		case EMean	 : strMethod = _T("Mean"); break;
		case EMedian : strMethod = _T("Median"); break;
		case EMiddle : strMethod = _T("Middle"); break;
	}
	info.stImg.stThreshold.stAdaptive.strType = strMethod;
}

void CFormThdAdt::SetParameter(StLibrary info)
{
	SetDlgItemInt(IDC_THD_ADT_EDIT_KERNEL, info.stImg.stThreshold.stAdaptive.nKernel);
	SetDlgItemInt(IDC_THD_ADT_EDIT_OFFSET, info.stImg.stThreshold.stAdaptive.nOffset);

	if (info.stImg.stThreshold.stAdaptive.strType == _T("Mean"))
		CheckRadioButton(IDC_THD_ADT_RBTN_MEAN, IDC_THD_ADT_RBTN_MIDDLE, IDC_THD_ADT_RBTN_MEAN);
	else if (info.stImg.stThreshold.stAdaptive.strType == _T("Median"))
		CheckRadioButton(IDC_THD_ADT_RBTN_MEAN, IDC_THD_ADT_RBTN_MIDDLE, IDC_THD_ADT_RBTN_MEDIAN);
	else if (info.stImg.stThreshold.stAdaptive.strType == _T("Middle"))
		CheckRadioButton(IDC_THD_ADT_RBTN_MEAN, IDC_THD_ADT_RBTN_MIDDLE, IDC_THD_ADT_RBTN_MIDDLE);
}

void CFormThdAdt::OnBnClickedThdAdtRBtnMethod(UINT ID)
{
	UpdateData(TRUE);
}