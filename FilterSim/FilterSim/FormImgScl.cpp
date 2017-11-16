// FormImgScl.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormImgScl.h"


// CFormImgScl

IMPLEMENT_DYNCREATE(CFormImgScl, CFormView)

CFormImgScl::CFormImgScl()
	: CFormView(CFormImgScl::IDD)
	, m_rbtnMode(0)
{

}

CFormImgScl::~CFormImgScl()
{
}

void CFormImgScl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_IMG_SCL_RBTN_SRCPIVOT, m_rbtnMode);
}

BEGIN_MESSAGE_MAP(CFormImgScl, CFormView)
	ON_WM_SIZE()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, CFormImgScl::OnBnClickedSclRBtnMode)
END_MESSAGE_MAP()


// CFormImgScl diagnostics

#ifdef _DEBUG
void CFormImgScl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImgScl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImgScl message handlers


void CFormImgScl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}

BOOL CFormImgScl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormImgScl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_IMG_SCL_CB_BITS);
	pCB->AddString(_T("0"));
	pCB->AddString(_T("4"));
	pCB->AddString(_T("8"));
	pCB->SetCurSel(0);

	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEX, _T("1.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEY, _T("1.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTX, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTY, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTX, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTY, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEANGLE, _T("0.0"));
}

void CFormImgScl::OnBnClickedSclRBtnMode(UINT ID)
{
	UpdateData(TRUE);

	switch (m_rbtnMode)
	{
	case 0 :
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEX		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEY		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEANGLE	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTX	)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTY	)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTY	)->EnableWindow(FALSE);
		break;
	case 1 :
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEX		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEY		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEANGLE	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTY	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTX	)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTY	)->EnableWindow(TRUE);
		break;
	case 2 :
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEX		)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEY		)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEANGLE	)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTY	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTY	)->EnableWindow(FALSE);
		break;
	case 3 :
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEX		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEY		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEANGLE	)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTY	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTY	)->EnableWindow(FALSE);
		break;
	case 4 :
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEX		)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEY		)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEANGLE	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTY	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTY	)->EnableWindow(FALSE);
		break;
	case 5 :
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEX		)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEY		)->EnableWindow(TRUE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SCALEANGLE	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_SRCPIVOTY	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTX	)->EnableWindow(FALSE);
		GetDlgItem(IDC_IMG_SCL_EDIT_DSTPIVOTY	)->EnableWindow(FALSE);
		break;
	}
}

void CFormImgScl::InitControls()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_IMG_SCL_CB_BITS);
	pCB->SetCurSel(0);

	CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_SRCPIVOT);

	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEX, _T("1.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEY, _T("1.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTX, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTY, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTX, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTY, _T("0.0"));
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEANGLE, _T("0.0"));
}

void CFormImgScl::GetParameter(StLibrary &info)
{
	CString strMode=_T("");
	switch(m_rbtnMode)
	{
	case 0 : strMode = _T("Src Pivot");			break;
	case 1 : strMode = _T("Dst Pivot");			break;
	case 2 : strMode = _T("Scale & Rotate");	break;
	case 3 : strMode = _T("Rotate");			break;
	case 4 : strMode = _T("Scale");				break;
	case 5 : strMode = _T("Scale Anisotrpoic"); break;
	}

	info.stImg.stScale.strType = strMode;

	CComboBox* pCB = NULL;
	CString strText=_T("");
	int sel=-1;

	pCB = (CComboBox*)GetDlgItem(IDC_IMG_SCL_CB_BITS);
	sel = pCB->GetCurSel();
	if (sel == -1) return;

	pCB->GetLBText(sel,strText);

	info.stImg.stScale.nBits = _ttoi(strText);

	GetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTX, strText);
	info.stImg.stScale.fSrcPvtX = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTY, strText);
	info.stImg.stScale.fSrcPvtY = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTX, strText);
	info.stImg.stScale.fDstPvtX = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTY, strText);
	info.stImg.stScale.fDstPvtY = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_SCL_EDIT_SCALEX, strText);
	info.stImg.stScale.fScaleX = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_SCL_EDIT_SCALEY, strText);
	info.stImg.stScale.fScaleY = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_SCL_EDIT_SCALEANGLE, strText);
	info.stImg.stScale.fAngle = (float)_ttof(strText);
}

void CFormImgScl::SetParameter(StLibrary info)
{
	CString strMode=_T("");

	strMode = info.stImg.stScale.strType;
	if (strMode == _T("Src Pivot"))
		CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_SRCPIVOT);
	else if (strMode == _T("Dst Pivot"))
		CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_DSTPIVOT);
	else if (strMode == _T("Scale & Rotate"))
		CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_SCLROT);
	else if (strMode == _T("Rotate"))
		CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_ROT);
	else if (strMode == _T("Scale"))
		CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_SCL);
	else if (strMode == _T("Scale Anisotrpoic"))
		CheckRadioButton(IDC_IMG_SCL_RBTN_SRCPIVOT, IDC_IMG_SCL_RBTN_SCLANISO, IDC_IMG_SCL_RBTN_SCLANISO);

	OnBnClickedSclRBtnMode(IDC_IMG_SCL_RBTN_SRCPIVOT);

	CComboBox* pCB = NULL;
	int sel=-1;
	CString strText=_T("");
	pCB = (CComboBox*)GetDlgItem(IDC_IMG_SCL_CB_BITS);

	strText.Format(_T("%d"), info.stImg.stScale.nBits);

	sel = pCB->FindString(-1, strText);
	pCB->SetCurSel(sel);

	strText.Format(_T("%.2f"), info.stImg.stScale.fSrcPvtX);
	SetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTX, strText);
	strText.Format(_T("%.2f"), info.stImg.stScale.fSrcPvtY);
	SetDlgItemText(IDC_IMG_SCL_EDIT_SRCPIVOTY, strText);
	strText.Format(_T("%.2f"), info.stImg.stScale.fDstPvtX);
	SetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTX, strText);
	strText.Format(_T("%.2f"), info.stImg.stScale.fDstPvtY);
	SetDlgItemText(IDC_IMG_SCL_EDIT_DSTPIVOTY, strText);
	strText.Format(_T("%.2f"), info.stImg.stScale.fScaleX);
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEX, strText);
	strText.Format(_T("%.2f"), info.stImg.stScale.fScaleY);
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEY, strText);
	strText.Format(_T("%.2f"), info.stImg.stScale.fAngle);
	SetDlgItemText(IDC_IMG_SCL_EDIT_SCALEANGLE, strText);
}