#pragma once

const int maxsize = 50;

template<class T>
class queue
{
public:
	queue();
	~queue() { delete[]elements; }
	bool IsFull();
	bool IsEmpty();
	bool InQueue(T &x);
	bool OutQueue(T &x);
	int GetSize();
	bool GetFront(T &x);

private:
	int rear, front;
	T* elements;
	int size;
	bool tag;
};

template<class T>
queue<T>::queue()
{
	size = maxsize;
	elements = new T[size];
	rear = 0;
	front = 0;
	tag = 0;
}

template<class T>
bool queue<T>::IsFull()
{
	if (rear == front&&tag == 1)
		return true;
	else
		return false;
}

template<class T>
bool queue<T>::IsEmpty()
{
	if (rear == front&&tag == 0)
		return true;
	else
		return false;
}

template<class T>
bool queue<T>::InQueue(T & x)
{
	if (IsFull())
		return false;
	rear = rear%size;
	elements[rear] = x;
	rear++;
	tag = 1;
}

template<class T>
bool queue<T>::OutQueue(T & x)
{
	if (IsEmpty())
		return false;
	front = front%size;
	x = elements[front];
	front++;
	tag = 0;
}

template<class T>
int queue<T>::GetSize()
{
	int x = rear - front;
	if (x >= 0)
		return x;
	else
		return size + x;
}

template<class T>
bool queue<T>::GetFront(T & x)
{
	return elements[front];
}

