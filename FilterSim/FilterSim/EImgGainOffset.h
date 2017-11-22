#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"

class CEImgGainOffset
{
public:
	CEImgGainOffset(void);
	~CEImgGainOffset(void);

private :
	static CString m_strLastErr;

public :
	//----- Last Error Message -----//
	static CString GetLastErrMsg() { return m_strLastErr; }

public :
	static bool GainOffset(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, float fGain, float fOffset, double &dTime);
};

