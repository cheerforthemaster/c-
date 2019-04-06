#include "curve.h"

Curve::Curve(int num)
{
}

Curve::Curve()
{
}

Curve::~Curve()
{
}

void Curve::Paint(ArgParser * args)
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

}