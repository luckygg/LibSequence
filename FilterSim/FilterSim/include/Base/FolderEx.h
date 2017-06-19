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
	static BOOL 	ExistsDir(CString Path);									// 경로 존재 여부 확인.
	static void 	CreateDir(CString Path) { CreateDirectory(Path,NULL); }		// 폴더 생성.
	static BOOL 	RemoveDir(CString Path) { return RemoveDirectory(Path); }	// 폴더 삭제. (파일 또는 폴더가 존재하면 제거 안 됨.)
	static BOOL 	RemoveDirAll(CString Path);									// 하위 폴더까지 제거.
	static BOOL 	RemoveFile(CString Path) { return DeleteFile(Path); }		// 파일 제거.
	static void 	ClearDir(CString Path);										// 경로내의 파일 제거.
	static CString	GetExeDir();												// 현재 실행파일 경로 확인.
};

