#pragma once


// MAIN dialog

class MAIN : public CDialogEx
{
	DECLARE_DYNAMIC(MAIN)

public:
	MAIN(CWnd* pParent = NULL);   // standard constructor
	virtual ~MAIN();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
