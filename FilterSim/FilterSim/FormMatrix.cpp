// FormMatrix.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormMatrix.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CFormMtx

IMPLEMENT_DYNCREATE(CFormMtx, CFormView)

CFormMtx::CFormMtx()
	: CFormView(CFormMtx::IDD)
{

}

CFormMtx::~CFormMtx()
{
}

void CFormMtx::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormMtx, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CFormMtx diagnostics

#ifdef _DEBUG
void CFormMtx::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormMtx::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormMtx message handlers


void CFormMtx::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	
}

BOOL CFormMtx::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormMtx::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}
