#include "Class_List.h"

int Test_List::GetInvert()
{
	arraysize = 10;						  //������һ����ȡarraysize�ĺ���
	A = new int[arraysize];
	for (int i = 0; i < arraysize; i++)   //��ʼ��A[]
	{
		A[i] = i;
	}

	//if (A == NULL)                        //���A[]�Ƿ�new�ɹ�
	//{
	//	cout << "error";
	//}

	int n = arraysize / 2;				  //��A[]��β����
	for (int i = 0, tem; i < n; i++)
	{
		tem = A[i];
		A[i] = A[arraysize - 1 - i];
		A[arraysize - 1 - i] = tem;
	}

	return 0;
}

Test_List::Test_List()
{

}

Test_List::~Test_List()
{
	delete[]A;
}