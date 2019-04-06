#pragma once
#include <fstream>
using namespace std;

template <class T>
class list_node                                        //节点
{
public:
	T Data;                                            //数据域
	list_node<T>* link;                                //指针域
	list_node() { link = NULL; };
	~list_node() {};
	list_node(const T &item, list_node<T>* prt = NULL) //初始化Data和link
	{
		Data = item;
		link = prt;
	}
};


template <class T>
class link_list
{
public:
	link_list() { first = new list_node<T>; tail = first; }		 //构造
	link_list(const T& x);                                       //构造 含参数
	~link_list() { makeEmpty(); delete first; }					 //析构
	void makeEmpty();											 //将链表置空
	int Length();											     //统计链表长度
	list_node<T>* Getfirst() { return first; }				     //返回头节点的位置
	list_node<T>* Search(T x);								     //搜索含数据x的节点
	list_node<T>* Loacte(int i);								 //搜索第i个元素的地址
	T getData(int i);							         		 //获取第i个元素的数据
	T only_output(int i);                                        //输出一个节点的数据
	bool setData(int i, T x);									 //将第i个位置的元素数据重置为x
	bool Insert(int i, T x);									 //在第i个元素后面插入数据为x的节点
	int Milddle_Insert(int i, int n,int a);                      //在两个节点中间插入两数据相加的节点，n为数据上限
	bool move_follow();                                          //将follow向后移动两次
	T Delete(int i);						     			     //删除第i个位置的节点，并返回数据
	bool IsEmpty();                                              //判断链表是否为空
	int input(T& x);                                             //输入一个数据域
	int output();                                                //输出到output.txt中
	int OutPut_reverse(list_node<T>* tem = NULL);                //递归逆序输出
	int OutPut_order(list_node<T>* tem = NULL);                  //递归顺序输出
	bool Sort();                                                 //升序排列
	bool Reverse();                                              //逆置
	link_list<T>* Merge(link_list *other);                       //合并两个单链表
	int Exchanged(int i);                                        //相邻比较 第i个和第i+1个比较 第i个更大则互换
	int Append(T x);                                             //在链表尾部接上一个节点


protected:
	list_node<T>* first;                                         //头结点
	list_node<T>* tail;                                          //尾节点
	list_node<T>* follow;                                        //跟随节点，指向当前结点的下一个
};

template<class T>
inline link_list<T>::link_list(const T & x)
{
	first = new list_node<T>;
	list_node<T>* tem = new list_node<T>(x);
	first->link = tem;
	tail = tem;
}

template<class T>
void link_list<T>::makeEmpty()                                   //将链表置空
{
	list_node<T>* prt = first->link;
	if (prt == NULL)
	{
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
list_node<T>* link_list<T>::Search(T x)                       //搜索含数据x的节点
{
	int size = Length();
	list_node<T> *prt = first;
	for (int i = 0; i < size; i++)
	{
		prt = prt->link;
		if (prt->Data == x)
		{
			break;
		}
		if (i == size)
		{
			return NULL;                                      //未搜索到
		}
	}
	return prt;                                        //搜索到了，返回该元素的指针域
}


template<class T>
list_node<T>* link_list<T>::Loacte(int i)                    //搜索第i个元素的地址
{
	int size = Length();
	list_node<T> *prt = first;
	if (i<0 || i>size)
	{
		return NULL;                                         //i值输入不正确
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			prt = prt->link;
		}
		return prt;                                          //正确则返回第i个元素的地址
	}
}

template<class T>
T link_list<T>::getData(int i)                            //获取第i个元素的数据
{
	T x;
	list_node<T> *prt = Loacte(i);
	if (prt == NULL)
	{
		return x;
	}
	x = prt->Data;
	return x;
}

template<class T>
inline T link_list<T>::only_output(int i)
{
	list_node<T>* tem=first;
	T x;
	if (tem==NULL)
	{
		return 0;
	}
	if (i==1)
	{
		follow = first;
		tem = follow->link;
		x = tem->Data;
		follow = tem;
	}
	else
	{
		tem=follow->link;
		x = tem->Data;
		follow = tem;
	}
	return x;
}

template<class T>
bool link_list<T>::setData(int i, T  x)                     //将第i个位置的元素数据重置为x
{
	list_node<T> *prt = Loacte(i);
	if (prt == NULL)
	{
		return false;
	}
	prt->Data = x;
	return true;
}

template<class T>
bool link_list<T>::Insert(int i, T  x)                      //在第i个元素后面插入数据为x的节点
{
	list_node<T> *prt = Loacte(i);
	if (prt == NULL)
	{
		return false;
	}
	list_node<T> *tem = new list_node<T>(x);
	//tem->Data = x;
	tem->link = prt->link;
	prt->link = tem;
	return true;
}

template<class T>
inline int link_list<T>::Milddle_Insert(int i, int n, int a)
{
	list_node<T>* tem;
	if (first->link->link->Data == n)
	{
		return 2;
	}
	if (i!=1)
	{
		tem = follow;
		follow = tem->link;
		
	}
	else
	{
		tem = first->link;
		follow = tem->link;

	}
	T x = tem->Data + follow->Data;
	if (x<=n)
	{
		list_node<T>* new_prt = new list_node<T>(x);
		tem->link = new_prt;
		new_prt->link = follow;
		a = x;
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class T>
inline bool link_list<T>::move_follow()
{
	if (follow == NULL)
	{
		return false;
	}
	else
	{
		follow = follow->link;
		return true;
	}
}

template<class T>
T link_list<T>::Delete(int i)	                        //删除第i个位置的节点，并返回数据
{
	T x;
	list_node<T> *prt = Loacte(i);
	if (prt == NULL || prt->link == NULL)
	{
		return x;
	}
	list_node<T> *tem = prt->link;
	x = prt->Data;
	prt->link = tem->link;
	delete tem;
	return x;
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
int link_list<T>::input(T& x)                               //输入
{
	Append(x);
	return 0;
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
		file << prt->Data << " ";
		prt = prt->link;
	}
	file.close();
	return 0;
}

template<class T>
inline int link_list<T>::OutPut_reverse(list_node<T> * tem = NULL)
{
	if (tem == NULL)
	{
		Reverse();
		tem = first->link;
	}
	if (tem != NULL&&tem->link == NULL)
	{
		cout << tem->Data;
		return 0;
	}
	cout << tem->Data << "  ";
	OutPut_order(tem->link);
	return 0;
}

template<class T>
inline int link_list<T>::OutPut_order(list_node<T> * tem = NULL)
{
	if (tem == NULL)
	{
		tem = first->link;
	}
	if (tem != NULL&&tem->link == NULL)
	{
		cout << tem->Data;
		return 0;
	}
	cout << tem->Data << "  ";
	OutPut_order(tem->link);
	return 0;
}

template<class T>
bool link_list<T>::Sort()                                    //排序 升序
{
	int size = Length();
	for (int i = 0; i < size; i++)
		for (int j = i; j > 0; j--)
			Exchanged(j);

	return true;
}


template<class T>
bool link_list<T>::Reverse()                              //逆置
{
	list_node<T> *prt_last, *prt_present, *prt_next;
	prt_last = first->link;
	prt_present = first->link->link;
	while (prt_present != NULL)
	{
		prt_next = prt_present->link;
		prt_present->link = prt_last;
		prt_last = prt_present;
		prt_present = prt_next;
	}
	first->link->link = NULL;
	first->link = prt_last;

	return true;
}

template<class T>
link_list<T>* link_list<T>::Merge(link_list * other)              //合并 排序
{
	list_node<T>* prt = other->Getfirst();
	int size = Length();
	list_node<T>* prt_1 = Loacte(size);
	prt_1->link = prt->link;      //将两链表合并
	prt->link = NULL;
	Sort();     //升序排序
	return NULL;
}

template<class T>
int link_list<T>::Exchanged(int i)                                //相邻比较 第i个和第i+1个比较 第i个更大则互换
{
	if (i == 1)
	{
		if (first->link->Data > first->link->link->Data)
		{
			list_node<T> *prt = first->link;
			list_node<T> *prt_1 = first->link->link;
			prt->link = prt_1->link;
			prt_1->link = prt;
			first->link = prt_1;
			return 0;
		}
		else
			return 0;
	}
	list_node<T> *prt = Loacte(i - 1);//比较的第一个元素的前一个元素
	list_node<T> *prt_1 = prt->link; //比较的第一个元素
	if (prt_1 == NULL)
	{
		return 0;
	}
	list_node<T> *prt_2 = prt->link->link; //比较的第二个元素
	if (prt_2 == NULL)
	{
		return 0;
	}
	if (prt_1->Data > prt_2->Data)
	{
		prt->link = prt_2;
		prt_1->link = prt_2->link;
		prt_2->link = prt_1;
	}
	return 0;
}

template<class T>
inline int link_list<T>::Append(T x)                              //在链表尾部接上一个节点
{
	list_node<T>* prt = tail;
	list_node<T>* prt_new = new list_node<T>(x);
	prt->link = prt_new;
	tail = prt_new;
	return 0;
}


