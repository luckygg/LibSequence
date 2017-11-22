#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"

class CEImgThreshold
{
public:
	CEImgThreshold(void);
	~CEImgThreshold(void);

private :
	static CString m_strLastErr;

public :
	//----- Last Error Message -----//
	static CString GetLastErrMsg() { return m_strLastErr; }

public :
	static bool ThresholdABS(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nThreshold, double &dTime);
	static bool ThresholdRelative(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, float fRelative, double &dTime);
	static bool ThresholdMinResidue(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool ThresholdMaxEntropy(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool ThresholdIsoData(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool ThresholdDouble(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nPxlHigh, int nThdHigh, int nPxlMid, int nThdLow, int nPxlLow, double &dTime);
	static bool ThresholdAdaptiveMean(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, int nOffset, double &dTime);
	static bool ThresholdAdaptiveMedian(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, int nOffset, double &dTime);
	static bool ThresholdAdaptiveMiddle(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, int nHalfKernel, int nOffset, double &dTime);
};

