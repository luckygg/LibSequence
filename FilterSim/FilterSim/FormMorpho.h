#pragma once



// CFormMorpho form view

class CFormMorpho : public CFormView
{
	DECLARE_DYNCREATE(CFormMorpho)

protected:
	CFormMorpho();           // protected constructor used by dynamic creation
	virtual ~CFormMorpho();

public:
	enum { IDD = IDD_FORM_MORPHOLOGY };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

private :
	CRect m_wndRc;
	int m_rbtnOper;
public :
	void InitControls();
	CString GetTextSelectedOper();
	void SetSelectOperByText(CString strData);
	int GetHalfKernel();
	void SetHalfKernel(int nHalfKernel);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedMplRBtnOperation(UINT ID);
};