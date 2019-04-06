
// CurriculumDesign5.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCurriculumDesign5App:
// See CurriculumDesign5.cpp for the implementation of this class
//

class CCurriculumDesign5App : public CWinApp
{
public:
	CCurriculumDesign5App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCurriculumDesign5App theApp;