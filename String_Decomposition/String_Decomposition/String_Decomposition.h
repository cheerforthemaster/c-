
// String_Decomposition.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CString_DecompositionApp:
// See String_Decomposition.cpp for the implementation of this class
//

class CString_DecompositionApp : public CWinApp
{
public:
	CString_DecompositionApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CString_DecompositionApp theApp;