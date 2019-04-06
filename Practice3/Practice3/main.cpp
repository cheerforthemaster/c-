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
	Triangle tra;//≤‚ ‘»˝Ω«
	tra.SetTriangle();
	tra.IsRight();
	tra.GetAngle();
	tra.GetHight(2);

	Circle cir;//≤‚ ‘‘≤
	cir.SetRadius();
	cir.GetRadius();
	cir.Area();

	Rectangle rec;//≤‚ ‘æÿ–Œ
	rec.SetRectangle();
	rec.GetWidth();
	rec.GetHeight();
	rec.GetDiagonal();

	Trapezoid trape;//≤‚ ‘Ã›–Œ
	trape.SetTrapezoid();
	trape.GetTop();
	trape.GetBottom();
}