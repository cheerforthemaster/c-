#include "editwidget.h"

editwidget::editwidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnOK()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnCancel()));

}


editwidget::~editwidget()
{

}

QString editwidget::showCell(QString *Item)
{
	ui.lineEdit->setText(*Item);
	re_string = Item;
	return QString();
}

bool editwidget::OnOK()
{
	*re_string = ui.lineEdit_2->text();
	reject();
	return false;
}


bool editwidget::OnCancel()
{
	close();
	return false;
}
