#include "BezierPatch.h"
#include <iostream>
BezierPatch::BezierPatch()
{
}

BezierPatch::~BezierPatch()
{
}

void BezierPatch::Paint(ArgParser * args)
{
	int size = getNumVertices();
	Vec3f tem;
	glLineWidth(1);
	glColor3f(0, 0, 1);
	glBegin(GL_LINES);
	for (int i = 0; i < size - 1; i++)
	{
		tem = getVertex(i);
		glVertex3f(tem.x(), tem.y(), tem.z());
		tem = getVertex(i + 1);
		glVertex3f(tem.x(), tem.y(), tem.z());
	}
	glEnd();

	glPointSize(5);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (int i = 0; i < size; i++)
	{
		tem = getVertex(i);
		glVertex3f(tem.x(), tem.y(), tem.z());
	}
	glEnd();

	glColor3f(0, 1, 0);
	glLineWidth(4);

}

TriangleMesh * BezierPatch::OutputTriangles(ArgParser * args)
{
	float f1, f2, f3, f4;
	float s1, s2, s3, s4;
	float delta = 1.0 / args->patch_tessellation;
	float t;
	float u;
	float x, y, z;
	for (int i = 0; i <= args->patch_tessellation; i++) {
		t = i * delta;
		f1 = pow((1 - t), 3);
		f2 = pow((1 - t), 2) * 3 * t;
		f3 = 3 * t*t*(1 - t);
		f4 = t*t*t;
		for (int j = 0; j <= args->patch_tessellation; j++)
		{
			u = j*delta;
			s1 = pow((1 - u), 3);
			s2 = pow((1 - u), 2) * 3 * u;
			s3 = 3 * u*u*(1 - u);
			s4 = u*u*u;
			x = s1*(f1*getVertex(0).x() + f2*getVertex(1).x() + f3*getVertex(2).x() + f4*getVertex(3).x()) +
				s2*(f1*getVertex(4).x() + f2*getVertex(5).x() + f3*getVertex(6).x() + f4*getVertex(7).x()) +
				s3*(f1*getVertex(8).x() + f2*getVertex(9).x() + f3*getVertex(10).x() + f4*getVertex(11).x()) +
				s4*(f1*getVertex(12).x() + f2*getVertex(13).x() + f3*getVertex(14).x() + f4*getVertex(15).x());

			y = s1*(f1*getVertex(0).y() + f2*getVertex(1).y() + f3*getVertex(2).y() + f4*getVertex(3).y()) +
				s2*(f1*getVertex(4).y() + f2*getVertex(5).y() + f3*getVertex(6).y() + f4*getVertex(7).y()) +
				s3*(f1*getVertex(8).y() + f2*getVertex(9).y() + f3*getVertex(10).y() + f4*getVertex(11).y()) +
				s4*(f1*getVertex(12).y() + f2*getVertex(13).y() + f3*getVertex(14).y() + f4*getVertex(15).y());

			z = s1*(f1*getVertex(0).z() + f2*getVertex(1).z() + f3*getVertex(2).z() + f4*getVertex(3).z()) +
				s2*(f1*getVertex(4).z() + f2*getVertex(5).z() + f3*getVertex(6).z() + f4*getVertex(7).z()) +
				s3*(f1*getVertex(8).z() + f2*getVertex(9).z() + f3*getVertex(10).z() + f4*getVertex(11).z()) +
				s4*(f1*getVertex(12).z() + f2*getVertex(13).z() + f3*getVertex(14).z() + f4*getVertex(15).z());
			m_data.insert(m_data.end(), Vec3f(x, y, z));
		}
	}

	TriangleMesh* tr= new TriangleNet(args->patch_tessellation, args->patch_tessellation);
	for (int i = 0; i <m_data.size(); i++)
	{
		tr->SetVertex(i, m_data[i]);
	}
	return tr;
}

void BezierPatch::addControlPoint(int selectedPoint, float x, float y)
{
}

void BezierPatch::deleteControlPoint(int selectedPoint)
{
}
