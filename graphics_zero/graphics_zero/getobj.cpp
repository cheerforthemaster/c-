#include "getobj.h"

bool getobj::setFileName(char * file)
{
	fstream objFile(file);
	if (!objFile.good())
		return false;
	char datatype;
	vector<double> tem;
	double pre = 0;
	while (!objFile.eof())
	{
		objFile >> datatype;
		for (int i = 0; i < 3; i++)
		{
			objFile >> pre;
			tem.insert(tem.end(), pre);
		}
		if (datatype == 'v')
		{
			vArr.insert(vArr.end(), tem);
		}
		if (datatype == 'f')
		{
			nArr.insert(nArr.end(), tem);
		}
		tem.clear();
		datatype = 0;
	}
}

