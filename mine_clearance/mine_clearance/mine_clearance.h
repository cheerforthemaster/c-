#ifndef MINE_CLEARANCE_H
#define MINE_CLEARANCE_H

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <ctime>
#include <QMouseEvent>
#include <QMessageBox>
#include "ui_mine_clearance.h"
using namespace std;


class mine_clearance : public QMainWindow
{
	Q_OBJECT

public:
	mine_clearance(QWidget *parent = 0);
	~mine_clearance();

private:
	Ui::mine_clearanceClass ui;
	int flood(int x, int y);//��group����ĵ�x�У���y�п�ʼ��ˮ���
	int haveMine(int x, int y);//group[x][y]��Χ�˸��������м�����
	void paintEvent(QPaintEvent *event);
	int difficulty;//1 ������ 2 �м��� 3 �߼�;
	int wiNum;//�������
	int heNum;//�������
	int mine;//����
	QPoint original;//������������
	QPoint endPoint;//����������յ�
	int height;
	int width;
	QPixmap *Qpix;//ͼƬ
	QPixmap blankQpix;//��ʼ����
	int **group;
	void setGroup();
	void initialGroup();
	QRect **rec;
	void setRect();
	void initialRect();
	void mousePressEvent(QMouseEvent *event);
	bool isContinue;
private slots:
	void setDifficulty();//�����Ѷ�
	bool primary();
	bool intermediate();
	bool senior();
	bool EXIT();
};

#endif // MINE_CLEARANCE_H
