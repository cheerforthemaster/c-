
// a_MFC_experimentDlg.h : header file
//

#pragma once

// Ca_MFC_experimentDlg dialog
class Ca_MFC_experimentDlg : public CDialogEx
{
// Construction
public:
	Ca_MFC_experimentDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_A_MFC_EXPERIMENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString experiment_value;
	afx_msg void OnBnClickedOk();
	//CString experiment_value123;
};
