#pragma once

template <class T>
class linear_list
{
public:
	linear_list();                    //定义线性表空间大小
	~linear_list();

	int Append();                     //末尾增加一个元素
	int Insert(int position);         //插入一个元素
	int Delete(int position);         //删除一个元素
	int Clear();                      //删除所有元素
	int Loaction(int position);       //查看任意一个元素
	int Find(T test_data);            //测定特定的元素
	int Length();                     //统计线性表长度
	bool Empty();                     //线性表是否为空
	int Show();                       //显示所有元素
	bool Resize();                    //扩大线性表空间

private:
	int Maxsize;                      //线性表最大空间
	T data;                           //数据
};

