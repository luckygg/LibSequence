// FormThreshold.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormThreshold.h"


// CFormThreshold

IMPLEMENT_DYNCREATE(CFormThreshold, CFormView)

CFormThreshold::CFormThreshold()
	: CFormView(CFormThreshold::IDD)
	, m_rbtnMethod(0)
{
	m_pFormSpl = NULL;
	m_pFormDbl = NULL;
	m_pFormAdt = NULL;
}

CFormThreshold::~CFormThreshold()
{
}

void CFormThreshold::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_THD_RBTN_SIMPLE, m_rbtnMethod);
}

BEGIN_MESSAGE_MAP(CFormThreshold, CFormView)
	ON_WM_SIZE()
	ON_CONTROL_RANGE(BN_CLICKED, IDC_THD_RBTN_SIMPLE, IDC_THD_RBTN_ADAPTIVE, CFormThreshold::OnBnClickedThdRBtnMethod)
END_MESSAGE_MAP()


// CFormThreshold diagnostics

#ifdef _DEBUG
void CFormThreshold::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormThreshold::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormThreshold message handlers


BOOL CFormThreshold::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormThreshold::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}


void CFormThreshold::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	GetDlgItem(IDC_THD_PC_TAB1)->MoveWindow(0,50,m_wndRc.Width(), m_wndRc.Height()-50);

	CCreateContext context;
	ZeroMemory(&context, sizeof(context));
	CView* pView = NULL;
	CRect rect=CRect(0,0,0,0);

	//----- Create Form Window -----//
	// Form Simple Threshold
	pView = (CView*)RUNTIME_CLASS(CFormThdSpl)->CreateObject();
	GetDlgItem(IDC_THD_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_THD_SIMPLE, &context);
	pView->OnInitialUpdate();
	m_pFormSpl = pView;

	m_pFormSpl->ShowWindow(SW_SHOW);

	// Form Double Threshold
	pView = (CView*)RUNTIME_CLASS(CFormThdDbl)->CreateObject();
	GetDlgItem(IDC_THD_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_THD_DOUBLE, &context);
	pView->OnInitialUpdate();
	m_pFormDbl = pView;

	m_pFormDbl->ShowWindow(SW_HIDE);

	// Form Adaptive Threshold
	pView = (CView*)RUNTIME_CLASS(CFormThdAdt)->CreateObject();
	GetDlgItem(IDC_THD_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_THD_ADAPTIVE, &context);
	pView->OnInitialUpdate();
	m_pFormAdt = pView;

	m_pFormAdt->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_THD_PC_TAB1)->DestroyWindow();

	InitControls();
}

void CFormThreshold::InitControls()
{
	CheckRadioButton(IDC_THD_RBTN_SIMPLE, IDC_THD_RBTN_ADAPTIVE, IDC_THD_RBTN_SIMPLE);

	FormSwitching(ESimple);
}

void CFormThreshold::FormSwitching(int nMethod)
{
	switch (nMethod)
	{
	case ESimple :
		{
			m_pFormSpl->ShowWindow(SW_SHOW);
			m_pFormDbl->ShowWindow(SW_HIDE);
			m_pFormAdt->ShowWindow(SW_HIDE);
			
			CFormThdSpl* pSpl = (CFormThdSpl*)m_pFormSpl;
			pSpl->InitControls();
		}
		break;
	case EDouble : 
		{
			m_pFormSpl->ShowWindow(SW_HIDE);
			m_pFormDbl->ShowWindow(SW_SHOW);
			m_pFormAdt->ShowWindow(SW_HIDE);

			CFormThdDbl* pDbl = (CFormThdDbl*)m_pFormDbl;
			pDbl->InitControls();
		}
		break;
	case EAdaptive : 
		{
			m_pFormSpl->ShowWindow(SW_HIDE);
			m_pFormDbl->ShowWindow(SW_HIDE);
			m_pFormAdt->ShowWindow(SW_SHOW);

			CFormThdAdt* pAdt = (CFormThdAdt*)m_pFormAdt;
			pAdt->InitControls();
		}
		break;
	case ENone : 
		m_pFormSpl->ShowWindow(SW_HIDE);
		m_pFormDbl->ShowWindow(SW_HIDE);
		m_pFormAdt->ShowWindow(SW_HIDE);
		break;
	}
}

void CFormThreshold::OnBnClickedThdRBtnMethod(UINT ID)
{
	UpdateData(TRUE);

	FormSwitching(m_rbtnMethod);
}

void CFormThreshold::GetParameter(StLibrary &info)
{
	CString strMethod=_T("");
	switch (m_rbtnMethod)
	{
		case ESimple	: strMethod = _T("Simple Threshold"); break;
		case EDouble	: strMethod = _T("Double Threshold"); break;
		case EAdaptive	: strMethod = _T("Adaptive Threshold"); break;
	}

	info.stImg.stThreshold.strType = strMethod;

	CFormThdSpl* pSpl = (CFormThdSpl*)m_pFormSpl;
	CFormThdDbl* pDbl = (CFormThdDbl*)m_pFormDbl;
	CFormThdAdt* pAdt = (CFormThdAdt*)m_pFormAdt;

	pSpl->GetParameter(info);
	pDbl->GetParameter(info);
	pAdt->GetParameter(info);
}

void CFormThreshold::SetParameter(StLibrary info)
{
	if (info.stImg.stThreshold.strType == _T("Simple Threshold"))
	{
		CheckRadioButton(IDC_THD_RBTN_SIMPLE, IDC_THD_RBTN_ADAPTIVE, IDC_THD_RBTN_SIMPLE);
		FormSwitching(ESimple);
	}
	else if (info.stImg.stThreshold.strType == _T("Double Threshold"))
	{
		CheckRadioButton(IDC_THD_RBTN_SIMPLE, IDC_THD_RBTN_ADAPTIVE, IDC_THD_RBTN_DOUBLE);
		FormSwitching(EDouble);
	}
	else if (info.stImg.stThreshold.strType == _T("Adaptive Threshold"))
	{
		CheckRadioButton(IDC_THD_RBTN_SIMPLE, IDC_THD_RBTN_ADAPTIVE, IDC_THD_RBTN_ADAPTIVE);
		FormSwitching(EAdaptive);
	}

	CFormThdSpl* pSpl = (CFormThdSpl*)m_pFormSpl;
	CFormThdDbl* pDbl = (CFormThdDbl*)m_pFormDbl;
	CFormThdAdt* pAdt = (CFormThdAdt*)m_pFormAdt;

	pSpl->SetParameter(info);
	pDbl->SetParameter(info);
	pAdt->SetParameter(info);
}