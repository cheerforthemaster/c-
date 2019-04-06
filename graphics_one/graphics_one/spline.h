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
	// ���ڻ�ͼ��FOR VISUALIZATION
	virtual void Paint(ArgParser *args);

	// ����ʵ����������ת����FOR CONVERTING BETWEEN SPLINE TYPES
	virtual void OutputBezier(FILE *file);
	virtual void OutputBSpline(FILE *file);

	// ���ڵõ����Ƶ��FOR CONTROL POINT PICKING
	virtual int getNumVertices();
	virtual Vec3f getVertex(int i);

	// ���ڱ༭������FOR EDITING OPERATIONS
	virtual void moveControlPoint(int selectedPoint, float x, float y);
	virtual void addControlPoint(int selectedPoint, float x, float y);
	virtual void deleteControlPoint(int selectedPoint);

	// ���ڲ��������ε�FOR GENERATING TRIANGLES
	virtual TriangleMesh* OutputTriangles(ArgParser *args);

	//���õ�
	virtual void set(int pre, Vec3f ve);

private:
	//���Ƶ�
	vector<Vec3f> vet;
};