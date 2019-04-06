#pragma once
#include <fstream>
using namespace std;

template <class T>
class list_node                                        //节点
{
public:
	T Data;                                            //数据域  分子
	T ex_Data;                                         //扩展的数据域  分母
	list_node<T>* link;                                //指针域
	list_node() { link = NULL; };
	~list_node() {};
};


template <class T>
class link_list
{
public:
	link_list();											     //构造
	~link_list() { makeEmpty(); }								 //析构
	void makeEmpty();											 //将链表置空
	int Length();											     //统计链表长度
	list_node<T>* Getfirst() { return first; }				     //返回头节点的位置
	bool IsEmpty();                                              //判断链表是否为空
	int output();                                                //输出到output.txt中
	int Append(T x,T y);                                         //在链表尾部接上一个节点
	int Fraction(int n);                                         //获取新的分数

protected:
	list_node<T>* first;                                         //头结点
	list_node<T>* tail;                                          //尾节点
};

template<class T>
inline link_list<T>::link_list()
{
	first = new list_node<T>;
	list_node<T>* tem = new list_node<T>;
	tem->Data = 0;
	tem->ex_Data = 1;
	first->link = tem;
	tail = tem;
}

template<class T>
void link_list<T>::makeEmpty()                                   //将链表置空
{
	list_node<T>* prt = first->link;
	if (prt == NULL)
	{
		delete first;
		return;
	}
	int size = Length();
	for (int i = 0; i < size; i++)
	{
		prt = first->link;
		delete first;
		first = prt;
	}
}

template<class T>
int link_list<T>::Length()                                    //统计链表长度
{
	int i = 0;
	list_node<T>* prt = first->link;
	while (prt != NULL)
	{
		i++;
		prt = prt->link;
	}
	return i;
}

template<class T>
bool link_list<T>::IsEmpty()                                //判断链表是否为空
{
	if (first->link != NULL)
	{
		return true;
	}
	else
		return false;
}


template<class T>
int link_list<T>::output()                                  //输出到output.txt中
{
	fstream file("output.txt", ios::out);
	list_node<T> *prt = first->link;
	if (!file.good())
	{
		return 0;
	}
	int size = Length();
	for (int i = 0; i < size; i++)
	{
		file << prt->Data << "/" << prt->ex_Data << ";";
		prt = prt->link;
	}
	file.close();
	return 0;
}

template<class T>
inline int link_list<T>::Append(T x,T y)                              //在链表尾部接上一个节点
{
	list_node<T>* prt = tail;
	list_node<T>* prt_new = new list_node<T>;
	prt_new->Data = x;
	prt_new->ex_Data = y;
	prt->link = prt_new;
	tail = prt_new;
	return 0;
}

template<class T>
inline int link_list<T>::Fraction(int n)//n为级数
{
	int last_molecule=0, last_denominator=1;//前一个的分子与分母
	int present_molecule=1, present_denominator=n;//当前的分子与分母
	int next_molecule, next_denominator;//下一个的分子与分母
	int x = 0;//倍数

	Append(present_molecule, present_denominator);
	while (present_denominator != 1)//若1/1生成，则结束
	{
		x = (last_denominator + n) / present_denominator;
		next_molecule = x*present_molecule - last_molecule;
		next_denominator = x*present_denominator - last_denominator;
		Append(next_molecule, next_denominator);
		last_molecule = present_molecule;
		last_denominator = present_denominator;
		present_molecule = next_molecule;
		present_denominator = next_denominator;
	}


	return 0;
}