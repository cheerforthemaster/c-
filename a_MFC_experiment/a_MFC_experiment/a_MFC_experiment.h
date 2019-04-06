
// a_MFC_experiment.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Ca_MFC_experimentApp:
// See a_MFC_experiment.cpp for the implementation of this class
//

class Ca_MFC_experimentApp : public CWinApp
{
public:
	Ca_MFC_experimentApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ca_MFC_experimentApp theApp;