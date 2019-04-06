
// CurriculumDesign5Dlg.h : header file
//

#pragma once


// CCurriculumDesign5Dlg dialog
class CCurriculumDesign5Dlg : public CDialogEx
{
// Construction
public:
	CCurriculumDesign5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURRICULUMDESIGN5_DIALOG };
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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	double x1;
	double y1;
	afx_msg void OnEnChangeEdit3();
	double x2;
	double y2;
	CString result;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
