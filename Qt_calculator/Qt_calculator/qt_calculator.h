#ifndef EXPRESSION_EVALUATION_H
#define EXPRESSION_EVALUATION_H

#include <QtWidgets/QMainWindow>
#include "ui_qt_calculator.h"

class Expression_evaluation : public QMainWindow
{
	Q_OBJECT

public:
	Expression_evaluation(QWidget *parent = 0);
	~Expression_evaluation();
	QString str_result;
	bool calculator(QString & tem);
private:
	Ui::Expression_evaluationClass ui;
	bool Point;
	bool Operator;
	int brackets;
	void keyPressEvent(QKeyEvent * event);
// 	void eventFilter(QObject *watched, QEvent *event);
// 	QList<QPushButton*>  buttonList;
private slots:
	int OnBtn0();
	int OnBtn1();
	int OnBtn2();
	int OnBtn3();
	int OnBtn4();
	int OnBtn5();
	int OnBtn6();
	int OnBtn7();
	int OnBtn8();
	int OnBtn9();
	int OnBtn10();
	int OnBtn11();
	int OnBtn12();
	int OnBtn13();
	int OnBtn14();
	int OnBtn15();
	int OnBtn16();
	int OnBtn17();
	int OnBtn18();
	int OnBtn19();

};

#endif // EXPRESSION_EVALUATION_H
