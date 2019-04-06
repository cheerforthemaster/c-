#ifndef TRAIN_SCHEDULING_PROBLEM_H
#define TRAIN_SCHEDULING_PROBLEM_H

#include <QtWidgets/QMainWindow>
#include "ui_train_scheduling_problem.h"

class Train_scheduling_problem : public QMainWindow
{
	Q_OBJECT

public:
	Train_scheduling_problem(QWidget *parent = 0);
	~Train_scheduling_problem();
	int result(int *RanArrary);
private:
	Ui::Train_scheduling_problemClass ui;
	int Number;
private slots:
	bool OnOKBtn();
	bool OnOKBtn2();
};

#endif // TRAIN_SCHEDULING_PROBLEM_H
