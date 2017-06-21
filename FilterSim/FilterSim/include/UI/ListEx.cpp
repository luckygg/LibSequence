// ListEx.cpp : implementation file
//

#include "stdafx.h"
#include "ListEx.h"


// CListEx

IMPLEMENT_DYNAMIC(CListEx, CListCtrl)

CListEx::CListEx()
{

}

CListEx::~CListEx()
{
}


BEGIN_MESSAGE_MAP(CListEx, CListCtrl)
	ON_NOTIFY_REFLECT ( NM_CUSTOMDRAW, OnNMCustomdrawLtcItem )
END_MESSAGE_MAP()

void CListEx::SetItemText(int nRow, int nCol, CString strText)
{
	if (nCol == 1)
		CListCtrl::InsertItem(nRow,_T(""));

	CListCtrl::SetItem(nRow,nCol,LVIF_TEXT,strText,0,0,0,NULL);
}

// CListEx message handlers
void CListEx::AddColumn(int nCol, CString strText, int nWidth)
{
	if (nCol == 1)
		CListCtrl::InsertColumn(0, _T(""), LVCFMT_CENTER, 0);

	CListCtrl::InsertColumn(nCol, strText, LVCFMT_CENTER, nWidth);
}

void CListEx::SetExtendedStyle(DWORD dwNewStyle)
{
	DWORD dwOldStyle = GetExtendedStyle();
	dwOldStyle |= dwNewStyle;

	CListCtrl::SetExtendedStyle(dwOldStyle);
}

void CListEx::SetItemColor(int nRow, int nCol, COLORREF clrBkg)
{
	CellInfo info;
	info.pos.x = nCol;
	info.pos.y = nRow;
	info.clr = clrBkg;

	m_Cell.push_back(info);

	Invalidate();
}

void CListEx::OnNMCustomdrawLtcItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	if(pNMCD->dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = (LRESULT)CDRF_NOTIFYITEMDRAW; 
		return; // 여기서 함수를 빠져 나가야 *pResult 값이 유지된다.
	}
 
	if(pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{ 
        // 한 줄 (row) 가 그려질 때. 여기서만 설정하면 한 줄이 모두 동일하게 설정이 된다.
		if(GetItemData(pNMCD->dwItemSpec) == 0)
		{
			//dwItemSpec 이 현재 그려지는 row index
			NMLVCUSTOMDRAW *pDraw = (NMLVCUSTOMDRAW*)(pNMHDR); 
 			pDraw->clrText = 0xffffff; 
			pDraw->clrTextBk = 0x0; 
			//*pResult = (LRESULT)CDRF_NEWFONT;//여기서 나가면 sub-item 이 변경되지 않는다.
			*pResult = (LRESULT)CDRF_NOTIFYSUBITEMDRAW;//sub-item 을 변경하기 위해서. 
			return;//여기서 중단해야 *pResult 값이 유지된다.
		}
		else
		{ 
			// When all matrices are already made. 
			NMLVCUSTOMDRAW *pDraw = (NMLVCUSTOMDRAW*)(pNMHDR); 
 			pDraw->clrText = 0x0; 
			pDraw->clrTextBk = RGB(255,255,196);  
			*pResult = (LRESULT)CDRF_NEWFONT; 
			return; 
		}
	}
	else if(pNMCD->dwDrawStage == (CDDS_SUBITEM | CDDS_ITEMPREPAINT))
	{	
        // sub-item 이 그려지는 순간. 위에서 *pResult 에 CDRF_NOTIFYSUBITEMDRAW 를 해서 여기로 올 수 있었던 것이다.
		NMLVCUSTOMDRAW *pDraw = (NMLVCUSTOMDRAW*)(pNMHDR); 

		pDraw->clrText = 0x0; 
		pDraw->clrTextBk = 0xffffff; 

		for (std::vector<CellInfo>::iterator it = m_Cell.begin(); it != m_Cell.end(); ++it)
		{
			if (it->pos.x == pDraw->iSubItem && it->pos.y == pNMCD->dwItemSpec)
			{
				pDraw->clrText = it->clr;
				pDraw->clrTextBk = it->clr;
			}
		}

		//CString text= GetItemText(pNMCD->dwItemSpec, pDraw->iSubItem); 
		//if(text == _T("t"))
		//if (pDraw->iSubItem == 1)
		//{
 		//	pDraw->clrText = RGB(255,255,255); 
		//	pDraw->clrTextBk = RGB(0,255,0); 
		//}
		//else
		//{
 		//	pDraw->clrText = 0x0; 
		//	pDraw->clrTextBk = 0xffffff; 
		//}
		
		*pResult = (LRESULT)CDRF_NEWFONT; // 이렇게 해야 설정한 대로 그려진다.
		return;
	}
 
 
	*pResult = 0;
	/*LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	
	*pResult = 0;

	LPNMLVCUSTOMDRAW lplvcd = (LPNMLVCUSTOMDRAW)pNMHDR;
	int iRow = (int)lplvcd->nmcd.dwItemSpec;

	switch(lplvcd->nmcd.dwDrawStage)
	{
	case CDDS_PREPAINT :
		*pResult = CDRF_NOTIFYITEMDRAW;
		break;
	case CDDS_ITEMPREPAINT :
		lplvcd->clrText = RGB(0,0,0);
		*pResult = CDRF_NOTIFYSUBITEMDRAW;
		break;
	case CDDS_SUBITEM | CDDS_PREPAINT | CDDS_ITEM :
		if (iRow % 4 == 0)
		{
			lplvcd->clrTextBk = RGB(192,192,192);
		}
		else if (iRow % 4 == 3)
		{
			lplvcd->clrTextBk = RGB(255,0,0);
		}
		else
		{
			lplvcd->clrTextBk = RGB(255,255,0);
		}

		*pResult = CDRF_DODEFAULT;
		break;
	}*/
}
