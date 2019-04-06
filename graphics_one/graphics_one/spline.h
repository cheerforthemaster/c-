#pragma once
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "triangle_mesh.h"
#include "arg_parser.h"
#include "vectors.h"
#include <vector>
#include "glut.h"
#include "matrix.h"
using namespace std;

class Spline
{
public:
	Spline(int num);
	Spline();
	virtual ~Spline();
	// 用于画图的FOR VISUALIZATION
	virtual void Paint(ArgParser *args);

	// 用于实现样条类型转换的FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE *file);
	virtual void OutputBSpline(FILE *file);

	// 用于得到控制点的FOR CONTROL POINT PICKING
	virtual int getNumVertices();
	virtual Vec3f getVertex(int i);

	// 用于编辑操作的FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
	virtual void deleteControlPoint(int selectedPoint);

	// 用于产生三角形的FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser *args);

	//设置点
	virtual void set(int pre, Vec3f ve);

private:
	//控制点
	vector<Vec3f> vet;
};