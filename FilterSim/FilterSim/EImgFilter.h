#pragma once

#include "Open_eVision_2_0.h"
using namespace Euresys::Open_eVision_2_0;

#include "include\Base\StopWatch.h"
class CEImgFilter
{
public:
	CEImgFilter(void);
	~CEImgFilter(void);

public :
	static bool OnFilter_Uniform	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Uniform3x3	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Uniform5x5	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Uniform7x7	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Gaussian	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Gaussian3x3(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Gaussian5x5(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Gaussian7x7(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Lowpass1	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Lowpass2	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Lowpass3	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Highpass1	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Highpass2	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Gradient	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_GradientX	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_GradientY	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Sobel		(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_SobelX		(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_SobelY		(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Prewitt	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_PrewittX	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_PrewittY	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Roberts	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_LaplacianX	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_LaplacianY	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Laplacian4	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
	static bool OnFilter_Laplacian8	(EImageBW8 *pIn, EImageBW8 *pOut, double &dTime);
};

