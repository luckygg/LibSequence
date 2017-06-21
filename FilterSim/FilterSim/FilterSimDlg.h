
// FilterSimDlg.h : header file
//

#pragma once
#include "Open_eVision_2_0.h"
#include "include/UI/ListEx.h"
#include "include/Base/FileDialogEx.h"
#include <vector>
#include "ImgInfo.h"
#include "EImgFilter.h"



using namespace Euresys::Open_eVision_2_0;
using namespace std;

struct StItemInfo
{
	BOOL bUse;
	CString strType;
	CString strInput;
	CString strOutput;
};

#include "FormTab1.h"

// CFilterSimDlg dialog
class CFilterSimDlg : public CDialogEx
{
	
// Construction
public:
	CFilterSimDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FILTERSIM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

public :
	void UpdateItem(int nRow, BOOL bUse, CString strAlgorithm, CString strIn, CString strOut);
	void UpdateItemColor();
	void OnSwitchForm();
private :
	CView* m_pFormTab1;
	int m_nImgCnt;
	std::vector<CImgInfo> m_vImgInfo;
	std::vector<StItemInfo> m_vItmInfo;
	CListEx m_wndLc;
	int m_nSelected;
	void InitContorls();
	void DrawImage(int nViewIdx, CString strFileName);
	CString GetTextCBSelected(UINT ID);

	void UpdateCBList();
	
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAddList();
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
};
