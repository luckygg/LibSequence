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
		return; // ���⼭ �Լ��� ���� ������ *pResult ���� �����ȴ�.
	}
 
	if(pNMCD->dwDrawStage == CDDS_ITEMPREPAINT)
	{ 
        // �� �� (row) �� �׷��� ��. ���⼭�� �����ϸ� �� ���� ��� �����ϰ� ������ �ȴ�.
		if(GetItemData(pNMCD->dwItemSpec) == 0)
		{
			//dwItemSpec �� ���� �׷����� row index
			NMLVCUSTOMDRAW *pDraw = (NMLVCUSTOMDRAW*)(pNMHDR); 
 			pDraw->clrText = 0xffffff; 
			pDraw->clrTextBk = 0x0; 
			//*pResult = (LRESULT)CDRF_NEWFONT;//���⼭ ������ sub-item �� ������� �ʴ´�.
			*pResult = (LRESULT)CDRF_NOTIFYSUBITEMDRAW;//sub-item �� �����ϱ� ���ؼ�. 
			return;//���⼭ �ߴ��ؾ� *pResult ���� �����ȴ�.
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
        // sub-item �� �׷����� ����. ������ *pResult �� CDRF_NOTIFYSUBITEMDRAW �� �ؼ� ����� �� �� �־��� ���̴�.
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
		
		*pResult = (LRESULT)CDRF_NEWFONT; // �̷��� �ؾ� ������ ��� �׷�����.
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
