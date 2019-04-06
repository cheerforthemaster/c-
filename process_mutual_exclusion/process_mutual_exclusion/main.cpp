#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <windows.h>
#include <condition_variable>
using namespace std;

mutex mt;//互斥对象
condition_variable cv;//信号量

const int maxNum = 10;
int source = 0;//资源，上限为10
bool isEmpty = true;//资源标志位

int producer()//生产者
{
	unique_lock<mutex> lck(mt);
	while (true)
	{
		if (source < maxNum)
		{
			source++;
			isEmpty = false;
			cout << "生产:" << source << endl;
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


int consumer(int id)//消费者
{
	unique_lock<mutex> lck(mt);
	while (true)
	{
		if (source > 0)
		{
			cout << "消费者" << id << "号，正在消费：" << source << endl;
			source--;
		}
		else
		{
			cout << "消费者" << id << "停止消费" << endl;
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
	thread thrConsumer(producer);//一个生产者

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