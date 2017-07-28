// FormMorpho.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormMorpho.h"


// CFormMorpho

IMPLEMENT_DYNCREATE(CFormMorpho, CFormView)

CFormMorpho::CFormMorpho()
	: CFormView(CFormMorpho::IDD)
{
	m_rbtnOper = 0;
}

CFormMorpho::~CFormMorpho()
{
}

void CFormMorpho::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_MPL_RBTN_ERODE, (int &)m_rbtnOper);
}

BEGIN_MESSAGE_MAP(CFormMorpho, CFormView)
	ON_WM_SIZE()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_MPL_RBTN_ERODE, IDC_MPL_RBTN_MEDIAN3X3, CFormMorpho::OnBnClickedMplRBtnOperation)
END_MESSAGE_MAP()


// CFormMorpho diagnostics

#ifdef _DEBUG
void CFormMorpho::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormMorpho::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormMorpho message handlers
void CFormMorpho::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormMorpho::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CFormMorpho::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CheckDlgButton(IDC_MPL_RBTN_ERODE, 1);

	SetDlgItemInt(IDC_MPL_EDIT_HALFKERNEL, 1);

	CSpinButtonCtrl* pSpCtrl = (CSpinButtonCtrl*)GetDlgItem(IDC_MPL_SPIN_HALFKERNEL);
	pSpCtrl->SetRange(0,255);
	pSpCtrl->SetPos(0);
}

void CFormMorpho::OnBnClickedMplRBtnOperation(UINT ID)
{
	UpdateData(TRUE);


}

CString CFormMorpho::GetTextSelectedOper()
{
	CString strOper=_T("");
	switch(m_rbtnOper)
	{
		case 0 : strOper = _T("Erode");			break;
		case 1 : strOper = _T("Dilate");		break;
		case 2 : strOper = _T("Open");			break;
		case 3 : strOper = _T("Close");			break;
		case 4 : strOper = _T("White Top Hat"); break;
		case 5 : strOper = _T("Black Top Hat"); break;
		case 6 : strOper = _T("Morpho Gradient");break;
		case 7 : strOper = _T("Median 3x3");	break;
	}

	return strOper;
}

void CFormMorpho::SetSelectOperByText(CString strData)
{
	if (strData == _T("Erode"))
		CheckDlgButton(IDC_MPL_RBTN_ERODE, 1);
	else if (strData == _T("Dilate"))
		CheckDlgButton(IDC_MPL_RBTN_DILATE, 1);
	else if (strData == _T("Open"))
		CheckDlgButton(IDC_MPL_RBTN_OPEN, 1);
	else if (strData == _T("Close"))
		CheckDlgButton(IDC_MPL_RBTN_CLOSE, 1);
	else if (strData == _T("White Top Hat"))
		CheckDlgButton(IDC_MPL_RBTN_WTHAT, 1);
	else if (strData == _T("Black Top Hat"))
		CheckDlgButton(IDC_MPL_RBTN_BTHAT, 1);
	else if (strData == _T("Gradient"))
		CheckDlgButton(IDC_MPL_RBTN_GRADIENT, 1);
	else if (strData == _T("Median 3x3"))
		CheckDlgButton(IDC_MPL_RBTN_MEDIAN3X3, 1);
}

int CFormMorpho::GetHalfKernel()
{
	CSpinButtonCtrl* pSpCtrl = (CSpinButtonCtrl*)GetDlgItem(IDC_MPL_SPIN_HALFKERNEL);
	if (pSpCtrl == NULL) return -1;

	return pSpCtrl->GetPos();
}

void CFormMorpho::SetHalfKernel(int nHalfKernel)
{
	CSpinButtonCtrl* pSpCtrl = (CSpinButtonCtrl*)GetDlgItem(IDC_MPL_SPIN_HALFKERNEL);
	if (pSpCtrl == NULL) return;

	pSpCtrl->SetPos(nHalfKernel);
}