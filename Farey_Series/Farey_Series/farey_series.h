#ifndef FAREY_SERIES_H
#define FAREY_SERIES_H

#include <QtWidgets/QMainWindow>
#include "ui_farey_series.h"

class Farey_Series : public QMainWindow
{
	Q_OBJECT

public:
	Farey_Series(QWidget *parent = 0);
	~Farey_Series();

private:
	Ui::Farey_SeriesClass ui;
private slots:
	int OnBtnOk();
	int OnBtnShow();
};

#endif // FAREY_SERIES_H
