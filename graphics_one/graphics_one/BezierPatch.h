#pragma once
#include "surface.h"

class BezierPatch:public Surface
{
public:
	BezierPatch();
	~BezierPatch();
	void Paint(ArgParser * args);
	TriangleMesh* OutputTriangles(ArgParser *args);

	void addControlPoint(int selectedPoint, float x, float y);
	void deleteControlPoint(int selectedPoint);
private:
	vector<Vec3f> m_data;
};