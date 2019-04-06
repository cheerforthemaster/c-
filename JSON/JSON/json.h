#ifndef JSON_H
#define JSON_H

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QByteArray>
#include <fstream>
#include <QStandardItemModel>
#include <stack>
#include "ui_JSON.h"
using namespace std;

class JSON : public QMainWindow
{
	Q_OBJECT

public:
	JSON(QWidget *parent = 0);
	~JSON();
private:
	Ui::JSONClass ui;
	QString file_name;
public slots:
	bool OnCopyAction();
	bool OnPasteAction();
	bool OnClearAction();
	bool OnOpenAction();
	bool OnSaveAction();
	bool OnSaveAsAction();
	bool OnProcesseText();//���ı�����Ȼ��ͼ��;
	bool OnConpress();//ȥ��""֮��Ŀո�
	bool OnFormat();//��ʽ��;
};

#endif // JSON_H