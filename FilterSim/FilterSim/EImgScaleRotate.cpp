#include "StdAfx.h"
#include "EImgScaleRotate.h"

CString CEImgScaleRotate::m_strLastErr;

CEImgScaleRotate::CEImgScaleRotate(void)
{
}


CEImgScaleRotate::~CEImgScaleRotate(void)
{
}

bool CEImgScaleRotate::ScaleRotate(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, float fSrcPviotX, float fSrcPviotY, float fDstPviotX, float fDstPviotY, float fScaleX, float fScaleY, float fAngle, int nBits, double &dTime)
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
			EasyImage::ScaleRotate(pIn->GetImage(), fSrcPviotX, fSrcPviotY, fDstPviotX, fDstPviotY, fScaleX, fScaleY, fAngle, pOut->GetImage(), nBits);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ScaleRotate(pIn->GetImage(), fSrcPviotX, fSrcPviotY, fDstPviotX, fDstPviotY, fScaleX, fScaleY, fAngle, pOut->GetROI(strOut), nBits);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ScaleRotate(pIn->GetROI(strIn), fSrcPviotX, fSrcPviotY, fDstPviotX, fDstPviotY, fScaleX, fScaleY, fAngle, pOut->GetImage(), nBits);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ScaleRotate(pIn->GetROI(strIn), fSrcPviotX, fSrcPviotY, fDstPviotX, fDstPviotY, fScaleX, fScaleY, fAngle, pOut->GetROI(strOut), nBits);
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