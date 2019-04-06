#pragma once


// Add_revenue_record dialog

class Add_revenue_record : public CDialogEx
{
	DECLARE_DYNAMIC(Add_revenue_record)

public:
	Add_revenue_record(CWnd* pParent = NULL);   // standard constructor
	virtual ~Add_revenue_record();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double income;
	CString income_remarks;
	CString income_type;
	CString income_account;
	afx_msg void OnBnClickedOk();
};
