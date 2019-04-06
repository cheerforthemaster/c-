#include "qt_experiment_2.h"

Qt_experiment_2::Qt_experiment_2(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnBtnOk()));

}

Qt_experiment_2::~Qt_experiment_2()
{

}

void Qt_experiment_2::paintEvent(QPaintEvent * event)
{
	if (!OnBtnOk())
		return;
	else
		update();
	QPainter painter(this);

	int width = this->width();
	int height = this->height();
	painter.setBrush(QBrush(QColor(0x9f, 0x9f, 0xff)));
	painter.setPen(QPen(Qt::black, 5));
	painter.drawLine(QPoint(width / 2, height / 4), QPoint(width / 4, height / 4 * 3));
	painter.drawLine(QPoint(width / 2, height / 4), QPoint(width / 4 * 3, height / 4 * 3));
	painter.setPen(QPen(Qt::black, 1));
	painter.drawEllipse(QPoint(width / 2, height / 4), 50, 50);
	painter.drawEllipse(QPoint(width / 4, height / 4 * 3), 50, 50);
	painter.drawEllipse(QPoint(width / 4 * 3, height / 4 * 3), 50, 50);
	QFont font("Times", 16, QFont::Bold, true);
	painter.setFont(font);

	painter.drawText(QPoint(QPoint(width / 2, height / 4)), QString::fromLocal8Bit("1"));
	painter.drawText(QPoint(QPoint(width / 4, height / 4 * 3)), QString::fromLocal8Bit("2"));
	painter.drawText(QPoint(QPoint(width / 4 * 3, height / 4 * 3)), QString::fromLocal8Bit("3"));

}

bool Qt_experiment_2::OnBtnOk()
{
	QString txt;
	txt = ui.lineEdit->text();
	if (txt.length() != 0)
	{
// 		update();
		return true;
	}
	else
		return false;
	

}
