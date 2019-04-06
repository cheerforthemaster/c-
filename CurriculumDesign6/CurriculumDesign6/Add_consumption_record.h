#pragma once


// Add_consumption_record dialog

class Add_consumption_record : public CDialogEx
{
	DECLARE_DYNAMIC(Add_consumption_record)

public:
	Add_consumption_record(CWnd* pParent = NULL);   // standard constructor
	virtual ~Add_consumption_record();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double consumption;
	CString consumption_remarks;
	CString consumption_type;
	CString consumption_account;
	afx_msg void OnBnClickedOk();
};
