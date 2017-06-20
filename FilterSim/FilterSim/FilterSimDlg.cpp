
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nSelected = -1;
	m_nImgCnt = 0;
}

void CFilterSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_LC_ITEM, m_wndLc);
	
}

BEGIN_MESSAGE_MAP(CFilterSimDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MAIN_BTN_ADDITEM, &CFilterSimDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_MAIN_BTN_DELITEM, &CFilterSimDlg::OnBnClickedBtnDelete)
	ON_NOTIFY(NM_CLICK, IDC_MAIN_LC_ITEM, &CFilterSimDlg::OnNMClickLcItem)
	ON_BN_CLICKED(IDC_MAIN_BTN_LOADIMG, &CFilterSimDlg::OnBnClickedBtnLoad)
	
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW1, &CFilterSimDlg::OnCbnSelchangeCbView1)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW2, &CFilterSimDlg::OnCbnSelchangeCbView2)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW3, &CFilterSimDlg::OnCbnSelchangeCbView3)
	ON_CBN_SELCHANGE(IDC_MAIN_CB_VIEW4, &CFilterSimDlg::OnCbnSelchangeCbView4)
	ON_BN_CLICKED(IDC_MAIN_BTN_EXECUTE, &CFilterSimDlg::OnBnClickedBtnExecute)
	ON_BN_CLICKED(IDC_MAIN_BTN_NEWIMG, &CFilterSimDlg::OnBnClickedBtnNew)
	ON_BN_CLICKED(IDC_MAIN_BTN_DELIMG, &CFilterSimDlg::OnBnClickedMainBtnDelimg)
	ON_BN_CLICKED(IDC_MAIN_BTN_SAVEIMG, &CFilterSimDlg::OnBnClickedMainBtnSaveimg)
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

	try
	{
		EImageBW8 init;
		init.SetSize(100,100);
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
	}

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
	int w = GetSystemMetrics(SM_CXSCREEN);
	int h = GetSystemMetrics(SM_CYSCREEN);

	this->MoveWindow( (w-1375)/2, (h-1000)/2, 1375, 1000);

	GetDlgItem(IDC_MAIN_BTN_LOADIMG)->MoveWindow( 950,  30, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_SAVEIMG)->MoveWindow(1050,  30, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_NEWIMG )->MoveWindow(1150,  30, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_DELIMG )->MoveWindow(1250,  30, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_ADDITEM)->MoveWindow( 950, 150, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_DELITEM)->MoveWindow(1050, 150, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_EXECUTE)->MoveWindow(1245, 150, 100,  50);
											   	    	 
	GetDlgItem(IDC_MAIN_PC_VIEW1)->MoveWindow(  25,  30, 450, 450);
	GetDlgItem(IDC_MAIN_PC_VIEW2)->MoveWindow( 485,  30, 450, 450);
	GetDlgItem(IDC_MAIN_PC_VIEW3)->MoveWindow(  25, 510, 450, 450);
	GetDlgItem(IDC_MAIN_PC_VIEW4)->MoveWindow( 485, 510, 450, 450);

	GetDlgItem(IDC_MAIN_LB_INFO1)->MoveWindow(  25,   9, 200,  15);
	GetDlgItem(IDC_MAIN_LB_INFO2)->MoveWindow( 485,   9, 200,  15);
	GetDlgItem(IDC_MAIN_LB_INFO3)->MoveWindow(  25, 489, 200,  15);
	GetDlgItem(IDC_MAIN_LB_INFO4)->MoveWindow( 485, 489, 200,  15);
												    	 
	GetDlgItem(IDC_MAIN_CB_VIEW1)->MoveWindow( 325,   9, 150,  15);
	GetDlgItem(IDC_MAIN_CB_VIEW2)->MoveWindow( 785,   9, 150,  15);
	GetDlgItem(IDC_MAIN_CB_VIEW3)->MoveWindow( 325, 489, 150,  15);
	GetDlgItem(IDC_MAIN_CB_VIEW4)->MoveWindow( 785, 489, 150,  15);

	GetDlgItem(IDC_MAIN_LC_ITEM )->MoveWindow( 950, 200, 395, 760);

	m_wndLc.InsertColumn(0, _T("")		, LVCFMT_LEFT  ,   0);
	m_wndLc.InsertColumn(1, _T("Index")	, LVCFMT_CENTER,  50);
	m_wndLc.InsertColumn(2, _T("Filter"), LVCFMT_CENTER,  80);
	m_wndLc.InsertColumn(3, _T("Input")	, LVCFMT_CENTER,  90);
	m_wndLc.InsertColumn(4, _T("Output"), LVCFMT_CENTER,  90);
	m_wndLc.InsertColumn(5, _T("ETC")	, LVCFMT_CENTER,  90);
	m_wndLc.EnableVScroll();
	m_wndLc.SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void CFilterSimDlg::OnBnClickedBtnAdd()
{
	int n = m_wndLc.GetItemCount();

	m_wndLc.SetRowColumnType(n, 0, CListCtrlEx::eType_ReadOnly);
	m_wndLc.SetRowColumnType(n, 1, CListCtrlEx::eType_ReadOnly);
	m_wndLc.SetRowColumnType(n, 2, CListCtrlEx::eType_Combo);
	m_wndLc.SetRowColumnType(n, 3, CListCtrlEx::eType_Combo);
	m_wndLc.SetRowColumnType(n, 4, CListCtrlEx::eType_Combo);
	m_wndLc.InsertItem(n,_T(""));
	
	// 각 row 의 두 번째 col (index) 설정 부분.
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
	m_wndLc.AddString(n,1,strIdx);

	{
		m_wndLc.AddString(n,2,_T("Uniform"));
		m_wndLc.AddString(n,2,_T("Uniform3x3"));
		m_wndLc.AddString(n,2,_T("Uniform5x5"));
		m_wndLc.AddString(n,2,_T("Uniform7x7"));
		m_wndLc.AddString(n,2,_T("Gaussian"));
		m_wndLc.AddString(n,2,_T("Gaussian3x3"));
		m_wndLc.AddString(n,2,_T("Gaussian5x5"));
		m_wndLc.AddString(n,2,_T("Gaussian7x7"));
		m_wndLc.AddString(n,2,_T("Lowpass1"));
		m_wndLc.AddString(n,2,_T("Lowpass2"));
		m_wndLc.AddString(n,2,_T("Highpass1"));
		m_wndLc.AddString(n,2,_T("Highpass2"));
		m_wndLc.AddString(n,2,_T("Gradient"));
		m_wndLc.AddString(n,2,_T("GradientX"));
		m_wndLc.AddString(n,2,_T("GradientY"));
		m_wndLc.AddString(n,2,_T("Sobel"));
		m_wndLc.AddString(n,2,_T("SobelX"));
		m_wndLc.AddString(n,2,_T("SobelY"));
		m_wndLc.AddString(n,2,_T("Prewitt"));
		m_wndLc.AddString(n,2,_T("PrewittX"));
		m_wndLc.AddString(n,2,_T("PrewittY"));
		m_wndLc.AddString(n,2,_T("Roberts"));
		m_wndLc.AddString(n,2,_T("LaplacianX"));
		m_wndLc.AddString(n,2,_T("LaplacianY"));
		m_wndLc.AddString(n,2,_T("Laplacian4"));
		m_wndLc.AddString(n,2,_T("Laplacian8"));
	}

	UpdateLCList();
}


void CFilterSimDlg::OnBnClickedBtnDelete()
{
	m_wndLc.DeleteItem(m_nSelected);
}

void CFilterSimDlg::OnNMClickLcItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_nSelected = pNMListView -> iItem;//

	*pResult = 0;
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

			CImgInfo info;

			try
			{
				CT2CA String (strPath);
				std::string str(String);  
				EImageBW8* pImg = info.GetImage();
				pImg->Load(str);
			}
			catch (EException& e)
			{
				CString strErr = (CString)e.What().c_str();
				AfxMessageBox(strErr);
				return;
			}

			info.SetFileName(fileName);

			m_vImgInfo.push_back(info);

			CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW1);
			pCB->AddString(fileName);
			pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW2);
			pCB->AddString(fileName);
			pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW3);
			pCB->AddString(fileName);
			pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW4);
			pCB->AddString(fileName);

			int n = m_wndLc.GetItemCount();
			for (int i=0; i<n; i++)
			{
				m_wndLc.AddString(i,3,fileName);
				m_wndLc.AddString(i,4,fileName);
			}

			m_nImgCnt++;
		}
	}
}

void CFilterSimDlg::OnBnClickedBtnExecute()
{
	int n = m_wndLc.GetItemCount();

	for (int i=0; i<n; i++)
	{
		CString filter	= m_wndLc.GetItemText(i,2);
		CString imgIn	= m_wndLc.GetItemText(i,3);
		CString imgOut	= m_wndLc.GetItemText(i,4);

		EImageBW8 *pIn = NULL, *pOut = NULL;
		for (vector<CImgInfo>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString fileName=_T("");
			it->GetFileName(fileName);

			if (fileName == imgIn)
				pIn = it->GetImage();
			
			if (fileName == imgOut)
				pOut = it->GetImage();
		}

		if (filter == _T("Uniform"))			CEImgFilter::OnFilter_Uniform(pIn, pOut);
		else if (filter == _T("Uniform3x3"))	CEImgFilter::OnFilter_Uniform3x3(pIn, pOut);
		else if (filter == _T("Uniform5x5"))	CEImgFilter::OnFilter_Uniform5x5(pIn, pOut);
		else if (filter == _T("Uniform7x7"))	CEImgFilter::OnFilter_Uniform7x7(pIn, pOut);
		else if (filter == _T("Gaussian"))		CEImgFilter::OnFilter_Gaussian(pIn, pOut);
		else if (filter == _T("Gaussian3x3"))	CEImgFilter::OnFilter_Gaussian3x3(pIn, pOut);
		else if (filter == _T("Gaussian5x5"))	CEImgFilter::OnFilter_Gaussian5x5(pIn, pOut);
		else if (filter == _T("Gaussian7x7"))	CEImgFilter::OnFilter_Gaussian7x7(pIn, pOut);
		else if (filter == _T("Lowpass1"))		CEImgFilter::OnFilter_Lowpass1(pIn, pOut);
		else if (filter == _T("Lowpass2"))		CEImgFilter::OnFilter_Lowpass2(pIn, pOut);
		else if (filter == _T("Highpass1"))		CEImgFilter::OnFilter_Highpass1(pIn, pOut);
		else if (filter == _T("Highpass2"))		CEImgFilter::OnFilter_Highpass2(pIn, pOut);
		else if (filter == _T("Gradient"))		CEImgFilter::OnFilter_Gradient(pIn, pOut);
		else if (filter == _T("GradientX"))		CEImgFilter::OnFilter_GradientX(pIn, pOut);
		else if (filter == _T("GradientY"))		CEImgFilter::OnFilter_GradientY(pIn, pOut);
		else if (filter == _T("Sobel"))			CEImgFilter::OnFilter_Sobel(pIn, pOut);
		else if (filter == _T("SobelX"))		CEImgFilter::OnFilter_SobelX(pIn, pOut);
		else if (filter == _T("SobelY"))		CEImgFilter::OnFilter_SobelY(pIn, pOut);
		else if (filter == _T("Prewitt"))		CEImgFilter::OnFilter_Prewitt(pIn, pOut);
		else if (filter == _T("PrewittX"))		CEImgFilter::OnFilter_PrewittX(pIn, pOut);
		else if (filter == _T("PrewittY"))		CEImgFilter::OnFilter_PrewittY(pIn, pOut);
		else if (filter == _T("Roberts"))		CEImgFilter::OnFilter_Roberts(pIn, pOut);
		else if (filter == _T("LaplacianX"))	CEImgFilter::OnFilter_LaplacianX(pIn, pOut);
		else if (filter == _T("LaplacianY"))	CEImgFilter::OnFilter_LaplacianY(pIn, pOut);
		else if (filter == _T("Laplacian4"))	CEImgFilter::OnFilter_Laplacian4(pIn, pOut);
		else if (filter == _T("Laplacian8"))	CEImgFilter::OnFilter_Laplacian8(pIn, pOut);

		for (vector<CImgInfo>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString fileName=_T("");
			it->GetFileName(fileName);

			if (fileName == imgOut)
			{
				it->SetImage(pOut);
				break;
			}
		}
	}

	for (int i=0; i<4; i++)
	{
		CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW1+i);
		if (name == _T("")) continue;

		vector<CImgInfo>::iterator it;
		for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString fileName=_T("");
			it->GetFileName(fileName);
			if (name == fileName) 
				break;
		}

		DrawImage(i, name);
	}
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
	
	vector<CImgInfo>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetFileName(fileName);
		if (strFileName == fileName) break;
	}
	
	try
	{
		EImageBW8* pImg = it->GetImage();

		float fH = (float)rect.Width()/pImg->GetWidth();
		float fV = (float)rect.Height()/pImg->GetHeight();
		pImg->Draw(pWnd->GetDC()->GetSafeHdc(), fH, fV);
	}
	catch (EException& e)
	{
		CString strErr = (CString)e.What().c_str();
		AfxMessageBox(strErr);
		return;
	}
}

void CFilterSimDlg::OnCbnSelchangeCbView1()
{
	CString name = GetTextCBSelected(IDC_MAIN_CB_VIEW1);

	vector<CImgInfo>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetFileName(fileName);
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

	vector<CImgInfo>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetFileName(fileName);
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

	vector<CImgInfo>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetFileName(fileName);
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

	vector<CImgInfo>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		CString fileName=_T("");
		it->GetFileName(fileName);
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


void CFilterSimDlg::OnBnClickedBtnNew()
{
	CNewDlg dlg(m_nImgCnt, m_vImgInfo);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetName();
		int w = dlg.GetWidth();
		int h = dlg.GetHeight();

		CImgInfo info;

		try
		{
			info.CreatImage(w,h,8);
		}
		catch (EException& e)
		{
			CString strErr = (CString)e.What().c_str();
			AfxMessageBox(strErr);
			return;
		}

		info.SetFileName(fileName);

		m_vImgInfo.push_back(info);

		CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW1);
		pCB->AddString(fileName);
		pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW2);
		pCB->AddString(fileName);
		pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW3);
		pCB->AddString(fileName);
		pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW4);
		pCB->AddString(fileName);

		int n = m_wndLc.GetItemCount();
		for (int i=0; i<n; i++)
		{
			m_wndLc.AddString(i,3,fileName);
			m_wndLc.AddString(i,4,fileName);
		}

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

void CFilterSimDlg::OnBnClickedMainBtnDelimg()
{
	CSelectDlg dlg(m_vImgInfo);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetName();
		
		for (std::vector<CImgInfo>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end();)
		{
			CString name=_T("");
			it->GetFileName(name);

			if (fileName == name)
			{
				it = m_vImgInfo.erase(it);
			}
			else
			{
				++it;
			}
		}

		UpdateCBList();
	}

	UpdateLCList();
}

void CFilterSimDlg::UpdateCBList()
{
	for (int i=0; i<4; i++)
	{
		CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_VIEW1+i);
		pCB->ResetContent();

		for (std::vector<CImgInfo>::iterator it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString name=_T("");
			it->GetFileName(name);
			pCB->AddString(name);
		}
	}
}

void CFilterSimDlg::UpdateLCList()
{
	int n = m_wndLc.GetItemCount();
	for (int i=0; i<n; i++)
	{
		m_wndLc.ClearString(i,3);
		m_wndLc.ClearString(i,4);
	}

	vector<CImgInfo>::iterator it;
	for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
	{
		for (int i=0; i<n; i++)
		{
			CString name=_T("");
			it->GetFileName(name);
			m_wndLc.AddString(i,3,name);
			m_wndLc.AddString(i,4,name);
		}
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


void CFilterSimDlg::OnBnClickedMainBtnSaveimg()
{
	CSelectDlg dlg(m_vImgInfo);
	if (dlg.DoModal() == IDOK)
	{
		CString fileName = dlg.GetName();

		std::vector<CImgInfo>::iterator it;
		for (it = m_vImgInfo.begin(); it != m_vImgInfo.end(); ++it)
		{
			CString name=_T("");
			it->GetFileName(name);
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
