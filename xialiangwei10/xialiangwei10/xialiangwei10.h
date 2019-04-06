
// xialiangwei10.h : main header file for the xialiangwei10 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cxialiangwei10App:
// See xialiangwei10.cpp for the implementation of this class
//

class Cxialiangwei10App : public CWinAppEx
{
public:
	Cxialiangwei10App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cxialiangwei10App theApp;

