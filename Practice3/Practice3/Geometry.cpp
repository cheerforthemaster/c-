#include <iostream>
#include <string>
#include<math.h>
#include "Rect.h"
#define OUT
#define IN
#ifndef GEOMETRY
#define GEOMETRY
using namespace std;


class Geometry
{
public:
	string GeometryType()
	{
		string Type;
		cout << "input Geometry:" << endl;
		cin >> Type;
		return Type;
	}

	Rect Envelope(OUT Rect rect)
	{
		cout << "input xmin,ymin,xmax,ymax:" << endl;
		cin >> rect.xmin;
		cin >> rect.ymin;
		cin >> rect.xmax;
		cin >> rect.ymax;
		x1 = rect.xmin;
		x2 = rect.xmax;
		y1 = rect.ymin;
		y2 = rect.ymax;
		return rect;
	}

	double Distance(IN Geometry &anotherGeometry)
	{
		//之后在具体的图形中定义
	}
protected:
	double x1, x2, y1, y2;

};
#endif
