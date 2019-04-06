#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <atlstr.h>
using namespace std;

struct stu
{
	char id[12];//学生学号
	char name[7];//学生名字
	double major;//专业 
	double math;
	double English;
	double physics;
};

struct sub
{
	char sub_name[5];//学科名称
	char id[14][14];//学生学号
	char name[14][7];//学生名字
	double average;//平均分
	double h_score;//最高分
	double l_score;//最低分
	double dif_socre;//最大分数差
	double std_dev;//标准差
	int ranking[14];//名次
	double mark[14];//分数组
};

double Getaverage(double a[14]);//获取平均分
double Geth_score(double a[14]);//获取最高分
double Getl_score(double a[14]);//获取最低分
double Getdif_score(double a[14]);//获取最大分数差
double Getstd_dev(double a[14]);//获取标准差
void Getranking(double a[14],int b[14]);//获取名次
double *Getmath(stu a[14],double b[14]);//获取数学分数组
double *GetEnglish(stu a[14],double b[14]);//获取英语分数组
double *Getphysics(stu a[14],double b[14]);//获取物理分数组
void subject(sub &a, stu b[14], double c[14]);//完成一个学科内容,c[14]为该学科的分数组

int main()
{
	stu student[14];

	student[0] = {"\0","\0",0,0,0,0 };
	student[1] = {"\0","\0",0,0,0,0 };
	student[2] = {"\0","\0",0,0,0,0 };
	student[3] = {"\0","\0",0,0,0,0 };
	student[4] = {"\0","\0",0,0,0,0 };
	student[5] = {"\0","\0",0,0,0,0 };
	student[6] = {"\0","\0",0,0,0,0 };
	student[7] = {"\0","\0",0,0,0,0 };
	student[8] = {"\0","\0",0,0,0,0 };
	student[9] = {"\0","\0",0,0,0,0 };
	student[10] = {"\0","\0",0,0,0,0 };
	student[11] = {"\0","\0",0,0,0,0 };
	student[12] = {"\0","\0",0,0,0,0 };
	student[13] = {"\0","\0",0,0,0,0 };

	CString str;
	fstream m_flie;//将信息输入到a.txt中
	m_flie.open("a.txt");
	char stud [2000]="\0";
	m_flie >> stud;
	m_flie.close();

	for (int j = 0, i = 6; j < 14 && i < 1541; j++, i += 108)
	{
		for (int k = 0; k < 12; k++)
			student[j].id[k] = stud[i + k];
		student[j].id[11] = '\0';
	}

	for (int j = 0, i = 25; j < 14 && i < 1541; j++, i += 108)
		for (int k = 0; k < 6; k++)
		{
			student[j].name[k] = stud[i + k];
		}

	for (int j = 0, i = 39; j < 14 && i < 1541; j++, i += 108)
	{
		char tem[7] = "\0";
		for (int k = 0; k < 6; k++)
		{
			tem[k] = stud[i + k];
		}
		student[j].major = atof(tem);
	}



	for (int j = 0, i = 57; j < 14 && i < 1541; j++, i += 108)
	{	
		char tem[9] = "\0";
		for (int k = 0; k < 8; k++)
		{
			tem[k] = stud[i + k];
		}
		student[j].math = atof(tem);
	}

	for (int j = 0, i = 78; j < 14 && i < 1541; j++, i += 108)
	{
		char tem[9] = "\0";
		for (int k = 0; k < 8; k++)
		{
			tem[k] = stud[i + k];
		}
		student[j].English = atof(tem);
	}

	for (int j = 0, i = 99; j < 14 && i < 1541; j++, i += 108)
	{
		char tem[9] = "\0";
		for (int k = 0; k < 8; k++)
		{
			tem[k] = stud[i + k];
		}
		student[j].physics = atof(tem);
	}

	sub mpe[3];//三门课程
	mpe[0] = { "数学" };
	mpe[1] = { "物理" };
	mpe[2] = { "英语" };

	double math_a[14], English_a[14], physics_a[14];
	Getmath(student, math_a);
	GetEnglish(student,English_a);
	Getphysics(student,physics_a);
	

	subject(mpe[0], student, math_a);
	subject(mpe[1], student, English_a);
	subject(mpe[2], student, physics_a);



	m_flie.open("b.txt");
	for (int i = 0; i < 3; i++)
	{
		str.Format("%s", mpe[i].sub_name);
		m_flie.write(str.operator LPCSTR(), str.GetLength());
		m_flie << endl;

		str.Format("%lf", mpe[i].average);
		m_flie << "平均分：";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].h_score);
		m_flie << "  最高分：";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].l_score);
		m_flie << "  最低分：";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].dif_socre);
		m_flie << "  最大分数差：";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].std_dev);
		m_flie << "  标准差：";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		m_flie << endl;

		for (int j = 0; j < 14; j++)
		{
			str.Format("%s", mpe[i].id[j]);
			m_flie << "学号：";
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			m_flie << "  姓名：";
			str.Format("%s", mpe[i].name[j]);
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			m_flie << "  分数：";
			str.Format("%lf", mpe[i].mark[j]);
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			str.Format("%d", mpe[i].ranking[j]);
			m_flie << "  名次：";
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			m_flie << endl;

		}
	}

	m_flie.close();

	cout << "请在b.txt文件中查询相关数据" << endl;
	system("pause");
	return 0;
}


double Getaverage(double a[14])
{
	double average = 0, sum = 0;
	for (int i = 0; i < 14; i++)
		sum += a[i];
	average = sum / 14;
	return average;
}

double Geth_score(double a[14])//获取最高分
{
	double tem = a[0];
	for (int i = 0; i < 14; i++)
	{
		if (a[i] > tem)
			tem = a[i];
	}
	return tem;
}

double Getl_score(double a[14])//获取最低分
{
	double tem = a[0];
	for (int i = 0; i < 14; i++)
	{
		if (a[i] < tem)
			tem = a[i];
	}
	return tem;
}

double Getdif_score(double a[14])//获取最大分数差
{
	return Geth_score(a) - Getl_score(a);
}

double Getstd_dev(double a[14])//获取标准差
{
	double average = Getaverage(a);
	double b = 0, s = 0;
	for (int i = 0; i < 14; i++)
	{
		b += (a[i] - average)*(a[i] - average);
	}
	b = b / 14;
	return s = sqrt(b);
}

void Getranking(double a[14],int b[14])//获取名次,数组a中为分数，数组b中为从第一个人到第十四个人的名次
{
	int tem = 1;
	for (int i = 0; i < 14; i++)
	{
		tem = 1;
		for (int j = 0; j < 14; j++)
		{
			if (a[i] < a[j])
				tem++;
			if (j == 13)
				b[i] = tem;
		}
	}
}

double *Getmath(stu a[14], double b[14])//获取数学分数组
{
	for (int i = 0; i < 14; i++)
	{		
		b[i] = a[i].math;
		b[i];
	}
	return b;
}

double *GetEnglish(stu a[14], double b[14])//获取英语分数组
{
	for (int i = 0; i < 14; i++)
		b[i] = a[i].English;
	return b;
}

double *Getphysics(stu a[14], double b[14])//获取物理分数组
{
	for (int i = 0; i < 14; i++)
		b[i] = a[i].physics;
	return b;
}

void subject(sub &a, stu b[14], double c[14])//完成一个学科内容,c[14]为该学科的分数组
{
	for (int i = 0; i < 14; i++)
	{
		strcpy_s(&(a.id[i][0]), 14, b[i].id);
		strcpy_s(&(a.name[i][0]), 8, b[i].name);
	}
	a.average = Getaverage(c);
	a.dif_socre = Getdif_score(c);
	a.h_score = Geth_score(c);
	a.l_score = Getl_score(c);
	Getranking(c, a.ranking);
	a.std_dev = Getstd_dev(c);
	for (int i = 0; i < 14; i++)
	{
		a.mark[i] = c[i];
	}
}