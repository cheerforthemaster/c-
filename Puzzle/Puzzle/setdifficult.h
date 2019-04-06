#ifndef SETDIFFICULT_H
#define SETDIFFICULT_H

#include <QWidget>
#include <QDialog>
#include "ui_setdifficult.h"

class setDifficult : public QDialog
{
	Q_OBJECT

public:
	setDifficult(QWidget *parent = 0);
	~setDifficult();
	int getDifficult(int *item);
	int *Difficult;
private:
	Ui::setDifficult ui;
	private slots:
	bool OnOK();
	bool Oncancel();
};

#endif // SETDIFFICULT_H
