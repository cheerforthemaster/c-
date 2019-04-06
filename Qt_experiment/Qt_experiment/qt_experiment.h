#ifndef QT_EXPERIMENT_H
#define QT_EXPERIMENT_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_experiment.h"

class Qt_experiment : public QMainWindow
{
	Q_OBJECT

public:
	Qt_experiment(QWidget *parent = 0);
	~Qt_experiment();

private:
	Ui::Qt_experimentClass ui;

private slots:
	int btnNext();
};

#endif // QT_EXPERIMENT_H
