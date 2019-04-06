
// Practice10Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Practice10.h"
#include "Practice10Dlg.h"
#include "afxdialogex.h"
#include <cmath>
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


// CPractice10Dlg dialog



CPractice10Dlg::CPractice10Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRACTICE10_DIALOG, pParent)
	, m_strReasult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPractice10Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strReasult);
}

BEGIN_MESSAGE_MAP(CPractice10Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPractice10Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPractice10Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &CPractice10Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CPractice10Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON7, &CPractice10Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &CPractice10Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CPractice10Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CPractice10Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CPractice10Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CPractice10Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CPractice10Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CPractice10Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON12, &CPractice10Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON11, &CPractice10Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON10, &CPractice10Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON16, &CPractice10Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CPractice10Dlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON15, &CPractice10Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &CPractice10Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &CPractice10Dlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CPractice10Dlg message handlers

BOOL CPractice10Dlg::OnInitDialog()
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

void CPractice10Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPractice10Dlg::OnPaint()
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
HCURSOR CPractice10Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice10Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
}


void CPractice10Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CPractice10Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "2";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
}


void CPractice10Dlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "7";
	UpdateData(FALSE);

}


void CPractice10Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);  
	m_strReasult += "1";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "3";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "4";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "5";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton6()
{
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "6";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "8";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "9";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(1);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(1);
	UpdateData(TRUE);
	m_strReasult += "0";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton11()
{
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);//按了符号后，禁用所用符号
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	if (m_strReasult != "")//如果之前没字符，则字符串依旧为空,且所有符号被禁用
		m_strReasult += ".";
	else
		m_strReasult = "";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton10()
{
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);//按了符号后，禁用 = . 两个符号
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);

	UpdateData(TRUE);
	//if (m_strReasult = "")//如果之前没字符，则字符串依旧为空,且所有符号被禁用
	//	m_strReasult = "";
	int f = m_strReasult.GetLength();
	GetCString(m_strReasult);
	for (int i = 0; i < w; i++)
	{
		if (b[i] == *add)
			a[i + 1] = a[i] + a[i + 1];
		if (b[i] == *sub)
			a[i + 1] = a[i] - a[i + 1];
		if (b[i] == *div)
			a[i + 1] = a[i] / a[i + 1];
		if (b[i] == *mul)
			a[i + 1] = a[i] * a[i + 1];
	}
	m_strReasult.Format(_T("%lf"), a[w], 10);
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton16()
{
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);//按了符号后，禁用所用符号
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	if (m_strReasult != "")//如果之前没字符，则字符串依旧为空,且所有符号被禁用
		m_strReasult += "/";
	else
		m_strReasult = "";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); //将对话框中的值传给控件变量   
	m_strReasult = "";
	UpdateData(FALSE);//将控件变量的值传给显示框
}


void CPractice10Dlg::OnBnClickedButton15()
{
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);//按了符号后，禁用所用符号
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	if (m_strReasult != "")//如果之前没字符，则字符串依旧为空,且所有符号被禁用
		m_strReasult += "*";
	else
		m_strReasult = "";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);//按了符号后，禁用所用符号
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	if (m_strReasult != "")//如果之前没字符，则字符串依旧为空,且所有符号被禁用
		m_strReasult += "-";
	else
		m_strReasult = "";
	UpdateData(FALSE);
}


void CPractice10Dlg::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);//按了符号后，禁用所用符号
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	if (m_strReasult != "")//如果之前没字符，则字符串依旧为空,且所有符号被禁用
		m_strReasult += "+";
	else
		m_strReasult = "";
	UpdateData(FALSE);
}


void CPractice10Dlg::GetCString(CString str)
{
	double rate = 10.0, itemp = 0.0;
	for (int i = 0; i < 40; i++)
		a[i] = 0;//初始化为0
	for (int i = 0; i < 20; i++)
		b[i] = *blank;//初始化为空;blank="";
	str.ReleaseBuffer();
	int f = str.GetLength();
	for (int i = 0; i < str.GetLength(); i++)
	{
		if (isdigit(str.GetAt(i)))
			if (rate == 10.0)
				itemp = itemp*rate + (str.GetAt(i) - '0');
			else
			{
				itemp = itemp + rate* (str.GetAt(i) - '0');
				rate = rate / 10;
			}
		else if (str.GetAt(i) == *point)
			rate = 0.1;
		else if (str.GetAt(i) == *add)
		{
			b[w] = *add;
			a[w] = itemp;
			w++;
			itemp = 0;
			rate = 10.0;
		}
		else if (str.GetAt(i) == *sub)
		{
			b[w] = *sub;
			a[w] = itemp;
			w++;
			itemp = 0;
			rate = 10.0;
		}
		else if (str.GetAt(i) == *div)
		{
			b[w] = *div;
			a[w] = itemp;
			w++;
			itemp = 0;
			rate = 10.0;
		}
		else if (str.GetAt(i) == *mul)
		{
			b[w] = *mul;
			a[w] = itemp;
			w++;
			itemp = 0;
			rate = 10.0;
		}
	}
	a[w] = itemp;//存最后一个数
}