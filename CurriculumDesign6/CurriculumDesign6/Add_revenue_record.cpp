// Add_revenue_record.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "Add_revenue_record.h"
#include "afxdialogex.h"
#include "CBC.h"
#include "CICBC.h"
#include "CCash.h"

// Add_revenue_record dialog

IMPLEMENT_DYNAMIC(Add_revenue_record, CDialogEx)

Add_revenue_record::Add_revenue_record(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, income(0)
	, income_remarks(_T(""))
	, income_type(_T(""))
	, income_account(_T(""))
{

}

Add_revenue_record::~Add_revenue_record()
{
}

void Add_revenue_record::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, income);
	DDX_Text(pDX, IDC_EDIT2, income_remarks);
	DDX_CBString(pDX, IDC_COMBO2, income_type);
	DDX_CBString(pDX, IDC_COMBO1, income_account);
}


BEGIN_MESSAGE_MAP(Add_revenue_record, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add_revenue_record::OnBnClickedOk)
END_MESSAGE_MAP()


// Add_revenue_record message handlers


void Add_revenue_record::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	if (income_account == "中国银行")
	{
		CBC income1;
		income1.Income(income_type, income, income_remarks);
	}
	else if (income_account == "工商银行")
	{
		CICBC income2;
		income2.Income(income_type, income, income_remarks);
	}
	else if (income_account == "现金账户")
	{
		CCash income3;
		income3.Income(income_type, income, income_remarks);
	}
	income = 0;
	income_remarks = "";
	UpdateData(FALSE);
}
