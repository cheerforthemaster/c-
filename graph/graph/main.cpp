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
	cout << "�����ܶ�������" << endl;
	cin >> size;
	cout << "����" << size << "����������ƣ�" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> verName;
		if (!theone.insertVertex(verName))
			cout << "�����ö���ʧ�ܣ�" << endl;
	}
	int edgeSize = 0;
	cout << "�����ܱ�����" << endl;
	cin >> edgeSize;
	cout << "����" << edgeSize << "���������ӵ����������λ�ã� eg:����0��1�������������һ������͵ڶ�����֮��ı�" << endl;
	for (int i = 0; i < edgeSize; i++)
	{
		cin >> firValue;
		cin >> secValue;
		if (!theone.insertEdge(firValue, secValue))
			cout << "�����ñ�ʧ��" << endl;
		else
			cout << "right!" << endl;
	}
	cout << "test part:" << endl;
	cout << firValue << "�ĵ�һ���ڽӽ��" << endl;
	cout << theone.getFirstNeighbor(firValue) << endl;
	cout << secValue << "���ڽӽ��" << firValue << "�ĵ�һ���ڽӽ��" << endl;
	cout << theone.getNextNeighbor(secValue, firValue) << endl;

	cout << "��2�����������:";
	cout << theone.getValue(1) << endl;

	cout << firValue << "��" << secValue << "֮���Ȩ��:";
	cout << theone.getWeight(firValue, secValue) << endl;

	cout << "�ڽӱ�" << endl;
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
	cout << "��ȱ�����" << endl;
	cout << "���������ʼ�Ľ�㣺����" << endl;
	cin >> Number;
	if (theone.IsVertex(Number))
	{
		Number = theone.depthTraverse(temporArrary,Number);
		for (int i = 0; i < Number; i++)
			cout << temporArrary[i];
	}
	else
		cout << "������" << endl;
	cout << endl;

	Number = 0;
	delete[]temporArrary;
	temporArrary = NULL;
	cout << "��ȱ�����" << endl;
	cout << "���������ʼ�Ľ�㣺����" << endl;
	cin >> Number;
	if (theone.IsVertex(Number))
	{
		Number = theone.breadthSearch(temporArrary,Number);
		for (int i = 0; i < Number; i++)
			cout << temporArrary[i];
	}
	else
		cout << "������" << endl;
	delete[]temporArrary;
	cout << endl;
	cout << "over!" << endl;
	return 0;
}