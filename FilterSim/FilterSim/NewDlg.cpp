// NewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "NewDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CNewDlg dialog

IMPLEMENT_DYNAMIC(CNewDlg, CDialogEx)

CNewDlg::CNewDlg(int nCnt, std::vector<CEImage> vImgInfo, CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewDlg::IDD, pParent)

{
	m_nCnt = nCnt;
	m_nWidth = 512;
	m_nHeight = 512;
	m_strName = _T("");
	m_vImgInfo = vImgInfo;
}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialogEx)
	ON_BN_CLICKED(IDC_NEW_BTN_OK, &CNewDlg::OnBnClickedNewBtnOk)
	ON_CBN_SELCHANGE(IDC_NEW_CB_REF, &CNewDlg::OnCbnSelchangeNewCbRef)
END_MESSAGE_MAP()


// CNewDlg message handlers


BOOL CNewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetDlgItemInt(IDC_NEW_EDIT_WIDTH, 512);
	SetDlgItemInt(IDC_NEW_EDIT_HEIGHT, 512);

	m_strName.Format(_T("Image%d"),m_nCnt);
	SetDlgItemText(IDC_NEW_EDIT_NAME, m_strName);

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_NEW_CB_REF);

	std::vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString strName = _T("");
		if (it->GetImageName(strName) == true)
			pCB->AddString(strName);

		for (int i=0; i<it->GetRoiCount(); i++)
		{
			it->GetRoiName(i,strName);
			strName = _T(" - ") + strName;
			pCB->AddString(strName);
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CNewDlg::OnBnClickedNewBtnOk()
{
	GetDlgItemText(IDC_NEW_EDIT_NAME, m_strName);
	m_nWidth = GetDlgItemInt(IDC_NEW_EDIT_WIDTH);
	m_nHeight = GetDlgItemInt(IDC_NEW_EDIT_HEIGHT);
	
	m_vImgInfo.clear();
	OnOK();
}



void CNewDlg::OnCbnSelchangeNewCbRef()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_NEW_CB_REF);

	CString strName=_T("");
	int sel = pCB->GetCurSel();
	if (sel == -1) return;

	pCB->GetLBText(sel,strName);

	if (strName.Find(_T(" - ")) == 0)
	{
		int len = strName.GetLength();
		strName = strName.Right(len-3);
	}

	std::vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (strName == fileName)
		{
			int w=0, h=0;
			it->GetWidth(w);
			it->GetHeight(h);

			SetDlgItemInt(IDC_NEW_EDIT_WIDTH,w);
			SetDlgItemInt(IDC_NEW_EDIT_HEIGHT,h);
		}
		else
		{
			for (int i=0; i<it->GetRoiCount(); i++)
			{
				it->GetRoiName(i,fileName);
				if (strName == fileName)
				{
					int x=0,y=0,w=0, h=0;
					it->GetRoiPlacement(fileName, x,y,w,h);

					SetDlgItemInt(IDC_NEW_EDIT_WIDTH,w);
					SetDlgItemInt(IDC_NEW_EDIT_HEIGHT,h);
				}
			}
		}
	}
}


BOOL CNewDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN)
		{
			OnBnClickedNewBtnOk();
		}

		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
