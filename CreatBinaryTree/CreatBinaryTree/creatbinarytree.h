#ifndef CREATBINARYTREE_H
#define CREATBINARYTREE_H

#include <QtWidgets/QMainWindow>
#include "ui_creatbinarytree.h"
#include "drawTree.h"
#include "twovisit.h"
#include <QPainter>
#include "BinaryTree.h"
#include "LinkQueue.h"

class CreatBinaryTree : public QMainWindow
{
	Q_OBJECT

public:
	CreatBinaryTree(QWidget *parent = 0);
	~CreatBinaryTree();

	QString txt;
	BinaryTree<QString> *tree;
	QString temp;
	LinkQueue<QString> queue;
private:
	Ui::CreatBinaryTreeClass ui;
	bool OnShowTree(QPlainTextEdit *item);
public slots:
	bool OnBtnOk();
	bool OnBtnFind();
	bool OnBtnSwap();
	bool OnBtnShow();
	bool OnBtnTwovisit();
};

#endif // CREATBINARYTREE_H
