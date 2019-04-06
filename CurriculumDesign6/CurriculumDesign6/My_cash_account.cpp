// My_cash_account.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "My_cash_account.h"
#include "afxdialogex.h"
#include "CCash.h"


// My_cash_account dialog

IMPLEMENT_DYNAMIC(My_cash_account, CDialogEx)

My_cash_account::My_cash_account(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, cash_account(_T(""))
{

}

My_cash_account::~My_cash_account()
{
}

void My_cash_account::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cash_account);
}


BEGIN_MESSAGE_MAP(My_cash_account, CDialogEx)
	ON_BN_CLICKED(IDOK, &My_cash_account::OnBnClickedOk)
END_MESSAGE_MAP()


// My_cash_account message handlers


void My_cash_account::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();

	UpdateData(TRUE);

	CCash display3;
	display3.Statistic(cash_account);

	UpdateData(FALSE);

}
