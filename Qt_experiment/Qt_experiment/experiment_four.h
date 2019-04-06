#ifndef EXPERIMENT_FOUR_H
#define EXPERIMENT_FOUR_H

#include <QWidget>
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include "ui_experiment_four.h"

class experiment_four : public QWidget
{
	Q_OBJECT

public:
	experiment_four(QWidget *parent = 0);
	~experiment_four();
private:
	Ui::experiment_four ui;
private slots:
	int OnBtnOpen();
	int OnBtnSave();
};

#endif // EXPERIMENT_FOUR_H
