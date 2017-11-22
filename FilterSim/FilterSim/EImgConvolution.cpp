#include "StdAfx.h"
#include "EImgConvolution.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString CEImgConvolution::m_strLastErr;

CEImgConvolution::CEImgConvolution(void)
{
}


CEImgConvolution::~CEImgConvolution(void)
{
}


bool CEImgConvolution::Uniform(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Uniform3x3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Uniform5x5(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Uniform7x7(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Gaussian(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Gaussian3x3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Gaussian5x5(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Gaussian7x7(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Lowpass1(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Lowpass2(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Lowpass3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Highpass1(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Highpass2(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Gradient(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::GradientX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::GradientY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Sobel(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::SobelX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::SobelY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Prewitt(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::PrewittX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::PrewittY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Roberts(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::LaplacianX(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::LaplacianY(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Laplacian4(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgConvolution::Laplacian8(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
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
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}