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
	LinkQueue();
	~LinkQueue();
	bool IsEmpty();
	bool InQueue(T &x);
	bool OutQueue(T &x);
	int GetSize() { return size; }
	T GetFront() { return first->data; }
private:
	Node<T>* first;
	Node<T>* tail;
	int size;
};

template<class T>
inline LinkQueue<T>::LinkQueue()
{
	size = 0;
}

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
inline bool LinkQueue<T>::OutQueue(T & x)
{
	if (IsEmpty())
		return false;
	else
	{
		x = first->data;
		Node<T>* temp = first->next;
		delete first;
		first = temp;
		size--;
		return true;
	}
}
