#pragma once
#include <QString>
#include <queue>
#include <QMessageBox>
using namespace std;

class TreeNode
{
public:
	TreeNode(QString item, int index) { data = item; preIndex = index; left = NULL; right = NULL; }
	TreeNode* left;
	TreeNode* right;
	QString data;
	int preIndex;
};


class BST
{
public:
	BST(QString Root,int index);
	~BST();

	bool build(QString item, int index, TreeNode* preNode);
	bool build(QString item, int index) { return build(item, index, root); }
	int findNode(QString item, TreeNode* preNode);
	int findNode(QString item) { return findNode(item, root); }
	TreeNode* root;


};