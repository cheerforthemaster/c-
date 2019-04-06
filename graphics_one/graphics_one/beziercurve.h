#pragma once
#include "curve.h"

class BezierCurve:public Curve
{
public:
	BezierCurve(int num);
	~BezierCurve();
	void OutputBSpline(FILE *file);
	void OutputBezier(FILE *file);
	void Paint(ArgParser * args);
	TriangleMesh* OutputTriangles(ArgParser *args);
	// 用于编辑操作的FOR EDITING OPERATIONS
	void addControlPoint(int selectedPoint, float x, float y);
	void deleteControlPoint(int selectedPoint);
private:

};
