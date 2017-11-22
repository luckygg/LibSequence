#include "StdAfx.h"
#include "EImgGainOffset.h"

CString CEImgGainOffset::m_strLastErr;

CEImgGainOffset::CEImgGainOffset(void)
{
	m_strLastErr = _T("No Error.");
}


CEImgGainOffset::~CEImgGainOffset(void)
{
}

bool CEImgGainOffset::GainOffset(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, float fGain, float fOffset, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString nameIn=_T(""),nameOut=_T("");

		pIn->GetImageName(nameIn);
		pOut->GetImageName(nameOut);

		if (nameIn == strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::GainOffset(pIn->GetImage(), pOut->GetImage(), fGain, fOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::GainOffset(pIn->GetImage(), pOut->GetROI(strOut), fGain, fOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::GainOffset(pIn->GetROI(strIn), pOut->GetImage(), fGain, fOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::GainOffset(pIn->GetROI(strIn), pOut->GetROI(strOut), fGain, fOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}