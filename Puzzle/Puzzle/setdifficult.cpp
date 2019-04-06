#include "setdifficult.h"

setDifficult::setDifficult(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnOK()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(Oncancel()));
}

setDifficult::~setDifficult()
{

}

int setDifficult::getDifficult(int * item)
{
	Difficult = item;
	return 0;
}

bool setDifficult::OnOK()
{
	*Difficult = ui.comboBox->currentIndex() + 3;
	close();
	return false;
}

bool setDifficult::Oncancel()
{
	*Difficult = 3;
	close();
	return false;
}
