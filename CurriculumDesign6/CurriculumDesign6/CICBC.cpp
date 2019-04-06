#include "CICBC.h"
//#include "stdafx.h"

long CICBC::Transfer(CMyAccount *ptSourceA, CMyAccount *ptDestA, double sum, CString ptNote)
{
	ptSourceA->Consume("ת��", sum, ptNote);
	ptDestA->Income("ת��", sum, ptNote);
	return 0;
}

long CICBC::Income(CString inType, double sum, CString ptNote)
{
	fstream mycbc;
	mycbc.open("CICBC.txt");
	balance += sum;
	mycbc.seekg(0, ios::end);//��ָ������ļ����
	mycbc << "���룺 " << GetTime().GetBuffer() << "  �������ͣ�" << inType << "  �����" << sum << "  ��ע:" << ptNote << "  ��" << balance << endl;
	mycbc.close();
	return 0;
}

long CICBC::Consume(CString conType, double sum, CString ptNote)
{
	fstream mycbc;
	mycbc.open("CICBC.txt");
	balance -= sum;
	mycbc.seekg(0, ios::end);//��ָ������ļ����
	mycbc << "֧���� " << GetTime().GetBuffer() << "  ֧�����ͣ�" << conType << "  ֧����" << sum << "  ��ע��" << ptNote << "  ��" << balance << endl;
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
		mycbc.read(asf, a + 1);//���ĵ���Ķ��������string asdf��
		string asdf(asf);
		string asd = "��";
		int a;
		a = asdf.find_last_of(asd, asdf.size());//��asdf��������ҳ�asd����������λ��
		tem = asdf.substr(a + 1, asdf.size());//���������ֵ��string���ŵ�tem��
		balance = atof(tem.c_str());//��stringת��Ϊdouble
		delete[]asf;
	}
	mycbc.close();

}