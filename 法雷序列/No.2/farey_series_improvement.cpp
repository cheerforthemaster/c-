#include "farey_series_improvement.h"
#include <fstream>
#include "list_link.h"
#include <QMessageBox>

using namespace std;

Farey_Series_Improvement::Farey_Series_Improvement(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnCalculate()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnBtnShow()));
}

Farey_Series_Improvement::~Farey_Series_Improvement()
{

}

int Farey_Series_Improvement::OnBtnShow()
{
	fstream file;
	file.open("output.txt", ios::in);
	file.seekg(0, ios::end);
	int i = file.tellg();
	char* txt = new char[i + 1];
	if (txt == NULL)
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

int Farey_Series_Improvement::OnBtnCalculate()
{
	QString str;
	str = ui.lineEdit->text();
	int num = str.toInt();
	if (num == 0)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("输入有误"), QString::fromLocal8Bit("请输入正整数"));
		return 0;
	}

	link_list<int> link;
	link.Fraction(num);
	link.output();
	QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("计算完成"));
	int len = link.Length();

	str = QString::number(len, 10);
	ui.lineEdit_2->setText(str);




	return 0;
}