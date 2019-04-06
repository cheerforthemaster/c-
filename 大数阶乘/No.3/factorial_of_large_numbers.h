#ifndef FACTORIAL_OF_LARGE_NUMBERS_H
#define FACTORIAL_OF_LARGE_NUMBERS_H

#include <QtWidgets/QMainWindow>
#include "ui_factorial_of_large_numbers.h"

class Factorial_of_large_numbers : public QMainWindow
{
	Q_OBJECT

public:
	Factorial_of_large_numbers(QWidget *parent = 0);
	~Factorial_of_large_numbers();
	int Data;
private:
	Ui::Factorial_of_large_numbersClass ui;
	int number;
private slots:
	int OnBtnShow();
	int OnBtnCal();
};

#endif // FACTORIAL_OF_LARGE_NUMBERS_H
