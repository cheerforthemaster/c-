#pragma once


// Monthly_income_statement dialog

class Monthly_income_statement : public CDialogEx
{
	DECLARE_DYNAMIC(Monthly_income_statement)

public:
	Monthly_income_statement(CWnd* pParent = NULL);   // standard constructor
	virtual ~Monthly_income_statement();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString monthly_value;
};
