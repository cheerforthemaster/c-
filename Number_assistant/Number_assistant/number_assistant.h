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
	QStandardItemModel *Model;//�в���
	QStandardItemModel *reModel;//ָ��model ��ѯ�󷵻�ʱʹ��
	bool setHead();//���ñ�ͷ��Ϣ
	bool Onstorage();//�洢��ǰmodel��������Ϣ��SaveDate.dat��
	bool Onload();//��SaveDate.dat�м�����Ϣ��model��
	private slots:
bool OnOpenImport();//�򿪲�����
bool Onexport();//������Ϣ
bool OnSearch();//��ѯ
bool Onedit();//�༭
bool Ondelete();//ɾ��ָ����
bool Onreturn();//����
bool Onadd();//��һ����Ϣ�����һ��

};

#endif // NUMBER_ASSISTANT_H
