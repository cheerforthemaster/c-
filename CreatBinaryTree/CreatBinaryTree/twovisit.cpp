#include "twovisit.h"

twovisit::twovisit(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnCreat()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnBtnClose()));
}

twovisit::~twovisit()
{
}

bool twovisit::GetDiaqueue(LinkQueue<QString> &tree)
{
	QString tem;
	if (diaQueue.GetSize() == 0)
	{
		queue = &tree;
		return false;
	}
	while (diaQueue.GetSize() != 0)
	{
		tem = diaQueue.OutQueue();
		tree.InQueue(tem);
	}
	return diaQueue.GetSize() == 0;
}

// int devideIn(QString tempo, link_list<QString> intempo, int size, LinkQueue<link_list<QString>> &instorage);
// int devidepre(link_list<QString> pretempo, int preNodeNum, int presentLen, LinkQueue<link_list<QString>> &prestorage);


bool twovisit::OnBtnClose()
{
	reject();
	return false;
}


bool twovisit::OnBtnCreat()
{
	QString preTempo = ui.lineEdit->text(), inTempo = ui.lineEdit_2->text();
	QString tempo;
	int preNodeNum = preTempo.length(), inNodeNum = inTempo.length();
	//非法输入的过滤;
	if (preTempo == 0 || inNodeNum == 0)//两者中任意一个为空;
		return false;
	preNodeNum = 0;
	inNodeNum = 0;
	for (int i = 0; i < preTempo.length(); i++)
	{
		if (preTempo.at(i) != ' ')
			preNodeNum++;
	}
	for (int i = 0; i < inTempo.length(); i++)
	{
		if (inTempo.at(i) != ' ')
			inNodeNum++;
	}
	if (preTempo == 0 || inNodeNum == 0 || preNodeNum != inNodeNum)//将两个序列以空格为间隔符，其他字符个数是否不为0，且相等;
		return false;
	 
	link_list<QString> *pretempo = new link_list<QString>, *intempo = new link_list<QString>;//将两个序列中以空格为间隔符分割后存入两个链表;
	preTempo += " ";
	inTempo += " ";
	for (int i = 0, j = 0; i < preTempo.length(); i++)
	{
		if (preTempo.at(i) != ' ')
			tempo += preTempo.at(i);
		else
			if (tempo != "")
			{
				pretempo->Append(tempo);
				tempo.clear();
			}
	}
	for (int i = 0; i < inTempo.length(); i++)
	{
		if (inTempo.at(i) != ' ')
			tempo += inTempo.at(i);
		else
			if (tempo != "")
			{
				intempo->Append(tempo);
				tempo.clear();
			}
	}

	bool compare = 0;
	for (int i = 1; i <= preNodeNum; i++)
	{
		for (int j = 1; j <= inNodeNum; j++)
		{
			if (pretempo->getData(i) == intempo->getData(j))
			{
				compare = 1;
				break;
			}
		}
		if (compare != 1)
			return false;
	}

	LinkQueue<link_list<QString>*> prestorage, instorage;
	LinkQueue<int> lenstorage;
	int presentLen = 0;
	while (preNodeNum != 0)
	{
		if (pretempo->Length() != 0)
		{
			tempo = pretempo->getData(1);
			diaQueue.InQueue(tempo);
			presentLen = devideIn(tempo, intempo, inNodeNum, instorage);
			presentLen--;
			inNodeNum--;
			lenstorage.InQueue(presentLen);
			presentLen = inNodeNum - presentLen;
			lenstorage.InQueue(presentLen);
			presentLen = inNodeNum - presentLen;

			pretempo->Delete(0);
			preNodeNum--;
			devidepre(pretempo, inNodeNum, presentLen, prestorage);
		}
		else
		{
			diaQueue.InQueue(QString::fromLocal8Bit("#"));
			tempo.clear();
		}

		delete pretempo;
		delete intempo;
		pretempo = prestorage.OutQueue();
		intempo = instorage.OutQueue();
		inNodeNum = lenstorage.OutQueue();
	}
	GetDiaqueue(*queue);
	reject();
	return true;
}

int twovisit::devideIn(QString tempo, link_list<QString>* intempo, int size, LinkQueue<link_list<QString>*> &instorage)
{
	if (tempo.isEmpty())
	{
		size = -1;
		intempo->makeEmpty();
		instorage.InQueue(intempo);
		instorage.InQueue(intempo);
		return -1;
	}
	if (intempo->Length() == 0)
	{
		size = -1;
		intempo->makeEmpty();
		instorage.InQueue(intempo);
		instorage.InQueue(intempo);
		return -1;
	}
	int i = 0;
	while (intempo->getData(i) != tempo)
		i++;
	link_list<QString> *temp;
	if (i != 0)
	{
		temp = new link_list<QString>;
		for (int j = 1; j < i; j++)
			temp->Append(intempo->getData(j));
		instorage.InQueue(temp);
	}
	else
	{
		temp = new link_list<QString>;
		instorage.InQueue(temp);
	}
	if (i != size)
	{
		int last = size - i;
		if (last == 0)
		{
			temp = new link_list<QString>;
			instorage.InQueue(temp);
			intempo->makeEmpty();
			return -1;
		}
		else
		{
			temp = new link_list<QString>;
			for (int j = 1; j <= last; j++)
				temp->Append(intempo->getData(i + j));
			instorage.InQueue(temp);
		}
	}
	else
	{
		temp = new link_list<QString>;
		instorage.InQueue(temp);
	}
	intempo->makeEmpty();
	return i;
}

int twovisit::devidepre(link_list<QString>* pretempo, int preNodeNum,  int presentLen, LinkQueue<link_list<QString>*> &prestorage)
{
	link_list<QString> *temp;
	if (presentLen == -1)
	{
		temp = new link_list<QString>();
		temp->makeEmpty();
		prestorage.InQueue(temp);
		prestorage.InQueue(temp);
		pretempo->makeEmpty();
		return 0;
	}
	if (presentLen != 0)
	{
		temp = new link_list<QString>();
		for (int i = 1; i <= presentLen; i++)
			temp->Append(pretempo->getData(i));
		prestorage.InQueue(temp);
	}
	else
	{
		temp = new link_list<QString>();
		temp->makeEmpty();
		prestorage.InQueue(temp);
	}
	if (presentLen != preNodeNum)
	{
		temp = new link_list<QString>;
		for (int i = 1; i <= (preNodeNum - presentLen); i++)
			temp->Append(pretempo->getData(presentLen + i));
		prestorage.InQueue(temp);
	}
	else
	{
		temp = new link_list<QString>();
		temp->makeEmpty();
		prestorage.InQueue(temp);
	}
	pretempo->makeEmpty();
	return 0;
}
