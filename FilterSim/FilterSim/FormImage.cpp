// FormTab1.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FilterSimDlg.h"
#include "FormImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CFormImg

IMPLEMENT_DYNCREATE(CFormImg, CFormView)

CFormImg::CFormImg()
	: CFormView(CFormImg::IDD)
{

}

CFormImg::~CFormImg()
{
}

void CFormImg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormImg, CFormView)
END_MESSAGE_MAP()


// CFormImg diagnostics

#ifdef _DEBUG
void CFormImg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImg message handlers


void CFormImg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	this->MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
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
}

void CFormImg::UpdateControls(StItemInfo info)
{
	CComboBox* pCB = NULL;
	int sel=-1;
	
	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
	sel = pCB->FindString(-1, info.strType);
	pCB->SetCurSel(sel);
}

void CFormImg::ResetControls()
{
	CComboBox* pCB = NULL;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
	pCB->SetCurSel(-1);
}

CString CFormImg::GetTextCBSelectedType()
{
	CComboBox* pCB = NULL;
	CString strText=_T("");
	int sel=-1;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
	sel = pCB->GetCurSel();
	if (sel == -1) return _T("");
	
	pCB->GetLBText(sel,strText);

	return strText;
}

BOOL CFormImg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
