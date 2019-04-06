#include<iostream>
#include "Point.cpp"
#include "Polygon.cpp"
using namespace std;

class Trapezoid :public Polygon
{
public:
	void SetTrapezoid()
	{
		double x, y;
		for (int i = 0; i < 4; i++)//设置梯形的4个点
		{
			cout << "Enter two vertices and two lower vertices in order: " << endl;
			cin >> x;
			cin >> y;
			tra[i].SetX(x);
			tra[i].SetY(y);
		}
	}
	Line GetTop()
	{
		Line tem;
		tem.Segment(tra[0],tra[1],0,0);
		return tem;
	}

	Line GetBottom()
	{
		Line tem;
		tem.Segment(tra[2],tra[3],0,0);
		return tem;
	}
	double GetHight()
	{

	}
private:
	Point tra[4];
};