#include <m_list.h>

m_list::m_list(int num, int size)
{
	pageNum = num;
	pageSize = size;
	room = pageSize*pageNum;
	mlist = new list<int>(pageNum, pageSize);//pageNum��Ԫ�أ�ÿ��Ԫ���з�һ��pageSize��intֵ
}

vector<int> m_list::state()
{
	vector<int> temVec;
	list<int>::iterator iter;
	for (iter = mlist->begin(); iter != mlist->end(); iter++)
	{
		temVec.insert(temVec.end(), *iter);
	}
	return temVec;
}

bool m_list::apply(int size)
{
	if (size > room)
		return false;
	list<int> temList(*mlist);
	list<int>::iterator iter;
	int temsize = size;
	room = room - temsize;
	for (iter = mlist->begin(); iter != mlist->end(); iter++)
	{
		if (*iter == pageSize)
		{
			if (size > pageSize)
			{
				*iter = 0;
				size = size - pageSize;
			}
			else
			{
				*iter = *iter - size;
				return true;
			}
		}
	}
	iter = mlist->end();
	if (*iter >= size)
	{
		*iter = *iter - size;
		return true;
	}
	room = room + temsize;
	mlist = &temList;//û���㹻�Ŀռ����룬�򷵻�ԭ����״̬
	tighten();
	return apply(temsize);
}

bool m_list::release(int size)
{
	list<int> temList(*mlist);
	list<int>::iterator iter;
	int temsize = size;
	room = room + temsize;
	for (iter = mlist->begin(); iter != mlist->end(); iter++)
	{
		if (*iter != pageSize)
		{
			if (size > pageSize)
			{
				size = size - (pageSize - *iter);
				*iter = pageSize;
			}
			else
			{
				*iter = *iter + size;
				return true;
			}
		}
	}
	room = room - temsize;
	mlist = &temList;//û���㹻�Ŀռ��ͷţ��򷵻�ԭ����״̬
	return false;
}

bool m_list::tighten()
{
	list<int>::iterator iter;
	list<int>::iterator temiter;
	for (iter = mlist->begin(); iter != mlist->end(); iter++)
	{
		if (*iter != 0)//�пռ����
		{
			temiter = iter;
			temiter++;
			for (; temiter != mlist->end(); temiter++)
			{
				if (*temiter != pageSize)//ҳ��������
				{
					if ((pageSize - *temiter) <= *iter)
					{
						*iter = *iter - (pageSize - *temiter);
						*temiter = pageSize;
					}
					else
					{
						*temiter += *iter;
						*iter = 0;
						break;
					}
				}
			}
		}
	}
	return false;
}