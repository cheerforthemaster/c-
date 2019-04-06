
// Practice10Dlg.h : header file
//

#pragma once


// CPractice10Dlg dialog
class CPractice10Dlg : public CDialogEx
{
// Construction
public:
	CPractice10Dlg(CWnd* pParent = NULL);	// standard constructor
	double a[40];
	char b[20];
	void GetCString(CString str);
	char *blank = "";
	char *add = "+";
	char *div = "/";
	char *sub = "-";
	char *mul = "*";
	char *point = ".";
	int w = 0;
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE10_DIALOG };
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	CString m_strReasult;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton13();
};
