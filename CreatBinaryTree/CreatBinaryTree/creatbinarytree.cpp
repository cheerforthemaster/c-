#include "creatbinarytree.h"
#include <QMessageBox>

CreatBinaryTree::CreatBinaryTree(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnOk()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), ui.pushButton, SIGNAL(clicked()));
	connect(ui.swapButton, SIGNAL(clicked()), this, SLOT(OnBtnSwap()));
	connect(ui.showButton, SIGNAL(clicked()), this, SLOT(OnBtnShow()));
	connect(ui.findButton, SIGNAL(clicked()), this, SLOT(OnBtnFind()));
	connect(ui.lineEdit_2, SIGNAL(returnPressed()), ui.findButton, SIGNAL(clicked()));
	connect(ui.twovisitButton, SIGNAL(clicked()), this, SLOT(OnBtnTwovisit()));
	tree = new BinaryTree<QString>();
}

CreatBinaryTree::~CreatBinaryTree()
{
	delete tree;
}

bool CreatBinaryTree::OnShowTree(QPlainTextEdit *item)
{

	item->clear();
	item->appendPlainText(QString::fromLocal8Bit("ǰ�����:"));
	tree->preOrderVisit();
	queue.makeEmpty();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("�������:"));
	tree->inOrderVisit();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("�������:"));
	tree->postOrderVisit();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("��α���:"));
	tree->levelOrderVisit();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("�������"));
	int leng = tree->GetSize();
	item->appendPlainText(QString::number(leng));

	item->appendPlainText(QString::fromLocal8Bit("��ȣ�"));
	int depth = tree->GetDepth();
	item->appendPlainText(QString::number(depth));

	return true;
}

bool CreatBinaryTree::OnBtnFind()
{
	temp = ui.lineEdit_2->text();
	if (tree->Find(temp))
	{
		queue.makeEmpty();
		tree->outVisit(queue);
		temp.clear();
		while (queue.GetSize() != 0)
			temp = queue.OutQueue() + " " + temp;
		ui.lineEdit_3->setText(temp);
		return true;
	}
	else
	{	
		temp = "NULL";
		ui.lineEdit_3->setText(temp);
		temp.clear();
		return false;
	}
	
}

bool CreatBinaryTree::OnBtnSwap()
{
	if (tree->IsEmpty())
		return false;
	else
	{
		tree->SwapTree();
		OnShowTree(ui.plainTextEdit_2);
	}
}

bool CreatBinaryTree::OnBtnShow()
{
	drawTree paint(this);
	paint.GetTree(tree);
	paint.exec();
	return true;
}

bool CreatBinaryTree::OnBtnTwovisit()
{
	twovisit twovisitcreat(this);
	twovisitcreat.GetDiaqueue(queue);
	twovisitcreat.exec();
	tree->SetRefValue(QString::fromLocal8Bit("#"));
	tree->SetAllNode(queue);
	tree->levelOrderCreat();
	OnShowTree(ui.plainTextEdit);//��ʾ���ĸ�����Ϣ;
	return false;
}

bool CreatBinaryTree::OnBtnOk()
{
	txt = ui.lineEdit->text();
	int length = txt.length();
	if (length == 0)//lineEdit���Ƿ�Ϊ��;
		return false;
	
	for (int i = 0; i < length; i++)//��lineEdit�еĽ��浽һ��������;
	{
		if (txt.at(i) == " ")
		{
			if (temp != NULL && temp != "")
				queue.InQueue(temp);
			temp.clear();
		}
		else
			temp += txt.at(i);
	}
	if (temp != NULL && temp != "")
		queue.InQueue(temp);

	if (queue.GetFront()==ui.comboBox->currentText())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("ͷ��㲻��Ϊ��"));
		return false;
	}

	temp = ui.comboBox->currentText();//������;
	tree->SetRefValue(temp);
	temp.clear();
	tree->SetAllNode(queue);
	if (ui.comboBox_2->currentText() != QString::fromLocal8Bit("��δ���")&&ui.comboBox_2->currentText() != QString::fromLocal8Bit("ǰ�򴴽�"))
		return false;
	if (ui.comboBox_2->currentText()== QString::fromLocal8Bit("��δ���"))
		tree->levelOrderCreat();
	if (ui.comboBox_2->currentText() == QString::fromLocal8Bit("ǰ�򴴽�"))
		tree->preOrderCreat();

	OnShowTree(ui.plainTextEdit);//��ʾ���ĸ�����Ϣ;

	return true;
}