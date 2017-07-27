#pragma once

#include "Open_eVision_2_1.h"
using namespace Euresys::Open_eVision_2_1;

class CEImage
{
private :
	EImageBW8 m_EImgBW8;
	std::vector<EROIBW8> m_vERoiBW8;
	
public :
	CEImage* GetEImage() { return this; }
	EImageBW8* GetImage() { return &m_EImgBW8; }
	EROIBW8* GetROI(CString strName);
	
	//----- Drawing -----//
	bool OnDrawImage(CWnd* pCWnd, float fH=1.0, float fV=1.0);
	bool OnDrawROIFrame(CWnd* pCWnd, float fH=1.0, float fV=1.0);
	
	//----- Image -----//
	bool CreatImage(int nWidth, int nHeight, int nBpp);
	bool SetImage (EImageBW8 *pImg);
	bool OnLoadImage(CString strPath);
	bool SetImageName(CString strName);
	bool GetImageName(CString &strValue);
	bool GetWidth(int &nValue);
	bool GetHeight(int &nValue);

	//----- ROI -----//
	bool CreateRoi(int nOrgX, int nOrgY, int nWidth, int nHeight, CString strName=_T(""));
	void DeleteRoi(CString strName=_T(""));
	bool GetRoiName(int nIdx, CString &strValue);
	int GetRoiCount();
	bool ModifyRoi(CString strName, int nOrgX, int nOrgY, int nWidth, int nHeight);
	bool GetRoiPlacement(CString strName, int &nOrgX, int &nOrgY, int &nWidth, int &nHeight);
	bool HasROI(CString strName);
};