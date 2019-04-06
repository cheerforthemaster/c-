#ifndef STUDENT
#define STUDENT
#include "person.h"
#include <iostream>
using namespace std;

class student:public virtual person
{
public:
	student():person()
	{
		cout << "student" << endl;
	}
	void get()
	{
		cout << "please input major(it's a number),years(>3 years and <6 years):" << endl;
		cin >> major >> years;
		if (major>=1000 || major < 0)
		{
			cout << "please input right major number";
			cin >> major;
		}
		if (years < 3 || years >6)
		{
			cout << "please input right years" << endl;
			cin >> years;
		}
	}
	void caltuition()
	{

		int sum;
		if (major >=100)
			sum = 8000 * years;
		else
			if (major >=10)
				sum = 6000 * years;
			else
				sum = 5000 * years;
		cout << "sum is " << sum << endl;
	}
	~student()
	{
		cout << "~student" << endl;
	}
protected:
	unsigned int long major;
	int years;
};
#endif