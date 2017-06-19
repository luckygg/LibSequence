#pragma once
#include "ImgInfo.h"

// CSelectDlg dialog

class CSelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSelectDlg)

public:
	CSelectDlg(std::vector<CImgInfo> vImgInfo, CWnd* pParent = NULL);   // standard constructor
	virtual ~CSelectDlg();

public :
	CString GetName() {return m_strName; }
private :
	std::vector<CImgInfo> m_vImgInfo;
	CString m_strName;

// Dialog Data
	enum { IDD = IDD_DIALOG_SELECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDelBtnOk();
	afx_msg void OnBnClickedSelBtnCancel();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
