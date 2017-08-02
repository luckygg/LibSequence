// FormThdDbl.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormThdDbl.h"


// CFormThdDbl

IMPLEMENT_DYNCREATE(CFormThdDbl, CFormView)

CFormThdDbl::CFormThdDbl()
	: CFormView(CFormThdDbl::IDD)
{

}

CFormThdDbl::~CFormThdDbl()
{
}

void CFormThdDbl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormThdDbl, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CFormThdDbl diagnostics

#ifdef _DEBUG
void CFormThdDbl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormThdDbl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormThdDbl message handlers


void CFormThdDbl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormThdDbl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormThdDbl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	InitControls();
}

void CFormThdDbl::InitControls()
{
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_PXLHIGH);
	pSpin->SetRange(0,255);
	pSpin->SetPos(255);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_THDHIGH);
	pSpin->SetRange(0,255);
	pSpin->SetPos(200);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_PXLBTW);
	pSpin->SetRange(0,255);
	pSpin->SetPos(128);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_THDLOW);
	pSpin->SetRange(0,255);
	pSpin->SetPos(100);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_PXLLOW);
	pSpin->SetRange(0,255);
	pSpin->SetPos(0);
}

void CFormThdDbl::GetParameter(StLibrary &info)
{
	int nPxlHigh=0, nPxlMid=0, nPxlLow=0, nThdHigh=0, nThdLow=0;
	nPxlHigh = GetDlgItemInt(IDC_THD_DBL_EDIT_PXLHIGH);
	nPxlMid = GetDlgItemInt(IDC_THD_DBL_EDIT_PXLBTW);
	nPxlLow = GetDlgItemInt(IDC_THD_DBL_EDIT_PXLLOW);
	nThdHigh = GetDlgItemInt(IDC_THD_DBL_EDIT_THDHIGH);
	nThdLow = GetDlgItemInt(IDC_THD_DBL_EDIT_THDLOW);

	info.stImg.stThreshold.stDouble.nPxlHigh = nPxlHigh;
	info.stImg.stThreshold.stDouble.nPxlMid = nPxlMid;
	info.stImg.stThreshold.stDouble.nPxlLow = nPxlLow;
	info.stImg.stThreshold.stDouble.nThdHigh = nThdHigh;
	info.stImg.stThreshold.stDouble.nThdLow = nThdLow;
}

void CFormThdDbl::SetParameter(StLibrary info)
{
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_PXLHIGH);
	pSpin->SetPos(255);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_THDHIGH);
	pSpin->SetPos(200);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_PXLBTW);
	pSpin->SetPos(128);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_THDLOW);
	pSpin->SetPos(100);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_DBL_SPIN_PXLLOW);
	pSpin->SetPos(0);

	SetDlgItemInt(IDC_THD_DBL_EDIT_PXLHIGH	,info.stImg.stThreshold.stDouble.nPxlHigh);
	SetDlgItemInt(IDC_THD_DBL_EDIT_PXLBTW	,info.stImg.stThreshold.stDouble.nPxlMid );
	SetDlgItemInt(IDC_THD_DBL_EDIT_PXLLOW	,info.stImg.stThreshold.stDouble.nPxlLow );
	SetDlgItemInt(IDC_THD_DBL_EDIT_THDHIGH	,info.stImg.stThreshold.stDouble.nThdHigh);
	SetDlgItemInt(IDC_THD_DBL_EDIT_THDLOW	,info.stImg.stThreshold.stDouble.nThdLow );
}