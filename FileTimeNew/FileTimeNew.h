// FileTimeNew.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFileTimeNewApp:
// �йش����ʵ�֣������ FileTimeNew.cpp
//

class CFileTimeNewApp : public CWinApp
{
public:
	CFileTimeNewApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFileTimeNewApp theApp;