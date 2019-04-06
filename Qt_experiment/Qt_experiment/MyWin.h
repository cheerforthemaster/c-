#ifndef MYWIN_H
#define MYWIN_H

#include <QWidget>
#include "ui_MyWin.h"

class MyWin : public QWidget
{
	Q_OBJECT

public:
	MyWin(QWidget *parent = 0);
	~MyWin();

private:
	Ui::MyWin ui;

private slots:
	int OnShowButton(bool click);

};

#endif // MYWIN_H
