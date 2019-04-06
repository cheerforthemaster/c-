#ifndef ADDROW_H
#define ADDROW_H

#include <QDialog>
#include "ui_addrow.h"

class addRow : public QDialog
{
	Q_OBJECT

public:
	addRow(QWidget *parent = 0);
	~addRow();
	bool reString(QString item[11]);

private:
	Ui::addRow ui;
	QString *str;
	private slots:
	bool OnOK();
	bool Oncancel();
};

#endif // ADDROW_H
