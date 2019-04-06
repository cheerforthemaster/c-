#include "memory_management.h"

memory_management::memory_management(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	mList = new m_list();//Ĭ��ҳ������ҳ���СΪ1024
	proOne = 0;
	proTwo = 0;
	proThree = 0;

	connect(ui.apply_1, SIGNAL(clicked()), this, SLOT(preApplyOne()));
	connect(ui.apply_2, SIGNAL(clicked()), this, SLOT(preApplyTwo()));
	connect(ui.apply_3, SIGNAL(clicked()), this, SLOT(preApplyThree()));

	connect(ui.release_1, SIGNAL(clicked()), this, SLOT(preReleaseOne()));
	connect(ui.release_2, SIGNAL(clicked()), this, SLOT(preReleaseTwo()));
	connect(ui.release_3, SIGNAL(clicked()), this, SLOT(preReleaseThree()));

}

memory_management::~memory_management()
{
	delete mList;
}

bool memory_management::preApplyOne()
{
	apply(1);
	return false;
}

bool memory_management::preApplyTwo()
{
	apply(2);
	return false;
}

bool memory_management::preApplyThree()
{
	apply(3);
	return false;
}

bool memory_management::preReleaseOne()
{
	release(1);
	return false;
}

bool memory_management::preReleaseTwo()
{
	release(2);
	return false;
}

bool memory_management::preReleaseThree()
{
	release(3);
	return false;
}

bool memory_management::apply(int item)
{
	QString line;
	switch (item)
	{
	case 1:
		line = ui.lineEdit->text();
		break;
	case 2:
		line = ui.lineEdit_2->text();
		break;
	case 3:
		line = ui.lineEdit_3->text();
		break;
	default:
		break;
	}
	int applyNum = line.toInt();
	if (applyNum > 0 && mList->apply(applyNum))
	{
		switch (item)
		{
		case 1:
			proOne += applyNum;
			break;
		case 2:
			proTwo += applyNum;
			break;
		case 3:
			proThree += applyNum;
			break;
		default:
			break;
		}
		QMessageBox::information(this, QString::fromLocal8Bit("����ռ�"), QString::fromLocal8Bit("����ɹ�"));
		update();
		return true;
	}
	QMessageBox::warning(this, QString::fromLocal8Bit("����ռ�"), QString::fromLocal8Bit("����ʧ�ܣ�����"));
	update();
	return false;
}

bool memory_management::release(int item)
{
	QString line;
	switch (item)
	{
	case 1:
		line = ui.lineEdit->text();
		break;
	case 2:
		line = ui.lineEdit_2->text();
		break;
	case 3:
		line = ui.lineEdit_3->text();
		break;
	default:
		break;
	}
	int releaseNum = line.toInt();
	if (releaseNum > 0 && mList->release(releaseNum))
	{
		switch (item)
		{
		case 1:
			proOne -= releaseNum;
			break;
		case 2:
			proTwo -= releaseNum;
			break;
		case 3:
			proThree -= releaseNum;
			break;
		default:
			break;
		}
		QMessageBox::information(this, QString::fromLocal8Bit("�ͷſռ�"), QString::fromLocal8Bit("�ͷųɹ�"));
		update();
		return true;
	}
	QMessageBox::warning(this, QString::fromLocal8Bit("�ͷſռ�"), QString::fromLocal8Bit("�ͷ�ʧ�ܣ�����"));
	update();
	return false;


	return false;
}


void memory_management::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);

	int used = mList->getUsedRoom();
	int baseColor = 255;
	int sum = proOne + proTwo + proThree;
	if (sum == 0)
		return;
	int oneColor = ((double)proOne / (double)sum)*baseColor;
	int twoColor = ((double)proTwo / (double)sum)*baseColor;
	int threeColor = ((double)proThree / (double)sum)*baseColor;

	if (oneColor == 0)
		painter.setBrush(QColor(255, 255, 255));
	else
		painter.setBrush(QColor(oneColor, 0, 0));
	QPoint leftTop = ui.label_5->pos();
	QPoint rightTop(leftTop.x() + ui.label_5->width()*((double)proOne / (double)sum), leftTop.y() + ui.label_5->height());
	painter.drawRect(QRect(leftTop, rightTop));

	if (twoColor == 0)
		painter.setBrush(QColor(255, 255, 255));
	else
		painter.setBrush(QColor(twoColor, 0, 0));
	leftTop = ui.label_6->pos();
	rightTop=QPoint(leftTop.x() + ui.label_6->width()*((double)proTwo / (double)sum), leftTop.y() + ui.label_6->height());
	painter.drawRect(QRect(leftTop, rightTop));
	
	if (threeColor == 0)
		painter.setBrush(QColor(255, 255, 255));
	else
		painter.setBrush(QColor(threeColor, 0, 0));
	leftTop = ui.label_7->pos();
	rightTop = QPoint(leftTop.x() + ui.label_7->width()*((double)proThree / (double)sum), leftTop.y() + ui.label_7->height());
	painter.drawRect(QRect(leftTop, rightTop));
}