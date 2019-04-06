#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <atlstr.h>
using namespace std;

struct stu
{
	char id[12];//ѧ��ѧ��
	char name[7];//ѧ������
	double major;//רҵ 
	double math;
	double English;
	double physics;
};

struct sub
{
	char sub_name[5];//ѧ������
	char id[14][14];//ѧ��ѧ��
	char name[14][7];//ѧ������
	double average;//ƽ����
	double h_score;//��߷�
	double l_score;//��ͷ�
	double dif_socre;//��������
	double std_dev;//��׼��
	int ranking[14];//����
	double mark[14];//������
};

double Getaverage(double a[14]);//��ȡƽ����
double Geth_score(double a[14]);//��ȡ��߷�
double Getl_score(double a[14]);//��ȡ��ͷ�
double Getdif_score(double a[14]);//��ȡ��������
double Getstd_dev(double a[14]);//��ȡ��׼��
void Getranking(double a[14],int b[14]);//��ȡ����
double *Getmath(stu a[14],double b[14]);//��ȡ��ѧ������
double *GetEnglish(stu a[14],double b[14]);//��ȡӢ�������
double *Getphysics(stu a[14],double b[14]);//��ȡ���������
void subject(sub &a, stu b[14], double c[14]);//���һ��ѧ������,c[14]Ϊ��ѧ�Ƶķ�����

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
	fstream m_flie;//����Ϣ���뵽a.txt��
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

	sub mpe[3];//���ſγ�
	mpe[0] = { "��ѧ" };
	mpe[1] = { "����" };
	mpe[2] = { "Ӣ��" };

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
		m_flie << "ƽ���֣�";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].h_score);
		m_flie << "  ��߷֣�";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].l_score);
		m_flie << "  ��ͷ֣�";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].dif_socre);
		m_flie << "  �������";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		str.Format("%lf", mpe[i].std_dev);
		m_flie << "  ��׼�";
		m_flie.write(str.operator LPCSTR(), str.GetLength());

		m_flie << endl;

		for (int j = 0; j < 14; j++)
		{
			str.Format("%s", mpe[i].id[j]);
			m_flie << "ѧ�ţ�";
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			m_flie << "  ������";
			str.Format("%s", mpe[i].name[j]);
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			m_flie << "  ������";
			str.Format("%lf", mpe[i].mark[j]);
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			str.Format("%d", mpe[i].ranking[j]);
			m_flie << "  ���Σ�";
			m_flie.write(str.operator LPCSTR(), str.GetLength());

			m_flie << endl;

		}
	}

	m_flie.close();

	cout << "����b.txt�ļ��в�ѯ�������" << endl;
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

double Geth_score(double a[14])//��ȡ��߷�
{
	double tem = a[0];
	for (int i = 0; i < 14; i++)
	{
		if (a[i] > tem)
			tem = a[i];
	}
	return tem;
}

double Getl_score(double a[14])//��ȡ��ͷ�
{
	double tem = a[0];
	for (int i = 0; i < 14; i++)
	{
		if (a[i] < tem)
			tem = a[i];
	}
	return tem;
}

double Getdif_score(double a[14])//��ȡ��������
{
	return Geth_score(a) - Getl_score(a);
}

double Getstd_dev(double a[14])//��ȡ��׼��
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

void Getranking(double a[14],int b[14])//��ȡ����,����a��Ϊ����������b��Ϊ�ӵ�һ���˵���ʮ�ĸ��˵�����
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

double *Getmath(stu a[14], double b[14])//��ȡ��ѧ������
{
	for (int i = 0; i < 14; i++)
	{		
		b[i] = a[i].math;
		b[i];
	}
	return b;
}

double *GetEnglish(stu a[14], double b[14])//��ȡӢ�������
{
	for (int i = 0; i < 14; i++)
		b[i] = a[i].English;
	return b;
}

double *Getphysics(stu a[14], double b[14])//��ȡ���������
{
	for (int i = 0; i < 14; i++)
		b[i] = a[i].physics;
	return b;
}

void subject(sub &a, stu b[14], double c[14])//���һ��ѧ������,c[14]Ϊ��ѧ�Ƶķ�����
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