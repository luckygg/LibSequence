// FormImgGan.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormImgGan.h"


// CFormImgGan

IMPLEMENT_DYNCREATE(CFormImgGan, CFormView)

CFormImgGan::CFormImgGan()
	: CFormView(CFormImgGan::IDD)
{

}

CFormImgGan::~CFormImgGan()
{
}

void CFormImgGan::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormImgGan, CFormView)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CFormImgGan diagnostics

#ifdef _DEBUG
void CFormImgGan::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImgGan::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImgGan message handlers


void CFormImgGan::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormImgGan::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormImgGan::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	InitControls();
}

void CFormImgGan::InitControls()
{
	CSliderCtrl* pCtrl=NULL;

	pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_GAIN);
	pCtrl->SetRange(0,300);
	pCtrl->SetTicFreq(100);
	pCtrl->SetPos(100);

	pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_OFFSET);
	pCtrl->SetRange(-25500,25500);
	pCtrl->SetTicFreq(5000);
	pCtrl->SetPos(0);

	SetDlgItemText(IDC_IMG_GAN_EDIT_GAIN, _T("1"));
	SetDlgItemText(IDC_IMG_GAN_EDIT_OFFSET, _T("0.00"));
}

void CFormImgGan::GetParameter(StLibrary &info)
{
	CString strText=_T("");
	GetDlgItemText(IDC_IMG_GAN_EDIT_GAIN, strText);
	info.stImg.stGain.fGain = (float)_ttof(strText);
	GetDlgItemText(IDC_IMG_GAN_EDIT_OFFSET, strText);
	info.stImg.stGain.fOffset = (float)_ttof(strText);

	info.stImg.stGain.strType = _T("Gain & Offset");
}

void CFormImgGan::SetParameter(StLibrary info)
{
	CString strText=_T("");

	strText.Format(_T("%.2f"), info.stImg.stGain.fGain);
	SetDlgItemText(IDC_IMG_GAN_EDIT_GAIN, strText);
	strText.Format(_T("%.2f"), info.stImg.stGain.fOffset);
	SetDlgItemText(IDC_IMG_GAN_EDIT_OFFSET, strText);

	CSliderCtrl* pCtrl=NULL;
	pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_GAIN);
	pCtrl->SetPos((int)info.stImg.stGain.fGain);
	pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_OFFSET);
	pCtrl->SetPos((int)info.stImg.stGain.fOffset);
}

void CFormImgGan::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pCtrl=NULL;
	int Pos=0;
	float fPos=0;
	CString strValue=_T("");
	pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_GAIN);
	if (pScrollBar->GetSafeHwnd() == pCtrl->GetSafeHwnd())
	{
		Pos = pCtrl->GetPos();
		fPos = (float)Pos/100;
		strValue.Format(_T("%.2f"), fPos);
		SetDlgItemText(IDC_IMG_GAN_EDIT_GAIN, strValue);
	}

	pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_OFFSET);
	if (pScrollBar->GetSafeHwnd() == pCtrl->GetSafeHwnd())
	{
		Pos = pCtrl->GetPos();
		fPos = (float)Pos/100;
		strValue.Format(_T("%.2f"), fPos);
		SetDlgItemText(IDC_IMG_GAN_EDIT_OFFSET, strValue);
	}

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


BOOL CFormImgGan::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->wParam == VK_RETURN) 
	{
		CString strValue=_T("");
		float fValue=0;
		int nValue=0;
		CSliderCtrl* pCtrl=NULL;
		if(pMsg->hwnd == GetDlgItem(IDC_IMG_GAN_EDIT_GAIN)->GetSafeHwnd())
		{
			GetDlgItemText(IDC_IMG_GAN_EDIT_GAIN, strValue);
			fValue = (float)_ttof(strValue);
			nValue = (int)(fValue*100);

			pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_GAIN);
			pCtrl->SetPos(nValue);
			return TRUE;
		}
		else if(pMsg->hwnd == GetDlgItem(IDC_IMG_GAN_EDIT_OFFSET)->GetSafeHwnd())
		{
			GetDlgItemText(IDC_IMG_GAN_EDIT_OFFSET, strValue);
			fValue = (float)_ttof(strValue);
			nValue = (int)(fValue*100);

			pCtrl = (CSliderCtrl*)GetDlgItem(IDC_IMG_GAN_HSL_OFFSET);
			pCtrl->SetPos(nValue);
			return TRUE;
		}
		
	}


	return CFormView::PreTranslateMessage(pMsg);
}
