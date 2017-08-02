// FormConvol.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormImgCvl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CFormImgCvl

IMPLEMENT_DYNCREATE(CFormImgCvl, CFormView)

CFormImgCvl::CFormImgCvl()
	: CFormView(CFormImgCvl::IDD)
{

}

CFormImgCvl::~CFormImgCvl()
{
}

void CFormImgCvl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormImgCvl, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CFormImgCvl diagnostics

#ifdef _DEBUG
void CFormImgCvl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImgCvl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImgCvl message handlers


void CFormImgCvl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormImgCvl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CFormImgCvl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_IMG_CVL_CB_PREKERNEL);
	pCB->AddString(_T("Uniform"));
	pCB->AddString(_T("Uniform3x3"));
	pCB->AddString(_T("Uniform5x5"));
	pCB->AddString(_T("Uniform7x7"));
	pCB->AddString(_T("Gaussian"));
	pCB->AddString(_T("Gaussian3x3"));
	pCB->AddString(_T("Gaussian5x5"));
	pCB->AddString(_T("Gaussian7x7"));
	pCB->AddString(_T("Lowpass1"));
	pCB->AddString(_T("Lowpass2"));
	pCB->AddString(_T("Highpass1"));
	pCB->AddString(_T("Highpass2"));
	pCB->AddString(_T("Gradient"));
	pCB->AddString(_T("GradientX"));
	pCB->AddString(_T("GradientY"));
	pCB->AddString(_T("Sobel"));
	pCB->AddString(_T("SobelX"));
	pCB->AddString(_T("SobelY"));
	pCB->AddString(_T("Prewitt"));
	pCB->AddString(_T("PrewittX"));
	pCB->AddString(_T("PrewittY"));
	pCB->AddString(_T("Roberts"));
	pCB->AddString(_T("LaplacianX"));
	pCB->AddString(_T("LaplacianY"));
	pCB->AddString(_T("Laplacian4"));
	pCB->AddString(_T("Laplacian8"));

	InitControls();
}

void CFormImgCvl::InitControls()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_IMG_CVL_CB_PREKERNEL);

	pCB->SetCurSel(-1);
}

void CFormImgCvl::GetParameter(StLibrary &info)
{
	CComboBox* pCB = NULL;
	CString strText=_T("");
	int sel=-1;

	pCB = (CComboBox*)GetDlgItem(IDC_IMG_CVL_CB_PREKERNEL);
	sel = pCB->GetCurSel();
	if (sel == -1) return;

	pCB->GetLBText(sel,strText);

	info.stImg.stConvolution.strType = strText;
}

void CFormImgCvl::SetParameter(StLibrary info)
{
	CComboBox* pCB = NULL;
	int sel=-1;
	CString strData=_T("");
	pCB = (CComboBox*)GetDlgItem(IDC_IMG_CVL_CB_PREKERNEL);

	strData = info.stImg.stConvolution.strType;

	sel = pCB->FindString(-1, strData);
	pCB->SetCurSel(sel);
}