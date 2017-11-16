// FormTab1.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FilterSimDlg.h"
#include "FormImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CFormImg

IMPLEMENT_DYNCREATE(CFormImg, CFormView)

CFormImg::CFormImg()
	: CFormView(CFormImg::IDD)
{
	m_pFormCvl = NULL;
	m_pFormMpl = NULL;
	m_pFormThd = NULL;
	m_pFormArh = NULL;
	m_pFormScl = NULL;
}

CFormImg::~CFormImg()
{
}

void CFormImg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormImg, CFormView)
	ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_TAB1_CB_PROCESSING, &CFormImg::OnCbnSelchangeTab1CbProcessing)
END_MESSAGE_MAP()


// CFormImg diagnostics

#ifdef _DEBUG
void CFormImg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImg message handlers


void CFormImg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CCreateContext context;
	ZeroMemory(&context, sizeof(context));
	CView* pView = NULL;
	CRect rect=CRect(0,0,0,0);

	GetDlgItem(IDC_IMG_PC_TAB1)->MoveWindow(0,30,m_wndRc.Width(), m_wndRc.Height()-30);

	//----- Create Form Window -----//
	// Form Convolution
	pView = (CView*)RUNTIME_CLASS(CFormImgCvl)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_IMG_CONVOL, &context);
	pView->OnInitialUpdate();
	m_pFormCvl = pView;

	m_pFormCvl->ShowWindow(SW_HIDE);

	// Form Morphology
	pView = (CView*)RUNTIME_CLASS(CFormImgMpl)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_IMG_MORPHOLOGY, &context);
	pView->OnInitialUpdate();
	m_pFormMpl = pView;

	m_pFormMpl->ShowWindow(SW_HIDE);

	// Form Threshold
	pView = (CView*)RUNTIME_CLASS(CFormImgThd)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_IMG_THRESHOLD, &context);
	pView->OnInitialUpdate();
	m_pFormThd = pView;

	m_pFormThd->ShowWindow(SW_HIDE);

	// Form Arithmetic
	pView = (CView*)RUNTIME_CLASS(CFormImgArh)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_IMG_ARITHMETIC, &context);
	pView->OnInitialUpdate();
	m_pFormArh = pView;

	m_pFormArh->ShowWindow(SW_HIDE);

	// Form Scale & Rotate
	pView = (CView*)RUNTIME_CLASS(CFormImgScl)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_IMG_SCALEROTATE, &context);
	pView->OnInitialUpdate();
	m_pFormScl = pView;

	m_pFormScl->ShowWindow(SW_HIDE);
	
	GetDlgItem(IDC_IMG_PC_TAB1)->DestroyWindow();

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	pCB->AddString(_T("Convolution"));
	pCB->AddString(_T("Morphology"));
	pCB->AddString(_T("Threshold"));
	pCB->AddString(_T("Arithmetic & Logic"));
	pCB->AddString(_T("Scale & Rotate"));
	pCB->AddString(_T("Gain & Offset"));
}

void CFormImg::InitControls()
{
	CComboBox* pCB = NULL;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	pCB->SetCurSel(-1);

	FormSwitching(ENone);
}

BOOL CFormImg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormImg::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}

void CFormImg::FormSwitching(eProcessing eType)
{
	switch (eType)
	{
	case EConvolution :
		{
			m_pFormCvl->ShowWindow(SW_SHOW);
			m_pFormMpl->ShowWindow(SW_HIDE);
			m_pFormThd->ShowWindow(SW_HIDE);
			m_pFormArh->ShowWindow(SW_HIDE);
			m_pFormScl->ShowWindow(SW_HIDE);

			CFormImgCvl* pCvl = (CFormImgCvl*)m_pFormCvl;
			pCvl->InitControls();
		}
		break;
	case EMorphology : 
		{
			m_pFormCvl->ShowWindow(SW_HIDE);
			m_pFormMpl->ShowWindow(SW_SHOW);
			m_pFormThd->ShowWindow(SW_HIDE);
			m_pFormArh->ShowWindow(SW_HIDE);
			m_pFormScl->ShowWindow(SW_HIDE);

			CFormImgMpl* pMpl = (CFormImgMpl*)m_pFormMpl;
			pMpl->InitControls();
		}
		break;
	case EThreshold : 
		{
			m_pFormCvl->ShowWindow(SW_HIDE);
			m_pFormMpl->ShowWindow(SW_HIDE);
			m_pFormThd->ShowWindow(SW_SHOW);
			m_pFormArh->ShowWindow(SW_HIDE);
			m_pFormScl->ShowWindow(SW_HIDE);

			CFormImgThd* pThd = (CFormImgThd*)m_pFormThd;
			pThd->InitControls();
		}
		
		break;
	case EArith : 
		{
			m_pFormCvl->ShowWindow(SW_HIDE);
			m_pFormMpl->ShowWindow(SW_HIDE);
			m_pFormThd->ShowWindow(SW_HIDE);
			m_pFormArh->ShowWindow(SW_SHOW);
			m_pFormScl->ShowWindow(SW_HIDE);

			CFormImgArh* pArh = (CFormImgArh*)m_pFormArh;
			pArh->InitControls();
		}
		
		break;
	case EScale : 
		m_pFormCvl->ShowWindow(SW_HIDE);
		m_pFormMpl->ShowWindow(SW_HIDE);
		m_pFormThd->ShowWindow(SW_HIDE);
		m_pFormArh->ShowWindow(SW_HIDE);
		m_pFormScl->ShowWindow(SW_SHOW);

		break;
	case EGain : 
		m_pFormCvl->ShowWindow(SW_HIDE);
		m_pFormMpl->ShowWindow(SW_HIDE);
		m_pFormThd->ShowWindow(SW_HIDE);
		m_pFormArh->ShowWindow(SW_HIDE);
		m_pFormScl->ShowWindow(SW_HIDE);

		break;
	case ENone : 
		m_pFormCvl->ShowWindow(SW_HIDE);
		m_pFormMpl->ShowWindow(SW_HIDE);
		m_pFormThd->ShowWindow(SW_HIDE);
		m_pFormArh->ShowWindow(SW_HIDE);
		m_pFormScl->ShowWindow(SW_HIDE);

		break;
	}
}

void CFormImg::OnCbnSelchangeTab1CbProcessing()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	int sel = pCB->GetCurSel();

	switch (sel)
	{
	case 0 : FormSwitching(EConvolution); break;
	case 1 : FormSwitching(EMorphology); break;
	case 2 : FormSwitching(EThreshold); break;
	case 3 : FormSwitching(EArith); break;
	case 4 : FormSwitching(EScale); break;
	case 5 : FormSwitching(EGain); break;
	default:
		break;
	}
}

bool CFormImg::IsConvolution(CString strValue)
{
	if (strValue == _T("Uniform"))			return true;
	else if (strValue == _T("Uniform3x3"))	return true;
	else if (strValue == _T("Uniform5x5"))	return true;
	else if (strValue == _T("Uniform7x7"))	return true;
	else if (strValue == _T("Gaussian"))	return true;
	else if (strValue == _T("Gaussian3x3"))	return true;
	else if (strValue == _T("Gaussian5x5"))	return true;
	else if (strValue == _T("Gaussian7x7"))	return true;
	else if (strValue == _T("Lowpass1"))	return true;
	else if (strValue == _T("Lowpass2"))	return true;
	else if (strValue == _T("Highpass1"))	return true;
	else if (strValue == _T("Highpass2"))	return true;
	else if (strValue == _T("Gradient"))	return true;
	else if (strValue == _T("GradientX"))	return true;
	else if (strValue == _T("GradientY"))	return true;
	else if (strValue == _T("Sobel"))		return true;
	else if (strValue == _T("SobelX"))		return true;
	else if (strValue == _T("SobelY"))		return true;
	else if (strValue == _T("Prewitt"))		return true;
	else if (strValue == _T("PrewittX"))	return true;
	else if (strValue == _T("PrewittY"))	return true;
	else if (strValue == _T("Roberts"))		return true;
	else if (strValue == _T("LaplacianX"))	return true;
	else if (strValue == _T("LaplacianY"))	return true;
	else if (strValue == _T("Laplacian4"))	return true;
	else if (strValue == _T("Laplacian8"))	return true;
	else return false;
}

bool CFormImg::IsMorphology(CString strValue)
{
	if (strValue == _T("Erode"))				return true;
	else if (strValue == _T("Dilate"))			return true;
	else if (strValue == _T("Open"))			return true;
	else if (strValue == _T("Close"))			return true;
	else if (strValue == _T("White Top Hat"))	return true;
	else if (strValue == _T("Black Top Hat"))	return true;
	else if (strValue == _T("Morpho Gradient"))	return true;
	else if (strValue == _T("Median 3x3"))		return true;
	else return false;
}

bool CFormImg::IsArtihemetic(CString strValue)
{
	if (strValue == _T("Copy"))						return true;
	else if (strValue == _T("Invert"))				return true;
	else if (strValue == _T("Add"))					return true;
	else if (strValue == _T("Subtract"))			return true;
	else if (strValue == _T("Compare"))				return true;
	else if (strValue == _T("Multiply"))			return true;
	else if (strValue == _T("Divide"))				return true;
	else if (strValue == _T("Modulo"))				return true;
	else if (strValue == _T("Scaled Add"))			return true;
	else if (strValue == _T("Scaled Subtract"))		return true;
	else if (strValue == _T("Scaled Multiply"))		return true;
	else if (strValue == _T("Scaled Divide"))		return true;
	else if (strValue == _T("Shift Left"))			return true;
	else if (strValue == _T("Modulo"))				return true;
	else if (strValue == _T("Scaled Add"))			return true;
	else if (strValue == _T("Scaled Subtract"))		return true;
	else if (strValue == _T("Scaled Multiply"))		return true;
	else if (strValue == _T("Scaled Divide"))		return true;
	else if (strValue == _T("Shift Left"))			return true;
	else if (strValue == _T("Shift Right"))			return true;
	else if (strValue == _T("Bitwise AND"))			return true;
	else if (strValue == _T("Bitwise OR"))			return true;
	else if (strValue == _T("Bitwise XOR"))			return true;
	else if (strValue == _T("Logical AND"))			return true;
	else if (strValue == _T("Logical OR"))			return true;
	else if (strValue == _T("Logical XOR"))			return true;
	else if (strValue == _T("Minimum"))				return true;
	else if (strValue == _T("Maximum"))				return true;
	else if (strValue == _T("Set Zero"))			return true;
	else if (strValue == _T("Set Non Zero"))		return true;
	else if (strValue == _T("Equal"))				return true;
	else if (strValue == _T("Not Equal"))			return true;
	else if (strValue == _T("Greater or Equal"))	return true;
	else if (strValue == _T("Lesser or Equal"))		return true;
	else if (strValue == _T("Greater"))				return true;
	else if (strValue == _T("Lesser"))				return true;
	else if (strValue == _T("Overlay"))				return true;
	else return false;
}

bool CFormImg::IsThreshold(CString strValue)
{
	if (strValue == _T("Simple Threshold"))			return true;
	else if (strValue == _T("Double Threshold"))	return true;
	else if (strValue == _T("Adaptive Threshold"))	return true;
	else return false;
}

void CFormImg::GetParameter(StLibrary& info)
{
	CComboBox* pCB = NULL;
	CString strMethod=_T("");
	int sel=-1;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	sel = pCB->GetCurSel();
	if (sel == -1) return;

	pCB->GetLBText(sel,strMethod);
	info.stImg.strType = strMethod;

	CFormImgCvl* pCvl = (CFormImgCvl*)m_pFormCvl;
	pCvl->GetParameter(info);

	CFormImgMpl* pMpl = (CFormImgMpl*)m_pFormMpl;
	pMpl->GetParameter(info);

	CFormImgThd* pThd = (CFormImgThd*)m_pFormThd;
	pThd->GetParameter(info);

	CFormImgArh* pArh = (CFormImgArh*)m_pFormArh;
	pArh->GetParameter(info);
}

void CFormImg::SetParameter(StLibrary info)
{
	CComboBox* pCB = NULL;
	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);

	if (info.stImg.strType == _T("Convolution"))
	{
		// Convolution
		pCB->SetCurSel(0);	
		FormSwitching(EConvolution);

		CFormImgCvl* pCvl = (CFormImgCvl*)m_pFormCvl;
		pCvl->SetParameter(info);
	}
	else if (info.stImg.strType == _T("Morphology"))
	{
		// Morphology
		pCB->SetCurSel(1);	
		FormSwitching(EMorphology);

		CFormImgMpl* pMpl = (CFormImgMpl*)m_pFormMpl;
		pMpl->SetParameter(info);
	}
	else if (info.stImg.strType == _T("Threshold"))
	{
		// Threshold
		pCB->SetCurSel(2);	
		FormSwitching(EThreshold);

		CFormImgThd* pThd = (CFormImgThd*)m_pFormThd;
		pThd->SetParameter(info);

	}
	else if (info.stImg.strType == _T("Arithmetic & Logic"))
	{
		// Arithmetic & Logic
		pCB->SetCurSel(3); 
		FormSwitching(EArith);

		CFormImgArh* pArh = (CFormImgArh*)m_pFormArh;
		pArh->SetParameter(info);
	}
}