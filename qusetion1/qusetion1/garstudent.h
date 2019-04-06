#ifndef GRASTUDENT
#define GRASTUDENT
#include <string>
#include "student.h"
#include <iostream>
using namespace std;

class garstudent:public virtual student
{
public:
	garstudent() :student()
	{
		cout << "garstudent" << endl;
	}
	void setmyteacher()
	{
		cout << "please input myteacher:" << endl;
		cin >> myteacher;
	}
	void getmyteacher()
	{
		cout << "myteacher is " << myteacher << endl;
	}

	void caltuition()
	{
		int sum;
		if (major % 100 >= 1)
			sum = 10000 * years;
		else
			if (major % 10 >= 1)
				sum = 8000 * years;
			else
				sum = 6000 * years;
		cout << sum << endl;
	}
	~garstudent()
	{
		cout << "~garstudent" << endl;
	}
private:
	string myteacher;
};
#endif