#pragma once
#include "LinkQueue.h"
#include "stack.h"

template <class T>
class TreeNode
{
public:
	T data;
	TreeNode<T>* lchild;
	TreeNode<T>* rchild;

	TreeNode() { lchild = NULL; rchild = NULL; }
	TreeNode(T item) { data = item;  lchild = NULL; rchild = NULL; }
	~TreeNode() { lchild = NULL; rchild = NULL; }
};

template <class T>
class BinaryTree
{
public:
	BinaryTree() { root = new TreeNode<T>(RefValue); follow = root; size = 0; depth = 1; }     //�����Ϊ��;
	BinaryTree(T &item) { root = new TreeNode<T>(item); follow = root; size = 1; depth = 1; }//�������ֵ;
	bool IsEmpty() { return root == NULL || root->data == RefValue; }
	TreeNode<T>* GetRoot() { return root; }
	bool SetRefValue(T item) { RefValue = item; return true; }
	T GetRefValue() { return RefValue; }

	bool SetAllNode(T *item, int size);//����������Ϊ���� �������н��;
	bool SetAllNode(LinkQueue<T> &linkqueue);
	bool preOrderCreat(TreeNode<T>* temp);//ǰ�� ����һ����;
	void preOrderCreat() { preOrderCreat(root); }
	bool levelOrderCreat(TreeNode<T>* temp);//��� ����һ����;
	void levelOrderCreat() { node_queue.makeEmpty(); levelOrderCreat(root); }

	bool visit(TreeNode<T>* temp);/////////////////////////////////////////////////////��ƽ̨�ı���ı�;
	bool preOrderVisit(TreeNode<T>* temp);//ǰ�����;
	void preOrderVisit() { queue.makeEmpty(); preOrderVisit(root); }
	bool inOrderVisit(TreeNode<T>* temp);//�������;
	void inOrderVisit() { queue.makeEmpty(); inOrderVisit(root); }
	bool postOrderVisit(TreeNode<T>* temp);//�������;
	void postOrderVisit() { queue.makeEmpty(); postOrderVisit(root); }
	bool levelOrderVisit(TreeNode<T>* temp);//��α���;
	void levelOrderVisit() { queue.makeEmpty(); levelOrderVisit(root); }
	bool outVisit(LinkQueue<T> &linkqueue);

	bool SwapTree(TreeNode<T>* temp);//������������;
	void SwapTree() { SwapTree(root); }
	bool Find(T value, TreeNode<T>* temp);//�����ض�ֵ�Ľ��;
	bool Find_leaf(T value, TreeNode<T>* temp);//�����ض�ֵ(Ҷ�ӽڵ�)�Ľ��;
	bool Find(T val);
	bool Find_leaf(T val);
	int FindDepth(T val) { Find_leaf(val); return queue.GetSize(); }
	int huffamFind(T val);//����huffman���룬���صľ���huffman����;
	bool huffamFind(T value, TreeNode<T>* temp, unsigned int& huff);//��1��0;
	int GetSize() { size = 0; GetSize(root); return size; }//ͳ�ƽ����;
	bool GetSize(TreeNode<T>* temp);
	int GetDepth() { depth = GetDepth(root); return depth; }//��ȡ���;
	int GetDepth(TreeNode<T>* temp);
	bool MergeTree(BinaryTree<T> *othertree);//�ϲ���;
	int gainASC(bool item);

	bool destroy(TreeNode<T>* temp);//�ݻ�һ�����;
	~BinaryTree();
private:
	int size;//�����;
	int depth;//���;
	T RefValue;//�ս���ֵ;
	Stack<TreeNode<T>*> node_stack;//��ѯĳ���������Ƚ��ʱ�洢���;
	LinkQueue<T> queue;//���д洫���������� �� ���ʱ������;
	LinkQueue<TreeNode<T>*> node_queue;//�������������ʱ�����ҽ��;
	TreeNode<T>* root;	//�����;
	TreeNode<T>* follow;
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
inline bool BinaryTree<T>::SetAllNode(LinkQueue<T>& linkqueue)
{
	size = 0; 
	depth = 0; 
	T item;
	while (linkqueue.GetSize() != 0)
	{
		item = linkqueue.OutQueue();
		queue.InQueue(item);
	}
	return true;
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
		return true;
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
	queue.InQueue(temp->data);
	return true;
}

template<class T>
inline bool BinaryTree<T>::preOrderVisit(TreeNode<T>* temp)
{
	if (temp != NULL)
	{
		visit(temp);
		preOrderVisit(temp->lchild);
		preOrderVisit(temp->rchild);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::inOrderVisit(TreeNode<T>* temp)
{
	if (temp != NULL)
	{
		inOrderVisit(temp->lchild);
		visit(temp);
		inOrderVisit(temp->rchild);
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::postOrderVisit(TreeNode<T>* temp)
{
	if (temp != NULL)
	{
		postOrderVisit(temp->lchild);
		postOrderVisit(temp->rchild);
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
inline bool BinaryTree<T>::outVisit(LinkQueue<T>& linkqueue)
{
	T item;
	while (queue.GetSize() != 0)
	{
		item = queue.OutQueue();
		linkqueue.InQueue(item);
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
		node_stack.push(temp);
		if (Find(value, temp->lchild))
			node_stack.pop();
		if (Find(value, temp->rchild))
			node_stack.pop();
	}
	else
	{
		node_stack.push(temp);
		while (node_stack.gettop() != 0)
			visit(node_stack.pop());
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::Find_leaf(T value, TreeNode<T>* temp)
{
	if (temp->data == RefValue)
		return false;
	if (temp->data != value)
	{
		node_stack.push(temp);
		if (Find_leaf(value, temp->lchild))
			node_stack.pop();
		if (Find_leaf(value, temp->rchild))
			node_stack.pop();
	}
	else
	{
		if (temp->lchild->lchild == NULL)
		{
			node_stack.push(temp);
			while (node_stack.gettop() != 0)
				visit(node_stack.pop());
		}
		else
		{
			node_stack.push(temp);
			if (Find_leaf(value, temp->lchild))
				node_stack.pop();
			if (Find_leaf(value, temp->rchild))
				node_stack.pop();
		}
	}
	return true;
}

template<class T>
inline bool BinaryTree<T>::Find(T val)
{
	node_stack.MakeEmpty();
	queue.makeEmpty();
	if (root->data == val)
		return false;
	Find(val, root);
	if (queue.GetSize() != 0)
		return true;
	else
		return false;
	
}

template<class T>
inline bool BinaryTree<T>::Find_leaf(T val)
{
	node_stack.MakeEmpty();
	queue.makeEmpty();
	if (root->data == val)
		return false;
	Find_leaf(val, root);
	if (queue.GetSize() != 0)
		return true;
	else
		return false;
}

template<class T>
inline int BinaryTree<T>::huffamFind(T val)
{	
	if (root->data == val)
		return -1;
	node_stack.MakeEmpty();
	queue.makeEmpty();
	unsigned int thehuffman = 0;
	if (!Find(val))//û�����ֵ;
		return -1;
	huffamFind(val, root, thehuffman);
	int bitNum = FindDepth(val);//λ��;
	unsigned int temp = 1;
	unsigned int midtemporary = 0;
	for (int i = 0; i < bitNum; i++)
	{
		temp = temp&thehuffman;
		temp = temp << (31 - i);
		thehuffman = thehuffman >> 1;
		midtemporary = midtemporary | temp;
		temp = 1;
	}
	thehuffman = midtemporary;
	return thehuffman;
}

template<class T>
inline bool BinaryTree<T>::huffamFind(T value, TreeNode<T>* temp, unsigned int& huff)//��1��0;
{
	if (temp->data != RefValue)
	{
		if (huffamFind(value, temp->lchild, huff) )//�����1;
		{
			huff = huff << 1;
			huff = huff | 1;
			return true;
		}
		if (huffamFind(value, temp->rchild, huff))//�����0;
		{
			huff = huff << 1;
			return true;
		}
		if (temp->data == value&&temp->lchild->lchild == NULL)
			return true;
		else
			return false;
	}
	else
		return false;
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
inline bool BinaryTree<T>::MergeTree(BinaryTree<T> *othertree)
{
	if (othertree == NULL || othertree->GetRoot() == NULL)
		return false;
	TreeNode<T> *tempo = new TreeNode<T>(root->data + othertree->GetRoot()->data);
// 	tempo->lchild = othertree->GetRoot();
	othertree->preOrderVisit();
	othertree->outVisit(queue);
	tempo->lchild = new TreeNode<T>(RefValue);
	preOrderCreat(tempo->lchild);
	tempo->rchild = root;
	root = tempo;
	return true;
}

template<class T>
inline int BinaryTree<T>::gainASC(bool item)
{
	if (follow->lchild->lchild == NULL)
		follow = root;
	if (item)
		follow = follow->lchild;
	else
		follow = follow->rchild;
	if (follow->lchild->data == RefValue)
		return follow->data;
	else
		return -1;
}


template<class T>
inline bool BinaryTree<T>::destroy(TreeNode<T>* temp)
{
	if (temp != NULL)
	{
		destroy(temp->lchild);
		destroy(temp->rchild);
		delete temp;
		temp = NULL;
		return true;
	}
	return false;
}

template<class T>
inline BinaryTree<T>::~BinaryTree()
{
	if (root==NULL)
		return;
	if (root->data == RefValue)
	{
		delete root;
		root = NULL;
	}
	else
		destroy(root);
	root = NULL;
}

