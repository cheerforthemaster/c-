#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class ProcessData
{
public:
	ProcessData()
	{
		points = new vector<vector<double>>;
		section_X = -1;
	}
	~ProcessData()
	{
		points->clear();
		x = -1;
		y = -1;
		z = -1;
	}
	// 传入一个数组
	// x坐标，y坐标，z坐标，温度
	//{
	//	{x1, y1, z0, t1},
	//	{x1, y1, z1, t2}
	//}
	// 一次只能出入一个时间片的数据
	vector<vector<double>> processArray(vector<vector<double>> &vec1, vector<double> &vec2,
		int X = -1, int Y = -1, int Z = -1)
	{
		x = X;
		y = Y;
		z = Z;
		double minT = 0;
		double maxT = -9999;
		mergeArray(vec1, vec2, minT, maxT);
		if ((X == -1) || (Y == -1))
		{
			cout << "Inadequacy of parameters" << endl;
			return vec1;
		}
		double level = maxT - minT; // level is used to make temperature
		double xMin = points->at(0)[0];    // the minimum value of X
		double yMin = points->at(0)[1];    // the minimum value of Y
		double intervalX = 0;  // the interval of X
		double intervalY = 0;  // the interval of Y
		for (int x = 0; x < points->size() - 1 / points->at(0).size(); ++x)
		{
			if (intervalX < 1e-5)
				intervalX = fabs(points->at(x + 1)[0] - points->at(x)[0]);  // the interval of X
			if (intervalY < 1e-5)
				intervalY = fabs(points->at(x + 1)[1] - points->at(x)[1]);  // the interval of Y
			if (intervalX && intervalY)
				break;
		}
		double interval = max(intervalX, intervalY);	 // the interval of both, and switch the bigger
		int numOfXY = max(X, Y);
		double needTO = 35 / ((double)numOfXY / 2);
		for (int i = 0; i < points->size(); ++i)
		{
			for (int j = 0; j < points->at(0).size(); ++j)
			{
				switch (j)
				{
				case 0:
				{
					// case 0 is mean vec[?][0], and it representative X
					// vec[i][j] = (vec[i][j] - xMin) / (interval * 10)
					// select the first as a benchmark
					// and then move it to appropriate position
					// such as, 0, 1, 2, 3, 4, 5 move them, -2, -1, 0, 1, 2, 3
					points->at(i)[j] = ((points->at(i)[j] - xMin) - X / 2 * intervalX) / interval * needTO;
					break;
				}
				case 1:
				{
					// case 1 is mean vec[?][1], and it representative Y
					points->at(i)[j] = ((points->at(i)[j] - yMin) - Y / 2 * intervalY) / interval * needTO;
					break;
				}
				case 2:
				{
					// case 2 is mean vec[?][2], and it representative Z
					points->at(i)[j] = points->at(i)[j] / interval;
					break;
				}
				case 3:
				{
					// 999 is mean the space, and need to be abandoned
					if (points->at(i)[j] + 999 < 1e-5)
					{
						points->at(i)[j] = -1;
						break;
					}
					double temp = points->at(i)[j] - minT;
					double post1 = temp / level * 100;
					points->at(i)[j] = post1;
					break;
				}
				default:
					break;
				}
			}
		}
		return *points;
	}
	// x轴的最小值   y轴的最小值   间隔（x和y之间最大的那个间隔） x行数  y行数
	bool getRectanglePoints(int num, vector<vector<double>> &vec)
	{
		int a = num / ((x - 1) * (y - 1));// a 是确定在哪个面
		int b = num - a * (x - 1)*(y - 1);// b 是面里数
		int i = b / (x - 1);
		int j = b % (x - 1);
		int first = (i * x + j)*z + a;
		int second = (i*x + j + 1)*z + a;
		int third = ((i + 1) *x + j + 1)*z + a;
		int fourth = ((i + 1)*x + j)*z + a;
		if (num < 0)
			return false;
		if (a > z - 1)
			return false;
		if (third > (x*y*z))
			return false;
		vec.clear();
		vec.push_back(points->at(first));
		vec.push_back(points->at(second));
		vec.push_back(points->at(third));
		vec.push_back(points->at(fourth));
		return true;
	}
	bool getSection(int num, vector<vector<double>> &vec, vector<vector<double>> &source)
	{
		if (section_X == -1)
		{
			int temp = source[0][1];
			for (int i = 0; i < source.size(); ++i)
			{
				if (temp - source[i][1] > 1e-5)
				{
					section_X = i - 1;
				}
			}
		}
		int i = num / (section_X - 1);
		int j = num % (section_X - 1);
		int first = i * section_X + j;
		int second = i * section_X + j + 1;
		int third = (i + 1) * section_X + j + 1;
		int fourth = (i + 1) * section_X + j;
		if (num < 0)
		{
			section_X = -1;
			return false;
		}
		if (third > source.size())
		{
			section_X = -1;
			return false;
		}
		vec.clear();
		vec.push_back(source[first]);
		vec.push_back(source[second]);
		vec.push_back(source[third]);
		vec.push_back(source[fourth]);
		return true;
	}
protected:
	void mergeArray(vector<vector<double>> &vec1, vector<double> &vec2, double &minT, double &maxT)
	{
		points->clear();
		for (int i = 0; i < vec1.size() && i < vec2.size(); ++i)
		{
			points->push_back(vec1[i]);
			points->at(i).push_back(vec2[i]);
			if (points->at(i).back() + 999 > 1e-7)
			{
				if (points->at(i).back() < minT)
					minT = points->at(i).back();
				if (points->at(i).back() > maxT)
					maxT = points->at(i).back();
			}
		}
	}
private:
	vector<vector<double>> *points;
	int x, y, z;
	int section_X;
};