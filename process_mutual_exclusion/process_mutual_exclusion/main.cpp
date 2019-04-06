#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <windows.h>
#include <condition_variable>
using namespace std;

mutex mt;//�������
condition_variable cv;//�ź���

const int maxNum = 10;
int source = 0;//��Դ������Ϊ10
bool isEmpty = true;//��Դ��־λ

int producer()//������
{
	unique_lock<mutex> lck(mt);
	while (true)
	{
		if (source < maxNum)
		{
			source++;
			isEmpty = false;
			cout << "����:" << source << endl;
		}
		if (!isEmpty)
		{
			cv.notify_all();
			cv.wait(lck);
			Sleep(500);
		}
	}
	return 0;

}


int consumer(int id)//������
{
	unique_lock<mutex> lck(mt);
	while (true)
	{
		if (source > 0)
		{
			cout << "������" << id << "�ţ��������ѣ�" << source << endl;
			source--;
		}
		else
		{
			cout << "������" << id << "ֹͣ����" << endl;
			isEmpty = true;
		}
		if (isEmpty)
		{
			cv.notify_one();
			cv.wait(lck);
			Sleep(500);
		}
	}
	return 0;
}



int main()
{
	thread thrConsumer(producer);//һ��������

	thread thrProducer[5];
	for (int i = 0; i < 5; i++)
	{
		thrProducer[i] = thread(consumer, i);
	}

	thrConsumer.join();
	for (int i = 0; i < 5; i++)
	{
		thrProducer[i].join();
	}
	system("pause");
	return 0;
}