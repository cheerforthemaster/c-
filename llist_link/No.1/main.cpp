#include <iostream>
#include "link_list.h"
using namespace std;

int main()
{
	link_list<int> LIST;
	//cout << LIST.Loacte(1);
	LIST.Append(5);
	LIST.Append(15);
	LIST.Append(1);
	//int one, two, three, four, five;
	//LIST.Exchanged(3);
	LIST.Insert(2, 6);
	//int i=LIST.IsEmpty();
	//LIST.setData(5,0);

	cout << "链表1：" << endl;
	LIST.OutPut_order();
	cout << endl;

	link_list<int> OTHER(1);
	OTHER.Append(2);
	OTHER.Append(3);
	cout << "链表2：" << endl;
	OTHER.OutPut_order();
	cout << endl;

	LIST.Merge(&OTHER);
	cout << "合并加排序后：" << endl;
	LIST.OutPut_order();
	cout << endl;

	LIST.Reverse();
	cout << "再逆置：" << endl;
	LIST.OutPut_order();
	cout << endl;

	//LIST.getData(1, one);
	//LIST.getData(2, two);
	//LIST.getData(3, three);
	//LIST.getData(4, four);
	//LIST.getData(5, five);
	//LIST.makeEmpty();
	//cout<< LIST.Getfirst();
	//LIST.Delete(1,one);
	//LIST.Search(1);

	LIST.output();
	cout << "链表1已输入到output.txt中" << endl;

	cout << "递归顺序输出：";
	LIST.OutPut_order();
	cout << endl;
	cout << "递归逆序输出：";
	LIST.OutPut_reverse();
	cout << endl;


	cout << "链表1的长度：" << LIST.Length() << endl;

	cout << "由于输入的类型用模板，所以input函数就是调用Append函数在链表尾部加节点" << endl;
	//cout << one << "  " << two << "  " << three << "  " << four << "  " << five << endl;


	system("pause");
	return 0;
}

