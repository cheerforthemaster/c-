#pragma once
#include <afx.h>
#include <fstream>
#include <cstring>
#include "stdafx.h"
using namespace std;

class Decompose
{
public:
	Decompose();//��Result��ʼ��Ϊ��
	CString decom(CString &tem1, CString &tem2, CString &tem3);//��Դ�ļ��е��ַ����ֽ�
	~Decompose();//��Result delete
private:
	int Str_Num;
	int* Result;//�����Ľ��
};

