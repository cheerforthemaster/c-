#include <iostream>
#include <string>
#include "Geometry.cpp"
#include "Point.cpp"
#include "Triangle.cpp"
#include "Trapezoid.cpp"
#include "Rectangle.cpp"
#include "Line.cpp"
#include "Circle.cpp"
using namespace std;



void main()
{
	Triangle tra;//��������
	tra.SetTriangle();
	tra.IsRight();
	tra.GetAngle();
	tra.GetHight(2);

	Circle cir;//����Բ
	cir.SetRadius();
	cir.GetRadius();
	cir.Area();

	Rectangle rec;//���Ծ���
	rec.SetRectangle();
	rec.GetWidth();
	rec.GetHeight();
	rec.GetDiagonal();

	Trapezoid trape;//��������
	trape.SetTrapezoid();
	trape.GetTop();
	trape.GetBottom();
}