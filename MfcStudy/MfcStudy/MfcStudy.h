
// MfcStudy.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMfcStudyApp:
// �йش����ʵ�֣������ MfcStudy.cpp
//

class CMfcStudyApp : public CWinApp
{
public:
	CMfcStudyApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMfcStudyApp theApp;