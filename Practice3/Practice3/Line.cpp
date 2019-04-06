#include "Point.cpp"
#include <iostream>
#include "Geometry.cpp"
using namespace std;
#ifndef LINE
#define LINE
#define IN
class Line : public Geometry
{
public:
	Line(){}
	void SetLine()
	{
		cout << "input point number:" << endl;
		cin >> pntNum;
		Point *a = new Point[pntNum];
		ptPoint = a;
		double x, y;
		for (int i = 0; i < pntNum; i++)
		{
			cout << "input points x,y: " << endl;
			cin >> x;
			cin >> y;
			ptPoint[i].SetX(x);
			ptPoint[i].SetY(y);
		}
	}


	Point GetVertex(IN int index)
	{
		cout << "Vertex x: " << ptPoint[index].GetX();
		cout << "Vertex y: " << ptPoint[index].GetY();
	}

	int GetCount()
	{
		return pntNum;
	}

	double GetLength()
	{
		double a = 0.0;
		for (int i = 1; i <= pntNum; i++)
			a += sqrt(pow(ptPoint[i].GetX() - ptPoint[2].GetX(), 2) + pow(ptPoint[i].GetY() - ptPoint[2].GetY(), 2));
		return a;
	}


	void Segment(Point a, Point b,double k,double p)//直线，由两个点确定,K为斜率
	{
		K = (a.GetY() - b.GetY()) / (a.GetX() - b.GetX());
		B = a.GetY() - K*a.GetX();
		cout << "line segment: y=" << K << "x+" << B << endl;
	}

	void ReSet(double k, double p)//由k b 重新定义线
	{
		K = k;
		B = p;
		cout << "line segment: y=" << K << "x+" << B << endl;
	}

	~Line()
	{
		delete []ptPoint;
	}
private:
	Point *ptPoint;
	long pntNum;//point number
	double K;
	double B;
};
#endif // !LINE
