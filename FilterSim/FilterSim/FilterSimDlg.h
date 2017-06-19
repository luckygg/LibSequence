
// FilterSimDlg.h : header file
//

#pragma once
#include "Open_eVision_2_0.h"
#include "include/UI/ListCtrlEx.h"
#include "include/Base/FileDialogEx.h"

#include "ImgInfo.h"
#include "EImgFilter.h"

using namespace Euresys::Open_eVision_2_0;


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

private :
	int m_nImgCnt;
	std::vector<CImgInfo> m_vImgInfo;
	CListCtrlEx m_wndLc;
	int m_nSelected;
	void InitContorls();
	void DrawImage(int nViewIdx, CString strFileName);
	CString GetTextCBSelected(UINT ID);

	void UpdateCBList();
	void UpdateLCList();
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnNMClickLcItem(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnLoad();
	afx_msg void OnCbnSelchangeCbView1();
	afx_msg void OnCbnSelchangeCbView2();
	afx_msg void OnCbnSelchangeCbView3();
	afx_msg void OnCbnSelchangeCbView4();
	afx_msg void OnBnClickedBtnExecute();
	afx_msg void OnBnClickedBtnNew();
	afx_msg void OnBnClickedMainBtnDelimg();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedMainBtnSaveimg();
};
