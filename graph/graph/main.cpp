#include <iostream>
#include<sstream>
#include "graph.h"
using namespace std;

int main()
{
	graph<string, int> theone;
	string verName;
	int firValue = 0, secValue = 0;
	int size = 0;
	cout << "输入总顶点数：" << endl;
	cin >> size;
	cout << "输入" << size << "个顶点的名称：" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> verName;
		if (!theone.insertVertex(verName))
			cout << "创建该顶点失败！" << endl;
	}
	int edgeSize = 0;
	cout << "输入总边数：" << endl;
	cin >> edgeSize;
	cout << "输入" << edgeSize << "条边所连接的两个顶点的位置： eg:输入0和1，即创建上面第一个顶点和第二顶点之间的边" << endl;
	for (int i = 0; i < edgeSize; i++)
	{
		cin >> firValue;
		cin >> secValue;
		if (!theone.insertEdge(firValue, secValue))
			cout << "创建该边失败" << endl;
		else
			cout << "right!" << endl;
	}
	cout << "test part:" << endl;
	cout << firValue << "的第一个邻接结点" << endl;
	cout << theone.getFirstNeighbor(firValue) << endl;
	cout << secValue << "的邻接结点" << firValue << "的第一个邻接结点" << endl;
	cout << theone.getNextNeighbor(secValue, firValue) << endl;

	cout << "第2个顶点的名称:";
	cout << theone.getValue(1) << endl;

	cout << firValue << "和" << secValue << "之间的权重:";
	cout << theone.getWeight(firValue, secValue) << endl;

	cout << "邻接表：" << endl;
	int *Neighbor = NULL;
	int num = 0;
	for (int i = 0; i < size; i++)
	{
		cout << theone.getValue(i);
		num = theone.getAllNeighbor(i, Neighbor);
		if (num != -1)
		{
			for (int j = 0; j < num; j++)
				cout << "-->" << Neighbor[j];
			cout << endl;
			delete[] Neighbor;
		}
	}


	int Number = 0;
	int* temporArrary = NULL;
	cout << "深度遍历：" << endl;
	cout << "输入遍历开始的结点：数字" << endl;
	cin >> Number;
	if (theone.IsVertex(Number))
	{
		Number = theone.depthTraverse(temporArrary,Number);
		for (int i = 0; i < Number; i++)
			cout << temporArrary[i];
	}
	else
		cout << "结点错误" << endl;
	cout << endl;

	Number = 0;
	delete[]temporArrary;
	temporArrary = NULL;
	cout << "广度遍历：" << endl;
	cout << "输入遍历开始的结点：数字" << endl;
	cin >> Number;
	if (theone.IsVertex(Number))
	{
		Number = theone.breadthSearch(temporArrary,Number);
		for (int i = 0; i < Number; i++)
			cout << temporArrary[i];
	}
	else
		cout << "结点错误" << endl;
	delete[]temporArrary;
	cout << endl;
	cout << "over!" << endl;
	return 0;
}