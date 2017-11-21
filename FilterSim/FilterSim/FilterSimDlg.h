
// FilterSimDlg.h : header file
//

#pragma once
#include "Base.h"
#include "Open_eVision_2_1.h"
#include "include/UI/ListEx.h"
#include "include/Base/FileDialogEx.h"
#include <vector>
#include "EImage.h"
#include "EImgConvolution.h"
#include "EImgMorphology.h"
#include "EImgThreshold.h"
#include "EImgArithmetic.h"
#include "EImgScaleRotate.h"
#include "EImgGainOffset.h"
#include "EMatrix.h"


using namespace Euresys::Open_eVision_2_1;
using namespace std;

struct StItemInfo
{
	BOOL bUse;
	CString strType;
	CString strIn1;
	CString strIn2;
	CString strOut;
	int nY8_In1;
	int nY8_In2;
	StRGB stRGB_In1;
	StRGB stRGB_In2;
	StLibrary stLib;
};

#include "FormImage.h"
#include "FormMatrix.h"

// CFilterSimDlg dialog
class CFilterSimDlg : public CDialogEx
{
	enum eAlgorithm {ENone=-1, EEasyImage=0, EEasyMatrix};
// Construction
public:
	CFilterSimDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FILTERSIM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public :
	void SetEnableIOList(bool bIn1Img, bool bIn1Cst, bool bIn2Img, bool bIn2Cst, bool bOutImg);
private :
	// Picture Control 및 Input / Output 콤보박스 리스트 재정렬.
	void UpdateCBList();
	// List Control 의 아이템 개수 만큼 Input / Output 재입력.
	void UpdateItemList();
	// Tab 에서 Input / Output / Lib 입력 후 Apply 누르면 저장되는 부분.
	void UpdateItem(int nRow, BOOL bUse, CString strAlgorithm, CString strIn1, CString strIn2, CString strOut, StLibrary stLib);
	// Enable 설정에 따라 Green / Red 표기 부분.
	void UpdateItemColor();
	// 선택된 Combo Image 에 따라 모든 Picture Control 을 갱신하는 부분.
	void UpdateAllView();
	// 선택된 Combo Image 파일 이름과 입력된 이미지 파일이 동일한 Picture Control 만 갱신하는 부분.
	void UpdateFileNameView(CString strFile);
	// 선택된 Combo Box 의 문자열 얻기.
	CString GetTextCBSelected(UINT ID);
	// 입력된 문자열로 Combo Box 의 텍스트 설정하기.
	void SetCBItembyText(UINT ID, CString strText);
	// 이미지 정보 vector 에 중복되는 파일명이 있는지 확인.
	bool IsExistName(CString strName);

	
private :
	CView* m_pFormImg;
	CView* m_pFormMtx;
	
	CListEx m_wndLc;
	
	std::vector<CEImage> m_vImgInfo;
	std::vector<StItemInfo> m_vItmInfo;

	int m_nImgCnt;
	
	// Radio Button
	int m_rbtnIn1;
	int m_rbtnIn2;
	int m_rbtnCst1;
	int m_rbtnCst2;
	void InitContorls();
	void DrawImage(int nViewIdx, CString strFileName);
	void DrawEmptyImage(int nViewIdx);
	void FormSwitching(eAlgorithm eType);
	void OnExecute();

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAddItem();
	afx_msg void OnBnClickedBtnDelList();
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnCbnSelchangeCbView1();
	afx_msg void OnCbnSelchangeCbView2();
	afx_msg void OnCbnSelchangeCbView3();
	afx_msg void OnCbnSelchangeCbView4();
	afx_msg void OnBnClickedBtnExecute();
	afx_msg void OnBnClickedBtnNewImg();
	afx_msg void OnBnClickedBtnDelimg();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtnSaveimg();
	afx_msg void OnNMClickMainLcItem(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelchangeMainCbLib();
	afx_msg void OnBnClickedMainBtnApply();
	afx_msg void OnBnClickedMainBtnAddroi();
	afx_msg void OnBnClickedMainBtnModify();
	afx_msg void OnBnClickedMainBtnDelroi();
	afx_msg void OnCbnSelchangeMainCbImglist();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedMainRBtnImgCst1(UINT ID);
	afx_msg void OnBnClickedMainRBtnImgCst2(UINT ID);
	afx_msg void OnBnClickedMainRBtnGrayClr1(UINT ID);
	afx_msg void OnBnClickedMainRBtnGrayClr2(UINT ID);
	
};
