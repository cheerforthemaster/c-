#pragma once


// BankofChinaaccount dialog

class BankofChinaaccount : public CDialogEx
{
	DECLARE_DYNAMIC(BankofChinaaccount)

public:
	BankofChinaaccount(CWnd* pParent = NULL);   // standard constructor
	virtual ~BankofChinaaccount();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString bankofChinaaccount;
	afx_msg void OnBnClickedOk();
};
