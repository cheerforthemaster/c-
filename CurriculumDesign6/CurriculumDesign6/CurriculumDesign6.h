
// CurriculumDesign6.h : main header file for the CurriculumDesign6 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCurriculumDesign6App:
// See CurriculumDesign6.cpp for the implementation of this class
//

class CCurriculumDesign6App : public CWinAppEx
{
public:
	CCurriculumDesign6App();


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

extern CCurriculumDesign6App theApp;
