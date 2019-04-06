#include "garstudent.h"
#include "teacher.h"
#include<iostream>
using namespace std;

class parttime:public virtual teacher ,public virtual garstudent 
{
public:
	parttime():garstudent(),teacher()
	{
		cout << "parttime" << endl;
	}
	void setwage()
	{
		cout << "please input wage" << endl;
		cin >> wage;
	}
	void getwage()
	{
		cout << "wage is " << wage << endl;
	}
	~parttime()
	{
		cout << "~parttime" << endl;
	}
private:
	int wage;
};
