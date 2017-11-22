#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"

class CEMatrix
{
public:
	CEMatrix(void);
	~CEMatrix(void);

private :
	CString m_strLastErr;

public :
	//----- Last Error Message -----//
	CString GetLastErrMsg() { return m_strLastErr; }

public :
	bool SetTimeoutMicroSec(int nTime);
	bool OnExecute(EImageBW8 *pSrc, CString &strResult, double &dTime);
	bool OnExecute(EROIBW8 *pSrc, CString &strResult, double &dTime);
	bool OnDrawResult(CWnd* pCWnd, bool bErr, float fH=1.0, float fV=1.0);
private :
	EMatrixCodeReader m_MtxReader;
	EMatrixCode m_MtxResult;
};

