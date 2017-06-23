#include "StdAfx.h"
#include "EImage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool CEImage::OnLoadImage(CString strPath)
{
	try
	{
		CT2CA String (strPath);
		std::string str(String);  

		Img.Load(str);

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImage::OnDrawImage(CWnd* pCWnd, float fH, float fV)
{
	try
	{
		if (pCWnd == NULL) return false;

		HDC hDC = pCWnd->GetDC()->GetSafeHdc();
		CRect rect;
		pCWnd->GetClientRect(&rect);

		Img.Draw(hDC,fH,fV);

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}

bool CEImage::OnDrawROIFrame(CWnd* pCWnd, float fH, float fV)
{
	try
	{
		if (pCWnd == NULL) return false;

		HDC hDC = pCWnd->GetDC()->GetSafeHdc();
		CRect rect;
		pCWnd->GetClientRect(&rect);

		std::vector<EBaseROI*> rois = Img.GetSubBaseROIs();

		for (int i=0; i<(int)rois.size(); i++)
		{
			EROIBW8* pRoi = (EROIBW8*)rois.at(i);
			pRoi->DrawFrame(hDC,false,fH,fV);
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

bool CEImage::CreateRoi(int nOrgX, int nOrgY, int nWidth, int nHeight, CString strName)
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

void CEImage::DeleteRoi(CString strName)
{
	std::vector<EBaseROI*> rois = Img.GetSubBaseROIs();
	
	for (int i=0; i<(int)rois.size(); i++)
	{
		EROIBW8* pRoi = (EROIBW8*)rois.at(i);
		if (strName == pRoi->GetTitle().c_str())
			pRoi->Detach();
	}
}

int CEImage::GetRoiCount()
{
	std::vector<EBaseROI*> rois = Img.GetSubBaseROIs();
	return (int)rois.size();
}

bool CEImage::GetRoiName(int nIdx, CString &strValue)
{
	try
	{
		std::vector<EBaseROI*> rois = Img.GetSubBaseROIs();

		if (nIdx >= (int)rois.size()) return false;

		EROIBW8* pRoi = (EROIBW8*)rois.at(nIdx);
		
		strValue = pRoi->GetTitle().c_str();

		return true;
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return false;
	}
}
bool CEImage::GetWidth(int &nValue)
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

bool CEImage::GetHeight(int &nValue)
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

bool CEImage::CreatImage(int nWidth, int nHeight, int nBpp)
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

bool CEImage::SetImage (EImageBW8 *pImg)
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

bool CEImage::SetFileName(CString strName) 
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

bool CEImage::GetFileName(CString &strValue)
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

