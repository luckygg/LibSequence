#include "StdAfx.h"
#include "EImgFilter.h"


CEImgFilter::CEImgFilter(void)
{
}


CEImgFilter::~CEImgFilter(void)
{
}


bool CEImgFilter::OnFilter_Uniform(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolUniform(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform3x3(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolUniform(pIn, pOut, 1);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform5x5(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolUniform(pIn, pOut, 2);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform7x7(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolUniform(pIn, pOut, 3);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGaussian(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian3x3(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGaussian(pIn, pOut, 1);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian5x5(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGaussian(pIn, pOut, 2);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian7x7(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGaussian(pIn, pOut, 3);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass1(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLowpass1(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass2(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLowpass2(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass3(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLowpass3(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Highpass1(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolHighpass1(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Highpass2(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolHighpass2(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gradient(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGradient(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_GradientX(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGradientX(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_GradientY(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolGradientY(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Sobel(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolSobel(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_SobelX(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolSobelX(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_SobelY(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolSobelY(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Prewitt(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolPrewitt(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_PrewittX(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolPrewittX(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_PrewittY(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolPrewittY(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Roberts(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolRoberts(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_LaplacianX(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLaplacianX(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_LaplacianY(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLaplacianY(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Laplacian4(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLaplacian4(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Laplacian8(EImageBW8 *pIn, EImageBW8 *pOut, double &dtime)
{
	try
	{
		CStopWatch time;
		time.Start();
		EasyImage::ConvolLaplacian8(pIn, pOut);
		time.Stop();
		dtime = time.GetTimeMs();
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}