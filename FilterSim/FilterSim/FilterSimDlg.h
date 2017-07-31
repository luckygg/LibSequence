
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
#include "EMatrix.h"


using namespace Euresys::Open_eVision_2_1;
using namespace std;

struct StItemInfo
{
	BOOL bUse;
	CString strType;
	CString strInput;
	CString strOutput;
	StLibrary stLibrary;
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

private :
	// Picture Control �� Input / Output �޺��ڽ� ����Ʈ ������.
	void UpdateCBList();
	// List Control �� ������ ���� ��ŭ Input / Output ���Է�.
	void UpdateItemList();
	// Tab ���� Input / Output / Lib �Է� �� Apply ������ ����Ǵ� �κ�.
	void UpdateItem(int nRow, BOOL bUse, CString strAlgorithm, CString strIn, CString strOut, StLibrary stLib);
	// Enable ������ ���� Green / Red ǥ�� �κ�.
	void UpdateItemColor();
	// ���õ� Combo Image �� ���� ��� Picture Control �� �����ϴ� �κ�.
	void UpdateAllView();
	// ���õ� Combo Image ���� �̸��� �Էµ� �̹��� ������ ������ Picture Control �� �����ϴ� �κ�.
	void UpdateFileNameView(CString strFile);
	// ���õ� Combo Box �� ���ڿ� ���.
	CString GetTextCBSelected(UINT ID);
	// �Էµ� ���ڿ��� Combo Box �� �ؽ�Ʈ �����ϱ�.
	void SetCBItembyText(UINT ID, CString strText);
	// �̹��� ���� vector �� �ߺ��Ǵ� ���ϸ��� �ִ��� Ȯ��.
	bool IsExistName(CString strName);
private :
	CView* m_pFormImg;
	CView* m_pFormMtx;
	
	CListEx m_wndLc;
	
	std::vector<CEImage> m_vImgInfo;
	std::vector<StItemInfo> m_vItmInfo;

	int m_nImgCnt;
	
	void InitContorls();
	void DrawImage(int nViewIdx, CString strFileName);
	void FormSwitching(eAlgorithm eType);
	void OnExecute();
	CString CheckLibrary(CString strLib);
	
	
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
