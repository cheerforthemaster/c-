// THE_MAIN.cpp : implementation file
//

#include "stdafx.h"
#include "xialiangwei10.h"
#include "THE_MAIN.h"
#include "afxdialogex.h"
#include <fstream>

// THE_MAIN dialog

IMPLEMENT_DYNAMIC(THE_MAIN, CDialogEx)

THE_MAIN::THE_MAIN(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_strResult(_T(""))
{

}

THE_MAIN::~THE_MAIN()
{
}

void THE_MAIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_editFont);
	DDX_Text(pDX, IDC_EDIT1, m_strResult);
}


BEGIN_MESSAGE_MAP(THE_MAIN, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &THE_MAIN::OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, &THE_MAIN::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON6, &THE_MAIN::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &THE_MAIN::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON1, &THE_MAIN::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON11, &THE_MAIN::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &THE_MAIN::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON17, &THE_MAIN::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON2, &THE_MAIN::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &THE_MAIN::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &THE_MAIN::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &THE_MAIN::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &THE_MAIN::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &THE_MAIN::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &THE_MAIN::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON16, &THE_MAIN::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON15, &THE_MAIN::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON14, &THE_MAIN::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON13, &THE_MAIN::OnBnClickedButton13)
END_MESSAGE_MAP()


// THE_MAIN message handlers
void THE_MAIN::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

double a[20];
char b[10];
bool OperatorPressed = false;
bool Restarted = false;
void THE_MAIN::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
}


void THE_MAIN::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "6";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE); 
	m_strResult += "7";
	UpdateData(FALSE); 
}


void THE_MAIN::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "1";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton11()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	m_strResult += ".";
	UpdateData(FALSE);

}


void THE_MAIN::OnBnClickedButton12()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "0";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton17()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult = "";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "2";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "3";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "4";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "5";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "8";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_strResult += "9";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
}


void THE_MAIN::OnBnClickedButton16()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	m_strResult += "/";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton15()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	m_strResult += "*";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton14()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	m_strResult += "-";
	UpdateData(FALSE);
}


void THE_MAIN::OnBnClickedButton13()
{
	// TODO: Add your control notification handler code here
	GetDlgItem(IDC_BUTTON10)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON16)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(0);
	GetDlgItem(IDC_BUTTON13)->EnableWindow(0);
	UpdateData(TRUE);
	m_strResult += "+";
	UpdateData(FALSE);
}
