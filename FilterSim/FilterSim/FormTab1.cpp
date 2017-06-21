// FormTab1.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FilterSimDlg.h"
#include "FormTab1.h"


// CFormTab1

IMPLEMENT_DYNCREATE(CFormTab1, CFormView)

CFormTab1::CFormTab1()
	: CFormView(CFormTab1::IDD)
{

}

CFormTab1::~CFormTab1()
{
}

void CFormTab1::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormTab1, CFormView)
	ON_BN_CLICKED(IDC_TAB1_BTN_APPLY, &CFormTab1::OnBnClickedTab1BtnApply)
END_MESSAGE_MAP()


// CFormTab1 diagnostics

#ifdef _DEBUG
void CFormTab1::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormTab1::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormTab1 message handlers


void CFormTab1::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

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

void CFormTab1::UpdateCBList(std::vector<CImgInfo> ImgInfo)
{
	CComboBox* pCBIn = (CComboBox*)GetDlgItem(IDC_TAB1_CB_INPUT);
	CComboBox* pCBOut = (CComboBox*)GetDlgItem(IDC_TAB1_CB_OUTPUT);
	pCBIn->ResetContent();
	pCBOut->ResetContent();

	for (std::vector<CImgInfo>::iterator it = ImgInfo.begin(); it != ImgInfo.end(); ++it)
	{
		CString name=_T("");
		it->GetFileName(name);
		pCBIn->AddString(name);
		pCBOut->AddString(name);
	}
}

void CFormTab1::OnBnClickedTab1BtnApply()
{
	CComboBox* pCB = NULL;
	CString strType=_T(""),strIn=_T(""),strOut=_T("");
	int row=0, sel = -1;

	row = GetDlgItemInt(IDC_TAB1_LB_ROW);

	pCB= (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
	sel = pCB->GetCurSel();
	if (sel >= 0) 
		pCB->GetLBText(sel,strType);
	
	pCB= (CComboBox*)GetDlgItem(IDC_TAB1_CB_INPUT);
	sel = pCB->GetCurSel();
	if (sel >= 0) 
		pCB->GetLBText(sel,strIn);

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_OUTPUT);
	sel = pCB->GetCurSel();
	if (sel >= 0) 
		pCB->GetLBText(sel,strOut);

	BOOL bChk = IsDlgButtonChecked(IDC_TAB1_CHK_USE);

	CFilterSimDlg* pParent = (CFilterSimDlg*)GetParent();
	pParent->UpdateItem(row,bChk,strType,strIn,strOut);
}

void CFormTab1::SetSelectedRow(int nRow)
{
	SetDlgItemInt(IDC_TAB1_LB_ROW, nRow);
}

void CFormTab1::UpdateControls(StItemInfo info)
{
	CComboBox* pCB = NULL;
	int sel=-1, state=0;
	
	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
	sel = pCB->FindString(-1, info.strType);
	pCB->SetCurSel(sel);

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_INPUT);
	sel = pCB->FindString(-1, info.strInput);
	pCB->SetCurSel(sel);

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_OUTPUT);
	sel = pCB->FindString(-1, info.strOutput);
	pCB->SetCurSel(sel);

	info.bUse ? state=1 : state=0;
	CheckDlgButton(IDC_TAB1_CHK_USE, state);
}

void CFormTab1::ResetControls()
{
	CComboBox* pCB = NULL;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_TYPE);
	pCB->SetCurSel(-1);

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_INPUT);
	pCB->SetCurSel(-1);

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_OUTPUT);
	pCB->SetCurSel(-1);

	CheckDlgButton(IDC_TAB1_CHK_USE, 0);
}