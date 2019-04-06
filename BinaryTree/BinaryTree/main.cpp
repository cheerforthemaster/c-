#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	BinaryTree<char> bintree;

	bintree.SetRefValue('#');
	char test[9] = { 'a','b','#','#','c','d','e','#','f' };
	bintree.SetAllNode(test, 9);
	bintree.preOrderCreat();
	//bintree.levelOrderCreat();
	cout << "ǰ�������" << endl;
	bintree.preOrderVisit();
	cout << endl;
	cout << "���������" << endl;
	bintree.inOrderVisit();
	cout << endl;
	cout << "���������" << endl;
	bintree.postOrderVisit();
	cout << endl;
	cout << "��α�����" << endl;
	bintree.levelOrderVisit();
	cout << endl;

	bintree.SwapTree();
	cout << "������" << endl;
	cout << "ǰ�������" << endl;
	bintree.preOrderVisit();
	cout << endl;
	cout << "���������" << endl;
	bintree.inOrderVisit();
	cout << endl;
	cout << "���������" << endl;
	bintree.postOrderVisit();
	cout << endl;
	cout << "��α�����" << endl;
	bintree.levelOrderVisit();
	cout << endl;

	cout << "���� 'f' ��" << endl;
	bintree.Find('f');
	cout << endl;

	int size = bintree.GetSize();
	cout<<"�������"<<size<<endl;
	int depth = bintree.GetDepth();
	cout << "��ȣ�" << depth << endl;

	return 0;
}