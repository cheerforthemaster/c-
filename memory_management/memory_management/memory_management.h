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
	m_list* mList;//�ڴ�ռ�
	int proOne;//����һ���ÿռ�
	int proTwo;//���̶����ÿռ�
	int proThree;//���������ÿռ�
	void paintEvent(QPaintEvent *event);
	bool apply(int item);//ָ����������ռ�
	bool release(int item);//ָ�������ͷſռ�

private slots:
bool preApplyOne();
bool preApplyTwo();
bool preApplyThree();
bool preReleaseOne();
bool preReleaseTwo();
bool preReleaseThree();
};

#endif // MEMORY_MANAGEMENT_H
