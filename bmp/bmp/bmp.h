#ifndef BMP_H
#define BMP_H

#include <QtWidgets/QMainWindow>
#include <fstream>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QFileDialog>
#include <QMessageBox>
#include "CompressBmp.h"
#include "ui_bmp.h"
using namespace std;

class bmp : public QMainWindow
{
	Q_OBJECT

public:
	bmp(QWidget *parent = 0);
	~bmp();
	QString Q_filename;//���򿪵��ļ������ƣ�eg��C:/Users/Master The/Desktop/Huffman.txt;
	bool IsFile();//�ж��ļ������Ƿ���ȷ;
	struct stat buf;//��ʾ�ļ�״̬��Ϣ;

private:
	Ui::bmpClass ui;
private slots:
	bool OnOKBtn();//ȷ������textEdit����ʾѡ���ļ���״̬��Ϣ;
	bool OnchooseBtn();//ѡ���ļ���������OKButton��ť;
	bool OnclearBtn();//���lineEdit��textEdit������c_filename=NULL;
	bool OncomBtn();//ѹ���ļ�;
	bool OndecomBtn();//��ѹ�ļ�;
};

#endif // BMP_H
