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
	item->appendPlainText(QString::fromLocal8Bit("前序遍历:"));
	tree->preOrderVisit();
	queue.makeEmpty();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("中序遍历:"));
	tree->inOrderVisit();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("后序遍历:"));
	tree->postOrderVisit();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("层次遍历:"));
	tree->levelOrderVisit();
	tree->outVisit(queue);
	while (queue.GetSize() != 0)
		temp = temp + queue.OutQueue() + " ";
	item->appendPlainText(temp);
	temp.clear();

	item->appendPlainText(QString::fromLocal8Bit("结点数："));
	int leng = tree->GetSize();
	item->appendPlainText(QString::number(leng));

	item->appendPlainText(QString::fromLocal8Bit("深度："));
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
	OnShowTree(ui.plainTextEdit);//显示树的各种信息;
	return false;
}

bool CreatBinaryTree::OnBtnOk()
{
	txt = ui.lineEdit->text();
	int length = txt.length();
	if (length == 0)//lineEdit中是否为空;
		return false;
	
	for (int i = 0; i < length; i++)//将lineEdit中的结点存到一个队列中;
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
		QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("头结点不能为空"));
		return false;
	}

	temp = ui.comboBox->currentText();//创建树;
	tree->SetRefValue(temp);
	temp.clear();
	tree->SetAllNode(queue);
	if (ui.comboBox_2->currentText() != QString::fromLocal8Bit("层次创建")&&ui.comboBox_2->currentText() != QString::fromLocal8Bit("前序创建"))
		return false;
	if (ui.comboBox_2->currentText()== QString::fromLocal8Bit("层次创建"))
		tree->levelOrderCreat();
	if (ui.comboBox_2->currentText() == QString::fromLocal8Bit("前序创建"))
		tree->preOrderCreat();

	OnShowTree(ui.plainTextEdit);//显示树的各种信息;

	return true;
}