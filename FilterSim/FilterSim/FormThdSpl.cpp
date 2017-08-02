// FormThdSpl.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormThdSpl.h"


// CFormThdSpl

IMPLEMENT_DYNCREATE(CFormThdSpl, CFormView)

CFormThdSpl::CFormThdSpl()
	: CFormView(CFormThdSpl::IDD)
	, m_rbtnMethod(0)
{

}

CFormThdSpl::~CFormThdSpl()
{
}

void CFormThdSpl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_THD_SPL_RBTN_ABSOLUTE, m_rbtnMethod);
}

BEGIN_MESSAGE_MAP(CFormThdSpl, CFormView)
	ON_WM_SIZE()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, CFormThdSpl::OnBnClickedThdSplRBtnMethod)
	ON_WM_HSCROLL()
	ON_NOTIFY(UDN_DELTAPOS, IDC_THD_SPL_SPIN_ABSOLUTE, &CFormThdSpl::OnDeltaposThdSplSpinAbsolute)
END_MESSAGE_MAP()


// CFormThdSpl diagnostics

#ifdef _DEBUG
void CFormThdSpl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormThdSpl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormThdSpl message handlers


void CFormThdSpl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


void CFormThdSpl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	InitControls();
}


BOOL CFormThdSpl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CFormThdSpl::InitControls()
{
	CheckRadioButton(IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, IDC_THD_SPL_RBTN_ABSOLUTE);

	SetDlgItemInt(IDC_THD_SPL_EDIT_ABSOLUTE, 128);
	SetDlgItemInt(IDC_THD_SPL_EDIT_RELATIVE,  50);

	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE);
	pSpin->SetRange(0,255);
	pSpin->SetPos(128);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_RELATIVE);
	pSpin->SetRange(0,100);
	pSpin->SetPos(50);

	CSliderCtrl* pSld = (CSliderCtrl*)GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE);
	pSld->SetRange(0, 255);	
	pSld->SetPos(128);

	GetDlgItem(IDC_THD_SPL_EDIT_RELATIVE)->EnableWindow(FALSE);
	GetDlgItem(IDC_THD_SPL_SPIN_RELATIVE)->EnableWindow(FALSE);
}

void CFormThdSpl::GetParameter(StLibrary &info)
{
	int nAbs=0, nRel;
	nAbs = GetDlgItemInt(IDC_THD_SPL_EDIT_ABSOLUTE);
	nRel = GetDlgItemInt(IDC_THD_SPL_EDIT_RELATIVE);

	info.stImg.stThreshold.stSimple.nAbs = nAbs;
	info.stImg.stThreshold.stSimple.nRel = nRel;

	CString strMethod=_T("");
	switch (m_rbtnMethod)
	{
		case EAbsolute	 : strMethod = _T("Absolute"); break;
		case ERelative	 : strMethod = _T("Relative"); break;
		case EMinResidue : strMethod = _T("MinResidue"); break;
		case EMaxEntropy : strMethod = _T("MaxEntropy"); break;
		case EIsoData	 : strMethod = _T("IsoData"); break;
	}

	info.stImg.stThreshold.stSimple.strType = strMethod;
}

void CFormThdSpl::SetParameter(StLibrary info)
{
	CSpinButtonCtrl* pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_RELATIVE);
	pSpin->SetPos(info.stImg.stThreshold.stSimple.nRel);

	pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE);
	pSpin->SetPos(info.stImg.stThreshold.stSimple.nAbs);

	CSliderCtrl* pSld = (CSliderCtrl*)GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE);
	pSld->SetPos(info.stImg.stThreshold.stSimple.nAbs);

	if (info.stImg.stThreshold.stSimple.strType == _T("Absolute"))
		CheckRadioButton(IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, IDC_THD_SPL_RBTN_ABSOLUTE);
	else if (info.stImg.stThreshold.stSimple.strType == _T("Relative"))
		CheckRadioButton(IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, IDC_THD_SPL_RBTN_RELATIVE);
	else if (info.stImg.stThreshold.stSimple.strType == _T("MinResidue"))
		CheckRadioButton(IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, IDC_THD_SPL_RBTN_RESIDUE);
	else if (info.stImg.stThreshold.stSimple.strType == _T("MaxEntropy"))
		CheckRadioButton(IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, IDC_THD_SPL_RBTN_ENTROPY);
	else if (info.stImg.stThreshold.stSimple.strType == _T("IsoData"))
		CheckRadioButton(IDC_THD_SPL_RBTN_ABSOLUTE, IDC_THD_SPL_RBTN_ISO, IDC_THD_SPL_RBTN_ISO);
}

void CFormThdSpl::OnBnClickedThdSplRBtnMethod(UINT ID)
{
	UpdateData(TRUE);

	switch (m_rbtnMethod)
	{
	case 0 :
		GetDlgItem(IDC_THD_SPL_EDIT_ABSOLUTE)->EnableWindow(TRUE);
		GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE)->EnableWindow(TRUE);
		GetDlgItem(IDC_THD_SPL_EDIT_RELATIVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_SPIN_RELATIVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE)->EnableWindow(TRUE);
		break;
	case 1 :
		GetDlgItem(IDC_THD_SPL_EDIT_ABSOLUTE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_EDIT_RELATIVE)->EnableWindow(TRUE);
		GetDlgItem(IDC_THD_SPL_SPIN_RELATIVE)->EnableWindow(TRUE);
		GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE)->EnableWindow(FALSE);
		break;
	case 2:
	case 3:
	case 4:
		GetDlgItem(IDC_THD_SPL_EDIT_ABSOLUTE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_EDIT_RELATIVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_SPIN_RELATIVE)->EnableWindow(FALSE);
		GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE)->EnableWindow(FALSE);
		break;
	}
}

void CFormThdSpl::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pSld = (CSliderCtrl*)GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE);

	if (pSld->m_hWnd == pScrollBar->m_hWnd)
	{
		int nPos = pSld->GetPos();

		CSpinButtonCtrl*pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE);
		pSpin->SetPos(nPos);
	}

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CFormThdSpl::OnDeltaposThdSplSpinAbsolute(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	CSpinButtonCtrl*pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE);
	int nPos = pSpin->GetPos();

	CSliderCtrl* pSld = (CSliderCtrl*)GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE);
	pSld->SetPos(nPos);

	*pResult = 0;
}


BOOL CFormThdSpl::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_THD_SPL_EDIT_ABSOLUTE)->GetSafeHwnd())
	{
		int nPos = GetDlgItemInt(IDC_THD_SPL_EDIT_ABSOLUTE);
		CSliderCtrl* pSld = (CSliderCtrl*)GetDlgItem(IDC_THD_SPL_HSL_ABSOLUTE);
		pSld->SetPos(nPos);

		CSpinButtonCtrl*pSpin = (CSpinButtonCtrl*)GetDlgItem(IDC_THD_SPL_SPIN_ABSOLUTE);
		pSpin->SetPos(nPos);
	}

	return CFormView::PreTranslateMessage(pMsg);
}
