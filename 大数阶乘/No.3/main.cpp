#include "factorial_of_large_numbers.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	Factorial_of_large_numbers w;
	
	w.show();

	return a.exec();
}

