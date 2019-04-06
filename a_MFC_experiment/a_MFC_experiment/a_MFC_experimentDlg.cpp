
// a_MFC_experimentDlg.cpp : implementation file
//
#include "stdafx.h"
#include "a_MFC_experiment.h"
#include "a_MFC_experimentDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
using namespace std;

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


// Ca_MFC_experimentDlg dialog



Ca_MFC_experimentDlg::Ca_MFC_experimentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_A_MFC_EXPERIMENT_DIALOG, pParent)
	, experiment_value(_T(""))
	//, experiment_value123(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ca_MFC_experimentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, experiment_value);
	//DDX_LBString(pDX, IDC_LIST1, experiment_value123);
}

BEGIN_MESSAGE_MAP(Ca_MFC_experimentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Ca_MFC_experimentDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Ca_MFC_experimentDlg message handlers

BOOL Ca_MFC_experimentDlg::OnInitDialog()
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

void Ca_MFC_experimentDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Ca_MFC_experimentDlg::OnPaint()
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
HCURSOR Ca_MFC_experimentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ca_MFC_experimentDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	//UpdateData(TRUE);
	//CString bank;
	//fstream mycbc;
	//mycbc.open("a.txt");
	//mycbc.seekg(0, ios::end);
	//int tem = mycbc.tellg();
	//mycbc.seekg(0, ios::beg);
	//char *temporary = new char[tem];
	//mycbc.read(temporary, tem);
	//bank.Format(_T("%s"), temporary);
	//bank.Replace("\n", "\r\n");
	//experiment_value = bank;
	//CString bank;
	//string asdf;
	//const char* tem = "123\r\n123";
	//fstream mycbc;
	//mycbc.open("a.txt");
	//mycbc.seekp(0, ios::end);
	//unsigned int a = mycbc.tellg();
	//char *b = new char[a+1];
	////mycbc.read(b, a);
	//mycbc.close();
	//mycbc.open("a.txt");

	//mycbc >> asdf;
	//bank.Format(_T("%s"), b);
	//delete[]b;
	//mycbc.close();
	//experiment_value.Format(_T("%s"), tem);
	experiment_value = "asdf\r\n123";
	UpdateData(FALSE);

}
