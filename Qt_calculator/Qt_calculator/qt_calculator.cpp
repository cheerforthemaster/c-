#include "qt_calculator.h"
#include <QMessageBox>
#include "stack.h"
#include <QKeyEvent>

bool calculator(QString &tem);

Expression_evaluation::Expression_evaluation(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//QStringList list = {
	//	"12,"
	//}
	//for (int i=0;i<20;i++)
	//{
	//	QPushButton * n = new QPushButton(this);
	//
	//	connect(n, &QPushButton::clicked(), [=]() {
	//		QString str += QString::number(10,i);
	//	})
	//}
// 	this->installEventFilter(this);
	connect(ui.pushButton_0, SIGNAL(clicked()), this, SLOT(OnBtn0()));
	connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(OnBtn1()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnBtn2()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(OnBtn3()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(OnBtn4()));
	connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(OnBtn5()));
	connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(OnBtn6()));
	connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(OnBtn7()));
	connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(OnBtn8()));
	connect(ui.pushButton_9, SIGNAL(clicked()), this, SLOT(OnBtn9()));
	connect(ui.pushButton_10, SIGNAL(clicked()), this, SLOT(OnBtn10()));
	connect(ui.pushButton_11, SIGNAL(clicked()), this, SLOT(OnBtn11()));
	connect(ui.pushButton_12, SIGNAL(clicked()), this, SLOT(OnBtn12()));
	connect(ui.pushButton_13, SIGNAL(clicked()), this, SLOT(OnBtn13()));
	connect(ui.pushButton_14, SIGNAL(clicked()), this, SLOT(OnBtn14()));
	connect(ui.pushButton_15, SIGNAL(clicked()), this, SLOT(OnBtn15()));
	connect(ui.pushButton_16, SIGNAL(clicked()), this, SLOT(OnBtn16()));
	connect(ui.pushButton_17, SIGNAL(clicked()), this, SLOT(OnBtn17()));
	connect(ui.pushButton_18, SIGNAL(clicked()), this, SLOT(OnBtn18()));
	connect(ui.pushButton_19, SIGNAL(clicked()), this, SLOT(OnBtn19()));

	//clicked();

	Point = 0;//����С����Ĳ���
	Operator = 1;//����������Ĳ���
	brackets = 0;//����������

}

Expression_evaluation::~Expression_evaluation()
{

}

void Expression_evaluation::keyPressEvent(QKeyEvent *event)
{
	switch (event->key())
	{
	case Qt::Key_0:
	{
		OnBtn0();
		break;
	}
	case Qt::Key_1:
	{
		OnBtn1();
		break;
	}
	case Qt::Key_2:
	{
		OnBtn2();
		break;
	}
	case Qt::Key_3:
	{
		OnBtn3();
		break;
	}
	case Qt::Key_4:
	{
		OnBtn4();
		break;
	}
	case Qt::Key_5:
	{
		OnBtn5();
		break;
	}
	case Qt::Key_6:
	{
		OnBtn6();
		break;
	}
	case Qt::Key_7:
	{
		OnBtn7();
		break;
	}
	case Qt::Key_8:
	{
		OnBtn8();
		break;
	}
	case Qt::Key_9:
	{
		OnBtn9();
		break;
	}
	case Qt::Key_Backspace: //  delet  <-
	{
		OnBtn16();
		break;
	}
	case Qt::Key_Return:  // = �س�
	{
		OnBtn19();
		break;
	}
	case 0x28://  ( 
	{
		OnBtn17();
		break;
	}
	case 0x29://  )
	{
		OnBtn18();
		break;
	}
	case 0x2a://  *
	{
		OnBtn14();
		break;
	}
	case 0x2b://  +
	{
		OnBtn12();
		break;
	}
	case 0x2d:// - 
	{
		OnBtn13();
		break;
	}
	case 0x2f:// /
	{
		OnBtn15();
		break;
	}
	case 0x2e:// .
	{
		OnBtn11();
		break;
	}

	default: return;
	}



}

// void Expression_evaluation::eventFilter(QObject * watched, QEvent * event)
// {
// 	event->type()==QEvent::KeyPress
// }
// 


int Expression_evaluation::OnBtn0()//���� 0   ��������ͬע��
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")//��߲���Ϊ ��
			return 0;
// 		if (str_result.at(str_result.length() - 1) == "/")//��߲���Ϊ /
// 		{
// 			QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������Ϊ0��"));
// 			return 0;
// 		}
	}
	str_result = str_result + "0";
	Operator = 0;                                    //���������Լ������
	ui.lineEdit->setText(str_result);
	return 0;
}


int Expression_evaluation::OnBtn1()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "1";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn2()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "2";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn3()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "3";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn4()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "4";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn5()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "5";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn6()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "6";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn7()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "7";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn8()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "8";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn9()
{
	if (str_result.length() != 0)
	{
		if (str_result.at(str_result.length() - 1) == ")")
			return 0;
	}
	str_result = str_result + "9";
	Operator = 0;
	ui.lineEdit->setText(str_result);

	return 0;
}

int Expression_evaluation::OnBtn10()      //  +/-
{
	if (str_result.length() == 0)//û�ж���
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	QChar qch = str_result.at(0);
	if (qch=="-") //��һ���ַ�Ϊ����
	{
		str_result = str_result.mid(1);//��ȡ��һ���ַ�֮����ַ���
	}
	else 
	{
		str_result = "-" + str_result;
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn11()   //  .
{
	if (str_result.length() == 0)//û���ַ�
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	if (Point == 0 && Operator == 0) //���һλ��������� �����һ����������û��С����
	{
		str_result = str_result + ".";
		ui.lineEdit->setText(str_result);
		Point = 1;
		Operator = 1;
		return 0;
	}
	else
	{
		return 0;
	}
}
 
int Expression_evaluation::OnBtn12()    //�ӷ�
{
	if (str_result.length() == 0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	if (str_result.at(str_result.length() - 1) == "(")// �� �������� ���Ϊ �� 0 +    �˴�ģ��΢�������������
	{
		OnBtn0();
		OnBtn12();
	}
	if (Point == 1 && Operator == 1)//���һλ��С����
	{
		return 0;
	} 
	else
	{
		if (Operator == 1)//���һλ�������
		{
			return 0;
		}
		str_result = str_result + "+";
		Operator = 1;
		Point = 0;
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn13()    //����
{
	if (str_result.length() == 0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	if (str_result.at(str_result.length() - 1) == "(")
	{
		OnBtn0();
		OnBtn13();
	}
	if (Point == 1 && Operator == 1)//���һλ��С����
	{
		return 0;
	}
	else
	{
		if (Operator==1)//���һλ�������
		{
			return 0;
		}
		str_result = str_result + "-";
		Operator = 1;
		Point = 0;
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn14()  //�˷�
{
	if (str_result.length() == 0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	if (str_result.at(str_result.length() - 1) == "(")
	{
		OnBtn0();
		OnBtn14();
	}
	if (Point == 1 && Operator == 1)//���һλ��С����
	{
		return 0;
	}
	else
	{
		if (Operator == 1)//���һλ�������
		{
			return 0;
		}
		str_result = str_result + "*";
		Operator = 1;
		Point = 0;
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn15()   //����
{
	if (str_result.length() == 0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	if (str_result.at(str_result.length() - 1) == "(")
	{
		OnBtn0();
		OnBtn15();
	}
	if (Point == 1 && Operator == 1)//���һλ��С����
	{
		return 0;
	}
	else
	{
		if (Operator == 1)//���һλ�������
		{
			return 0;
		}
		str_result = str_result + "/";
		Operator = 1;
		Point = 0;
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn16()   // delete
{
	if (str_result.length() == 0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	int size = str_result.length();
	if (size==0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	QChar cha = str_result.at(size - 1);
	if (size==1) //ֻ��һ���ַ�
	{
		if (cha == "(")
		{
			str_result.chop(1);
			brackets--;
		}
		else
			str_result.chop(1);

	}
	else
	{
		QChar lastcha= str_result.at(size - 2);
		if (cha=="+"||cha=="-"|| cha == "*"|| cha == "/")  //ɾ�����������
		{
			str_result.chop(1);
			Operator = 0;
		}
		if (cha == "0" || cha == "1" || cha == "2" ||
			cha == "3" || cha == "4" || cha == "5" ||
			cha == "6" || cha == "7" || cha == "8" || cha == "9") //ɾ����������
		{
			if (lastcha == "+" || lastcha == "-" ||
				lastcha == "*" || lastcha == "/") //ɾ�������ֵ�ǰһ���������
			{
				str_result.chop(1);
				Operator = 1;
			}
			else if (lastcha == ".")//ǰһ����С����
			{
				str_result.chop(1);
				Point = 1;
				Operator = 1;
			}
			else
				str_result.chop(1);
		}
		if (cha==".")//ɾ����С����
		{
			str_result.chop(1);
			Point = 0;
			Operator = 0;
		}
		if (cha=="(")
		{
			str_result.chop(1);
			brackets--;
		}
		if (cha==")")
		{
			str_result.chop(1);
			brackets++;
		}
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn17()  //   )
{
	if (str_result.length() == 0)
	{
		ui.lineEdit->setText(str_result);
		return 0;
	}
	if (str_result.at(str_result.length() - 1) == "(")
	{
		return 0;
	}
	if (Operator == 0 && brackets > 0)//�����������ֺͷ���֮�� ��ǰ����������
	{
		str_result = str_result + ")";
		brackets--;
		Point = 1;//�����ź�����С����
	}
	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn18()   // (
{
	if (str_result.length()==0) //��ͷ������
	{
		str_result = str_result + "(";
		brackets++;
	}
	else if (Point==0&&Operator==1)//�������ڷ��ź�����֮��
	{
		str_result = str_result + "(";
		brackets++;
	}
	else if(str_result.at(str_result.length()-1)=="(") 
	{
		str_result = str_result + "(";
		brackets++;
	}


	ui.lineEdit->setText(str_result);
	return 0;
}

int Expression_evaluation::OnBtn19()   // = 
{
	if (str_result.length()==0)
	{
		return 0;
	}
	QChar cha = str_result.at(str_result.length() - 1);
	if (cha == ".")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("С�����û��ȫ��"));
		return 0;
	}
	if (brackets!=0)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("���������ţ�"));
		return 0;
	}
	if (cha == "+" || cha == "-" || cha == "*" || cha == "/")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�������û��ȫ��"));
		return 0;
	}

	calculator(str_result);
	ui.lineEdit->setText(str_result);
	str_result = "";
	return 0;
}

bool Expression_evaluation::calculator(QString & tem)
{
	int size = tem.length();
	QString cha, temcha;//�����ַ�
	QString temstring;//����
	Stack<QString> sta_oper;//����
	Stack<QString> sta_fin;//���ź�����
	if (tem.at(0)=="-")  //��ͷΪ���ţ����Ϊ0- 
	{
		tem = "0" + tem;
	}
	for (int i=0;i<size;i++)
	{
		cha = tem.at(i);
		if (cha == "+" || cha == "-" || cha == "*" || cha == "/"||cha=="(")
		{
			if (temstring != "")
			{
				sta_fin.push(temstring);
				temstring = "";
			}

			if (cha == "+" || cha == "-")
			{
				temcha = sta_oper.GetTop();
				while (temcha == "*" || temcha == "/")
				{
					sta_oper.pop(temcha);
					sta_fin.push(temcha);
					temcha = sta_oper.GetTop();
				}
				sta_oper.push(cha);
			}
			else
				sta_oper.push(cha);
		}
		if (cha == "0" || cha == "1" || cha == "2" ||
			cha == "3" || cha == "4" || cha == "5" ||
			cha == "6" || cha == "7" || cha == "8" ||
			cha == "9" || cha == ".")
		{
			temstring = temstring + cha;
		}
		if (cha==")")
		{
			sta_fin.push(temstring);
			temstring = "";
			while (1)
			{
				sta_oper.pop(cha);
				if (cha == "(")
					break;
				sta_fin.push(cha);
			}
		}
		if (i==size-1)
		{
			if (temstring!="")
			{
				sta_fin.push(temstring);
			}
			while (!sta_oper.IsEmpty())
			{
				sta_oper.pop(cha);
				sta_fin.push(cha);
			}
		}
	}

	size = sta_fin.gettop();
	tem = "";
	for (int i = 0; i <= size; i++)
	{
		sta_fin.pop(temstring);
		tem = temstring + tem;
		sta_oper.push(temstring);
	}

	double *one = new double[size + 1];
	int j = -1;
	for (int i = 0; i <= size; i++)
	{
		sta_oper.pop(temstring);
		cha = "";
		temcha = "";
		if (temstring=="+"|| temstring == "-" || temstring == "*" || temstring == "/" )
		{
			if (temstring == "+")
			{
				one[j-1] = one[j] + one[j-1];
				j--;
			}			
			if (temstring == "-")
			{
				one[j - 1] = one[j - 1] - one[j];
				j--;
			}
			if (temstring == "*")
			{
				one[j-1] = one[j] * one[j - 1];
				j--;
			}
			if (temstring == "/")
			{
				if (one[j] == 0)
				{
					QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������Ϊ0��"));
					tem.clear();
					delete[]one;
					return false;
				}
				one[j - 1] = one[j - 1] / one[j];
				j--;
			}
		}
		else
		{
			j++;
			one[j] = temstring.toDouble();
		}
	}
	tem = QString::number(one[0], 10, 4);
	delete[]one;
	return true;
}
