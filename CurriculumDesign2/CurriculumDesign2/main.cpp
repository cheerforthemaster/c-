#include <iostream>
#include "stdlib.h"
#include "CBook.h"
#include "CReader.h"
using namespace std;

int main()
{
	CBook b1("面向对象程序设计", 100, "郑莉"), b2("数据结构", 110, "严蔚敏");
	CReader r1("王华", 1234);
	r1.rentbook(b1);
	r1.rentbook(b2);
	r1.showreader();

	system("pause");
	return 0;
}