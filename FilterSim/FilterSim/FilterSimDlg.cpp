
// FilterSimDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FilterSim.h"
#include "FilterSimDlg.h"
#include "afxdialogex.h"

#include "NameDlg.h"
#include "NewDlg.h"
#include "SelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFilterSimDlg dialog




CFilterSimDlg::CFilterSimDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFilterSimDlg::IDD, pParent)
	, m_rbtnIn1(0)
	, m_rbtnIn2(0)
	, m_rbtnCst1(0)
	, m_rbtnCst2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nImgCnt = 0;

	m_pFormImg = NULL;
	m_pFormMtx  = NULL;
}

void CFilterSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_LC_ITEM, m_wndLc);

	DDX_Radio(pDX, IDC_MAIN_RBTN_INIMG1, m_rbtnIn1);
	DDX_Radio(pDX, IDC_MAIN_RBTN_INIMG2, m_rbtnIn2);
	DDX_Radio(pDX, IDC_MAIN_RBTN_CSTGRAY1, m_rbtnCst1);
	DDX_Radio(pDX, IDC_MAIN_RBTN_CSTGRAY2, m_rbtnCst2);
}

BEGIN_MESSAGE_MAP(CFilterSimDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MAIN_BTN_ADDITEM, &CFilterSimDlg::OnBnClickedBtnAddItem)
	ON_BN_CLICKED(IDC_MAIN_BTN_DELITEM, &CFilterSimDlg::OnBnClickedBtnDelList)
	ON_BN_CLICKED(IDC_MAIN_BTN_LOADIMG, &CFilterSimDlg::OnBnClickedBtnLoad)
	
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW1, &CFilterSimDlg::OnCbnSelchangeCbView1)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW2, &CFilterSimDlg::OnCbnSelchangeCbView2)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW3, &CFilterSimDlg::OnCbnSelchangeCbView3)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW4, &CFilterSimDlg::OnCbnSelchangeCbView4)
	ON_BN_CLICKED(IDC_MAIN_BTN_EXECUTE, &CFilterSimDlg::OnBnClickedBtnExecute)
	ON_BN_CLICKED(IDC_MAIN_BTN_NEWIMG, &CFilterSimDlg::OnBnClickedBtnNewImg)
	ON_BN_CLICKED(IDC_MAIN_BTN_DELIMG, &CFilterSimDlg::OnBnClickedBtnDelimg)
	ON_BN_CLICKED(IDC_MAIN_BTN_SAVEIMG, &CFilterSimDlg::OnBnClickedBtnSaveimg)
	ON_NOTIFY(NM_CLICK, IDC_MAIN_LC_ITEM, &CFilterSimDlg::OnNMClickMainLcItem)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_LIB, &CFilterSimDlg::OnCbnSelchangeMainCbLib)
	ON_BN_CLICKED(IDC_MAIN_BTN_APPLY, &CFilterSimDlg::OnBnClickedMainBtnApply)
	ON_BN_CLICKED(IDC_MAIN_BTN_ADDROI, &CFilterSimDlg::OnBnClickedMainBtnAddroi)
	ON_BN_CLICKED(IDC_MAIN_BTN_DELROI, &CFilterSimDlg::OnBnClickedMainBtnDelroi)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_IMGLIST, &CFilterSimDlg::OnCbnSelchangeMainCbImglist)
	ON_BN_CLICKED(IDC_MAIN_BTN_MODIFY, &CFilterSimDlg::OnBnClickedMainBtnModify)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_MAIN_RBTN_INIMG1, IDC_MAIN_RBTN_INCST1, CFilterSimDlg::OnBnClickedMainRBtnImgCst1)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_MAIN_RBTN_INIMG2, IDC_MAIN_RBTN_INCST2, CFilterSimDlg::OnBnClickedMainRBtnImgCst2)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_MAIN_RBTN_CSTGRAY1, IDC_MAIN_RBTN_CSTCLR1, CFilterSimDlg::OnBnClickedMainRBtnGrayClr1)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_MAIN_RBTN_CSTGRAY2, IDC_MAIN_RBTN_CSTCLR2, CFilterSimDlg::OnBnClickedMainRBtnGrayClr2)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CFilterSimDlg message handlers

BOOL CFilterSimDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	InitContorls();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFilterSimDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		UpdateAllView();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFilterSimDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFilterSimDlg::InitContorls()
{
	m_wndLc.AddColumn(1, _T("No.")		,  30);
	m_wndLc.AddColumn(2, _T("Use")		,  30);
	m_wndLc.AddColumn(3, _T("Algorithm"),  90);
	m_wndLc.AddColumn(4, _T("Input1")	,  90);
	m_wndLc.AddColumn(5, _T("Input2")	,  90);
	m_wndLc.AddColumn(6, _T("Output")	,  90);
	m_wndLc.AddColumn(7, _T("Time")		,  60);
	m_wndLc.AddColumn(8, _T("Result")	,  50);
	m_wndLc.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CComboBox* pCB = NULL;
	pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_LIB);
	pCB->AddString(_T("EasyImage"));
	pCB->AddString(_T("EasyMatrixCode"));
	pCB->EnableWindow(FALSE);

	CheckDlgButton(IDC_MAIN_RBTN_INIMG1, 1);
	CheckDlgButton(IDC_MAIN_RBTN_INIMG2, 1);
	CheckDlgButton(IDC_MAIN_RBTN_CSTGRAY1, 1);
	CheckDlgButton(IDC_MAIN_RBTN_CSTGRAY2, 1);

	GetDlgItem(IDC_MAIN_CB_INPUT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_CB_INPUT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_CB_OUTPUT)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_CHK_USE)->EnableWindow(FALSE);

	GetDlgItem(IDC_MAIN_RBTN_INIMG1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_INIMG2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_INCST1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_INCST2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_CSTGRAY1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_CSTGRAY2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_CSTCLR1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_RBTN_CSTCLR2)->EnableWindow(FALSE);

	GetDlgItem(IDC_MAIN_EDIT_GRAY1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_GRAY2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_R1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_G1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_B1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_R2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_G2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_B2)->EnableWindow(FALSE);

	SetDlgItemInt(IDC_MAIN_EDIT_GRAY1, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_GRAY2, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_R1, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_G1, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_B1, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_R2, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_G2, 128);
	SetDlgItemInt(IDC_MAIN_EDIT_B2, 128);

	CCreateContext context;
	ZeroMemory(&context, sizeof(context));
	CView* pView = NULL;
	CRect rect=CRect(0,0,0,0);

	//----- Create Form Window -----//
	// Form TAB1
	pView = (CView*)RUNTIME_CLASS(CFormImg)->CreateObject();
	GetDlgItem(IDC_MAIN_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_IMAGE, &context);
	pView->OnInitialUpdate();
	m_pFormImg = pView;

	m_pFormImg->ShowWindow(SW_HIDE);
	
	// Form Matrix
	pView = (CView*)RUNTIME_CLASS(CFormMtx)->CreateObject();
	GetDlgItem(IDC_MAIN_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_MATRIX, &context);
	pView->OnInitialUpdate();
	m_pFormMtx = pView;

	m_pFormMtx->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAIN_PC_TAB1)->DestroyWindow();
}

void CFilterSimDlg::OnBnClickedBtnAddItem()
{
	int n = m_wndLc.GetItemCount();
	
	CString strIdx=_T("");
	
	if (n > 0)
	{
		CString strLast = m_wndLc.GetItemText(n-1,1);
		int temp = _ttoi(strLast);
		strIdx.Format(_T("%d"),temp+1);
	}
	else
	{
		strIdx.Format(_T("%d"),n);
	}

	m_wndLc.SetItemText(n,1,strIdx);

	StItemInfo info;
	info.bUse = FALSE;
	info.strType = _T("");
	info.strIn1 = _T("");
	info.strIn2 = _T("");
	info.strOut = _T("");

	m_vItmInfo.push_back(info);

	UpdateItemColor();
}

void CFilterSimDlg::OnBnClickedBtnDelList()
{
	POSITION pos = NULL;
	int nItemIdx = -1;

	pos = m_wndLc.GetFirstSelectedItemPosition();

	if( NULL != pos )
		nItemIdx = m_wndLc.GetNextSelectedItem(pos);

	if (nItemIdx >= 0)
		m_wndLc.DeleteItem(nItemIdx);

	int nCnt=0;
	for (std::vector<StItemInfo>::iterator it = m_vItmInfo.begin(); it != m_vItmInfo.end(); )
	{
		if (nCnt == nItemIdx)
		{
			it = m_vItmInfo.erase(it);
		}
		else
		{
			it++;
		}
		nCnt++;
	}

	UpdateItemColor();
}

void CFilterSimDlg::OnBnClickedBtnLoad()
{
	CString strPath=_T("");
	if (CFileDialogEx::GetPathOpenFileDlg(strPath) == true)
	{
		CString fileName;
		CNameDlg dlg(m_nImgCnt);
		if (dlg.DoModal() == IDOK)
		{
			fileName = dlg.GetName();

			CEImage info;

			info.OnLoadImage(strPath);
			
			info.SetImageName(fileName);

			if (IsExistName(fileName) == true)
			{
				AfxMessageBox(_T("중복되는 이름이 존재합니다."));
				return;
			}

			m_vImgInfo.push_back(info);

			UpdateCBList();
			
			m_nImgCnt++;
		}
	}
}

void CFilterSimDlg::OnBnClickedBtnExecute()
{
	OnExecute();
}

void CFilterSimDlg::DrawEmptyImage(int nViewIdx)
{
	CWnd* pWnd = NULL;
	switch (nViewIdx)
	{
		case 0 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW1); break;
		case 1 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW2); break;
		case 2 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW3); break;
		case 3 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW4); break;
	}

	CClientDC dc(pWnd);
	CRect rect;
	pWnd->GetClientRect(&rect);

	dc.FillSolidRect(rect,RGB(128,128,128));
}

void CFilterSimDlg::DrawImage(int nViewIdx, CString strFileName)
{
	CWnd* pWnd = NULL;
	switch (nViewIdx)
	{
		case 0 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW1); break;
		case 1 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW2); break;
		case 2 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW3); break;
		case 3 : pWnd = GetDlgItem(IDC_MAIN_PC_VIEW4); break;
	}

	CClientDC dc(pWnd);
	CRect rect;
	pWnd->GetClientRect(&rect);
	
	vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (strFileName == fileName) break;
	}
	
	int w=0, h=0;
	it->GetWidth(w);
	it->GetHeight(h);
	float fH = (float)rect.Width()/w;
	float fV = (float)rect.Height()/h;
	it->OnDrawImage(pWnd, fH, fV);
	it->OnDrawROIFrame(pWnd, fH, fV);
}

void CFilterSimDlg::OnCbnSelchangeCbView1()
{
	CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW1);

	vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (name == fileName) break;
	}
	
	int w=0,h=0;
	it->GetWidth(w);
	it->GetHeight(h);

	CString strInfo=_T("");
	strInfo.Format(_T("Width : %d, Height : %d"),w,h);
	SetDlgItemText(IDC_MAIN_LB_INFO1, strInfo);

	DrawImage(0, name);
}

void CFilterSimDlg::OnCbnSelchangeCbView2()
{
	CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW2);

	vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (name == fileName) break;
	}

	int w=0,h=0;
	it->GetWidth(w);
	it->GetHeight(h);

	CString strInfo=_T("");
	strInfo.Format(_T("Width : %d, Height : %d"),w,h);
	SetDlgItemText(IDC_MAIN_LB_INFO2, strInfo);

	DrawImage(1, name);
}

void CFilterSimDlg::OnCbnSelchangeCbView3()
{
	CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW3);

	std::vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (name == fileName) break;
	}

	int w=0,h=0;
	it->GetWidth(w);
	it->GetHeight(h);

	CString strInfo=_T("");
	strInfo.Format(_T("Width : %d, Height : %d"),w,h);
	SetDlgItemText(IDC_MAIN_LB_INFO3, strInfo);

	DrawImage(2, name);
}

void CFilterSimDlg::OnCbnSelchangeCbView4()
{
	CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW4);

	vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (name == fileName) break;
	}

	int w=0,h=0;
	it->GetWidth(w);
	it->GetHeight(h);

	CString strInfo=_T("");
	strInfo.Format(_T("Width : %d, Height : %d"),w,h);
	SetDlgItemText(IDC_MAIN_LB_INFO4, strInfo);

	DrawImage(3, name);
}

void CFilterSimDlg::OnBnClickedBtnNewImg()
{
	CNewDlg dlg(m_nImgCnt, m_vImgInfo);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetName();
		int w = dlg.GetWidth();
		int h = dlg.GetHeight();
		
		CEImage info;
		info.CreatImage(w,h,8);
		info.SetImageName(fileName);
		
		if (IsExistName(fileName) == true)
		{
			AfxMessageBox(_T("중복되는 이름이 존재합니다."));
			return;
		}

		m_vImgInfo.push_back(info);
		
		UpdateCBList();

		m_nImgCnt++;
	}
}

CString CFilterSimDlg::GetTextCBSelected(UINT ID)
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(ID);

	CString strName=_T("");
	int sel = pCB->GetCurSel();
	if (sel == -1) return _T("");
	
	pCB->GetLBText(sel,strName);

	return strName;
}

void CFilterSimDlg::OnBnClickedBtnDelimg()
{
	CSelectDlg dlg(m_vImgInfo);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetName();
		
		for (std::vector<CEImage>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end();)
		{
			CString name=_T("");
			it->GetImageName(name);

			if (fileName == name)
			{
				it = m_vImgInfo.erase(it);
			}
			else
			{
				++it;
			}
		}

		for (std::vector<StItemInfo>::iterator it = m_vItmInfo.begin(); it != m_vItmInfo.end(); ++it)
		{
			if (it->strIn1 == fileName)
				it->strIn1 = _T("");
			if (it->strIn2 == fileName)
				it->strIn2 = _T("");
			if (it->strOut == fileName)
				it->strOut = _T("");
		}

		UpdateCBList();
		UpdateAllView();
		UpdateItemList();
	}
}

void CFilterSimDlg::UpdateCBList()
{
	// Picture Control Combo Box 4 + Input + Output
	for (int i=0; i<8; i++)
	{
		CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW1+i);
		CString strLastText=_T("");
		int sel = pCB->GetCurSel();

		if (sel != -1)
		{
			pCB->GetLBText(sel, strLastText);
		}

		pCB->ResetContent();
		for (std::vector<CEImage>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString name=_T("");
			it->GetImageName(name);
			pCB->AddString(name);

			if (i > 3)
			{
				int cnt = it->GetRoiCount();
				for (int j=0; j<it->GetRoiCount(); j++)
				{
					it->GetRoiName(j,name);
					name = _T(" - ") + name;
					pCB->AddString(name);
				}
			}
		}
		
		if (sel != -1)
			pCB->SetCurSel(pCB->FindString(0, strLastText));
	}
}

void CFilterSimDlg::UpdateItemList()
{
	int n = m_wndLc.GetItemCount();

	for (int i=0; i<n; i++)
	{
		StItemInfo info = m_vItmInfo.at(i);

		m_wndLc.SetItemText(i,4,info.strIn1);
		m_wndLc.SetItemText(i,5,info.strIn2);
		m_wndLc.SetItemText(i,6,info.strOut);
	}
}

void CFilterSimDlg::UpdateItemColor()
{
	int nRow=0;
	for (std::vector<StItemInfo>::iterator it = m_vItmInfo.begin(); it != m_vItmInfo.end(); it++)
	{
		if (it->bUse == TRUE)
		{
			m_wndLc.SetItemText(nRow, 2, _T("T"));
			m_wndLc.SetItemColor(nRow, 2, RGB(0,255,0));
		}
		else
		{
			m_wndLc.SetItemText(nRow, 2, _T("F"));
			m_wndLc.SetItemColor(nRow, 2, RGB(255,0,0));
		}
		m_wndLc.SetItemColor(nRow, 8, RGB(128,128,128));

		nRow++;
	}
}

void CFilterSimDlg::UpdateItem(int nRow, BOOL bUse, CString strAlgorithm, CString strIn1, CString strIn2, CString strOut, StLibrary stLib)
{
	if (bUse == TRUE)
	{
		m_wndLc.SetItemText(nRow, 2, _T("T"));
		m_wndLc.SetItemColor(nRow, 2, RGB(0,255,0));
	}
	else
	{
		m_wndLc.SetItemText(nRow, 2, _T("F"));
		m_wndLc.SetItemColor(nRow, 2, RGB(255,0,0));
	}

	m_wndLc.SetItemText(nRow, 3, strAlgorithm);
	m_wndLc.SetItemText(nRow, 4, strIn1);
	m_wndLc.SetItemText(nRow, 5, strIn2);
	m_wndLc.SetItemText(nRow, 6, strOut);

	int nCnt=0;
	for (std::vector<StItemInfo>::iterator it = m_vItmInfo.begin(); it != m_vItmInfo.end(); it++)
	{
		if (nCnt == nRow)
		{
			it->bUse = bUse;
			it->strType = strAlgorithm;
			it->strIn1 = strIn1;
			it->strIn2 = strIn2;
			it->strOut = strOut;
			it->stLib = stLib;
			break;
		}
		else
			nCnt++;
	}
}

BOOL CFilterSimDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == VK_RETURN)
			return TRUE;
		
		if (pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CFilterSimDlg::OnBnClickedBtnSaveimg()
{
	CSelectDlg dlg(m_vImgInfo);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetName();

		std::vector<CEImage>::iterator it;
		for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString name=_T("");
			it->GetImageName(name);
			if (fileName == name)
				break;
		}

		CString path=_T("");
		CFileDialogEx::GetPathSaveFileDlg(path);

		ATL::CT2CA str(path);
		std::string strPath(str); 

		try
		{
			EImageBW8* img = it->GetImage();
			img->Save(strPath);
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
		}
	}
}

void CFilterSimDlg::OnNMClickMainLcItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	POSITION pos = NULL;
	int nRow = -1;

	pos = m_wndLc.GetFirstSelectedItemPosition();

	if( NULL != pos )
		nRow = m_wndLc.GetNextSelectedItem(pos);

	CString strLib = m_wndLc.GetItemText(nRow, 3);
	CComboBox* pCB_Lib = (CComboBox*)GetDlgItem(IDC_MAIN_CB_LIB);

	if (nRow == -1)
	{
		FormSwitching(ENone);
		pCB_Lib->SetCurSel(-1);

		pCB_Lib->EnableWindow(FALSE);
		
		GetDlgItem(IDC_MAIN_CHK_USE)->EnableWindow(FALSE);

		return;
	}
	else
	{
		pCB_Lib->EnableWindow(TRUE);
		
		GetDlgItem(IDC_MAIN_CHK_USE)->EnableWindow(TRUE);

		SetDlgItemInt(IDC_MAIN_LB_ROW, nRow);
	}

	if (strLib == _T("EasyMatrixCode"))
	{
		SetCBItembyText(IDC_MAIN_CB_LIB,strLib);

		FormSwitching(EEasyMatrix);

		GetDlgItem(IDC_MAIN_CB_INPUT1)->EnableWindow(FALSE);
	}
	else if (strLib == _T(""))
	{
		FormSwitching(ENone);
		pCB_Lib->SetCurSel(-1);
	}
	// EasyImage
	else
	{
		pCB_Lib->SetCurSel(0);
		
		FormSwitching(EEasyImage);

		SetDlgItemInt(IDC_MAIN_LB_ROW, nRow);

		CFormImg* pImg = (CFormImg*)m_pFormImg;
		pImg->SetParameter(m_vItmInfo.at(nRow).stLib);

		GetDlgItem(IDC_MAIN_CB_INPUT1)->EnableWindow(TRUE);
	}

	SetCBItembyText(IDC_MAIN_CB_INPUT1,m_vItmInfo.at(nRow).strIn1);
	SetCBItembyText(IDC_MAIN_CB_INPUT2,m_vItmInfo.at(nRow).strIn2);
	SetCBItembyText(IDC_MAIN_CB_OUTPUT,m_vItmInfo.at(nRow).strOut);
	
	int state=0;
	m_vItmInfo.at(nRow).bUse ? state=1 : state=0;
	CheckDlgButton(IDC_MAIN_CHK_USE, state);

	*pResult = 0;
}


void CFilterSimDlg::OnCbnSelchangeMainCbLib()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_LIB);
	int sel = pCB->GetCurSel();

	switch (sel)
	{
	case 0 :
		{
			int nRow = GetDlgItemInt(IDC_MAIN_LB_ROW);
			FormSwitching(EEasyImage);
			CFormImg* pImg = (CFormImg*)m_pFormImg;
			pImg->InitControls();
		}
		
		break;
	case 1 :
		FormSwitching(EEasyMatrix);
		{
			
		}
		break;
	}

	SetEnableIOList(false, false, false, false, false);
}

void CFilterSimDlg::SetCBItembyText(UINT ID, CString strText)
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(ID);
	int sel = pCB->FindString(0,strText);
	pCB->SetCurSel(sel);
}

void CFilterSimDlg::FormSwitching(eAlgorithm eType)
{
	switch (eType)
	{
	case EEasyImage :
		{
			m_pFormImg->ShowWindow(SW_SHOW);
			m_pFormMtx->ShowWindow(SW_HIDE);

			CFormImg *pImg = (CFormImg*)m_pFormImg;
			pImg->InitControls();
		}
		break;
	case EEasyMatrix : 
		{
			m_pFormImg->ShowWindow(SW_HIDE);
			m_pFormMtx->ShowWindow(SW_SHOW);

			CFormMtx *pMtx = (CFormMtx*)m_pFormMtx;
			//pImg->InitControls();
		}
		break;
	case ENone : 
		m_pFormImg->ShowWindow(SW_HIDE);
		m_pFormMtx->ShowWindow(SW_HIDE);
	}
}

void CFilterSimDlg::OnBnClickedMainBtnApply()
{
	StLibrary library;

	CFormImg* pImg = (CFormImg*)m_pFormImg;
	pImg->GetParameter(library);

	int nRow = GetDlgItemInt(IDC_MAIN_LB_ROW);
	CString strLib = GetTextCBSelected(IDC_MAIN_CB_LIB);
	if (strLib == _T("EasyImage"))
	{
		if (library.stImg.strType == _T("Convolution"))
		{
			strLib = library.stImg.stConvolution.strType;
		}
		else if (library.stImg.strType == _T("Morphology"))
		{
			strLib = library.stImg.stMorphology.strType;
		}
		else if (library.stImg.strType == _T("Threshold"))
		{
			strLib = library.stImg.stThreshold.strType;
		}
		else if (library.stImg.strType == _T("Arithmetic & Logic"))
		{
			strLib = library.stImg.stArithmetic.strType;
		}
		else if (library.stImg.strType == _T("Scale & Rotate"))
		{
			strLib = library.stImg.stScale.strType;
		}
		else if (library.stImg.strType == _T("Gain & Offset"))
		{
			strLib = library.stImg.stGain.strType;
		}
	}

	CString strIn1=_T(""),strIn2=_T("");
	if (m_rbtnIn1 == 0)
		strIn1 = GetTextCBSelected(IDC_MAIN_CB_INPUT1);
	else
	{
		if (m_rbtnCst1 == 0)
		{
			int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
			strIn1.Format(_T("Y8(%d)"),nY8);
		}
		else
		{
			int nR = GetDlgItemInt(IDC_MAIN_EDIT_R1);
			int nG = GetDlgItemInt(IDC_MAIN_EDIT_G1);
			int nB = GetDlgItemInt(IDC_MAIN_EDIT_B1);
			strIn1.Format(_T("RGB24(%d:%d:%d)"),nR,nG,nB);
		}
	}
	
	if (m_rbtnIn2 == 0)
		strIn2 = GetTextCBSelected(IDC_MAIN_CB_INPUT2);
	else
	{
		if (m_rbtnCst2 == 0)
		{
			int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
			strIn2.Format(_T("Y8(%d)"),nY8);
		}
		else
		{
			int nR = GetDlgItemInt(IDC_MAIN_EDIT_R2);
			int nG = GetDlgItemInt(IDC_MAIN_EDIT_G2);
			int nB = GetDlgItemInt(IDC_MAIN_EDIT_B2);
			strIn2.Format(_T("RGB24(%d:%d:%d)"),nR,nG,nB);
		}
	}

	CString strOut = GetTextCBSelected(IDC_MAIN_CB_OUTPUT);
	
	BOOL bChk = IsDlgButtonChecked(IDC_MAIN_CHK_USE);

	UpdateItem(nRow, bChk, strLib, strIn1, strIn2, strOut, library);
}

void CFilterSimDlg::OnExecute()
{
	int n = m_wndLc.GetItemCount();
	CEImage *pIn1 = NULL, *pIn2 = NULL, *pOut = NULL;
	
	for (int i=0; i<n; i++)
	{
		double time=0;
		bool bRet=false;
		bool bInRoi=false, bOutRoi=false;
		
		CString use	= m_wndLc.GetItemText(i,2);
		if (use == _T("F"))
			continue;

		CString strLib = m_wndLc.GetItemText(i,3);
		CString strIn1 = m_wndLc.GetItemText(i,4);
		CString strIn2 = m_wndLc.GetItemText(i,5);
		CString strOut = m_wndLc.GetItemText(i,6);

		if (strIn1.Find(_T(" - ")) == 0)
		{
			int len = strIn1.GetLength();
			strIn1 = strIn1.Right(len-3);
			bInRoi = true;
		}

		if (strIn2.Find(_T(" - ")) == 0)
		{
			int len = strIn2.GetLength();
			strIn2 = strIn2.Right(len-3);
			bInRoi = true;
		}

		if (strOut.Find(_T(" - ")) == 0)
		{
			int len = strOut.GetLength();
			strOut = strOut.Right(len-3);
			bOutRoi = true;
		}

		for (vector<CEImage>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString fileName=_T("");
			it->GetImageName(fileName);

			if (it->HasROI(strIn1) == true)
				pIn1 = it->GetEImage();
			
			if (fileName == strIn1)
				pIn1 = it->GetEImage();

			if (it->HasROI(strIn2) == true)
				pIn2 = it->GetEImage();

			if (fileName == strIn2)
				pIn2 = it->GetEImage();

			if (it->HasROI(strOut) == true)
				pOut = it->GetEImage();

			if (fileName == strOut)
				pOut = it->GetEImage();
		}

		if (strLib == _T("EasyMatrixCode"))
		{
			CEMatrix Mtx;
			CString strResult = _T("");
			if (bOutRoi == true)
			{
				EROIBW8* pRoi = pOut->GetROI(strOut);
				bRet = Mtx.OnExecute(pRoi,strResult,time);
			}
			else
				bRet = Mtx.OnExecute(pOut->GetImage(),strResult,time);

			if (bRet == false)
			{
				m_wndLc.SetItemColor(i, 8, RGB(255,0,0));
				continue;
			}

			m_wndLc.SetItemColor(i, 8, RGB(0,255,0));

			for (int k=0; k<4; k++)
			{
				CString strSelFile = GetTextCBSelected(IDC_MAIN_CB_VIEW1+k);

				CString strImg=_T("");
				pOut->GetImageName(strImg);
				if (strSelFile == strImg)
				{
					CClientDC dc(GetDlgItem(IDC_MAIN_PC_VIEW1+k));
					CRect rect;
					GetDlgItem(IDC_MAIN_PC_VIEW1+k)->GetClientRect(&rect);

					int w=0, h=0;
					pOut->GetWidth(w);
					pOut->GetHeight(h);
					float fH = (float)rect.Width()/w;
					float fV = (float)rect.Height()/h;

					Mtx.OnDrawResult(GetDlgItem(IDC_MAIN_PC_VIEW1+k),true,fH,fV);
				}
			}
		}
		else
		{
			CFormImg* pImg = (CFormImg*)m_pFormImg;

			if (pImg->IsConvolution(strLib) == true)
			{
				if (strLib == _T("Uniform"))			bRet = CEImgConvolution::Uniform		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Uniform3x3"))	bRet = CEImgConvolution::Uniform3x3		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Uniform5x5"))	bRet = CEImgConvolution::Uniform5x5		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Uniform7x7"))	bRet = CEImgConvolution::Uniform7x7		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Gaussian"))		bRet = CEImgConvolution::Gaussian		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Gaussian3x3"))	bRet = CEImgConvolution::Gaussian3x3	(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Gaussian5x5"))	bRet = CEImgConvolution::Gaussian5x5	(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Gaussian7x7"))	bRet = CEImgConvolution::Gaussian7x7	(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Lowpass1"))		bRet = CEImgConvolution::Lowpass1		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Lowpass2"))		bRet = CEImgConvolution::Lowpass2		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Highpass1"))		bRet = CEImgConvolution::Highpass1		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Highpass2"))		bRet = CEImgConvolution::Highpass2		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Gradient"))		bRet = CEImgConvolution::Gradient		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("GradientX"))		bRet = CEImgConvolution::GradientX		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("GradientY"))		bRet = CEImgConvolution::GradientY		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Sobel"))			bRet = CEImgConvolution::Sobel			(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("SobelX"))		bRet = CEImgConvolution::SobelX			(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("SobelY"))		bRet = CEImgConvolution::SobelY			(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Prewitt"))		bRet = CEImgConvolution::Prewitt		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("PrewittX"))		bRet = CEImgConvolution::PrewittX		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("PrewittY"))		bRet = CEImgConvolution::PrewittY		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Roberts"))		bRet = CEImgConvolution::Roberts		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("LaplacianX"))	bRet = CEImgConvolution::LaplacianX		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("LaplacianY"))	bRet = CEImgConvolution::LaplacianY		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Laplacian4"))	bRet = CEImgConvolution::Laplacian4		(pIn1, strIn1, pOut, strOut, time);
				else if (strLib == _T("Laplacian8"))	bRet = CEImgConvolution::Laplacian8		(pIn1, strIn1, pOut, strOut, time);
			}
			else if (pImg->IsMorphology(strLib) == true)
			{
				StItemInfo info = m_vItmInfo.at(i);
				int nHalf = info.stLib.stImg.stMorphology.nHalfKernel;
				if (strLib == _T("Erode"))				bRet = CEImgMorphology::Erode		(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("Dilate"))		bRet = CEImgMorphology::Dilate		(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("Open"))			bRet = CEImgMorphology::Open		(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("Close"))			bRet = CEImgMorphology::Close		(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("White Top Hat"))	bRet = CEImgMorphology::WhiteTopHat	(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("Black Top Hat"))	bRet = CEImgMorphology::BlackTopHat	(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("Morpho Gradient"))bRet = CEImgMorphology::Gradient	(pIn1, strIn1, pOut, strOut, nHalf, time);
				else if (strLib == _T("Median 3x3"))	bRet = CEImgMorphology::Median3x3	(pIn1, strIn1, pOut, strOut, time);
			}
			else if (pImg->IsThreshold(strLib) == true)
			{
				StItemInfo info = m_vItmInfo.at(i);
				if (strLib == _T("Simple Threshold"))
				{
					CString strType = info.stLib.stImg.stThreshold.stSimple.strType;
					if (strType == _T("Absolute"))				bRet = CEImgThreshold::ThresholdABS(pIn1, strIn1, pOut, strOut, info.stLib.stImg.stThreshold.stSimple.nAbs, time);
					else if (strType == _T("Relative"))
					{
						float fRel = (float)(info.stLib.stImg.stThreshold.stSimple.nRel)/100;
						bRet = CEImgThreshold::ThresholdRelative(pIn1, strIn1, pOut, strOut, fRel, time);
					}
					else if (strType == _T("Minimum Residue"))	bRet = CEImgThreshold::ThresholdMinResidue(pIn1, strIn1, pOut, strOut, time);
					else if (strType == _T("Maximum Entropy"))	bRet = CEImgThreshold::ThresholdMaxEntropy(pIn1, strIn1, pOut, strOut, time);
					else if (strType == _T("Iso-Data"))			bRet = CEImgThreshold::ThresholdIsoData(pIn1, strIn1, pOut, strOut, time);
				}
				else if (strLib == _T("Double Threshold"))
				{
					int nPxlHigh = info.stLib.stImg.stThreshold.stDouble.nPxlHigh;
					int nPxlMid  = info.stLib.stImg.stThreshold.stDouble.nPxlMid;
					int nPxlLow  = info.stLib.stImg.stThreshold.stDouble.nPxlLow;
					int nThdHigh = info.stLib.stImg.stThreshold.stDouble.nThdHigh;
					int nThdLow  = info.stLib.stImg.stThreshold.stDouble.nThdLow;

					bRet = CEImgThreshold::ThresholdDouble(pIn1, strIn1, pOut, strOut, nPxlHigh, nThdHigh, nPxlMid, nThdLow, nPxlLow, time);
				}
				else if (strLib == _T("Adaptive Threshold"))
				{
					CString strType = info.stLib.stImg.stThreshold.stAdaptive.strType;
					int nKernel = info.stLib.stImg.stThreshold.stAdaptive.nKernel;
					int nOffset = info.stLib.stImg.stThreshold.stAdaptive.nOffset;

					if (strType == _T("Mean"))			bRet = CEImgThreshold::ThresholdAdaptiveMean(pIn1, strIn1, pOut, strOut, nKernel, nOffset, time);
					else if (strType == _T("Median"))	bRet = CEImgThreshold::ThresholdAdaptiveMedian(pIn1, strIn1, pOut, strOut, nKernel, nOffset, time);
					else if (strType == _T("Middle"))	bRet = CEImgThreshold::ThresholdAdaptiveMiddle(pIn1, strIn1, pOut, strOut, nKernel, nOffset, time);
				}
			}
			else if (pImg->IsArtihemetic(strLib) == true)
			{
				StItemInfo info = m_vItmInfo.at(i);

				CString strType = info.stLib.stImg.stArithmetic.strType;
				if (strType == _T("Copy"))
					bRet = CEImgArithmetic::Oper_Copy(pIn1, strIn1, pOut, strOut, time);
				else if (strType == _T("Invert"))
					bRet = CEImgArithmetic::Oper_Invert(pIn1, strIn1, pOut, strOut, time);
				else if (strType == _T("Add"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Add(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Add(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Add(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Subtract"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Subtract(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Subtract(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Subtract(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Compare"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Compare(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Compare(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Compare(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Multiply"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Multiply(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Multiply(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Multiply(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Divide"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Divide(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Divide(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Divide(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Modulo"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Modulo(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Modulo(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Modulo(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Scaled Add"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_ScaledAdd(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_ScaledAdd(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_ScaledAdd(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Scaled Subtract"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_ScaledSubtract(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_ScaledSubtract(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_ScaledSubtract(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Scaled Multiply"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_ScaledMultiply(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_ScaledMultiply(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_ScaledMultiply(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Scaled Divide"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_ScaledDivide(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_ScaledDivide(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_ScaledDivide(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Shift Left"))
				{
					int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
					bRet = CEImgArithmetic::Oper_ShiftLeft(pIn1, strIn1, nY8, pOut, strOut, time);
				}
				else if (strType == _T("Shift Right"))
				{
					int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
					bRet = CEImgArithmetic::Oper_ShiftRight(pIn1, strIn1, nY8, pOut, strOut, time);
				}
				else if (strType == _T("Bitwise AND"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_BitwiseAND(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_BitwiseAND(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_BitwiseAND(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Bitwise OR"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_BitwiseOR(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_BitwiseOR(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_BitwiseOR(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Bitwise XOR"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_BitwiseXOR(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_BitwiseXOR(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_BitwiseXOR(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Logical AND"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_LogicalAND(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_LogicalAND(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Logical OR"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_LogicalOR(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_LogicalOR(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Logical XOR"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_LogicalXOR(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_LogicalXOR(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Minimum"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Minimum(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Minimum(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Minimum(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Maximum"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Maximum(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Maximum(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Maximum(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Set Zero"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_SetZero(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_SetZero(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_SetZero(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Set Non Zero"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_SetNonZero(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_SetNonZero(pIn1, strIn1, nY8, pOut, strOut, time);
						}
					}
				}
				else if (strType == _T("Equal"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Equal(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Equal(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Equal(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Not Equal"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_NotEqual(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_NotEqual(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_NotEqual(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Greater or Equal"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_GreaterOrEqual(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_GreaterOrEqual(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_GreaterOrEqual(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Lesser or Equal"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_LesserOrEqual(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_LesserOrEqual(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_LesserOrEqual(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Greater"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Greater(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Greater(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Greater(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
				else if (strType == _T("Lesser"))
				{
					// In1 Image & In2 Image
					if (m_rbtnIn1 == 0 && m_rbtnIn2 == 0)
						bRet = CEImgArithmetic::Oper_Lesser(pIn1, strIn1, pIn2, strIn2, pOut, strOut, time);
					// In1 Constant & In2 Image
					else if (m_rbtnIn1 == 1 && m_rbtnIn2 == 0)
					{
						// In1 Gray
						if (m_rbtnCst1 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY1);
							bRet = CEImgArithmetic::Oper_Lesser(nY8, pIn2, strIn2, pOut, strOut, time);
						}
						// In1 Color
						else
						{

						}
					}
					// In1 Image & In2 Constant
					else if (m_rbtnIn1 == 0 && m_rbtnIn2 == 1)
					{
						// In2 Gray
						if (m_rbtnCst2 == 0)
						{
							int nY8 = GetDlgItemInt(IDC_MAIN_EDIT_GRAY2);
							bRet = CEImgArithmetic::Oper_Lesser(pIn1, strIn1, nY8, pOut, strOut, time);
						}
						// In2 Color
						else
						{

						}
					}
				}
			}
			else if (pImg->IsScaleRotate(strLib) == true)
			{
				StItemInfo info = m_vItmInfo.at(i);
				
				float fSrcPvtX = info.stLib.stImg.stScale.fSrcPvtX;
				float fSrcPvtY = info.stLib.stImg.stScale.fSrcPvtY;
				float fDstPvtX = info.stLib.stImg.stScale.fDstPvtX;
				float fDstPvtY = info.stLib.stImg.stScale.fDstPvtY;
				float fScaleX = info.stLib.stImg.stScale.fScaleX;
				float fScaleY = info.stLib.stImg.stScale.fScaleY;
				float fAngle = info.stLib.stImg.stScale.fAngle;
				int nBits = info.stLib.stImg.stScale.nBits;

				bRet = CEImgScaleRotate::ScaleRotate(pIn1, strIn1, pOut, strOut, fSrcPvtX, fSrcPvtY, fDstPvtX, fDstPvtY, fScaleX, fScaleY, fAngle, nBits, time);
			}
			else if (pImg->IsGainOffset(strLib) == true)
			{
				StItemInfo info = m_vItmInfo.at(i);

				float fGain = info.stLib.stImg.stGain.fGain;
				float fOffset = info.stLib.stImg.stGain.fOffset;

				bRet = CEImgGainOffset::GainOffset(pIn1, strIn1, pOut, strOut, fGain, fOffset, time);
			}

			if (bRet == false)
			{
				m_wndLc.SetItemColor(i, 8, RGB(255,0,0));
				continue;
			}

			m_wndLc.SetItemColor(i, 8, RGB(0,255,0));

			for (vector<CEImage>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
			{
				CString fileName=_T("");
				it->GetImageName(fileName);

				if (fileName == strOut)
				{
					it->SetImage(pOut->GetImage());
					break;
				}
			}

			CString fileName = _T("");
			pOut->GetImageName(fileName);
			UpdateFileNameView(fileName);
		}

		CString strTime=_T("");
		strTime.Format(_T("%.3f"),time);
		m_wndLc.SetItemText(i,7,strTime);

	}
}

void CFilterSimDlg::OnBnClickedMainBtnAddroi()
{
	CString strSelImg = GetTextCBSelected(IDC_MAIN_CB_IMGLIST);
	bool bContinue=false;
	std::vector<CEImage>::iterator it;

	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); it++)
	{
		CString name=_T("");
		it->GetImageName(name);

		if (strSelImg == name)
		{
			bContinue = true;
			break;
		}
	}

	if (bContinue == false)
	{
		CString msg = _T("ROI는 이미지에 생성할 수 있습니다.");
		MessageBox(msg,_T("Information"),MB_ICONINFORMATION);
		return;
	}

	int nOrgX=0,nOrgY=0,nWidth=0,nHeight=0;
	CString strName=_T("");
	nOrgX	= GetDlgItemInt(IDC_MAIN_EDIT_ORGX);
	nOrgY	= GetDlgItemInt(IDC_MAIN_EDIT_ORGY);
	nWidth	= GetDlgItemInt(IDC_MAIN_EDIT_WIDTH);
	nHeight = GetDlgItemInt(IDC_MAIN_EDIT_HEIGHT);
	GetDlgItemText(IDC_MAIN_EDIT_ROINAME, strName);
	
	if (IsExistName(strName) == true)
	{
		AfxMessageBox(_T("중복되는 이름이 존재합니다."));
		return;
	}

	it->CreateRoi(nOrgX,nOrgY,nWidth,nHeight,strName);

	UpdateCBList();
	
	UpdateAllView();

	SetDlgItemText(IDC_MAIN_EDIT_ORGX, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_ORGY, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_WIDTH, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_HEIGHT, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_ROINAME, _T(""));
}

void CFilterSimDlg::OnBnClickedMainBtnModify()
{
	CString strSel = GetTextCBSelected(IDC_MAIN_CB_IMGLIST);
	std::vector<CEImage>::iterator it;

	if (strSel.Find(_T(" - ")) == 0)
	{
		int len = strSel.GetLength();
		strSel = strSel.Right(len-3);
	}

	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); it++)
	{
		CString name=_T("");
		if (it->HasROI(strSel) == true)
			break;
	}

	int nOrgX=0,nOrgY=0,nWidth=0,nHeight=0;
	CString strName=_T("");
	nOrgX	= GetDlgItemInt(IDC_MAIN_EDIT_ORGX);
	nOrgY	= GetDlgItemInt(IDC_MAIN_EDIT_ORGY);
	nWidth	= GetDlgItemInt(IDC_MAIN_EDIT_WIDTH);
	nHeight = GetDlgItemInt(IDC_MAIN_EDIT_HEIGHT);
	GetDlgItemText(IDC_MAIN_EDIT_ROINAME, strName);

	it->ModifyRoi(strName,nOrgX,nOrgY,nWidth,nHeight);

	UpdateAllView();
}


void CFilterSimDlg::OnBnClickedMainBtnDelroi()
{
	CString strSelRoi = GetTextCBSelected(IDC_MAIN_CB_IMGLIST);
	int len = strSelRoi.GetLength();
	strSelRoi = strSelRoi.Right(len-3);

	std::vector<CEImage>::iterator it1;
	for (it1 = m_vImgInfo.begin(); it1 != m_vImgInfo.end(); it1++)
	{
		for (int i=0; i<it1->GetRoiCount(); i++)
		{
			CString strName=_T("");
			it1->GetRoiName(i, strName);
			
			if (strName == strSelRoi)
			{
				it1->DeleteRoi(strSelRoi);
			}
		}
	}

	std::vector<StItemInfo>::iterator it2;
	for (it2 = m_vItmInfo.begin(); it2 != m_vItmInfo.end(); it2++)
	{
		if (it2->strIn1 == strSelRoi)
			it2->strIn1 = _T("");
		if (it2->strIn2 == strSelRoi)
			it2->strIn2 = _T("");
		if (it2->strOut == strSelRoi)
			it2->strOut = _T("");
	}

	SetDlgItemText(IDC_MAIN_EDIT_ORGX, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_ORGY, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_WIDTH, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_HEIGHT, _T(""));
	SetDlgItemText(IDC_MAIN_EDIT_ROINAME, _T(""));

	UpdateCBList();

	UpdateAllView();

	UpdateItemList();
}
	

void CFilterSimDlg::UpdateAllView()
{
	for (int i=0; i<4; i++)
	{
		DrawEmptyImage(i);

		CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW1+i);
		if (name == _T("")) continue;

		vector<CEImage>::iterator it;
		for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString fileName=_T("");
			it->GetImageName(fileName);
			if (name == fileName) 
				break;
		}

		DrawImage(i, name);
	}
}

void CFilterSimDlg::UpdateFileNameView(CString strFile)
{
	for (int i=0; i<4; i++)
	{
		CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW1+i);
		if (name == _T("")) continue;
		if (name != strFile) continue;

		vector<CEImage>::iterator it;
		for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString fileName=_T("");
			it->GetImageName(fileName);
			if (name == fileName) 
				break;
		}

		DrawImage(i, name);
	}
}

bool CFilterSimDlg::IsExistName(CString strName)
{
	bool bExist = false;
	vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		for (int i=0; i<it->GetRoiCount(); i++)
		{
			it->GetRoiName(i, fileName);
			if (strName == fileName)
			{
				bExist = true;
				break;
			}
		}
		
		it->GetImageName(fileName);
		if (strName == fileName) 
		{
			bExist = true;
			break;
		}
	}

	return bExist;
}

void CFilterSimDlg::OnCbnSelchangeMainCbImglist()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_IMGLIST);
	int sel = pCB->GetCurSel();
	CString strSel=_T("");
	pCB->GetLBText(sel, strSel);

	if (strSel.Find(_T(" - ")) == 0)
	{
		int len = strSel.GetLength();
		strSel = strSel.Right(len-3);
	}

	bool bSelRoi = false;
	vector<CEImage>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetImageName(fileName);
		if (it->HasROI(strSel) == true)
		{
			bSelRoi = true;
			break;
		}
	}

	if (bSelRoi == true)
	{
		int orgx=0,orgy=0,w=0,h=0;
		it->GetRoiPlacement(strSel, orgx, orgy, w, h);

		SetDlgItemInt(IDC_MAIN_EDIT_ORGX, orgx);
		SetDlgItemInt(IDC_MAIN_EDIT_ORGY, orgy);
		SetDlgItemInt(IDC_MAIN_EDIT_WIDTH, w);
		SetDlgItemInt(IDC_MAIN_EDIT_HEIGHT, h);
		SetDlgItemText(IDC_MAIN_EDIT_ROINAME, strSel);
	}
	else
	{
		SetDlgItemText(IDC_MAIN_EDIT_ORGX, _T(""));
		SetDlgItemText(IDC_MAIN_EDIT_ORGY, _T(""));
		SetDlgItemText(IDC_MAIN_EDIT_WIDTH, _T(""));
		SetDlgItemText(IDC_MAIN_EDIT_HEIGHT, _T(""));
		SetDlgItemText(IDC_MAIN_EDIT_ROINAME, _T(""));
	}
}

void CFilterSimDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	m_vImgInfo.clear();
	m_vItmInfo.clear();
}

void CFilterSimDlg::OnBnClickedMainRBtnImgCst1(UINT ID)
{
	UpdateData(TRUE);

	GetDlgItem(IDC_MAIN_EDIT_GRAY1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_R1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_G1)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_B1)->EnableWindow(FALSE);

	int state = IsDlgButtonChecked(IDC_MAIN_RBTN_INIMG1);

	if (state == 1)
	{
		GetDlgItem(IDC_MAIN_CB_INPUT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_RBTN_CSTGRAY1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_RBTN_CSTCLR1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_MAIN_CB_INPUT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_RBTN_CSTGRAY1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_RBTN_CSTCLR1)->EnableWindow(TRUE);
		CheckRadioButton(IDC_MAIN_RBTN_CSTGRAY1, IDC_MAIN_RBTN_CSTCLR1, IDC_MAIN_RBTN_CSTGRAY1);
		GetDlgItem(IDC_MAIN_EDIT_GRAY1)->EnableWindow(TRUE);
	}
}

void CFilterSimDlg::OnBnClickedMainRBtnImgCst2(UINT ID)
{
	UpdateData(TRUE);

	GetDlgItem(IDC_MAIN_EDIT_GRAY2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_R2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_G2)->EnableWindow(FALSE);
	GetDlgItem(IDC_MAIN_EDIT_B2)->EnableWindow(FALSE);

	int state = IsDlgButtonChecked(IDC_MAIN_RBTN_INIMG2);

	if (state == 1)
	{
		GetDlgItem(IDC_MAIN_CB_INPUT2)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_RBTN_CSTGRAY2)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_RBTN_CSTCLR2)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_MAIN_CB_INPUT2)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_RBTN_CSTGRAY2)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_RBTN_CSTCLR2)->EnableWindow(TRUE);
		CheckRadioButton(IDC_MAIN_RBTN_CSTGRAY2, IDC_MAIN_RBTN_CSTCLR2, IDC_MAIN_RBTN_CSTGRAY2);
		GetDlgItem(IDC_MAIN_EDIT_GRAY2)->EnableWindow(TRUE);
	}
}

void CFilterSimDlg::OnBnClickedMainRBtnGrayClr1(UINT ID)
{
	UpdateData(TRUE);

	int state = IsDlgButtonChecked(IDC_MAIN_RBTN_CSTGRAY1);

	if (state == 1)
	{
		GetDlgItem(IDC_MAIN_EDIT_GRAY1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_EDIT_R1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_EDIT_G1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_EDIT_B1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_MAIN_EDIT_GRAY1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_EDIT_R1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_EDIT_G1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_EDIT_B1)->EnableWindow(TRUE);
	}
}

void CFilterSimDlg::OnBnClickedMainRBtnGrayClr2(UINT ID)
{
	UpdateData(TRUE);

	int state = IsDlgButtonChecked(IDC_MAIN_RBTN_CSTGRAY2);

	if (state == 1)
	{
		GetDlgItem(IDC_MAIN_EDIT_GRAY2)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_EDIT_R2)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_EDIT_G2)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_EDIT_B2)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_MAIN_EDIT_GRAY2)->EnableWindow(FALSE);
		GetDlgItem(IDC_MAIN_EDIT_R2)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_EDIT_G2)->EnableWindow(TRUE);
		GetDlgItem(IDC_MAIN_EDIT_B2)->EnableWindow(TRUE);
	}
}

void CFilterSimDlg::SetEnableIOList(bool bIn1Img, bool bIn1Cst, bool bIn2Img, bool bIn2Cst, bool bOutImg)
{
	GetDlgItem(IDC_MAIN_RBTN_INCST1)->EnableWindow(bIn1Cst);
	if (bIn1Cst == true)
		CheckRadioButton(IDC_MAIN_RBTN_INIMG1, IDC_MAIN_RBTN_INCST1, IDC_MAIN_RBTN_INCST1);

	GetDlgItem(IDC_MAIN_RBTN_INIMG1)->EnableWindow(bIn1Img);
	GetDlgItem(IDC_MAIN_CB_INPUT1)->EnableWindow(bIn1Img);
	if (bIn1Img == true)
		CheckRadioButton(IDC_MAIN_RBTN_INIMG1, IDC_MAIN_RBTN_INCST1, IDC_MAIN_RBTN_INIMG1);
	
	GetDlgItem(IDC_MAIN_RBTN_INCST2)->EnableWindow(bIn2Cst);
	if (bIn2Cst == true)
		CheckRadioButton(IDC_MAIN_RBTN_INIMG2, IDC_MAIN_RBTN_INCST2, IDC_MAIN_RBTN_INCST2);

	GetDlgItem(IDC_MAIN_RBTN_INIMG2)->EnableWindow(bIn2Img);
	GetDlgItem(IDC_MAIN_CB_INPUT2)->EnableWindow(bIn2Img);
	if (bIn2Img == true)
		CheckRadioButton(IDC_MAIN_RBTN_INIMG2, IDC_MAIN_RBTN_INCST2, IDC_MAIN_RBTN_INIMG2);
	
	GetDlgItem(IDC_MAIN_CB_OUTPUT)->EnableWindow(bOutImg);
}

