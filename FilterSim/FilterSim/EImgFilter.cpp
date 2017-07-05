#include "StdAfx.h"
#include "EImgFilter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CEImgFilter::CEImgFilter(void)
{
}


CEImgFilter::~CEImgFilter(void)
{
}


bool CEImgFilter::OnFilter_Uniform(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetROI(strOut));
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

bool CEImgFilter::OnFilter_Uniform3x3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetImage(), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetROI(strOut), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetImage(), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetROI(strOut), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform5x5(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetImage(), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetROI(strOut), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetImage(), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetROI(strOut), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform7x7(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetImage(), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetImage(), pOut->GetROI(strOut), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetImage(), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolUniform(pIn->GetROI(strIn), pOut->GetROI(strOut), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian3x3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetImage(), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetROI(strOut), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetImage(), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetROI(strOut), 1);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian5x5(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetImage(), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetROI(strOut), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetImage(), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetROI(strOut), 2);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian7x7(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetImage(), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetImage(), pOut->GetROI(strOut), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetImage(), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGaussian(pIn->GetROI(strIn), pOut->GetROI(strOut), 3);
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass1(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLowpass1(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLowpass1(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLowpass1(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLowpass1(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass2(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLowpass2(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLowpass2(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLowpass2(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLowpass2(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLowpass3(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLowpass3(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLowpass3(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLowpass3(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Highpass1(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolHighpass1(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolHighpass1(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolHighpass1(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolHighpass1(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Highpass2(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolHighpass2(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolHighpass2(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolHighpass2(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolHighpass2(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gradient(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGradient(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGradient(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGradient(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGradient(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_GradientX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGradientX(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGradientX(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGradientX(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGradientX(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_GradientY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolGradientY(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolGradientY(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolGradientY(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolGradientY(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Sobel(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolSobel(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolSobel(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolSobel(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolSobel(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_SobelX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolSobelX(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolSobelX(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolSobelX(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolSobelX(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_SobelY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolSobelY(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolSobelY(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolSobelY(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolSobelY(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Prewitt(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolPrewitt(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolPrewitt(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolPrewitt(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolPrewitt(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_PrewittX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolPrewittX(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolPrewittX(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolPrewittX(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolPrewittX(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_PrewittY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolPrewittY(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolPrewittY(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolPrewittY(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolPrewittY(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Roberts(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolRoberts(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolRoberts(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolRoberts(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolRoberts(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_LaplacianX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLaplacianX(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacianX(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacianX(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLaplacianX(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_LaplacianY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLaplacianY(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacianY(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacianY(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLaplacianY(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Laplacian4(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLaplacian4(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacian4(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacian4(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLaplacian4(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Laplacian8(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
			EasyImage::ConvolLaplacian8(pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacian8(pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::ConvolLaplacian8(pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::ConvolLaplacian8(pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}