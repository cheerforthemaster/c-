#include "BSplineCurve.h"

BSplineCurve::BSplineCurve(int num)
{
}

BSplineCurve::~BSplineCurve()
{
}

void BSplineCurve::OutputBSpline(FILE * file)
{
	fprintf(file, "bspline\nnum_vertices %d\n", this->Curve::getNumVertices());
	Vec3f tem;
	for (int i = 0; i < this->Curve::getNumVertices(); i++)
	{
		tem = getVertex(i);
		fprintf(file, "%f %f %f\n", tem.x(), tem.y(), tem.z());
	}
}

void BSplineCurve::OutputBezier(FILE * file)
{
	fprintf(file, "bezier\nnum_vertices %d\n", this->Curve::getNumVertices());
	float bb[] = { -1,3,-3,1,
		3,-6,3,0,
		-3,3,0,0,
		1,0,0,0 };
	float bs[] = { -1,3,-3,1,
		3,-6,0,4,
		-3,3,3,1,
		1,0,0,0 };
	float gs[16];
	float *gb;
	Vec3f tem;
	int i = 0;

	for (int j = 0; j < 4; j++)
	{
		tem = getVertex(j);
		gs[i] = tem.x();
		gs[i + 4] = tem.y();
		gs[i + 8] = tem.z();
		gs[i + 12] = 0;
		i++;
	}

	Matrix BB(bb);
	Matrix BS(bs);
	Matrix GS(gs);
	BB.Inverse();
	Matrix GB =  (GS*BS)*BB;
	gb = GB.glGet();
	i = 0;
	for (int j = 0; j < 4; j++)
	{
		fprintf(file, "%f %f %f\n", gb[i]/6, gb[i + 1]/6, gb[i + 2]/6);
		i = i + 4;
	}

}

void BSplineCurve::Paint(ArgParser * args)
{
	this->Curve::Paint(args);
	Vec3f tem;
	int prePoint = 0;
	int veNum = getNumVertices();
	glColor3f(0, 1, 0);
	glLineWidth(4);
	while (prePoint + 4 <= veNum)
	{
		for (int i = prePoint,j = 0; i < prePoint + 4&&j < 4; i++, j++)
		{
			tem = getVertex(i);
			ctrlpoints[j][0] = tem.x();
			ctrlpoints[j][1] = tem.y();
			ctrlpoints[j][2] = tem.z();
		}
		prePoint++;


		float f1, f2, f3, f4;
		float deltaT = 1.0 / args->curve_tessellation;
		float T;

		glBegin(GL_LINE_STRIP);

		for (int i = 0; i <= args->curve_tessellation; i++) {

			T = i * deltaT;

			f1 = (-T*T*T + 3 * T*T - 3 * T + 1) / 6.0;
			f2 = (3 * T*T*T - 6 * T*T + 4) / 6.0;
			f3 = (-3 * T*T*T + 3 * T*T + 3 * T + 1) / 6.0;
			f4 = (T*T*T) / 6.0;

			glVertex3f(f1*ctrlpoints[0][0] + f2*ctrlpoints[1][0] + f3*ctrlpoints[2][0] + f4*ctrlpoints[3][0],
				f1*ctrlpoints[0][1] + f2*ctrlpoints[1][1] + f3*ctrlpoints[2][1] + f4*ctrlpoints[3][1],
				f1*ctrlpoints[0][2] + f2*ctrlpoints[1][2] + f3*ctrlpoints[2][2] + f4*ctrlpoints[3][2]);
		}
		glEnd();
	}

}

TriangleMesh * BSplineCurve::OutputTriangles(ArgParser * args)
{
	TriangleMesh* ou = new TriangleNet((args->curve_tessellation + 1)*(getNumVertices() - 3)- 1, args->revolution_tessellation);
	Vec3f tem;
	int prePoint = 0;
	int veNum = getNumVertices();

	Matrix GB;
	vector<Vec3f> vectem;
	while (prePoint + 4 <= veNum)
	{
		for (int i = prePoint, j = 0; i < prePoint + 4 && j < 4; i++, j++)//取出控制点
		{
			tem = getVertex(i);
			ctrlpoints[j][0] = tem.x();
			ctrlpoints[j][1] = tem.y();
			ctrlpoints[j][2] = tem.z();
		}
		prePoint++;
		float f1, f2, f3, f4;
		float deltaT = 1.0 / args->curve_tessellation;
		float T;
		for (int l = 0; l <= args->curve_tessellation; l++)//算出由控制点打出的点
		{
			T = l * deltaT;

			f1 = (-T*T*T + 3 * T*T - 3 * T + 1) / 6.0;
			f2 = (3 * T*T*T - 6 * T*T + 4) / 6.0;
			f3 = (-3 * T*T*T + 3 * T*T + 3 * T + 1) / 6.0;
			f4 = (T*T*T) / 6.0;
			tem.Set(f1*ctrlpoints[0][0] + f2*ctrlpoints[1][0] + f3*ctrlpoints[2][0] + f4*ctrlpoints[3][0],
				f1*ctrlpoints[0][1] + f2*ctrlpoints[1][1] + f3*ctrlpoints[2][1] + f4*ctrlpoints[3][1],
				f1*ctrlpoints[0][2] + f2*ctrlpoints[1][2] + f3*ctrlpoints[2][2] + f4*ctrlpoints[3][2]);
			vectem.insert(vectem.end(), tem);
		}
	}
	int k = 0;
	GB = Matrix::MakeYRotation(0);
	//TriangleMesh* outem = new TriangleNet((args->curve_tessellation + 1)*(getNumVertices() - 1) / 3 - 1, 1);
	for (int j = 0; j < vectem.size(); j++)
	{
		for (int i = 0; i <= args->revolution_tessellation; i++)//转动args->revolution_tessellation次画成一个闭合的立体
		{
			GB = Matrix::MakeYRotation(2 * 3.1415926 / args->revolution_tessellation);
			GB.Transpose(GB);
			GB.Transform(vectem[j]);
			ou->SetVertex(k, vectem[j]);
			k++;
		}
	}
	return ou;
}
