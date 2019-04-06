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
	//��Polygon�е�һ�г�Ա�����������еľ��������и�����������
private:
	long lineNum;
	Line *ptLine;
};
#endif