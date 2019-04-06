#include <iostream>
using namespace std;

class CPoint
{
public:
	CPoint() { X = Y = 0; }
	CPoint(int xx, int yy) { X = xx; 	Y = yy; }
	~CPoint() {}
	double GetX() { return X; }
	double  GetY() { return Y; }
	void Move(int x, int y) { X = x;  Y = y; }
	void display(){}
	void operator ++()
	{
		X += 1;
		Y += 1;
	}
	void operator --()
	{
		X -= 1;
		Y -= 1;
	}
private:
	double  X, Y;
};



void main()
{
	CPoint pt(3,4);
//	pt(3,4);
	++pt;
	--pt;
	cout << pt.GetX() << "\n" << pt.GetY() << endl;
}


