#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"

class CEImgMorphology
{
public:
	CEImgMorphology(void);
	~CEImgMorphology(void);

private :
	static CString m_strLastErr;

public :
	//----- Last Error Message -----//
	CString GetLastErrMsg() { return m_strLastErr; }

public :
	static bool Erode		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool Dilate		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool Open		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool Close		(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool WhiteTopHat	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool BlackTopHat	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool Gradient	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, double &dTime);
	static bool Median3x3	(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
};

