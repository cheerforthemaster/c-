#pragma once
#include <list>
#include <vector>
using namespace std;

class m_list
{
public:
	m_list(int num = 1024, int size = 1024);//������������������һΪҳ����������Ϊҳ���С����Ĭ��Ϊ1024
	~m_list() { if (mlist != NULL)delete mlist; }//�ͷ�listָ��
	//list<int>* get() { return mlist; }//���������ָ��
	int getNum() { return pageNum; }//����ҳ����
	int getSize() { return pageSize; }//����ҳ���С
	vector<int> state();//���������еĸ���Ԫ�ص�ֵ�������ظ���ҳ���ʹ�����
	bool apply(int size);//����ָ����С�Ŀռ�
	bool release(int size);//�ͷ�ָ����С�Ŀռ�
	bool tighten();//�ڴ����
	int getUsedRoom() { return pageNum*pageSize - room; }
private:
	int pageNum;//ҳ����
	int pageSize;//ҳ���С
	list<int> *mlist;//����
	int room;//���ڴ��С
};