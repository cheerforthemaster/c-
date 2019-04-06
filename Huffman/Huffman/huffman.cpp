#include "huffman.h"

Huffman::Huffman(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.OKButton,SIGNAL(clicked()),this,SLOT(OnOKBtn()));
	connect(ui.chooseButton, SIGNAL(clicked()), this, SLOT(OnchooseBtn()));
	connect(ui.compressionButton, SIGNAL(clicked()), this, SLOT(OncomBtn()));
	connect(ui.decompressionButton, SIGNAL(clicked()), this, SLOT(OndecomBtn()));
	connect(ui.clearButton, SIGNAL(clicked()), this, SLOT(OnclearBtn()));
	connect(ui.lineEdit, SIGNAL(returnPressed()), ui.OKButton, SIGNAL(clicked()));

	tree = NULL;
	thesize = 4 * 1024 * 1024;
	everyreadchar = new unsigned char[thesize + 1];
	everywritechar = new unsigned char[thesize + 2];
	ascint = new long[256];
	for (int i = 0; i < 256; i++)
		ascint[i] = 0;
	huffman = new unsigned int*[256];
	for (int i = 0; i < 256; i++)
		huffman[i] = new unsigned int[2];
	for (int i = 0; i < 256; i++)
	{
		huffman[i][0] = 0;
		huffman[i][1] = 0;
	}

}

Huffman::~Huffman()
{
	delete[] everyreadchar;
	delete[] ascint;

	for (int i = 0; i < 256; i++)
		delete[] huffman[i];
	delete[] huffman;
}

bool Huffman::IsFile()
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

bool Huffman::OnOKBtn()
{
	Q_filename = ui.lineEdit->text();
	QByteArray bty = Q_filename.toLocal8Bit();
	const char* c_filename = bty.data();
	if (!IsFile())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ�������"));
		OnclearBtn();
		return false;
	}
	stat(c_filename, &buf);
	ui.textEdit->setText(QString::fromLocal8Bit("��ѡ����ļ���") + Q_filename);
	ui.textEdit->append(QString::fromLocal8Bit("�ļ���С��")+QString::number(buf.st_size)+ QString::fromLocal8Bit("�ֽ�"));
	return false;
}

bool Huffman::minasc(int &sub)
{
	sub = -1;
	int minNum = -1;
	for (int i = 0; i < 256; i++)//ȡascint�����в�Ϊ0��ֵ
	{
		if (ascint[i] != 0)
		{
			minNum = ascint[i];
			break;
		}
	}
	if (minNum == -1)//ûȡ��;
		return false;
	for (int i = 0; i < 256; i++)
	{
		if (ascint[i] != 0 && ascint[i] <= minNum)
		{
			minNum = ascint[i];
			sub = i;
		}
	}
	if (sub == -1)
		return false;
	else
		return true;
}

bool Huffman::initializeReadchar()
{
	for (int i = 0; i < thesize + 1; i++)
		everyreadchar[i] = '\0';
	return true;
}

bool Huffman::initializeWritechar()
{
	for (int i = 1; i < thesize + 2; i++)
		everywritechar[i] = 0;
	return true;
}


bool Huffman::OnchooseBtn()
{
	QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ���ļ�"));
	if (filename.length() > 0)
	{
		ui.lineEdit->setText(filename);
		OnOKBtn();
		return true;
	}
	else
		return false;
}

bool Huffman::OnclearBtn()
{
	ui.lineEdit->clear();
	ui.textEdit->clear();
	Q_filename.clear();
	return false;
}

bool Huffman::OncomBtn()
{
	Q_filename = ui.lineEdit->text();
	QByteArray bty = Q_filename.toLocal8Bit();
	const char* c_filename = bty.data();

	fstream file;
	file.open(c_filename, ios::in | ios::binary);
	if (!file.good())
		return false;
	long prepoint = 0;//��ǰ������λ��;
	long rest = buf.st_size;//ʣ����ֽ���;

	if (rest == 0)
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ļ�Ϊ�գ�����"));
		return false;
	}

	while (rest != 0)//ͳ��;
	{
		prepoint = file.tellg();
		rest = buf.st_size - prepoint;
		if (rest >= thesize)//ʣ�µ��ֽ�������4M;
		{
			initializeReadchar();
			file.read(reinterpret_cast<char*>(everyreadchar), thesize);
			for (int i = 0; i < thesize; i++)
				ascint[everyreadchar[i]] ++;
		}
		else//ʣ���ֽ�������4M;
		{
			initializeReadchar();
			file.read(reinterpret_cast<char*>(everyreadchar), rest);
			for (int i = 0; i < rest; i++)
				ascint[everyreadchar[i]] ++;
			rest = 0;
		}
	}

	BinaryTree<long> *forest = new BinaryTree<long>[256];
 	for (int i = 0; i < 256; i++)
 	{
 	 	forest[i].GetRoot()->data = i;
 	 	forest[i].SetRefValue(-1);
 	 	forest[i].GetRoot()->rchild = new TreeNode<long>(-1);
 	 	forest[i].GetRoot()->lchild = new TreeNode<long>(-1);
 	}
 	int minnumber = 0;
 	int subscript[2] = { -1,-1 };//ascint�г�ȥ0�������Сֵ��Ӧ���±꣬[0]��ǰһ����[1]�ǵ�ǰ��;
 	int mergeNum = 0;//�ϳɴ���;
 	while (mergeNum < 256)//�ϳ�һ����;
	{
 		if (minasc(subscript[0]))//ȡ��ascint�г�ȥ0�������Сֵ;
 		{
 		 	minnumber = ascint[subscript[0]];
 		 	ascint[subscript[0]] = 0;
 		}
 		else
 		 	break;
 		if (minasc(subscript[1]))
 		{
 		 	ascint[subscript[1]] += minnumber;
 		 	tree = &forest[subscript[1]];
 		 	tree->MergeTree(&forest[subscript[0]]);
 		}
 		else
 		 	break;
 		mergeNum++;
 	}

	if (tree->GetDepth() > 32)
	{
		QMessageBox::warning(this, "warning", "the huffman-tree's depth beyond 32!");
		delete[] forest;
		tree = NULL;
		file.close();
		return false;
	}

	unsigned int tempor = 0;
	for (int i = 0; i < 256; i++)//����;
	{
		tempor = tree->huffamFind(i);
		if (tempor == -1)//��ѯ���������ڻ�Ϊ���ڵ��ֵ;
			continue;
		else
		{
			huffman[i][1] = tree->FindDepth(i);
			huffman[i][0] = (tempor >> (32 - huffman[i][1]));
		}
	}
	
	//���Բ���;222222222222222222222222222222222222222222222222
// 	 	QString tempo;
// 		tempo = "the depth is " + QString::number(tree->GetDepth(), 10);
// 		ui.textEdit->append(tempo);
// 	 	for (int i = 0; i < 256; i++)
// 	 	{
// 			tempo = "depth:" + QString::number(huffman[i][1], 10);
// 			ui.textEdit->append(tempo);
// 	 		tempo = QString::number(huffman[i][0], 10);
// 	 		ui.textEdit->append(tempo);
// 	 	}

	QString tem;
	for (int i = Q_filename.length() - 1; i >= 0; i--)
	{
		if (Q_filename.at(i) == '/')
			break;
		if (Q_filename.at(i) == '.')
			tem = "huf";
		tem = Q_filename.at(i) + tem;
	}
	QByteArray temporary = tem.toLocal8Bit();
	const char* newFile = temporary.data();
	fstream new_file;
	new_file.open(newFile, ios::out);
	if (!new_file.good())
	{
		QMessageBox::warning(this, "false!", QString::fromLocal8Bit("����ѹ���ļ��������ˣ�"));
		delete[] forest;
		tree = NULL;
		file.close();
		return false;
	}

	tem.clear();
	for (int i = Q_filename.length() - 1; i >= 0; i--)//�洢�ļ�ԭ�����ļ���;
	{
		if (Q_filename.at(i) == '/')
			break;
		tem = Q_filename.at(i) + tem;
	}
	temporary = tem.toLocal8Bit() + " ";
	new_file.write(temporary.data(), temporary.length());

	new_file << buf.st_size;//�洢ԭ���ļ��Ĵ�С;
	new_file << " ";

	tem.clear();
	LinkQueue<long> writeQueue;//�洢Huffman����ǰ������Ľ��;
	tree->preOrderVisit();
	tree->outVisit(writeQueue);
	int t_size = writeQueue.GetSize();
	for (int i = 0; i < t_size; i++)
		tem = tem + ";" + QString::number(writeQueue.OutQueue(), 10);
	temporary = tem.toLocal8Bit() + " ";
	new_file.write(temporary.data(), temporary.length());

	for (int i = 0; i < thesize + 1; i++)
		everywritechar[i] = 0;
	file.seekg(0, ios::beg);
	prepoint = 0;//��ǰ������λ��;
	rest = buf.st_size;//ʣ����ֽ���;
	int writePosition = 0;
	tempor = 0;
	int bitPosition = 0;//С��32;
	unsigned int t_int = 0;
	long now_read = 0;
	while (rest != 0)//ѹ��;
	{
		prepoint = file.tellg();
		rest = buf.st_size - prepoint;
		if (rest >= thesize)//ʣ�µ��ֽ�������4M;
			now_read = thesize;
		else//ʣ���ֽ�������4M;
		{
			now_read = rest;
			rest = 0;
		}

		initializeReadchar();
		if (writePosition == thesize)
		{
			new_file.write(reinterpret_cast<char*>(everywritechar), thesize);
			everywritechar[0] = 0;
			initializeWritechar();
			writePosition = 0;
		}
		file.read(reinterpret_cast<char*>(everyreadchar), now_read);
 		for (int i = 0; i < now_read; i++)
		{
			if (bitPosition + huffman[everyreadchar[i]][1] < 8)
			{
				t_int = huffman[everyreadchar[i]][0] << (8 - bitPosition - huffman[everyreadchar[i]][1]);
				everywritechar[writePosition] = everywritechar[writePosition] | t_int;
				bitPosition += huffman[everyreadchar[i]][1];
			}
			else
			{
				t_int = huffman[everyreadchar[i]][0];
				t_int = t_int >> (bitPosition + huffman[everyreadchar[i]][1] - 8);
				everywritechar[writePosition] = everywritechar[writePosition] | t_int;
				writePosition++;
				t_int = 0;
				if (writePosition == thesize)
				{
					new_file.write(reinterpret_cast<char*>(everywritechar), thesize);
					everywritechar[0] = 0;
					initializeWritechar();
					writePosition = 0;
				}
				bitPosition = bitPosition + huffman[everyreadchar[i]][1] - 8;
				t_int = huffman[everyreadchar[i]][0] << (32 - bitPosition);
				t_int = t_int >> 24;
				everywritechar[writePosition] = everywritechar[writePosition] | t_int;
				while (bitPosition > 8)
				{
					if (writePosition == thesize)
					{
						new_file.write(reinterpret_cast<char*>(everywritechar), thesize);
						everywritechar[0] = 0;
						initializeWritechar();
						writePosition = 0;
					}
					bitPosition -= 8;
					writePosition++;
					t_int = huffman[everyreadchar[i]][0] << (32 - bitPosition);
					t_int = t_int >> 24;
					everywritechar[writePosition] = everywritechar[writePosition] | t_int;
				}
			}
		}
	}

	if (writePosition != 0)
	{
		new_file.write(reinterpret_cast<char*>(everywritechar), writePosition + 1);
		writePosition = 0;
	}

	ui.textEdit->append(QString::fromLocal8Bit("ѹ����ɣ�"));
	new_file.close();
	delete[] forest;
	tree = NULL;
	file.close();
	return true;
}

bool Huffman::OndecomBtn()
{
	QString tem;
	if (Q_filename.isEmpty())
		return false;
	for (int i = Q_filename.length() - 1; i > Q_filename.length() - 4; i--)
	{
		tem = Q_filename.at(i) + tem;
	}
	if (tem!="huf")
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����huf�ļ�������"));
		return false;
	}

	QByteArray bty = Q_filename.toLocal8Bit();
	const char* filename = bty.data();
	fstream file;
	file.open(filename, ios::in | ios::binary);
	if (!file.good())
		return false;

	char* readchar = new char[thesize];
	for (int i = 0; i < thesize; i++)
		readchar[i] = '\0';
	char originalName[50] = "\0";
	file >> originalName;//��ȡ�ļ���һ�У����ļ�ԭ�����ļ���;
	fstream original_file;
	original_file.open(originalName, ios::out | ios::binary);
	if (!original_file.good())
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ԭ�����ļ�����"));
		original_file.close();
		file.close();
		return false;
	}

	for (int i = 0; i < thesize; i++)
		readchar[i] = '\0';
	file >> readchar;//��ȡԭ�����ļ��Ĵ�С;
	unsigned long original_size = atol(readchar);

	for (int i = 0; i < thesize; i++)
		readchar[i] = '\0';
	file >> readchar;//��ȡԭ�����ļ���huffman��;
	char nodenumber[20] = "\0";
	LinkQueue<long> readnode;
	long node = 0;
	for (int i = 0, j = 0; i < thesize; i++)
	{
		if (readchar[i] == '\0')
			break;
		if (readchar[i] == ';')
		{
			if (nodenumber[0] != '\0')
			{
				node = atoi(nodenumber);
				readnode.InQueue(node);
			}
			j = 0;
			for (int k = 0; k < 20; k++)
				nodenumber[k] = '\0';
		}
		else
		{
			nodenumber[j] = readchar[i];
			j++;
		}
	}

	tree = new BinaryTree<long>;//����huffman��;
	tree->SetRefValue(-1);
	tree->SetAllNode(readnode);
	tree->preOrderCreat();

 	int tem_int = file.tellp();//����ǰ���������� /r/n;
 	tem_int += 1;
 	file.seekp(tem_int);

	for (int i = 0; i < thesize + 1; i++)
		everywritechar[i] = 0;
	stat(filename, &buf);
	long prePosition = 0;//��ǰ������λ��;
	long rest = buf.st_size;//ʣ����ֽ���;
	unsigned char t_char = '\0';//�洢��ǰ�ֽ�;
	int t_int = 0;
	bool t_bool = 0;
	int writePosition = 0;
	while (rest != 0)
	{
		prePosition = file.tellg();
		rest = buf.st_size - prePosition;
		if (rest >= thesize)//ʣ�µ��ֽ�������4M;
		{
			initializeReadchar();
			file.read(reinterpret_cast<char*>(everyreadchar), thesize);
			for (int i = 0; i < thesize; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					t_char = everyreadchar[i];
					if (t_char == '\r'&&everyreadchar[i + 1] == '\n')
					{
						i++;
						t_char = t_char = everyreadchar[i];
					}
					t_char = t_char << j;
					t_char = t_char >> 7;
					t_bool = t_char;
					t_int = tree->gainASC(t_bool);
					if (t_int == -1)
						continue;
					else
					{
						if (writePosition == thesize)
						{
							original_file.write(reinterpret_cast<char*>(everywritechar), thesize);
							initializeWritechar();
							writePosition = 0;
						}
						everywritechar[writePosition] = t_int;
						writePosition++;
						original_size--;
					}
				}
			}
		}
		else//ʣ���ֽ�������4M;
		{
			initializeReadchar();
			file.read(reinterpret_cast<char*>(everyreadchar), rest);
			for (int i = 0; i < rest; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					t_char = everyreadchar[i];
					if (t_char == '\r'&&everyreadchar[i + 1] == '\n')
					{
						i++;
						t_char = everyreadchar[i];
					}
					t_char = t_char << j;
					t_char = t_char >> 7;
					t_bool = t_char;
					t_int = tree->gainASC(t_bool);
					if (t_int == -1)
						continue;
					else
					{
						if (writePosition == thesize)
						{
							original_file.write(reinterpret_cast<char*>(everywritechar), thesize);
							initializeWritechar();
							writePosition = 0;
						}
						everywritechar[writePosition] = t_int;
						writePosition++;
						original_size--;
						if (original_size == 0)
							break;
					}
				}
				if (original_size == 0)
					break;
			}
			rest = 0;
		}
	}
	if (writePosition != 0)
	{
		original_file.write(reinterpret_cast<char*>(everywritechar), writePosition);
		writePosition = 0;
	}

	ui.textEdit->append(QString::fromLocal8Bit("��ѹ��ɣ�"));
	delete[]readchar;
	delete tree;
	original_file.close();
	file.close();
	return true;
}
