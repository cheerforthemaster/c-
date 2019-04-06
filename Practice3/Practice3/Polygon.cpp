#ifndef POLYGON
#define POLYGON
#include "Point.cpp"
#include "Line.cpp"
using namespace std;

class Polygon :public Geometry
{
public:
	double GetArea() {}
	double GetPerimeter() {}
	Point GetVertex(IN int index) {}
	int GetVCount() {}
	Point Centroid() {}
	int GetECount() {}
	Line GetEdge(IN int index) {}
	//类Polygon中的一切成员函数在子类中的具体多边形中覆盖来起作用
private:
	long lineNum;
	Line *ptLine;
};
#endif