#ifndef SOURCEPICTRUE_H
#define SOURCEPICTRUE_H

#include <QDialog>
#include <QPainter>
#include "ui_sourcepictrue.h"

class sourcePictrue : public QDialog
{
	Q_OBJECT

public:
	sourcePictrue(QWidget *parent = 0);
	~sourcePictrue();
	bool getPictrue(char* c_filename);
	bool getPictrue(QString Filename);
	char* filename;
	QString str;
private:
	Ui::sourcePictrue ui;
	void paintEvent(QPaintEvent * event);

};

#endif // SOURCEPICTRUE_H
