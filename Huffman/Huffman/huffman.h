#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <QtWidgets/QMainWindow>
#include <fstream>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <QFileDialog>
#include <QByteArray>
#include <QMessageBox>
#include "LinkQueue.h"
#include "BinaryTree.h"
#include "ui_huffman.h"
using namespace std;

class Huffman : public QMainWindow
{
	Q_OBJECT

public:
	Huffman(QWidget *parent = 0);
	~Huffman();
	QString Q_filename;//所打开的文件的名称，eg：C:/Users/Master The/Desktop/Huffman.txt;
	bool IsFile();//判断文件名称是否正确;
	struct stat buf;//显示文件状态信息;
	long thesize;//每次读取的大小为4M;
	unsigned char *everyreadchar;//存放每次读取的4M大小的字节;
	unsigned char *everywritechar;//存放每次写入的4M大小的字节;
	long *ascint;//每个ASCII所表示的字符出现的次数;
	unsigned int **huffman;//存储每个ASCII码重新编码后的编码;
	bool minasc(int &sub);//获取ascint里的除去0以外的最小值的下标;
private:
	Ui::HuffmanClass ui;
	bool initializeReadchar();//将数组everyreadchar每个元素初始化为 \0 ;
	bool initializeWritechar();//将数组everywritechar每个元素初始化为 \0;
	BinaryTree<long> *tree;
private slots:
	bool OnOKBtn();//确定，在textEdit中显示选中文件的状态信息;
	bool OnchooseBtn();//选择文件，并按下OKButton按钮;
	bool OnclearBtn();//清空lineEdit和textEdit，并将c_filename=NULL;
	bool OncomBtn();//压缩文件;
	bool OndecomBtn();//解压文件;
};

#endif // HUFFMAN_H
