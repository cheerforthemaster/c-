#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class threeDsort
{
public:
	threeDsort();
	vector<vector<double>> _read(vector<vector<double>> &vec);
	vector<vector<double>> readFile();
	vector<vector<double>> readPoint();
	vector<double> readTemperature();
	void _out(vector<vector<double>> &vec);
protected:
private:
	double minT;
	double maxT;
	double xMin;
	double xMin2;
	double yMin;
	double interval;
};