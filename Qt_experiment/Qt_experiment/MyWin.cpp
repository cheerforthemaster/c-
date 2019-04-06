#include "MyWin.h"
//#include <QTextCodec>

MyWin::MyWin(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(
		ui.pushButton,
		SIGNAL(clicked(bool)),
		this,
		SLOT(OnShowButton(bool))
	);
}

MyWin::~MyWin()
{

}

int MyWin :: OnShowButton(bool click)
{
	QString str = QString::fromLocal8Bit("ÄãºÃ");
	ui.textEdit->setPlainText(str);

	//QString str = ui.textEdit->toPlainText();
	//QByteArray byt = str.toLocal8Bit();
	//char *cha = byt.data();

	return 0;
}