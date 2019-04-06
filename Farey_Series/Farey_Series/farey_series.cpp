#include "farey_series.h"
#include <QMessageBox>
#include "link_list.h"

int sequence(int n);

Farey_Series::Farey_Series(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnOk()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnBtnShow()));
}

Farey_Series::~Farey_Series()
{

}

int Farey_Series::OnBtnOk()
{
	QString str;
	str = ui.lineEdit->text();
	int num = str.toInt();
	if (num==0)
	{
		QMessageBox::warning(this,QString::fromLocal8Bit("输入有误"),QString::fromLocal8Bit("请输入正整数"));
		return 0;
	}
	sequence(num);
	QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("计算完成"));
	return 0;
}


int Farey_Series::OnBtnShow()
{
	fstream file;
	file.open("output.txt", ios::in);
	file.seekg(0, ios::end);
	int i = file.tellg();
	char* txt = new char[i+1];
	if (txt==NULL)
	{
		return 0;
	}
	for (int j = 0; j < i; j++)
	{
		txt[i] = '\0';
	}
	file.seekg(0, ios::beg);
	file.read(txt, i);
	QString str;
	str = QString::fromLocal8Bit(txt);
	ui.plainTextEdit->setPlainText(str);
	delete[]txt;
	return 0;
}


int sequence(int n)
{
	link_list<int> denominator(1); //分母
	denominator.Append(1);

	link_list<int> molecule(0); //分子
	molecule.Append(1);

	int judget = 0;
	int size = 0;
	int de = 0, mo = 0;
	while (1)
	{
		size = denominator.Length();
		for (int i = 1; i < size; i++)
		{
			judget = denominator.Milddle_Insert(i, n, de);
			if (judget == 1)
			{
				molecule.Milddle_Insert(i, n, mo);

			}
			else
			{
				if (judget == 0)
					molecule.move_follow();
				else
				{
					if (judget == 2)
						break;
				}
			}
		}
		if (judget == 2)
			break;
	}

	fstream file("output.txt", ios::out);
	if (!file.good())
	{
		return 0;
	}
	size = molecule.Length();
	for (int i = 1; i <= size; i++)
	{
		file << molecule.only_output(i) << "/" << denominator.only_output(i) << " ";
	}
	file.close();


	return 0;
}
