//#include<iostream>
#ifndef POINT
#define POINT
#include"Geometry.cpp"
#define IN
using namespace std;

class Point :public Geometry
{
public:
	void SetX(IN double x)
	{
		X = x;
	}

	void SetY(IN double y)
	{
		Y = y;
	}

	double GetX()
	{
		//cout << X << endl;
		return X;
	}

	double GetY()
	{
		//cout << Y << endl;
		return Y;
	}
private:
	double X, Y;
};

#endif // !POINT