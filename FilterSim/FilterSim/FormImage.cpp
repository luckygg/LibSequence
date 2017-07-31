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
	m_pFormConvol = NULL;
	m_pFormMorpho = NULL;
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
	pView = (CView*)RUNTIME_CLASS(CFormConvol)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_CONVOL, &context);
	pView->OnInitialUpdate();
	m_pFormConvol = pView;

	m_pFormConvol->ShowWindow(SW_HIDE);

	// Form Morphology
	pView = (CView*)RUNTIME_CLASS(CFormMorpho)->CreateObject();
	GetDlgItem(IDC_IMG_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_MORPHOLOGY, &context);
	pView->OnInitialUpdate();
	m_pFormMorpho = pView;

	m_pFormMorpho->ShowWindow(SW_HIDE);
	
	GetDlgItem(IDC_IMG_PC_TAB1)->DestroyWindow();

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	pCB->AddString(_T("Convolution"));
	pCB->AddString(_T("Morphology"));
	pCB->AddString(_T("Threshold"));
	pCB->AddString(_T("Arithmetic & Logic"));
	pCB->AddString(_T("Scale & Rotate"));
	pCB->AddString(_T("Gain & Offset"));
}

void CFormImg::UpdateControls(StItemInfo info)
{
	CComboBox* pCB = NULL;
	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	
	if (IsConvolution(info.strType) == true)
	{
		pCB->SetCurSel(0);	// Convolution
		FormSwitching(EConvolution);

		CFormConvol* pCvl = (CFormConvol*)m_pFormConvol;
		pCvl->SetSelectKernelByText(info.strType);
	}
	else if (IsMorphology(info.strType) == true)
	{
		pCB->SetCurSel(1);	// Morphology
		FormSwitching(EMorphology);

		CFormMorpho* pMpl = (CFormMorpho*)m_pFormMorpho;
		pMpl->SetSelectOperByText(info.strType);
		pMpl->SetHalfKernel(info.stLibrary.stImg.stMorphology.nHalfKernel);
	}
	else if (IsThreshold(info.strType) == true)
	{
		pCB->SetCurSel(2);	// Threshold
		FormSwitching(EThreshold);
	}
	else if (IsArtihemetic(info.strType) == true)
	{
		pCB->SetCurSel(3); // Arithmetic & Logic
		FormSwitching(EArith);
	}
}

void CFormImg::InitControls()
{
	CComboBox* pCB = NULL;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	pCB->SetCurSel(-1);

	FormSwitching(ENone);
}

CString CFormImg::GetTextCBSelectedProcessing()
{
	CComboBox* pCB = NULL;
	CString strText=_T("");
	int sel=-1;

	pCB = (CComboBox*)GetDlgItem(IDC_TAB1_CB_PROCESSING);
	sel = pCB->GetCurSel();
	if (sel == -1) return _T("");
	
	pCB->GetLBText(sel,strText);

	return strText;
}

CString CFormImg::GetTextCBSelectedConvolution()
{
	CFormConvol* pCvl = (CFormConvol*)m_pFormConvol;
	if (pCvl == NULL) return _T("");

	return pCvl->GetTextCBSelectedKernel();
}

CString CFormImg::GetTextSelectedMorphology()
{
	CFormMorpho* pMpl = (CFormMorpho*)m_pFormMorpho;
	if (pMpl == NULL) return _T("");

	return pMpl->GetTextSelectedOper();
}

int CFormImg::GetValueMorphologyHalfKernel()
{
	CFormMorpho* pMpl = (CFormMorpho*)m_pFormMorpho;
	if (pMpl == NULL) return 0;

	return pMpl->GetHalfKernel();
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
			m_pFormConvol->ShowWindow(SW_SHOW);
			m_pFormMorpho->ShowWindow(SW_HIDE);

			CFormConvol* pCvl = (CFormConvol*)m_pFormConvol;
			pCvl->InitControls();
		}
		break;
	case EMorphology : 
		{
			m_pFormConvol->ShowWindow(SW_HIDE);
			m_pFormMorpho->ShowWindow(SW_SHOW);
			
			CFormMorpho* pMpl = (CFormMorpho*)m_pFormMorpho;
			pMpl->InitControls();
		}
		break;
	case EThreshold : 
		m_pFormConvol->ShowWindow(SW_HIDE);
		m_pFormMorpho->ShowWindow(SW_HIDE);
		break;
	case EArith : 
		m_pFormConvol->ShowWindow(SW_HIDE);
		m_pFormMorpho->ShowWindow(SW_HIDE);
		break;
	case EScale : 
		m_pFormConvol->ShowWindow(SW_HIDE);
		m_pFormMorpho->ShowWindow(SW_HIDE);
		break;
	case EGain : 
		m_pFormConvol->ShowWindow(SW_HIDE);
		m_pFormMorpho->ShowWindow(SW_HIDE);
		break;
	case ENone : 
		m_pFormConvol->ShowWindow(SW_HIDE);
		m_pFormMorpho->ShowWindow(SW_HIDE);
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
	if (strValue == _T("Simpe"))			return true;
	else if (strValue == _T("Double"))		return true;
	else if (strValue == _T("Adaptive"))	return true;
	else return false;
}