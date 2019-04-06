
// CurriculumDesign5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign5.h"
#include "CurriculumDesign5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCurriculumDesign5Dlg dialog



CCurriculumDesign5Dlg::CCurriculumDesign5Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CURRICULUMDESIGN5_DIALOG, pParent)
	, x1(0)
	, y1(0)
	, x2(0)
	, y2(0)
	, result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCurriculumDesign5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, y1);
	DDX_Text(pDX, IDC_EDIT3, x2);
	DDX_Text(pDX, IDC_EDIT4, y2);
	DDX_Text(pDX, IDC_EDIT5, result);
}

BEGIN_MESSAGE_MAP(CCurriculumDesign5Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CCurriculumDesign5Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CCurriculumDesign5Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CCurriculumDesign5Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCurriculumDesign5Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCurriculumDesign5Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT3, &CCurriculumDesign5Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCurriculumDesign5Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCurriculumDesign5Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CCurriculumDesign5Dlg message handlers

BOOL CCurriculumDesign5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCurriculumDesign5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCurriculumDesign5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCurriculumDesign5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCurriculumDesign5Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CCurriculumDesign5Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void CCurriculumDesign5Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData (TRUE);
	if (x1 == x2&&y1 == y2)
		result = "相等";
	else
		result = "不相等";
	UpdateData(FALSE);
}


void CCurriculumDesign5Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CString str1, str2, str3, str4;

	x1 = -x1;
	y1 = -y1;
	x2 = -x2;
	y2 = -y2;

	str1.Format(_T("%f"),x1);
	str2.Format(_T("%f"), y1);
	str3.Format(_T("%f"), x2);
	str4.Format(_T("%f"), y2);

	result ="(";
	result += str1;
	result += ",";
	result += str2;
	result += ")";
	result += "   ";
	result += "(";
	result += str3;
	result += ",";
	result += str4;
	result += ")";


	UpdateData(FALSE);


}


void CCurriculumDesign5Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CString str1, str2;
	double a, b;

	a = x1 - x2;
	b = y1 - y2;

	str1.Format(_T("%f"), a);
	str2.Format(_T("%f"), b);

	result = "(";
	result += str1;
	result += ",";
	result += str2;
	result += ")";

	UpdateData(FALSE);

}


void CCurriculumDesign5Dlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCurriculumDesign5Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	CString str1, str2;
	double a, b;

	a = x1 + x2;
	b = y1 + y2;

	str1.Format(_T("%f"), a);
	str2.Format(_T("%f"), b);

	result = "(";
	result += str1;
	result += ",";
	result += str2;
	result += ")";

	UpdateData(FALSE);

}


void CCurriculumDesign5Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE);

	CString str1;
	double a;

	a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	result.Format(_T("%f"), a);

	UpdateData(FALSE);

}
