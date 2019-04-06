#include "memory_management.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	memory_management w;
	w.show();
	return a.exec();
}
