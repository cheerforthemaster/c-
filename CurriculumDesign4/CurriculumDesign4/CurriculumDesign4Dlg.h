
// CurriculumDesign4Dlg.h : header file
//

#pragma once


// CCurriculumDesign4Dlg dialog
class CCurriculumDesign4Dlg : public CDialogEx
{
// Construction
public:
	CCurriculumDesign4Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CURRICULUMDESIGN4_DIALOG };
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
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnEnChangeEdit11();
	double ZV1;
	double BS1;
	double BS2;
	double QV2;
	double BS3;
	double YV3;
	afx_msg void OnEnChangeEdit1();
	double length;
	double radius;
	double high;
	double b_radius;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
};
