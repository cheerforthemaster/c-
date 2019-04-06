#include <iostream>
using namespace std;
#ifndef CBASE
#define CBASE

class CBase
{
private:
	char name[20];
	int no;
public:
	CBase() {}
	CBase(char na[], int n)
	{
		strcpy_s(name, 20, na);
		no = n;
	}
	void show()
	{
		cout << name << "(" << no << ")" << endl;
	}

};
#endif
