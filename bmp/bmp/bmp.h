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
	QString Q_filename;//所打开的文件的名称，eg：C:/Users/Master The/Desktop/Huffman.txt;
	bool IsFile();//判断文件名称是否正确;
	struct stat buf;//显示文件状态信息;

private:
	Ui::bmpClass ui;
private slots:
	bool OnOKBtn();//确定，在textEdit中显示选中文件的状态信息;
	bool OnchooseBtn();//选择文件，并按下OKButton按钮;
	bool OnclearBtn();//清空lineEdit和textEdit，并将c_filename=NULL;
	bool OncomBtn();//压缩文件;
	bool OndecomBtn();//解压文件;
};

#endif // BMP_H
