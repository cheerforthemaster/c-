#ifndef TWOVISIT_H
#define TWOVISIT_H

#include <QDialog>
#include "link_list.h"
#include "LinkQueue.h"
#include "ui_twovisit.h"

class twovisit : public QDialog
{
	Q_OBJECT

public:
	twovisit(QWidget *parent = 0);
	~twovisit();
	bool GetDiaqueue(LinkQueue<QString> &tree);
	int devideIn(QString tempo, link_list<QString>* intempo, int size, LinkQueue<link_list<QString>*> &instorage);
	int devidepre(link_list<QString>* pretempo, int preNodeNum, int presentLen, LinkQueue<link_list<QString>*> &prestorage);
private:
	Ui::twovisit ui;
	LinkQueue<QString> diaQueue;
	LinkQueue<QString>* queue;
private slots:
	bool OnBtnClose();
	bool OnBtnCreat();
};

#endif // TWOVISIT_H
