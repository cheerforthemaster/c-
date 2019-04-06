#ifndef PERSON
#define PERSON
#include <iostream>
#include<string>
using namespace std ;

class person
{
public:
	person()
	{
		cout << "person" << endl;
	}
	void GetInfo()
	{
		cout << "please input name , sex ,old" << endl;
		cin >> name;
		cin >> sex;
		cin >> old;
	}
	void SetIfo()
	{
		cout << "name:" << name << "  sex:" << sex << "  old:" << old << endl;
	}
	~person() 
	{
		cout << "~person" << endl;
	}
private:
	string name;
	string sex; 
	int old;
};
#endif