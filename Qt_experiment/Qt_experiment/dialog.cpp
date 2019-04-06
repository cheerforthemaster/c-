#include "dialog.h"

dialog::dialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	connect(ui.pushButton, SIGNAL(clicked()),this,SLOT(OnbtnOk()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(OnbtnCancel()));
}

dialog::~dialog()
{

}

int dialog::OnbtnOk()
{
	m_user = ui.lineEdit->text();
	m_password = ui.lineEdit_2->text();

	accept();
	return 0;
}

int dialog::OnbtnCancel()
{
	reject();
	return 0;
}
