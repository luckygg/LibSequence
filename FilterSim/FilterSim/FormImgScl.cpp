// FormImgScl.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FormImgScl.h"


// CFormImgScl

IMPLEMENT_DYNCREATE(CFormImgScl, CFormView)

CFormImgScl::CFormImgScl()
	: CFormView(CFormImgScl::IDD)
{

}

CFormImgScl::~CFormImgScl()
{
}

void CFormImgScl::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFormImgScl, CFormView)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CFormImgScl diagnostics

#ifdef _DEBUG
void CFormImgScl::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormImgScl::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormImgScl message handlers


void CFormImgScl::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	MoveWindow(m_wndRc.left,m_wndRc.top,m_wndRc.Width(),m_wndRc.Height());
}

BOOL CFormImgScl::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	m_wndRc = rect;

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CFormImgScl::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class
}
