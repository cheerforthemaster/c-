#include "farey_series.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Farey_Series w;
	w.show();
	return a.exec();
}
