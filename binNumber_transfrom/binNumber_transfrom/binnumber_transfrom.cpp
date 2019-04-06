#include "binnumber_transfrom.h"

binNumber_transfrom::binNumber_transfrom(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnOKBtn()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), ui.pushButton, SIGNAL(clicked()));
}

binNumber_transfrom::~binNumber_transfrom()
{

}

bool binNumber_transfrom::OnOKBtn()//������Ƕ�������;
{
	Num = ui.lineEdit->text();
	if (Num.isEmpty())
	{
		QMessageBox::warning(this, "error", "there is nothing!");
		return false;
	}
	int length = Num.length();
	QChar temporary;
	for (int i = 0; i < length; i++)
	{
		temporary = Num.at(i);
		if (Num.at(i) != '0' && Num.at(i) != '1' && length != 32)
		{
			QMessageBox::warning(this, "error", "this isn't a binary number of thirty-two bits!");
			return false;
		}
	}

	int orderNum = 0;//����;
	double Mantissa = 1;//β��;
	bool IsNegative = false;//������־λ;
	double finalNum = 0;

	if (Num.at(0) == '1')//�Ƿ�Ϊ����;
		IsNegative = true;
	else
		IsNegative = false;


	for (int i = 8; i >= 1; i--)//��λ������ֵ;
	{
		if (Num.at(i) == '1')
			orderNum += pow(2, 8 - i);
	}
	orderNum = orderNum - 127;//ƫ����;

	for (int j = -1, i = 9; j > -23, i < 32; j--, i++)
	{
		if (Num.at(i) == '1')
			Mantissa = Mantissa + pow(2, j);
	}

	finalNum = Mantissa*pow(2, orderNum);
	if (IsNegative)
		finalNum = 0 - finalNum;

	ui.textEdit->setText(QString::number(finalNum, 10, 15));
	return true;
}
