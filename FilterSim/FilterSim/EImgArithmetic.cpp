#include "StdAfx.h"
#include "EImgArithmetic.h"

CString CEImgArithmetic::m_strLastErr;

CEImgArithmetic::CEImgArithmetic(void)
{
	m_strLastErr = _T("No Error.");
}


CEImgArithmetic::~CEImgArithmetic(void)
{
}

bool CEImgArithmetic::Oper_Copy(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString nameIn=_T(""),nameOut=_T("");

		pIn->GetImageName(nameIn);
		pOut->GetImageName(nameOut);
		if (nameIn == strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Copy, pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Copy, pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Copy, pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Copy, pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImgArithmetic::Oper_Invert(CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString nameIn=_T(""),nameOut=_T("");

		pIn->GetImageName(nameIn);
		pOut->GetImageName(nameOut);
		if (nameIn == strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Invert, pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn == strIn && nameOut != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Invert, pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else if (nameIn != strIn && nameOut == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Invert, pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		else
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Invert, pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Add(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Add(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		
		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Add(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Add, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Subtract(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Subtract(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Subtract(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Subtract, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Compare(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Compare(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Compare(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Compare, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Multiply(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Multiply(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Multiply(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Multiply, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Divide(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Divide(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Divide(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Divide, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Modulo(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Modulo(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Modulo(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Modulo, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledAdd(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledAdd(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledAdd(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledAdd, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledSubtract(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledSubtract(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledSubtract(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledSubtract, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledMultiply(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledMultiply(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledMultiply(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledMultiply, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledDivide(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledDivide(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ScaledDivide(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ScaledDivide, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ShiftLeft(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftLeft, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftLeft, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftLeft, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftLeft, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_ShiftRight(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftRight, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftRight, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftRight, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_ShiftRight, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseAND(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseAND(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseAND(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseAnd, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseOR(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseOr, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseXOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseXOR(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_BitwiseXOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_BitwiseXor, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LogicalAND(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LogicalAND(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalAnd, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LogicalOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LogicalOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalOr, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LogicalXOR(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LogicalXOR(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LogicalXor, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Minimum(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Minimum(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Minimum(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Min, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Maximum(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Maximum(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Maximum(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Max, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_SetZero(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_SetZero(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_SetZero(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetZero, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_SetNonZero(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_SetNonZero(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_SetNonZero, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Equal(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Equal(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Equal(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Equal, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_NotEqual(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_NotEqual(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_NotEqual(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_NotEqual, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_GreaterOrEqual(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_GreaterOrEqual(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_GreaterOrEqual(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_GreaterOrEqual, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LesserOrEqual(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LesserOrEqual(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_LesserOrEqual(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_LesserOrEqual, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Greater(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Greater(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Greater(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Greater, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Lesser(CEImage *pIn1, CString strIn1, CEImage *pIn2, CString strIn2, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn1 == NULL || pIn2 == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In1=_T(""),In2=_T(""),Out=_T("");

		pIn1->GetImageName(In1);
		pIn2->GetImageName(In2);
		pOut->GetImageName(Out);

		//000
		if (In1 == strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetImage(), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//001
		else if (In1 == strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetImage(), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//010
		else if (In1 == strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//011
		else if (In1 == strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetImage(), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//100
		else if (In1 != strIn1 && In2 == strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//101
		else if (In1 != strIn1 && In2 == strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetROI(strIn1), pIn2->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//110
		else if (In1 != strIn1 && In2 != strIn2 && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		//111
		else if (In1 != strIn1 && In2 != strIn2 && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn1->GetROI(strIn1), pIn2->GetROI(strIn2), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Lesser(CEImage *pIn, CString strIn, int nY8, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn->GetImage(), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn->GetImage(), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn->GetROI(strIn), EBW8(nY8), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, pIn->GetROI(strIn), EBW8(nY8), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImgArithmetic::Oper_Lesser(int nY8, CEImage *pIn, CString strIn, CEImage *pOut, CString strOut, double &dTime)
{
	if (pIn == NULL || pOut == NULL) return false;
	try
	{
		CStopWatch time;
		CString In=_T(""),Out=_T("");

		pIn->GetImageName(In);
		pOut->GetImageName(Out);

		// 00
		if (In == strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, EBW8(nY8), pIn->GetImage(), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 01
		else if (In == strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, EBW8(nY8), pIn->GetImage(), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 10
		else if (In != strIn && Out == strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, EBW8(nY8), pIn->GetROI(strIn), pOut->GetImage());
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}
		// 11
		else if (In != strIn && Out != strOut)
		{
			time.Start();
			EasyImage::Oper(EArithmeticLogicOperation_Lesser, EBW8(nY8), pIn->GetROI(strIn), pOut->GetROI(strOut));
			time.Stop();
			dTime = time.GetTimeMs();
			return true;
		}

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}