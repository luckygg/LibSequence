// DlgName.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "NameDlg.h"
#include "afxdialogex.h"


// CNameDlgdialog

IMPLEMENT_DYNAMIC(CNameDlg, CDialogEx)

CNameDlg::CNameDlg(int nCnt, CWnd* pParent /*=NULL*/)
	: CDialogEx(CNameDlg::IDD, pParent)
{
	m_nCnt = nCnt;
	m_strName = _T("");
}

CNameDlg::~CNameDlg()
{
}

void CNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNameDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NAME_BTN_OK, &CNameDlg::OnBnClickedBtnOk)
END_MESSAGE_MAP()


// CNameDlgmessage handlers


BOOL CNameDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_strName.Format(_T("Image%d"),m_nCnt);
	SetDlgItemText(IDC_NAME_EDIT_NAME, m_strName);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CNameDlg::OnBnClickedBtnOk()
{
	GetDlgItemText(IDC_NAME_EDIT_NAME, m_strName);
	OnOK();
}


BOOL CNameDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedBtnOk();
		}

		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
