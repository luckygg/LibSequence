// FormMorpho.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormImgMpl.h"


// CFormImgMpl

IMPLEMENT_DYNCREATE(CFormImgMpl, CFormView)

CFormImgMpl::CFormImgMpl()
	: CFormView(CFormImgMpl::IDD)
{
	m_rbtnOper = 0;
}

CFormImgMpl::~CFormImgMpl()
{
}

void CFormImgMpl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_IMG_MPL_RBTN_ERODE, (int &)m_rbtnOper);
}

BEGIN_MESSAGE_MAP(CFormImgMpl, CFormView)
	ON_WM_SIZE()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, CFormImgMpl::OnBnClickedMplRBtnOperation)
END_MESSAGE_MAP()


// CFormImgMpl diagnostics

#ifdef _DEBUG
void CFormImgMpl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImgMpl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImgMpl message handlers
void CFormImgMpl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormImgMpl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CFormImgMpl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	InitControls();
}

void CFormImgMpl::OnBnClickedMplRBtnOperation(UINT ID)
{
	UpdateData(TRUE);

	if (ID == IDC_IMG_MPL_RBTN_MEDIAN3X3)
	{
		GetDlgItem(IDC_IMG_MPL_EDIT_HALFKERNEL)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_MPL_SPIN_HALFKERNEL)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_IMG_MPL_EDIT_HALFKERNEL)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_MPL_SPIN_HALFKERNEL)->EnableWindow(TRUE);
	}
}

void CFormImgMpl::InitControls()
{
	CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_ERODE);

	SetDlgItemInt(IDC_IMG_MPL_EDIT_HALFKERNEL, 1);

	CSpinButtonCtrl* pSpCtrl = (CSpinButtonCtrl*)GetDlgItem(IDC_IMG_MPL_SPIN_HALFKERNEL);
	pSpCtrl->SetRange(0,255);
	pSpCtrl->SetPos(1);
}

void CFormImgMpl::GetParameter(StLibrary &info)
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

	info.stImg.stMorphology.strType = strOper;

	CSpinButtonCtrl* pSpCtrl = (CSpinButtonCtrl*)GetDlgItem(IDC_IMG_MPL_SPIN_HALFKERNEL);

	info.stImg.stMorphology.nHalfKernel = pSpCtrl->GetPos();
}

void CFormImgMpl::SetParameter(StLibrary info)
{
	CString strOper=_T("");

	strOper = info.stImg.stMorphology.strType;
	if (strOper == _T("Erode"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_ERODE);
	else if (strOper == _T("Dilate"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_DILATE);
	else if (strOper == _T("Open"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_OPEN);
	else if (strOper == _T("Close"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_CLOSE);
	else if (strOper == _T("White Top Hat"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_WTHAT);
	else if (strOper == _T("Black Top Hat"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_BTHAT);
	else if (strOper == _T("Morpho Gradient"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_GRADIENT);
	else if (strOper == _T("Median 3x3"))
		CheckRadioButton(IDC_IMG_MPL_RBTN_ERODE, IDC_IMG_MPL_RBTN_MEDIAN3X3, IDC_IMG_MPL_RBTN_MEDIAN3X3);

	CSpinButtonCtrl* pSpCtrl = (CSpinButtonCtrl*)GetDlgItem(IDC_IMG_MPL_SPIN_HALFKERNEL);

	pSpCtrl->SetPos(info.stImg.stMorphology.nHalfKernel);
}