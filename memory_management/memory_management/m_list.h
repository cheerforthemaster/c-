#pragma once
#include <list>
#include <vector>
using namespace std;

class m_list
{
public:
	m_list(int num = 1024, int size = 1024);//创建链表，两个参数，一为页面数量，二为页面大小，都默认为1024
	~m_list() { if (mlist != NULL)delete mlist; }//释放list指针
	//list<int>* get() { return mlist; }//返回链表的指针
	int getNum() { return pageNum; }//返回页面数
	int getSize() { return pageSize; }//返回页面大小
	vector<int> state();//返回链表中的各个元素的值，即返回各个页面的使用情况
	bool apply(int size);//申请指定大小的空间
	bool release(int size);//释放指定大小的空间
	bool tighten();//内存紧缩
	int getUsedRoom() { return pageNum*pageSize - room; }
private:
	int pageNum;//页面数
	int pageSize;//页面大小
	list<int> *mlist;//链表
	int room;//总内存大小
};