#include <iostream>
#include "Polygon.cpp"
using namespace std;

class Triangle :public Polygon
{
public:
	void SetTriangle()
	{
		double x, y;
		for (int i = 0; i < 3; i++)
		{
			cout << "input points x,y: " << endl;
			cin >> x;
			cin >> y;
			a[i].SetX(x);
			a[i].SetY(y);
		}
	}
	bool IsRight()
	{
		dis1 = sqrt(pow(a[1].GetX() - a[2].GetX(), 2) + pow(a[1].GetY() - a[2].GetY(), 2));
		dis2 = sqrt(pow(a[1].GetX() - a[3].GetX(), 2) + pow(a[1].GetY() - a[3].GetY(), 2));
		dis3 = sqrt(pow(a[2].GetX() - a[3].GetX(), 2) + pow(a[2].GetY() - a[3].GetY(), 2));
		return (dis1 + dis2>dis3&&dis1 + dis3>dis2&&dis3 + dis2>dis1);
	}
	double GetAngle()
	{
		ang1 = (dis1*dis1 + dis2*dis2 - dis3*dis3) / 2 * dis1*dis2;
		ang2 = (dis1*dis1 + dis3*dis3 - dis2*dis2) / 2 * dis1*dis3;
		ang3 = (dis2*dis2 + dis3*dis3 - dis1*dis1) / 2 * dis2*dis3;
		cout << "角1的sin值: " << ang1 << "角2的sin值: " << ang2 << "角3的sin值: " << ang3 << endl;
		return 0;
	}

	Line GetHight(IN int index)
	{
		Line tem1;
		double k, b;
		tem1.Segment(a[0], a[1],k=0,b=0);
		double K1;
		K1 = -1 / k;
		b = a[3].GetY() - k*a[3].GetX();
		tem1.ReSet(K1,b);
		return tem1;
	}
private:
	Point a[3];
	double dis1;//三边长度
	double dis2;
	double dis3;
	double ang1;//三角度的sin值
	double ang2;
	double ang3;
};