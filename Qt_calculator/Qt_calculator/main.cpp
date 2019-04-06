#include "qt_calculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Expression_evaluation w;
	w.show();
	return a.exec();
}
