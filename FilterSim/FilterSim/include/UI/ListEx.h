//----------------------------------------------------------
// ListCtrlEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2017-06-21 11:50
// Modified by William Kim
// Demo Version
//----------------------------------------------------------


#pragma once

#include <vector>
// CListEx

class CListEx : public CListCtrl
{
	DECLARE_DYNAMIC(CListEx)
	struct CellInfo
	{
		CPoint pos;
		COLORREF clr;
	};

public:
	CListEx();
	virtual ~CListEx();

public :
	void SetItemColor(int nRow, int nCol, COLORREF clrBkg);
	void SetItemText(int nRow, int nCol, CString strText);
	void AddColumn(int nCol, CString strText, int nWidth);
	void SetExtendedStyle(DWORD dwNewStyle);

private :
	std::vector<CellInfo> m_Cell;
protected:
	afx_msg void OnNMCustomdrawLtcItem(NMHDR *pNMHDR, LRESULT *pResult);
	
	DECLARE_MESSAGE_MAP()
};


