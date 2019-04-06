#include "SurfaceOfRevolution.h"

SurfaceOfRevolution::SurfaceOfRevolution(Curve * line)
{
	li = line;
}

SurfaceOfRevolution::SurfaceOfRevolution()
{
}

SurfaceOfRevolution::~SurfaceOfRevolution()
{
}

void SurfaceOfRevolution::Paint(ArgParser * args)
{
	li->Paint(args);
}

TriangleMesh * SurfaceOfRevolution::OutputTriangles(ArgParser * args)
{
	return li->OutputTriangles(args);
}

void SurfaceOfRevolution::OutputBSpline(FILE * file)
{
	li->OutputBSpline(file);
}

void SurfaceOfRevolution::OutputBezier(FILE * file)
{
	li->OutputBezier(file);
}

int SurfaceOfRevolution::getNumVertices()
{
	return li->getNumVertices();
}

Vec3f SurfaceOfRevolution::getVertex(int i)
{
	return li->getVertex(i);
}

void SurfaceOfRevolution::moveControlPoint(int selectedPoint, float x, float y)
{
	li->moveControlPoint(selectedPoint, x, y);
}

void SurfaceOfRevolution::addControlPoint(int selectedPoint, float x, float y)
{
	li->addControlPoint(selectedPoint, x, y);
}

void SurfaceOfRevolution::deleteControlPoint(int selectedPoint)
{
	li->deleteControlPoint(selectedPoint);
}
