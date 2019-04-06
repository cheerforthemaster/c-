#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <m_list.h>
#include <QDebug>
#include <QPainter>
#include <QMessageBox>

#include <QtWidgets/QMainWindow>
#include "ui_memory_management.h"
using namespace std;

class memory_management : public QMainWindow
{
	Q_OBJECT

public:
	memory_management(QWidget *parent = 0);
	~memory_management();

private:
	Ui::memory_managementClass ui;
	m_list* mList;//内存空间
	int proOne;//进程一所用空间
	int proTwo;//进程二所用空间
	int proThree;//进程三所用空间
	void paintEvent(QPaintEvent *event);
	bool apply(int item);//指定进程申请空间
	bool release(int item);//指定进程释放空间

private slots:
bool preApplyOne();
bool preApplyTwo();
bool preApplyThree();
bool preReleaseOne();
bool preReleaseTwo();
bool preReleaseThree();
};

#endif // MEMORY_MANAGEMENT_H
