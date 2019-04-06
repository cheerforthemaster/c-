#include <iostream>
#include "Polygon.cpp"
#ifndef RECTANGLE
#define RECTANGLE
using namespace std;

class Rectangle :public Polygon
{
public:
	int a=1, b=2, c=3, p;//ab为长(高)，bc为宽，ac为对角线；a，b，c 是记录rec这个数组的下标；p为暂用参数
	void SetRectangle()
	{
		double x, y;
		for (int i = 0; i < 4; i++)//设置矩形的4个点
		{
			cout << "input points x,y: " << endl;
			cin >> x;
			cin >> y;
			rec[i].SetX(x);
			rec[i].SetY(y);
		}
		//计算长，宽，对角线，最长的是对角线，最短的是宽;只需三个点
		w = sqrt(pow(rec[1].GetX() - rec[2].GetX(), 2) + pow(rec[1].GetY() - rec[2].GetY(), 2));//ab
		h = sqrt(pow(rec[2].GetX() - rec[3].GetX(), 2) + pow(rec[2].GetY() - rec[3].GetY(), 2));//bc
		d = sqrt(pow(rec[1].GetX() - rec[3].GetX(), 2) + pow(rec[1].GetY() - rec[3].GetY(), 2));//ac
		double tem;
		if (h > w)//三个if是起排列作用
		{
			tem = h;
			h = w;
			w = tem;

			p = c;
			c = a;
			a = p;
		}
		if (w > d)
		{
			tem = w;
			w = d;
			d = tem;

			p = b;
			b = c;
			c = p;
		}
		if (h > d)
		{
			tem = h;
			h = d;
			d = tem;

			p = a;
			a = b;
			b = p;
		}
	}

	double GetWidth()
	{
		cout << "width: " << w;
		return w;
	}

	double GetHeight()
	{
		cout << "height: " << h;
		return h;
	}

	double GetDiagonal()
	{
		cout << "diagonal: " << d;
		return d;
	}

	Line GetDiagonal(IN int index)
	{
		Line tem;
		tem.Segment(rec[a], rec[c],0,0);
		return tem;
	}
private:
	Point rec[4];
	double w;
	double h;
	double d;
};
#endif 