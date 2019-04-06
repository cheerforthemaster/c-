#include "factorial_of_large_numbers.h"
#include "link_list.h"
#include <QMessageBox>
#include <fstream>
using namespace std;

int factorial(int n);

Factorial_of_large_numbers::Factorial_of_large_numbers(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnShow()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnBtnCal()));
}

Factorial_of_large_numbers::~Factorial_of_large_numbers()
{

}

int Factorial_of_large_numbers::OnBtnShow()
{
	fstream file;
	file.open("output.txt",ios::in);
	file.seekg(0, ios::end);
	int i = file.tellg();
	char* txt = new char[i+1];
	for (int j=0;j<i;j++)
	{
		txt[i] = '\0';
	}
	file.seekg(0, ios::beg);
	file.read(txt, i);
	//QString str =(QString(QLatin1String(txt)));
	QString str;
	str = QString::fromLocal8Bit(txt);
	ui.textEdit->setPlainText(str);
	delete []txt;

	return 0;
}

int Factorial_of_large_numbers::OnBtnCal()
{
	QString str = ui.lineEdit->text();
	int num = str.toInt();
	if (num==0)
	{
		QMessageBox::warning(this,QString::fromLocal8Bit("输入有误"),QString::fromLocal8Bit("请输入正整数！") );
		return 0;
	}
	else
	{
		number=factorial(num);
		QMessageBox::information(this, QString::fromLocal8Bit("成功"), QString::fromLocal8Bit("计算成功！"));

	}
	str = QString::number(number, 10);
	ui.lineEdit_2->setText(str);
	return 0;
}

int factorial(int n)
{
	link_list<int> LIST;
	int tem = 1;
	int CarryFlag = 0;
	int size = 0;
	int tem_size = 0;
	int i;
	if (n < 7)
	{
		for (i = 1; i <= n; i++)
		{
			tem = tem*i;
		}
		LIST.Append(tem);
		size++;
		LIST.Reverse();
		LIST.output();
		return 0;
	}
	else
	{
		tem = 1 * 2 * 3 * 4 * 5 * 6;
		i = 6;
		size++;
		LIST.Append(tem);
	}
	while (i < n)
	{
		i++;
		CarryFlag = 0;
		tem_size = size;
		for (int j = 1; j <= tem_size; j++)
		{
			LIST.Get_Data(j, tem);
			tem = tem*i + CarryFlag;
			if (tem <= 999)
			{
				LIST.Set_Data(tem);
				CarryFlag = 0;
			}
			else
			{
				CarryFlag = tem / 1000;
				tem = tem % 1000;
				LIST.Set_Data(tem);
			}
			if (j == tem_size)
			{
				while (CarryFlag != 0)
				{
					tem = CarryFlag % 1000;
					LIST.Append(tem);
					size++;
					CarryFlag = CarryFlag / 1000;
				}
			}
		}
	}
	LIST.Reverse();
	LIST.output();
	return LIST.Length();
}