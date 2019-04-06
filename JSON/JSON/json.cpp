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
		QMessageBox::warning(this, QString::fromLocal8Bit("���棡"), QString::fromLocal8Bit("�ļ��򿪴���"));
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
	

	//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ����"));
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
	bool colon = 0;//ǰһ���Ƿ��� :   
	bool quotes = 0;// " 
	int isarray = -1;// �Ƿ�������,-1����,����0����
	QStandardItem* preitem = NULL;
	QStandardItem* temitem = NULL;
	double d_tem = 0;//��rowValueת����double
	bool isDouble = 0;//��rowValueת����int,�Ƿ�ɹ�
	bool isContinue = 1;//�����Ƿ���Լ�������
	if (text.at(0) == '"'&&text.at(size - 1) == '"')//����"����"
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
	for (int i = 0; i < size; i++)//����{����}��[����]
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
			if (!isContinue)//���ܼ���
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			isContinue = 1;
			arrayNum++;//�����Ŷ�һ��;

			if (isarray >= 0 && arrayNum > 1)//�����е�����
			{
				if (!rowName.isEmpty() || colon)
				{
					model->clear();
					//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ����"));
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
					return false;
				}
				temitem = new QStandardItem(QIcon(":/JSON/Resources/array.gif"), QString::number(isarray, 10));
				isarray++;
				isArray.push(isarray);//�洢�±�
				isarray = 0;//�����µ��±�
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
			isarray = 0;//�����飬����������;
			if (arrayNum == 1 && objectNum == 0)//������һ�е�JSON;
			{
				jsonitem = new QStandardItem(QIcon(":/JSON/Resources/array.gif"), "JSON");
				item_stack.push(jsonitem);
				preitem = jsonitem;
				model->appendRow(jsonitem);
				continue;
			}
			if (!rowName.isEmpty() && colon == 1)//rowName��Ϊ�գ����и� ��
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
				//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ����"));
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10)+QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
		}
		if (text.at(i) == ']'&&quotes == 0)
		{
			isContinue = 0;
			if ((rowValue.isEmpty() && rowName.isEmpty()) && temitem != NULL)//rowName��rowValueΪ�� ��temitem��Ϊ��
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			if (!rowName.isEmpty() && rowValue.isEmpty())//rowName��Ϊ�գ�rowValueΪ��
			{
				if (isarray >= 0)//�����е��ַ���
				{
					temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), QString::number(isarray, 10) + ":" + rowName);
					isarray++;
					//isArray.push(isarray);//�洢��ǰ�±�
					isarray = 0;//�����µ��±�
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
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
					return false;
				}
				arrayNum--;//��������һ��;
				isarray = isArray.top();//��һ�����ڵ��Ƿ�������;
				isArray.pop();
				item_stack.pop();
				if (item_stack.size() != 0)
					preitem = item_stack.top();//����һ�����ڵ�;
				colon = 0;
				continue;
			}
			if (!rowValue.isEmpty() && !rowName.isEmpty() /*&& temitem != NULL*/)//�������һ��
			{
				delete temitem;
				d_tem = rowValue.toDouble(&isDouble);
				if (isDouble)//rowValue������;
					temitem = new QStandardItem(QIcon(":/JSON/Resources/green.gif"), rowName + ":" + rowValue);
				else
				{
					if (rowValue == "true" || rowValue == "false")//rowValue��bool�͵�
						temitem = new QStandardItem(QIcon(":/JSON/Resources/yellow.gif"), rowName + ":" + rowValue);
					else
					{
						if (rowValue.at(0) == '"'&&rowValue.at(rowValue.length() - 1) == '"')//rowValue���ַ�������ͷβ���� "
							temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), rowName + ":" + rowValue);
						else
						{
							model->clear();
							QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
							return false;
						}
					}
				}
				preitem->appendRow(temitem);
				rowValue.clear();
				rowName.clear();
				temitem = NULL;
			}
			arrayNum--;//��������һ��;
			isarray = isArray.top();//��һ�����ڵ��Ƿ�������;
			isArray.pop();
			item_stack.pop();
			if (item_stack.size() != 0)
				preitem = item_stack.top();//����һ�����ڵ�;
			colon = 0;
			continue;
		}
		if (text.at(i) == '{'&&quotes == 0)
		{
			if (!isContinue)//���ܼ���
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			isContinue = 1;
			objectNum++;//�����Ŷ�һ��;
			if (isarray >= 0 && arrayNum > 0)//�����еĶ���
			{
				if (!rowName.isEmpty() || colon)
				{
					model->clear();
					//QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ����"));
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
					return false;
				}
				temitem = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), QString::number(isarray, 10));
				isarray++;
				isArray.push(isarray);//�洢�±�
				item_stack.push(temitem);
				preitem->appendRow(temitem);
				preitem = temitem;
				temitem = NULL;
				colon = 0;
				rowName.clear();
				rowValue.clear();
 				isarray = -1;//��������;
				continue;
			}
			isarray = -1;//��������;
			isArray.push(isarray);
			if (objectNum == 1 && arrayNum == 0)//������һ�е�JSON;
			{
				jsonitem = new QStandardItem(QIcon(":/JSON/Resources/object.gif"), "JSON");
				item_stack.push(jsonitem);
				preitem = jsonitem;
				model->appendRow(jsonitem);
				continue;
			}
			if (!rowName.isEmpty() && colon == 1)//rowName��Ϊ�գ����и� ��
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
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			continue;
		}
		if (text.at(i) == '}'&&quotes == 0)
		{
			isContinue = 0;
			if (temitem != NULL && (rowValue.isEmpty() || rowName.isEmpty()))//ǰ���ж��� ��rowName��rowValueΪ��
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			if (!rowValue.isEmpty() && !rowName.isEmpty() /*&& temitem != NULL*/)//�������һ��
			{
				delete temitem;
				d_tem = rowValue.toDouble(&isDouble);
				if (isDouble)//rowValue������;
					temitem = new QStandardItem(QIcon(":/JSON/Resources/green.gif"), rowName + ":" + rowValue);
				else
				{
					if (rowValue == "true" || rowValue == "false")//rowValue��bool�͵�
						temitem = new QStandardItem(QIcon(":/JSON/Resources/yellow.gif"), rowName + ":" + rowValue);
					else
					{
						if (rowValue.at(0) == '"'&&rowValue.at(rowValue.length() - 1) == '"')//rowValue���ַ�������ͷβ���� "
							temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), rowName + ":" + rowValue);
						else
						{
							model->clear();
							QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
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
			isarray = isArray.top();//��һ�����ڵ��Ƿ�������;
			isArray.pop();
			item_stack.pop();
			if (item_stack.size() != 0)
				preitem = item_stack.top();//����һ�����ڵ�;
			colon = 0;
			continue;
		}
		if (text.at(i) == ':'&&quotes == 0)
		{
			if (isContinue == 0)
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			isContinue = 1;
			colon = 1;//���� ��
			if (rowName.isEmpty())
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			continue;
		}
		if (text.at(i) == '"')
		{
			quotes = 1 - quotes;
			//quotes ����0��Ϊ�ڶ���"������1��Ϊ��һ��"
			if (colon == 0)//ð��֮ǰ;
			{
				if (rowName.size() == 0)//rowNameΪ��;
				{
					if (quotes == 0)//�ǵڶ���"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
						return false;
					}
					rowName = '"';
				}
				else//rowName��Ϊ��;
				{
					if (quotes == 1)//�ǵ�һ��"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
						return false;
					}
					rowName = rowName + '"';
				}
			}
			else//ð��֮��;
			{
				if (rowValue.size() == 0)//rowValueΪ��;
				{
					if (quotes == 0)//�ǵڶ���"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
						return false;
					}
					rowValue = '"';
				}
				else//rowValue��Ϊ��;
				{
					if (quotes == 1)//�ǵ�һ��"
					{
						model->clear();
						QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
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
			if (colon == 0 && rowName.isEmpty() && rowValue.isEmpty() && temitem == NULL)//ǰһ���� } �� ]
			{
				temitem = new QStandardItem;
				continue;
			}
			if (!rowName.isEmpty() && rowValue.isEmpty())//rowName��Ϊ�գ�rowValueΪ��
			{
				if (isarray >= 0)//�����е�����
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
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
					return false;
				}
				rowValue.clear();
				rowName.clear();
				temitem = new QStandardItem;
				colon = 0;
				continue;
			}
			if (!rowName.isEmpty() && !rowValue.isEmpty() && colon == 1)//���ƺ�ֵ��Ϊ�� �У�
			{
				d_tem = rowValue.toDouble(&isDouble);
				if (isDouble)//rowValue������;
					temitem = new QStandardItem(QIcon(":/JSON/Resources/green.gif"), rowName + ":" + rowValue);
				else
				{
					if (rowValue=="true"||rowValue=="false")//rowValue��bool�͵�
						temitem = new QStandardItem(QIcon(":/JSON/Resources/yellow.gif"), rowName + ":" + rowValue);
					else
					{
						if (rowValue.at(0) == '"'&&rowValue.at(rowValue.length() - 1) == '"')//rowValue���ַ�������ͷβ���� "
							temitem = new QStandardItem(QIcon(":/JSON/Resources/blue.gif"), rowName + ":" + rowValue);
						else
						{
							model->clear();
							QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
							return false;
						}
					}
				}
			}
			else//���ƺ�ֵ��һ��Ϊ��
			{
				model->clear();
				QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
				return false;
			}
			preitem->appendRow(temitem);
			rowValue.clear();
			rowName.clear();
			temitem = new QStandardItem;
			colon = 0;
			continue;
		}

		if (colon != 1 && quotes != 1)//����""�У�ǰ��Ҳû�У�
		{
			model->clear();
			QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
			return false;
		}
		else
		{
			if (colon == 1)//���� ��֮���ֵ;
			{
				if (rowName.isEmpty())//���������û������;
				{
					model->clear();
					QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ���󣬵�") + QString::number(i, 10) + QString::fromLocal8Bit("���ֽ�"));
					return false;
				}
// 				else
// 					rowValue = rowValue + text.at(i);
			}
			if (quotes == 1)//����"֮���ֵ;
			{
				if (colon == 1)//�������������ֵ;
				{
					rowValue = rowValue +  text.at(i);
				}
				else//�����������������;
				{
					rowName = rowName + text.at(i);
				}
			}
			else//���ֻ�true��false
			{
				if (colon == 1)//�������������ֵ;
				{
					rowValue = rowValue + text.at(i);
				}
				else//�����������������;
				{
					rowName = rowName + text.at(i);
				}
			}
		}
	}
	if (objectNum != 0 || arrayNum != 0)//���Ų�ƥ��
	{
		model->clear();
		QMessageBox::warning(this, "Error!!!", QString::fromLocal8Bit("��ʽ����"));
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
	OnConpress();//��ѹ��
	QString text = ui.textEdit->toPlainText();
	ui.textEdit->clear();
	int size = text.size();
	QString temtext;
	int brackets = 0;//��������
	bool quotes = 0;
	for (int i = 0; i < size; i++)
	{
		if ((text.at(i) == '{' || text.at(i) == '[') && quotes != 1)
		{
			temtext = temtext + text.at(i);
			for (int j = 0; j < brackets; j++)//��һ�������žͼ������ո�
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
			for (int j = 0; j < brackets; j++)//��һ�������žͼ������ո�
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
			for (int j = 0; j < brackets; j++)//��һ�������žͼ������ո�
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
