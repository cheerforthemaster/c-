#ifndef PUZZLE_H
#define PUZZLE_H

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <ctime>
#include <QDebug>
#include <QKeyEvent> 
#include <QMouseEvent>
#include <QMessageBox>
#include <vector>
#include "sourcepictrue.h"
#include "setdifficult.h"
#include "ui_puzzle.h"
using namespace std;

class Puzzle : public QMainWindow
{
	Q_OBJECT

public:
	Puzzle(QWidget *parent = 0);
	~Puzzle();

private:
	Ui::PuzzleClass ui;
	void paintEvent(QPaintEvent * event);
	void keyPressEvent(QKeyEvent * event);
	void mousePressEvent(QMouseEvent * event);
	void mouseReleaseEvent(QMouseEvent * event);
	bool m_mouse;//鼠标是否按下
	vector<QPoint> vec;//存储鼠标按下和松开的位置
	QPixmap prepicture;//画图
	int num;//难度 默认为3x3
	int *rect;//矩阵
	QRect source;//源图矩阵
	char* c_filename;//打开的图片的文件名
	QString filename;//打开的图片的文件名
	bool keyevent();//键盘事件对应的图片变化
	int moveKey;//1 为上 2为下 3为左 4为右 对象：空白区
	bool issuccess();//游戏是否成功
	private slots:
	bool OnChoose();//选择文件
	bool OnNewGame();//重新开始游戏
	bool OnsetDifficulty();//设置难度
	bool OnSeeSource();//查看原图
};

#endif // PUZZLE_H
