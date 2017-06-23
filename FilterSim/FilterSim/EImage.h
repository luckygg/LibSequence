#pragma once

#include "Open_eVision_2_0.h"
using namespace Euresys::Open_eVision_2_0;

class CEImage
{
private :
	EImageBW8 Img;
	std::vector<EROIBW8> Roi;
public :
	EImageBW8* GetImage() { return &Img; }
	bool GetRoiPlacement(CString strName, int &nOrgX, int &nOrgY, int &nWidth, int &nHeight);
	bool OnLoadImage(CString strPath);
	bool OnDrawImage(CWnd* pCWnd, float fH=1.0, float fV=1.0);
	bool OnDrawROIFrame(CWnd* pCWnd, float fH=1.0, float fV=1.0);
	bool CreateRoi(int nOrgX, int nOrgY, int nWidth, int nHeight, CString strName=_T(""));
	void DeleteRoi(CString strName=_T(""));
	bool GetRoiName(int nIdx, CString &strValue);
	bool GetWidth(int &nValue);
	bool GetHeight(int &nValue);
	bool CreatImage(int nWidth, int nHeight, int nBpp);
	bool SetImage (EImageBW8 *pImg);
	bool SetFileName(CString strName);
	bool GetFileName(CString &strValue);
	int GetRoiCount();
	void clear();
};