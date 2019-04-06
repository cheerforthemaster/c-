#include "cmq.h"

cmq::cmq(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnOKButton));
}

cmq::~cmq()
{

}
//textEdit
bool OnOKButton()
{
	return true;
}