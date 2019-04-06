// FileOperDemo.h : main header file for the FILEOPERDEMO application
//

#if !defined(AFX_FILEOPERDEMO_H__CBCDF2F3_8B5C_4990_8810_926F9CF577BC__INCLUDED_)
#define AFX_FILEOPERDEMO_H__CBCDF2F3_8B5C_4990_8810_926F9CF577BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileOperDemoApp:
// See FileOperDemo.cpp for the implementation of this class
//

class CFileOperDemoApp : public CWinApp
{
public:
	CFileOperDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOperDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileOperDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPERDEMO_H__CBCDF2F3_8B5C_4990_8810_926F9CF577BC__INCLUDED_)
