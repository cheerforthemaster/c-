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
	int flood(int x, int y);//从group数组的第x行，第y列开始洪水填充
	int haveMine(int x, int y);//group[x][y]周围八个格子中有几个雷
	void paintEvent(QPaintEvent *event);
	int difficulty;//1 初级； 2 中级； 3 高级;
	int wiNum;//横向块数
	int heNum;//纵向块数
	int mine;//雷数
	QPoint original;//方块数组的起点
	QPoint endPoint;//方块数组的终点
	int height;
	int width;
	QPixmap *Qpix;//图片
	QPixmap blankQpix;//起始方块
	int **group;
	void setGroup();
	void initialGroup();
	QRect **rec;
	void setRect();
	void initialRect();
	void mousePressEvent(QMouseEvent *event);
	bool isContinue;
private slots:
	void setDifficulty();//设置难度
	bool primary();
	bool intermediate();
	bool senior();
	bool EXIT();
};

#endif // MINE_CLEARANCE_H
