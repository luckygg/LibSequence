//----------------------------------------------------------
// FolderEx Class
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------
// Last Update : 2016-11-17 09:24
// Modified by William Kim
//----------------------------------------------------------

#pragma once

class CFolderEx
{
public :
	static BOOL 	ExistsDir(CString Path);									// ��� ���� ���� Ȯ��.
	static void 	CreateDir(CString Path) { CreateDirectory(Path,NULL); }		// ���� ����.
	static BOOL 	RemoveDir(CString Path) { return RemoveDirectory(Path); }	// ���� ����. (���� �Ǵ� ������ �����ϸ� ���� �� ��.)
	static BOOL 	RemoveDirAll(CString Path);									// ���� �������� ����.
	static BOOL 	RemoveFile(CString Path) { return DeleteFile(Path); }		// ���� ����.
	static void 	ClearDir(CString Path);										// ��γ��� ���� ����.
	static CString	GetExeDir();												// ���� �������� ��� Ȯ��.
};

