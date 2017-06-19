#pragma once


// CNameDlgdialog

class CNameDlg: public CDialogEx
{
	DECLARE_DYNAMIC(CNameDlg)

public:
	CNameDlg(int nCnt, CWnd* pParent = NULL);   // standard constructor
	virtual ~CNameDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG_NAME };

public :
	CString GetName() {return m_strName; }
private :
	CString m_strName;
	int m_nCnt;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnOk();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
