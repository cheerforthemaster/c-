#include <iostream>
#include "stdlib.h"
#include "CBook.h"
#include "CReader.h"
using namespace std;

int main()
{
	CBook b1("�������������", 100, "֣��"), b2("���ݽṹ", 110, "��ε��");
	CReader r1("����", 1234);
	r1.rentbook(b1);
	r1.rentbook(b2);
	r1.showreader();

	system("pause");
	return 0;
}