#pragma once

template<class T>
class Node
{
public:
	T data;
	Node* next;
	Node() { next = NULL; }
	Node(T &x) { data = x; next = NULL; }
};

template<class T>
class LinkQueue
{
public:
	LinkQueue() :size(0) {};
	~LinkQueue();
	bool IsEmpty();
	bool InQueue(T &x);
	bool makeEmpty();
	T OutQueue();
	int GetSize() { return size; }
	T GetFront() { return first->data; }
private:
	Node<T>* first;
	Node<T>* tail;
	int size;
};

template<class T>
inline LinkQueue<T>::~LinkQueue()
{
	if (!IsEmpty())
	{
		while (first == tail)
		{
			Node<T>* temp = first->next;
			delete first;
			first = temp;
		}
	}
}

template<class T>
inline bool LinkQueue<T>::IsEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

template<class T>
inline bool LinkQueue<T>::InQueue(T & x)
{
	if (size != 0)
	{
		Node<T>* temp = new Node<T>;
		tail->next = temp;
		tail = temp;
		tail->data = x;
		size++;
		return true;
	}
	else
	{
		first = new Node<T>;
		tail = first;
		first->data = x;
		size++;
		return true;
	}
}

template<class T>
inline bool LinkQueue<T>::makeEmpty()
{
	if (size == 0)
		return false;
	while (size != 0)
		OutQueue();
	return true;
}

template<class T>
inline T LinkQueue<T>::OutQueue()
{
	if (IsEmpty())
		return NULL;
	else
	{
		T tem = first->data;
		Node<T>* temp = first->next;
		delete first;
		first = temp;
		size--;
		return tem;
	}
}
