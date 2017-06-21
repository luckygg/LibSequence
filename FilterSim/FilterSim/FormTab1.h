#pragma once

#include <vector>
#include "ImgInfo.h"

// CFormTab1 form view

class CFormTab1 : public CFormView
{
	DECLARE_DYNCREATE(CFormTab1)

protected:
	CFormTab1();           // protected constructor used by dynamic creation
	virtual ~CFormTab1();

public :
	void SetSelectedRow(int nRow);
	void UpdateCBList(std::vector<CImgInfo> ImgInfo);
	void UpdateControls(StItemInfo info);
	void ResetControls();
public:
	enum { IDD = IDD_FORM_TAB1 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedTab1BtnApply();
};


