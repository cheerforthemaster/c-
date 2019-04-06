#pragma once
#include "3Dsort.h"
#include <vector>

// 1  vec[0].size()
// 1 2 vec[1]
// 1 2 3 vec[2]


// the example of array
//{
//	{x1, y1, z0, t1},
//	{x1, y1, z1, t2}
//}

threeDsort::threeDsort()
{
	minT = 0;
	maxT = -9999;
	xMin = 67108864;
	xMin2 = 67108864;
	yMin = 67108864;
	interval = 0;
}

vector<vector<double>> threeDsort::_read(vector<vector<double>>& vec)
{
	double level = maxT - minT;
	double FUYI = -0.9990E+03;
	interval = xMin2 - xMin;
	for (int i = 0; i < vec.size(); ++i)
	{
		for (int j = 0; j < vec[0].size(); ++j)
		{
			switch (j)
			{
			case 0:
			{
				//vec[i][j] = (vec[i][j] - xMin) / interval;
				vec[i][j] = (vec[i][j] - xMin) / (interval*10) - 88 / 20;
				break;
			}
			case 1:
			{
				//vec[i][j] = (vec[i][j] - yMin) / interval;
				vec[i][j] = (vec[i][j] - yMin) / (interval * 10) - 144 / 20 * 1.07;
				break;
			}
			case 2:
			{
				vec[i][j] = vec[i][j] / (interval * 10);
				break;
			}
			case 3:
			{
				if (vec[i][j] + 999 < 1e-5)
				{
					vec[i][j] = -1;
					break;
				}
				double temp = vec[i][j] - minT;
				double post1 = temp / level * 100;
// 				int pos = (int)post1;
// 				if (post1 - pos >= 0.5)
// 					vec[i][j] = pos + 1;
// 				else if ((post1 - pos < 0.5))
// 					vec[i][j] = pos;
				vec[i][j] = post1;
				break;
			}
			default:
				break;
			}
		}
	}
	return vec;
}

vector<vector<double>> threeDsort::readFile()
{
	string fileName = "Z_LAYER7.SX7";
	string fileName2 = "headdetail.out";
	ifstream infile;
	ifstream infile2;
	infile.open(fileName, ios::in);
	infile2.open(fileName2, ios::in);
	if (!infile.is_open())
		cout << "Open file failure" << endl;
	if (!infile2.is_open())
		cout << "Open file two failure" << endl;
	int x = 0;
	vector<vector<double>> vec;
	while (!infile.eof())
	{
		double X, Y, Z0, Z1, Z2, Z3, Z4, Z5;
		infile >> X >> Y >> Z0 >> Z1 >> Z2 >> Z3 >> Z4 >> Z5;
		if (x == 0)
		{
			xMin = X;
			yMin = Y;
		}
		if (x == 6)
			xMin2 = X;
		for (int y = 0; y < 6; y++)
		{
			vec.push_back({});
			vec[x].push_back(X);
			vec[x].push_back(Y);
			switch (y)
			{
			case 0:
				vec[x].push_back(Z0);
				x++;
				break;
			case 1:
				vec[x].push_back(Z1);
				x++;
				break;
			case 2:
				vec[x].push_back(Z2);
				x++;
				break;
			case 3:
				vec[x].push_back(Z3);
				x++;
				break;
			case 4:
				vec[x].push_back(Z4);
				x++;
				break;
			case 5:
				vec[x].push_back(Z5);
				x++;
				break;
			default:
				break;
			}
		}
	}
	infile.close();
	x = 0;
	double mmm;
	infile2 >> mmm;
	int maxsize = vec.size();
	while (!infile2.eof() && x < maxsize)
	{	
		string temp;
		infile2 >> temp;
		const char * t = temp.c_str();
		double tt = atof(t);
		if (tt > 40000)
		{
			continue;
		}
		if (tt + 999 > 1e-7)
		{
			if (tt < minT)
				minT = tt;
			if (tt > maxT)
				maxT = tt;
		}
		vec[x].push_back(tt);
		x++;
	}
	infile2.close();
	return vec;
}

vector<vector<double>> threeDsort::readPoint()
{
	string fileName = "Z_LAYER7.SX7";
	ifstream infile;
	infile.open(fileName, ios::in);
	if (!infile.is_open())
		cout << "Open file failure" << endl;
	vector<vector<double>> Points;
	int x = 0;
	while (!infile.eof())
	{
		double X, Y, Z0, Z1, Z2, Z3, Z4, Z5;
		infile >> X >> Y >> Z0 >> Z1 >> Z2 >> Z3 >> Z4 >> Z5;
		for (int y = 0; y < 6; y++)
		{
			switch (y)
			{
			case 0:
				Points.push_back({});
				Points[x].push_back(X);
				Points[x].push_back(Y);
				Points[x].push_back(Z0);
				x++;
				break;
			case 1:
				Points.push_back({});
				Points[x].push_back(X);
				Points[x].push_back(Y);
				Points[x].push_back(Z1);
				x++;
				break;
			case 2:
				Points.push_back({});
				Points[x].push_back(X);
				Points[x].push_back(Y);
				Points[x].push_back(Z2);
				x++;
				break;
			case 3:
				Points.push_back({});
				Points[x].push_back(X);
				Points[x].push_back(Y);
				Points[x].push_back(Z3);
				x++;
				break;
			case 4:
				Points.push_back({});
				Points[x].push_back(X);
				Points[x].push_back(Y);
				Points[x].push_back(Z4);
				x++;
				break;
			case 5:
// 				Points[x].push_back(Z5);
// 				x++;
				break;
			default:
				break;
			}
		}
	}
	infile.close();
	return Points;
}

vector<double> threeDsort::readTemperature()
{
	vector<double> temperature;
	string fileName2 = "headdetail.out";
	ifstream infile2;
	infile2.open(fileName2, ios::in);
	if (!infile2.is_open())
		cout << "Open file two failure" << endl;
	int x = 0;
	double mmm;
	infile2 >> mmm;
	while (!infile2.eof())
	{
		string temp;
		infile2 >> temp;
		const char * t = temp.c_str();
		double tt = atof(t);
		if (tt > 40000)
		{
			break;
		}
		if (tt + 999 > 1e-7)
		{
			if (tt < minT)
				minT = tt;
			if (tt > maxT)
				maxT = tt;
		}
		temperature.push_back(tt);
		x++;
	}
	infile2.close();
	return temperature;
}

void threeDsort::_out(vector<vector<double>>& vec)
{
// 	for (int i = 0; i < vec.size()/ vec[0].size(); ++i)
// 	{
// 		cout << "{";
// 		for (int j = 0; j < vec[0].size(); ++j)
// 		{
// 			cout << vec[i][j];
// 			if (j != vec[0].size() - 1)
// 				cout << ", ";
// 		}
// 		cout << "}" << endl;
// 	}
	ofstream outfile("out0.txt", ios::trunc);
	ofstream outfile1("out1.txt", ios::trunc);
	ofstream outfile2("out2.txt", ios::trunc);
	ofstream outfile3("out3.txt", ios::trunc);
	ofstream outfile4("out4.txt", ios::trunc);
	ofstream outfile5("out5.txt", ios::trunc);
	for (int i = 0; i < vec.size(); ++i)
	{
		switch (i%6)
		{
		case 0:
		{
			outfile << "{";
			for (int j = 0; j < vec[0].size(); ++j)
			{
				outfile << vec[i][j];
				if (j != vec[0].size() - 1)
					outfile << ", ";
			}
			outfile << "}" << endl;
			break;
		}
		case 1:
		{
			outfile1 << "{";
			for (int j = 0; j < vec[0].size(); ++j)
			{
				outfile1 << vec[i][j];
				if (j != vec[0].size() - 1)
					outfile1 << ", ";
			}
			outfile1 << "}" << endl;
			break;
		}
		case 2:
		{
			outfile2 << "{";
			for (int j = 0; j < vec[0].size(); ++j)
			{
				outfile2 << vec[i][j];
				if (j != vec[0].size() - 1)
					outfile2 << ", ";
			}
			outfile2 << "}" << endl;
			break;
		}
		case 3:
		{
			outfile3 << "{";
			for (int j = 0; j < vec[0].size(); ++j)
			{
				outfile3 << vec[i][j];
				if (j != vec[0].size() - 1)
					outfile3 << ", ";
			}
			outfile3 << "}" << endl;
			break;
		}
		case 4:
		{
			outfile4 << "{";
			for (int j = 0; j < vec[0].size(); ++j)
			{
				outfile4 << vec[i][j];
				if (j != vec[0].size() - 1)
					outfile4 << ", ";
			}
			outfile4 << "}" << endl;
			break;
		}
		case 5:
		{
			outfile5 << "{";
			for (int j = 0; j < vec[0].size(); ++j)
			{
				outfile5 << vec[i][j];
				if (j != vec[0].size() - 1)
					outfile5 << ", ";
			}
			outfile5 << "}" << endl;
			break;
		}
		default:
			break;
		}
	}
	outfile.close();
}
