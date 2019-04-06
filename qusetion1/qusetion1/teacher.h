#ifndef TEACHER
#define TEACHER

#include "person.h"
#include <string>
#include <iostream>
using namespace std;

class teacher:virtual public person
{
public:
	teacher():person()
	{
		cout << "teacher" << endl;
	}

	void SetTitle()
	{
		cout << "please set title:" << endl;
		cin >> title;
	}
	void GetTitle()
	{
		cout <<"title is "<< title << endl;
	}
	~teacher()
	{
		cout << "~teacher" << endl;
	}
private:
	string title;
};
#endif