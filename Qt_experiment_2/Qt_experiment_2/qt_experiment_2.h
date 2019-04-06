#ifndef QT_EXPERIMENT_2_H
#define QT_EXPERIMENT_2_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_experiment_2.h"
#include <QPainter>
#include <QPixmap>

class Qt_experiment_2 : public QMainWindow
{
	Q_OBJECT

public:
	Qt_experiment_2(QWidget *parent = 0);
	~Qt_experiment_2();

private:
	Ui::Qt_experiment_2Class ui;
	void paintEvent(QPaintEvent * event);

private slots:
	bool OnBtnOk();

};

#endif // QT_EXPERIMENT_2_H
