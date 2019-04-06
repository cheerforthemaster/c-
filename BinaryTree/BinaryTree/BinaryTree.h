#pragma once
#include "LinkQueue.h"

template <class T>
class TreeNode
{
public:
	T data;
	TreeNode<T>* lchild;
	TreeNode<T>* rchild;

	TreeNode() { lchild = NULL; rchild = NULL; }
	TreeNode(T item, TreeNode<T>* lchild = NULL, TreeNode<T>* rchild = NULL) { data = item; }
	~TreeNode() { lchild = NULL; rchild = NULL; }
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() { root = new TreeNode<T>(RefValue); size = 0; depth = 1; }     //根结点为空;
	BinaryTree(T &item) { root = new TreeNode<T>(item); size = 0; depth = 1; }//根结点有值;
	bool IsEmpty() { return root == NULL; }
	TreeNode<T>* GetRoot() { return root; }
	bool SetRefValue(T item) { return RefValue = item; }

	bool SetAllNode(T *item, int size);//以数组为参数 设置所有结点;
	bool preOrderCreat(TreeNode<T>* temp);//前序 创建一颗树;
	void preOrderCreat() { preOrderCreat(root); }
	bool levelOrderCreat(TreeNode<T>* temp);//层次 创建一颗树;
	void levelOrderCreat() { levelOrderCreat(root); }

	bool visit(TreeNode<T>* temp);/////////////////////////////////////////////////////随平台改变而改变;
	bool preOrderVisit(TreeNode<T>* temp);//前序遍历;
	void preOrderVisit() { queue.makeEmpty(); preOrderVisit(root); }
	bool inOrderVisit(TreeNode<T>* temp);//中序遍历;
	void inOrderVisit() { queue.makeEmpty(); inOrderVisit(root); }
	bool postOrderVisit(TreeNode<T>* temp);//后序遍历;
	void postOrderVisit() { queue.makeEmpty(); postOrderVisit(root); }
	bool levelOrderVisit(TreeNode<T>* temp);//层次遍历;
	void levelOrderVisit() { queue.makeEmpty(); levelOrderVisit(root); }

	bool SwapTree(TreeNode<T>* temp);//交换左右子树;
	void SwapTree() { SwapTree(root); }
	bool Find(T value, TreeNode<T>* temp);//查找特定值的结点;
	void Find(T val);
	int GetSize() { GetSize(root); return size; }//统计结点数;
	bool GetSize(TreeNode<T>* temp);
	int GetDepth() { depth = GetDepth(root); return depth; }//获取深度;
	int GetDepth(TreeNode<T>* temp);

	bool destroy(TreeNode<T>* temp);//摧毁一个结点;
	~BinaryTree() { destroy(root); }
private:
	int size;//结点数;
	int depth;//深度;
	T RefValue;//空结点的值;
	LinkQueue<T> queue;//队列存传进来的数组 或 输出时存数据;
	LinkQueue<TreeNode<T>*> node_queue;//遍历或创造二叉树时存左右结点;
	TreeNode<T>* root;	//根结点;
};

template<class T>
inline bool BinaryTree<T>::SetAllNode(T * item, int Size)
{
	if (item == NULL || Size <= 0)
		return false;
	else
	{
		size = 0;
		depth = 0;
	}
	if (!IsEmpty())
	{
		for (int i = 0; i < Size; i++)
			queue.InQueue(item[i]);
		return true;
	}
	else
		return false;
}


template<class T>
inline bool BinaryTree<T>::preOrderCreat(TreeNode<T>* temp)
{
	T tem;
	if (queue.GetSize() != 0)
		tem = queue.OutQueue();
	else
		return false;
	if (tem != RefValue)
	{
		temp->data = tem;
		temp->lchild = new TreeNode<T>(RefValue);
		temp->rchild = new TreeNode<T>(RefValue);
		preOrderCreat(temp->lchild);
		preOrderCreat(temp->rchild);
	}
	else
		return true;
}

template<class T>
inline bool BinaryTree<T>::levelOrderCreat(TreeNode<T>* temp)
{
	if (queue.GetSize() != 0)
	{
		T tem = queue.OutQueue();
		if (tem == RefValue)
			return false;
		temp->data = tem;
		temp->lchild = new TreeNode<T>(RefValue);
		temp->rchild = new TreeNode<T>(RefValue);
		node_queue.InQueue(temp->lchild);
		node_queue.InQueue(temp->rchild);
		while (node_queue.GetSize() != 0)
			levelOrderCreat(node_queue.OutQueue());
	}
	return false;
}

template<class T>
inline bool BinaryTree<T>::visit(TreeNode<T>* temp)
{
	cout << temp->data;
	queue.InQueue(temp->data);
	return true;
}

template<class T>
inline bool BinaryTree<T>::preOrderVisit(TreeNode<T>* temp)
{
	if (temp->data != RefValue)
	{
		visit(temp);
		preOrderVisit(temp->lchild);
		preOrderVisit(temp->rchild);
	}
	else
	{
		if (temp!=NULL)
			visit(temp);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::inOrderVisit(TreeNode<T>* temp)
{
	if (temp->data != RefValue)
	{
		preOrderVisit(temp->lchild);
		visit(temp);
		preOrderVisit(temp->rchild);
	}
	else
	{
		if (temp != NULL)
			visit(temp);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::postOrderVisit(TreeNode<T>* temp)
{
	if (temp->data != RefValue)
	{
		preOrderVisit(temp->lchild);
		preOrderVisit(temp->rchild);
		visit(temp);
	}
	else
	{
		if (temp != NULL)
			visit(temp);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::levelOrderVisit(TreeNode<T>* temp)
{
	if (temp->data != RefValue)
	{
		visit(temp);
		node_queue.InQueue(temp->lchild);
		node_queue.InQueue(temp->rchild);
		if (node_queue.GetSize() != 0)
		{
			levelOrderVisit(node_queue.OutQueue());
			levelOrderVisit(node_queue.OutQueue());
		}
		else
			return true;
	}
	else
	{
		if (temp != NULL)
			visit(temp);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::SwapTree(TreeNode<T>* temp)
{
	if (temp != NULL)
	{
		TreeNode<T>* Rep = temp->lchild;
		temp->lchild = temp->rchild;
		temp->rchild = Rep;
		SwapTree(temp->lchild);
		SwapTree(temp->rchild);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::Find(T value, TreeNode<T>* temp)
{
	if (temp->data == RefValue)
		return false;
	if (temp->data!=value)
	{
		node_queue.InQueue(temp);
		if (Find(value, temp->lchild))
			node_queue.OutQueue();
		if (Find(value, temp->rchild))
			node_queue.OutQueue();
	}
	else
	{
		node_queue.InQueue(temp);
		while (node_queue.GetSize() != 0)
			visit(node_queue.OutQueue());
	}
	return true;
}

template<class T>
inline void BinaryTree<T>::Find(T val)
{
	while (node_queue.GetSize() != 0)
		node_queue.OutQueue();
	Find(val, root);
}

template<class T>
inline bool BinaryTree<T>::GetSize(TreeNode<T>* temp)
{
	if (temp->data != RefValue)
	{
		size++;
		GetSize(temp->lchild);
		GetSize(temp->rchild);
	}

	return 0;
}

template<class T>
inline int BinaryTree<T>::GetDepth(TreeNode<T>* temp)
{
	if (temp->data != RefValue)
	{
		int leftdepth = GetDepth(temp->lchild) + 1;
		int rightdepth = GetDepth(temp->rchild) + 1;
		return leftdepth> rightdepth?leftdepth:rightdepth;
	}
	else
		return 0;
}

template<class T>
inline bool BinaryTree<T>::destroy(TreeNode<T>* temp)
{
	if (temp != NULL)
	{
		destroy(temp->lchild);
		destroy(temp->rchild);
		delete temp;
		return true;
	}
}
