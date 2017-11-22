#include "StdAfx.h"
#include "EMatrix.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CEMatrix::CEMatrix(void)
{
	m_strLastErr = _T("No Error.");
}


CEMatrix::~CEMatrix(void)
{
}


bool CEMatrix::SetTimeoutMicroSec(int nTime)
{
	try
	{
		m_MtxReader.SetTimeOut(nTime);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEMatrix::OnExecute(EImageBW8 *pSrc, CString &strResult, double &dTime)
{
	if (pSrc == NULL) return false;
	try
	{
		CStopWatch time;
		time.Start();
		m_MtxResult = m_MtxReader.Read(*pSrc);
		time.Stop();
		dTime = time.GetTimeMs();

		std::string result = m_MtxResult.GetDecodedString();
		strResult = (CString)result.c_str();

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		strResult = _T("None");
		return false;
	}
}

bool CEMatrix::OnExecute(EROIBW8 *pSrc, CString &strResult, double &dTime)
{
	if (pSrc == NULL) return false;
	try
	{
		CStopWatch time;
		time.Start();
		m_MtxResult = m_MtxReader.Read(*pSrc);
		time.Stop();
		dTime = time.GetTimeMs();

		std::string result = m_MtxResult.GetDecodedString();
		strResult = (CString)result.c_str();

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		strResult = _T("None");
		return false;
	}
}

bool CEMatrix::OnDrawResult(CWnd* pCWnd, bool bErr, float fH, float fV)
{
	try
	{
		if (pCWnd == NULL) return false;
		
		HDC hDC = pCWnd->GetDC()->GetSafeHdc();
		CRect rect;
		pCWnd->GetClientRect(&rect);

		m_MtxResult.Draw(hDC,fH,fV);

		if (bErr == true)
			m_MtxResult.DrawErrors(hDC, fH, fV);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}