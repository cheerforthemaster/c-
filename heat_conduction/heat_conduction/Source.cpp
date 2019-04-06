#include <iostream>
#include <omp.h>
#include <time.h>
#include <vector>
using namespace std;

static int row = 100;
static int column = 100;
double dValue = 1;
vector<vector<double>> preObject;
vector<vector<double>> lastObject;
static int frequency = 0;


bool initVector()//初始化数组
{
	for (int i = 0; i < row; i++)
	{
		vector<double> tem;
		for (int j = 0; j < column; j++)
		{
			tem.push_back(0);
		}
		preObject.push_back(tem);
	}

	for (int i = 0; i < row; i++)//上下为100度，左右为200度
	{
		preObject[0][i] = 100;
		preObject[row - 1][i] = 100;
		preObject[i][column - 1] = 200;
		preObject[i][0] = 200;
	}
	lastObject = preObject;
	return true;
}

bool isAccord()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (abs(preObject[i][j] - lastObject[i][j]) > dValue)
			{
				return false;
			}
		}
	}
	return true;
}

//并行计算前
long b_JacobiFor()
{
	clock_t Start = clock();
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < column - 1; j++)
		{
			preObject[i][j] = (lastObject[i - 1][j] + lastObject[i + 1][j] + lastObject[i][j - 1] + lastObject[i][j + 1]) / 4;
		}
	}
	clock_t End = clock();
	return End - Start;
}

bool b_Jacobi()
{
	b_JacobiFor();
	long m_time = 0;
	while (!isAccord())
	{
		frequency++;
		lastObject = preObject;
		m_time += b_JacobiFor();
	}
	cout << "Jacobi算法执行持续时间：" << m_time << "毫秒" << "； 迭代次数:" << frequency << endl;
	frequency = 0;
	return true;
}

//Gauss - Seidel
long b_Gauss_SeidelFor()
{
	clock_t Start = clock(); 
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < column - 1; j++)
		{
			preObject[i][j] = (preObject[i - 1][j] + preObject[i + 1][j] + preObject[i][j - 1] + preObject[i][j + 1]) / 4;
		}
	}
	clock_t End = clock();
	return End - Start;
}

bool b_Gauss_Seidel()
{
	long m_time = 0;
	b_Gauss_SeidelFor();
	while (!isAccord())
	{
		frequency++;
		lastObject = preObject;
		m_time += b_Gauss_SeidelFor();
	}

	cout << "Gauss_Seidel算法执行持续时间：" << m_time << "毫秒" << "； 迭代次数:" << frequency << endl;
	frequency = 0;
	return true;
}

//SOR
long b_SORFor()
{
	clock_t Start = clock();
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < column - 1; j++)
		{
			preObject[i][j] = (preObject[i - 1][j] + preObject[i + 1][j] + preObject[i][j - 1] + preObject[i][j + 1]) / 4;
		}
	}

	for (int i = 1; i < column - 1; i++)
	{
		for (int j = 1; j < row - 1; j++)
		{
			preObject[j][i] = (preObject[j - 1][i] + preObject[j + 1][i] + preObject[j][i - 1] + preObject[j][i + 1]) / 4;
		}
	}

	clock_t End = clock();
	return End - Start;
}

bool b_SOR()
{
	long m_time = 0;
	b_SORFor();
	while (!isAccord())
	{
		frequency++;
		lastObject = preObject;
		m_time += b_SORFor();
	}
	cout << "SOR算法执行持续时间：" << m_time << "毫秒" << "； 迭代次数:" << frequency << endl;
	frequency = 0;
	return true;
}


//并行计算后
//Jacobi
long JacobiFor() 
{
	clock_t Start = clock();
	#pragma omp parallel
	{
	#pragma omp for 
		for (int i = 1; i < row - 1; i++)
		{
			for (int j = 1; j < column - 1; j++)
			{
				preObject[i][j] = (lastObject[i - 1][j] + lastObject[i + 1][j] + lastObject[i][j - 1] + lastObject[i][j + 1]) / 4;
			}
		}
	}
	clock_t End = clock();
	return End - Start;
}

bool Jacobi()
{
	JacobiFor();
	long m_time = 0;
	while (!isAccord())
	{
		frequency++;
		lastObject = preObject;
		m_time += JacobiFor();
	}
	cout << "Jacobi算法执行持续时间：" << m_time << "毫秒" << "； 迭代次数:" << frequency << endl;
	frequency = 0;
	return true;
}

//Gauss - Seidel
long Gauss_SeidelFor()
{
	clock_t Start = clock();
	#pragma omp parallel
	{
	#pragma omp for 
		for (int i = 1; i < row - 1; i++)
		{
			for (int j = 1; j < column - 1; j++)
			{
				preObject[i][j] = (preObject[i - 1][j] + preObject[i + 1][j] + preObject[i][j - 1] + preObject[i][j + 1]) / 4;
			}
		}
	}
	clock_t End = clock();
	return End - Start;
}

bool Gauss_Seidel()
{
	long m_time = 0;
	Gauss_SeidelFor();
	while (!isAccord())
	{
		frequency++;
		lastObject = preObject;
		m_time += Gauss_SeidelFor();
	}

	cout << "Gauss_Seidel算法执行持续时间：" << m_time << "毫秒" << "； 迭代次数:" << frequency << endl;
	frequency = 0;
	return true;
}

//SOR
long SORFor()
{
	clock_t Start = clock();
	#pragma omp parallel
	{
		#pragma omp for 
		for (int i = 1; i < row - 1; i++)
		{
			for (int j = 1; j < column - 1; j++)
			{
				preObject[i][j] = (preObject[i - 1][j] + preObject[i + 1][j] + preObject[i][j - 1] + preObject[i][j + 1]) / 4;
			}
		}
	}
	#pragma omp parallel
	{
		#pragma omp for 
		for (int i = 1; i < column - 1; i++)
		{
			for (int j = 1; j < row - 1; j++)
			{
				preObject[j][i] = (preObject[j - 1][i] + preObject[j + 1][i] + preObject[j][i - 1] + preObject[j][i + 1]) / 4;
			}
		}
	}
	clock_t End = clock();
	return End - Start;
}

bool SOR()
{
	long m_time = 0;
	SORFor();
	while (!isAccord())
	{
		frequency++;
		lastObject = preObject;
		m_time += SORFor();
	}
	cout << "SOR算法执行持续时间：" << m_time << "毫秒" << "； 迭代次数:" << frequency << endl;
	frequency = 0;
	return true;
}

int	main()
{
	cout << "并行化前:" << endl;
	initVector();
	b_Jacobi();
	b_Gauss_Seidel();
	b_SOR();
	cout << endl;
	cout << "并行化后:" << endl;
	lastObject.clear();
	preObject.clear();
	initVector();
	Jacobi();
	Gauss_Seidel();
	SOR();

	system("pause");
	return 0;
}