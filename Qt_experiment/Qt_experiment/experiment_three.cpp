#include "experiment_three.h"
#include <QMessageBox>

experiment_three::experiment_three(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.toolButton,SIGNAL(clicked()),
	this,SLOT(BtnHelp()));
}

experiment_three::~experiment_three()
{

}

int experiment_three::BtnHelp()
{
	QMessageBox::information(this, "yes","hello,world");
	return 0;
}
