#include "experiment_four.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <QByteArray>
#include <QDebug>
using namespace std;

experiment_four::experiment_four(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.BtnOpen, SIGNAL(clicked()), this, SLOT(OnBtnOpen()));
	connect(ui.BtnSave, SIGNAL(clicked()), this, SLOT(OnBtnSave()));
}

experiment_four::~experiment_four()
{

}

int experiment_four::OnBtnOpen()
{
	QFile file("file.dat");
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);   // we will serialize the data into the file  
	out << QString("");   // serialize a string  
	out << (qint32)42;        // serialize an integer  
	file.close();
	return 0;
	//QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"));
	//if (filename.length()>0)
	//{
	//	//QString str = QMessageBox::information(this, "ok", "chose " + filename);
	//	QByteArray bty =filename.toLocal8Bit();
	//	const char* cha = bty.data();
	//	fstream File;
	//	File.open(cha);
	//	if (!File.good())
	//	{
	//		return 1;
	//	}
	//	File.seekg(0, ios::end);
	//	//File.seekg(1024 * 4, ios::beg);
	//	//bool Eof = File.eof();
	//	int size = File.tellg();
	//	char* text_out = new char[size + 1];
	//	if (text_out==NULL)
	//	{
	//		return 1;
	//	}
	//	for (int i=0;i<size+1;i++)
	//	{
	//		text_out[i] ='\0';
	//	}
	//	File.seekg(0, ios::beg);
	//	File.read(text_out, size + 1);
	//	//qDebug("%s", text_out);
	//	ui.plainTextEdit->setPlainText(QString::fromLocal8Bit(text_out));
	//	ui.plainTextEdit->appendPlainText(filename);
	//	delete[] text_out;
	//	File.close();

	//}
	//else
	//{
	//	//QMessageBox::information(this, "error", "not chose any file");
	//}
	//return 0;
}

int experiment_four::OnBtnSave()
{
	QFile file("file.dat");
	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	QString str;
	qint32 a;
	in >> str;
	in >> a;

	qDebug() << str;
	qDebug() << a;
	file.close();
	return 0;
	//QString filename = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("保存文件"));
	//if (filename.length()>0)
	//{
	//	//QString str = QMessageBox::information(this, "ok", "chose " + filename);
	//	QByteArray bty = filename.toLocal8Bit();
	//	const char* cha = bty.data();
	//	fstream File;
	//	File.open(cha);
	//	if (!File.good())
	//	{
	//		return 1;
	//	}
	//	QString qstr = ui.plainTextEdit->toPlainText();
	//	bty = qstr.toLocal8Bit();
	//	int size = bty.length();
	//	char *save_char = new char[size+1];
	//	for (int i=0;i<size+1;i++)
	//	{
	//		save_char[i] = '\0';
	//	}
	//	for(int i=0;i<size;i++)
	//	{
	//		save_char[i] = bty.data()[i]; 
	//	}
	//	File.write(save_char, size);

	//	delete[] save_char;
	//	File.close();
	//}
	//else
	//{
	//	//QMessageBox::information(this, "error", "not chose any file");
	//}

	//return 0;
}