#include <iostream>
#include "Polygon.cpp"
using namespace std;

class Circle :public Polygon
{
public:
	double SetRadius()
	{
		cout << "input circle radius:" << endl;
		cin >> radi;
		return radi;
	}
	double GetRadius()
	{
		return radi;
	}
	double Area()
	{
		return radi*radi*3.1415;
	}
private:
	double radi;
};