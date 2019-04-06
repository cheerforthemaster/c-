#include "bmp.h"

bmp::bmp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.OKButton, SIGNAL(clicked()), this, SLOT(OnOKBtn()));
	connect(ui.chooseButton, SIGNAL(clicked()), this, SLOT(OnchooseBtn()));
	connect(ui.compressionButton, SIGNAL(clicked()), this, SLOT(OncomBtn()));
	connect(ui.decompressionButton, SIGNAL(clicked()), this, SLOT(OndecomBtn()));
	connect(ui.clearButton, SIGNAL(clicked()), this, SLOT(OnclearBtn()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), ui.OKButton, SIGNAL(clicked()));
}

bmp::~bmp()
{

}

bool bmp::IsFile()
{
	Q_filename = ui.lineEdit->text();
	QByteArray bty = Q_filename.toLocal8Bit();
	const char* c_filename = bty.data();

	fstream I_file;
	I_file.open(c_filename);
	if (I_file.good())
	{
		I_file.close();
		return true;
	}
	else
	{
		I_file.close();
		return false;
	}

}

bool bmp::OnOKBtn()
{
	Q_filename = ui.lineEdit->text();
	QByteArray bty = Q_filename.toLocal8Bit();
	const char* c_filename = bty.data();
	if (!IsFile())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("文件名错误"));
		OnclearBtn();
		return false;
	}
	stat(c_filename, &buf);
	ui.textEdit->setText(QString::fromLocal8Bit("所选择的文件：") + Q_filename);
	ui.textEdit->append(QString::fromLocal8Bit("文件大小：") + QString::number(buf.st_size) + QString::fromLocal8Bit("字节"));
	return false;
}

bool bmp::OnchooseBtn()
{
	QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"));
	if (filename.length() > 0)
	{
		ui.lineEdit->setText(filename);
		OnOKBtn();
		return true;
	}
	else
		return false;
}

bool bmp::OnclearBtn()
{
	ui.lineEdit->clear();
	ui.textEdit->clear();
	Q_filename.clear();
	return false;
}

bool bmp::OncomBtn()
{
	Q_filename = ui.lineEdit->text();
	QByteArray bty = Q_filename.toLocal8Bit();
	const char* c_filename = bty.data();

	fstream file;
	file.open(c_filename, ios::in | ios::binary);
	if (!file.good())
		return false;
	long rest = buf.st_size;//剩余的字节数;
	if (rest == 0)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("警告"), QString::fromLocal8Bit("文件为空！！！"));
		return false;
	}
	file.close();
 	CompressBmp m_object;
 	m_object.ReadBitmap(c_filename);
// 	m_object.WriteBitmap("out.bmp");
	int paragraph = m_object.Compress();
	ui.textEdit->append(QString::fromLocal8Bit("段落数")+QString::number(paragraph));
 	ui.textEdit->append(QString::fromLocal8Bit("压缩测试结束！"));

	return false;
}

bool bmp::OndecomBtn()
{
	QString tem;
	if (Q_filename.isEmpty())
		return false;
	for (int i = Q_filename.length() - 1; i > Q_filename.length() - 4; i--)
	{
		tem = Q_filename.at(i) + tem;
	}
	if (tem != "img")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("不是img文件！！！"));
		return false;
	}

	QByteArray bty = Q_filename.toLocal8Bit();
	const char* filename = bty.data();
	fstream file;
	file.open(filename, ios::in | ios::binary);
	if (!file.good())
		return false;
	file.close();
	CompressBmp m_object;
	m_object.UnCompress();
	ui.textEdit->append(QString::fromLocal8Bit("解压测试结束！"));
	return false;
}
