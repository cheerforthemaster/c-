#include "SearchWindow.h"

SearchWindow::SearchWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	M_win = new M_Search(this);
	M_win->setWindowFlags(Qt::Window);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnShow()));
	connect(M_win->ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnSearch()));
}

SearchWindow::~SearchWindow()
{

}

int SearchWindow::OnBtnSearch()
{
	QString str = M_win->ui.lineEdit->text();
	ui.plainTextEdit->appendPlainText(str);

	return 0;
}

int SearchWindow::OnBtnShow()
{
	M_win->show();

	return 0;
}
