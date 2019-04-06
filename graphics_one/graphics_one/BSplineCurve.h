#pragma once
#include "curve.h"

class BSplineCurve:public Curve
{
public:
	BSplineCurve(int num);
	~BSplineCurve();
	void OutputBSpline(FILE *file);
	void OutputBezier(FILE *file);
	void Paint(ArgParser * args);
	TriangleMesh* OutputTriangles(ArgParser *args);
private:

};