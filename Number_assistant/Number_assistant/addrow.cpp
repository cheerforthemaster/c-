#include "addrow.h"

addRow::addRow(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.OkButton, SIGNAL(clicked()), this, SLOT(OnOK()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(Oncancel()));
}

addRow::~addRow()
{

}

bool addRow::reString(QString item[11])
{
	str = item;
	return false;
}

bool addRow::OnOK()
{
	str[0] = ui.lineEdit->text();
	str[1] = ui.lineEdit_2->text();
	str[2] = ui.lineEdit_3->text();
	str[3] = ui.lineEdit_4->text();
	str[4] = ui.lineEdit_5->text();
	str[5] = ui.lineEdit_6->text();
	str[6] = ui.lineEdit_7->text();
	str[7] = ui.lineEdit_8->text();
	str[8] = ui.lineEdit_9->text();
	str[9] = ui.lineEdit_10->text();
	str[10] = ui.lineEdit_11->text();
	reject();
	return false;
}


bool addRow::Oncancel()
{
	for (int i = 0; i < 11; i++)
	{
		str[i].clear();
	}
	reject();
	return false;
}
