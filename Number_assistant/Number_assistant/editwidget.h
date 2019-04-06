#ifndef EDITWIDGET_H
#define EDITWIDGET_H

#include <QDialog>
#include "ui_editwidget.h"

class editwidget : public QDialog
{
	Q_OBJECT

public:
	editwidget(QWidget *parent = 0);
	~editwidget();
	QString showCell(QString *Item);
	QString *re_string;
private:
	Ui::editwidget ui;
	private slots:
	bool OnOK();
	bool OnCancel();
};

#endif // EDITWIDGET_H
