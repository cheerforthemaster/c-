#include "mine_clearance.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mine_clearance w;
	w.show();
	return a.exec();
}
