#ifndef EXPERIMENT_TWO_H
#define EXPERIMENT_TWO_H

#include <QWidget>
#include "ui_experiment_two.h"

class experiment_two : public QWidget
{
	Q_OBJECT

public:
	experiment_two(QWidget *parent = 0);
	~experiment_two();

private:
	Ui::experiment_two ui;

private slots:
	int OnBtnOk();
	int OnTextChanged(int index);
	int OnBtnNext();
};

#endif // EXPERIMENT_TWO_H
