// Add_transfer_record.cpp : implementation file
//

#include "stdafx.h"
#include "CurriculumDesign6.h"
#include "Add_transfer_record.h"
#include "afxdialogex.h"
#include "CBC.h"
#include "CCash.h"
#include "CICBC.h"


// Add_transfer_record dialog

IMPLEMENT_DYNAMIC(Add_transfer_record, CDialogEx)

Add_transfer_record::Add_transfer_record(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, transfer(0)
	, transfer_remarks(_T(""))
	, source_transfer(_T(""))
	, aim_transfer(_T(""))
{

}

Add_transfer_record::~Add_transfer_record()
{
}

void Add_transfer_record::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, transfer);
	DDX_Text(pDX, IDC_EDIT2, transfer_remarks);
	DDX_CBString(pDX, IDC_COMBO1, source_transfer);
	DDX_CBString(pDX, IDC_COMBO2, aim_transfer);
}


BEGIN_MESSAGE_MAP(Add_transfer_record, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add_transfer_record::OnBnClickedOk)
END_MESSAGE_MAP()


// Add_transfer_record message handlers


void Add_transfer_record::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	UpdateData(TRUE);
	CString source("转账");
	if (source_transfer == "中国银行")
	{
		CBC income1;
		income1.Consume(source, transfer, transfer_remarks);
	}
	else if (source_transfer == "工商银行")
	{
		CICBC income2;
		income2.Consume(source, transfer, transfer_remarks);
	}
	else if (source_transfer == "现金账户")
	{
		CCash income3;
		income3.Consume(source, transfer, transfer_remarks);
	}
	///////////
	if (aim_transfer == "中国银行")
	{
		CBC income1;
		income1.Income(source, transfer, transfer_remarks);
	}
	else if (source_transfer == "工商银行")
	{
		CICBC income2;
		income2.Income(source, transfer, transfer_remarks);
	}
	else if (source_transfer == "现金账户")
	{
		CCash income3;
		income3.Income(source, transfer, transfer_remarks);
	}

	transfer = 0;
	transfer_remarks = "";
	UpdateData(FALSE);

}
