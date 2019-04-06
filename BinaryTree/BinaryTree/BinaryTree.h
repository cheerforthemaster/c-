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
	BinaryTree() { root = new TreeNode<T>(RefValue); size = 0; depth = 1; }     //�����Ϊ��;
	BinaryTree(T &item) { root = new TreeNode<T>(item); size = 0; depth = 1; }//�������ֵ;
	bool IsEmpty() { return root == NULL; }
	TreeNode<T>* GetRoot() { return root; }
	bool SetRefValue(T item) { return RefValue = item; }

	bool SetAllNode(T *item, int size);//������Ϊ���� �������н��;
	bool preOrderCreat(TreeNode<T>* temp);//ǰ�� ����һ����;
	void preOrderCreat() { preOrderCreat(root); }
	bool levelOrderCreat(TreeNode<T>* temp);//��� ����һ����;
	void levelOrderCreat() { levelOrderCreat(root); }

	bool visit(TreeNode<T>* temp);/////////////////////////////////////////////////////��ƽ̨�ı���ı�;
	bool preOrderVisit(TreeNode<T>* temp);//ǰ�����;
	void preOrderVisit() { queue.makeEmpty(); preOrderVisit(root); }
	bool inOrderVisit(TreeNode<T>* temp);//�������;
	void inOrderVisit() { queue.makeEmpty(); inOrderVisit(root); }
	bool postOrderVisit(TreeNode<T>* temp);//�������;
	void postOrderVisit() { queue.makeEmpty(); postOrderVisit(root); }
	bool levelOrderVisit(TreeNode<T>* temp);//��α���;
	void levelOrderVisit() { queue.makeEmpty(); levelOrderVisit(root); }

	bool SwapTree(TreeNode<T>* temp);//������������;
	void SwapTree() { SwapTree(root); }
	bool Find(T value, TreeNode<T>* temp);//�����ض�ֵ�Ľ��;
	void Find(T val);
	int GetSize() { GetSize(root); return size; }//ͳ�ƽ����;
	bool GetSize(TreeNode<T>* temp);
	int GetDepth() { depth = GetDepth(root); return depth; }//��ȡ���;
	int GetDepth(TreeNode<T>* temp);

	bool destroy(TreeNode<T>* temp);//�ݻ�һ�����;
	~BinaryTree() { destroy(root); }
private:
	int size;//�����;
	int depth;//���;
	T RefValue;//�ս���ֵ;
	LinkQueue<T> queue;//���д洫���������� �� ���ʱ������;
	LinkQueue<TreeNode<T>*> node_queue;//�������������ʱ�����ҽ��;
	TreeNode<T>* root;	//�����;
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
