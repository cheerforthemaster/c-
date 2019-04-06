
// Practice10.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPractice10App:
// See Practice10.cpp for the implementation of this class
//

class CPractice10App : public CWinApp
{
public:
	CPractice10App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPractice10App theApp;