#include <iostream>
#include <vector>
using namespace std;

int n;//进程总数
int m;//资源种类
vector<vector<int>> resource;//资源总量
vector<vector<int>> process;//当前每个进程已分配的各种资源数量
vector<vector<int>> process_need;//当前每个进程需要的各种资源的最大数
vector<vector<int>> work;//当前每种资源可分配的数量
vector<bool> isfinish;//进程是否结束

int m_init()//初始化
{
	resource.resize(m);
	for (int i = 0; i < resource.size(); i++)
	{
		resource[i].resize(1);
		resource[i][0] = 2 * n;//每种资源总数为2*n
	}

	process.resize(n);
	for (int i = 0; i < process.size(); i++)
	{
		process[i].resize(m);
		for (int j = 0; j < process.size(); j++)
		{
			process[i][j] = 0;//初始已分配的资源为0
		}
	}

	process_need.resize(n);
	for (int i = 0; i < process_need.size(); i++)
	{
		process_need[i].resize(m);
		for (int j = 0; j < process_need.size(); j++)
		{
			process_need[i][j] = 0;//初始需要量最大值为0
		}
	}

	work.resize(m);
	for (int i = 0; i < work.size(); i++)
	{
		work[i].resize(1);
		work[i][0] = 2 * n;//每种资源可分配的初始总数为2*n
	}

	isfinish.resize(n);
	for (int i = 0; i < isfinish.size(); i++)
	{
		isfinish[i] = true;//初始所有进程都没启动
	}

	return 0;
}

int Security_sequence()
{
	int num = 0;//已完成的进程数
	int temnum = 0;//上一轮遍历中已完成的进程数
	int *sequence = new int[n];//安全序列
	int l = 0;//sequence的下标
	vector<vector<int>> temwork(work);//work的临时复制
	while (num!=n)
	{
		num = 0;
		for (int i = 0; i < n; i++)
		{
			if (!isfinish[i])//进程没有结束
			{
				for (int j = 0; j < m; j++)
				{
					if (process_need[i][j] - process[i][j] > temwork[j][0])//当前进程中有一个资源不能满足
					{
						break;
					}
					if (j == m - 1)//当前进程可以完全满足
					{
						for (int k = 0; k < m; k++)
						{
							temwork[k][0] = temwork[k][0] + process[i][j];//释放资源
						}
						isfinish[i] = true;//该进程可以结束
						sequence[l] = i;//进入安全序列
						l++;
					}
				}
			}
			else
				num++;
			if (temnum == num)//结束进程数量没有变化
			{
				break;
			}
			temnum = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << sequence[i] << endl;
	}
	work = temwork;
	return 0;
}


int main()
{
	cout << "输入总进程数n：";
	cin >> n;//n=3
	cout << "输入资源种类m：";
	cin >> m;//=3

	m_init();

	for (int i = 0; i < n; i++)
	{
		isfinish[i] = 0;
	}

	return 0;
}