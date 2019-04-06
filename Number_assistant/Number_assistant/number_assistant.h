#ifndef NUMBER_ASSISTANT_H
#define NUMBER_ASSISTANT_H

#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QByteArray>
#include <QMessageBox>
#include <fstream>
#include <QDebug>
#include <QFile>
#include <sys/stat.h>
#include <sys/types.h>
#include "addrow.h"
#include "Binary_Search_Tree.h"
#include "editwidget.h"
#include "ui_number_assistant.h"
using namespace std;

class Number_assistant : public QMainWindow
{
	Q_OBJECT

public:
	Number_assistant(QWidget *parent = 0);
	~Number_assistant();


private:
	Ui::Number_assistantClass ui;
	QStandardItemModel *Model;//行操作
	QStandardItemModel *reModel;//指向model 查询后返回时使用
	bool setHead();//设置表头信息
	bool Onstorage();//存储当前model的所有信息到SaveDate.dat中
	bool Onload();//从SaveDate.dat中加载信息到model中
	private slots:
bool OnOpenImport();//打开并导入
bool Onexport();//导出信息
bool OnSearch();//查询
bool Onedit();//编辑
bool Ondelete();//删除指定行
bool Onreturn();//返回
bool Onadd();//加一行信息到最后一行

};

#endif // NUMBER_ASSISTANT_H
