#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

#include "include\Base\StopWatch.h"
#include "EImage.h"

class CEImgArithmetic
{
public:
	CEImgArithmetic(void);
	~CEImgArithmetic(void);

private :
	static CString m_strLastErr;

public :
	//----- Last Error Message -----//
	static CString GetLastErrMsg() { return m_strLastErr; }

	// In 1
	static bool Oper_Copy(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Invert(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	// In 2
	static bool Oper_Add(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Add(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Add(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Subtract(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Subtract(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Subtract(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Compare(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Compare(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Compare(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Multiply(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Multiply(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Multiply(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Divide(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Divide(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Divide(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Modulo(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Modulo(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Modulo(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_ScaledAdd(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledAdd(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledAdd(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_ScaledSubtract(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledSubtract(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledSubtract(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_ScaledMultiply(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledMultiply(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledMultiply(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_ScaledDivide(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledDivide(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ScaledDivide(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	// In2 BW8 ¸¸
	static bool Oper_ShiftLeft(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_ShiftRight(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	// In 2
	static bool Oper_BitwiseAND(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_BitwiseAND(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_BitwiseAND(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_BitwiseOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_BitwiseOR(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_BitwiseOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_BitwiseXOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_BitwiseXOR(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_BitwiseXOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	// In2 Image¸¸
	static bool Oper_LogicalAND(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_LogicalAND(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_LogicalOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_LogicalOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);
	
	static bool Oper_LogicalXOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_LogicalXOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Minimum(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Minimum(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Minimum(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Maximum(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Maximum(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Maximum(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_SetZero(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_SetZero(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_SetZero(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_SetNonZero(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_SetNonZero(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Equal(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Equal(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Equal(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_NotEqual(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_NotEqual(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_NotEqual(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_GreaterOrEqual(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_GreaterOrEqual(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_GreaterOrEqual(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_LesserOrEqual(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_LesserOrEqual(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_LesserOrEqual(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Greater(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Greater(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Greater(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	static bool Oper_Lesser(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Lesser(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime);
	static bool Oper_Lesser(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime);

	// In2 Image¸¸
	static bool Oper_Overlay(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime);
};

