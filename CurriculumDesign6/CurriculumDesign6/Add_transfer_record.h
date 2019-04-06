#pragma once


// Add_transfer_record dialog

class Add_transfer_record : public CDialogEx
{
	DECLARE_DYNAMIC(Add_transfer_record)

public:
	Add_transfer_record(CWnd* pParent = NULL);   // standard constructor
	virtual ~Add_transfer_record();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double transfer;
	CString transfer_remarks;
	afx_msg void OnBnClickedOk();
	CString source_transfer;
	CString aim_transfer;
};
