#pragma once

#include "Open_eVision_2_0.h"
using namespace Euresys::Open_eVision_2_0;

class CImgInfo
{
private :
	EImageBW8 Img;
	CString Name;

public :
	EImageBW8* GetImage() { return &Img; }

	bool GetWidth(int &nValue)
	{
		try
		{
			int value=0;
			value = Img.GetWidth();
			nValue = value;

			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}
	
	bool GetHeight(int &nValue)
	{
		try
		{
			int value=0;
			value = Img.GetHeight();
			nValue = value;

			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}

	bool CreatImage(int nWidth, int nHeight, int nBpp)
	{
		try
		{
			Img.SetSize(nWidth,nHeight);
			EasyImage::Oper(EArithmeticLogicOperation_Copy, EBW8(0), &Img);
			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}

	bool SetImage (EImageBW8 *pImg)
	{
		try
		{
			EasyImage::Oper(EArithmeticLogicOperation_Copy, pImg, &Img);
			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}

	void SetFileName(CString strName) { Name = strName; }
	CString GetFileName() { return Name; }

	void clear()
	{
		Name = _T("");
	}
};