#pragma once
#include "ImgInfo.h"

// CNewDlg dialog

class CNewDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNewDlg)

public:
	CNewDlg(int nCnt, std::vector<CImgInfo> vImgInfo, CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewDlg();

public :
	CString GetName() {return m_strName; }
	int GetWidth() { return m_nWidth; }
	int GetHeight() { return m_nHeight; }
private :
	std::vector<CImgInfo> m_vImgInfo;
	CString m_strName;
	int m_nCnt;
	int m_nWidth;
	int m_nHeight;

// Dialog Data
	enum { IDD = IDD_DIALOG_NEW };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedNewBtnOk();
	afx_msg void OnCbnSelchangeNewCbRef();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
