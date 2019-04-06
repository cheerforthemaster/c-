#include "CICBC.h"
//#include "stdafx.h"

long CICBC::Transfer(CMyAccount *ptSourceA, CMyAccount *ptDestA, double sum, CString ptNote)
{
	ptSourceA->Consume("转账", sum, ptNote);
	ptDestA->Income("转账", sum, ptNote);
	return 0;
}

long CICBC::Income(CString inType, double sum, CString ptNote)
{
	fstream mycbc;
	mycbc.open("CICBC.txt");
	balance += sum;
	mycbc.seekg(0, ios::end);//将指针调到文件最后
	mycbc << "收入： " << GetTime().GetBuffer() << "  收入类型：" << inType << "  收入金额：" << sum << "  备注:" << ptNote << "  余额：" << balance << endl;
	mycbc.close();
	return 0;
}

long CICBC::Consume(CString conType, double sum, CString ptNote)
{
	fstream mycbc;
	mycbc.open("CICBC.txt");
	balance -= sum;
	mycbc.seekg(0, ios::end);//将指针调到文件最后
	mycbc << "支出： " << GetTime().GetBuffer() << "  支出类型：" << conType << "  支出金额：" << sum << "  备注：" << ptNote << "  余额：" << balance << endl;
	mycbc.close();
	return 0;
}

long CICBC::Statistic(CString &bankofChinaaccount)
{
	fstream mycbc;
	mycbc.open("CICBC.txt");
	mycbc.seekg(0, ios::end);
	int tem = mycbc.tellg();
	mycbc.seekg(0, ios::beg);
	char *temporary = new char[tem + 1];
	for (int i = 0; i < tem + 1; i++)
		temporary[i] = '\0';
	mycbc.read(temporary, tem+1);
	bankofChinaaccount.Format(_T("%s"), temporary);
	bankofChinaaccount.Replace("\n","\r\n");
	delete[]temporary;
	return 0;
}

CICBC::CICBC()
{
	fstream mycbc;
	mycbc.open("CICBC.txt");
	mycbc.seekp(0, ios::end);
	int a = mycbc.tellp();
	if (a == 0)
	{
		balance = 0;
		mycbc.close();
	}
	else
	{
		mycbc.seekp(0, ios::beg);
		char* asf = new char[a + 1];
		string tem;
		mycbc.read(asf, a + 1);//将文档里的东西输出到string asdf中
		string asdf(asf);
		string asd = "余额：";
		int a;
		a = asdf.find_last_of(asd, asdf.size());//从asdf中最后面找出asd（余额：）所在位置
		tem = asdf.substr(a + 1, asdf.size());//将最后的余额值（string）放到tem中
		balance = atof(tem.c_str());//将string转化为double
		delete[]asf;
	}
	mycbc.close();

}