#pragma once
#include <fstream>
using namespace std;

template <class T>
class list_node                                        //�ڵ�
{
public:
	T Data;                                            //������  ����
	T ex_Data;                                         //��չ��������  ��ĸ
	list_node<T>* link;                                //ָ����
	list_node() { link = NULL; };
	~list_node() {};
};


template <class T>
class link_list
{
public:
	link_list();											     //����
	~link_list() { makeEmpty(); }								 //����
	void makeEmpty();											 //�������ÿ�
	int Length();											     //ͳ��������
	list_node<T>* Getfirst() { return first; }				     //����ͷ�ڵ��λ��
	bool IsEmpty();                                              //�ж������Ƿ�Ϊ��
	int output();                                                //�����output.txt��
	int Append(T x,T y);                                         //������β������һ���ڵ�
	int Fraction(int n);                                         //��ȡ�µķ���

protected:
	list_node<T>* first;                                         //ͷ���
	list_node<T>* tail;                                          //β�ڵ�
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
void link_list<T>::makeEmpty()                                   //�������ÿ�
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
		file << prt->Data << "/" << prt->ex_Data << ";";
		prt = prt->link;
	}
	file.close();
	return 0;
}

template<class T>
inline int link_list<T>::Append(T x,T y)                              //������β������һ���ڵ�
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
inline int link_list<T>::Fraction(int n)//nΪ����
{
	int last_molecule=0, last_denominator=1;//ǰһ���ķ������ĸ
	int present_molecule=1, present_denominator=n;//��ǰ�ķ������ĸ
	int next_molecule, next_denominator;//��һ���ķ������ĸ
	int x = 0;//����

	Append(present_molecule, present_denominator);
	while (present_denominator != 1)//��1/1���ɣ������
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