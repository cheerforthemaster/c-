//#include "stdafx.h"
#include"CMyAccount.h"
using namespace std;

CString CMyAccount::GetTime()//��ȡ��ǰʱ��
{
	time_t a = time(0);
	tm b;
	localtime_s(&b, &a);
	CString str1, str2;
	str2.Format(_T("%d"), b.tm_year + 1900);
	str1 = str2;
	str1 += "��";
	str2.Format(_T("%d"), b.tm_mon + 1);
	str1 += str2;
	str1 += "��";
	str2.Format(_T("%d"), b.tm_mday);
	str1 += str2;
	str1 += "��";
	str2.Format(_T("%d"), b.tm_hour);
	str1 += str2;
	str1 += "ʱ";
	str2.Format(_T("%d"), b.tm_min + 1);
	str1 += str2;
	str1 += "��";
	str2.Format(_T("%d"), b.tm_sec);
	str1 += str2;
	str1 += "��";

	return str1;
}



