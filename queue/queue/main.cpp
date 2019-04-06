#include <iostream>
//#include "queue.h"
#include "LinkQueue.h"
//#include "stdlib.h"
#include "time.h"
using namespace std;

int main()
{
	srand(time(NULL));

	int arr[10];
	int tem_1, tem_2;
	for (int i = 0; i < 10; i++)
		arr[i] = i;
	for (int i = 0; i < 10; i++)
	{
		tem_1 = arr[i];
		tem_2 = rand() % 10;
		arr[i] = arr[tem_2];
		arr[tem_2] = tem_1;

	}
	int array[10];
	for (int i = 0; i < 10; i++)
	{
		array[i] = arr[i];
		cout << arr[i] << endl;
	}
	cout << endl;


	LinkQueue<int> que;
	for (int i = 0; i < 10; i++)
		que.InQueue(arr[i]);
	cout << "size:" << que.GetSize() << endl;
	for (int i = 0; i < 9; i++)
	{
		que.OutQueue(arr[i]);
	}
	for (int i = 0; i < 10; i++)
		cout << arr[i] << endl;
	cout << "size:" << que.GetSize() << endl;
	

	return 0;
}