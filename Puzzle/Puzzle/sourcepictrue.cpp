#include "sourcepictrue.h"

sourcePictrue::sourcePictrue(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	filename = NULL;
}

sourcePictrue::~sourcePictrue()
{

}

bool sourcePictrue::getPictrue(char* c_filename)
{
	filename = c_filename;
	return false;
}

bool sourcePictrue::getPictrue(QString Filename)
{
	str = Filename;
	update();
	return false;
}

void sourcePictrue::paintEvent(QPaintEvent * event)
{
	if (filename == NULL&&str.isEmpty())
	{
		return;
	}

	QPainter painter(this);
	int width = this->width();
	int height = this->height() - 40;
	QRect target(0, 0, width, height);//Ä¿±ê¾ØÕó

	if (!str.isEmpty())
	{
		QByteArray bty = str.toLocal8Bit();
		filename = bty.data();
	}

	QPixmap prepicture;
	if (!prepicture.load(filename))
		return;
	int imgWidth = prepicture.width();
	int imgHeight = prepicture.height();
	if (imgHeight == 0 || imgWidth == 0)
	{
		return;
	}
	QRect source(0, 0, imgWidth, imgHeight);
	painter.drawPixmap(target, prepicture, source);

}

