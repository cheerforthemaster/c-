#include "cmq.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	cmq w;
	w.show();
	return a.exec();
}
