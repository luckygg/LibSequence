#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"
class CEImgFilter
{
public:
	CEImgFilter(void);
	~CEImgFilter(void);

public :
	static bool OnFilter_Uniform	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Uniform3x3	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Uniform5x5	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Uniform7x7	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Gaussian	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Gaussian3x3(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Gaussian5x5(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Gaussian7x7(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Lowpass1	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Lowpass2	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Lowpass3	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Highpass1	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Highpass2	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Gradient	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_GradientX	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_GradientY	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Sobel		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_SobelX		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_SobelY		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Prewitt	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_PrewittX	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_PrewittY	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Roberts	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_LaplacianX	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_LaplacianY	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Laplacian4	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool OnFilter_Laplacian8	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
};

