//----------------------------------------------------------
// FileDialogEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2016-11-17 10:02
// Modified by William Kim
//----------------------------------------------------------
#pragma once

class CFileDialogEx
{
public:
	CFileDialogEx(void);
	~CFileDialogEx(void);

	static bool GetPathOpenFileDlg(CString &strValue);
	static bool GetPathOpenFileDlg(CStringArray &arrValue);
	static bool GetPathSaveFileDlg(CString &strValue);
	static bool GetPathSelectFolder(CString &strValue);
	static void SetFileExtension(CString strExtension);
private :
	static CString m_strFileFilter;
};

