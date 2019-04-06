// BankofChinaaccount.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "BankofChinaaccount.h"
#include "afxdialogex.h"
#include "CBC.h"


// BankofChinaaccount dialog

IMPLEMENT_DYNAMIC(BankofChinaaccount, CDialogEx)

BankofChinaaccount::BankofChinaaccount(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, bankofChinaaccount(_T(""))
{

}

BankofChinaaccount::~BankofChinaaccount()
{
}

void BankofChinaaccount::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, bankofChinaaccount);
}


BEGIN_MESSAGE_MAP(BankofChinaaccount, CDialogEx)
	ON_BN_CLICKED(IDOK, &BankofChinaaccount::OnBnClickedOk)
END_MESSAGE_MAP()


// BankofChinaaccount message handlers


void BankofChinaaccount::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();

	UpdateData(TRUE);

	CBC display2;
	display2.Statistic(bankofChinaaccount);
	//bankofChinaaccount = "asdf";
	UpdateData(FALSE);


}
