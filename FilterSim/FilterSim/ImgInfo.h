#pragma once

#include "Open_eVision_2_0.h"
using namespace Euresys::Open_eVision_2_0;

class CImgInfo
{
private :
	EImageBW8 Img;
	std::vector<EROIBW8> Roi;

public :
	EImageBW8* GetImage() { return &Img; }

	bool CreateRoi(int nOrgX, int nOrgY, int nWidth, int nHeight, CString strName=_T(""))
	{
		try
		{
			CT2CA String (strName);
			std::string str(String);  

			EROIBW8 roi;
			roi.Attach(&Img);
			roi.SetPlacement(nOrgX, nOrgY, nWidth, nHeight);
			roi.SetTitle(str);
			Roi.push_back(roi);

			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}
	void DeleteRoi(CString strName=_T(""))
	{
		for (std::vector<EROIBW8>::iterator it = Roi.begin(); it != Roi.end(); )
		{
			if (it->GetTitle().c_str() == strName)
				it = Roi.erase(it);
			else
				++it;
		}
	}
	bool GetRoiCount(int &nValue)
	{
		try
		{
			int value=0;
			value = (int)Roi.size();
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
	bool GetRoiName(int nIdx, CString &strValue)
	{
		try
		{
			CString strName=_T("");
			std::string str = Roi.at(nIdx).GetTitle();
			strValue = (CString)str.c_str();

			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}
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

	bool SetFileName(CString strName) 
	{ 
		try
		{
			CT2CA String (strName);
			std::string str(String);  
			Img.SetTitle(str);

			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}
	bool GetFileName(CString &strValue)
	{ 
		try
		{
			CString strName=_T("");
			std::string str = Img.GetTitle();
			strValue = (CString)str.c_str();

			return true;
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return false;
		}
	}

	void clear()
	{
		Roi.clear();
	}
};