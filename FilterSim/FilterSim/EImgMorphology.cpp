#include "StdAfx.h"
#include "EImgMorphology.h"


CEImgMorphology::CEImgMorphology(void)
{
}


CEImgMorphology::~CEImgMorphology(void)
{
}

bool CEImgMorphology::Erode(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::ErodeBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ErodeBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ErodeBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ErodeBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::Dilate(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::DilateBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::DilateBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::DilateBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::DilateBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::Open(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::OpenBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::OpenBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::OpenBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::OpenBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::Close(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::CloseBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::CloseBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::CloseBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::CloseBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::WhiteTopHat(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::WhiteTopHatBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::WhiteTopHatBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::WhiteTopHatBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::WhiteTopHatBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::BlackTopHat(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::BlackTopHatBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::BlackTopHatBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::BlackTopHatBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::BlackTopHatBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::Gradient(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime)
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
			EasyImage::MorphoGradientBox(pIn->GetImage(), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::MorphoGradientBox(pIn->GetImage(), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::MorphoGradientBox(pIn->GetROI(strIn), pOut->GetImage(), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::MorphoGradientBox(pIn->GetROI(strIn), pOut->GetROI(strOut), nHalfKernel);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgMorphology::Median3x3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::Median(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Median(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Median(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Median(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}