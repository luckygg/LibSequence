#include "StdAfx.h"
#include "EImgThreshold.h"

CString CEImgThreshold::m_strLastErr;

CEImgThreshold::CEImgThreshold(void)
{
	m_strLastErr = _T("No Error.");
}


CEImgThreshold::~CEImgThreshold(void)
{
}

bool CEImgThreshold::ThresholdABS(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nThreshold, double &dTime)
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
			EasyImage::Threshold(pIn->GetImage(), pOut->GetImage(), nThreshold);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetImage(), pOut->GetROI(strOut), nThreshold);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetImage(), nThreshold);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetROI(strOut), nThreshold);
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

bool CEImgThreshold::ThresholdRelative(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, float fRelative, double &dTime)
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
			EasyImage::Threshold(pIn->GetImage(), pOut->GetImage(), EThresholdMode_Relative, 0, 255, fRelative);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetImage(), pOut->GetROI(strOut), EThresholdMode_Relative, 0, 255, fRelative);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetImage(), EThresholdMode_Relative, 0, 255, fRelative);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EThresholdMode_Relative, 0, 255, fRelative);
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

bool CEImgThreshold::ThresholdMinResidue(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::Threshold(pIn->GetImage(), pOut->GetImage(), EThresholdMode_MinResidue);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetImage(), pOut->GetROI(strOut), EThresholdMode_MinResidue);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetImage(), EThresholdMode_MinResidue);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EThresholdMode_MinResidue);
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

bool CEImgThreshold::ThresholdMaxEntropy(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::Threshold(pIn->GetImage(), pOut->GetImage(), EThresholdMode_MaxEntropy);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetImage(), pOut->GetROI(strOut), EThresholdMode_MaxEntropy);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetImage(), EThresholdMode_MaxEntropy);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EThresholdMode_MaxEntropy);
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

bool CEImgThreshold::ThresholdIsoData(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::Threshold(pIn->GetImage(), pOut->GetImage(), EThresholdMode_Isodata);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetImage(), pOut->GetROI(strOut), EThresholdMode_Isodata);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetImage(), EThresholdMode_Isodata);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Threshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EThresholdMode_Isodata);
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

bool CEImgThreshold::ThresholdDouble(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nPxlHigh, int nThdHigh, int nPxlMid, int nThdLow, int nPxlLow, double &dTime)
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
			EasyImage::DoubleThreshold(pIn->GetImage(), pOut->GetImage(), nThdLow, nThdHigh, nPxlLow, nPxlMid, nPxlHigh);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::DoubleThreshold(pIn->GetImage(), pOut->GetROI(strOut), nThdLow, nThdHigh, nPxlLow, nPxlMid, nPxlHigh);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::DoubleThreshold(pIn->GetROI(strIn), pOut->GetImage(), nThdLow, nThdHigh, nPxlLow, nPxlMid, nPxlHigh);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::DoubleThreshold(pIn->GetROI(strIn), pOut->GetROI(strOut), nThdLow, nThdHigh, nPxlLow, nPxlMid, nPxlHigh);
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

bool CEImgThreshold::ThresholdAdaptiveMean(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, int nOffset, double &dTime)
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
			EasyImage::AdaptiveThreshold(pIn->GetImage(), pOut->GetImage(), EAdaptiveThresholdMethod_Mean, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetImage(), pOut->GetROI(strOut), EAdaptiveThresholdMethod_Mean, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetROI(strIn), pOut->GetImage(), EAdaptiveThresholdMethod_Mean, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EAdaptiveThresholdMethod_Mean, nHalfKernel, nOffset);
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

bool CEImgThreshold::ThresholdAdaptiveMedian(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, int nOffset, double &dTime)
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
			EasyImage::AdaptiveThreshold(pIn->GetImage(), pOut->GetImage(), EAdaptiveThresholdMethod_Median, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetImage(), pOut->GetROI(strOut), EAdaptiveThresholdMethod_Median, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetROI(strIn), pOut->GetImage(), EAdaptiveThresholdMethod_Median, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EAdaptiveThresholdMethod_Median, nHalfKernel, nOffset);
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

bool CEImgThreshold::ThresholdAdaptiveMiddle(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, int nOffset, double &dTime)
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
			EasyImage::AdaptiveThreshold(pIn->GetImage(), pOut->GetImage(), EAdaptiveThresholdMethod_Middle, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetImage(), pOut->GetROI(strOut), EAdaptiveThresholdMethod_Middle, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetROI(strIn), pOut->GetImage(), EAdaptiveThresholdMethod_Middle, nHalfKernel, nOffset);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::AdaptiveThreshold(pIn->GetROI(strIn), pOut->GetROI(strOut), EAdaptiveThresholdMethod_Middle, nHalfKernel, nOffset);
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