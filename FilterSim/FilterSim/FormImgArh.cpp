// FormImgArh.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormImgArh.h"


// CFormImgArh

IMPLEMENT_DYNCREATE(CFormImgArh, CFormView)

CFormImgArh::CFormImgArh()
	: CFormView(CFormImgArh::IDD)
{

}

CFormImgArh::~CFormImgArh()
{
}

void CFormImgArh::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormImgArh, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CFormImgArh diagnostics

#ifdef _DEBUG
void CFormImgArh::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImgArh::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImgArh message handlers

void CFormImgArh::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


BOOL CFormImgArh::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

void CFormImgArh::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_IMG_ARH_CB_OPER);
	pCB->AddString(_T("Copy")				);
	pCB->AddString(_T("Invert")				);
	pCB->AddString(_T("Add")				);
	pCB->AddString(_T("Subtract")			);
	pCB->AddString(_T("Compare")			);
	pCB->AddString(_T("Multiply")			);
	pCB->AddString(_T("Divide")				);
	pCB->AddString(_T("Modulo")				);
	pCB->AddString(_T("Scaled Add")			);
	pCB->AddString(_T("Scaled Subtract")	);
	pCB->AddString(_T("Scaled Multiply")	);
	pCB->AddString(_T("Scaled Divide")		);
	pCB->AddString(_T("Modulo")				);
	pCB->AddString(_T("Scaled Add")			);
	pCB->AddString(_T("Scaled Subtract")	);
	pCB->AddString(_T("Scaled Multiply")	);
	pCB->AddString(_T("Scaled Divide")		);
	pCB->AddString(_T("Shift Left")			);
	pCB->AddString(_T("Shift Right")		);
	pCB->AddString(_T("Bitwise AND")		);
	pCB->AddString(_T("Bitwise OR")			);
	pCB->AddString(_T("Bitwise XOR")		);
	pCB->AddString(_T("Logical AND")		);
	pCB->AddString(_T("Logical OR")			);
	pCB->AddString(_T("Logical XOR")		);
	pCB->AddString(_T("Minimum")			);
	pCB->AddString(_T("Maximum")			);
	pCB->AddString(_T("Set Zero")			);
	pCB->AddString(_T("Set Non Zero")		);
	pCB->AddString(_T("Equal")				);
	pCB->AddString(_T("Not Equal")			);
	pCB->AddString(_T("Greater or Equal")	);
	pCB->AddString(_T("Lesser or Equal")	);
	pCB->AddString(_T("Greater")			);
	pCB->AddString(_T("Lesser")				);
	pCB->AddString(_T("Overlay")			);

	InitControls();
}

void CFormImgArh::InitControls()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_IMG_ARH_CB_OPER);

	pCB->SetCurSel(-1);
}

void CFormImgArh::GetParameter(StLibrary &info)
{
	CComboBox* pCB = NULL;
	CString strText=_T("");
	int sel=-1;

	pCB = (CComboBox*)GetDlgItem(IDC_IMG_ARH_CB_OPER);
	sel = pCB->GetCurSel();
	if (sel == -1) return;

	pCB->GetLBText(sel,strText);

	info.stImg.stArithmetic.strType = strText;
}

void CFormImgArh::SetParameter(StLibrary info)
{
	CComboBox* pCB = NULL;
	int sel=-1;
	CString strData=_T("");
	pCB = (CComboBox*)GetDlgItem(IDC_IMG_ARH_CB_OPER);

	strData = info.stImg.stArithmetic.strType;

	sel = pCB->FindString(-1, strData);
	pCB->SetCurSel(sel);
}