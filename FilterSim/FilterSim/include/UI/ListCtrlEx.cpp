// ListCtrlEx.cpp : implementation file
//

#include "stdafx.h"
#include "ListCtrlEx.h"
#include "ListCombo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#defines
#define FIRST_COLUMN				0
#define MIN_COLUMN_WIDTH			10
#define MAX_DROP_DOWN_ITEM_COUNT	10


// CListCtrlEx

IMPLEMENT_DYNAMIC(CListCtrlEx, CListCtrl)

CListCtrlEx::CListCtrlEx()
{
	m_mapListctrlType.clear();

	m_dwDropDownCtrlStyle = WS_BORDER | WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_AUTOVSCROLL | 
		CBS_DROPDOWNLIST | CBS_DISABLENOSCROLL;
}

CListCtrlEx::~CListCtrlEx()
{
	CListCombo::DeleteInstance();
}


BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndLabelEdit)
END_MESSAGE_MAP()

// CListCtrlEx message handlers

CListCombo* CListCtrlEx::ShowInPlaceList(int iRowIndex, int iColumnIndex, CStringList& rComboItemsList, 
	CString strCurSelecetion /*= ""*/, int iSel /*= -1*/)
{
	// The returned obPointer should not be saved

	// Make sure that the item is visible
	if (!EnsureVisible(iRowIndex, TRUE))
	{
		return NULL;
	}

	// Make sure that iColumnIndex is valid 
	CHeaderCtrl* pHeader = static_cast<CHeaderCtrl*> (GetDlgItem(FIRST_COLUMN));

	int iColumnCount = pHeader->GetItemCount();

	if (iColumnIndex >= iColumnCount || GetColumnWidth(iColumnIndex) < MIN_COLUMN_WIDTH) 
	{
		return NULL;
	}

	// Calculate the rectangle specifications for the combo box
	CRect obCellRect(0, 0, 0, 0);
	CalculateCellRect(iColumnIndex, iRowIndex, obCellRect);

	int iHeight = obCellRect.Height();  
	int iCount = (int)rComboItemsList.GetCount();

	iCount = (iCount < MAX_DROP_DOWN_ITEM_COUNT) ? 
		iCount + MAX_DROP_DOWN_ITEM_COUNT : (MAX_DROP_DOWN_ITEM_COUNT + 1); 

	obCellRect.bottom += iHeight * iCount; 

	// Create the in place combobox
	CListCombo* pInPlaceCombo = CListCombo::GetInstance();
	pInPlaceCombo->OnShowCtrl(m_dwDropDownCtrlStyle, obCellRect, this, 0, iRowIndex, iColumnIndex, &rComboItemsList, 
		strCurSelecetion, iSel);

	return pInPlaceCombo;
}

void CListCtrlEx::OnHScroll(UINT iSBCode, UINT iPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

	if (GetFocus() != this)
	{
		SetFocus();
	}

	CListCtrl::OnHScroll(iSBCode, iPos, pScrollBar);
}

void CListCtrlEx::OnVScroll(UINT iSBCode, UINT iPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default

	if (GetFocus() != this)
	{
		SetFocus();
	}

	CListCtrl::OnVScroll(iSBCode, iPos, pScrollBar);
}

void CListCtrlEx::OnLButtonDown(UINT iFlags, CPoint obPoint) 
{
	// TODO: Add your message handler code here and/or call default

	int iColumnIndex = -1;
	int iRowIndex = -1;

	// Get the current column and row
	if (!HitTestEx(obPoint, &iRowIndex, &iColumnIndex))
	{
		return;
	}

	CListCtrl::OnLButtonDown(iFlags, obPoint);

	// If column is not read only then
	// If the SHIFT or CTRL key is down call the base class
	// Check the high bit of GetKeyState to determine whether SHIFT or CTRL key is down
	if ((GetKeyState(VK_SHIFT) & 0x80) || (GetKeyState(VK_CONTROL) & 0x80))
	{
		return;
	}

	// Get the current selection before creating the in place combo box
	CString strCurSelection = GetItemText(iRowIndex, iColumnIndex);

	if (-1 != iRowIndex)
	{
		UINT flag = LVIS_FOCUSED;

		if ((GetItemState(iRowIndex, flag ) & flag) == flag)
		{
			// Add check for LVS_EDITLABELS
			//if (GetWindowLong(m_hWnd, GWL_STYLE) & LVS_EDITLABELS)
			{
				UINT iType = WhatType(iRowIndex, iColumnIndex);
				CString strKey = _T("");
				strKey.Format(_T("%d_%d"), iRowIndex, iColumnIndex);
				map<CString, RowColInfo>::iterator itr;
				itr = m_mapListctrlType.find(strKey);
				if (iType == eType_Combo)
				{
					CStringList obComboItemsList;

					if (itr == m_mapListctrlType.end())
					{
						;
					}
					else
					{
						for (unsigned int i = 0; i < itr->second.vecStrData.size(); i++)
						{
							obComboItemsList.AddTail(itr->second.vecStrData[i]);
						}

						CListCombo* pInPlaceComboBox = ShowInPlaceList(iRowIndex, iColumnIndex, obComboItemsList, strCurSelection);
						ASSERT(pInPlaceComboBox);

						// Set the selection to previous selection
						pInPlaceComboBox->SelectString(-1, strCurSelection);
					}
				}
				else if (iType == eType_ReadOnly)
				{
					RowColInfo temp;
					temp = itr->second;

					if (temp.vecStrData.size() == 0)
						return;

					CString text = temp.vecStrData[temp.vecStrData.size()-1];

					SetItemText(iRowIndex,iColumnIndex,text);
				}
			}
		}
	}  
}

bool CListCtrlEx::HitTestEx(CPoint &obPoint, int* pRowIndex, int* pColumnIndex) const
{
	if (!pRowIndex || !pColumnIndex)
	{
		return false;
	}

	// Get the row index
	*pRowIndex = HitTest(obPoint, NULL);

	if (pColumnIndex)
	{
		*pColumnIndex = 0;
	}

	// Make sure that the ListView is in LVS_REPORT
	if ((GetWindowLong(m_hWnd, GWL_STYLE) & LVS_TYPEMASK) != LVS_REPORT)
	{
		return false;
	}

	// Get the number of columns
	CHeaderCtrl* pHeader = (CHeaderCtrl*)GetDlgItem(0);

	int iColumnCount = pHeader->GetItemCount();

	// Get bounding rect of item and check whether obPoint falls in it.
	CRect obCellRect;
	GetItemRect(*pRowIndex, &obCellRect, LVIR_BOUNDS);

	if (obCellRect.PtInRect(obPoint))
	{
		// Now find the column
		for (*pColumnIndex = 0; *pColumnIndex < iColumnCount; (*pColumnIndex)++)
		{
			int iColWidth = GetColumnWidth(*pColumnIndex);

			if (obPoint.x >= obCellRect.left && obPoint.x <= (obCellRect.left + iColWidth))
			{
				return true;
			}
			obCellRect.left += iColWidth;
		}
	}
	return false;
}

//void CListCtrlEx::SetRowColumnType(int iRow, int iCol, UINT iType, vector <CString> strData)
//{
//	CString strKey = _T("");
//	strKey.Format(_T("%d_%d"), iRow, iCol);
//	RowColInfo temp;
//	temp.iType = iType;
//	temp.vecStrData = strData;
//
//	map<CString, RowColInfo>::iterator itr;
//	itr = m_mapListctrlType.find(strKey);
//	// Data 가 없으면
//	if (itr == m_mapListctrlType.end())
//	{
//		// push data
//		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
//	}
//	// Data 가 있으면
//	else
//	{
//		// delete
//		m_mapListctrlType.erase(itr);
//
//		// push data
//		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
//	}
//
//	// replace
//}

void CListCtrlEx::SetRowColumnType(int iRow, int iCol, eType Type)
{
	CString strKey = _T("");
	strKey.Format(_T("%d_%d"), iRow, iCol);
	RowColInfo temp;
	temp.iType = Type;

	map<CString, RowColInfo>::iterator itr;
	itr = m_mapListctrlType.find(strKey);
	if (itr == m_mapListctrlType.end())
	{
		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}
	else
	{
		// delete
		m_mapListctrlType.erase(itr);

		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}

	// replace
}

void CListCtrlEx::AddString(int iRow, int iCol, CString strString)
{
	CString strKey = _T("");
	strKey.Format(_T("%d_%d"), iRow, iCol);
	
	RowColInfo temp;

	map<CString, RowColInfo>::iterator itr;
	itr = m_mapListctrlType.find(strKey);
	if (itr == m_mapListctrlType.end())
	{
		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}
	else
	{
		temp = itr->second;

		temp.vecStrData.push_back(strString);

		// delete
		m_mapListctrlType.erase(itr);

		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));

		// 일반일 경우 Text 가 안그려지므로 아래와 같이 설정.
		if (temp.iType == eType_ReadOnly)
			SetItemText(iRow,iCol,strString);
	}
}

void CListCtrlEx::DeleteString(int iRow, int iCol, CString strString)
{
	CString strKey = _T("");
	strKey.Format(_T("%d_%d"), iRow, iCol);

	RowColInfo temp;

	map<CString, RowColInfo>::iterator itr;
	itr = m_mapListctrlType.find(strKey);
	if (itr == m_mapListctrlType.end())
	{
		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}
	else
	{
		temp = itr->second;

		if (temp.iType == eType_Combo)
		{
			CString strCaption=_T("");
			for (vector<CString>::iterator it = temp.vecStrData.begin();
				it != temp.vecStrData.end(); ++it)
			{
				strCaption = it->GetString();
				if (strCaption == strString)
				{
					temp.vecStrData.erase(it);
					break;
				}
			}

			// delete
			m_mapListctrlType.erase(itr);

			// push data
			m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
		}
		else if (temp.iType == eType_ReadOnly)
		{
			temp.Clear();
			
			// delete
			m_mapListctrlType.erase(itr);
			
			// push data
			m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
		}
	}

	SetItemText(iRow,iCol,_T(""));
}

void CListCtrlEx::ClearString(int iRow, int iCol)
{
	CString strKey = _T("");
	strKey.Format(_T("%d_%d"), iRow, iCol);

	RowColInfo temp;

	map<CString, RowColInfo>::iterator itr;
	itr = m_mapListctrlType.find(strKey);
	if (itr == m_mapListctrlType.end())
	{
		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}
	else
	{
		temp = itr->second;

		temp.vecStrData.clear();

		// delete
		m_mapListctrlType.erase(itr);

		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}
}

CString CListCtrlEx::GetString(int iRow, int iCol)
{
	CString strKey = _T("");
	strKey.Format(_T("%d_%d"), iRow, iCol);

	RowColInfo temp;

	map<CString, RowColInfo>::iterator itr;
	itr = m_mapListctrlType.find(strKey);
	CString strLast;
	if (itr == m_mapListctrlType.end())
	{
		// push data
		m_mapListctrlType.insert(pair<CString, RowColInfo>(strKey, temp));
	}
	else
	{
		temp = itr->second;

		strLast = temp.vecStrData.back();
	}
	
	return strLast;
}

void CListCtrlEx::DeleteItem(int iRow)
{
	int nCntHdr=0;
	CHeaderCtrl *pHeaderCtrl = GetHeaderCtrl();
	nCntHdr = pHeaderCtrl->GetItemCount();

	int nCntItm = GetItemCount();
	for (int j=iRow; j<nCntItm; j++)
	{
		for (int i=1; i<nCntHdr; i++)
		{
			CString strKey = _T("");
			strKey.Format(_T("%d_%d"), j+1, i);

			map<CString, RowColInfo>::iterator itr1;
			itr1 = m_mapListctrlType.find(strKey);
			if (itr1 != m_mapListctrlType.end())
			{
				CString strKey2 = _T("");
				strKey2.Format(_T("%d_%d"), j, i);
				map<CString, RowColInfo>::iterator itr2;
				itr2 = m_mapListctrlType.find(strKey2);

				itr2->second.vecStrData.clear();
				for (vector<CString>::iterator it = itr1->second.vecStrData.begin(); 
					it != itr1->second.vecStrData.end(); ++it)
				{
					itr2->second.vecStrData.push_back(it->GetString());
				}
			}
		}
	}
	
	CListCtrl::DeleteItem(iRow);
}

UINT CListCtrlEx::WhatType(int iRow, int iCol)
{
	CString strKey = _T("");
	strKey.Format(_T("%d_%d"), iRow, iCol);

	map<CString, RowColInfo>::iterator itr;
	itr = m_mapListctrlType.find(strKey);
	if (itr == m_mapListctrlType.end())
	{
		return 99;
	}
	else
	{
		return itr->second.iType;
	}

	return 99;
}

void CListCtrlEx::CalculateCellRect(int iColumnIndex, int iRowIndex, CRect& robCellRect)
{
	GetItemRect(iRowIndex, &robCellRect, LVIR_BOUNDS);

	CRect rcClient;
	GetClientRect(&rcClient);

	if (robCellRect.right > rcClient.right) 
	{
		robCellRect.right = rcClient.right;
	}

	ScrollToView(iColumnIndex, robCellRect); 
}

void CListCtrlEx::EnableHScroll(bool bEnable /*= true*/)
{
	if (bEnable)
	{
		m_dwDropDownCtrlStyle |= WS_HSCROLL;
	}
	else
	{
		m_dwDropDownCtrlStyle &= ~WS_HSCROLL;
	}	
}

void CListCtrlEx::EnableVScroll(bool bEnable /*= true*/)
{
	if (bEnable)
	{
		m_dwDropDownCtrlStyle |= WS_VSCROLL;
	}
	else
	{
		m_dwDropDownCtrlStyle &= ~WS_VSCROLL;
	}
}

void CListCtrlEx::ScrollToView(int iColumnIndex, /*int iOffSet, */CRect& robCellRect)
{
	// Now scroll if we need to expose the column
	CRect rcClient;
	GetClientRect(&rcClient);

	int iColumnWidth = GetColumnWidth(iColumnIndex);

	// Get the column iOffset
	int iOffSet = 0;
	for (int iIndex_ = 0; iIndex_ < iColumnIndex; iIndex_++)
	{
		iOffSet += GetColumnWidth(iIndex_);
	}

	// If x1 of cell rect is < x1 of ctrl rect or
	// If x1 of cell rect is > x1 of ctrl rect or **Should not ideally happen**
	// If the width of the cell extends beyond x2 of ctrl rect then
	// Scroll

	CSize obScrollSize(0, 0);

	if (((iOffSet + robCellRect.left) < rcClient.left) || 
		((iOffSet + robCellRect.left) > rcClient.right))
	{
		obScrollSize.cx = iOffSet + robCellRect.left;
	}
	else if ((iOffSet + robCellRect.left + iColumnWidth) > rcClient.right)
	{
		obScrollSize.cx = iOffSet + robCellRect.left + iColumnWidth - rcClient.right;
	}

	Scroll(obScrollSize);
	robCellRect.left -= obScrollSize.cx;

	// Set the width to the column width
	robCellRect.left += iOffSet;
	robCellRect.right = robCellRect.left + iColumnWidth;
}

void CListCtrlEx::OnEndLabelEdit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here

	// Update the item text with the new text
	SetItemText(pDispInfo->item.iItem, pDispInfo->item.iSubItem, pDispInfo->item.pszText);

	GetParent()->SendMessage(WM_VALIDATE, GetDlgCtrlID(), (LPARAM)pDispInfo); 

	*pResult = 0;

	SetItemState(pDispInfo->item.iItem, 0, LVIS_SELECTED | LVIS_FOCUSED); 
}