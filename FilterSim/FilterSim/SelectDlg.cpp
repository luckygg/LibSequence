// DeleteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "SelectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CSelectDlg dialog

IMPLEMENT_DYNAMIC(CSelectDlg, CDialogEx)

CSelectDlg::CSelectDlg(std::vector<CEImage> vImgInfo, CWnd* pParent /*=NULL*/)
	: CDialogEx(CSelectDlg::IDD, pParent)
{
	m_strName = _T("");
	m_vImgInfo = vImgInfo;
}

CSelectDlg::~CSelectDlg()
{
}

void CSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelectDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEL_BTN_OK, &CSelectDlg::OnBnClickedDelBtnOk)
	ON_BN_CLICKED(IDC_SEL_BTN_CANCEL, &CSelectDlg::OnBnClickedSelBtnCancel)
END_MESSAGE_MAP()


// CSelectDlg message handlers


BOOL CSelectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_SEL_CB_IMAGE);

	std::vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString strName = _T("");
		if (it->GetFileName(strName) == true)
			pCB->AddString(strName);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CSelectDlg::OnBnClickedDelBtnOk()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_SEL_CB_IMAGE);

	CString strName=_T("");
	int sel = pCB->GetCurSel();
	if (sel == -1) OnCancel();

	pCB->GetLBText(sel,strName);

	m_strName = strName;

	OnOK();
}


void CSelectDlg::OnBnClickedSelBtnCancel()
{
	OnCancel();
}


BOOL CSelectDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_SEL_BTN_OK)->GetSafeHwnd())
		{
			OnBnClickedDelBtnOk();
		}
		else if (pMsg->wParam == VK_RETURN && pMsg->hwnd == GetDlgItem(IDC_SEL_BTN_CANCEL)->GetSafeHwnd())
		{
			OnBnClickedSelBtnCancel();
		}

		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
