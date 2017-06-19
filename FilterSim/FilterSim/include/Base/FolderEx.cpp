#include "StdAfx.h"
#include "FolderEx.h"

BOOL CFolderEx::ExistsDir(CString Path)
{
	if (GetFileAttributes(Path) == -1) return FALSE; // -1 is No Exist
	else return TRUE;
}

BOOL CFolderEx::RemoveDirAll(CString Path)
{
	if( Path == _T("") )  
	{  
		return FALSE;  
	}  

	BOOL bResult = FALSE; 
	int nRval = 0; 

	CString szNextDirPath   = _T(""); 
	CString szRoot = _T("");

	szRoot.Format(_T("%s\\*.*"), Path);

	CFileFind find; 

	bResult = find.FindFile( szRoot );

	if( bResult == FALSE )  
	{        
		return bResult;  
	}

	while( bResult )  
	{  
		bResult = find.FindNextFile();

		if( find.IsDots() == FALSE )   
		{   
			if( find.IsDirectory() )   
			{   
				RemoveDirAll(find.GetFilePath());   
			}   
			else   
			{    
				bResult = DeleteFile(find.GetFilePath()); 
			}  
		}
	} 
	find.Close();
	bResult = RemoveDirectory( Path );          
	return bResult;
}

void CFolderEx::ClearDir(CString Path)
{
	if( Path == _T("") )  
		return;  

	BOOL bResult = FALSE; 
	int nRval = 0; 

	CString szNextDirPath   = _T(""); 
	CString szRoot = _T("");

	szRoot.Format(_T("%s\\*.*"), Path);

	CFileFind find; 

	bResult = find.FindFile( szRoot );

	if( bResult == FALSE )  
		return ;  

	while( bResult )  
	{  
		bResult = find.FindNextFile();

		if( find.IsDots() == FALSE )   
		{   
			if( find.IsDirectory() )   
			{   
				ClearDir(find.GetFilePath());   
			}   
			else   
			{    
				bResult = DeleteFile(find.GetFilePath()); 
			}  
		}
	} 
	find.Close();
}

CString CFolderEx::GetExeDir()
{
	TCHAR pszPathName[_MAX_PATH];

	::GetModuleFileName(::AfxGetInstanceHandle(), pszPathName, _MAX_PATH); 

	CString strPathName = pszPathName;

	int i = strPathName.ReverseFind('\\');

	//Left(i+1)은 마지막의 '\'까지 포함할지 정함.
	strPathName = strPathName.Left(i+1);

	return strPathName;
}