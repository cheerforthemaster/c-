// Add_consumption_record.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "Add_consumption_record.h"
#include "afxdialogex.h"
#include "CBC.h"
#include "CICBC.h"
#include "CCash.h"


// Add_consumption_record dialog

IMPLEMENT_DYNAMIC(Add_consumption_record, CDialogEx)

Add_consumption_record::Add_consumption_record(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, consumption(0)
	, consumption_remarks(_T(""))
	, consumption_type(_T(""))
	, consumption_account(_T(""))
{

}

Add_consumption_record::~Add_consumption_record()
{
}

void Add_consumption_record::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, consumption);
	DDX_Text(pDX, IDC_EDIT2, consumption_remarks);
	DDX_CBString(pDX, IDC_COMBO2, consumption_type);
	DDX_CBString(pDX, IDC_COMBO1, consumption_account);
}


BEGIN_MESSAGE_MAP(Add_consumption_record, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add_consumption_record::OnBnClickedOk)
END_MESSAGE_MAP()


// Add_consumption_record message handlers


void Add_consumption_record::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	if (consumption_account == "中国银行")
	{
		CBC income1;
		income1.Consume(consumption_type, consumption, consumption_remarks);
	}
	else if (consumption_account == "工商银行")
	{
		CICBC income2;
		income2.Consume(consumption_type, consumption, consumption_remarks);
	}
	else if (consumption_account == "现金账户")
	{
		CCash income3;
		income3.Consume(consumption_type, consumption, consumption_remarks);
	}
	consumption = 0;
	consumption_remarks = "";
	UpdateData(FALSE);
}


