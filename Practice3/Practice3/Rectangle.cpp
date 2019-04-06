#include <iostream>
#include "Polygon.cpp"
#ifndef RECTANGLE
#define RECTANGLE
using namespace std;

class Rectangle :public Polygon
{
public:
	int a=1, b=2, c=3, p;//abΪ��(��)��bcΪ��acΪ�Խ��ߣ�a��b��c �Ǽ�¼rec���������±ꣻpΪ���ò���
	void SetRectangle()
	{
		double x, y;
		for (int i = 0; i < 4; i++)//���þ��ε�4����
		{
			cout << "input points x,y: " << endl;
			cin >> x;
			cin >> y;
			rec[i].SetX(x);
			rec[i].SetY(y);
		}
		//���㳤�����Խ��ߣ�����ǶԽ��ߣ���̵��ǿ�;ֻ��������
		w = sqrt(pow(rec[1].GetX() - rec[2].GetX(), 2) + pow(rec[1].GetY() - rec[2].GetY(), 2));//ab
		h = sqrt(pow(rec[2].GetX() - rec[3].GetX(), 2) + pow(rec[2].GetY() - rec[3].GetY(), 2));//bc
		d = sqrt(pow(rec[1].GetX() - rec[3].GetX(), 2) + pow(rec[1].GetY() - rec[3].GetY(), 2));//ac
		double tem;
		if (h > w)//����if������������
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