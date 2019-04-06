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
	bool m_mouse;//����Ƿ���
	vector<QPoint> vec;//�洢��갴�º��ɿ���λ��
	QPixmap prepicture;//��ͼ
	int num;//�Ѷ� Ĭ��Ϊ3x3
	int *rect;//����
	QRect source;//Դͼ����
	char* c_filename;//�򿪵�ͼƬ���ļ���
	QString filename;//�򿪵�ͼƬ���ļ���
	bool keyevent();//�����¼���Ӧ��ͼƬ�仯
	int moveKey;//1 Ϊ�� 2Ϊ�� 3Ϊ�� 4Ϊ�� ���󣺿հ���
	bool issuccess();//��Ϸ�Ƿ�ɹ�
	private slots:
	bool OnChoose();//ѡ���ļ�
	bool OnNewGame();//���¿�ʼ��Ϸ
	bool OnsetDifficulty();//�����Ѷ�
	bool OnSeeSource();//�鿴ԭͼ
};

#endif // PUZZLE_H
