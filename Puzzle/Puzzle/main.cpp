#include "puzzle.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Puzzle w;
	w.show();
	return a.exec();
}
