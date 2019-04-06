#pragma once


// My_cash_account dialog

class My_cash_account : public CDialogEx
{
	DECLARE_DYNAMIC(My_cash_account)

public:
	My_cash_account(CWnd* pParent = NULL);   // standard constructor
	virtual ~My_cash_account();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString cash_account;
	afx_msg void OnBnClickedOk();
};
