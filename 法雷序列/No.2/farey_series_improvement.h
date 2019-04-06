#ifndef FAREY_SERIES_IMPROVEMENT_H
#define FAREY_SERIES_IMPROVEMENT_H

#include <QtWidgets/QMainWindow>
#include "ui_farey_series_improvement.h"

class Farey_Series_Improvement : public QMainWindow
{
	Q_OBJECT

public:
	Farey_Series_Improvement(QWidget *parent = 0);
	~Farey_Series_Improvement();

private:
	Ui::Farey_Series_ImprovementClass ui;
private slots:
	int OnBtnCalculate();
	int OnBtnShow();
};

#endif // FAREY_SERIES_IMPROVEMENT_H
