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

	cout << "����1��" << endl;
	LIST.OutPut_order();
	cout << endl;

	link_list<int> OTHER(1);
	OTHER.Append(2);
	OTHER.Append(3);
	cout << "����2��" << endl;
	OTHER.OutPut_order();
	cout << endl;

	LIST.Merge(&OTHER);
	cout << "�ϲ��������" << endl;
	LIST.OutPut_order();
	cout << endl;

	LIST.Reverse();
	cout << "�����ã�" << endl;
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
	cout << "����1�����뵽output.txt��" << endl;

	cout << "�ݹ�˳�������";
	LIST.OutPut_order();
	cout << endl;
	cout << "�ݹ����������";
	LIST.OutPut_reverse();
	cout << endl;


	cout << "����1�ĳ��ȣ�" << LIST.Length() << endl;

	cout << "���������������ģ�壬����input�������ǵ���Append����������β���ӽڵ�" << endl;
	//cout << one << "  " << two << "  " << three << "  " << four << "  " << five << endl;


	system("pause");
	return 0;
}

