#include "StdAfx.h"
#include "EImgFilter.h"


CEImgFilter::CEImgFilter(void)
{
}


CEImgFilter::~CEImgFilter(void)
{
}


bool CEImgFilter::OnFilter_Uniform(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolUniform(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform3x3(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolUniform(pIn, pOut, 1);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform5x5(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolUniform(pIn, pOut, 2);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Uniform7x7(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolUniform(pIn, pOut, 3);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGaussian(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian3x3(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGaussian(pIn, pOut, 1);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian5x5(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGaussian(pIn, pOut, 2);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gaussian7x7(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGaussian(pIn, pOut, 3);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass1(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLowpass1(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass2(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLowpass2(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Lowpass3(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLowpass3(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Highpass1(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolHighpass1(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Highpass2(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolHighpass2(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Gradient(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGradient(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_GradientX(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGradientX(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_GradientY(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolGradientY(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Sobel(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolSobel(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_SobelX(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolSobelX(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_SobelY(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolSobelY(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Prewitt(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolPrewitt(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_PrewittX(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolPrewittX(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_PrewittY(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolPrewittY(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Roberts(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolRoberts(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_LaplacianX(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLaplacianX(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_LaplacianY(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLaplacianY(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Laplacian4(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLaplacian4(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgFilter::OnFilter_Laplacian8(EImageBW8 *pIn, EImageBW8 *pOut)
{
	try
	{
		EasyImage::ConvolLaplacian8(pIn, pOut);
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}