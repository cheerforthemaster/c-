#pragma once
#include "surface.h"
#include "curve.h"

class SurfaceOfRevolution:public Surface
{
public:
	SurfaceOfRevolution(Curve *line);
	SurfaceOfRevolution();
	~SurfaceOfRevolution();
	void Paint(ArgParser * args);
	TriangleMesh* OutputTriangles(ArgParser *args);
	void OutputBSpline(FILE *file);
	void OutputBezier(FILE *file);
	// 用于编辑操作的FOR EDITING OPERATIONS
	int getNumVertices();
	Vec3f getVertex(int i);
	void moveControlPoint(int selectedPoint, float x, float y);
	void addControlPoint(int selectedPoint, float x, float y);
	void deleteControlPoint(int selectedPoint);
private:
	Curve *li;

};