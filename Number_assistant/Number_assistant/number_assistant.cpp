#include "number_assistant.h"
#define  Column_Size 256

Number_assistant::Number_assistant(QWidget *parent)
	: QMainWindow(parent)
{
	fstream file;//创建SaveDate.dat
	file.open("SaveDate.dat");
	if (!file.good())
		file.open("SaveDate.dat", ios::out);
	else
		file.close();

	ui.setupUi(this);
	Model = new QStandardItemModel();
	reModel = Model;
	ui.tableView->setModel(Model);
	setHead();

	connect(ui.action, SIGNAL(triggered()), this, SLOT(OnOpenImport()));
	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(Onexport()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnSearch()));
	connect(ui.editButton, SIGNAL(clicked()), this, SLOT(Onedit()));
	connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(Ondelete()));
	connect(ui.returnButton, SIGNAL(clicked()), this, SLOT(Onreturn()));
	connect(ui.addButton, SIGNAL(clicked()), this, SLOT(Onadd()));

	Onload();//加载已存储信息
}

Number_assistant::~Number_assistant()
{
	Onreturn();
	Onstorage();//存储已有的信息
}



bool Number_assistant::setHead()
{
	Model->setColumnCount(11);
	//姓名、城市、手机号码、住宅电话号码、办公电话号码、电子邮件、公司、地址、添加时间、所属群组、备注
	Model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("姓名"));
	Model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("城市"));
	Model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("手机号码"));
	Model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("住宅电话号码"));
	Model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("办公电话号码"));
	Model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("电子邮件"));
	Model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("公司"));
	Model->setHeaderData(7, Qt::Horizontal, QString::fromLocal8Bit("地址"));
	Model->setHeaderData(8, Qt::Horizontal, QString::fromLocal8Bit("添加时间"));
	Model->setHeaderData(9, Qt::Horizontal, QString::fromLocal8Bit("所属群组"));
	Model->setHeaderData(10, Qt::Horizontal, QString::fromLocal8Bit("备注"));
	return false;
}

bool Number_assistant::Onstorage()
{
	int rows = Model->rowCount();
	int columns = Model->columnCount();
	if (rows == -1 || columns == -1)
		return false;

	QFile File("SaveDate.dat");
	File.open(QIODevice::WriteOnly);
	QDataStream out(&File);
	QString str;
	QStandardItem *textstr = NULL;
	out << (qint32)rows;
	out << (qint32)columns;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			textstr = Model->item(i,j);
			str = textstr->text();
			out << str;
		}
	File.close();
	return true;
}

bool Number_assistant::Onload()
{
	struct stat buf;//显示文件状态信息;
	int result = 0;
	result = stat("SaveDate.dat", &buf);
	if (buf.st_size == 0)
		return false;

	QFile File("SaveDate.dat");
	File.open(QIODevice::ReadOnly);
	QDataStream in(&File);
	int rows = 0;
	int columns = 0;
	in >> rows;
	in >> columns;

	QString **tabeDate = new QString*[rows];
	for (int i = 0; i < rows; i++)
	{
	 	tabeDate[i] = new QString[columns];
	}
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
			in >> tabeDate[i][j];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < columns; j++)
		{
			Model->setItem(i, j, new QStandardItem(tabeDate[i][j]));
		}


	for (int i = 0; i < rows; i++)
		delete[] tabeDate[i];
	delete[] tabeDate;

	return false;
}


bool Number_assistant::OnOpenImport()
{
	//model->setItem(0, 0, new QStandardItem(QString::fromLocal8Bit("湛邦")));
	//model->setItem(0, 1, new QStandardItem(QString::fromLocal8Bit("齐齐哈尔")));
	QString file_name = QFileDialog::getOpenFileName(this, "Open File");
	QByteArray tem = file_name.toLocal8Bit();
	const char * filename = tem.data();
	fstream file;
	file.open(filename, ios::in);
	if (!file.good())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("警告！"), QString::fromLocal8Bit("文件打开错误！"));
		return false;
	}
	char *words = new char[Column_Size];
	for (int i = 0; i < Column_Size; i++)
	{
		words[i] = '\0';
	}
	int postion = 0;
	int rows = Model->rowCount();
	QString Item[10];
	while (!file.eof())
	{
		file >> words;
		Item[postion] = QString::fromLocal8Bit(words);
		postion++;
		if (postion == 10)
		{
			for (int i = 0; i < 8; i++)
			{
				Model->setItem(rows, i, new QStandardItem(Item[i]));
			}
			Model->setItem(rows, 8, new QStandardItem(Item[8] + " " + Item[9]));
			Model->setItem(rows, 9, new QStandardItem());
			Model->setItem(rows, 10, new QStandardItem());
			postion = 0;
			rows++;
		}
	}
	file.close();
	return true;
}


bool Number_assistant::Onexport()
{
	int rows = Model->rowCount();
	int columns = Model->columnCount();
	if (rows == -1 || columns == -1)
		return false;

	QString str;
	QStandardItem *textstr = NULL;

	fstream file("export.txt", ios::out);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			textstr = Model->item(i, j);
			str = textstr->text();
			file << str.toLocal8Bit().data();
			file << " ";
		}
		file << "\n";
	}
	file.close();
	QMessageBox::information(this, QString::fromLocal8Bit("成功导出"), QString::fromLocal8Bit("已导出到export.txt"));
	return false;
}

bool Number_assistant::OnSearch()
{
	int index = ui.comboBox->currentIndex();
	QString keywords = ui.lineEdit->text();
	if (keywords.isEmpty())
		return false;
	Model = new QStandardItemModel();
	setHead();
	ui.tableView->setModel(Model);

	int prerow = 0;
	int rows = reModel->rowCount();
	int columns = reModel->columnCount();
	QString textstr;
	if (index == 1 || index == 9 || index == 6 || index == 7)//组群、城市、地址、公司查找     遍历
	{
		for (int i = 0; i < rows; i++)
		{
			textstr = reModel->item(i, index)->text();
			if (textstr.indexOf(keywords) == 0)
			{
				for (int j = 0; j < columns; j++)
				{
					Model->setItem(prerow, j, new QStandardItem(reModel->item(i, j)->text()));
				}
				prerow++;
			}
		}

	}
	else
	{
		BST findIndex(reModel->item(0, index)->text(), 0);//其他的创建bst树再查找
		for (int i = 1; i < rows; i++)
		{
			textstr = reModel->item(i, index)->text();
			findIndex.build(textstr, i);
		}
		int postion = 0;
		postion = findIndex.findNode(keywords);
		if (postion != -1)
		{
			for (int j = 0; j < columns; j++)
			{
				Model->setItem(prerow, j, new QStandardItem(reModel->item(postion, j)->text()));
			}
			prerow++;
		}
		else
		{
			return false;
		}
	}

	return false;
}

bool Number_assistant::Onedit()
{
	int Row = ui.tableView->currentIndex().row();
	int Column = ui.tableView->currentIndex().column();
	if (Row == -1 || Column == -1)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit("请点击选择需要删除的单元格"));
		return false;
	}
	QModelIndex index = Model->index(Row, Column);
	QString str = index.data().toString();
	editwidget editcell(this);
	editcell.showCell(&str);
	editcell.exec();
	Model->setItem(Row, Column, new QStandardItem(str));
	return true;
}

bool Number_assistant::Ondelete()
{
	int Row = ui.tableView->currentIndex().row();
	if (Row == -1)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("提示！"), QString::fromLocal8Bit("请点击选择需要删除的单行"));
		return false;
	}
	Model->removeRow(Row);
	return true;
}

bool Number_assistant::Onreturn()
{
	Model = reModel;
	ui.tableView->setModel(Model);
	return false;
}

bool Number_assistant::Onadd()
{
	QString item[11];
	addRow addArow;
	addArow.reString(item);
	addArow.exec();
	bool isempty = true;
	for (int i = 0; i < 11; i++)
	{
		if (!item[i].isEmpty())
		{
			isempty = false;
		}
	}
	int preRow = Model->rowCount();
	if (!isempty)
	{
		for (int i = 0; i < 11; i++)
		{
			Model->setItem(preRow, i, new QStandardItem(item[i]));
		}
		QMessageBox::information(this, QString::fromLocal8Bit("添加成功！"), QString::fromLocal8Bit("已在添加到")+preRow+ QString::fromLocal8Bit("行"));
	}
	return false;
}
