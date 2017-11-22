#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"
class CEImgConvolution
{
public:
	CEImgConvolution(void);
	~CEImgConvolution(void);

private :
	static CString m_strLastErr;

public :
	//----- Last Error Message -----//
	static CString GetLastErrMsg() { return m_strLastErr; }

	static bool Uniform		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Uniform3x3	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Uniform5x5	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Uniform7x7	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Gaussian	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Gaussian3x3	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Gaussian5x5	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Gaussian7x7	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Lowpass1	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Lowpass2	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Lowpass3	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Highpass1	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Highpass2	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Gradient	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool GradientX	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool GradientY	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Sobel		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool SobelX		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool SobelY		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Prewitt		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool PrewittX	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool PrewittY	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Roberts		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool LaplacianX	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool LaplacianY	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Laplacian4	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Laplacian8	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
};

