// FileOperDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileOperDemo.h"
#include "FileOperDemoDlg.h"

#include "FileOperOBJ.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileOperDemoDlg dialog

CFileOperDemoDlg::CFileOperDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileOperDemoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileOperDemoDlg)
	m_InputFileName = _T("");
	m_OutputFileName = _T("");
	m_SortMethod = 0;
	m_IsDescend = TRUE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileOperDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileOperDemoDlg)
	DDX_Text(pDX, IDC_EDIT1, m_InputFileName);
	DDX_Text(pDX, IDC_EDIT2, m_OutputFileName);
	DDX_Radio(pDX, IDC_RADIO1, m_SortMethod);
	DDX_Check(pDX, IDC_CHECK1, m_IsDescend);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileOperDemoDlg, CDialog)
	//{{AFX_MSG_MAP(CFileOperDemoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnSelectInputFileName)
	ON_BN_CLICKED(IDC_BUTTON2, OnSelectOutputFileName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileOperDemoDlg message handlers

BOOL CFileOperDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CFileOperDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFileOperDemoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFileOperDemoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//输入文件名.
void CFileOperDemoDlg::OnSelectInputFileName() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	
	char szFilter[]="输入文件(*.txt;*.dat)|*.txt;*.dat|";
	CFileDialog	dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY|OFN_FILEMUSTEXIST,szFilter);
	
	if(dlg.DoModal()!=IDOK)
		m_InputFileName=_T("");
	else
		m_InputFileName=dlg.GetPathName();

	UpdateData(FALSE);
}

//输出文件名.
void CFileOperDemoDlg::OnSelectOutputFileName() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	char szFilter[]="结果文件(*.txt)|*.txt|";
	CFileDialog	dlg(FALSE, "txt", NULL, OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);

	if(dlg.DoModal()!=IDOK)
		m_OutputFileName=_T("");
	else
		m_OutputFileName=dlg.GetPathName();

	UpdateData(FALSE);
}

void CFileOperDemoDlg::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData(TRUE);

	if(m_InputFileName.IsEmpty() || m_OutputFileName.IsEmpty())
	{
		AfxMessageBox("请选择输入/输出文件!");
		return;
	}

	CFileOperOBJ FileOperObj;
	bool         bResult=false;

	//读入并解析文件.
	if(FileOperObj.ReadFileToArray((LPCTSTR)m_InputFileName))
	{
		//按照结构成员进行排序(1/2/3/4: 姓名/职称编号/工龄/年龄)
		if(FileOperObj.SortArrayByMemberNo((short)m_SortMethod, (m_IsDescend==1)))
		{
			//将排序结果写入文件.
			bResult=FileOperObj.WriteArrayToFile((LPCTSTR)m_OutputFileName);
		}
	}

    bResult ? AfxMessageBox("处理成功!") : AfxMessageBox("失败提示!");
	
	CDialog::OnOK();
}
