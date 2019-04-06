#include "visit_gragh.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	visit_gragh w;
	w.show();
	return a.exec();
}
