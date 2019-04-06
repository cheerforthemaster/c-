#include "train_scheduling_problem.h"
#include <QMessageBox>
#include "LinkQueue.h"
#include "time.h"
#include "link_list.h"

Train_scheduling_problem::Train_scheduling_problem(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.OKButton, SIGNAL(clicked()), this, SLOT(OnOKBtn()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), ui.OKButton, SIGNAL(clicked())/*, Qt::UniqueConnection*/);
	connect(ui.OKButton2, SIGNAL(clicked()),this,SLOT(OnOKBtn2()));
	Number = 0;//车厢数
}

Train_scheduling_problem::~Train_scheduling_problem()
{

}

int Train_scheduling_problem::result(int * RanArrary)//处理数组
{
	LinkQueue <int>* Queue;//队列 也是缓冲轨道
	link_list<LinkQueue<int>*> List;//链表 记录缓冲轨道

	QString txt;//输出的字符串
	int j = 0;//数组的下标
	int preNum = 1;//下一个应该出轨的车厢号
	int m = 0;//用于判段所有缓冲轨道中是否有可以出轨的控制参数，若m等于size则所有轨道都没有可以出轨的
	int size = 0;//缓冲轨道数

	while (j < Number)
	{
		if (RanArrary[j] == preNum)//当前车厢要出轨，同时判断其他缓冲轨道中的车厢是否也能出轨
		{
			txt = QString::number(preNum, 10) + QString::fromLocal8Bit("号车厢出轨");//当前车厢出轨
			ui.plainTextEdit->appendPlainText(txt);
			preNum++;
			j++;
			m = 0;
			while (m != size)//其他轨道的车厢是否出轨
			{
				m = 0;
				for (int i = 1; i <= size; i++)
				{
					List.Get_Data(i, Queue);
					if (Queue->GetSize() == 0)//第i个缓冲轨道为空
						m++;
					else
					{
						if (Queue->GetFront() == preNum)//第i个缓冲轨道的第一个车厢刚好是要出轨的
						{
							Queue->OutQueue(preNum);
							txt = QString::number(preNum, 10) + QString::fromLocal8Bit("号车厢从") + QString::number(i, 10) + QString::fromLocal8Bit("号缓冲轨道出轨");
							ui.plainTextEdit->appendPlainText(txt);
							preNum++;
						}
						else
							m++;
					}
				}
			}
		}
		else
		{
			if (size == 0)//没有缓冲轨道 新建一个缓冲轨道
			{
				Queue = new LinkQueue<int>(RanArrary[j]);
				List.Append(Queue);
				size = List.Length();
				txt = QString::number(RanArrary[j], 10) + QString::fromLocal8Bit("号车厢进入") + QString::number(size, 10) + QString::fromLocal8Bit("号缓冲轨道");
				ui.plainTextEdit->appendPlainText(txt);
				j++;
			}
			else
			{
				for (int i = 1; i <= size; i++)//当前的车厢要进入缓冲轨道
				{
					List.Get_Data(i, Queue);
					if (Queue->GetSize() == 0 || RanArrary[j] > Queue->GetTail())//车厢大于队列最后一个则加在原有的轨道后面，或者队列为空
					{
						Queue->InQueue(RanArrary[j]);
						size = List.Length();
						txt = QString::number(RanArrary[j], 10) + QString::fromLocal8Bit("号车厢进入") + QString::number(size, 10) + QString::fromLocal8Bit("号缓冲轨道");
						ui.plainTextEdit->appendPlainText(txt);
						j++;
						break;
					}
					if (i == size)//要进入的车厢号小于所有缓冲轨道的最后一个则新建一个轨道
					{
						Queue = new LinkQueue<int>(RanArrary[j]);
						List.Append(Queue);
						size = List.Length();
						txt = QString::number(RanArrary[j], 10) + QString::fromLocal8Bit("号车厢进入") + QString::number(size, 10) + QString::fromLocal8Bit("号缓冲轨道");
						ui.plainTextEdit->appendPlainText(txt);
						j++;
						break;
					}
				}
			}
		}
	}

	txt = QString::fromLocal8Bit("共用") + QString::number(size, 10) + QString::fromLocal8Bit("条缓冲轨道");
	ui.plainTextEdit->appendPlainText(txt);

	return 0;
}

bool Train_scheduling_problem::OnOKBtn2()//输入序列
{
	ui.plainTextEdit->setPlainText("");
	QString train = ui.textEdit_2->toPlainText();
	QString temp;
	LinkQueue<QString> Array;
	int length = train.length();
	int locat = 0;
	while (locat != length)//将输入的数字存到队列中，中间以任意符号隔开
	{
		if (train.at(locat) >= '0' && train.at(locat) <= '9')
		{
			temp += train.at(locat);
			locat++;
		}
		else
		{
			if (temp.length()!=0)
			{
				Array.InQueue(temp);
				temp.clear();
				locat++;
			}
			else
				locat++;
		}
	}
	Array.InQueue(temp);

	if (Array.GetSize()==0)//没有数字
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("输入数据有误"));
		return false;
	}
	else
	{
		Number = Array.GetSize();
		int *RanArrary = new int[Number];
		for (int i = 0; i < Number; i++)
		{
			Array.OutQueue(temp);
			RanArrary[i] = temp.toInt();
			if (RanArrary[i] <= 0)//将输入的数字存到一个int型数组中
			{
				//小于0就警告
				QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("输入数据有误,小于1"));
				return false;
			}
		}

		int m = 1, n = 0;
		while (m != Number + 1)//判断数列是否是1到n的数列
		{
			for (int i = 0; i < Number; i++)
			{
				if (RanArrary[i] == m)
					m++;
			}
			n++;
			if (m == n)
				break;
		}
		if (m == n)//如果不是则爆warning 
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("输入数据有误，车厢数不是1到") + QString::number(Number, 10) + QString::fromLocal8Bit("的序列"));
			return false;
		}
		result(RanArrary);
	}
	return true;
}

bool Train_scheduling_problem::OnOKBtn()
{
	ui.plainTextEdit->setPlainText("");
	QString NumTrain;
	NumTrain = ui.lineEdit->text();
	Number = NumTrain.toInt();
	if (Number <= 0)                //异常输入处理
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("输入的车厢数有误"));
		return false;
	}
	else
	{
		int *RanArrary = new int[Number];           
		for (int i = 0; i < Number; i++)
			RanArrary[i] = i + 1;
		srand(time(NULL));
		int tempone, temptwo;
		for (int i = 0; i < Number; i++)         //生成随机数组
		{
			tempone = RanArrary[i];
			temptwo = rand() % Number;
			RanArrary[i] = RanArrary[temptwo];
			RanArrary[temptwo] = tempone;
		}
		
		QString RanArr;                        //显示随机数组
		for (int i = 0; i < Number; i++)
			RanArr = RanArr + QString::number(RanArrary[i], 10) + " ";
		ui.textEdit->setText(RanArr);

		result(RanArrary);

		delete[] RanArrary;
		return true;
	}
}

