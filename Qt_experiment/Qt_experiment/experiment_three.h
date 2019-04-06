#ifndef EXPERIMENT_THREE_H
#define EXPERIMENT_THREE_H

#include <QWidget>
#include "ui_experiment_three.h"

class experiment_three : public QWidget
{
	Q_OBJECT

public:
	experiment_three(QWidget *parent = 0);
	~experiment_three();

private:
	Ui::experiment_three ui;

private slots:
	int BtnHelp();
};

#endif // EXPERIMENT_THREE_H
