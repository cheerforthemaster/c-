#pragma once
#include <afx.h>
#include <fstream>
#include <cstring>
#include "stdafx.h"
using namespace std;

class Decompose
{
public:
	Decompose();//将Result初始化为空
	CString decom(CString &tem1, CString &tem2, CString &tem3);//将源文件中的字符串分解
	~Decompose();//将Result delete
private:
	int Str_Num;
	int* Result;//存最后的结果
};

