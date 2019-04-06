#include "qt_experiment.h"

Qt_experiment::Qt_experiment(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	connect(ui.checkBox, SIGNAL(stateChanged ( int ) ),
			this,SLOT(btnNext()));
}

Qt_experiment::~Qt_experiment()
{

}


int Qt_experiment::btnNext()
{
	//ui.plainTextEdit->setPlainText("123456");
	if (ui.checkBox->isChecked())
	{
		ui.pushButton->setEnabled(true);
	}
	else
	{
		ui.pushButton->setEnabled(false);

	}
	return 0;
}