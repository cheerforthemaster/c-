#pragma once


// Icbcaccount dialog

class Icbcaccount : public CDialogEx
{
	DECLARE_DYNAMIC(Icbcaccount)

public:
	Icbcaccount(CWnd* pParent = NULL);   // standard constructor
	virtual ~Icbcaccount();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString Icbc_account;
	afx_msg void OnBnClickedOk();
};
