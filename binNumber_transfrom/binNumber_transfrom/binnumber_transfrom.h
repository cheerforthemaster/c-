#ifndef BINNUMBER_TRANSFROM_H
#define BINNUMBER_TRANSFROM_H

#include <QtWidgets/QMainWindow>
#include "QMessageBox"
#include "QByteArray"
#include "ui_binnumber_transfrom.h"

class binNumber_transfrom : public QMainWindow
{
	Q_OBJECT

public:
	binNumber_transfrom(QWidget *parent = 0);
	~binNumber_transfrom();

private:
	Ui::binNumber_transfromClass ui;
	QString Num;
private slots:
bool OnOKBtn();
};

#endif // BINNUMBER_TRANSFROM_H
