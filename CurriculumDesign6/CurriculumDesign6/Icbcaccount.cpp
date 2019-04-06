// Icbcaccount.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "Icbcaccount.h"
#include "afxdialogex.h"
#include "CICBC.h"



// Icbcaccount dialog

IMPLEMENT_DYNAMIC(Icbcaccount, CDialogEx)

Icbcaccount::Icbcaccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, Icbc_account(_T(""))
{

}

Icbcaccount::~Icbcaccount()
{
}

void Icbcaccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Icbc_account);
}


BEGIN_MESSAGE_MAP(Icbcaccount, CDialogEx)
	ON_BN_CLICKED(IDOK, &Icbcaccount::OnBnClickedOk)
END_MESSAGE_MAP()


// Icbcaccount message handlers


void Icbcaccount::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData(TRUE);

	CICBC display1;
	display1.Statistic(Icbc_account);

	UpdateData(FALSE);

}
