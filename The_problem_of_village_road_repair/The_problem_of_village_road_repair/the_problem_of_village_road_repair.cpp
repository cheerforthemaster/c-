#include "the_problem_of_village_road_repair.h"

The_problem_of_village_road_repair::The_problem_of_village_road_repair(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(getMatrix()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(DrawGraph()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(drawOriginalGraph()));
	ui.plainTextEdit->setPlainText("0 28 # # # 10 #\r\n28 0 16 # # # 14\r\n# 16 0 12 # # #\r\n# # 12 0 22 # 18\r\n# # # 22 0 25 24\r\n10 # # # 25 0 #\r\n# 14 # 18 24 # 0\r\n");
	matrixSize = 0;
	edgeNum = 0;
	minVillage = new graph<char, int>;
	villageGraph = new graph<char, int>;
	temGraph = new graph<char, int>;
}

The_problem_of_village_road_repair::~The_problem_of_village_road_repair()
{
	delete villageGraph;
	delete minVillage;
	delete temGraph;
}

bool The_problem_of_village_road_repair::DrawGraph()
{
	//drawgraph one(this);
	drawgraph *one = new drawgraph(this);
	one->GetGraph(minVillage);
	one->setModal(false);
	one->show();
	return true;
}

bool The_problem_of_village_road_repair::drawOriginalGraph()
{
	//draworiginalgraph two(this);
	draworiginalgraph *two = new draworiginalgraph(this);
	two->GetGraph(villageGraph);
	two->setModal(false);
	two->show();
	return true;
}

bool The_problem_of_village_road_repair::getMatrix()
{
	ui.textEdit->clear();
	QString matrixString = ui.plainTextEdit->toPlainText();
	matrixSize = 0;
	edgeNum = 0;
	int length = matrixString.length();
	for (int i = 0; i < length; i++)
	{
		if (matrixString.at(i) == '\n')
			matrixSize++;
	}	
	matrix = new int *[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		matrix[i] = new int[matrixSize];

	for (int i = 0; i < matrixSize; i++)
		for (int j = 0; j < matrixSize; j++)
			matrix[i][j] = -1;

	int n = 0;//第n行;
	int k = 0;//第k列;
	QString temString;
	for (int i = 0; i < length; i++)
	{
		if (matrixString.at(i) <= '9'&&matrixString.at(i) >= '0')//当前字节为数字;
		{
			temString += matrixString.at(i);
		}
		else
		{
			if (matrixString.at(i) == '\n')//当前字节为\n;
			{
				if (!temString.isEmpty())
					matrix[n][k] = temString.toInt();
				n++;
				k = 0;
				temString.clear();
			}
			else
			{
				if (n >= matrixSize || k >= matrixSize)//矩阵的行列数超过行数;
				{
					QMessageBox::warning(this, "error!", "the matrix is wrong!");//从结构上判断矩阵是否正确;
					for (int i = 0; i < matrixSize; i++)
						delete[]matrix[i];
					delete[]matrix;
					return false;
				}
				if (matrixString.at(i) == '#')//当前矩阵位置为空,-1即为空;
				{
					matrix[n][k] = -1;
					k++;
				}
				else
				{
					if (!temString.isEmpty())
					{
						matrix[n][k] = temString.toInt();
						k++;
					}
				}
				temString.clear();
			}
		}
	}

	for (int i = 0; i < matrixSize; i++)//从数据上判断是否是正确的矩阵;
		for (int j = 0; j < matrixSize; j++)
		{
			if (j == i&&matrix[i][j] != 0)
			{
				QMessageBox::warning(this, "error!", "the matrix is wrong!");
				for (int i = 0; i < matrixSize; i++)
					delete[]matrix[i];
				delete[]matrix;
				return false;
			}
			if (matrix[i][j] != matrix[j][i])
			{
				QMessageBox::warning(this, "error!", "the matrix is wrong!");
				for (int i = 0; i < matrixSize; i++)
					delete[]matrix[i];
				delete[]matrix;
				return false;
			}
		}

	char temchar = 65;
	for (int i = 0; i < matrixSize; i++)
	{
		temchar += i;
		villageGraph->insertVertex(temchar);
		minVillage->insertVertex(temchar);
		temGraph->insertVertex(temchar);
	}

	for (int i = 0; i < matrixSize; i++)
		for (int j = 1 + i; j < matrixSize; j++)
		{
			if (matrix[i][j] != -1)
			{
				villageGraph->insertEdge(i, j, matrix[i][j]);
				temGraph->insertEdge(i, j, matrix[i][j]);
				edgeNum++;
			}
		}


	ui.textEdit->append(QString::fromLocal8Bit("邻接表："));
	int *Neighbor = NULL;
	int num = 0;
	for (int i = 0; i < matrixSize; i++)
	{
		ui.textEdit->append(QString::number(i, 10));
		num = villageGraph->getAllNeighbor(i, Neighbor);
		if (num != -1)
		{
			for (int j = 0; j < num; j++)
				ui.textEdit->append(QString::fromLocal8Bit("-->") + QString::number(Neighbor[j]));
			delete[] Neighbor;
		}
	}

	int one = 0, two = 0;
	int *vertex = NULL;
	int cost = 0;
	bool isConnect = false;
	while (!isConnect)
	{
		cost = temGraph->getMinEdge(one, two);
		if (one >= matrixSize || two >= matrixSize || one == two)
		{
			QMessageBox::warning(this, "error!", "error!");
			return false;
		}
		minVillage->insertEdge(one, two, cost);
		minVillage->breadthSearch(vertex, one);
		isConnect = true;
		for (int i = 0; i < matrixSize; i++)
		{
			if (vertex[i] == -1)
			{
				isConnect = false;
				break;
			}
		}
	}

	ui.textEdit->append(QString::fromLocal8Bit("最小生成树对应的图的深度遍历："));
	for (int i = 0; i < matrixSize; i++)
	{
		minVillage->depthTraverse(vertex, 0);
		ui.textEdit->append(QString::number(vertex[i]));
	}


	for (int i = 0; i < matrixSize; i++)
		delete[]matrix[i];
	delete[]matrix;

	return true;
}

