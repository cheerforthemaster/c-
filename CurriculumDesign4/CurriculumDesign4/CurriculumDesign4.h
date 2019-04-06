
// CurriculumDesign4.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCurriculumDesign4App:
// See CurriculumDesign4.cpp for the implementation of this class
//

class CCurriculumDesign4App : public CWinApp
{
public:
	CCurriculumDesign4App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCurriculumDesign4App theApp;