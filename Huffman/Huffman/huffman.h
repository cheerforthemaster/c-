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
	QString Q_filename;//���򿪵��ļ������ƣ�eg��C:/Users/Master The/Desktop/Huffman.txt;
	bool IsFile();//�ж��ļ������Ƿ���ȷ;
	struct stat buf;//��ʾ�ļ�״̬��Ϣ;
	long thesize;//ÿ�ζ�ȡ�Ĵ�СΪ4M;
	unsigned char *everyreadchar;//���ÿ�ζ�ȡ��4M��С���ֽ�;
	unsigned char *everywritechar;//���ÿ��д���4M��С���ֽ�;
	long *ascint;//ÿ��ASCII����ʾ���ַ����ֵĴ���;
	unsigned int **huffman;//�洢ÿ��ASCII�����±����ı���;
	bool minasc(int &sub);//��ȡascint��ĳ�ȥ0�������Сֵ���±�;
private:
	Ui::HuffmanClass ui;
	bool initializeReadchar();//������everyreadcharÿ��Ԫ�س�ʼ��Ϊ \0 ;
	bool initializeWritechar();//������everywritecharÿ��Ԫ�س�ʼ��Ϊ \0;
	BinaryTree<long> *tree;
private slots:
	bool OnOKBtn();//ȷ������textEdit����ʾѡ���ļ���״̬��Ϣ;
	bool OnchooseBtn();//ѡ���ļ���������OKButton��ť;
	bool OnclearBtn();//���lineEdit��textEdit������c_filename=NULL;
	bool OncomBtn();//ѹ���ļ�;
	bool OndecomBtn();//��ѹ�ļ�;
};

#endif // HUFFMAN_H
