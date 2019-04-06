// Monthly_income_statement.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "Monthly_income_statement.h"
#include "afxdialogex.h"
#include "CBC.h"
#include "CCash.h"
#include "CICBC.h"

// Monthly_income_statement dialog

IMPLEMENT_DYNAMIC(Monthly_income_statement, CDialogEx)

Monthly_income_statement::Monthly_income_statement(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, monthly_value(_T(""))
{

}

Monthly_income_statement::~Monthly_income_statement()
{
}

void Monthly_income_statement::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, monthly_value);
}


BEGIN_MESSAGE_MAP(Monthly_income_statement, CDialogEx)
	ON_BN_CLICKED(IDOK, &Monthly_income_statement::OnBnClickedOk)
END_MESSAGE_MAP()


// Monthly_income_statement message handlers


void Monthly_income_statement::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	//monthly_value
	CString tempor1;
	monthly_value = "现金账户\r\n";
	CCash display3;
	display3.Statistic(tempor1);
	monthly_value = monthly_value + tempor1;

	monthly_value = monthly_value + "中国银行\r\n";
	CBC display2;
	display2.Statistic(tempor1);
	monthly_value = monthly_value + tempor1;

	monthly_value = monthly_value + "工商银行\r\n";
	CICBC display1;
	display1.Statistic(tempor1);
	monthly_value = monthly_value + tempor1;

	UpdateData(FALSE);

}
