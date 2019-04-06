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
	Number = 0;//������
}

Train_scheduling_problem::~Train_scheduling_problem()
{

}

int Train_scheduling_problem::result(int * RanArrary)//��������
{
	LinkQueue <int>* Queue;//���� Ҳ�ǻ�����
	link_list<LinkQueue<int>*> List;//���� ��¼������

	QString txt;//������ַ���
	int j = 0;//������±�
	int preNum = 1;//��һ��Ӧ�ó���ĳ����
	int m = 0;//�����ж����л��������Ƿ��п��Գ���Ŀ��Ʋ�������m����size�����й����û�п��Գ����
	int size = 0;//��������

	while (j < Number)
	{
		if (RanArrary[j] == preNum)//��ǰ����Ҫ���죬ͬʱ�ж������������еĳ����Ƿ�Ҳ�ܳ���
		{
			txt = QString::number(preNum, 10) + QString::fromLocal8Bit("�ų������");//��ǰ�������
			ui.plainTextEdit->appendPlainText(txt);
			preNum++;
			j++;
			m = 0;
			while (m != size)//��������ĳ����Ƿ����
			{
				m = 0;
				for (int i = 1; i <= size; i++)
				{
					List.Get_Data(i, Queue);
					if (Queue->GetSize() == 0)//��i��������Ϊ��
						m++;
					else
					{
						if (Queue->GetFront() == preNum)//��i���������ĵ�һ������պ���Ҫ�����
						{
							Queue->OutQueue(preNum);
							txt = QString::number(preNum, 10) + QString::fromLocal8Bit("�ų����") + QString::number(i, 10) + QString::fromLocal8Bit("�Ż���������");
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
			if (size == 0)//û�л����� �½�һ��������
			{
				Queue = new LinkQueue<int>(RanArrary[j]);
				List.Append(Queue);
				size = List.Length();
				txt = QString::number(RanArrary[j], 10) + QString::fromLocal8Bit("�ų������") + QString::number(size, 10) + QString::fromLocal8Bit("�Ż�����");
				ui.plainTextEdit->appendPlainText(txt);
				j++;
			}
			else
			{
				for (int i = 1; i <= size; i++)//��ǰ�ĳ���Ҫ���뻺����
				{
					List.Get_Data(i, Queue);
					if (Queue->GetSize() == 0 || RanArrary[j] > Queue->GetTail())//������ڶ������һ�������ԭ�еĹ�����棬���߶���Ϊ��
					{
						Queue->InQueue(RanArrary[j]);
						size = List.Length();
						txt = QString::number(RanArrary[j], 10) + QString::fromLocal8Bit("�ų������") + QString::number(size, 10) + QString::fromLocal8Bit("�Ż�����");
						ui.plainTextEdit->appendPlainText(txt);
						j++;
						break;
					}
					if (i == size)//Ҫ����ĳ����С�����л����������һ�����½�һ�����
					{
						Queue = new LinkQueue<int>(RanArrary[j]);
						List.Append(Queue);
						size = List.Length();
						txt = QString::number(RanArrary[j], 10) + QString::fromLocal8Bit("�ų������") + QString::number(size, 10) + QString::fromLocal8Bit("�Ż�����");
						ui.plainTextEdit->appendPlainText(txt);
						j++;
						break;
					}
				}
			}
		}
	}

	txt = QString::fromLocal8Bit("����") + QString::number(size, 10) + QString::fromLocal8Bit("��������");
	ui.plainTextEdit->appendPlainText(txt);

	return 0;
}

bool Train_scheduling_problem::OnOKBtn2()//��������
{
	ui.plainTextEdit->setPlainText("");
	QString train = ui.textEdit_2->toPlainText();
	QString temp;
	LinkQueue<QString> Array;
	int length = train.length();
	int locat = 0;
	while (locat != length)//����������ִ浽�����У��м���������Ÿ���
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

	if (Array.GetSize()==0)//û������
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("������������"));
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
			if (RanArrary[i] <= 0)//����������ִ浽һ��int��������
			{
				//С��0�;���
				QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("������������,С��1"));
				return false;
			}
		}

		int m = 1, n = 0;
		while (m != Number + 1)//�ж������Ƿ���1��n������
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
		if (m == n)//���������warning 
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����������󣬳���������1��") + QString::number(Number, 10) + QString::fromLocal8Bit("������"));
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
	if (Number <= 0)                //�쳣���봦��
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ĳ���������"));
		return false;
	}
	else
	{
		int *RanArrary = new int[Number];           
		for (int i = 0; i < Number; i++)
			RanArrary[i] = i + 1;
		srand(time(NULL));
		int tempone, temptwo;
		for (int i = 0; i < Number; i++)         //�����������
		{
			tempone = RanArrary[i];
			temptwo = rand() % Number;
			RanArrary[i] = RanArrary[temptwo];
			RanArrary[temptwo] = tempone;
		}
		
		QString RanArr;                        //��ʾ�������
		for (int i = 0; i < Number; i++)
			RanArr = RanArr + QString::number(RanArrary[i], 10) + " ";
		ui.textEdit->setText(RanArr);

		result(RanArrary);

		delete[] RanArrary;
		return true;
	}
}

