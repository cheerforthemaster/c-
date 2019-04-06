#ifndef DRAWTREE_H
#define DRAWTREE_H

#include <QDialog>
#include <QPainter>
#include "BinaryTree.h"
//#include "qmath.h"
#include "ui_drawTree.h"

class drawTree : public QDialog
{
	Q_OBJECT

public:
	drawTree(QWidget *parent = 0);
	~drawTree();
	bool GetTree(BinaryTree<QString> *Tree);
	QPoint *pointarr;
	int *IsPoint;
	bool preOrderCreat(TreeNode<QPoint>* temp, int level, bool IsLeft, int lastX, int lastY);
	bool preOrderVisit(TreeNode<QPoint>* tempor, QPainter &one);
	BinaryTree<QPoint> pointTree;
	int levelheight;
	int Width;
	int Height;
private:
	Ui::drawTree ui;
	void paintEvent(QPaintEvent * event);
	BinaryTree<QString> *binTree;
	int nodeNum;
	int levelNum;
};

#endif // DRAWTREE_H
