// FileOperDemoDlg.h : header file
//

#if !defined(AFX_FILEOPERDEMODLG_H__6B4796BF_C4AC_40B3_8D98_FB6CDC6663CA__INCLUDED_)
#define AFX_FILEOPERDEMODLG_H__6B4796BF_C4AC_40B3_8D98_FB6CDC6663CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileOperDemoDlg dialog

class CFileOperDemoDlg : public CDialog
{
// Construction
public:
	CFileOperDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileOperDemoDlg)
	enum { IDD = IDD_FILEOPERDEMO_DIALOG };
	CString	m_InputFileName;
	CString	m_OutputFileName;
	int		m_SortMethod;
	BOOL	m_IsDescend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileOperDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileOperDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelectInputFileName();
	afx_msg void OnSelectOutputFileName();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEOPERDEMODLG_H__6B4796BF_C4AC_40B3_8D98_FB6CDC6663CA__INCLUDED_)
