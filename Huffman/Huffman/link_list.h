#pragma once
#include <fstream>
using namespace std;

template <class T>
class list_node                                        //�ڵ�
{
public:
	T Data;                                            //������
	list_node<T>* link;                                //ָ����
	list_node() { link = NULL; };
	~list_node() {};
	list_node(const T &item, list_node<T>* prt = NULL) //��ʼ��Data��link
	{
		Data = item;
		link = prt;
	}
};


template <class T>
class link_list
{
public:
	link_list() { first = new list_node<T>; tail = first; }		 //����
	link_list(const T& x);                                       //���� ������
	~link_list() { makeEmpty(); delete first; }					 //����
	void makeEmpty();											 //�������ÿ�
	int Length();											     //ͳ��������
	list_node<T>* Getfirst() { return first; }				     //����ͷ�ڵ��λ��
	list_node<T>* Search(T x);								     //����������x�Ľڵ�
	list_node<T>* Loacte(int i);								 //������i��Ԫ�صĵ�ַ
	T getData(int i);							         		 //��ȡ��i��Ԫ�ص�����
	T only_output(int i);                                        //���һ���ڵ������
	bool setData(int i, T x);									 //����i��λ�õ�Ԫ����������Ϊx
	bool Insert(int i, T x);									 //�ڵ�i��Ԫ�غ����������Ϊx�Ľڵ�
	int Milddle_Insert(int i, int n,int a);                      //�������ڵ��м������������ӵĽڵ㣬nΪ��������
	bool move_follow();                                          //��follow����ƶ�����
	T Delete(int i);						     			     //ɾ����i��λ�õĽڵ㣬����������
	bool IsEmpty();                                              //�ж������Ƿ�Ϊ��
	int input(T& x);                                             //����һ��������
	int output();                                                //�����output.txt��
	int OutPut_reverse(list_node<T>* tem = NULL);                //�ݹ��������
	int OutPut_order(list_node<T>* tem = NULL);                  //�ݹ�˳�����
	bool Sort();                                                 //��������
	bool Reverse();                                              //����
	link_list<T>* Merge(link_list *other);                       //�ϲ�����������
	int Exchanged(int i);                                        //���ڱȽ� ��i���͵�i+1���Ƚ� ��i�������򻥻�
	int Append(T x);                                             //������β������һ���ڵ�


protected:
	list_node<T>* first;                                         //ͷ���
	list_node<T>* tail;                                          //β�ڵ�
	list_node<T>* follow;                                        //����ڵ㣬ָ��ǰ������һ��
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
void link_list<T>::makeEmpty()                                   //�������ÿ�
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
int link_list<T>::Length()                                    //ͳ��������
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
list_node<T>* link_list<T>::Search(T x)                       //����������x�Ľڵ�
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
			return NULL;                                      //δ������
		}
	}
	return prt;                                        //�������ˣ����ظ�Ԫ�ص�ָ����
}


template<class T>
list_node<T>* link_list<T>::Loacte(int i)                    //������i��Ԫ�صĵ�ַ
{
	int size = Length();
	list_node<T> *prt = first;
	if (i<0 || i>size)
	{
		return NULL;                                         //iֵ���벻��ȷ
	}
	else
	{
		for (int j = 0; j < i; j++)
		{
			prt = prt->link;
		}
		return prt;                                          //��ȷ�򷵻ص�i��Ԫ�صĵ�ַ
	}
}

template<class T>
T link_list<T>::getData(int i)                            //��ȡ��i��Ԫ�ص�����
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
bool link_list<T>::setData(int i, T  x)                     //����i��λ�õ�Ԫ����������Ϊx
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
bool link_list<T>::Insert(int i, T  x)                      //�ڵ�i��Ԫ�غ����������Ϊx�Ľڵ�
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
T link_list<T>::Delete(int i)	                        //ɾ����i��λ�õĽڵ㣬����������
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
bool link_list<T>::IsEmpty()                                //�ж������Ƿ�Ϊ��
{
	if (first->link != NULL)
	{
		return true;
	}
	else
		return false;
}

template<class T>
int link_list<T>::input(T& x)                               //����
{
	Append(x);
	return 0;
}

template<class T>
int link_list<T>::output()                                  //�����output.txt��
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
bool link_list<T>::Sort()                                    //���� ����
{
	int size = Length();
	for (int i = 0; i < size; i++)
		for (int j = i; j > 0; j--)
			Exchanged(j);

	return true;
}


template<class T>
bool link_list<T>::Reverse()                              //����
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
link_list<T>* link_list<T>::Merge(link_list * other)              //�ϲ� ����
{
	list_node<T>* prt = other->Getfirst();
	int size = Length();
	list_node<T>* prt_1 = Loacte(size);
	prt_1->link = prt->link;      //��������ϲ�
	prt->link = NULL;
	Sort();     //��������
	return NULL;
}

template<class T>
int link_list<T>::Exchanged(int i)                                //���ڱȽ� ��i���͵�i+1���Ƚ� ��i�������򻥻�
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
	list_node<T> *prt = Loacte(i - 1);//�Ƚϵĵ�һ��Ԫ�ص�ǰһ��Ԫ��
	list_node<T> *prt_1 = prt->link; //�Ƚϵĵ�һ��Ԫ��
	if (prt_1 == NULL)
	{
		return 0;
	}
	list_node<T> *prt_2 = prt->link->link; //�Ƚϵĵڶ���Ԫ��
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
inline int link_list<T>::Append(T x)                              //������β������һ���ڵ�
{
	list_node<T>* prt = tail;
	list_node<T>* prt_new = new list_node<T>(x);
	prt->link = prt_new;
	tail = prt_new;
	return 0;
}


