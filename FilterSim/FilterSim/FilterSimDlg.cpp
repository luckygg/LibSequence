
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

	m_pFormTab1 = NULL;
}

void CFilterSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_LC_ITEM, m_wndLc);
	
}

BEGIN_MESSAGE_MAP(CFilterSimDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MAIN_BTN_ADDITEM, &CFilterSimDlg::OnBnClickedBtnAddList)
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
	GetDlgItem(IDC_MAIN_BTN_ADDITEM)->MoveWindow( 950, 450, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_DELITEM)->MoveWindow(1050, 450, 100,  50);
	GetDlgItem(IDC_MAIN_BTN_EXECUTE)->MoveWindow(1245, 450, 100,  50);
											   	    	 
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

	GetDlgItem(IDC_MAIN_LB_LIB  )->MoveWindow( 950,  93,  45,  15);
	GetDlgItem(IDC_MAIN_CB_LIB  )->MoveWindow(1000,  90, 100,  20);
	GetDlgItem(IDC_MAIN_PC_TAB1 )->MoveWindow( 950, 115, 395, 335);
	GetDlgItem(IDC_MAIN_LC_ITEM )->MoveWindow( 950, 500, 395, 460);

	
	m_wndLc.AddColumn(1, _T("No.")		,  30);
	m_wndLc.AddColumn(2, _T("Use")		,  30);
	m_wndLc.AddColumn(3, _T("Algorithm"),  90);
	m_wndLc.AddColumn(4, _T("Input")	,  90);
	m_wndLc.AddColumn(5, _T("Output")	,  90);
	m_wndLc.AddColumn(6, _T("Time")		,  60);
	m_wndLc.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_LIB);
	pCB->AddString(_T("EasyImage"));
	pCB->AddString(_T("EasyMatrixCode"));

	CCreateContext context;
	ZeroMemory(&context, sizeof(context));
	CView* pView = NULL;
	CRect rect=CRect(0,0,0,0);

	//----- Create Form Window -----//
	pView = (CView*)RUNTIME_CLASS(CFormTab1)->CreateObject();
	GetDlgItem(IDC_MAIN_PC_TAB1)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	pView->Create(NULL, NULL, WS_CHILD, rect, this, IDD_FORM_TAB1, &context);
	pView->OnInitialUpdate();
	m_pFormTab1 = pView;

	m_pFormTab1->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MAIN_PC_TAB1)->DestroyWindow();
}

void CFilterSimDlg::OnBnClickedBtnAddList()
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
	info.strInput = _T("");
	info.strOutput = _T("");

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

			UpdateCBList();
			
			m_nImgCnt++;
		}
	}
}

void CFilterSimDlg::OnBnClickedBtnExecute()
{
	int n = m_wndLc.GetItemCount();

	for (int i=0; i<n; i++)
	{
		CString use		= m_wndLc.GetItemText(i,2);
		if (use == _T("F"))
			continue;

		CString filter	= m_wndLc.GetItemText(i,3);
		CString imgIn	= m_wndLc.GetItemText(i,4);
		CString imgOut	= m_wndLc.GetItemText(i,5);

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

	std::vector<CImgInfo>::iterator it;
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

void CFilterSimDlg::OnBnClickedBtnNewImg()
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

	CFormTab1* pTab1 = (CFormTab1*)m_pFormTab1;
	pTab1->UpdateCBList(m_vImgInfo);
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
		nRow++;
	}
}

void CFilterSimDlg::UpdateItem(int nRow, BOOL bUse, CString strAlgorithm, CString strIn, CString strOut)
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
	m_wndLc.SetItemText(nRow, 4, strIn);
	m_wndLc.SetItemText(nRow, 5, strOut);

	int nCnt=0;
	for (std::vector<StItemInfo>::iterator it = m_vItmInfo.begin(); it != m_vItmInfo.end(); it++)
	{
		if (nCnt == nRow)
		{
			it->bUse = bUse;
			it->strType = strAlgorithm;
			it->strInput = strIn;
			it->strOutput = strOut;
		}
		
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

void CFilterSimDlg::OnNMClickMainLcItem(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	POSITION pos = NULL;
	int nRow = -1;

	pos = m_wndLc.GetFirstSelectedItemPosition();

	if( NULL != pos )
		nRow = m_wndLc.GetNextSelectedItem(pos);

	CString strLib = m_wndLc.GetItemText(nRow, 3);
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_LIB);
	if (strLib == _T("EasyMatrixCode"))
	{
		int sel = pCB->FindString(0,strLib);
		pCB->SetCurSel(sel);
	}
	else if (strLib == _T(""))
	{
		m_pFormTab1->ShowWindow(SW_HIDE);
		pCB->SetCurSel(-1);
	}
	else
	{
		pCB->SetCurSel(0);
		
		m_pFormTab1->ShowWindow(SW_SHOW);
		CFormTab1* pTab1 = (CFormTab1*)m_pFormTab1;
		pTab1->SetSelectedRow(nRow);

		pTab1->UpdateControls(m_vItmInfo.at(nRow));
	}

	*pResult = 0;
}


void CFilterSimDlg::OnCbnSelchangeMainCbLib()
{
	CComboBox* pCB = (CComboBox*)GetDlgItem(IDC_MAIN_CB_LIB);
	int sel = pCB->GetCurSel();

	POSITION pos = NULL;
	int nRow = -1;

	pos = m_wndLc.GetFirstSelectedItemPosition();

	if( NULL != pos )
		nRow = m_wndLc.GetNextSelectedItem(pos);

	switch (sel)
	{
	case 0 :
		{
			m_pFormTab1->ShowWindow(SW_SHOW);
			CFormTab1* pTab1 = (CFormTab1*)m_pFormTab1;
			pTab1->SetSelectedRow(nRow);
			pTab1->ResetControls();
		}
		
		break;
	case 1 :
		m_pFormTab1->ShowWindow(SW_HIDE);
		break;
	}
}
