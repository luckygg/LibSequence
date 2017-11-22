#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"

class CEImgScaleRotate
{
public:
	CEImgScaleRotate(void);
	~CEImgScaleRotate(void);

private :
	static CString m_strLastErr;

public :
	//----- Last Error Message -----//
	static CString GetLastErrMsg() { return m_strLastErr; }

public :
	static bool ScaleRotate(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, float fSrcPviotX, float fSrcPviotY, float fDstPviotX, float fDstPviotY, float fScaleX, float fScaleY, float fAngle, int nBits, double &dTime);
	
};

