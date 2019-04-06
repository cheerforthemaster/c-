#include "Binary_Search_Tree.h"

BST::BST(QString Root, int index)
{
	root = new TreeNode(Root, index);
}

BST::~BST()
{
	queue<TreeNode*> que;
	que.push(root);
	TreeNode *present;
	while (que.size() != 0)
	{
		present = que.front();
		que.pop();
		if (present->right != NULL)
			que.push(present->right);
		if (present->left != NULL)
		que.push(present->left);
	}
}

bool BST::build(QString item, int index, TreeNode* preNode)
{
	if (item > preNode->data)
	{
		if (preNode->right == NULL)
		{
			preNode->right = new TreeNode(item, index);
		}
		else
		{
			build(item, index, preNode->right);
		}
	}
	else
	{
		if (preNode->left == NULL)
		{
			preNode->left = new TreeNode(item, index);
		}
		else
		{
			build(item, index, preNode->left);
		}
	}
	return false;
}

int BST::findNode(QString item, TreeNode * preNode)
{
	int comp = preNode->data.indexOf(item);//如果comp为0则item是preNode->data的子字符串  0代表从头开始比较并且成功
	if (comp == 0)
	{
		return preNode->preIndex;
	}

	if (item > preNode->data)
	{
		return findNode(item, preNode->right);
	}
	else
	{
		if (item < preNode->data)
		{
			return findNode(item, preNode->left);
		}
		else
		{
			if (item == preNode->data)
			{
				return preNode->preIndex;
			}
		}
	}
	return -1;
}
