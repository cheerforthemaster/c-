#include "train_scheduling_problem.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Train_scheduling_problem w;
	w.show();
	return a.exec();
}
