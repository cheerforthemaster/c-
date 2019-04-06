#ifndef VISIT_GRAGH_H
#define VISIT_GRAGH_H

#include <QtWidgets/QMainWindow>
#include "ui_visit_gragh.h"

class visit_gragh : public QMainWindow
{
	Q_OBJECT

public:
	visit_gragh(QWidget *parent = 0);
	~visit_gragh();

private:
	Ui::visit_graghClass ui;
};

#endif // VISIT_GRAGH_H
