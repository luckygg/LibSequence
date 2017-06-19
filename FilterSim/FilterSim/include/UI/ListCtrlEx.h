#pragma once

#include <afxtempl.h>
#include <vector>
#include <map>
using namespace std;

class CListCombo;

class RowColInfo
{
public:
	RowColInfo(){ Clear(); }
	~RowColInfo(){ Clear(); }

	UINT iType;
	vector <CString> vecStrData;

	void Clear()
	{
		iType = 0;
		vecStrData.clear();
	}
};

#define WM_VALIDATE		WM_USER + 0x7FFD
#define WM_SET_ITEMS	WM_USER + 0x7FFC

// CListCtrlEx

class CListCtrlEx : public CListCtrl
{
	DECLARE_DYNAMIC(CListCtrlEx)

public:
	CListCtrlEx();
	virtual ~CListCtrlEx();

public :
	enum eType
	{
		eType_ReadOnly = 0,
		eType_Combo,
	};
	void SetRowColumnType(int iRow, int iCol, eType Type);
	void AddString(int iRow, int iCol, CString strString);
	void DeleteString(int iRow, int iCol, CString strString=_T(""));
	void ClearString(int iRow, int iCol);
	CString GetString(int iRow, int iCol);
	void DeleteItem(int iRow);
	
	// Sets/Resets the column which support the in place combo box
	//void SetRowColumnType(int iRow, int iCol, UINT iType, vector <CString> strData);
	
	
	// Sets the vertical scroll
	void EnableVScroll(bool bEnable = true);

	// Sets the horizontal scroll
	void EnableHScroll(bool bEnable = true);

private :
	// Returns the row & column index of the column on which mouse click event has occured
	bool HitTestEx(CPoint& rHitPoint, int* pRowIndex, int* pColumnIndex) const;

	// Creates and displays the in place combo box
	CListCombo* ShowInPlaceList(int iRowIndex, int iColumnIndex, CStringList& rComboItemsList, 
		CString strCurSelecetion = _T(""), int iSel = -1);


	// Calculates the cell rect
	void CalculateCellRect(int iColumnIndex, int iRowIndex, CRect& robCellRect);

	UINT WhatType(int iRow, int iCol);


	// Scrolls the list ctrl to bring the in place ctrl to the view
	void ScrollToView(int iColumnIndex, /*int iOffSet, */CRect& obCellRect);

	// Attributes

	// List of columns that support the in place combo box
	map < CString, RowColInfo > m_mapListctrlType;

	// The window style of the in place combo ctrl
	DWORD m_dwDropDownCtrlStyle;

protected:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBeginLabelEdit(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};


