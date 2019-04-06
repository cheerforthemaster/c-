#include "Class_List.h"

int Test_List::GetInvert()
{
	arraysize = 10;						  //可设置一个获取arraysize的函数
	A = new int[arraysize];
	for (int i = 0; i < arraysize; i++)   //初始化A[]
	{
		A[i] = i;
	}

	//if (A == NULL)                        //检查A[]是否new成功
	//{
	//	cout << "error";
	//}

	int n = arraysize / 2;				  //将A[]首尾互换
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