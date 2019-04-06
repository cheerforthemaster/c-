#pragma once
#include "spline.h"

class Curve:public Spline
{
public:
	Curve(int num);
	Curve();
	~Curve();
	void Paint(ArgParser *args);
	GLfloat ctrlpoints[4][3];
private:

};