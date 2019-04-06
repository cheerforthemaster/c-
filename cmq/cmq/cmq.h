#ifndef CMQ_H
#define CMQ_H


#include <QtWidgets/QMainWindow>
#include "ui_cmq.h"

class cmq : public QMainWindow
{
	Q_OBJECT

public:
	cmq(QWidget *parent = 0);
	~cmq();

private:
	Ui::cmqClass ui;
	private slots:
	bool OnOKButton();
};

#endif // CMQ_H
