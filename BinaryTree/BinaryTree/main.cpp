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
	cout << "前序遍历：" << endl;
	bintree.preOrderVisit();
	cout << endl;
	cout << "中序遍历：" << endl;
	bintree.inOrderVisit();
	cout << endl;
	cout << "后序遍历：" << endl;
	bintree.postOrderVisit();
	cout << endl;
	cout << "层次遍历：" << endl;
	bintree.levelOrderVisit();
	cout << endl;

	bintree.SwapTree();
	cout << "交换后：" << endl;
	cout << "前序遍历：" << endl;
	bintree.preOrderVisit();
	cout << endl;
	cout << "中序遍历：" << endl;
	bintree.inOrderVisit();
	cout << endl;
	cout << "后序遍历：" << endl;
	bintree.postOrderVisit();
	cout << endl;
	cout << "层次遍历：" << endl;
	bintree.levelOrderVisit();
	cout << endl;

	cout << "查找 'f' ：" << endl;
	bintree.Find('f');
	cout << endl;

	int size = bintree.GetSize();
	cout<<"结点数："<<size<<endl;
	int depth = bintree.GetDepth();
	cout << "深度：" << depth << endl;

	return 0;
}