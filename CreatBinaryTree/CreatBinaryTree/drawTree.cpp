#include "drawTree.h"

drawTree::drawTree(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	binTree = NULL;
}

drawTree::~drawTree()
{

}

bool drawTree::GetTree(BinaryTree<QString> *Tree)
{
	binTree = Tree;
	nodeNum = binTree->GetSize();
	levelNum = binTree->GetDepth();
	return true;
}

bool drawTree::preOrderCreat(TreeNode<QPoint>* temp, int level, bool IsLeft, int lastX, int lastY)
{
	int i = 0;
	while (IsPoint[i] == -1)
		i++;
	if (IsPoint[i] != 0)
	{
		IsPoint[i] = -1;
		if (temp == pointTree.GetRoot())
			temp->data = pointarr[0];
		else
		{
			lastY = lastY + levelheight;
			if (IsLeft)
				lastX -= Width / pow(2, level);
			else
				lastX += Width / pow(2, level);
			pointarr[i] = QPoint(lastX, lastY);
			temp->data = QPoint(lastX, lastY);
		}
		temp->lchild = new TreeNode<QPoint>(pointTree.GetRefValue());
		temp->rchild = new TreeNode<QPoint>(pointTree.GetRefValue());
		preOrderCreat(temp->lchild, level + 1, true, lastX, lastY);
		preOrderCreat(temp->rchild, level + 1, false, lastX, lastY);
		return true;
	}
	else
	{
		IsPoint[i] = -1;
		pointarr[i] = QPoint(-1, -1);
		return false;
	}
}

bool drawTree::preOrderVisit(TreeNode<QPoint>* tempor, QPainter &one)
{
	if (tempor->data != QPoint(-1, -1))
	{
		if (tempor->lchild->data != QPoint(-1, -1))
			one.drawLine(tempor->data, tempor->lchild->data);
		if (tempor->rchild->data != QPoint(-1, -1))
			one.drawLine(tempor->data, tempor->rchild->data);
		preOrderVisit(tempor->lchild, one);
		preOrderVisit(tempor->rchild, one);
	}
	else
		return false;
}

void drawTree::paintEvent(QPaintEvent * event)
{
	if (binTree == NULL || binTree->IsEmpty())
		return;

	QPainter painter(this);
	Width = this->width();
	Height = this->height();

	levelheight = Height / levelNum;//每层高度;
	int atlevel = 1;//当前层数;
	LinkQueue<QString> tempoQueue;
	binTree->preOrderVisit();
	binTree->outVisit(tempoQueue);
	QString RefuseValue = binTree->GetRefValue();
	int nodeNum = tempoQueue.GetSize();
	IsPoint = new int[nodeNum];
	int i = 0;
	while (tempoQueue.GetSize() != 0)
	{
		if (tempoQueue.OutQueue() != RefuseValue)
			IsPoint[i] = 1;
		else
			IsPoint[i] = 0;
		i++;
	}
	binTree->preOrderVisit();
	binTree->outVisit(tempoQueue);
	pointTree.SetRefValue(QPoint(-1, -1));
	pointarr = new QPoint[nodeNum];
	pointarr[0] = QPoint(Width / 2 , levelheight / 2);
	preOrderCreat(pointTree.GetRoot(), atlevel, 1, Width / 2 , levelheight / 2);

	painter.setBrush(QBrush(QColor(0x9f, 0x9f, 0xff)));//画线;
	painter.setPen(QPen(Qt::black, 5));
	preOrderVisit(pointTree.GetRoot(), painter);

	painter.setPen(QPen(Qt::black, 1));//画圆;
	int radius = 0;
	if (levelheight / 2 < Width / pow(2, levelNum))
		radius = levelheight / 2;
	else
		radius = Width / pow(2, levelNum);
	radius = radius / 2;
	for (int j = 0; j < nodeNum; j++)
	{
		if (pointarr[j] != QPoint(-1, -1))
			painter.drawEllipse(pointarr[j], radius, radius);
	}


	QFont font("Times", 16, QFont::Bold, true);//输出结点内容;
	painter.setFont(font);
	QString tem;
	for (int j = 0; j < nodeNum; j++)
	{
		if (pointarr[j] != QPoint(-1, -1))
		{
			tem = tempoQueue.OutQueue();
			while (tem == binTree->GetRefValue())
				tem = tempoQueue.OutQueue();
			painter.drawText(pointarr[j].x() - 8, pointarr[j].y() + 8, tem);
		}
	}

}
