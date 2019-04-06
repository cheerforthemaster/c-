
// CurriculumDesign4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign4.h"
#include "CurriculumDesign4Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//
//class base;
//class cube;
//class ball;
//class cylinder;
//
class base
{
public:
	virtual double area() = 0;
	virtual double volume() = 0;
};

class cube :public base
{
public:
	cube(double a)
	{
		length = a;
	}
	double area()
	{
		return 6 * length*length;
	}
	double volume()
	{
		return length*length*length;
	}

private:
	double length;

};

class ball :public base
{
public:
	ball(double a)
	{
		radius = a;
	}
	double area()
	{
		return 4 * 3.14*radius*radius;
	}
	double volume()
	{
		return 4 / 3 * 3.14*radius*radius*radius;
	}

private:
	double radius;
};

class cylinder :public base
{
public:
	cylinder(double a, double b)
	{
		high = a;
		b_radius = b;
	}
	double area()
	{
		return 2 * 3.14*b_radius*b_radius + 2 * 3.14*b_radius*high;
	}
	double volume()
	{
		return 3.14*b_radius*b_radius*high;
	}
private:
	double b_radius, high;
};

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


// CCurriculumDesign4Dlg dialog



CCurriculumDesign4Dlg::CCurriculumDesign4Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CURRICULUMDESIGN4_DIALOG, pParent)
	, ZV1(0)
	, BS1(0)
	, BS2(0)
	, QV2(0)
	, BS3(0)
	, YV3(0)
	, length(0)
	, radius(0)
	, high(0)
	, b_radius(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCurriculumDesign4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT11, ZV1);
	DDX_Text(pDX, IDC_EDIT2, BS1);
	DDX_Text(pDX, IDC_EDIT5, BS2);
	DDX_Text(pDX, IDC_EDIT6, QV2);
	DDX_Text(pDX, IDC_EDIT8, BS3);
	DDX_Text(pDX, IDC_EDIT9, YV3);
	DDX_Text(pDX, IDC_EDIT1, length);
	DDX_Text(pDX, IDC_EDIT4, radius);
	DDX_Text(pDX, IDC_EDIT7, high);
	DDX_Text(pDX, IDC_EDIT10, b_radius);
}

BEGIN_MESSAGE_MAP(CCurriculumDesign4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CCurriculumDesign4Dlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT5, &CCurriculumDesign4Dlg::OnEnChangeEdit5)
	ON_BN_CLICKED(IDC_BUTTON1, &CCurriculumDesign4Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT8, &CCurriculumDesign4Dlg::OnEnChangeEdit8)
	ON_EN_CHANGE(IDC_EDIT11, &CCurriculumDesign4Dlg::OnEnChangeEdit11)
	ON_EN_CHANGE(IDC_EDIT1, &CCurriculumDesign4Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCurriculumDesign4Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CCurriculumDesign4Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CCurriculumDesign4Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CCurriculumDesign4Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CCurriculumDesign4Dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CCurriculumDesign4Dlg message handlers

BOOL CCurriculumDesign4Dlg::OnInitDialog()
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

void CCurriculumDesign4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCurriculumDesign4Dlg::OnPaint()
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
HCURSOR CCurriculumDesign4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCurriculumDesign4Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CCurriculumDesign4Dlg::OnEnChangeEdit5()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CCurriculumDesign4Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	cube cu(length);
	BS1 = cu.area();
	ZV1 = cu.volume();
	UpdateData(FALSE);
}


void CCurriculumDesign4Dlg::OnEnChangeEdit8()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.


	// TODO:  Add your control notification handler code here
}





void CCurriculumDesign4Dlg::OnEnChangeEdit11()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData (TRUE);


	UpdateData (FALSE);
	// TODO:  Add your control notification handler code here
}


void CCurriculumDesign4Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.


	// TODO:  Add your control notification handler code here
}



void CCurriculumDesign4Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	length = 0;
	BS1 = 0;
	ZV1 = 0;
	UpdateData(FALSE);

}


void CCurriculumDesign4Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	BS2 = 0;
	QV2 = 0;
	UpdateData(FALSE);

}


void CCurriculumDesign4Dlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	BS3 = 0;
	YV3 = 0;
	UpdateData(FALSE);

}


void CCurriculumDesign4Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	ball ba(radius);
	BS2 = ba.area();
	QV2 = ba.volume();
	UpdateData(FALSE);
}


void CCurriculumDesign4Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	UpdateData (TRUE);
	cylinder cy(high, b_radius);
	BS3 = cy.area();
	YV3 = cy.volume();
	UpdateData (FALSE);

}


