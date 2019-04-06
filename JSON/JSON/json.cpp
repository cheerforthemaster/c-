#include "json.h"

JSON::JSON(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.action_3, SIGNAL(triggered()), this, SLOT(OnCopyAction()));
	connect(ui.action_4, SIGNAL(triggered()), this, SLOT(OnPasteAction()));
	connect(ui.action_5, SIGNAL(triggered()), this, SLOT(OnClearAction()));
	connect(ui.action_6, SIGNAL(triggered()), this, SLOT(OnOpenAction()));
	connect(ui.action_7, SIGNAL(triggered()), this, SLOT(OnSaveAction()));
	connect(ui.action, SIGNAL(triggered()), this, SLOT(OnSaveAsAction()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(OnProcesseText()));
	connect(ui.action_8, SIGNAL(triggered()), this, SLOT(OnConpress()));
	connect(ui.action_2, SIGNAL(triggered()), this, SLOT(OnFormat()));
}

JSON::~JSON()
{

}

bool JSON::OnOpenAction()
{
	file_name = QFileDialog::getOpenFileName(this, "Open File");
	QByteArray tem = file_name.toLocal8Bit();
	const char * filename = tem.data();
	fstream file;
	file.open(filename, ios::in);
	if (!file.good())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("警告！"), QString::fromLocal8Bit("文件打开错误！"));
		return false;
	}
	ui.textEdit->clear();
	QString text;
	file.seekg(0, ios::end);
	long size = file.tellg();
	file.seekg(0, ios::beg);
	char* ch_text = new char[size + 1];
	for (int i = 0; i < size + 1; i++)
		ch_text[i] = '\0';
	file.read(ch_text, size);
	text = ch_text;
	ui.textEdit->setText(text);
	file.close();
	return false;
}

bool JSON::OnSaveAction()
{
	if (file_name.isEmpty())
		OnSaveAsAction();
	else
	{
		QByteArray tem = file_name.toLocal8Bit();
		const char * filename = tem.data();
		fstream file;
		file.open(filename, ios::out);
		QString text;
		text = ui.textEdit->toPlainText();
		long size = text.size();
		tem = text.toLocal8Bit();
		const char* ch_text = tem.data();
		file.write(ch_text, size);
		file.close();
	}
	return false;
}

bool JSON::OnCopyAction()
{
	ui.textEdit->copy();
	return true;
}

bool JSON::OnPasteAction()
{
	ui.textEdit->paste();
	return true;
}

bool JSON::OnClearAction()
{
	ui.textEdit->clear();
	return true;
}

bool JSON::OnSaveAsAction()
{
	file_name = QFileDialog::getSaveFileName(this, "Save json", "", "json Files (*.json)");
	OnSaveAction();
	return false;
}

bool JSON::OnProcesseText()
{
	
	QString text = ui.textEdit->toPlainText();
	if (text.isEmpty())
		return false;

	QStandardItemModel* model = new QStandardItemModel(ui.treeView);
	ui.treeView->setModel(model);
// 	QStandardItem* itemProject = new QStandardItem(QIcon(":/JSON/Resources/array.gif"), "JSON");
// 	model->appendRow(itemProject);
// 	itemProject = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), "treeItem");
// 	model->appendRow(itemProject);
// 	QStandardItem* temProject = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), "tree");
// 	itemProject->appendRow(temProject);
	

	//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误"));
	//model->clear();
	//return false;
	QString rowName;
	QString rowValue;
	stack<QStandardItem*> item_stack;
	stack<int> isArray;
	QStandardItem* jsonitem = NULL;
	int int_tem = 0;
	int size = text.size();
	int arrayNum = 0;//[]
	int objectNum = 0;//{}
	bool colon = 0;//前一个是否是 :   
	bool quotes = 0;// " 
	int isarray = -1;// 是否是数组,-1不是,大于0就是
	QStandardItem* preitem = NULL;
	QStandardItem* temitem = NULL;
	double d_tem = 0;//将rowValue转化成double
	bool isDouble = 0;//将rowValue转化成int,是否成功
	bool isContinue = 1;//后面是否可以继续加行
	if (text.at(0) == '"'&&text.at(size - 1) == '"')//形如"……"
	{
		jsonitem = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), "JSON");
		model->appendRow(jsonitem);
		for (int i = 1; i < size - 1; i++)
		{
			temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), QString::number(i, 10) + ":" + '"' + text.at(i) + '"' + ',');
			jsonitem->appendRow(temitem);
		}
		return true;
	}
	QChar textAT;
	for (int i = 0; i < size; i++)//形如{……}或[……]
	{
		textAT = text.at(i);
		if ((text.at(i) == '\n' || text.at(i) == ' ' || text.at(i) == '\r' || text.at(i) == '\t') && quotes != 1)
		{
			continue;
		}
		if (i == 254)
		{
			textAT = text.at(i);
		}
		if (text.at(i) == '['&&quotes == 0)
		{
			if (!isContinue)//不能加行
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			isContinue = 1;
			arrayNum++;//方括号多一组;

			if (isarray >= 0 && arrayNum > 1)//数组中的数组
			{
				if (!rowName.isEmpty() || colon)
				{
					model->clear();
					//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误"));
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
					return false;
				}
				temitem = new QStandardItem(QIcon(":/JSON/Resources/array.gif"), QString::number(isarray, 10));
				isarray++;
				isArray.push(isarray);//存储下标
				isarray = 0;//创建新的下标
				//isArray.push(isarray);
				item_stack.push(temitem);
				preitem->appendRow(temitem);
				preitem = temitem;
				temitem = NULL;
				colon = 0;
				rowName.clear();
				rowValue.clear();
				continue;
			}
			isArray.push(isarray);
			isarray = 0;//是数组，即在数组中;
			if (arrayNum == 1 && objectNum == 0)//创建第一行的JSON;
			{
				jsonitem = new QStandardItem(QIcon(":/JSON/Resources/array.gif"), "JSON");
				item_stack.push(jsonitem);
				preitem = jsonitem;
				model->appendRow(jsonitem);
				continue;
			}
			if (!rowName.isEmpty() && colon == 1)//rowName不为空，且有个 ：
			{
				temitem = new QStandardItem(QIcon(":/JSON/Resources/array.gif"), rowName);
				item_stack.push(temitem);
				preitem->appendRow(temitem);
				preitem = temitem;
				temitem = NULL;
				colon = 0;
				rowName.clear();
				rowValue.clear();
				continue;
			}
			else
			{
				model->clear();
				//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误"));
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10)+QString::fromLocal8Bit("个字节"));
				return false;
			}
		}
		if (text.at(i) == ']'&&quotes == 0)
		{
			isContinue = 0;
			if ((rowValue.isEmpty() && rowName.isEmpty()) && temitem != NULL)//rowName和rowValue为空 且temitem不为空
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			if (!rowName.isEmpty() && rowValue.isEmpty())//rowName不为空，rowValue为空
			{
				if (isarray >= 0)//数组中的字符串
				{
					temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), QString::number(isarray, 10) + ":" + rowName);
					isarray++;
					//isArray.push(isarray);//存储当前下标
					isarray = 0;//创建新的下标
					//isArray.push(isarray);
					//item_stack.push(temitem);
					preitem->appendRow(temitem);
					preitem = temitem;
					temitem = NULL;
					colon = 0;
					rowName.clear();
					rowValue.clear();
				}
				else
				{
					model->clear();
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
					return false;
				}
				arrayNum--;//方括号少一组;
				isarray = isArray.top();//上一个父节点是否是数组;
				isArray.pop();
				item_stack.pop();
				if (item_stack.size() != 0)
					preitem = item_stack.top();//到上一个父节点;
				colon = 0;
				continue;
			}
			if (!rowValue.isEmpty() && !rowName.isEmpty() /*&& temitem != NULL*/)//补充最后一行
			{
				delete temitem;
				d_tem = rowValue.toDouble(&isDouble);
				if (isDouble)//rowValue是数字;
					temitem = new QStandardItem(QIcon(":/JSON/Resources/green.gif"), rowName + ":" + rowValue);
				else
				{
					if (rowValue == "true" || rowValue == "false")//rowValue是bool型的
						temitem = new QStandardItem(QIcon(":/JSON/Resources/yellow.gif"), rowName + ":" + rowValue);
					else
					{
						if (rowValue.at(0) == '"'&&rowValue.at(rowValue.length() - 1) == '"')//rowValue是字符串，且头尾都是 "
							temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), rowName + ":" + rowValue);
						else
						{
							model->clear();
							QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
							return false;
						}
					}
				}
				preitem->appendRow(temitem);
				rowValue.clear();
				rowName.clear();
				temitem = NULL;
			}
			arrayNum--;//方括号少一组;
			isarray = isArray.top();//上一个父节点是否是数组;
			isArray.pop();
			item_stack.pop();
			if (item_stack.size() != 0)
				preitem = item_stack.top();//到上一个父节点;
			colon = 0;
			continue;
		}
		if (text.at(i) == '{'&&quotes == 0)
		{
			if (!isContinue)//不能加行
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			isContinue = 1;
			objectNum++;//花括号多一组;
			if (isarray >= 0 && arrayNum > 0)//数组中的对象
			{
				if (!rowName.isEmpty() || colon)
				{
					model->clear();
					//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误"));
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
					return false;
				}
				temitem = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), QString::number(isarray, 10));
				isarray++;
				isArray.push(isarray);//存储下标
				item_stack.push(temitem);
				preitem->appendRow(temitem);
				preitem = temitem;
				temitem = NULL;
				colon = 0;
				rowName.clear();
				rowValue.clear();
 				isarray = -1;//不是数组;
				continue;
			}
			isarray = -1;//不是数组;
			isArray.push(isarray);
			if (objectNum == 1 && arrayNum == 0)//创建第一行的JSON;
			{
				jsonitem = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), "JSON");
				item_stack.push(jsonitem);
				preitem = jsonitem;
				model->appendRow(jsonitem);
				continue;
			}
			if (!rowName.isEmpty() && colon == 1)//rowName不为空，且有个 ：
			{
				temitem = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), rowName);
				item_stack.push(temitem);
				preitem->appendRow(temitem);
				preitem = temitem;
				temitem = NULL;
				colon = 0;
				rowName.clear();
				rowValue.clear();
				continue;
			}
			else
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			continue;
		}
		if (text.at(i) == '}'&&quotes == 0)
		{
			isContinue = 0;
			if (temitem != NULL && (rowValue.isEmpty() || rowName.isEmpty()))//前面有逗号 但rowName或rowValue为空
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			if (!rowValue.isEmpty() && !rowName.isEmpty() /*&& temitem != NULL*/)//补充最后一行
			{
				delete temitem;
				d_tem = rowValue.toDouble(&isDouble);
				if (isDouble)//rowValue是数字;
					temitem = new QStandardItem(QIcon(":/JSON/Resources/green.gif"), rowName + ":" + rowValue);
				else
				{
					if (rowValue == "true" || rowValue == "false")//rowValue是bool型的
						temitem = new QStandardItem(QIcon(":/JSON/Resources/yellow.gif"), rowName + ":" + rowValue);
					else
					{
						if (rowValue.at(0) == '"'&&rowValue.at(rowValue.length() - 1) == '"')//rowValue是字符串，且头尾都是 "
							temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), rowName + ":" + rowValue);
						else
						{
							model->clear();
							QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
							return false;
						}
					}
				}
				preitem->appendRow(temitem);
				rowValue.clear();
				rowName.clear();
				temitem = NULL;
			}
			objectNum--;
			isarray = isArray.top();//上一个父节点是否是数组;
			isArray.pop();
			item_stack.pop();
			if (item_stack.size() != 0)
				preitem = item_stack.top();//到上一个父节点;
			colon = 0;
			continue;
		}
		if (text.at(i) == ':'&&quotes == 0)
		{
			if (isContinue == 0)
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			isContinue = 1;
			colon = 1;//到了 ：
			if (rowName.isEmpty())
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			continue;
		}
		if (text.at(i) == '"')
		{
			quotes = 1 - quotes;
			//quotes 等于0则为第二个"，等于1则为第一个"
			if (colon == 0)//冒号之前;
			{
				if (rowName.size() == 0)//rowName为空;
				{
					if (quotes == 0)//是第二个"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
						return false;
					}
					rowName = '"';
				}
				else//rowName不为空;
				{
					if (quotes == 1)//是第一个"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
						return false;
					}
					rowName = rowName + '"';
				}
			}
			else//冒号之后;
			{
				if (rowValue.size() == 0)//rowValue为空;
				{
					if (quotes == 0)//是第二个"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
						return false;
					}
					rowValue = '"';
				}
				else//rowValue不为空;
				{
					if (quotes == 1)//是第一个"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
						return false;
					}
					rowValue = rowValue + '"';
				}
			}
			continue;
		}
		if (text.at(i) == ','&&quotes == 0)
		{
			isContinue = 1;
			if (colon == 0 && rowName.isEmpty() && rowValue.isEmpty() && temitem == NULL)//前一个是 } 或 ]
			{
				temitem = new QStandardItem;
				continue;
			}
			if (!rowName.isEmpty() && rowValue.isEmpty())//rowName不为空，rowValue为空
			{
				if (isarray >= 0)//数组中的数组
				{
					temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), QString::number(isarray, 10) + ":" + rowName);
					isarray++;
					preitem->appendRow(temitem);
					colon = 0;
					temitem = NULL;
					rowName.clear();
					rowValue.clear();
				}
				else
				{
					model->clear();
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
					return false;
				}
				rowValue.clear();
				rowName.clear();
				temitem = new QStandardItem;
				colon = 0;
				continue;
			}
			if (!rowName.isEmpty() && !rowValue.isEmpty() && colon == 1)//名称和值不为空 有：
			{
				d_tem = rowValue.toDouble(&isDouble);
				if (isDouble)//rowValue是数字;
					temitem = new QStandardItem(QIcon(":/JSON/Resources/green.gif"), rowName + ":" + rowValue);
				else
				{
					if (rowValue=="true"||rowValue=="false")//rowValue是bool型的
						temitem = new QStandardItem(QIcon(":/JSON/Resources/yellow.gif"), rowName + ":" + rowValue);
					else
					{
						if (rowValue.at(0) == '"'&&rowValue.at(rowValue.length() - 1) == '"')//rowValue是字符串，且头尾都是 "
							temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), rowName + ":" + rowValue);
						else
						{
							model->clear();
							QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
							return false;
						}
					}
				}
			}
			else//名称和值有一个为空
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
				return false;
			}
			preitem->appendRow(temitem);
			rowValue.clear();
			rowName.clear();
			temitem = new QStandardItem;
			colon = 0;
			continue;
		}

		if (colon != 1 && quotes != 1)//不在""中，前面也没有：
		{
			model->clear();
			QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
			return false;
		}
		else
		{
			if (colon == 1)//处理 ：之后的值;
			{
				if (rowName.isEmpty())//对象或数组没有名字;
				{
					model->clear();
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误，第") + QString::number(i, 10) + QString::fromLocal8Bit("个字节"));
					return false;
				}
// 				else
// 					rowValue = rowValue + text.at(i);
			}
			if (quotes == 1)//处理"之后的值;
			{
				if (colon == 1)//处理数组或对象的值;
				{
					rowValue = rowValue +  text.at(i);
				}
				else//处理数组或对象的名称;
				{
					rowName = rowName + text.at(i);
				}
			}
			else//数字或true或false
			{
				if (colon == 1)//处理数组或对象的值;
				{
					rowValue = rowValue + text.at(i);
				}
				else//处理数组或对象的名称;
				{
					rowName = rowName + text.at(i);
				}
			}
		}
	}
	if (objectNum != 0 || arrayNum != 0)//括号不匹配
	{
		model->clear();
		QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("格式错误"));
		return false;
	}

	return true;
}

bool JSON::OnConpress()
{
	bool quotes = 0;
	QString text = ui.textEdit->toPlainText();
	int size = text.size();
	QString temtext;
	for (int i = 0; i < size; i++)
	{
		if ((text.at(i) == '\n' || text.at(i) == ' ' || text.at(i) == '\r' || text.at(i) == '\t') && quotes != 1)
		{
			continue;
		}
		else
		{
			temtext = temtext + text.at(i);
		}
		if (text.at(i) == '"')
		{
			quotes = 1 - quotes;
		}
	}
	ui.textEdit->setText(temtext);
	return false;
}

bool JSON::OnFormat()
{
	OnConpress();//先压缩
	QString text = ui.textEdit->toPlainText();
	ui.textEdit->clear();
	int size = text.size();
	QString temtext;
	int brackets = 0;//左括号数
	bool quotes = 0;
	for (int i = 0; i < size; i++)
	{
		if ((text.at(i) == '{' || text.at(i) == '[') && quotes != 1)
		{
			temtext = temtext + text.at(i);
			for (int j = 0; j < brackets; j++)//有一个左括号就加两个空格
			{
				temtext = "  " + temtext;
			}
			ui.textEdit->append(temtext);
			temtext.clear();
			brackets++;
			continue;
		}
		if ((text.at(i) == '}' || text.at(i) == ']') && quotes != 1)
		{
			for (int j = 0; j < brackets; j++)//有一个左括号就加两个空格
			{
				temtext = "  " + temtext;
			}
			ui.textEdit->append(temtext);
			temtext = text.at(i);
			brackets--;
			continue;
		}
		if (text.at(i) == ','&& quotes != 1)
		{
			temtext = temtext + text.at(i);
			for (int j = 0; j < brackets; j++)//有一个左括号就加两个空格
			{
				temtext = "  " + temtext;
			}
			ui.textEdit->append(temtext);
			temtext.clear();
			continue;
		}
		if (text.at(i) == '"')
		{
			quotes = 1 - quotes;
		}
		temtext = temtext + text.at(i);
	}
	if ((temtext == "}" || temtext == "]") && quotes != 1)
	{
		for (int j = 0; j < brackets; j++)
		{
			temtext = "  " + temtext;
		}
		ui.textEdit->append(temtext);
	}
	return false;
}
