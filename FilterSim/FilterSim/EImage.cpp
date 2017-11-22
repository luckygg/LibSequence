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

		m_EImgBW8.Load(str);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::OnSaveImage(CString strPath)
{
	try
	{
		CT2CA String (strPath);
		std::string str(String);  

		m_EImgBW8.Save(str);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
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

		m_EImgBW8.Draw(hDC,fH,fV);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
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

		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);
		EROIBW8* pRoi = NULL;
		
		for (int i=0; i<(int)pRois.size(); i++)
		{
			pRoi = (EROIBW8*)pRois.at(i);
			if (pRoi == NULL)
				return false;

			pRoi->DrawFrame(hDC,false,fH,fV);
		}

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
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
		roi.Attach(&m_EImgBW8);
		roi.SetPlacement(nOrgX, nOrgY, nWidth, nHeight);
		roi.SetTitle(str);
		
		m_vERoiBW8.push_back(roi);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::ModifyRoi(CString strName, int nOrgX, int nOrgY, int nWidth, int nHeight)
{
	try
	{
		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);

		for (int i=0; i<(int)pRois.size(); i++)
		{
			EROIBW8* pRoi = NULL;
			pRoi = (EROIBW8*)pRois.at(i);
			CString name = (CString)pRoi->GetTitle().c_str();
			if (strName == name)
				pRoi->SetPlacement(nOrgX, nOrgY, nWidth, nHeight);
		}

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

void CEImage::DeleteRoi(CString strName)
{
	try
	{
		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);

		for (int i=0; i<(int)pRois.size(); i++)
		{
			EROIBW8* pRoi = NULL;
			pRoi = (EROIBW8*)pRois.at(i);
			CString name = (CString)pRoi->GetTitle().c_str();
			if (strName == name)
				pRoi->Detach();
		}
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return;
	}
}

int CEImage::GetRoiCount()
{
	std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);
	return (int)pRois.size();
}

bool CEImage::GetRoiName(int nIdx, CString &strValue)
{
	try
	{
		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);

		int nSize = (int)pRois.size();
		if (nIdx >= nSize) return false;

		CString name = _T("");
		EROIBW8* pRoi = NULL;
		
		pRoi = (EROIBW8*)pRois.at(nIdx);
		if (pRoi == NULL) return false;
	
		name = (CString)pRoi->GetTitle().c_str();
		strValue = name;

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::GetWidth(int &nValue)
{
	try
	{
		int value=0;
		value = m_EImgBW8.GetWidth();
		nValue = value;

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::GetHeight(int &nValue)
{
	try
	{
		int value=0;
		value = m_EImgBW8.GetHeight();
		nValue = value;

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::CreatImage(int nWidth, int nHeight, int nBpp)
{
	try
	{
		m_EImgBW8.SetSize(nWidth,nHeight);
		EasyImage::Oper(EArithmeticLogicOperation_Copy, EBW8(0), &m_EImgBW8);
		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::SetImage (EImageBW8 *pImg)
{
	try
	{
		EasyImage::Oper(EArithmeticLogicOperation_Copy, pImg, &m_EImgBW8);
		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::SetImageName(CString strName) 
{ 
	try
	{
		CT2CA String (strName);
		std::string str(String);  
		m_EImgBW8.SetTitle(str);

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::GetImageName(CString &strValue)
{ 
	try
	{
		CString strName=_T("");
		std::string str = m_EImgBW8.GetTitle();
		strValue = (CString)str.c_str();

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

bool CEImage::HasROI(CString strName)
{
	try
	{
		bool bHasRoi = false;

		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);

		for (int i=0; i<(int)pRois.size(); i++)
		{
			CString name = _T("");
			EROIBW8* pRoi = NULL;

			pRoi = (EROIBW8*)pRois.at(i);
			if (pRoi == NULL) return false;

			name = (CString)pRoi->GetTitle().c_str();

			if (strName == name)
			{
				bHasRoi = true;
				break;
			}
		}
		
		return bHasRoi;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}

EROIBW8* CEImage::GetROI(CString strName)
{
	try
	{
		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);
		EROIBW8* pRoi = NULL;
		int size = (int)pRois.size();
		for (int i=0; i<(int)pRois.size(); i++)
		{
			pRoi = (EROIBW8*)pRois.at(i);
			if (pRoi->GetTitle().c_str() == strName)
				break;
		}
		
		return pRoi;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return NULL;
	}
}

bool CEImage::GetRoiPlacement(CString strName, int &nOrgX, int &nOrgY, int &nWidth, int &nHeight)
{
	try
	{
		std::vector<EBaseROI*> pRois = m_EImgBW8.GetSubBaseROIs(TRUE);

		for (int i=0; i<(int)pRois.size(); i++)
		{
			CString name = _T("");
			EROIBW8* pRoi = NULL;

			pRoi = (EROIBW8*)pRois.at(i);
			if (pRoi == NULL) return false;

			name = (CString)pRoi->GetTitle().c_str();

			if (strName == name)
			{
				nOrgX = pRoi->GetOrgX();
				nOrgY = pRoi->GetOrgY();
				nWidth = pRoi->GetWidth();
				nHeight = pRoi->GetHeight();

				break;
			}
		}

		return true;
	}
	catch (EException& e)
	{
		m_strLastErr = (CString)e.What().c_str();
		return false;
	}
}