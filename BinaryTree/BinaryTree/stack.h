#pragma once
const int stackIncreament = 20;
template<class T>
class Stack
{
public:
	Stack();
	~Stack() { delete[]elements; }

	bool push(T &x);                         //ѹջ
	bool pop(T &x);                          //��ջ
	int gettop() { return top; }             //��ȡͷλ��
	bool IsEmpty();                          //ջ�Ƿ�Ϊ��
	bool IsFull();                           //ջ�Ƿ���
	bool MakeEmpty() { top = -1; }           //��ջ�ÿ�

private:
	T* elements;
	int top;
	int maxsize;
	bool overstack();
};

template<class T>
inline Stack<T>::Stack()
{
	maxsize = 50;
	elements = new T[maxsize];
	top = -1;
}

template<class T>
inline bool Stack<T>::push(T & x)
{
	if (IsFull())
	{
		if (overstack())
		{
			top++;
			elements[top] = x;
		}
		else
			return false;
	}
	else
	{
		top++;
		elements[top] = x;
	}
}

template<class T>
inline bool Stack<T>::pop(T & x)
{
	if (IsEmpty())
		return false;
	else
	{
		x = elements[top];
		top--;
		return true;
	}
}

template<class T>
inline bool Stack<T>::IsEmpty()
{
	if (top==-1)
		return true;
	else
		return false;
}

template<class T>
inline bool Stack<T>::IsFull()
{
	if (top == maxsize-1)
		return true;
	else
		return false;
}

template<class T>
inline bool Stack<T>::overstack()
{
	if (IsFull())
	{
		int tem = maxsize;
		maxsize = maxsize + stackIncreament;
		T* temp_ele = new T[maxsize];
		for (int i=0;i<tem;i++)
		{
			temp_ele[i] = elements[i];
		}
		delete[]elements;
		elements = temp_ele;
		return true;
	}
	else
		return false;
}
