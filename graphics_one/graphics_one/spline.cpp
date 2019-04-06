#include "spline.h"

Spline::Spline(int num)
{
}

Spline::Spline()
{
}

Spline::~Spline()
{
}

void Spline::Paint(ArgParser * args)
{
}

void Spline::OutputBezier(FILE * file)
{
}

void Spline::OutputBSpline(FILE * file)
{
}

int Spline::getNumVertices()
{
	return vet.size();
}

Vec3f Spline::getVertex(int i)
{
	return vet[i];
}

void Spline::moveControlPoint(int selectedPoint, float x, float y)
{
	vet[selectedPoint].Set(x, y, 0);
}

void Spline::addControlPoint(int selectedPoint, float x, float y)
{
	Vec3f ve(x, y, 0);
	set(selectedPoint, ve);
}

void Spline::deleteControlPoint(int selectedPoint)
{
	vet.erase(vet.begin() + selectedPoint);
}

TriangleMesh * Spline::OutputTriangles(ArgParser * args)
{
	return nullptr;
}

void Spline::set(int pre, Vec3f ve)
{
	vet.insert(vet.begin() + pre, ve);
}
